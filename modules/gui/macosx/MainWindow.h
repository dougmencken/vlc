/*****************************************************************************
 * MainWindow.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2002-2014 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
 *          Jon Lech Johansen <jon-vl@nanocrew.net>
 *          Christophe Massiot <massiot@via.ecp.fr>
 *          Derk-Jan Hartman <hartman at videolan.org>
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
#import "PXSourceList.h"
#import "PXSourceListDataSource.h"

#import <vlc_input.h>
#import <vlc_vout_window.h>

#import "Windows.h"
#import "misc.h"
#import "fspanel.h"
#import "MainWindowTitle.h"

@class VLCDetachedVideoWindow;
@class VLCMainWindowControlsBar;
@class VLCVoutView;

typedef enum {
    psUserEvent,
    psUserMenuEvent,
    psVideoStartedOrStoppedEvent,
    psPlaylistItemChangedEvent
} VLCPlaylistStateEvent;

@interface VLCMainWindow : VLCVideoWindowCommon <PXSourceListDataSource, PXSourceListDelegate, NSWindowDelegate, NSAnimationDelegate, NSSplitViewDelegate> {

    BOOL videoPlaybackEnabled;
    BOOL dropzoneActive;
    BOOL splitViewRemoved;
    BOOL minimizedView;

    BOOL b_video_playback_enabled;
    BOOL b_dropzone_active;
    BOOL b_splitview_removed;
    BOOL b_minimized_view;

    CGFloat f_lastSplitViewHeight;
    CGFloat f_lastLeftSplitViewWidth;

    NSMutableArray *o_sidebaritems;

    /* this is only true, when we have NO video playing inside the main window */

    BOOL b_podcastView_displayed;

    VLCColorView * o_color_backdrop;

    NSRect frameBeforePlayback;

    // ivars for properties

    IBOutlet NSTextField        * _searchField;
    IBOutlet NSScrollView       * _playlistScrollView;
    IBOutlet NSOutlineView      * _outlineView;
    IBOutlet NSSplitView        * _splitView;
    IBOutlet NSView             * _splitViewLeft;
    IBOutlet NSView             * _splitViewRight;
    IBOutlet PXSourceList       * _sidebarView;
    IBOutlet NSScrollView       * _sidebarScrollView;
    IBOutlet NSTextField        * _categoryLabel;

    IBOutlet NSView             * _dropzoneView;
    IBOutlet NSButton           * _dropzoneButton;
    IBOutlet NSTextField        * _dropzoneLabel;
    IBOutlet NSBox              * _dropzoneBox;
    IBOutlet NSImageView        * _dropzoneImageView;

    IBOutlet NSView             * _podcastView;
    IBOutlet NSButton           * _podcastAddButton;
    IBOutlet NSButton           * _podcastRemoveButton;

    IBOutlet NSWindow           * _podcastSubscribeWindow;
    IBOutlet NSTextField        * _podcastSubscribeTitle;
    IBOutlet NSTextField        * _podcastSubscribeSubtitle;
    IBOutlet NSTextField        * _podcastSubscribeUrlField;
    IBOutlet NSButton           * _podcastSubscribeOkButton;
    IBOutlet NSButton           * _podcastSubscribeCancelButton;

    IBOutlet NSWindow           * _podcastUnsubscribeWindow;
    IBOutlet NSTextField        * _podcastUnsubscirbeTitle;
    IBOutlet NSTextField        * _podcastUnsubscribeSubtitle;
    IBOutlet NSPopUpButton      * _podcastUnsubscribePopUpButton;
    IBOutlet NSButton           * _podcastUnsubscribeOkButton;
    IBOutlet NSButton           * _podcastUnsubscribeCancelButton;

    BOOL _nativeFullscreenMode;
    BOOL _nonembedded;

    VLCFSPanel* _fspanel;

}

// General MainWindow outlets
@property (readwrite, assign) IBOutlet NSTextField        *searchField;
@property (readwrite, assign) IBOutlet NSScrollView       *playlistScrollView;
@property (readwrite, assign) IBOutlet NSOutlineView      *outlineView;
@property (readwrite, assign) IBOutlet NSSplitView        *splitView;
@property (readwrite, assign) IBOutlet NSView             *splitViewLeft;
@property (readwrite, assign) IBOutlet NSView             *splitViewRight;
@property (readwrite, assign) IBOutlet PXSourceList       *sidebarView;
@property (readwrite, assign) IBOutlet NSScrollView       *sidebarScrollView;
@property (readwrite, assign) IBOutlet NSTextField        *categoryLabel;

// Dropzone outlets
@property (readwrite, assign) IBOutlet NSView             *dropzoneView;
@property (readwrite, assign) IBOutlet NSButton           *dropzoneButton;
@property (readwrite, assign) IBOutlet NSTextField        *dropzoneLabel;
@property (readwrite, assign) IBOutlet NSBox              *dropzoneBox;
@property (readwrite, assign) IBOutlet NSImageView        *dropzoneImageView;

// Podcast View outlets
@property (readwrite, assign) IBOutlet NSView             *podcastView;
@property (readwrite, assign) IBOutlet NSButton           *podcastAddButton;
@property (readwrite, assign) IBOutlet NSButton           *podcastRemoveButton;

// Podcast Subscribe Window outlets
@property (readwrite, assign) IBOutlet NSWindow           *podcastSubscribeWindow;
@property (readwrite, assign) IBOutlet NSTextField        *podcastSubscribeTitle;
@property (readwrite, assign) IBOutlet NSTextField        *podcastSubscribeSubtitle;
@property (readwrite, assign) IBOutlet NSTextField        *podcastSubscribeUrlField;
@property (readwrite, assign) IBOutlet NSButton           *podcastSubscribeOkButton;
@property (readwrite, assign) IBOutlet NSButton           *podcastSubscribeCancelButton;

// Podcast Unsubscribe Window outlets
@property (readwrite, assign) IBOutlet NSWindow           *podcastUnsubscribeWindow;
@property (readwrite, assign) IBOutlet NSTextField        *podcastUnsubscirbeTitle;
@property (readwrite, assign) IBOutlet NSTextField        *podcastUnsubscribeSubtitle;
@property (readwrite, assign) IBOutlet NSPopUpButton      *podcastUnsubscribePopUpButton;
@property (readwrite, assign) IBOutlet NSButton           *podcastUnsubscribeOkButton;
@property (readwrite, assign) IBOutlet NSButton           *podcastUnsubscribeCancelButton;

@property (readonly) BOOL nativeFullscreenMode;
@property (readwrite) BOOL nonembedded;

@property (readonly) VLCFSPanel* fspanel;

- (void)changePlaylistState:(VLCPlaylistStateEvent)event;

- (IBAction)dropzoneButtonAction:(id)sender;

- (IBAction)addPodcast:(id)sender;
- (IBAction)addPodcastWindowAction:(id)sender;
- (IBAction)removePodcast:(id)sender;
- (IBAction)removePodcastWindowAction:(id)sender;

- (IBAction)searchItem:(id)sender;

- (void)windowResizedOrMoved:(NSNotification *)notification;

- (void)reloadSidebar;

- (void)toggleLeftSubSplitView;
- (void)showDropZone;
- (void)hideDropZone;
- (void)updateTimeSlider;
- (void)updateWindow;
- (void)updateName;
- (void)setPause;
- (void)setPlay;
- (void)updateVolumeSlider;

- (void)showFullscreenController;

- (void)videoplayWillBeStarted;
- (void)setVideoplayEnabled;

- (void)resizePlaylistAfterCollapse;
- (void)makeSplitViewVisible;
- (void)makeSplitViewHidden;
- (void)showPodcastControls;
- (void)hidePodcastControls;

- (void)showSplitView:(BOOL)resize;
- (void)hideSplitView:(BOOL)resize;

- (void)_updatePlaylistTitle;

- (NSString *)_playbackDurationOfNode:(playlist_item_t*)node;

@end

@interface VLCDetachedVideoWindow : VLCVideoWindowCommon {

    VLCColorView * o_color_backdrop;

}

@end
