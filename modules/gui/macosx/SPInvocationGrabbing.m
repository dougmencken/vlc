/*
 Copyright (c) 2011, Joachim Bengtsson
 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

 * Neither the name of the organization nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "SPInvocationGrabbing.h"
#import <execinfo.h>

#pragma mark Invocation grabbing

@implementation SPInvocationGrabber

@synthesize object = _object;
@synthesize invocation = _invocation;
@synthesize backgroundAfterForward = _backgroundAfterForward;
@synthesize onMainAfterForward = _onMainAfterForward;
@synthesize waitUntilDone = _waitUntilDone;

- (id)initWithObject:(id)obj;
{
    return [self initWithObject:obj stacktraceSaving:YES];
}

-(id)initWithObject:(id)obj stacktraceSaving:(BOOL)saveStack;
{
    _object = obj;
    if(saveStack)
        [self saveBacktrace];

    return self;
}

-(void)dealloc;
{
    free(frameStrings);
    _object = nil;
    _invocation = nil;
    [super dealloc];
}

- (void)runInBackground;
{
    [self invoke];
}


- (void)forwardInvocation:(NSInvocation *)anInvocation {
    [anInvocation retainArguments];
    [anInvocation setTarget:_object];
    _invocation = anInvocation;

    if(_backgroundAfterForward)
        [NSThread detachNewThreadSelector:@selector(runInBackground) toTarget:self withObject:nil];
    else if(_onMainAfterForward)
        [self performSelectorOnMainThread:@selector(invoke) withObject:nil waitUntilDone:_waitUntilDone];
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)inSelector {
    NSMethodSignature *signature = [super methodSignatureForSelector:inSelector];
    if (signature == NULL)
        signature = [_object methodSignatureForSelector:inSelector];

    return signature;
}

- (void)invoke;
{
    @try {
        [_invocation invoke];
    }
    @catch (NSException * e) {
        NSLog(@"SPInvocationGrabber's target raised %@:\n\t%@\nInvocation was originally scheduled at:", e.name, e);
        [self printBacktrace];
        printf("\n");
        [e raise];
    }

    _invocation = nil;
    _object = nil;
}

-(void)saveBacktrace;
{
    void *backtraceFrames[128];
    frameCount = backtrace(&backtraceFrames[0], 128);
    frameStrings = backtrace_symbols(&backtraceFrames[0], frameCount);
}

-(void)printBacktrace;
{
    for(int x = 3; x < frameCount; x++) {
        if(frameStrings[x] == NULL) { break; }
        printf("%s\n", frameStrings[x]);
    }
}
@end

@implementation NSObject (SPInvocationGrabbing)
-(id)grab;
{
    return [[SPInvocationGrabber alloc] initWithObject:self];
}

-(id)invokeAfter:(NSTimeInterval)delta;
{
    id grabber = [self grab];
    [NSTimer scheduledTimerWithTimeInterval:delta target:grabber selector:@selector(invoke) userInfo:nil repeats:NO];
    return grabber;
}

- (id)nextRunloop;
{
    return [self invokeAfter:0];
}

-(id)inBackground;
{
    SPInvocationGrabber *grabber = [self grab];
    grabber.backgroundAfterForward = YES;
    return grabber;
}

-(id)onMainAsync:(BOOL)async;
{
    SPInvocationGrabber *grabber = [self grab];
    grabber.onMainAfterForward = YES;
    grabber.waitUntilDone = !async;
    return grabber;
}

@end
