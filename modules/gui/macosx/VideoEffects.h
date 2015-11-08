/*****************************************************************************
 * VideoEffects.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2011-2015 Felix Paul Kühne
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

@class VLCPopupPanelController;
@class VLCTextfieldPanelController;

@interface VLCVideoEffects : NSWindowController {

    NSInteger i_old_profile_index;

    IBOutlet NSTabView * _tabView;
    IBOutlet NSPopUpButton * _profilePopup;

    IBOutlet NSButton * _adjustCheckbox;
    IBOutlet NSTextField * _adjustHueLabel;
    IBOutlet NSSlider * _adjustHueSlider;
    IBOutlet NSTextField * _adjustContrastLabel;
    IBOutlet NSSlider * _adjustContrastSlider;
    IBOutlet NSTextField * _adjustBrightnessLabel;
    IBOutlet NSSlider * _adjustBrightnessSlider;
    IBOutlet NSButton * _adjustBrightnessCheckbox;
    IBOutlet NSTextField * _adjustSaturationLabel;
    IBOutlet NSSlider * _adjustSaturationSlider;
    IBOutlet NSTextField * _adjustGammaLabel;
    IBOutlet NSSlider * _adjustGammaSlider;
    IBOutlet NSButton * _adjustResetButton;
    IBOutlet NSButton * _sharpenCheckbox;
    IBOutlet NSTextField * _sharpenLabel;
    IBOutlet NSSlider * _sharpenSlider;
    IBOutlet NSButton * _bandingCheckbox;
    IBOutlet NSTextField * _bandingLabel;
    IBOutlet NSSlider * _bandingSlider;
    IBOutlet NSButton * _grainCheckbox;
    IBOutlet NSSlider * _grainSlider;
    IBOutlet NSTextField * _grainLabel;

    IBOutlet NSTextField * _cropTopLabel;
    IBOutlet NSTextField * _cropTopTextField;
    IBOutlet NSStepper * _cropTopStepper;
    IBOutlet NSTextField * _cropLeftLabel;
    IBOutlet NSTextField * _cropLeftTextField;
    IBOutlet NSStepper * _cropLeftStepper;
    IBOutlet NSTextField * _cropRightLabel;
    IBOutlet NSTextField * _cropRightTextField;
    IBOutlet NSStepper * _cropRightStepper;
    IBOutlet NSTextField * _cropBottomLabel;
    IBOutlet NSTextField * _cropBottomTextField;
    IBOutlet NSStepper * _cropBottomStepper;
    IBOutlet NSButton * _cropSyncTopBottomCheckbox;
    IBOutlet NSButton * _cropSyncLeftRightCheckbox;

    IBOutlet NSButton * _transformCheckbox;
    IBOutlet NSPopUpButton * _transformPopup;
    IBOutlet NSButton * _zoomCheckbox;
    IBOutlet NSButton * _puzzleCheckbox;
    IBOutlet NSTextField * _puzzleRowsLabel;
    IBOutlet NSTextField * _puzzleRowsTextField;
    IBOutlet NSStepper * _puzzleRowsStepper;
    IBOutlet NSTextField * _puzzleColumnsLabel;
    IBOutlet NSTextField * _puzzleColumnsTextField;
    IBOutlet NSStepper * _puzzleColumnsStepper;
    IBOutlet NSButton * _cloneCheckbox;
    IBOutlet NSTextField * _cloneNumberTextField;
    IBOutlet NSStepper * _cloneNumberStepper;
    IBOutlet NSTextField * _cloneNumberLabel;
    IBOutlet NSButton * _wallCheckbox;
    IBOutlet NSTextField * _wallNumbersOfRowsTextField;
    IBOutlet NSStepper * _wallNumbersOfRowsStepper;
    IBOutlet NSTextField * _wallNumbersOfRowsLabel;
    IBOutlet NSTextField * _wallNumberOfColumnsTextField;
    IBOutlet NSStepper * _wallNumberOfColumnsStepper;
    IBOutlet NSTextField * _wallNumberOfColumnsLabel;

    IBOutlet NSButton * _thresholdCheckbox;
    IBOutlet NSTextField * _thresholdColorLabel;
    IBOutlet NSTextField * _thresholdColorTextField;
    IBOutlet NSTextField * _thresholdSaturationLabel;
    IBOutlet NSSlider * _thresholdSaturationSlider;
    IBOutlet NSTextField * _thresholdSimilarityLabel;
    IBOutlet NSSlider * _thresholdSimilaritySlider;
    IBOutlet NSButton * _sepiaCheckbox;
    IBOutlet NSTextField * _sepiaLabel;
    IBOutlet NSTextField * _sepiaTextField;
    IBOutlet NSStepper * _sepiaStepper;
    IBOutlet NSButton * _noiseCheckbox;
    IBOutlet NSButton * _gradientCheckbox;
    IBOutlet NSTextField * _gradientModeLabel;
    IBOutlet NSPopUpButton * _gradientModePopup;
    IBOutlet NSButton * _gradientColorCheckbox;
    IBOutlet NSButton * _gradientCartoonCheckbox;
    IBOutlet NSButton * _extractCheckbox;
    IBOutlet NSTextField * _extractLabel;
    IBOutlet NSTextField * _extractTextField;
    IBOutlet NSButton * _invertCheckbox;
    IBOutlet NSButton * _posterizeCheckbox;
    IBOutlet NSTextField * _posterizeLabel;
    IBOutlet NSTextField * _posterizeTextField;
    IBOutlet NSStepper * _posterizeStepper;
    IBOutlet NSButton * _blurCheckbox;
    IBOutlet NSSlider * _blurSlider;
    IBOutlet NSTextField * _blurLabel;
    IBOutlet NSButton * _motiondetectCheckbox;
    IBOutlet NSButton * _watereffectCheckbox;
    IBOutlet NSButton * _wavesCheckbox;
    IBOutlet NSButton * _psychedelicCheckbox;

    IBOutlet NSButton * _addTextCheckbox;
    IBOutlet NSTextField * _addTextTextTextField;
    IBOutlet NSTextField * _addTextTextLabel;
    IBOutlet NSTextField * _addTextPositionLabel;
    IBOutlet NSPopUpButton * _addTextPositionPopup;
    IBOutlet NSButton * _addLogoCheckbox;
    IBOutlet NSTextField * _addLogoLogoLabel;
    IBOutlet NSTextField * _addLogoLogoTextField;
    IBOutlet NSTextField * _addLogoPositionLabel;
    IBOutlet NSPopUpButton * _addLogoPositionPopup;
    IBOutlet NSTextField * _addLogoTransparencyLabel;
    IBOutlet NSSlider * _addLogoTransparencySlider;
    IBOutlet NSButton * _anaglyphCheckbox;

    VLCPopupPanelController * _popupPanel;
    VLCTextfieldPanelController * _textfieldPanel;

    int _cropLeftValue;
    int _cropTopValue;
    int _cropRightValue;
    int _cropBottomValue;

    int _puzzleRowsValue;
    int _puzzleColumnsValue;

    int _wallRowsValue;
    int _wallColumnsValue;

    int _cloneValue;

    int _sepiaValue;

    int _posterizeValue;

}

/* generic */
@property (readwrite, assign) IBOutlet NSTabView *tabView;
@property (readwrite, assign) IBOutlet NSPopUpButton *profilePopup;

/* basic */
@property (readwrite, assign) IBOutlet NSButton *adjustCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *adjustHueLabel;
@property (readwrite, assign) IBOutlet NSSlider *adjustHueSlider;
@property (readwrite, assign) IBOutlet NSTextField *adjustContrastLabel;
@property (readwrite, assign) IBOutlet NSSlider *adjustContrastSlider;
@property (readwrite, assign) IBOutlet NSTextField *adjustBrightnessLabel;
@property (readwrite, assign) IBOutlet NSSlider *adjustBrightnessSlider;
@property (readwrite, assign) IBOutlet NSButton *adjustBrightnessCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *adjustSaturationLabel;
@property (readwrite, assign) IBOutlet NSSlider *adjustSaturationSlider;
@property (readwrite, assign) IBOutlet NSTextField *adjustGammaLabel;
@property (readwrite, assign) IBOutlet NSSlider *adjustGammaSlider;
@property (readwrite, assign) IBOutlet NSButton *adjustResetButton;
@property (readwrite, assign) IBOutlet NSButton *sharpenCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *sharpenLabel;
@property (readwrite, assign) IBOutlet NSSlider *sharpenSlider;
@property (readwrite, assign) IBOutlet NSButton *bandingCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *bandingLabel;
@property (readwrite, assign) IBOutlet NSSlider *bandingSlider;
@property (readwrite, assign) IBOutlet NSButton *grainCheckbox;
@property (readwrite, assign) IBOutlet NSSlider *grainSlider;
@property (readwrite, assign) IBOutlet NSTextField *grainLabel;

/* crop */
@property (readwrite, assign) IBOutlet NSTextField *cropTopLabel;
@property (readwrite, assign) IBOutlet NSTextField *cropTopTextField;
@property (readwrite, assign) IBOutlet NSStepper *cropTopStepper;
@property (readwrite, assign) IBOutlet NSTextField *cropLeftLabel;
@property (readwrite, assign) IBOutlet NSTextField *cropLeftTextField;
@property (readwrite, assign) IBOutlet NSStepper *cropLeftStepper;
@property (readwrite, assign) IBOutlet NSTextField *cropRightLabel;
@property (readwrite, assign) IBOutlet NSTextField *cropRightTextField;
@property (readwrite, assign) IBOutlet NSStepper *cropRightStepper;
@property (readwrite, assign) IBOutlet NSTextField *cropBottomLabel;
@property (readwrite, assign) IBOutlet NSTextField *cropBottomTextField;
@property (readwrite, assign) IBOutlet NSStepper *cropBottomStepper;
@property (readwrite, assign) IBOutlet NSButton *cropSyncTopBottomCheckbox;
@property (readwrite, assign) IBOutlet NSButton *cropSyncLeftRightCheckbox;

/* geometry */
@property (readwrite, assign) IBOutlet NSButton *transformCheckbox;
@property (readwrite, assign) IBOutlet NSPopUpButton *transformPopup;
@property (readwrite, assign) IBOutlet NSButton *zoomCheckbox;
@property (readwrite, assign) IBOutlet NSButton *puzzleCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *puzzleRowsLabel;
@property (readwrite, assign) IBOutlet NSTextField *puzzleRowsTextField;
@property (readwrite, assign) IBOutlet NSStepper *puzzleRowsStepper;
@property (readwrite, assign) IBOutlet NSTextField *puzzleColumnsLabel;
@property (readwrite, assign) IBOutlet NSTextField *puzzleColumnsTextField;
@property (readwrite, assign) IBOutlet NSStepper *puzzleColumnsStepper;
@property (readwrite, assign) IBOutlet NSButton *cloneCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *cloneNumberTextField;
@property (readwrite, assign) IBOutlet NSStepper *cloneNumberStepper;
@property (readwrite, assign) IBOutlet NSTextField *cloneNumberLabel;
@property (readwrite, assign) IBOutlet NSButton *wallCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *wallNumbersOfRowsTextField;
@property (readwrite, assign) IBOutlet NSStepper *wallNumbersOfRowsStepper;
@property (readwrite, assign) IBOutlet NSTextField *wallNumbersOfRowsLabel;
@property (readwrite, assign) IBOutlet NSTextField *wallNumberOfColumnsTextField;
@property (readwrite, assign) IBOutlet NSStepper *wallNumberOfColumnsStepper;
@property (readwrite, assign) IBOutlet NSTextField *wallNumberOfColumnsLabel;

/* color */
@property (readwrite, assign) IBOutlet NSButton *thresholdCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *thresholdColorLabel;
@property (readwrite, assign) IBOutlet NSTextField *thresholdColorTextField;
@property (readwrite, assign) IBOutlet NSTextField *thresholdSaturationLabel;
@property (readwrite, assign) IBOutlet NSSlider *thresholdSaturationSlider;
@property (readwrite, assign) IBOutlet NSTextField *thresholdSimilarityLabel;
@property (readwrite, assign) IBOutlet NSSlider *thresholdSimilaritySlider;
@property (readwrite, assign) IBOutlet NSButton *sepiaCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *sepiaLabel;
@property (readwrite, assign) IBOutlet NSTextField *sepiaTextField;
@property (readwrite, assign) IBOutlet NSStepper *sepiaStepper;
@property (readwrite, assign) IBOutlet NSButton *noiseCheckbox;
@property (readwrite, assign) IBOutlet NSButton *gradientCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *gradientModeLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *gradientModePopup;
@property (readwrite, assign) IBOutlet NSButton *gradientColorCheckbox;
@property (readwrite, assign) IBOutlet NSButton *gradientCartoonCheckbox;
@property (readwrite, assign) IBOutlet NSButton *extractCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *extractLabel;
@property (readwrite, assign) IBOutlet NSTextField *extractTextField;
@property (readwrite, assign) IBOutlet NSButton *invertCheckbox;
@property (readwrite, assign) IBOutlet NSButton *posterizeCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *posterizeLabel;
@property (readwrite, assign) IBOutlet NSTextField *posterizeTextField;
@property (readwrite, assign) IBOutlet NSStepper *posterizeStepper;
@property (readwrite, assign) IBOutlet NSButton *blurCheckbox;
@property (readwrite, assign) IBOutlet NSSlider *blurSlider;
@property (readwrite, assign) IBOutlet NSTextField *blurLabel;
@property (readwrite, assign) IBOutlet NSButton *motiondetectCheckbox;
@property (readwrite, assign) IBOutlet NSButton *watereffectCheckbox;
@property (readwrite, assign) IBOutlet NSButton *wavesCheckbox;
@property (readwrite, assign) IBOutlet NSButton *psychedelicCheckbox;

/* misc */
@property (readwrite, assign) IBOutlet NSButton *addTextCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *addTextTextTextField;
@property (readwrite, assign) IBOutlet NSTextField *addTextTextLabel;
@property (readwrite, assign) IBOutlet NSTextField *addTextPositionLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *addTextPositionPopup;
@property (readwrite, assign) IBOutlet NSButton *addLogoCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *addLogoLogoLabel;
@property (readwrite, assign) IBOutlet NSTextField *addLogoLogoTextField;
@property (readwrite, assign) IBOutlet NSTextField *addLogoPositionLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *addLogoPositionPopup;
@property (readwrite, assign) IBOutlet NSTextField *addLogoTransparencyLabel;
@property (readwrite, assign) IBOutlet NSSlider *addLogoTransparencySlider;
@property (readwrite, assign) IBOutlet NSButton *anaglyphCheckbox;

@property (retain) VLCPopupPanelController *popupPanel;
@property (retain) VLCTextfieldPanelController *textfieldPanel;

/* text field / stepper binding values */
/* use setter to modify gui elements */
@property (nonatomic) int cropLeftValue;
@property (nonatomic) int cropTopValue;
@property (nonatomic) int cropRightValue;
@property (nonatomic) int cropBottomValue;

@property (nonatomic) int puzzleRowsValue;
@property (nonatomic) int puzzleColumnsValue;

@property (nonatomic) int wallRowsValue;
@property (nonatomic) int wallColumnsValue;

@property (nonatomic) int cloneValue;

@property (nonatomic) int sepiaValue;

@property (nonatomic) int posterizeValue;

- (void)resetValues;
- (void)resetProfileSelector;

/* generic */
- (void)updateCocoaWindowLevel:(NSInteger)i_level;
- (void)saveCurrentProfile;

- (void)toggleWindow:(id)sender;
- (IBAction)profileSelectorAction:(id)sender;

/* basic */
- (IBAction)enableAdjust:(id)sender;
- (IBAction)adjustSliderChanged:(id)sender;
- (IBAction)enableAdjustBrightnessThreshold:(id)sender;
- (IBAction)enableSharpen:(id)sender;
- (IBAction)sharpenSliderChanged:(id)sender;
- (IBAction)enableBanding:(id)sender;
- (IBAction)bandingSliderChanged:(id)sender;
- (IBAction)enableGrain:(id)sender;
- (IBAction)grainSliderChanged:(id)sender;

/* crop */
- (IBAction)cropObjectChanged:(id)sender;

/* geometry */
- (IBAction)enableTransform:(id)sender;
- (IBAction)transformModifierChanged:(id)sender;
- (IBAction)enableZoom:(id)sender;
- (IBAction)enablePuzzle:(id)sender;
- (IBAction)puzzleModifierChanged:(id)sender;
- (IBAction)enableClone:(id)sender;
- (IBAction)cloneModifierChanged:(id)sender;
- (IBAction)enableWall:(id)sender;
- (IBAction)wallModifierChanged:(id)sender;

/* color */
- (IBAction)enableThreshold:(id)sender;
- (IBAction)thresholdModifierChanged:(id)sender;
- (IBAction)enableSepia:(id)sender;
- (IBAction)sepiaModifierChanged:(id)sender;
- (IBAction)enableNoise:(id)sender;
- (IBAction)enableGradient:(id)sender;
- (IBAction)gradientModifierChanged:(id)sender;
- (IBAction)enableExtract:(id)sender;
- (IBAction)extractModifierChanged:(id)sender;
- (IBAction)enableInvert:(id)sender;
- (IBAction)enablePosterize:(id)sender;
- (IBAction)posterizeModifierChanged:(id)sender;
- (IBAction)enableBlur:(id)sender;
- (IBAction)blurModifierChanged:(id)sender;
- (IBAction)enableMotionDetect:(id)sender;
- (IBAction)enableWaterEffect:(id)sender;
- (IBAction)enableWaves:(id)sender;
- (IBAction)enablePsychedelic:(id)sender;

/* miscellaneous */
- (IBAction)enableAddText:(id)sender;
- (IBAction)addTextModifierChanged:(id)sender;
- (IBAction)enableAddLogo:(id)sender;
- (IBAction)addLogoModifierChanged:(id)sender;
- (IBAction)enableAnaglyph:(id)sender;

@end
