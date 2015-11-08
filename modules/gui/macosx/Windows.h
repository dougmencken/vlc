/*****************************************************************************
 * Windows.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2012-2014 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
 *          David Fuhrmann <david dot fuhrmann at googlemail dot com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>
#import "CompatibilityFixes.h"

/*****************************************************************************
 * VLCWindow
 *
 *  Missing extension to NSWindow
 *****************************************************************************/

@class VLCVoutView;

@interface VLCWindow : NSWindow <NSAnimationDelegate> {

    BOOL b_canBecomeKeyWindow;
    BOOL b_isset_canBecomeKeyWindow;
    BOOL b_canBecomeMainWindow;
    BOOL b_isset_canBecomeMainWindow;

    BOOL _hasActiveVideo;
    BOOL _fullscreen;

    NSViewAnimation *o_current_animation;

}

//@property (readwrite) BOOL canBecomeKeyWindow;
- (BOOL)canBecomeKeyWindow;
- (void)setCanBecomeKeyWindow: (BOOL)canBecomeKey;

//@property (readwrite) BOOL canBecomeMainWindow;
- (BOOL)canBecomeMainWindow;
- (void)setCanBecomeMainWindow: (BOOL)canBecomeMain;

@property (nonatomic, readwrite) BOOL hasActiveVideo;
@property (nonatomic, readwrite) BOOL fullscreen;

/* animate mode is only supported in >=10.4 */
- (void)orderFront: (id)sender animate: (BOOL)animate;

/* animate mode is only supported in >=10.4 */
- (void)orderOut: (id)sender animate: (BOOL)animate;

/* animate mode is only supported in >=10.4 */
- (void)orderOut: (id)sender animate: (BOOL)animate callback:(NSInvocation *)callback;

/* animate mode is only supported in >=10.4 */
- (void)closeAndAnimate: (BOOL)animate;

- (VLCVoutView *)videoView;

@end


static const float f_min_video_height = 70.0;

@class VLCControlsBarCommon;
@class VLCMainWindowTitleView;

/*****************************************************************************
 * VLCVideoWindowCommon
 *
 *  Common code for main window, detached window and extra video window
 *****************************************************************************/

@interface VLCVideoWindowCommon : VLCWindow <NSWindowDelegate, NSAnimationDelegate> {

    IBOutlet VLCMainWindowTitleView * _titlebarView;
    IBOutlet VLCVoutView * _videoView;
    IBOutlet VLCControlsBarCommon * _controlsBar;
    BOOL _inFullscreenTransition;
    BOOL _darkInterface;
    BOOL _windowShouldExitFullscreenWhenFinished;
    NSRect _previousSavedFrame;
    NSSize _nativeVideoSize;

    // variables for fullscreen handling
    VLCVideoWindowCommon *o_current_video_window;
    VLCWindow       * o_fullscreen_window;
    NSViewAnimation * o_fullscreen_anim1;
    NSViewAnimation * o_fullscreen_anim2;
    NSView          * o_temp_view;

    NSInteger i_originalLevel;

    BOOL b_video_view_was_hidden;

    NSTimer *t_hide_mouse_timer;

    NSRect frameBeforeLionFullscreen;

}

@property (nonatomic, assign) IBOutlet VLCMainWindowTitleView *titlebarView; // only set in main or detached window
@property (nonatomic, assign) IBOutlet VLCVoutView* videoView;
@property (nonatomic, assign) IBOutlet VLCControlsBarCommon* controlsBar;
@property (readonly) BOOL inFullscreenTransition;
@property (readonly) BOOL darkInterface;
@property (readonly) BOOL windowShouldExitFullscreenWhenFinished;
@property (readwrite, assign) NSRect previousSavedFrame;
@property (nonatomic, readwrite, assign) NSSize nativeVideoSize;

- (void)setWindowLevel:(NSInteger)i_state;
- (void)resizeWindow;

- (NSRect)getWindowRectForProposedVideoViewSize:(NSSize)size;

- (void)setTitle:(NSString *)title;

/* fullscreen handling */
- (void)enterFullscreenWithAnimation:(BOOL)b_animation;
- (void)leaveFullscreenWithAnimation:(BOOL)b_animation;

- (void)customZoom:(id)sender;
- (void)hasBecomeFullscreen;
- (void)hasEndedFullscreen;

/* lion fullscreen handling */
- (void)windowWillEnterFullScreen:(NSNotification *)notification;
- (void)windowDidEnterFullScreen:(NSNotification *)notification;
- (void)windowWillExitFullScreen:(NSNotification *)notification;

- (void)toggleForwardBackward:(NSNumber *)boolVal;

@end
