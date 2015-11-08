/*****************************************************************************
 * ConvertAndSave.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2012 Felix Paul Kühne
 * $Id$
 *
 * Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
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

@class VLCDropDisabledImageView;
@class VLCDragDropView;
@class VLCPopupPanelController;
@class VLCTextfieldPanelController;

@interface VLCConvertAndSave : NSWindowController {

    NSArray *_videoCodecs;
    NSArray *_audioCodecs;
    NSArray *_subsCodecs;
    BOOL b_streaming;

    // ivars of properties

    IBOutlet VLCDragDropView * _dropBox;
    IBOutlet NSTextField * _dropLabel;

    IBOutlet VLCDropDisabledImageView * _dropImage;
    IBOutlet NSButton * _dropButton;
    IBOutlet NSTextField * _profileLabel;
    IBOutlet NSPopUpButton * _profilePopup;
    IBOutlet NSButton * _customizeButton;

    IBOutlet NSTextField * _destinationLabel;
    IBOutlet NSBox * _destinationBox;

    IBOutlet NSButton * _destinationCancelBtn;
    IBOutlet NSButton * _destinationStreamButton;
    IBOutlet NSButton * _destinationFileButton;

    IBOutlet NSButton * _okButton;

    IBOutlet NSView * _dropinView;
    IBOutlet VLCDropDisabledImageView * _dropinIcon;
    IBOutlet NSTextField * _dropinMediaLabel;
    IBOutlet NSView * _fileDestinationView;
    IBOutlet NSImageView * _fileDestinationIcon;
    IBOutlet NSTextField * _fileDestinationFileName;
    IBOutlet NSTextField * _fileDestinationFileNameStub;
    IBOutlet NSButton * _fileDestinationBrowseButton;
    IBOutlet NSView * _streamDestinationView;
    IBOutlet NSTextField * _streamDestinationURLLabel;
    IBOutlet NSButton * _streamDestinationButton;

    IBOutlet NSWindow * _customizePanel;
    IBOutlet NSButton * _customizeNewProfileButton;
    IBOutlet NSButton * _customizeCancelButton;
    IBOutlet NSButton * _customizeOkButton;
    IBOutlet NSTabView * _customizeTabView;
    IBOutlet NSMatrix * _customizeEncapMatrix;

    IBOutlet NSButton * _customizeVidCheckbox;
    IBOutlet NSButton * _customizeVidKeepCheckbox;
    IBOutlet NSBox * _customizeVidSettingsBox;
    IBOutlet NSTextField * _customizeVidCodecLabel;
    IBOutlet NSTextField * _customizeVidBitrateLabel;
    IBOutlet NSTextField * _customizeVidFramerateLabel;
    IBOutlet NSBox * _customizeVidResolutionBox;
    IBOutlet NSTextField * _customizeVidWidthLabel;
    IBOutlet NSTextField * _customizeVidHeightLabel;
    IBOutlet NSTextField * _customizeVidScaleLabel;
    IBOutlet NSTextField * _customizeVidResLabel;
    IBOutlet NSPopUpButton * _customizeVidCodecPopup;
    IBOutlet NSTextField * _customizeVidBitrateField;
    IBOutlet NSTextField * _customizeVidFramerateField;
    IBOutlet NSTextField * _customizeVidWidthField;
    IBOutlet NSTextField * _customizeVidHeightField;
    IBOutlet NSPopUpButton * _customizeVidScalePopup;

    IBOutlet NSButton * _customizeAudCheckbox;
    IBOutlet NSButton * _customizeAudKeepCheckbox;
    IBOutlet NSBox * _customizeAudSettingsBox;
    IBOutlet NSTextField * _customizeAudCodecLabel;
    IBOutlet NSTextField * _customizeAudBitrateLabel;
    IBOutlet NSTextField * _customizeAudChannelsLabel;
    IBOutlet NSTextField * _customizeAudSamplerateLabel;
    IBOutlet NSPopUpButton * _customizeAudCodecPopup;
    IBOutlet NSTextField * _customizeAudBitrateField;
    IBOutlet NSTextField * _customizeAudChannelsField;
    IBOutlet NSPopUpButton * _customizeAudSampleratePopup;

    IBOutlet NSButton * _customizeSubsCheckbox;
    IBOutlet NSButton * _customizeSubsOverlayCheckbox;
    IBOutlet NSPopUpButton * _customizeSubsPopup;

    IBOutlet NSWindow * _streamPanel;
    IBOutlet NSTextField * _streamDestinationLabel;
    IBOutlet NSTextField * _streamTypeLabel;
    IBOutlet NSTextField * _streamAddressLabel;
    IBOutlet NSPopUpButton * _streamTypePopup;
    IBOutlet NSTextField * _streamAddressField;
    IBOutlet NSTextField * _streamTTLLabel;
    IBOutlet NSTextField * _streamTTLField;
    IBOutlet NSStepper * _streamTTLStepper;
    IBOutlet NSTextField * _streamPortLabel;
    IBOutlet NSTextField * _streamPortField;
    IBOutlet NSTextField * _streamAnnouncementLabel;
    IBOutlet NSButton * _streamSAPCheckbox;
    IBOutlet NSTextField * _streamChannelField;
    IBOutlet NSMatrix * _streamSDPMatrix;
    IBOutlet NSButton * _streamSDPFileBrowseButton;
    IBOutlet NSTextField * _streamSDPField;
    IBOutlet NSButton * _streamCancelButton;
    IBOutlet NSButton * _streamOkButton;

    VLCPopupPanelController * _popupPanel;
    VLCTextfieldPanelController * _textfieldPanel;

    NSString * _MRL;
    NSString * _outputDestination;
    NSArray * _profileNames;
    NSArray * _profileValueList;
    NSMutableArray * _currentProfile;

    int _vidBitrate;
    int _vidFramerate;
    int _audBitrate;
    int _audChannels;

}

// main panel
@property (assign) IBOutlet VLCDragDropView *dropBox;
@property (assign) IBOutlet NSTextField *dropLabel;

@property (assign) IBOutlet VLCDropDisabledImageView *dropImage;
@property (assign) IBOutlet NSButton *dropButton;
@property (assign) IBOutlet NSTextField *profileLabel;
@property (assign) IBOutlet NSPopUpButton *profilePopup;
@property (assign) IBOutlet NSButton *customizeButton;

@property (assign) IBOutlet NSTextField *destinationLabel;
@property (assign) IBOutlet NSBox *destinationBox;

@property (assign) IBOutlet NSButton *destinationCancelBtn;
@property (assign) IBOutlet NSButton *destinationStreamButton;
@property (assign) IBOutlet NSButton *destinationFileButton;

@property (assign) IBOutlet NSButton *okButton;

@property (assign) IBOutlet NSView *dropinView;
@property (assign) IBOutlet VLCDropDisabledImageView *dropinIcon;
@property (assign) IBOutlet NSTextField *dropinMediaLabel;
@property (assign) IBOutlet NSView *fileDestinationView;
@property (assign) IBOutlet NSImageView *fileDestinationIcon;
@property (assign) IBOutlet NSTextField *fileDestinationFileName;
@property (assign) IBOutlet NSTextField *fileDestinationFileNameStub;
@property (assign) IBOutlet NSButton *fileDestinationBrowseButton;
@property (assign) IBOutlet NSView *streamDestinationView;
@property (assign) IBOutlet NSTextField *streamDestinationURLLabel;
@property (assign) IBOutlet NSButton *streamDestinationButton;

// customize panel
@property (assign) IBOutlet NSWindow *customizePanel;
@property (assign) IBOutlet NSButton *customizeNewProfileButton;
@property (assign) IBOutlet NSButton *customizeCancelButton;
@property (assign) IBOutlet NSButton *customizeOkButton;
@property (assign) IBOutlet NSTabView *customizeTabView;
@property (assign) IBOutlet NSMatrix *customizeEncapMatrix;

// customize panel: video
@property (assign) IBOutlet NSButton *customizeVidCheckbox;
@property (assign) IBOutlet NSButton *customizeVidKeepCheckbox;
@property (assign) IBOutlet NSBox *customizeVidSettingsBox;
@property (assign) IBOutlet NSTextField *customizeVidCodecLabel;
@property (assign) IBOutlet NSTextField *customizeVidBitrateLabel;
@property (assign) IBOutlet NSTextField *customizeVidFramerateLabel;
@property (assign) IBOutlet NSBox *customizeVidResolutionBox;
@property (assign) IBOutlet NSTextField *customizeVidWidthLabel;
@property (assign) IBOutlet NSTextField *customizeVidHeightLabel;
@property (assign) IBOutlet NSTextField *customizeVidScaleLabel;
@property (assign) IBOutlet NSTextField *customizeVidResLabel;
@property (assign) IBOutlet NSPopUpButton *customizeVidCodecPopup;
@property (assign) IBOutlet NSTextField *customizeVidBitrateField;
@property (assign) IBOutlet NSTextField *customizeVidFramerateField;
@property (assign) IBOutlet NSTextField *customizeVidWidthField;
@property (assign) IBOutlet NSTextField *customizeVidHeightField;
@property (assign) IBOutlet NSPopUpButton *customizeVidScalePopup;

// customize panel: audio
@property (assign) IBOutlet NSButton *customizeAudCheckbox;
@property (assign) IBOutlet NSButton *customizeAudKeepCheckbox;
@property (assign) IBOutlet NSBox *customizeAudSettingsBox;
@property (assign) IBOutlet NSTextField *customizeAudCodecLabel;
@property (assign) IBOutlet NSTextField *customizeAudBitrateLabel;
@property (assign) IBOutlet NSTextField *customizeAudChannelsLabel;
@property (assign) IBOutlet NSTextField *customizeAudSamplerateLabel;
@property (assign) IBOutlet NSPopUpButton *customizeAudCodecPopup;
@property (assign) IBOutlet NSTextField *customizeAudBitrateField;
@property (assign) IBOutlet NSTextField *customizeAudChannelsField;
@property (assign) IBOutlet NSPopUpButton *customizeAudSampleratePopup;

// customize panel: subs
@property (assign) IBOutlet NSButton *customizeSubsCheckbox;
@property (assign) IBOutlet NSButton *customizeSubsOverlayCheckbox;
@property (assign) IBOutlet NSPopUpButton *customizeSubsPopup;

// stream panel
@property (assign) IBOutlet NSWindow *streamPanel;
@property (assign) IBOutlet NSTextField *streamDestinationLabel;
@property (assign) IBOutlet NSTextField *streamTypeLabel;
@property (assign) IBOutlet NSTextField *streamAddressLabel;
@property (assign) IBOutlet NSPopUpButton *streamTypePopup;
@property (assign) IBOutlet NSTextField *streamAddressField;
@property (assign) IBOutlet NSTextField *streamTTLLabel;
@property (assign) IBOutlet NSTextField *streamTTLField;
@property (assign) IBOutlet NSStepper *streamTTLStepper;
@property (assign) IBOutlet NSTextField *streamPortLabel;
@property (assign) IBOutlet NSTextField *streamPortField;
@property (assign) IBOutlet NSTextField *streamAnnouncementLabel;
@property (assign) IBOutlet NSButton *streamSAPCheckbox;
@property (assign) IBOutlet NSTextField *streamChannelField;
@property (assign) IBOutlet NSMatrix *streamSDPMatrix;
@property (assign) IBOutlet NSButton *streamSDPFileBrowseButton;
@property (assign) IBOutlet NSTextField *streamSDPField;
@property (assign) IBOutlet NSButton *streamCancelButton;
@property (assign) IBOutlet NSButton *streamOkButton;

// other properties
@property (retain) VLCPopupPanelController *popupPanel;
@property (retain) VLCTextfieldPanelController *textfieldPanel;

@property (readwrite, nonatomic, retain) NSString * MRL;
@property (readwrite, nonatomic, retain) NSString * outputDestination;
@property (readwrite, retain) NSArray * profileNames;
@property (readwrite, retain) NSArray * profileValueList;
@property (readwrite, retain) NSMutableArray * currentProfile;

// Bindings for field / stepper combis
@property (nonatomic) int vidBitrate;
@property (nonatomic) int vidFramerate;
@property (nonatomic) int audBitrate;
@property (nonatomic) int audChannels;


- (IBAction)finalizePanel:(id)sender;
- (IBAction)openMedia:(id)sender;
- (IBAction)switchProfile:(id)sender;
- (IBAction)iWantAFile:(id)sender;
- (IBAction)iWantAStream:(id)sender;
- (IBAction)cancelDestination:(id)sender;
- (IBAction)browseFileDestination:(id)sender;

- (IBAction)customizeProfile:(id)sender;
- (IBAction)closeCustomizationSheet:(id)sender;
- (IBAction)videoSettingsChanged:(id)sender;
- (IBAction)audioSettingsChanged:(id)sender;
- (IBAction)subSettingsChanged:(id)sender;
- (IBAction)newProfileAction:(id)sender;

- (IBAction)showStreamPanel:(id)sender;
- (IBAction)closeStreamPanel:(id)sender;
- (IBAction)streamTypeToggle:(id)sender;
- (IBAction)streamAnnouncementToggle:(id)sender;
- (IBAction)sdpFileLocationSelector:(id)sender;

- (void)updateDropView;
- (void)updateOKButton;
- (void)resetCustomizationSheetBasedOnProfile:(NSString *)profileString;
- (void)selectCellByEncapsulationFormat:(NSString *)format;
- (NSString *)currentEncapsulationFormatAsFileExtension:(BOOL)b_extension;
- (NSString *)composedOptions;
- (void)updateCurrentProfile;
- (void)storeProfilesOnDisk;
- (void)recreateProfilePopup;

@end
