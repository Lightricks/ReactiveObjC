//
//  UITextField+RACSignalSupport.m
//  ReactiveObjC
//
//  Created by Josh Abernathy on 4/17/12.
//  Copyright (c) 2012 GitHub, Inc. All rights reserved.
//

#import "UITextField+RACSignalSupport.h"
#import <ReactiveObjC/EXTKeyPathCoding.h>
#import <ReactiveObjC/EXTScope.h>
#import "NSObject+RACDeallocating.h"
#import "NSObject+RACDescription.h"
#import "RACSignal+Operations.h"
#import "UIControl+RACSignalSupport.h"
#import "UIControl+RACSignalSupportPrivate.h"

@implementation UITextField (RACSignalSupport)

- (RACSignal *)rac_textSignal {
  @rac_weakify(self);
  return [[[[[RACSignal
    defer:^{
      @rac_strongify(self);
      return [RACSignal return:self];
    }]
    concat:[self rac_signalForControlEvents:UIControlEventAllEditingEvents]]
    map:^(UITextField *x) {
      return x.text;
    }]
    takeUntil:self.rac_willDeallocSignal]
    setNameWithFormat:@"%@ -rac_textSignal", RACDescription(self)];
}

- (RACChannelTerminal *)rac_newTextChannel {
  return [self rac_channelForControlEvents:UIControlEventAllEditingEvents key:@rac_keypath(self.text) nilValue:@""];
}

@end
