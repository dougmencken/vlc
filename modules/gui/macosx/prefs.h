/*****************************************************************************
 * prefs.h: MacOS X module for vlc
 *****************************************************************************
 * Copyright (C) 2002-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Jon Lech Johansen <jon-vl@nanocrew.net>
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

@class VLCTreeMainItem;

/*****************************************************************************
 * VLCPrefs interface
 *****************************************************************************/
@interface VLCPrefs : NSWindowController {

    VLCTreeMainItem *_rootTreeItem;
    NSView *o_emptyView;
    NSMutableDictionary *o_save_prefs;

    // property ivars
    IBOutlet NSTextField * _titleLabel;
    IBOutlet NSOutlineView * _tree;
    IBOutlet NSScrollView * _prefsView;
    IBOutlet NSButton * _saveButton;
    IBOutlet NSButton * _cancelButton;
    IBOutlet NSButton * _resetButton;
    IBOutlet NSButton * _showBasicButton;

}

@property (readwrite, assign) IBOutlet NSTextField *titleLabel;
@property (readwrite, assign) IBOutlet NSOutlineView *tree;
@property (readwrite, assign) IBOutlet NSScrollView *prefsView;
@property (readwrite, assign) IBOutlet NSButton *saveButton;
@property (readwrite, assign) IBOutlet NSButton *cancelButton;
@property (readwrite, assign) IBOutlet NSButton *resetButton;
@property (readwrite, assign) IBOutlet NSButton *showBasicButton;

- (void)setTitle: (NSString *) o_title_name;
- (void)showPrefsWithLevel:(NSInteger)i_window_level;
- (IBAction)savePrefs: (id)sender;
- (IBAction)closePrefs: (id)sender;
- (IBAction)showSimplePrefs: (id)sender;
- (IBAction)resetPrefs: (id)sender;

@end
