/*****************************************************************************
 * TimeSelectionPanelController.h: Controller for time selection panel
 *****************************************************************************
 * Copyright (C) 2015 VideoLAN and authors
 * Author:       David Fuhrmann <david dot fuhrmann at googlemail dot com>
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

@interface VLCTimeSelectionPanelController : NSWindowController {

    IBOutlet NSButton * _cancelButton;
    IBOutlet NSTextField * _textField;
    IBOutlet NSTextField * _goToLabel;
    IBOutlet NSButton * _okButton;
    IBOutlet NSTextField * _secsLabel;
    IBOutlet NSStepper * _stepper;

    int _jumpTimeValue;
    int _maxValue;

}

@property (readwrite, assign) IBOutlet NSButton *cancelButton;
@property (readwrite, assign) IBOutlet NSTextField *textField;
@property (readwrite, assign) IBOutlet NSTextField *goToLabel;
@property (readwrite, assign) IBOutlet NSButton *okButton;
@property (readwrite, assign) IBOutlet NSTextField *secsLabel;
@property (readwrite, assign) IBOutlet NSStepper *stepper;

@property (nonatomic) int jumpTimeValue;
@property (nonatomic) int maxValue;

- (IBAction)buttonPressed:(id)sender;

/**
 * Shows the panel as a modal dialog with window as its owner.
 */
- (void)runModalForWindow:(NSWindow *)window target:(id)obj completionSelector:(SEL)sel;


@end