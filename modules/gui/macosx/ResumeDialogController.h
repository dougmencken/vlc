/*****************************************************************************
 * ResumeDialogController.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2015 VLC authors and VideoLAN
 *
 * Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
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

#import <Cocoa/Cocoa.h>

#import <vlc_common.h>
#import <vlc_input.h>

enum ResumeResult {
    RESUME_RESTART,
    RESUME_ALWAYS,
    RESUME_NOW
};

@interface ResumeDialogController : NSWindowController
{
    IBOutlet id o_title_lbl;
    IBOutlet id o_text_lbl;

    IBOutlet id o_restart_btn;
    IBOutlet id o_resume_btn;
    IBOutlet id o_always_resume_btn;

    int currentResumeTimeout;

    enum ResumeResult m_resumeResult;

    id o_target;
    SEL o_selector;
}

- (IBAction)buttonClicked:(id)sender;

- (void)showWindowWithItem:(input_item_t *)p_item withLastPosition:(NSInteger)pos target:(id)aObj selector:(SEL)aSel;

- (void)setResumeResult:(int)result;

- (void)updateCocoaWindowLevel:(NSInteger)i_level;

@end
