/*****************************************************************************
 * intf.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2002-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Derk-Jan Hartman <hartman at videolan dot org>
 *          Felix Paul Kühne <fkuehne at videolan dot org>
 *          David Fuhrmann <david dot fuhrmann at googlemail dot com>
 *          Pierre d'Herbemont <pdherbemont # videolan org>
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

#ifdef HAVE_CONFIG_H
#   include "config.h"
#endif

#import <vlc_common.h>
#import <vlc_interface.h>
#import <vlc_playlist.h>
#import <vlc_vout.h>
#import <vlc_aout.h>
#import <vlc_input.h>
#import <vlc_vout_window.h>
#import <vlc_atomic.h>

#import <Cocoa/Cocoa.h>
#import "CompatibilityFixes.h"
#import "misc.h"
#import "MainWindow.h"
#import "VLCVoutWindowController.h"
#import "StringUtility.h"
#import "CoreInteraction.h"
#import "BWQuincyManager.h"

/*****************************************************************************
 * Local prototypes.
 *****************************************************************************/

// deprecated macro
#define VLCIntf getIntf()

intf_thread_t *getIntf();

static NSString * VLCInputChangedNotification = @"VLCInputChangedNotification";

/*****************************************************************************
 * VLCMain interface
 *****************************************************************************/
@class AppleRemote;
@class VLCInfo;
@class VLCMainMenu;
@class VLCPlaylist;
@class VLCInputManager;
@class ResumeDialogController;
@class VLCSimplePrefs;
@class VLCPrefs;
@class VLCCoreDialogProvider;
@class VLCBookmarks;
@class VLCOpen;
@class VLCDebugMessageVisualizer;
@class VLCTrackSynchronization;
@class VLCAudioEffects;
@class VLCVideoEffects;
@class VLCConvertAndSave;
@class ExtensionsManager;

@interface VLCMain : NSObject <NSWindowDelegate, NSApplicationDelegate, BWQuincyManagerDelegate> {

    VLCVoutWindowController* _voutController;
    BOOL _nativeFullscreenMode;
    BOOL _playlistUpdatedSelectorInQueue;

    intf_thread_t *p_intf;
    BOOL launched;
    int items_at_launch;

    BOOL b_active_videoplayback;

    NSWindowController *_mainWindowController;
    VLCMainMenu *_mainmenu;
    VLCPrefs *_prefs;
    VLCSimplePrefs *_sprefs;
    VLCOpen *_open;
    VLCCoreDialogProvider *_coredialogs;
    VLCBookmarks *_bookmarks;
    VLCCoreInteraction *_coreinteraction;
    ResumeDialogController *_resume_dialog;
    VLCInputManager *_input_manager;
    VLCPlaylist *_playlist;
    VLCDebugMessageVisualizer *_messagePanelController;
    VLCTrackSynchronization *_trackSyncPanel;
    VLCAudioEffects *_audioEffectsPanel;
    VLCVideoEffects *_videoEffectsPanel;
    VLCConvertAndSave *_convertAndSaveWindow;
    ExtensionsManager *_extensionsManager;

    bool b_intf_terminating; /* Makes sure applicationWillTerminate will be called only once */

}

@property (readonly) VLCVoutWindowController* voutController;
@property (readonly) BOOL nativeFullscreenMode;
@property (nonatomic, readwrite) BOOL playlistUpdatedSelectorInQueue;

+ (VLCMain *)sharedInstance;
+ (void)killInstance;

- (VLCMainMenu *)mainMenu;
- (VLCMainWindow *)mainWindow;
- (VLCBookmarks *)bookmarks;
- (VLCOpen *)open;
- (VLCSimplePrefs *)simplePreferences;
- (VLCPrefs *)preferences;
- (VLCPlaylist *)playlist;
- (VLCCoreDialogProvider *)coreDialogProvider;
- (ResumeDialogController *)resumeDialog;
- (VLCInputManager *)inputManager;
- (ExtensionsManager *)extensionsManager;

- (VLCDebugMessageVisualizer *)debugMsgPanel;

- (VLCTrackSynchronization *)trackSyncPanel;
- (VLCAudioEffects *)audioEffectsPanel;
- (VLCVideoEffects *)videoEffectsPanel;

- (VLCConvertAndSave *)convertAndSaveWindow;

- (void)setActiveVideoPlayback:(BOOL)b_value;
- (BOOL)activeVideoPlayback;
- (void)applicationWillTerminate:(NSNotification *)notification;

- (void)showFullscreenController;

- (BOOL)isTerminating;

@end


/*****************************************************************************
 * VLCApplication interface
 *****************************************************************************/

@interface VLCApplication : NSApplication

@end

#import "helpers.h"
