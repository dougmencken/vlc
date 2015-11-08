/*****************************************************************************
 *MainMenu.h: MacOS X interface module
 *****************************************************************************
 *Copyright (C) 2011-2015 Felix Paul Kühne
 *$Id$
 *
 *Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
 *
 *This program is free software; you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation; either version 2 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program; if not, write to the Free Software
 *Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>
#import <vlc_common.h>
#import <vlc_interface.h>

@class AboutWindowController;
@class AddonsWindowController;
@class HelpWindowController;
@class VLCTimeSelectionPanelController;

@interface VLCMainMenu : NSObject {

    IBOutlet NSMenuItem * _about;
    IBOutlet NSMenuItem * _prefs;
    IBOutlet NSMenuItem * _checkForUpdate;
    IBOutlet NSMenuItem * _extensions;
    IBOutlet NSMenu * _extensionsMenu;
    IBOutlet NSMenuItem * _addonManager;
    IBOutlet NSMenuItem * _add_intf;
    IBOutlet NSMenu * _add_intfMenu;
    IBOutlet NSMenuItem * _services;
    IBOutlet NSMenuItem * _hide;
    IBOutlet NSMenuItem * _hide_others;
    IBOutlet NSMenuItem * _show_all;
    IBOutlet NSMenuItem * _quit;

    IBOutlet NSMenu * _fileMenu;
    IBOutlet NSMenuItem * _open_file;
    IBOutlet NSMenuItem * _open_generic;
    IBOutlet NSMenuItem * _open_disc;
    IBOutlet NSMenuItem * _open_net;
    IBOutlet NSMenuItem * _open_capture;
    IBOutlet NSMenuItem * _open_recent;
    IBOutlet NSMenuItem * _close_window;
    IBOutlet NSMenuItem * _convertandsave;
    IBOutlet NSMenuItem * _save_playlist;
    IBOutlet NSMenuItem * _revealInFinder;

    IBOutlet NSMenu * _editMenu;
    IBOutlet NSMenuItem * _cutItem;
    IBOutlet NSMenuItem * _mcopyItem;
    IBOutlet NSMenuItem * _pasteItem;
    IBOutlet NSMenuItem * _clearItem;
    IBOutlet NSMenuItem * _select_all;

    IBOutlet NSMenu * _viewMenu;
    IBOutlet NSMenuItem * _toggleJumpButtons;
    IBOutlet NSMenuItem * _togglePlaymodeButtons;
    IBOutlet NSMenuItem * _toggleEffectsButton;
    IBOutlet NSMenuItem * _toggleSidebar;
    IBOutlet NSMenu * _playlistTableColumnsMenu;
    IBOutlet NSMenuItem * _playlistTableColumns;

    IBOutlet NSMenu * _controlsMenu;
    IBOutlet NSMenuItem * _play;
    IBOutlet NSMenuItem * _stop;
    IBOutlet NSMenuItem * _record;
    IBOutlet NSMenuItem * _rate;
    IBOutlet NSView * _rate_view;
    IBOutlet NSTextField * _rateLabel;
    IBOutlet NSTextField * _rate_slowerLabel;
    IBOutlet NSTextField * _rate_normalLabel;
    IBOutlet NSTextField * _rate_fasterLabel;
    IBOutlet NSSlider * _rate_sld;
    IBOutlet NSTextField * _rateTextField;
    IBOutlet NSMenuItem * _trackSynchronization;
    IBOutlet NSMenuItem * _previous;
    IBOutlet NSMenuItem * _next;
    IBOutlet NSMenuItem * _random;
    IBOutlet NSMenuItem * _repeat;
    IBOutlet NSMenuItem * _loop;
    IBOutlet NSMenuItem * _AtoBloop;
    IBOutlet NSMenuItem * _quitAfterPB;
    IBOutlet NSMenuItem * _fwd;
    IBOutlet NSMenuItem * _bwd;
    IBOutlet NSMenuItem * _jumpToTime;
    IBOutlet NSMenuItem * _program;
    IBOutlet NSMenu * _programMenu;
    IBOutlet NSMenuItem * _title;
    IBOutlet NSMenu * _titleMenu;
    IBOutlet NSMenuItem * _chapter;
    IBOutlet NSMenu * _chapterMenu;

    IBOutlet NSMenu * _audioMenu;
    IBOutlet NSMenuItem * _vol_up;
    IBOutlet NSMenuItem * _vol_down;
    IBOutlet NSMenuItem * _mute;
    IBOutlet NSMenuItem * _audiotrack;
    IBOutlet NSMenu * _audiotrackMenu;
    IBOutlet NSMenuItem * _channels;
    IBOutlet NSMenu * _channelsMenu;
    IBOutlet NSMenuItem * _audioDevice;
    IBOutlet NSMenu * _audioDeviceMenu;
    IBOutlet NSMenuItem * _visual;
    IBOutlet NSMenu * _visualMenu;

    IBOutlet NSMenu * _videoMenu;
    IBOutlet NSMenuItem * _half_window;
    IBOutlet NSMenuItem * _normal_window;
    IBOutlet NSMenuItem * _double_window;
    IBOutlet NSMenuItem * _fittoscreen;
    IBOutlet NSMenuItem * _fullscreenItem;
    IBOutlet NSMenuItem * _floatontop;
    IBOutlet NSMenuItem * _snapshot;
    IBOutlet NSMenuItem * _videotrack;
    IBOutlet NSMenu * _videotrackMenu;
    IBOutlet NSMenuItem * _screen;
    IBOutlet NSMenu * _screenMenu;
    IBOutlet NSMenuItem * _aspect_ratio;
    IBOutlet NSMenu * _aspect_ratioMenu;
    IBOutlet NSMenuItem * _crop;
    IBOutlet NSMenu * _cropMenu;
    IBOutlet NSMenuItem * _deinterlace;
    IBOutlet NSMenu * _deinterlaceMenu;
    IBOutlet NSMenuItem * _deinterlace_mode;
    IBOutlet NSMenu * _deinterlace_modeMenu;
    IBOutlet NSMenuItem * _postprocessing;
    IBOutlet NSMenu * _postprocessingMenu;

    IBOutlet NSMenu * _subtitlesMenu;
    IBOutlet NSMenuItem * _subtitle_track;
    IBOutlet NSMenu * _subtitle_tracksMenu;
    IBOutlet NSMenuItem * _openSubtitleFile;
    IBOutlet NSMenu * _subtitle_sizeMenu;
    IBOutlet NSMenuItem * _subtitle_size;
    IBOutlet NSMenu * _subtitle_textcolorMenu;
    IBOutlet NSMenuItem * _subtitle_textcolor;
    IBOutlet NSMenu * _subtitle_bgcolorMenu;
    IBOutlet NSMenuItem * _subtitle_bgcolor;
    IBOutlet NSMenuItem * _subtitle_bgopacity;
    IBOutlet NSView * _subtitle_bgopacity_view;
    IBOutlet NSTextField * _subtitle_bgopacityLabel;
    IBOutlet NSTextField * _subtitle_bgopacityLabel_gray;
    IBOutlet NSSlider * _subtitle_bgopacity_sld;
    IBOutlet NSMenu * _subtitle_outlinethicknessMenu;
    IBOutlet NSMenuItem * _subtitle_outlinethickness;
    IBOutlet NSMenuItem * _teletext;
    IBOutlet NSMenuItem * _teletext_transparent;
    IBOutlet NSMenuItem * _teletext_index;
    IBOutlet NSMenuItem * _teletext_red;
    IBOutlet NSMenuItem * _teletext_green;
    IBOutlet NSMenuItem * _teletext_yellow;
    IBOutlet NSMenuItem * _teletext_blue;

    IBOutlet NSMenu * _windowMenu;
    IBOutlet NSMenuItem * _minimize;
    IBOutlet NSMenuItem * _zoom_window;
    IBOutlet NSMenuItem * _player;
    IBOutlet NSMenuItem * _controller;
    IBOutlet NSMenuItem * _audioeffects;
    IBOutlet NSMenuItem * _videoeffects;
    IBOutlet NSMenuItem * _bookmarks;
    IBOutlet NSMenuItem * _playlist;
    IBOutlet NSMenuItem * _info;
    IBOutlet NSMenuItem * _messages;
    IBOutlet NSMenuItem * _bring_atf;

    IBOutlet NSMenu * _helpMenu;
    IBOutlet NSMenuItem * _help;
    IBOutlet NSMenuItem * _readme;
    IBOutlet NSMenuItem * _documentation;
    IBOutlet NSMenuItem * _license;
    IBOutlet NSMenuItem * _website;
    IBOutlet NSMenuItem * _donation;
    IBOutlet NSMenuItem * _forum;
    IBOutlet NSMenuItem * _errorsAndWarnings;

    IBOutlet NSMenuItem * _dockMenuplay;
    IBOutlet NSMenuItem * _dockMenustop;
    IBOutlet NSMenuItem * _dockMenunext;
    IBOutlet NSMenuItem * _dockMenuprevious;
    IBOutlet NSMenuItem * _dockMenumute;

    IBOutlet NSMenu * _voutMenu;
    IBOutlet NSMenuItem * _voutMenuplay;
    IBOutlet NSMenuItem * _voutMenustop;
    IBOutlet NSMenuItem * _voutMenuprev;
    IBOutlet NSMenuItem * _voutMenunext;
    IBOutlet NSMenuItem * _voutMenuvolup;
    IBOutlet NSMenuItem * _voutMenuvoldown;
    IBOutlet NSMenuItem * _voutMenumute;
    IBOutlet NSMenuItem * _voutMenufullscreen;
    IBOutlet NSMenuItem * _voutMenusnapshot;

    IBOutlet NSView * _playlistSaveAccessoryView;
    IBOutlet NSPopUpButton * _playlistSaveAccessoryPopup;
    IBOutlet NSTextField * _playlistSaveAccessoryText;

    AboutWindowController *_aboutWindowController;
    HelpWindowController  *_helpWindowController;
    AddonsWindowController *_addonsController;

    // information for playlist table columns menu
    NSDictionary *_translationsForPlaylistTableColumns;
    NSArray *_menuOrderOfPlaylistTableColumns;

    NSMenu *_playlistTableColumnsContextMenu;

    VLCTimeSelectionPanelController *_timeSelectionPanel;

}

/* main menu */
@property (readwrite, assign) IBOutlet NSMenuItem *about;
@property (readwrite, assign) IBOutlet NSMenuItem *prefs;
@property (readwrite, assign) IBOutlet NSMenuItem *checkForUpdate;
@property (readwrite, assign) IBOutlet NSMenuItem *extensions;
@property (readwrite, assign) IBOutlet NSMenu *extensionsMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *addonManager;
@property (readwrite, assign) IBOutlet NSMenuItem *add_intf;
@property (readwrite, assign) IBOutlet NSMenu *add_intfMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *services;
@property (readwrite, assign) IBOutlet NSMenuItem *hide;
@property (readwrite, assign) IBOutlet NSMenuItem *hide_others;
@property (readwrite, assign) IBOutlet NSMenuItem *show_all;
@property (readwrite, assign) IBOutlet NSMenuItem *quit;

@property (readwrite, assign) IBOutlet NSMenu *fileMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *open_file;
@property (readwrite, assign) IBOutlet NSMenuItem *open_generic;
@property (readwrite, assign) IBOutlet NSMenuItem *open_disc;
@property (readwrite, assign) IBOutlet NSMenuItem *open_net;
@property (readwrite, assign) IBOutlet NSMenuItem *open_capture;
@property (readwrite, assign) IBOutlet NSMenuItem *open_recent;
@property (readwrite, assign) IBOutlet NSMenuItem *close_window;
@property (readwrite, assign) IBOutlet NSMenuItem *convertandsave;
@property (readwrite, assign) IBOutlet NSMenuItem *save_playlist;
@property (readwrite, assign) IBOutlet NSMenuItem *revealInFinder;

@property (readwrite, assign) IBOutlet NSMenu *editMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *cutItem;
@property (readwrite, assign) IBOutlet NSMenuItem *mcopyItem;
@property (readwrite, assign) IBOutlet NSMenuItem *pasteItem;
@property (readwrite, assign) IBOutlet NSMenuItem *clearItem;
@property (readwrite, assign) IBOutlet NSMenuItem *select_all;

@property (readwrite, assign) IBOutlet NSMenu *viewMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *toggleJumpButtons;
@property (readwrite, assign) IBOutlet NSMenuItem *togglePlaymodeButtons;
@property (readwrite, assign) IBOutlet NSMenuItem *toggleEffectsButton;
@property (readwrite, assign) IBOutlet NSMenuItem *toggleSidebar;
@property (readwrite, assign) IBOutlet NSMenu *playlistTableColumnsMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *playlistTableColumns;

@property (readwrite, assign) IBOutlet NSMenu *controlsMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *play;
@property (readwrite, assign) IBOutlet NSMenuItem *stop;
@property (readwrite, assign) IBOutlet NSMenuItem *record;
@property (readwrite, assign) IBOutlet NSMenuItem *rate;
@property (readwrite, assign) IBOutlet NSView *rate_view;
@property (readwrite, assign) IBOutlet NSTextField *rateLabel;
@property (readwrite, assign) IBOutlet NSTextField *rate_slowerLabel;
@property (readwrite, assign) IBOutlet NSTextField *rate_normalLabel;
@property (readwrite, assign) IBOutlet NSTextField *rate_fasterLabel;
@property (readwrite, assign) IBOutlet NSSlider *rate_sld;
@property (readwrite, assign) IBOutlet NSTextField *rateTextField;
@property (readwrite, assign) IBOutlet NSMenuItem *trackSynchronization;
@property (readwrite, assign) IBOutlet NSMenuItem *previous;
@property (readwrite, assign) IBOutlet NSMenuItem *next;
@property (readwrite, assign) IBOutlet NSMenuItem *random;
@property (readwrite, assign) IBOutlet NSMenuItem *repeat;
@property (readwrite, assign) IBOutlet NSMenuItem *loop;
@property (readwrite, assign) IBOutlet NSMenuItem *AtoBloop;
@property (readwrite, assign) IBOutlet NSMenuItem *quitAfterPB;
@property (readwrite, assign) IBOutlet NSMenuItem *fwd;
@property (readwrite, assign) IBOutlet NSMenuItem *bwd;
@property (readwrite, assign) IBOutlet NSMenuItem *jumpToTime;
@property (readwrite, assign) IBOutlet NSMenuItem *program;
@property (readwrite, assign) IBOutlet NSMenu *programMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *title;
@property (readwrite, assign) IBOutlet NSMenu *titleMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *chapter;
@property (readwrite, assign) IBOutlet NSMenu *chapterMenu;

@property (readwrite, assign) IBOutlet NSMenu *audioMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *vol_up;
@property (readwrite, assign) IBOutlet NSMenuItem *vol_down;
@property (readwrite, assign) IBOutlet NSMenuItem *mute;
@property (readwrite, assign) IBOutlet NSMenuItem *audiotrack;
@property (readwrite, assign) IBOutlet NSMenu *audiotrackMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *channels;
@property (readwrite, assign) IBOutlet NSMenu *channelsMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *audioDevice;
@property (readwrite, assign) IBOutlet NSMenu *audioDeviceMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *visual;
@property (readwrite, assign) IBOutlet NSMenu *visualMenu;

@property (readwrite, assign) IBOutlet NSMenu *videoMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *half_window;
@property (readwrite, assign) IBOutlet NSMenuItem *normal_window;
@property (readwrite, assign) IBOutlet NSMenuItem *double_window;
@property (readwrite, assign) IBOutlet NSMenuItem *fittoscreen;
@property (readwrite, assign) IBOutlet NSMenuItem *fullscreenItem;
@property (readwrite, assign) IBOutlet NSMenuItem *floatontop;
@property (readwrite, assign) IBOutlet NSMenuItem *snapshot;
@property (readwrite, assign) IBOutlet NSMenuItem *videotrack;
@property (readwrite, assign) IBOutlet NSMenu *videotrackMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *screen;
@property (readwrite, assign) IBOutlet NSMenu *screenMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *aspect_ratio;
@property (readwrite, assign) IBOutlet NSMenu *aspect_ratioMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *crop;
@property (readwrite, assign) IBOutlet NSMenu *cropMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *deinterlace;
@property (readwrite, assign) IBOutlet NSMenu *deinterlaceMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *deinterlace_mode;
@property (readwrite, assign) IBOutlet NSMenu *deinterlace_modeMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *postprocessing;
@property (readwrite, assign) IBOutlet NSMenu *postprocessingMenu;

@property (readwrite, assign) IBOutlet NSMenu *subtitlesMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *subtitle_track;
@property (readwrite, assign) IBOutlet NSMenu *subtitle_tracksMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *openSubtitleFile;
@property (readwrite, assign) IBOutlet NSMenu *subtitle_sizeMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *subtitle_size;
@property (readwrite, assign) IBOutlet NSMenu *subtitle_textcolorMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *subtitle_textcolor;
@property (readwrite, assign) IBOutlet NSMenu *subtitle_bgcolorMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *subtitle_bgcolor;
@property (readwrite, assign) IBOutlet NSMenuItem *subtitle_bgopacity;
@property (readwrite, assign) IBOutlet NSView *subtitle_bgopacity_view;
@property (readwrite, assign) IBOutlet NSTextField *subtitle_bgopacityLabel;
@property (readwrite, assign) IBOutlet NSTextField *subtitle_bgopacityLabel_gray;
@property (readwrite, assign) IBOutlet NSSlider *subtitle_bgopacity_sld;
@property (readwrite, assign) IBOutlet NSMenu *subtitle_outlinethicknessMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *subtitle_outlinethickness;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext_transparent;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext_index;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext_red;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext_green;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext_yellow;
@property (readwrite, assign) IBOutlet NSMenuItem *teletext_blue;

@property (readwrite, assign) IBOutlet NSMenu *windowMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *minimize;
@property (readwrite, assign) IBOutlet NSMenuItem *zoom_window;
@property (readwrite, assign) IBOutlet NSMenuItem *player;
@property (readwrite, assign) IBOutlet NSMenuItem *controller;
@property (readwrite, assign) IBOutlet NSMenuItem *audioeffects;
@property (readwrite, assign) IBOutlet NSMenuItem *videoeffects;
@property (readwrite, assign) IBOutlet NSMenuItem *bookmarks;
@property (readwrite, assign) IBOutlet NSMenuItem *playlist;
@property (readwrite, assign) IBOutlet NSMenuItem *info;
@property (readwrite, assign) IBOutlet NSMenuItem *messages;
@property (readwrite, assign) IBOutlet NSMenuItem *bring_atf;

@property (readwrite, assign) IBOutlet NSMenu *helpMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *help;
@property (readwrite, assign) IBOutlet NSMenuItem *readme;
@property (readwrite, assign) IBOutlet NSMenuItem *documentation;
@property (readwrite, assign) IBOutlet NSMenuItem *license;
@property (readwrite, assign) IBOutlet NSMenuItem *website;
@property (readwrite, assign) IBOutlet NSMenuItem *donation;
@property (readwrite, assign) IBOutlet NSMenuItem *forum;
@property (readwrite, assign) IBOutlet NSMenuItem *errorsAndWarnings;

/* dock menu */
@property (readwrite, assign) IBOutlet NSMenuItem *dockMenuplay;
@property (readwrite, assign) IBOutlet NSMenuItem *dockMenustop;
@property (readwrite, assign) IBOutlet NSMenuItem *dockMenunext;
@property (readwrite, assign) IBOutlet NSMenuItem *dockMenuprevious;
@property (readwrite, assign) IBOutlet NSMenuItem *dockMenumute;

/* vout menu */
@property (readwrite, assign) IBOutlet NSMenu *voutMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenuplay;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenustop;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenuprev;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenunext;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenuvolup;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenuvoldown;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenumute;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenufullscreen;
@property (readwrite, assign) IBOutlet NSMenuItem *voutMenusnapshot;

@property (readwrite, assign) IBOutlet NSView *playlistSaveAccessoryView;
@property (readwrite, assign) IBOutlet NSPopUpButton *playlistSaveAccessoryPopup;
@property (readwrite, assign) IBOutlet NSTextField *playlistSaveAccessoryText;

- (void)releaseRepresentedObjects:(NSMenu *)the_menu;

- (void)setupMenus;
- (void)setSubmenusEnabled:(BOOL)b_enabled;
- (void)setRateControlsEnabled:(BOOL)b_enabled;
- (void)updateSidebarMenuItem;

- (IBAction)openAddonManager:(id)sender;

- (IBAction)intfOpenFile:(id)sender;
- (IBAction)intfOpenFileGeneric:(id)sender;
- (IBAction)intfOpenDisc:(id)sender;
- (IBAction)intfOpenNet:(id)sender;
- (IBAction)intfOpenCapture:(id)sender;
- (IBAction)savePlaylist:(id)sender;
- (IBAction)revealItemInFinder:(id)sender;

- (IBAction)toggleEffectsButton:(id)sender;
- (IBAction)toggleJumpButtons:(id)sender;
- (IBAction)togglePlaymodeButtons:(id)sender;
- (IBAction)toggleSidebar:(id)sender;
- (BOOL)setPlaylistColumnTableState:(NSInteger)i_state forColumn:(NSString *)o_column;
- (NSMenu *)setupPlaylistTableColumnsMenu;

- (IBAction)play:(id)sender;
- (IBAction)stop:(id)sender;

- (IBAction)prev:(id)sender;
- (IBAction)next:(id)sender;
- (IBAction)random:(id)sender;
- (IBAction)repeat:(id)sender;
- (IBAction)loop:(id)sender;

- (IBAction)forward:(id)sender;
- (IBAction)backward:(id)sender;

- (IBAction)volumeUp:(id)sender;
- (IBAction)volumeDown:(id)sender;
- (IBAction)mute:(id)sender;

- (IBAction)goToSpecificTime:(id)sender;

- (IBAction)quitAfterPlayback:(id)sender;
- (IBAction)toggleRecord:(id)sender;
- (void)updateRecordState:(BOOL)b_value;
- (IBAction)setPlaybackRate:(id)sender;
- (void)updatePlaybackRate;
- (IBAction)toggleAtoBloop:(id)sender;

- (IBAction)toggleFullscreen:(id)sender;
- (IBAction)resizeVideoWindow:(id)sender;
- (IBAction)floatOnTop:(id)sender;
- (IBAction)createVideoSnapshot:(id)sender;

- (IBAction)addSubtitleFile:(id)sender;
- (IBAction)switchSubtitleBackgroundOpacity:(id)sender;
- (IBAction)telxTransparent:(id)sender;
- (IBAction)telxNavLink:(id)sender;

- (IBAction)showConvertAndSave:(id)sender;
- (IBAction)showVideoEffects:(id)sender;
- (IBAction)showAudioEffects:(id)sender;
- (IBAction)showTrackSynchronization:(id)sender;
- (IBAction)showBookmarks:(id)sender;
- (IBAction)showInformationPanel:(id)sender;

- (IBAction)showAbout:(id)sender;
- (IBAction)showLicense:(id)sender;
- (IBAction)showPreferences:(id)sender;
- (IBAction)showHelp:(id)sender;
- (IBAction)openReadMe:(id)sender;
- (IBAction)openDocumentation:(id)sender;
- (IBAction)openWebsite:(id)sender;
- (IBAction)openForum:(id)sender;
- (IBAction)openDonate:(id)sender;
- (IBAction)showErrorsAndWarnings:(id)sender;
- (IBAction)showMessagesPanel:(id)showMessagesPanel;
- (IBAction)showMainWindow:(id)sender;
- (IBAction)showPlaylist:(id)sender;

- (void)setPlay;
- (void)setPause;
- (void)setRepeatOne;
- (void)setRepeatAll;
- (void)setRepeatOff;
- (void)setShuffle;

- (void)initStrings;

- (void)refreshAudioDeviceList;

- (void)setupPlaylistTableColumnsForMenu:(NSMenu *)menu;

- (void)setupMenu:(NSMenu*)menu withIntList:(char *)psz_name andSelector:(SEL)selector;

- (void)setupVarMenu:(NSMenu *)menu
         forMenuItem: (NSMenuItem *)parent
              target:(vlc_object_t *)p_object
                 var:(const char *)psz_variable
            selector:(SEL)pf_callback;

- (void)setupVarMenuItem:(NSMenuItem *)mi
                  target:(vlc_object_t *)p_object
                     var:(const char *)psz_variable
                selector:(SEL)pf_callback;

- (void)refreshVoutDeviceMenu:(NSNotification *)notification;

@end

/*****************************************************************************
 *VLCAutoGeneratedMenuContent interface
 *****************************************************************************
 *This holds our data for autogenerated menus
 *****************************************************************************/
@interface VLCAutoGeneratedMenuContent : NSObject {
    char *psz_name;
    vlc_object_t *vlc_object;
    vlc_value_t value;
    int i_type;
}

- (id)initWithVariableName: (const char *)name
                  ofObject: (vlc_object_t *)object
                  andValue: (vlc_value_t)value
                    ofType: (int)type;
- (const char *)name;
- (vlc_value_t)value;
- (vlc_object_t *)vlcObject;
- (int)type;

@end
