/*****************************************************************************
 * open.h: Open dialogues for VLC's MacOS X port
 *****************************************************************************
 * Copyright (C) 2002-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Jon Lech Johansen <jon-vl@nanocrew.net>
 *          Christophe Massiot <massiot@via.ecp.fr>
 *          Derk-Jan Hartman <thedj@users.sourceforge.net>
 *          Felix Paul Kühne <fkuehne at videolan dot org>
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

#import "output.h"
#import "eyetv.h"

struct display_info_t
{
    CGRect rect;
    CGDirectDisplayID id;
};

@interface VLCOpen : NSWindowController {

    VLCOutput *_output;
    BOOL b_outputNibLoaded;
    NSArray *_qtkvideoDevices;
    NSArray *_qtkaudioDevices;
    NSString *_qtkCurrentDeviceUID;
    NSString *_qtkCurrentAudioDeviceUID;

    BOOL b_autoplay;
    BOOL b_nodvdmenus;
    NSView *_currentOpticalMediaView;
    NSImageView *_currentOpticalMediaIconView;
    NSMutableArray *_allMediaDevices;
    NSArray *_opticalDevices;
    NSMutableArray *_specialMediaFolders;
    NSString *_filePath;
    NSView *_currentCaptureView;
    NSString *_fileSlavePath;
    NSString *_subPath;
    NSString *_MRL;
    NSMutableArray *_displayInfos;
    VLCEyeTVController *_eyeTVController;
    
    // ivars for properties
    
    IBOutlet NSTextField * _mrlTextField;
    IBOutlet NSTextField * _mrlLabel;
    IBOutlet NSView * _mrlView;
    IBOutlet NSButton * _mrlButton;
    IBOutlet NSTabView * _tabView;

    IBOutlet NSButton * _okButton;
    IBOutlet NSButton * _cancelButton;

    IBOutlet NSButton * _outputCheckbox;
    IBOutlet NSButton * _outputSettingsButton;

    IBOutlet NSTextField * _fileNameLabel;
    IBOutlet NSTextField * _fileNameStubLabel;
    IBOutlet NSImageView * _fileIconWell;
    IBOutlet NSButton * _fileBrowseButton;
    IBOutlet NSButton * _fileTreatAsPipeButton;
    IBOutlet NSButton * _fileSlaveCheckbox;
    IBOutlet NSButton * _fileSelectSlaveButton;
    IBOutlet NSTextField * _fileSlaveFilenameLabel;
    IBOutlet NSImageView * _fileSlaveIconWell;
    IBOutlet NSTextField * _fileSubtitlesFilenameLabel;
    IBOutlet NSImageView * _fileSubtitlesIconWell;
    IBOutlet NSButton * _fileCustomTimingCheckbox;
    IBOutlet NSTextField * _fileStartTimeTextField;
    IBOutlet NSTextField * _fileStartTimeLabel;
    IBOutlet NSTextField * _fileStopTimeTextField;
    IBOutlet NSTextField * _fileStopTimeLabel;

    IBOutlet NSPopUpButton * _discSelectorPopup;

    IBOutlet NSView * _discNoDiscView;
    IBOutlet NSTextField * _discNoDiscLabel;
    IBOutlet NSButton * _discNoDiscVideoTSButton;

    IBOutlet NSView * _discAudioCDView;
    IBOutlet NSTextField * _discAudioCDLabel;
    IBOutlet NSTextField * _discAudioCDTrackCountLabel;
    IBOutlet NSButton * _discAudioCDVideoTSButton;

    IBOutlet NSView * _discDVDView;
    IBOutlet NSTextField * _discDVDLabel;
    IBOutlet NSButton * _discDVDDisableMenusButton;
    IBOutlet NSButton * _discDVDVideoTSButton;

    IBOutlet NSView * _discDVDwomenusView;
    IBOutlet NSTextField * _discDVDwomenusLabel;
    IBOutlet NSButton * _discDVDwomenusEnableMenusButton;
    IBOutlet NSButton * _discDVDwomenusVideoTSButton;
    IBOutlet NSTextField * _discDVDwomenusTitleTextField;
    IBOutlet NSTextField * _discDVDwomenusTitleLabel;
    IBOutlet NSStepper * _discDVDwomenusTitleStepper;
    IBOutlet NSTextField * _discDVDwomenusChapterTextField;
    IBOutlet NSTextField * _discDVDwomenusChapterLabel;
    IBOutlet NSStepper * _discDVDwomenusChapterStepper;

    IBOutlet NSView * _discVCDView;
    IBOutlet NSTextField * _discVCDLabel;
    IBOutlet NSButton * _discVCDVideoTSButton;
    IBOutlet NSTextField * _discVCDTitleTextField;
    IBOutlet NSTextField * _discVCDTitleLabel;
    IBOutlet NSStepper * _discVCDTitleStepper;
    IBOutlet NSTextField * _discVCDChapterTextField;
    IBOutlet NSTextField * _discVCDChapterLabel;
    IBOutlet NSStepper * _discVCDChapterStepper;

    IBOutlet NSView * _discBDView;
    IBOutlet NSTextField * _discBDLabel;
    IBOutlet NSButton * _discBDVideoTSButton;

    IBOutlet NSTextField * _netHTTPURLLabel;
    IBOutlet NSTextField * _netHTTPURLTextField;
    IBOutlet NSTextField * _netHelpLabel;

    IBOutlet NSTextField * _netHelpUDPLabel;
    IBOutlet NSMatrix * _netUDPProtocolMatrix;
    IBOutlet NSTextField * _netUDPProtocolLabel;
    IBOutlet NSTextField * _netUDPAddressLabel;
    IBOutlet NSTextField * _netUDPModeLabel;
    IBOutlet NSMatrix * _netModeMatrix;
    IBOutlet NSButton * _netOpenUDPButton;
    IBOutlet NSButton * _netUDPCancelButton;
    IBOutlet NSButton * _netUDPOKButton;
    IBOutlet NSWindow * _netUDPPanel;
    IBOutlet NSTextField * _netUDPPortTextField;
    IBOutlet NSTextField * _netUDPPortLabel;
    IBOutlet NSStepper * _netUDPPortStepper;
    IBOutlet NSTextField * _netUDPMAddressTextField;
    IBOutlet NSTextField * _netUDPMAddressLabel;
    IBOutlet NSTextField * _netUDPMPortTextField;
    IBOutlet NSTextField * _netUDPMPortLabel;
    IBOutlet NSStepper * _netUDPMPortStepper;

    IBOutlet NSButton * _fileSubCheckbox;
    IBOutlet NSButton * _fileSubSettingsButton;
    IBOutlet NSPanel * _fileSubSheet;
    IBOutlet NSTextField * _fileSubPathLabel;
    IBOutlet NSTextField * _fileSubPathTextField;
    IBOutlet NSImageView * _fileSubIconView;
    IBOutlet NSButton * _fileSubBrowseButton;
    IBOutlet NSButton * _fileSubOverrideCheckbox;
    IBOutlet NSTextField * _fileSubDelayTextField;
    IBOutlet NSTextField * _fileSubDelayLabel;
    IBOutlet NSStepper * _fileSubDelayStepper;
    IBOutlet NSTextField * _fileSubFPSTextField;
    IBOutlet NSTextField * _fileSubFPSLabel;
    IBOutlet NSStepper * _fileSubFPSStepper;
    IBOutlet NSPopUpButton * _fileSubEncodingPopup;
    IBOutlet NSTextField * _fileSubEncodingLabel;
    IBOutlet NSPopUpButton * _fileSubSizePopup;
    IBOutlet NSTextField * _fileSubSizeLabel;
    IBOutlet NSPopUpButton * _fileSubAlignPopup;
    IBOutlet NSTextField * _fileSubAlignLabel;
    IBOutlet NSButton * _fileSubOKButton;
    IBOutlet NSBox * _fileSubFontBox;
    IBOutlet NSBox * _fileSubFileBox;

    IBOutlet NSTextField * _captureLabel;
    IBOutlet NSTextField * _captureLongLabel;
    IBOutlet NSPopUpButton * _captureModePopup;
    IBOutlet NSView * _captureView;

    IBOutlet NSView * _eyeTVnotLaunchedView;
    IBOutlet NSView * _eyeTVrunningView;
    IBOutlet NSPopUpButton * _eyeTVchannelsPopup;
    IBOutlet NSTextField * _eyeTVcurrentChannelLabel;
    IBOutlet NSTextField * _eyeTVChannelStatusLabel;
    IBOutlet NSProgressIndicator * _eyeTVChannelProgressBar;
    IBOutlet NSButton * _eyeTVlaunchEyeTVButton;
    IBOutlet NSButton * _eyeTVgetPluginButton;
    IBOutlet NSButton * _eyeTVnextProgramButton;
    IBOutlet NSTextField * _eyeTVnoInstanceLabel;
    IBOutlet NSTextField * _eyeTVnoInstanceLongLabel;
    IBOutlet NSButton * _eyeTVpreviousProgramButton;

    IBOutlet NSView * _screenView;
    IBOutlet NSTextField * _screenlongLabel;
    IBOutlet NSTextField * _screenFPSTextField;
    IBOutlet NSTextField * _screenFPSLabel;
    IBOutlet NSStepper * _screenFPSStepper;
    IBOutlet NSTextField * _screenLabel;
    IBOutlet NSPopUpButton * _screenPopup;
    IBOutlet NSTextField * _screenLeftTextField;
    IBOutlet NSTextField * _screenLeftLabel;
    IBOutlet NSStepper * _screenLeftStepper;
    IBOutlet NSTextField * _screenTopTextField;
    IBOutlet NSTextField * _screenTopLabel;
    IBOutlet NSStepper * _screenTopStepper;
    IBOutlet NSTextField * _screenWidthTextField;
    IBOutlet NSTextField * _screenWidthLabel;
    IBOutlet NSStepper * _screenWidthStepper;
    IBOutlet NSTextField * _screenHeightTextField;
    IBOutlet NSTextField * _screenHeightLabel;
    IBOutlet NSStepper * _screenHeightStepper;
    IBOutlet NSButton * _screenFollowMouseCheckbox;
    IBOutlet NSPopUpButton * _screenqtkAudioPopup;
    IBOutlet NSButton * _screenqtkAudioCheckbox;

    IBOutlet NSView * _qtkView;
    IBOutlet NSPopUpButton * _qtkVideoDevicePopup;
    IBOutlet NSButton * _qtkVideoCheckbox;
    IBOutlet NSPopUpButton * _qtkAudioDevicePopup;
    IBOutlet NSButton * _qtkAudioCheckbox;
    IBOutlet NSTextField * _qtkWidthLabel;
    IBOutlet NSTextField * _qtkWidthTextField;
    IBOutlet NSStepper * _qtkWidthStepper;
    IBOutlet NSTextField * _qtkHeightLabel;
    IBOutlet NSTextField * _qtkHeightTextField;
    IBOutlet NSStepper * _qtkHeightStepper;

    float _fileSubDelay;
    float _fileSubFps;

}

@property (readwrite, assign) IBOutlet NSTextField *mrlTextField;
@property (readwrite, assign) IBOutlet NSTextField *mrlLabel;
@property (readwrite, assign) IBOutlet NSView *mrlView;
@property (readwrite, assign) IBOutlet NSButton *mrlButton;
@property (readwrite, assign) IBOutlet NSTabView *tabView;

@property (readwrite, assign) IBOutlet NSButton *okButton;
@property (readwrite, assign) IBOutlet NSButton *cancelButton;

/* bottom-line items */
@property (readwrite, assign) IBOutlet NSButton *outputCheckbox;
@property (readwrite, assign) IBOutlet NSButton *outputSettingsButton;

/* open file */
@property (readwrite, assign) IBOutlet NSTextField *fileNameLabel;
@property (readwrite, assign) IBOutlet NSTextField *fileNameStubLabel;
@property (readwrite, assign) IBOutlet NSImageView *fileIconWell;
@property (readwrite, assign) IBOutlet NSButton *fileBrowseButton;
@property (readwrite, assign) IBOutlet NSButton *fileTreatAsPipeButton;
@property (readwrite, assign) IBOutlet NSButton *fileSlaveCheckbox;
@property (readwrite, assign) IBOutlet NSButton *fileSelectSlaveButton;
@property (readwrite, assign) IBOutlet NSTextField *fileSlaveFilenameLabel;
@property (readwrite, assign) IBOutlet NSImageView *fileSlaveIconWell;
@property (readwrite, assign) IBOutlet NSTextField *fileSubtitlesFilenameLabel;
@property (readwrite, assign) IBOutlet NSImageView *fileSubtitlesIconWell;
@property (readwrite, assign) IBOutlet NSButton *fileCustomTimingCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *fileStartTimeTextField;
@property (readwrite, assign) IBOutlet NSTextField *fileStartTimeLabel;
@property (readwrite, assign) IBOutlet NSTextField *fileStopTimeTextField;
@property (readwrite, assign) IBOutlet NSTextField *fileStopTimeLabel;

/* open disc */
@property (readwrite, assign) IBOutlet NSPopUpButton *discSelectorPopup;

@property (readwrite, assign) IBOutlet NSView *discNoDiscView;
@property (readwrite, assign) IBOutlet NSTextField *discNoDiscLabel;
@property (readwrite, assign) IBOutlet NSButton *discNoDiscVideoTSButton;

@property (readwrite, assign) IBOutlet NSView *discAudioCDView;
@property (readwrite, assign) IBOutlet NSTextField *discAudioCDLabel;
@property (readwrite, assign) IBOutlet NSTextField *discAudioCDTrackCountLabel;
@property (readwrite, assign) IBOutlet NSButton *discAudioCDVideoTSButton;

@property (readwrite, assign) IBOutlet NSView *discDVDView;
@property (readwrite, assign) IBOutlet NSTextField *discDVDLabel;
@property (readwrite, assign) IBOutlet NSButton *discDVDDisableMenusButton;
@property (readwrite, assign) IBOutlet NSButton *discDVDVideoTSButton;

@property (readwrite, assign) IBOutlet NSView *discDVDwomenusView;
@property (readwrite, assign) IBOutlet NSTextField *discDVDwomenusLabel;
@property (readwrite, assign) IBOutlet NSButton *discDVDwomenusEnableMenusButton;
@property (readwrite, assign) IBOutlet NSButton *discDVDwomenusVideoTSButton;
@property (readwrite, assign) IBOutlet NSTextField *discDVDwomenusTitleTextField;
@property (readwrite, assign) IBOutlet NSTextField *discDVDwomenusTitleLabel;
@property (readwrite, assign) IBOutlet NSStepper *discDVDwomenusTitleStepper;
@property (readwrite, assign) IBOutlet NSTextField *discDVDwomenusChapterTextField;
@property (readwrite, assign) IBOutlet NSTextField *discDVDwomenusChapterLabel;
@property (readwrite, assign) IBOutlet NSStepper *discDVDwomenusChapterStepper;

@property (readwrite, assign) IBOutlet NSView *discVCDView;
@property (readwrite, assign) IBOutlet NSTextField *discVCDLabel;
@property (readwrite, assign) IBOutlet NSButton *discVCDVideoTSButton;
@property (readwrite, assign) IBOutlet NSTextField *discVCDTitleTextField;
@property (readwrite, assign) IBOutlet NSTextField *discVCDTitleLabel;
@property (readwrite, assign) IBOutlet NSStepper *discVCDTitleStepper;
@property (readwrite, assign) IBOutlet NSTextField *discVCDChapterTextField;
@property (readwrite, assign) IBOutlet NSTextField *discVCDChapterLabel;
@property (readwrite, assign) IBOutlet NSStepper *discVCDChapterStepper;

@property (readwrite, assign) IBOutlet NSView *discBDView;
@property (readwrite, assign) IBOutlet NSTextField *discBDLabel;
@property (readwrite, assign) IBOutlet NSButton *discBDVideoTSButton;

/* open network */
@property (readwrite, assign) IBOutlet NSTextField *netHTTPURLLabel;
@property (readwrite, assign) IBOutlet NSTextField *netHTTPURLTextField;
@property (readwrite, assign) IBOutlet NSTextField *netHelpLabel;

/* open UDP stuff panel */
@property (readwrite, assign) IBOutlet NSTextField *netHelpUDPLabel;
@property (readwrite, assign) IBOutlet NSMatrix *netUDPProtocolMatrix;
@property (readwrite, assign) IBOutlet NSTextField *netUDPProtocolLabel;
@property (readwrite, assign) IBOutlet NSTextField *netUDPAddressLabel;
@property (readwrite, assign) IBOutlet NSTextField *netUDPModeLabel;
@property (readwrite, assign) IBOutlet NSMatrix *netModeMatrix;
@property (readwrite, assign) IBOutlet NSButton *netOpenUDPButton;
@property (readwrite, assign) IBOutlet NSButton *netUDPCancelButton;
@property (readwrite, assign) IBOutlet NSButton *netUDPOKButton;
@property (readwrite, assign) IBOutlet NSWindow *netUDPPanel;
@property (readwrite, assign) IBOutlet NSTextField *netUDPPortTextField;
@property (readwrite, assign) IBOutlet NSTextField *netUDPPortLabel;
@property (readwrite, assign) IBOutlet NSStepper *netUDPPortStepper;
@property (readwrite, assign) IBOutlet NSTextField *netUDPMAddressTextField;
@property (readwrite, assign) IBOutlet NSTextField *netUDPMAddressLabel;
@property (readwrite, assign) IBOutlet NSTextField *netUDPMPortTextField;
@property (readwrite, assign) IBOutlet NSTextField *netUDPMPortLabel;
@property (readwrite, assign) IBOutlet NSStepper *netUDPMPortStepper;

/* open subtitle file */
@property (readwrite, assign) IBOutlet NSButton *fileSubCheckbox;
@property (readwrite, assign) IBOutlet NSButton *fileSubSettingsButton;
@property (readwrite, assign) IBOutlet NSPanel *fileSubSheet;
@property (readwrite, assign) IBOutlet NSTextField *fileSubPathLabel;
@property (readwrite, assign) IBOutlet NSTextField *fileSubPathTextField;
@property (readwrite, assign) IBOutlet NSImageView *fileSubIconView;
@property (readwrite, assign) IBOutlet NSButton *fileSubBrowseButton;
@property (readwrite, assign) IBOutlet NSButton *fileSubOverrideCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *fileSubDelayTextField;
@property (readwrite, assign) IBOutlet NSTextField *fileSubDelayLabel;
@property (readwrite, assign) IBOutlet NSStepper *fileSubDelayStepper;
@property (readwrite, assign) IBOutlet NSTextField *fileSubFPSTextField;
@property (readwrite, assign) IBOutlet NSTextField *fileSubFPSLabel;
@property (readwrite, assign) IBOutlet NSStepper *fileSubFPSStepper;
@property (readwrite, assign) IBOutlet NSPopUpButton *fileSubEncodingPopup;
@property (readwrite, assign) IBOutlet NSTextField *fileSubEncodingLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *fileSubSizePopup;
@property (readwrite, assign) IBOutlet NSTextField *fileSubSizeLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *fileSubAlignPopup;
@property (readwrite, assign) IBOutlet NSTextField *fileSubAlignLabel;
@property (readwrite, assign) IBOutlet NSButton *fileSubOKButton;
@property (readwrite, assign) IBOutlet NSBox *fileSubFontBox;
@property (readwrite, assign) IBOutlet NSBox *fileSubFileBox;

/* generic capturing stuff */
@property (readwrite, assign) IBOutlet NSTextField *captureLabel;
@property (readwrite, assign) IBOutlet NSTextField *captureLongLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *captureModePopup;
@property (readwrite, assign) IBOutlet NSView *captureView;

/* eyetv support */
@property (readwrite, assign) IBOutlet NSView *eyeTVnotLaunchedView;
@property (readwrite, assign) IBOutlet NSView *eyeTVrunningView;
@property (readwrite, assign) IBOutlet NSPopUpButton *eyeTVchannelsPopup;
@property (readwrite, assign) IBOutlet NSTextField *eyeTVcurrentChannelLabel;
@property (readwrite, assign) IBOutlet NSTextField *eyeTVChannelStatusLabel;
@property (readwrite, assign) IBOutlet NSProgressIndicator *eyeTVChannelProgressBar;
@property (readwrite, assign) IBOutlet NSButton *eyeTVlaunchEyeTVButton;
@property (readwrite, assign) IBOutlet NSButton *eyeTVgetPluginButton;
@property (readwrite, assign) IBOutlet NSButton *eyeTVnextProgramButton;
@property (readwrite, assign) IBOutlet NSTextField *eyeTVnoInstanceLabel;
@property (readwrite, assign) IBOutlet NSTextField *eyeTVnoInstanceLongLabel;
@property (readwrite, assign) IBOutlet NSButton *eyeTVpreviousProgramButton;

/* screen support */
@property (readwrite, assign) IBOutlet NSView *screenView;
@property (readwrite, assign) IBOutlet NSTextField *screenlongLabel;
@property (readwrite, assign) IBOutlet NSTextField *screenFPSTextField;
@property (readwrite, assign) IBOutlet NSTextField *screenFPSLabel;
@property (readwrite, assign) IBOutlet NSStepper *screenFPSStepper;
@property (readwrite, assign) IBOutlet NSTextField *screenLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *screenPopup;
@property (readwrite, assign) IBOutlet NSTextField *screenLeftTextField;
@property (readwrite, assign) IBOutlet NSTextField *screenLeftLabel;
@property (readwrite, assign) IBOutlet NSStepper *screenLeftStepper;
@property (readwrite, assign) IBOutlet NSTextField *screenTopTextField;
@property (readwrite, assign) IBOutlet NSTextField *screenTopLabel;
@property (readwrite, assign) IBOutlet NSStepper *screenTopStepper;
@property (readwrite, assign) IBOutlet NSTextField *screenWidthTextField;
@property (readwrite, assign) IBOutlet NSTextField *screenWidthLabel;
@property (readwrite, assign) IBOutlet NSStepper *screenWidthStepper;
@property (readwrite, assign) IBOutlet NSTextField *screenHeightTextField;
@property (readwrite, assign) IBOutlet NSTextField *screenHeightLabel;
@property (readwrite, assign) IBOutlet NSStepper *screenHeightStepper;
@property (readwrite, assign) IBOutlet NSButton *screenFollowMouseCheckbox;
@property (readwrite, assign) IBOutlet NSPopUpButton *screenqtkAudioPopup;
@property (readwrite, assign) IBOutlet NSButton *screenqtkAudioCheckbox;

/* QTK support */
@property (readwrite, assign) IBOutlet NSView *qtkView;
@property (readwrite, assign) IBOutlet NSPopUpButton *qtkVideoDevicePopup;
@property (readwrite, assign) IBOutlet NSButton *qtkVideoCheckbox;
@property (readwrite, assign) IBOutlet NSPopUpButton *qtkAudioDevicePopup;
@property (readwrite, assign) IBOutlet NSButton *qtkAudioCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *qtkWidthLabel;
@property (readwrite, assign) IBOutlet NSTextField *qtkWidthTextField;
@property (readwrite, assign) IBOutlet NSStepper *qtkWidthStepper;
@property (readwrite, assign) IBOutlet NSTextField *qtkHeightLabel;
@property (readwrite, assign) IBOutlet NSTextField *qtkHeightTextField;
@property (readwrite, assign) IBOutlet NSStepper *qtkHeightStepper;

/* text field / stepper binding values - subs panel */
@property (nonatomic) float fileSubDelay;
@property (nonatomic) float fileSubFps;

@property (readwrite, assign) NSString *MRL;

- (IBAction)outputSettings:(id)sender;
- (void)setSubPanel;
- (void)tabView:(NSTabView *)o_tv didSelectTabViewItem:(NSTabViewItem *)o_tvi;
- (void)textFieldWasClicked:(NSNotification *)o_notification;
- (IBAction)expandMRLfieldAction:(id)sender;
- (IBAction)inputSlaveAction:(id)sender;
- (IBAction)fileTimeCustomization:(id)sender;

- (void)openFileGeneric;
- (IBAction)openFileBrowse:(id)sender;
- (IBAction)openFileStreamChanged:(id)sender;

- (void)openDisc;
- (IBAction)discSelectorChanged:(id)sender;
- (IBAction)openSpecialMediaFolder:(id)sender;
- (IBAction)dvdreadOptionChanged:(id)sender;
- (IBAction)vcdOptionChanged:(id)sender;

- (void)openNet;
- (IBAction)openNetModeChanged:(id)sender;
- (IBAction)openNetStepperChanged:(id)sender;
- (void)openNetInfoChanged:(NSNotification *)o_notification;
- (IBAction)openNetUDPButtonAction:(id)sender;

- (void)openCapture;
- (IBAction)openCaptureModeChanged:(id)sender;
- (IBAction)qtkChanged:(id)sender;
- (IBAction)qtkAudioChanged:(id)sender;
- (IBAction)qtkToggleUIElements:(id)sender;
- (IBAction)screenChanged:(id)sender;
- (IBAction)eyetvSwitchChannel:(id)sender;
- (IBAction)eyetvLaunch:(id)sender;
- (IBAction)eyetvGetPlugin:(id)sender;

- (IBAction)subsChanged:(id)sender;
- (IBAction)subSettings:(id)sender;
- (IBAction)subFileBrowse:(id)sender;
- (IBAction)subOverride:(id)sender;

- (IBAction)subCloseSheet:(id)sender;

- (IBAction)panelCancel:(id)sender;
- (IBAction)panelOk:(id)sender;

- (void)openFile;

- (void)openFilePathChanged:(NSNotification *)o_notification;

- (void)setupChannelInfo;

- (void)setEyeTVUnconnected;

- (void)updateQTKVideoDevices;
- (void)updateQTKAudioDevices;

- (void)scanOpticalMedia:(NSNotification *)o_notification;

@end
