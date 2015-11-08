/*****************************************************************************
 * output.h: MacOS X Output Dialog
 *****************************************************************************
 * Copyright (C) 2002-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Jon Lech Johansen <jon-vl@nanocrew.net>
 *          Christophe Massiot <massiot@via.ecp.fr>
 *          Derk-Jan Hartman <thedj@users.sourceforge.net>
 *          Felix Paul Kühne <fkuehne # videolan org>
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

@interface VLCOutput : NSObject {

    IBOutlet NSPanel * _outputSheet;
    IBOutlet NSButton * _okButton;

    IBOutlet NSBox * _optionsBox;
    IBOutlet NSButton * _displayOnLocalScreenCheckbox;
    IBOutlet NSMatrix * _outputMethodMatrix;
    IBOutlet NSTextField * _fileTextField;
    IBOutlet NSButton * _dumpCheckbox;
    IBOutlet NSButton * _browseButton;
    IBOutlet NSTextField * _streamAddressTextField;
    IBOutlet NSTextField * _streamAddressLabel;
    IBOutlet NSTextField * _streamPortTextField;
    IBOutlet NSStepper * _streamPortStepper;
    IBOutlet NSTextField * _streamPortLabel;
    IBOutlet NSTextField * _streamTTLTextField;
    IBOutlet NSStepper * _streamTTLStepper;
    IBOutlet NSTextField * _streamTTLLabel;
    IBOutlet NSPopUpButton * _streamTypePopup;
    IBOutlet NSTextField * _streamTypeLabel;

    IBOutlet NSTextField * _muxLabel;
    IBOutlet NSPopUpButton * _muxSelectorPopup;

    IBOutlet NSBox * _transcodeBox;
    IBOutlet NSComboBox * _transcodeAudioBitrateComboBox;
    IBOutlet NSTextField * _transcodeAudioBitrateLabel;
    IBOutlet NSComboBox * _transcodeAudioChannelsComboBox;
    IBOutlet NSTextField * _transcodeAudioChannelsLabel;
    IBOutlet NSButton * _transcodeAudioCheckbox;
    IBOutlet NSPopUpButton * _transcodeAudioSelectorPopup;
    IBOutlet NSComboBox * _transcodeVideoBitrateComboBox;
    IBOutlet NSTextField * _transcodeVideoBitrateLabel;
    IBOutlet NSComboBox * _transcodeVideoScaleComboBox;
    IBOutlet NSTextField * _transcodeVideoScaleLabel;
    IBOutlet NSButton * _transcodeVideoCheckbox;
    IBOutlet NSPopUpButton * _transcodeVideoSelectorPopup;

    IBOutlet NSBox * _miscBox;
    IBOutlet NSButton * _sapCheckbox;
    IBOutlet NSTextField * _channelNameTextField;
    IBOutlet NSTextField * _channelNameLabel;

    IBOutlet NSTextField * _sdpURLTextField;
    IBOutlet NSTextField * _sdpURLLabel;
    IBOutlet NSButton * _rtspCheckbox;
    IBOutlet NSButton * _httpCheckbox;
    IBOutlet NSButton * _fileCheckbox;

    NSArray * _soutMRL;

    NSString * _transcode;

}

@property (readwrite, assign) IBOutlet NSPanel *outputSheet;
@property (readwrite, assign) IBOutlet NSButton *okButton;

@property (readwrite, assign) IBOutlet NSBox *optionsBox;
@property (readwrite, assign) IBOutlet NSButton *displayOnLocalScreenCheckbox;
@property (readwrite, assign) IBOutlet NSMatrix *outputMethodMatrix;
@property (readwrite, assign) IBOutlet NSTextField *fileTextField;
@property (readwrite, assign) IBOutlet NSButton *dumpCheckbox;
@property (readwrite, assign) IBOutlet NSButton *browseButton;
@property (readwrite, assign) IBOutlet NSTextField *streamAddressTextField;
@property (readwrite, assign) IBOutlet NSTextField *streamAddressLabel;
@property (readwrite, assign) IBOutlet NSTextField *streamPortTextField;
@property (readwrite, assign) IBOutlet NSStepper *streamPortStepper;
@property (readwrite, assign) IBOutlet NSTextField *streamPortLabel;
@property (readwrite, assign) IBOutlet NSTextField *streamTTLTextField;
@property (readwrite, assign) IBOutlet NSStepper *streamTTLStepper;
@property (readwrite, assign) IBOutlet NSTextField *streamTTLLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *streamTypePopup;
@property (readwrite, assign) IBOutlet NSTextField *streamTypeLabel;

@property (readwrite, assign) IBOutlet NSTextField *muxLabel;
@property (readwrite, assign) IBOutlet NSPopUpButton *muxSelectorPopup;

@property (readwrite, assign) IBOutlet NSBox *transcodeBox;
@property (readwrite, assign) IBOutlet NSComboBox *transcodeAudioBitrateComboBox;
@property (readwrite, assign) IBOutlet NSTextField *transcodeAudioBitrateLabel;
@property (readwrite, assign) IBOutlet NSComboBox *transcodeAudioChannelsComboBox;
@property (readwrite, assign) IBOutlet NSTextField *transcodeAudioChannelsLabel;
@property (readwrite, assign) IBOutlet NSButton *transcodeAudioCheckbox;
@property (readwrite, assign) IBOutlet NSPopUpButton *transcodeAudioSelectorPopup;
@property (readwrite, assign) IBOutlet NSComboBox *transcodeVideoBitrateComboBox;
@property (readwrite, assign) IBOutlet NSTextField *transcodeVideoBitrateLabel;
@property (readwrite, assign) IBOutlet NSComboBox *transcodeVideoScaleComboBox;
@property (readwrite, assign) IBOutlet NSTextField *transcodeVideoScaleLabel;
@property (readwrite, assign) IBOutlet NSButton *transcodeVideoCheckbox;
@property (readwrite, assign) IBOutlet NSPopUpButton *transcodeVideoSelectorPopup;

@property (readwrite, assign) IBOutlet NSBox *miscBox;
@property (readwrite, assign) IBOutlet NSButton *sapCheckbox;
@property (readwrite, assign) IBOutlet NSTextField *channelNameTextField;
@property (readwrite, assign) IBOutlet NSTextField *channelNameLabel;

@property (readwrite, assign) IBOutlet NSTextField *sdpURLTextField;
@property (readwrite, assign) IBOutlet NSTextField *sdpURLLabel;
@property (readwrite, assign) IBOutlet NSButton *rtspCheckbox;
@property (readwrite, assign) IBOutlet NSButton *httpCheckbox;
@property (readwrite, assign) IBOutlet NSButton *fileCheckbox;

@property (readonly) NSArray *soutMRL;

- (IBAction)outputCloseSheet:(id)sender;
- (IBAction)outputMethodChanged:(id)sender;
- (IBAction)outputInfoChanged:(id)object;
- (IBAction)outputFileBrowse:(id)sender;
- (IBAction)streamPortStepperChanged:(id)sender;
- (IBAction)streamTTLStepperChanged:(id)sender;
- (IBAction)transcodeChanged:(id)sender;
- (IBAction)transcodeInfoChanged:(id)object;
- (IBAction)announceChanged:(id)sender;

- (IBAction)streamTTLStepperChanged:(id)sender;

@end
