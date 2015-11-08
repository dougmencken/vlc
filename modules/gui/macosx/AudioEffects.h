/*****************************************************************************
 * AudioEffects.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2004-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
 *          Jérôme Decoodt <djc@videolan.org>
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

@class VLCPopupPanelController;
@class VLCTextfieldPanelController;

@interface VLCAudioEffects : NSWindowController {

    IBOutlet NSTabView * _tabView;
    IBOutlet NSPopUpButton * _profilePopup;

    IBOutlet NSView * _equalizerView;
    IBOutlet NSButton * _equalizerEnableCheckbox;
    IBOutlet NSButton * _equalizerTwoPassCheckbox;
    IBOutlet NSTextField * _equalizerPreampLabel;
    IBOutlet NSPopUpButton * _equalizerPresetsPopup;
    IBOutlet NSSlider * _equalizerBand1Slider;
    IBOutlet NSSlider * _equalizerBand2Slider;
    IBOutlet NSSlider * _equalizerBand3Slider;
    IBOutlet NSSlider * _equalizerBand4Slider;
    IBOutlet NSSlider * _equalizerBand5Slider;
    IBOutlet NSSlider * _equalizerBand6Slider;
    IBOutlet NSSlider * _equalizerBand7Slider;
    IBOutlet NSSlider * _equalizerBand8Slider;
    IBOutlet NSSlider * _equalizerBand9Slider;
    IBOutlet NSSlider * _equalizerBand10Slider;
    IBOutlet NSSlider * _equalizerPreampSlider;

    IBOutlet NSView * _compressorView;
    IBOutlet NSButton * _compressorEnableCheckbox;
    IBOutlet NSButton * _compressorResetButton;
    IBOutlet NSSlider * _compressorBand1Slider;
    IBOutlet NSTextField * _compressorBand1TextField;
    IBOutlet NSTextField * _compressorBand1Label;
    IBOutlet NSSlider * _compressorBand2Slider;
    IBOutlet NSTextField * _compressorBand2TextField;
    IBOutlet NSTextField * _compressorBand2Label;
    IBOutlet NSSlider * _compressorBand3Slider;
    IBOutlet NSTextField * _compressorBand3TextField;
    IBOutlet NSTextField * _compressorBand3Label;
    IBOutlet NSSlider * _compressorBand4Slider;
    IBOutlet NSTextField * _compressorBand4TextField;
    IBOutlet NSTextField * _compressorBand4Label;
    IBOutlet NSSlider * _compressorBand5Slider;
    IBOutlet NSTextField * _compressorBand5TextField;
    IBOutlet NSTextField * _compressorBand5Label;
    IBOutlet NSSlider * _compressorBand6Slider;
    IBOutlet NSTextField * _compressorBand6TextField;
    IBOutlet NSTextField * _compressorBand6Label;
    IBOutlet NSSlider * _compressorBand7Slider;
    IBOutlet NSTextField * _compressorBand7TextField;
    IBOutlet NSTextField * _compressorBand7Label;

    IBOutlet NSView * _spatializerView;
    IBOutlet NSButton * _spatializerEnableCheckbox;
    IBOutlet NSButton * _spatializerResetButton;
    IBOutlet NSSlider * _spatializerBand1Slider;
    IBOutlet NSTextField * _spatializerBand1TextField;
    IBOutlet NSTextField * _spatializerBand1Label;
    IBOutlet NSSlider * _spatializerBand2Slider;
    IBOutlet NSTextField * _spatializerBand2TextField;
    IBOutlet NSTextField * _spatializerBand2Label;
    IBOutlet NSSlider * _spatializerBand3Slider;
    IBOutlet NSTextField * _spatializerBand3TextField;
    IBOutlet NSTextField * _spatializerBand3Label;
    IBOutlet NSSlider * _spatializerBand4Slider;
    IBOutlet NSTextField * _spatializerBand4TextField;
    IBOutlet NSTextField * _spatializerBand4Label;
    IBOutlet NSSlider * _spatializerBand5Slider;
    IBOutlet NSTextField * _spatializerBand5TextField;
    IBOutlet NSTextField * _spatializerBand5Label;

    IBOutlet NSButton * _filterHeadPhoneCheckbox;
    IBOutlet NSButton * _filterNormLevelCheckbox;
    IBOutlet NSSlider * _filterNormLevelSlider;
    IBOutlet NSTextField * _filterNormLevelLabel;
    IBOutlet NSButton * _filterKaraokeCheckbox;

    VLCPopupPanelController * _popupPanel;
    VLCTextfieldPanelController * _textfieldPanel;

    NSInteger i_old_profile_index;

}

/* generic */
@property (readwrite, assign) IBOutlet NSTabView *tabView;
@property (readwrite, assign) IBOutlet NSPopUpButton *profilePopup;

/* Equalizer */
@property (readwrite, assign) IBOutlet NSView *equalizerView;
@property (readwrite, assign) IBOutlet NSButton *equalizerEnableCheckbox;
@property (readwrite, assign) IBOutlet NSButton *equalizerTwoPassCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *equalizerPreampLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *equalizerPresetsPopup;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand1Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand2Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand3Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand4Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand5Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand6Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand7Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand8Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand9Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerBand10Slider;
@property (readwrite, assign) IBOutlet NSSlider *equalizerPreampSlider;

/* Compressor */
@property (readwrite, assign) IBOutlet NSView *compressorView;
@property (readwrite, assign) IBOutlet NSButton *compressorEnableCheckbox;
@property (readwrite, assign) IBOutlet NSButton *compressorResetButton;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand1Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand1TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand1Label;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand2Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand2TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand2Label;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand3Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand3TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand3Label;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand4Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand4TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand4Label;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand5Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand5TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand5Label;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand6Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand6TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand6Label;
@property (readwrite, assign) IBOutlet NSSlider *compressorBand7Slider;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand7TextField;
@property (readwrite, assign) IBOutlet NSTextField *compressorBand7Label;

/* Spatializer */
@property (readwrite, assign) IBOutlet NSView *spatializerView;
@property (readwrite, assign) IBOutlet NSButton *spatializerEnableCheckbox;
@property (readwrite, assign) IBOutlet NSButton *spatializerResetButton;
@property (readwrite, assign) IBOutlet NSSlider *spatializerBand1Slider;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand1TextField;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand1Label;
@property (readwrite, assign) IBOutlet NSSlider *spatializerBand2Slider;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand2TextField;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand2Label;
@property (readwrite, assign) IBOutlet NSSlider *spatializerBand3Slider;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand3TextField;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand3Label;
@property (readwrite, assign) IBOutlet NSSlider *spatializerBand4Slider;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand4TextField;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand4Label;
@property (readwrite, assign) IBOutlet NSSlider *spatializerBand5Slider;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand5TextField;
@property (readwrite, assign) IBOutlet NSTextField *spatializerBand5Label;

/* Filter */
@property (readwrite, assign) IBOutlet NSButton *filterHeadPhoneCheckbox;
@property (readwrite, assign) IBOutlet NSButton *filterNormLevelCheckbox;
@property (readwrite, assign) IBOutlet NSSlider *filterNormLevelSlider;
@property (readwrite, assign) IBOutlet NSTextField *filterNormLevelLabel;
@property (readwrite, assign) IBOutlet NSButton *filterKaraokeCheckbox;

@property (retain) VLCPopupPanelController *popupPanel;
@property (retain) VLCTextfieldPanelController *textfieldPanel;

/* generic */
- (IBAction)profileSelectorAction:(id)sender;

- (void)toggleWindow:(id)sender;
- (void)updateCocoaWindowLevel:(NSInteger)i_level;
- (void)saveCurrentProfile;

/* Equalizer */
- (void)equalizerUpdated;
- (IBAction)equalizerBandSliderUpdated:(id)sender;
- (IBAction)equalizerChangePreset:(id)sender;
- (IBAction)equalizerEnable:(id)sender;
- (IBAction)equalizerPreAmpSliderUpdated:(id)sender;
- (IBAction)equalizerTwoPass:(id)sender;
- (void)setValue:(float)value forSlider:(int)index;

/* Compressor */
- (void)resetCompressor;
- (IBAction)resetCompressorValues:(id)sender;
- (IBAction)compressorEnable:(id)sender;
- (IBAction)compressorSliderUpdated:(id)sender;

/* Spatializer */
- (void)resetSpatializer;
- (IBAction)resetSpatializerValues:(id)sender;
- (IBAction)spatializerEnable:(id)sender;
- (IBAction)spatializerSliderUpdated:(id)sender;

/* Filter */
- (void)resetAudioFilters;
- (IBAction)filterEnableHeadPhoneVirt:(id)sender;
- (IBAction)filterEnableVolumeNorm:(id)sender;
- (IBAction)filterVolumeNormSliderUpdated:(id)sender;
- (IBAction)filterEnableKaraoke:(id)sender;

- (void)resetProfileSelector;
- (void)updatePresetSelector;
- (void)setBandSliderValuesForPreset:(NSInteger)presetID;

@end
