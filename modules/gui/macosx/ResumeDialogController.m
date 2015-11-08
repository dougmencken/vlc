/*****************************************************************************
 * ResumeDialogController.m: MacOS X interface module
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


#import "ResumeDialogController.h"

#import "intf.h"
#import "StringUtility.h"

@implementation ResumeDialogController

- (id)init
{
    self = [super initWithWindowNibName:@"ResumeDialog"];

    return self;
}

- (void)windowDidLoad
{
    [o_title_lbl setStringValue:_NS("Continue playback?")];
    [o_resume_btn setTitle:_NS("Continue")];

    [o_always_resume_btn setTitle:_NS("Always continue")];
}

- (void)showWindowWithItem:(input_item_t *)p_item withLastPosition:(NSInteger)pos target:(id)aObj selector:(SEL)aSel
{
    NSWindow *w = [self window];

    if ([w isVisible]) {
        msg_Err(VLCIntf, "Resume dialog in use already");
        return;
    }

    currentResumeTimeout = 10;
    o_target = aObj;
    o_selector = aSel;

    NSString *o_restartButtonLabel = _NS("Restart playback");
    o_restartButtonLabel = [o_restartButtonLabel stringByAppendingFormat:@" (%d)", currentResumeTimeout];
    [o_restart_btn setTitle:o_restartButtonLabel];

    char *psz_title_name = input_item_GetTitleFbName(p_item);
    NSString *o_title = toNSStr(psz_title_name);
    free(psz_title_name);
    NSString *labelString = [NSString stringWithFormat:_NS("Playback of \"%@\" will continue at %@"), o_title, [[VLCStringUtility sharedInstance] stringForTime:pos]];
    [o_text_lbl setStringValue:labelString];

    NSTimer *timer = [NSTimer scheduledTimerWithTimeInterval:1
                                             target:self
                                           selector:@selector(updateAlertWindow:)
                                           userInfo:nil
                                            repeats:YES];

    [w setLevel:[[[VLCMain sharedInstance] voutController] currentStatusWindowLevel]];
    [w center];

    [w makeKeyAndOrderFront:nil];
}

- (void)doContinuePlayback
{
    if (m_resumeResult == RESUME_RESTART)
        return;

    ///mtime_t lastPos = (mtime_t)lastPosition.intValue * 1000000;
    ///msg_Dbg(VLCIntf, "continuing playback at %lld", lastPos);
    ///var_SetInteger(p_input_thread, "time", lastPos);

    if (m_resumeResult == RESUME_ALWAYS)
        config_PutInt(VLCIntf, "macosx-continue-playback", 1);
}

- (void)updateAlertWindow:(NSTimer *)timer
{
    --currentResumeTimeout;
    if (currentResumeTimeout <= 0) {
        [self buttonClicked:o_restart_btn];
        [timer invalidate];
        timer = nil;
    }

    NSString *buttonLabel = _NS("Restart playback");
    buttonLabel = [buttonLabel stringByAppendingFormat:@" (%d)", currentResumeTimeout];

    [o_restart_btn setTitle:buttonLabel];
}

- (IBAction)buttonClicked:(id)sender
{
    if (sender == o_restart_btn)
        m_resumeResult = RESUME_RESTART;
    else if (sender == o_resume_btn)
        m_resumeResult = RESUME_NOW;
    else
        m_resumeResult = RESUME_ALWAYS;

    [[self window] close];

    if (o_target && o_selector) {
        [o_target performSelector:o_selector];
        o_selector = nil; o_target = nil;
    }
}

- (void)setResumeResult:(int)result
{
    m_resumeResult = result;
}

- (void)updateCocoaWindowLevel:(NSInteger)i_level
{
    if ([self window] && [[self window] isVisible] && [[self window] level] != i_level)
        [[self window] setLevel: i_level];
}

@end
