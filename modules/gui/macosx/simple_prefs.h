/*****************************************************************************
* simple_prefs.h: Simple Preferences for Mac OS X
*****************************************************************************
* Copyright (C) 2008-2014 VLC authors and VideoLAN
* $Id$
*
* Authors: Felix Paul Kühne <fkuehne at videolan dot org>
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
#import "intf.h"
#import <vlc_common.h>

@interface VLCSimplePrefs : NSWindowController <NSToolbarDelegate, NSWindowDelegate> {

    BOOL _audioSettingChanged;
    BOOL _intfSettingChanged;
    BOOL _videoSettingChanged;
    BOOL _osdSettingChanged;
    BOOL _inputSettingChanged;
    BOOL _hotkeyChanged;
    id _currentlyShownCategoryView;

    NSOpenPanel *_selectFolderPanel;
    NSArray *_hotkeyDescriptions;
    NSArray *_hotkeyNames;
    NSArray *_hotkeysNonUseableKeys;
    NSMutableArray *_hotkeySettings;
    NSString *_keyInTransition;

    intf_thread_t *p_intf;

    // ivars for properties

    IBOutlet NSPopUpButton * _audio_dolbyPopup;
    IBOutlet NSTextField * _audio_dolbyLabel;
    IBOutlet NSBox * _audio_effectsBox;
    IBOutlet NSButton * _audio_enableCheckbox;
    IBOutlet NSBox * _audio_generalBox;
    IBOutlet NSTextField * _audio_langTextField;
    IBOutlet NSTextField * _audio_langLabel;
    IBOutlet NSBox * _audio_lastBox;
    IBOutlet NSButton * _audio_lastCheckbox;
    IBOutlet NSSecureTextField * _audio_lastpwdSecureTextField;
    IBOutlet NSTextField * _audio_lastpwdLabel;
    IBOutlet NSTextField * _audio_lastuserTextField;
    IBOutlet NSTextField * _audio_lastuserLabel;
    IBOutlet NSButton * _audio_spdifCheckbox;
    IBOutlet NSView * _audioView;
    IBOutlet NSPopUpButton * _audio_visualPopup;
    IBOutlet NSTextField * _audio_visualLabel;
    IBOutlet NSTextField * _audio_volTextField;
    IBOutlet NSSlider * _audio_volSlider;
    IBOutlet NSMatrix * _audio_autosavevolMatrix;
    IBOutlet NSButtonCell * _audio_autosavevol_yesButtonCell;
    IBOutlet NSButtonCell * _audio_autosavevol_noButtonCell;

    IBOutlet NSButton * _hotkeys_changeButton;
    IBOutlet NSTextField * _hotkeys_changeLabel;
    IBOutlet NSTextField * _hotkeys_change_keysLabel;
    IBOutlet NSTextField * _hotkeys_change_takenLabel;
    IBOutlet NSWindow * _hotkeys_change_win;
    IBOutlet NSButton * _hotkeys_change_cancelButton;
    IBOutlet NSButton * _hotkeys_change_okButton;
    IBOutlet NSButton * _hotkeys_clearButton;
    IBOutlet NSTextField * _hotkeysLabel;
    IBOutlet NSTableView * _hotkeys_listbox;
    IBOutlet NSView * _hotkeysView;

    IBOutlet NSBox * _input_recordBox;
    IBOutlet NSTextField * _input_recordTextField;
    IBOutlet NSButton * _input_recordButton;
    IBOutlet NSPopUpButton * _input_aviPopup;
    IBOutlet NSTextField * _input_aviLabel;
    IBOutlet NSPopUpButton * _input_cachelevelPopup;
    IBOutlet NSTextField * _input_cachelevelLabel;
    IBOutlet NSTextField * _input_cachelevel_customLabel;
    IBOutlet NSBox * _input_cachingBox;
    IBOutlet NSBox * _input_muxBox;
    IBOutlet NSBox * _input_netBox;
    IBOutlet NSTextField * _input_avcodec_hwLabel;
    IBOutlet NSPopUpButton * _input_avcodec_hwPopup;
    IBOutlet NSTextField * _input_postprocTextField;
    IBOutlet NSTextField * _input_postprocLabel;
    IBOutlet NSButton * _input_rtspCheckbox;
    IBOutlet NSTextField * _input_skipLoopLabel;
    IBOutlet NSPopUpButton * _input_skipLoopPopup;
    IBOutlet NSButton * _input_mkv_preload_dirCheckbox;
    IBOutlet NSButton * _input_urlhandlerButton;
    IBOutlet NSView * _inputView;

    IBOutlet NSPopUpButton * _intf_languagePopup;
    IBOutlet NSTextField * _intf_languageLabel;
    IBOutlet NSTextField * _intf_styleLabel;
    IBOutlet NSButtonCell * _intf_style_darkButtonCell;
    IBOutlet NSButtonCell * _intf_style_brightButtonCell;
    IBOutlet NSButton * _intf_artCheckbox;
    IBOutlet NSButton * _intf_embeddedCheckbox;
    IBOutlet NSButton * _intf_fspanelCheckbox;
    IBOutlet NSButton * _intf_appleremoteCheckbox;
    IBOutlet NSButton * _intf_appleremote_sysvolCheckbox;
    IBOutlet NSButton * _intf_mediakeysCheckbox;
    IBOutlet NSBox * _intf_networkBox;
    IBOutlet NSView * _intfView;
    IBOutlet NSButton * _intf_updateCheckbox;
    IBOutlet NSTextField * _intf_last_updateLabel;
    IBOutlet NSButton * _intf_enableNotificationsCheckbox;
    IBOutlet NSButton * _intf_nativefullscreenCheckbox;
    IBOutlet NSButton * _intf_autoresizeCheckbox;
    IBOutlet NSButton * _intf_pauseminimizedCheckbox;
    IBOutlet NSBox * _intf_luahttpBox;
    IBOutlet NSTextField * _intf_luahttppwdLabel;
    IBOutlet NSTextField * _intf_luahttppwdTextField;
    IBOutlet NSTextField * _intf_pauseitunesLabel;
    IBOutlet NSPopUpButton * _intf_pauseitunesPopup;
    IBOutlet NSTextField * _intf_continueplaybackLabel;
    IBOutlet NSPopUpButton * _intf_continueplaybackPopup;

    IBOutlet NSPopUpButton * _osd_encodingPopup;
    IBOutlet NSTextField * _osd_encodingLabel;
    IBOutlet NSBox * _osd_fontBox;
    IBOutlet NSButton * _osd_fontButton;
    IBOutlet NSPopUpButton * _osd_font_colorPopup;
    IBOutlet NSTextField * _osd_font_colorLabel;
    IBOutlet NSTextField * _osd_fontTextField;
    IBOutlet NSPopUpButton * _osd_font_sizePopup;
    IBOutlet NSTextField * _osd_font_sizeLabel;
    IBOutlet NSTextField * _osd_fontLabel;
    IBOutlet NSBox * _osd_langBox;
    IBOutlet NSTextField * _osd_langTextField;
    IBOutlet NSTextField * _osd_langLabel;
    IBOutlet NSTextField * _osd_opacityLabel;
    IBOutlet NSTextField * _osd_opacityTextField;
    IBOutlet NSSlider * _osd_opacitySlider;
    IBOutlet NSPopUpButton * _osd_outline_colorPopup;
    IBOutlet NSTextField * _osd_outline_colorLabel;
    IBOutlet NSPopUpButton * _osd_outline_thicknessPopup;
    IBOutlet NSTextField * _osd_outline_thicknessLabel;
    IBOutlet NSButton * _osd_forceboldCheckbox;
    IBOutlet NSBox * _osd_osdBox;
    IBOutlet NSButton * _osd_osdCheckbox;
    IBOutlet NSView * _osdView;

    IBOutlet NSButton * _showAllButton;
    IBOutlet NSButton * _cancelButton;
    IBOutlet NSBox * _controlsBox;
    IBOutlet NSButton * _resetButton;
    IBOutlet NSButton * _saveButton;

    IBOutlet NSButton * _video_blackCheckbox;
    IBOutlet NSPopUpButton * _video_devicePopup;
    IBOutlet NSTextField * _video_deviceLabel;
    IBOutlet NSBox * _video_displayBox;
    IBOutlet NSButton * _video_enableCheckbox;
    IBOutlet NSButton * _video_fullscreenCheckbox;
    IBOutlet NSButton * _video_videodecoCheckbox;
    IBOutlet NSButton * _video_onTopCheckbox;
    IBOutlet NSButton * _video_skipFramesCheckbox;
    IBOutlet NSBox * _video_snapBox;
    IBOutlet NSButton * _video_snap_folderButton;
    IBOutlet NSTextField * _video_snap_folderTextField;
    IBOutlet NSTextField * _video_snap_folderLabel;
    IBOutlet NSPopUpButton * _video_snap_formatPopup;
    IBOutlet NSTextField * _video_snap_formatLabel;
    IBOutlet NSTextField * _video_snap_prefixTextField;
    IBOutlet NSTextField * _video_snap_prefixLabel;
    IBOutlet NSButton * _video_snap_seqnumCheckbox;
    IBOutlet NSTextField * _video_deinterlaceLabel;
    IBOutlet NSPopUpButton * _video_deinterlacePopup;
    IBOutlet NSTextField * _video_deinterlace_modeLabel;
    IBOutlet NSPopUpButton * _video_deinterlace_modePopup;
    IBOutlet NSBox * _video_videoBox;
    IBOutlet NSView * _videoView;

    IBOutlet NSTextField * _urlhandler_titleLabel;
    IBOutlet NSTextField * _urlhandler_subtitleLabel;
    IBOutlet NSButton * _urlhandler_saveButton;
    IBOutlet NSButton * _urlhandler_cancelButton;
    IBOutlet NSPopUpButton * _urlhandler_ftpPopup;
    IBOutlet NSPopUpButton * _urlhandler_mmsPopup;
    IBOutlet NSPopUpButton * _urlhandler_rtmpPopup;
    IBOutlet NSPopUpButton * _urlhandler_rtpPopup;
    IBOutlet NSPopUpButton * _urlhandler_rtspPopup;
    IBOutlet NSPopUpButton * _urlhandler_sftpPopup;
    IBOutlet NSPopUpButton * _urlhandler_smbPopup;
    IBOutlet NSPopUpButton * _urlhandler_udpPopup;
    IBOutlet NSWindow * _urlhandler_win;

}

@property (readwrite, assign) IBOutlet NSPopUpButton *audio_dolbyPopup;
@property (readwrite, assign) IBOutlet NSTextField *audio_dolbyLabel;
@property (readwrite, assign) IBOutlet NSBox *audio_effectsBox;
@property (readwrite, assign) IBOutlet NSButton *audio_enableCheckbox;
@property (readwrite, assign) IBOutlet NSBox *audio_generalBox;
@property (readwrite, assign) IBOutlet NSTextField *audio_langTextField;
@property (readwrite, assign) IBOutlet NSTextField *audio_langLabel;
@property (readwrite, assign) IBOutlet NSBox *audio_lastBox;
@property (readwrite, assign) IBOutlet NSButton *audio_lastCheckbox;
@property (readwrite, assign) IBOutlet NSSecureTextField *audio_lastpwdSecureTextField;
@property (readwrite, assign) IBOutlet NSTextField *audio_lastpwdLabel;
@property (readwrite, assign) IBOutlet NSTextField *audio_lastuserTextField;
@property (readwrite, assign) IBOutlet NSTextField *audio_lastuserLabel;
@property (readwrite, assign) IBOutlet NSButton *audio_spdifCheckbox;
@property (readwrite, assign) IBOutlet NSView *audioView;
@property (readwrite, assign) IBOutlet NSPopUpButton *audio_visualPopup;
@property (readwrite, assign) IBOutlet NSTextField *audio_visualLabel;
@property (readwrite, assign) IBOutlet NSTextField *audio_volTextField;
@property (readwrite, assign) IBOutlet NSSlider *audio_volSlider;
@property (readwrite, assign) IBOutlet NSMatrix *audio_autosavevolMatrix;
@property (readwrite, assign) IBOutlet NSButtonCell *audio_autosavevol_yesButtonCell;
@property (readwrite, assign) IBOutlet NSButtonCell *audio_autosavevol_noButtonCell;

@property (readwrite, assign) IBOutlet NSButton *hotkeys_changeButton;
@property (readwrite, assign) IBOutlet NSTextField *hotkeys_changeLabel;
@property (readwrite, assign) IBOutlet NSTextField *hotkeys_change_keysLabel;
@property (readwrite, assign) IBOutlet NSTextField *hotkeys_change_takenLabel;
@property (readwrite, assign) IBOutlet NSWindow *hotkeys_change_win;
@property (readwrite, assign) IBOutlet NSButton *hotkeys_change_cancelButton;
@property (readwrite, assign) IBOutlet NSButton *hotkeys_change_okButton;
@property (readwrite, assign) IBOutlet NSButton *hotkeys_clearButton;
@property (readwrite, assign) IBOutlet NSTextField *hotkeysLabel;
@property (readwrite, assign) IBOutlet NSTableView *hotkeys_listbox;
@property (readwrite, assign) IBOutlet NSView *hotkeysView;

@property (readwrite, assign) IBOutlet NSBox *input_recordBox;
@property (readwrite, assign) IBOutlet NSTextField *input_recordTextField;
@property (readwrite, assign) IBOutlet NSButton *input_recordButton;
@property (readwrite, assign) IBOutlet NSPopUpButton *input_aviPopup;
@property (readwrite, assign) IBOutlet NSTextField *input_aviLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *input_cachelevelPopup;
@property (readwrite, assign) IBOutlet NSTextField *input_cachelevelLabel;
@property (readwrite, assign) IBOutlet NSTextField *input_cachelevel_customLabel;
@property (readwrite, assign) IBOutlet NSBox *input_cachingBox;
@property (readwrite, assign) IBOutlet NSBox *input_muxBox;
@property (readwrite, assign) IBOutlet NSBox *input_netBox;
@property (readwrite, assign) IBOutlet NSTextField *input_avcodec_hwLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *input_avcodec_hwPopup;
@property (readwrite, assign) IBOutlet NSTextField *input_postprocTextField;
@property (readwrite, assign) IBOutlet NSTextField *input_postprocLabel;
@property (readwrite, assign) IBOutlet NSButton *input_rtspCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *input_skipLoopLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *input_skipLoopPopup;
@property (readwrite, assign) IBOutlet NSButton *input_mkv_preload_dirCheckbox;
@property (readwrite, assign) IBOutlet NSButton *input_urlhandlerButton;
@property (readwrite, assign) IBOutlet NSView *inputView;

@property (readwrite, assign) IBOutlet NSPopUpButton *intf_languagePopup;
@property (readwrite, assign) IBOutlet NSTextField *intf_languageLabel;
@property (readwrite, assign) IBOutlet NSTextField *intf_styleLabel;
@property (readwrite, assign) IBOutlet NSButtonCell *intf_style_darkButtonCell;
@property (readwrite, assign) IBOutlet NSButtonCell *intf_style_brightButtonCell;
@property (readwrite, assign) IBOutlet NSButton *intf_artCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_embeddedCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_fspanelCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_appleremoteCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_appleremote_sysvolCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_mediakeysCheckbox;
@property (readwrite, assign) IBOutlet NSBox *intf_networkBox;
@property (readwrite, assign) IBOutlet NSView *intfView;
@property (readwrite, assign) IBOutlet NSButton *intf_updateCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *intf_last_updateLabel;
@property (readwrite, assign) IBOutlet NSButton *intf_enableNotificationsCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_nativefullscreenCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_autoresizeCheckbox;
@property (readwrite, assign) IBOutlet NSButton *intf_pauseminimizedCheckbox;
@property (readwrite, assign) IBOutlet NSBox *intf_luahttpBox;
@property (readwrite, assign) IBOutlet NSTextField *intf_luahttppwdLabel;
@property (readwrite, assign) IBOutlet NSTextField *intf_luahttppwdTextField;
@property (readwrite, assign) IBOutlet NSTextField *intf_pauseitunesLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *intf_pauseitunesPopup;
@property (readwrite, assign) IBOutlet NSTextField *intf_continueplaybackLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *intf_continueplaybackPopup;

@property (readwrite, assign) IBOutlet NSPopUpButton *osd_encodingPopup;
@property (readwrite, assign) IBOutlet NSTextField *osd_encodingLabel;
@property (readwrite, assign) IBOutlet NSBox *osd_fontBox;
@property (readwrite, assign) IBOutlet NSButton *osd_fontButton;
@property (readwrite, assign) IBOutlet NSPopUpButton *osd_font_colorPopup;
@property (readwrite, assign) IBOutlet NSTextField *osd_font_colorLabel;
@property (readwrite, assign) IBOutlet NSTextField *osd_fontTextField;
@property (readwrite, assign) IBOutlet NSPopUpButton *osd_font_sizePopup;
@property (readwrite, assign) IBOutlet NSTextField *osd_font_sizeLabel;
@property (readwrite, assign) IBOutlet NSTextField *osd_fontLabel;
@property (readwrite, assign) IBOutlet NSBox *osd_langBox;
@property (readwrite, assign) IBOutlet NSTextField *osd_langTextField;
@property (readwrite, assign) IBOutlet NSTextField *osd_langLabel;
@property (readwrite, assign) IBOutlet NSTextField *osd_opacityLabel;
@property (readwrite, assign) IBOutlet NSTextField *osd_opacityTextField;
@property (readwrite, assign) IBOutlet NSSlider *osd_opacitySlider;
@property (readwrite, assign) IBOutlet NSPopUpButton *osd_outline_colorPopup;
@property (readwrite, assign) IBOutlet NSTextField *osd_outline_colorLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *osd_outline_thicknessPopup;
@property (readwrite, assign) IBOutlet NSTextField *osd_outline_thicknessLabel;
@property (readwrite, assign) IBOutlet NSButton *osd_forceboldCheckbox;
@property (readwrite, assign) IBOutlet NSBox *osd_osdBox;
@property (readwrite, assign) IBOutlet NSButton *osd_osdCheckbox;
@property (readwrite, assign) IBOutlet NSView *osdView;

@property (readwrite, assign) IBOutlet NSButton *showAllButton;
@property (readwrite, assign) IBOutlet NSButton *cancelButton;
@property (readwrite, assign) IBOutlet NSBox *controlsBox;
@property (readwrite, assign) IBOutlet NSButton *resetButton;
@property (readwrite, assign) IBOutlet NSButton *saveButton;

@property (readwrite, assign) IBOutlet NSButton *video_blackCheckbox;
@property (readwrite, assign) IBOutlet NSPopUpButton *video_devicePopup;
@property (readwrite, assign) IBOutlet NSTextField *video_deviceLabel;
@property (readwrite, assign) IBOutlet NSBox *video_displayBox;
@property (readwrite, assign) IBOutlet NSButton *video_enableCheckbox;
@property (readwrite, assign) IBOutlet NSButton *video_fullscreenCheckbox;
@property (readwrite, assign) IBOutlet NSButton *video_videodecoCheckbox;
@property (readwrite, assign) IBOutlet NSButton *video_onTopCheckbox;
@property (readwrite, assign) IBOutlet NSButton *video_skipFramesCheckbox;
@property (readwrite, assign) IBOutlet NSBox *video_snapBox;
@property (readwrite, assign) IBOutlet NSButton *video_snap_folderButton;
@property (readwrite, assign) IBOutlet NSTextField *video_snap_folderTextField;
@property (readwrite, assign) IBOutlet NSTextField *video_snap_folderLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *video_snap_formatPopup;
@property (readwrite, assign) IBOutlet NSTextField *video_snap_formatLabel;
@property (readwrite, assign) IBOutlet NSTextField *video_snap_prefixTextField;
@property (readwrite, assign) IBOutlet NSTextField *video_snap_prefixLabel;
@property (readwrite, assign) IBOutlet NSButton *video_snap_seqnumCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *video_deinterlaceLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *video_deinterlacePopup;
@property (readwrite, assign) IBOutlet NSTextField *video_deinterlace_modeLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *video_deinterlace_modePopup;
@property (readwrite, assign) IBOutlet NSBox *video_videoBox;
@property (readwrite, assign) IBOutlet NSView *videoView;

@property (readwrite, assign) IBOutlet NSTextField *urlhandler_titleLabel;
@property (readwrite, assign) IBOutlet NSTextField *urlhandler_subtitleLabel;
@property (readwrite, assign) IBOutlet NSButton *urlhandler_saveButton;
@property (readwrite, assign) IBOutlet NSButton *urlhandler_cancelButton;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_ftpPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_mmsPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_rtmpPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_rtpPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_rtspPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_sftpPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_smbPopup;
@property (readwrite, assign) IBOutlet NSPopUpButton *urlhandler_udpPopup;
@property (readwrite, assign) IBOutlet NSWindow *urlhandler_win;

/* toolbar */
- (NSToolbarItem *)toolbar:(NSToolbar *)o_toolbar
     itemForItemIdentifier:(NSString *)o_itemIdent
 willBeInsertedIntoToolbar:(BOOL)b_willBeInserted;
- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar *)toolbar;
- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar *)toolbar;

- (void)showSimplePrefs;
- (void)showSimplePrefsWithLevel:(NSInteger)i_window_level;

- (IBAction)buttonAction:(id)sender;
- (IBAction)resetPreferences:(id)sender;
- (void)sheetDidEnd:(NSWindow *)o_sheet
         returnCode:(int)i_return
        contextInfo:(void *)o_context;

/* interface */
- (IBAction)interfaceSettingChanged:(id)sender;

/* audio */
- (IBAction)audioSettingChanged:(id)sender;

/* video */
- (IBAction)videoSettingChanged:(id)sender;

/* OSD / subtitles */
- (IBAction)osdSettingChanged:(id)sender;
- (IBAction)showFontPicker:(id)sender;
- (void)changeFont:(id)sender;

/* input & codecs */
- (IBAction)inputSettingChanged:(id)sender;
- (IBAction)urlHandlerAction:(id)sender;

/* hotkeys */
- (IBAction)hotkeySettingChanged:(id)sender;
- (BOOL)changeHotkeyTo: (NSString *)theKey;

- (void)initStrings;
- (void)saveChangedSettings;
- (void)showInterfaceSettings;

- (void)enableLionFullscreenMode: (BOOL)_value;

@end

@interface VLCHotkeyChangeWindow : NSWindow

@end

@interface VLCSimplePrefsWindow : NSWindow

@end
