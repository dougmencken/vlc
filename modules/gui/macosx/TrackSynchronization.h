/*****************************************************************************
 * TrackSynchronization.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2011-2012 VLC authors and VideoLAN
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

@interface VLCTrackSynchronization : NSWindowController {

    IBOutlet NSButton * _resetButton;
    IBOutlet NSTextField * _avLabel;
    IBOutlet NSTextField * _av_advanceLabel;
    IBOutlet NSTextField * _av_advanceTextField;
    IBOutlet NSStepper * _avStepper;
    IBOutlet NSTextField * _svLabel;
    IBOutlet NSTextField * _sv_advanceLabel;
    IBOutlet NSTextField * _sv_advanceTextField;
    IBOutlet NSStepper * _sv_advanceStepper;
    IBOutlet NSTextField * _sv_speedLabel;
    IBOutlet NSTextField * _sv_speedTextField;
    IBOutlet NSStepper * _sv_speedStepper;
    IBOutlet NSTextField * _sv_durLabel;
    IBOutlet NSTextField * _sv_durTextField;
    IBOutlet NSStepper * _sv_durStepper;

}

/* generic */
@property (readwrite, assign) IBOutlet NSButton *resetButton;

/* Audio / Video */
@property (readwrite, assign) IBOutlet NSTextField *avLabel;
@property (readwrite, assign) IBOutlet NSTextField *av_advanceLabel;
@property (readwrite, assign) IBOutlet NSTextField *av_advanceTextField;
@property (readwrite, assign) IBOutlet NSStepper *avStepper;

/* Subtitles / Video */
@property (readwrite, assign) IBOutlet NSTextField *svLabel;
@property (readwrite, assign) IBOutlet NSTextField *sv_advanceLabel;
@property (readwrite, assign) IBOutlet NSTextField *sv_advanceTextField;
@property (readwrite, assign) IBOutlet NSStepper *sv_advanceStepper;
@property (readwrite, assign) IBOutlet NSTextField *sv_speedLabel;
@property (readwrite, assign) IBOutlet NSTextField *sv_speedTextField;
@property (readwrite, assign) IBOutlet NSStepper *sv_speedStepper;
@property (readwrite, assign) IBOutlet NSTextField *sv_durLabel;
@property (readwrite, assign) IBOutlet NSTextField *sv_durTextField;
@property (readwrite, assign) IBOutlet NSStepper *sv_durStepper;


- (void)updateCocoaWindowLevel:(NSInteger)i_level;
- (IBAction)toggleWindow:(id)sender;
- (IBAction)resetValues:(id)sender;
- (void)updateValues;

- (IBAction)avValueChanged:(id)sender;

- (IBAction)svAdvanceValueChanged:(id)sender;
- (IBAction)svSpeedValueChanged:(id)sender;
- (IBAction)svDurationValueChanged:(id)sender;
@end
