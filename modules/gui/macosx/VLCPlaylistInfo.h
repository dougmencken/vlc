/*****************************************************************************
 * VLCPlaylistInfo.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2002-2015 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Benjamin Pracht <bigben at videolan dot org>
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

/*****************************************************************************
 * VLCPlaylistInfo interface
 *****************************************************************************/

#import "CompatibilityFixes.h"

@class VLCInfoTreeItem;

@interface VLCInfo : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate> {

    VLCInfoTreeItem *rootItem;

    input_item_t *p_item;

    BOOL b_nibLoaded;
    BOOL b_awakeFromNib;
    BOOL b_stats;

    // ivars for properties

    input_item_t * _item;

    IBOutlet NSPanel * _infoPanel;
    IBOutlet NSOutlineView * _outlineView;
    IBOutlet NSTabView * _tabView;

    IBOutlet NSTextField * _uriLabel;
    IBOutlet NSTextField * _titleLabel;
    IBOutlet NSTextField * _authorLabel;
    IBOutlet NSTextField * _uriTextField;
    IBOutlet NSTextField * _titleTextField;
    IBOutlet NSTextField * _authorTextField;
    IBOutlet NSTextField * _collectionLabel;
    IBOutlet NSTextField * _collectionTextField;
    IBOutlet NSTextField * _copyrightLabel;
    IBOutlet NSTextField * _copyrightTextField;
    IBOutlet NSTextField * _dateLabel;
    IBOutlet NSTextField * _dateTextField;
    IBOutlet NSTextField * _descriptionLabel;
    IBOutlet NSTextField * _descriptionTextField;
    IBOutlet NSTextField * _encodedbyLabel;
    IBOutlet NSTextField * _encodedbyTextField;
    IBOutlet NSTextField * _genreLabel;
    IBOutlet NSTextField * _genreTextField;
    IBOutlet NSTextField * _languageLabel;
    IBOutlet NSTextField * _languageTextField;
    IBOutlet NSTextField * _nowPlayingLabel;
    IBOutlet NSTextField * _nowPlayingTextField;
    IBOutlet NSTextField * _publisherLabel;
    IBOutlet NSTextField * _publisherTextField;
    IBOutlet NSTextField * _seqNumLabel;
    IBOutlet NSTextField * _seqNumTextField;
    IBOutlet NSImageView * _imageWell;
    IBOutlet NSButton * _saveMetaDataButton;

    IBOutlet NSTextField * _audioLabel;
    IBOutlet NSTextField * _audioDecodedLabel;
    IBOutlet NSTextField * _audioDecodedTextField;
    IBOutlet NSTextField * _demuxBitrateLabel;
    IBOutlet NSTextField * _demuxBitrateTextField;
    IBOutlet NSTextField * _demuxBytesLabel;
    IBOutlet NSTextField * _demuxBytesTextField;
    IBOutlet NSTextField * _displayedLabel;
    IBOutlet NSTextField * _displayedTextField;
    IBOutlet NSTextField * _inputBitrateLabel;
    IBOutlet NSTextField * _inputBitrateTextField;
    IBOutlet NSTextField * _inputLabel;
    IBOutlet NSTextField * _lostAudioBuffersLabel;
    IBOutlet NSTextField * _lostAudioBuffersTextField;
    IBOutlet NSTextField * _lostFramesLabel;
    IBOutlet NSTextField * _lostFramesTextField;
    IBOutlet NSTextField * _playedAudioBuffersLabel;
    IBOutlet NSTextField * _playedAudioBuffersTextField;
    IBOutlet NSTextField * _readBytesLabel;
    IBOutlet NSTextField * _readBytesTextField;
    IBOutlet NSTextField * _sentBitrateLabel;
    IBOutlet NSTextField * _sentBitrateTextField;
    IBOutlet NSTextField * _sentBytesLabel;
    IBOutlet NSTextField * _sentBytesTextField;
    IBOutlet NSTextField * _sentPacketsLabel;
    IBOutlet NSTextField * _sentPacketsTextField;
    IBOutlet NSTextField * _soutLabel;
    IBOutlet NSTextField * _videoLabel;
    IBOutlet NSTextField * _videoDecodedLabel;
    IBOutlet NSTextField * _videoDecodedTextField;

}

@property (readonly) input_item_t *item;

@property (readwrite, assign) IBOutlet NSPanel *infoPanel;
@property (readwrite, assign) IBOutlet NSOutlineView *outlineView;
@property (readwrite, assign) IBOutlet NSTabView *tabView;

@property (readwrite, assign) IBOutlet NSTextField *uriLabel;
@property (readwrite, assign) IBOutlet NSTextField *titleLabel;
@property (readwrite, assign) IBOutlet NSTextField *authorLabel;
@property (readwrite, assign) IBOutlet NSTextField *uriTextField;
@property (readwrite, assign) IBOutlet NSTextField *titleTextField;
@property (readwrite, assign) IBOutlet NSTextField *authorTextField;
@property (readwrite, assign) IBOutlet NSTextField *collectionLabel;
@property (readwrite, assign) IBOutlet NSTextField *collectionTextField;
@property (readwrite, assign) IBOutlet NSTextField *copyrightLabel;
@property (readwrite, assign) IBOutlet NSTextField *copyrightTextField;
@property (readwrite, assign) IBOutlet NSTextField *dateLabel;
@property (readwrite, assign) IBOutlet NSTextField *dateTextField;
@property (readwrite, assign) IBOutlet NSTextField *descriptionLabel;
@property (readwrite, assign) IBOutlet NSTextField *descriptionTextField;
@property (readwrite, assign) IBOutlet NSTextField *encodedbyLabel;
@property (readwrite, assign) IBOutlet NSTextField *encodedbyTextField;
@property (readwrite, assign) IBOutlet NSTextField *genreLabel;
@property (readwrite, assign) IBOutlet NSTextField *genreTextField;
@property (readwrite, assign) IBOutlet NSTextField *languageLabel;
@property (readwrite, assign) IBOutlet NSTextField *languageTextField;
@property (readwrite, assign) IBOutlet NSTextField *nowPlayingLabel;
@property (readwrite, assign) IBOutlet NSTextField *nowPlayingTextField;
@property (readwrite, assign) IBOutlet NSTextField *publisherLabel;
@property (readwrite, assign) IBOutlet NSTextField *publisherTextField;
@property (readwrite, assign) IBOutlet NSTextField *seqNumLabel;
@property (readwrite, assign) IBOutlet NSTextField *seqNumTextField;
@property (readwrite, assign) IBOutlet NSImageView *imageWell;
@property (readwrite, assign) IBOutlet NSButton *saveMetaDataButton;

@property (readwrite, assign) IBOutlet NSTextField *audioLabel;
@property (readwrite, assign) IBOutlet NSTextField *audioDecodedLabel;
@property (readwrite, assign) IBOutlet NSTextField *audioDecodedTextField;
@property (readwrite, assign) IBOutlet NSTextField *demuxBitrateLabel;
@property (readwrite, assign) IBOutlet NSTextField *demuxBitrateTextField;
@property (readwrite, assign) IBOutlet NSTextField *demuxBytesLabel;
@property (readwrite, assign) IBOutlet NSTextField *demuxBytesTextField;
@property (readwrite, assign) IBOutlet NSTextField *displayedLabel;
@property (readwrite, assign) IBOutlet NSTextField *displayedTextField;
@property (readwrite, assign) IBOutlet NSTextField *inputBitrateLabel;
@property (readwrite, assign) IBOutlet NSTextField *inputBitrateTextField;
@property (readwrite, assign) IBOutlet NSTextField *inputLabel;
@property (readwrite, assign) IBOutlet NSTextField *lostAudioBuffersLabel;
@property (readwrite, assign) IBOutlet NSTextField *lostAudioBuffersTextField;
@property (readwrite, assign) IBOutlet NSTextField *lostFramesLabel;
@property (readwrite, assign) IBOutlet NSTextField *lostFramesTextField;
@property (readwrite, assign) IBOutlet NSTextField *playedAudioBuffersLabel;
@property (readwrite, assign) IBOutlet NSTextField *playedAudioBuffersTextField;
@property (readwrite, assign) IBOutlet NSTextField *readBytesLabel;
@property (readwrite, assign) IBOutlet NSTextField *readBytesTextField;
@property (readwrite, assign) IBOutlet NSTextField *sentBitrateLabel;
@property (readwrite, assign) IBOutlet NSTextField *sentBitrateTextField;
@property (readwrite, assign) IBOutlet NSTextField *sentBytesLabel;
@property (readwrite, assign) IBOutlet NSTextField *sentBytesTextField;
@property (readwrite, assign) IBOutlet NSTextField *sentPacketsLabel;
@property (readwrite, assign) IBOutlet NSTextField *sentPacketsTextField;
@property (readwrite, assign) IBOutlet NSTextField *soutLabel;
@property (readwrite, assign) IBOutlet NSTextField *videoLabel;
@property (readwrite, assign) IBOutlet NSTextField *videoDecodedLabel;
@property (readwrite, assign) IBOutlet NSTextField *videoDecodedTextField;

- (void)updateCocoaWindowLevel:(NSInteger)i_level;
- (void)initPanel;

- (IBAction)metaFieldChanged:(id)sender;
- (IBAction)saveMetaData:(id)sender;
- (IBAction)downloadCoverArt:(id)sender;
- (void)initMediaPanelStats;
- (void)updatePanelWithItem:(input_item_t *)_p_item;
- (void)setMeta:(char *)meta forLabel:(id)theItem;
- (void)updateMetadata;
- (void)updateStatistics;

+ (VLCInfo *)sharedInstance;
@end

@interface VLCInfoTreeItem : NSObject {

    int _numberOfChildren;
    NSString* _name;
    NSString* _value;

    int i_object_id;
    input_item_t *p_item;
    VLCInfoTreeItem *_parent;
    NSMutableArray *_children;
    BOOL _isALeafNode;

}

@property (readonly) int numberOfChildren;
@property (readonly) NSString *name;
@property (readonly) NSString *value;

- (VLCInfoTreeItem *)childAtIndex:(NSUInteger)i_index;
- (void)refresh;

@end
