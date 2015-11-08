/*****************************************************************************
 * prefs_widgets.h: Preferences controls
 *****************************************************************************
 * Copyright (C) 2002-2012 VLC authors and VideoLAN
 * $Id$
 *
 * Authors: Derk-Jan Hartman <hartman at videolan.org>
 *          Felix Paul Kühne <fkuehne at videolan.org>
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

static NSMenu *o_keys_menu = nil;

@interface VLCConfigControl : NSView {

    module_config_t * _p_item;
    NSTextField * _label;
    NSString * _name;
    int _type;
    int _viewType;
    bool _advanced;
    int _intValue;
    float _floatValue;
    char * _stringValue;
    int _labelSize;

    const char *psz_name;

}

@property (readonly) module_config_t *p_item;

@property (readwrite, assign) NSTextField *label;

@property (readonly) NSString *name;
@property (readonly) int type;
@property (readwrite) int viewType;
@property (readonly) bool advanced;
@property (readonly) int intValue;
@property (readonly) float floatValue;
@property (readonly) char *stringValue;
@property (readonly) int labelSize;


+ (VLCConfigControl *)newControl:(module_config_t *)_p_item
                        withView:(NSView *)o_parent_view;
+ (int)calcVerticalMargin:(int)i_curItem lastItem:(int)i_lastItem;

- (id)initWithFrame:(NSRect)frame
               item:(module_config_t *)p_item;

- (void)setYPos:(int)i_yPos;
- (void)alignWithXPosition:(int)i_xPos;

- (void)applyChanges;
- (void)resetValues;

@end

@interface StringConfigControl : VLCConfigControl {
    NSTextField     *o_textfield;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface StringListConfigControl : VLCConfigControl {
    NSPopUpButton      *o_popup;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface FileConfigControl : VLCConfigControl {
    NSTextField     *o_textfield;
    NSButton        *o_button;
    BOOL            b_directory;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

- (IBAction)openFileDialog:(id)sender;

@end

@interface ModuleConfigControl : VLCConfigControl {
    NSPopUpButton   *o_popup;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface IntegerConfigControl : VLCConfigControl <NSTextFieldDelegate> {
    NSTextField     *o_textfield;
    NSStepper       *o_stepper;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

- (IBAction)stepperChanged:(id)sender;

@end

@interface IntegerListConfigControl : VLCConfigControl {
    NSPopUpButton      *o_popup;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface RangedIntegerConfigControl : VLCConfigControl <NSTextFieldDelegate> {
    NSSlider        *o_slider;
    NSTextField     *o_textfield;
    NSTextField     *o_textfield_min;
    NSTextField     *o_textfield_max;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

- (IBAction)sliderChanged:(id)sender;

@end

@interface BoolConfigControl : VLCConfigControl {
    NSButton        *o_checkbox;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface FloatConfigControl : VLCConfigControl <NSTextFieldDelegate> {
    NSTextField     *o_textfield;
    NSStepper       *o_stepper;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

- (IBAction)stepperChanged:(id)sender;

@end

@interface RangedFloatConfigControl : VLCConfigControl <NSTextFieldDelegate> {
    NSSlider        *o_slider;
    NSTextField     *o_textfield;
    NSTextField     *o_textfield_min;
    NSTextField     *o_textfield_max;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

- (IBAction)sliderChanged:(id)sender;

@end

@interface KeyConfigControl : VLCConfigControl {
    NSPopUpButton   *o_popup;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface ModuleListConfigControl : VLCConfigControl <NSTextFieldDelegate, NSTableViewDataSource> {
    NSTextField     *o_textfield;
    NSTableView     *o_tableview;
    NSMutableArray  *o_modulearray;
}

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end

@interface SectionControl : VLCConfigControl

- (id)initWithItem:(module_config_t *)_p_item
          withView:(NSView *)o_parent_view;

@end
