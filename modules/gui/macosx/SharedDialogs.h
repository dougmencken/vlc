/*****************************************************************************
 * SharedDialogs.h: MacOS X interface module
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


@interface VLCTextfieldPanelController : NSWindowController {

    // ivars for properties

    IBOutlet NSTextField * _titleLabel;
    IBOutlet NSTextField * _subtitleLabel;
    IBOutlet NSTextField * _textField;
    IBOutlet NSButton * _cancelButton;
    IBOutlet NSButton * _okButton;

    NSString * _titleString;
    NSString * _subTitleString;
    NSString * _okButtonString;
    NSString * _cancelButtonString;

    id _target;

}

@property (assign) IBOutlet NSTextField *titleLabel;
@property (assign) IBOutlet NSTextField *subtitleLabel;
@property (assign) IBOutlet NSTextField *textField;
@property (assign) IBOutlet NSButton *cancelButton;
@property (assign) IBOutlet NSButton *okButton;

@property (readwrite, assign) NSString *titleString;
@property (readwrite, assign) NSString *subTitleString;
@property (readwrite, assign) NSString *okButtonString;
@property (readwrite, assign) NSString *cancelButtonString;

@property (readwrite, assign) id target;

/**
 * Shows the panel as a modal dialog with window as its owner.
 * \param window Parent window for the dialog.
 */
- (void)runModalForWindow:(NSWindow *)window;

- (IBAction)windowElementAction:(id)sender;

@end


@interface VLCPopupPanelController : NSWindowController {

    // properties

    IBOutlet NSTextField * _titleLabel;
    IBOutlet NSTextField * _subtitleLabel;
    IBOutlet NSPopUpButton * _popupButton;
    IBOutlet NSButton * _cancelButton;
    IBOutlet NSButton * _okButton;

    NSString * _titleString;
    NSString * _subTitleString;
    NSString * _okButtonString;
    NSString * _cancelButtonString;
    NSArray * _popupButtonContent;

    id _target;

}

@property (assign) IBOutlet NSTextField *titleLabel;
@property (assign) IBOutlet NSTextField *subtitleLabel;
@property (assign) IBOutlet NSPopUpButton *popupButton;
@property (assign) IBOutlet NSButton *cancelButton;
@property (assign) IBOutlet NSButton *okButton;

@property (readwrite, assign) NSString *titleString;
@property (readwrite, assign) NSString *subTitleString;
@property (readwrite, assign) NSString *okButtonString;
@property (readwrite, assign) NSString *cancelButtonString;
@property (readwrite, assign) NSArray *popupButtonContent;

@property (readwrite, assign) id target;

/**
 * Shows the panel as a modal dialog with window as its owner.
 * \param window Parent window for the dialog.
 */
- (void)runModalForWindow:(NSWindow *)window;

- (IBAction)windowElementAction:(id)sender;

@end
