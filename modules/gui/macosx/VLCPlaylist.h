/*****************************************************************************
 * VLCPlaylist.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2002-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Benjamin Pracht <bigben at videolab dot org>
 *          Felix Paul Kühne <fkuehne at videolan dot org>
 *          David Fuhrmann <david dot fuhrmann at googlemail dot com>
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

#import "PXSourceList.h"
#import "PLModel.h"
#import "VLCPlaylistView.h"

@interface VLCPlaylist : NSObject<NSOutlineViewDelegate> {

    NSImage *_descendingSortingImage;
    NSImage *_ascendingSortingImage;

    BOOL b_selected_item_met;
    BOOL b_isSortDescending;
    NSTableColumn *_sortTableColumn;

    BOOL b_playlistmenu_nib_loaded;
    BOOL b_view_setup;

    PLModel *_model;

    // ivars for properties
    IBOutlet NSMenu * _playlistMenu;
    IBOutlet NSMenuItem * _playPlaylistMenuItem;
    IBOutlet NSMenuItem * _deletePlaylistMenuItem;
    IBOutlet NSMenuItem * _infoPlaylistMenuItem;
    IBOutlet NSMenuItem * _preparsePlaylistMenuItem;
    IBOutlet NSMenuItem * _revealInFinderPlaylistMenuItem;
    IBOutlet NSMenuItem * _downloadCoverArtPlaylistMenuItem;
    IBOutlet NSMenuItem * _selectAllPlaylistMenuItem;
    IBOutlet NSMenuItem * _sortNamePlaylistMenuItem;
    IBOutlet NSMenuItem * _sortAuthorPlaylistMenuItem;
    IBOutlet NSMenuItem * _recursiveExpandPlaylistMenuItem;
    VLCPlaylistView * _outlineView;
    NSTableHeaderView * _playlistHeaderView;

}

@property (readwrite, assign) IBOutlet NSMenu *playlistMenu;
@property (readwrite, assign) IBOutlet NSMenuItem *playPlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *deletePlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *infoPlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *preparsePlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *revealInFinderPlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *downloadCoverArtPlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *selectAllPlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *sortNamePlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *sortAuthorPlaylistMenuItem;
@property (readwrite, assign) IBOutlet NSMenuItem *recursiveExpandPlaylistMenuItem;

@property (nonatomic, readwrite, assign) VLCPlaylistView *outlineView;
@property (nonatomic, readwrite, assign) NSTableHeaderView *playlistHeaderView;

- (PLModel *)model;

- (void)reloadStyles;

- (NSMenu *)menuForEvent:(NSEvent *)o_event;

- (void)playlistUpdated;
- (void)playbackModeUpdated;
- (void)updateTogglePlaylistState;
- (void)outlineViewSelectionDidChange:(NSNotification *)notification;
- (void)sortNode:(int)i_mode;

- (void)currentlyPlayingItemChanged;

- (BOOL)isSelectionEmpty;

- (IBAction)playItem:(id)sender;
- (IBAction)revealItemInFinder:(id)sender;
- (IBAction)preparseItem:(id)sender;
- (IBAction)downloadCoverArt:(id)sender;
- (IBAction)deleteItem:(id)sender;
- (IBAction)selectAll:(id)sender;
- (IBAction)sortNodeByName:(id)sender;
- (IBAction)sortNodeByAuthor:(id)sender;
- (IBAction)recursiveExpandNode:(id)sender;
- (IBAction)showInfoPanel:(id)sender;

- (NSArray *)draggedItems;

/**
 * Simplified version to add new items at the end of the current playlist
 */
- (void)addPlaylistItems:(NSArray*)o_array;

/**
 * Adds new items to the playlist, at specified parent node and index.
 * @param o_array array of items. Each item is a Dictionary with meta info.
 * @param i_plItemId parent playlist node id, -1 for default playlist
 * @param i_position index for new items, -1 for appending at end
 * @param b_start starts playback of first item if true
 */
- (void)addPlaylistItems:(NSArray*)o_array withParentItemId:(int)i_plItemId atPos:(int)i_position startPlayback:(BOOL)b_start;


- (void)setColumn: (NSString *)o_column state: (NSInteger)i_state translationDict:(NSDictionary *)o_dict;
- (void)continuePlaybackWhereYouLeftOff:(input_thread_t *)p_input_thread;
- (void)storePlaybackPositionForItem:(input_thread_t *)p_input_thread;

- (void)saveTableColumns;

- (void)initStrings;

@end
