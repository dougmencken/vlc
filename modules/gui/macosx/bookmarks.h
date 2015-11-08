/*****************************************************************************
 * bookmarks.h: MacOS X Bookmarks window
 *****************************************************************************
 * Copyright (C) 2005, 2007, 2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Felix Kühne <fkuehne at videolan dot org>
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
#import "CompatibilityFixes.h"

@interface VLCBookmarks : NSWindowController <NSTableViewDataSource, NSTableViewDelegate> {

    IBOutlet NSButton * _addButton;
    IBOutlet NSButton * _clearButton;
    IBOutlet NSButton * _editButton;
    IBOutlet NSButton * _extractButton;
    IBOutlet NSButton * _removeButton;
    IBOutlet NSTableView * _dataTable;

    IBOutlet NSWindow * _editBookmarksWindow;
    IBOutlet NSButton * _editOKButton;
    IBOutlet NSButton * _editCancelButton;
    IBOutlet NSTextField * _editNameLabel;
    IBOutlet NSTextField * _editTimeLabel;
    IBOutlet NSTextField * _editNameTextField;
    IBOutlet NSTextField * _editTimeTextField;

    input_thread_t *p_old_input;

}

/* main window */
@property (readwrite, assign) IBOutlet NSButton *addButton;
@property (readwrite, assign) IBOutlet NSButton *clearButton;
@property (readwrite, assign) IBOutlet NSButton *editButton;
@property (readwrite, assign) IBOutlet NSButton *extractButton;
@property (readwrite, assign) IBOutlet NSButton *removeButton;
@property (readwrite, assign) IBOutlet NSTableView *dataTable;

/* edit window */
@property (readwrite, assign) IBOutlet NSWindow *editBookmarksWindow;
@property (readwrite, assign) IBOutlet NSButton *editOKButton;
@property (readwrite, assign) IBOutlet NSButton *editCancelButton;
@property (readwrite, assign) IBOutlet NSTextField *editNameLabel;
@property (readwrite, assign) IBOutlet NSTextField *editTimeLabel;
@property (readwrite, assign) IBOutlet NSTextField *editNameTextField;
@property (readwrite, assign) IBOutlet NSTextField *editTimeTextField;

- (void)updateCocoaWindowLevel:(NSInteger)i_level;

- (IBAction)add:(id)sender;
- (IBAction)clear:(id)sender;
- (IBAction)edit:(id)sender;
- (IBAction)extract:(id)sender;
- (IBAction)remove:(id)sender;
- (IBAction)goToBookmark:(id)sender;

- (IBAction)edit_cancel:(id)sender;
- (IBAction)edit_ok:(id)sender;

- (void)showBookmarks;

@end
