/*****************************************************************************
 * AddonManager.h: Addons manager for the Mac
 ****************************************************************************
 * Copyright (C) 2014 VideoLAN and authors
 * Author:       Felix Paul Kühne <fkuehne # videolan.org>
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

#import <vlc_addons.h>

#import <Cocoa/Cocoa.h>
#import "CompatibilityFixes.h"

@interface AddonsWindowController : NSWindowController < NSTableViewDataSource, NSTableViewDelegate >
{
    IBOutlet NSPopUpButton *_typeSwitcher;
    IBOutlet NSButton *_localAddonsOnlyCheckbox;
    IBOutlet NSButton *_downloadCatalogButton;

    IBOutlet NSTableView *_addonsTable;
    IBOutlet NSProgressIndicator *_spinner;
    IBOutlet NSTextField *_name;
    IBOutlet NSTextField *_author;
    IBOutlet NSTextField *_version;
    IBOutlet NSTextView *_description;
    IBOutlet NSButton *_installButton;

    addons_manager_t *_manager;
    NSMutableArray *_addons;
    NSArray *_displayedAddons;
    BOOL _shouldRefreshSideBarOnAddonChange;
}

- (IBAction)switchType:(id)sender;
- (IBAction)toggleLocalCheckbox:(id)sender;
- (IBAction)downloadCatalog:(id)sender;
- (IBAction)installSelection:(id)sender;
- (IBAction)uninstallSelection:(id)sender;

- (void)addAddon:(NSValue *)o_value;
- (void)discoveryEnded;
- (void)addonChanged:(NSValue *)o_value;

- (void)updateInstallButton:(BOOL)b_is_installed;

- (void)_findInstalled;
- (void)_refactorDataModel;
- (void)_findNewAddons;
- (void)_installAddonWithID:(NSData *)o_data type:(addon_type_t)type;
- (void)_removeAddonWithID:(NSData *)o_data type:(addon_type_t)type;

@end
