//
//  PXSourceList.h
//  PXSourceList
//
//  Created by Alex Rozanski on 05/09/2009.
//  Copyright 2009-10 Alex Rozanski http://perspx.com
//

#import <Cocoa/Cocoa.h>

#import "CompatibilityFixes.h"

#import "PXSourceListDelegate.h"
#import "PXSourceListDataSource.h"

@interface PXSourceList: NSOutlineView <NSOutlineViewDelegate, NSOutlineViewDataSource>
{
    id <PXSourceListDelegate> _secondaryDelegate; //Used to store the publicly visible delegate
    id <PXSourceListDataSource> _secondaryDataSource; //Used to store the publicly visible data source

    // properties
    NSSize _iconSize;
}

@property (nonatomic) NSSize iconSize;

@property (assign) id<PXSourceListDataSource> dataSource;
@property (assign) id<PXSourceListDelegate> delegate;

- (NSUInteger)numberOfGroups; //Returns the number of groups in the Source List
- (BOOL)isGroupItem:(id)item; //Returns whether `item` is a group
- (BOOL)isGroupAlwaysExpanded:(id)group; //Returns whether `group` is displayed as always expanded

- (BOOL)itemHasBadge:(id)item; //Returns whether `item` has a badge
- (NSInteger)badgeValueForItem:(id)item; //Returns the badge value for `item`

- (NSSize)sizeOfBadgeAtRow:(NSInteger)rowIndex;
- (void)drawBadgeForRow:(NSInteger)rowIndex inRect:(NSRect)badgeFrame;
- (void)registerDelegateToReceiveNotification:(NSString*)notification withSelector:(SEL)selector;

@end

