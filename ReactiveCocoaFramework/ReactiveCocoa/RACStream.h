//
//  RACStream.h
//  ReactiveCocoa
//
//  Created by Justin Spahr-Summers on 2012-10-31.
//  Copyright (c) 2012 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EXTConcreteProtocol.h"

// A concrete protocol representing any stream of values. Implemented by
// RACSubscribable and RACStream.
//
// This protocol represents a monad, upon which many stream-based operations can
// be built.
//
// When conforming to this protocol in a custom class, only `@required` methods
// need to be implemented. Default implementations will automatically be
// provided for any methods marked as `@concrete`. For more information, see
// EXTConcreteProtocol.h.
@protocol RACStream <NSObject>
@required

// Returns an empty stream.
+ (instancetype)empty;

// Lifts `value` into the stream monad.
//
// Returns a stream containing only the given value.
+ (instancetype)return:(id)value;

// Binds `block` to the values in the receiver.
//
// block - A block which accepts the values in the receiver and returns a new
//         instance of the receiver's class.
//
// Returns a new stream which represents the combined result of all applications
// of `block`.
- (instancetype)bind:(id (^)(id value))block;

@concrete

// Maps `block` across the values in the receiver.
//
// Returns a new stream with the mapped values.
- (instancetype)map:(id (^)(id value))block;

@end
