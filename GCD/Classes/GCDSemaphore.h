//
//  GCDSemaphore.h
//  GCD
//
//  Created by Sun on 2020/6/9.
//  Copyright © 2020 Qing Class. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GCDSemaphore : NSObject

/// 内部持有的 GCD 信号量
@property (strong, readonly, nonatomic) dispatch_semaphore_t dispatchSemaphore;

#pragma 初始化

/// 构造方法, 默认 value = 0.
- (instancetype)init;

/// 通过 value 构造一个 GCDSemaphore
/// @param value 信号量的值
- (instancetype)initWithValue:(long)value;

#pragma mark - 用法

/// 信号量 +1
- (BOOL)signal;

/// 信号量 -1
- (void)wait;

/// 信号量 -1, 若 -1 成功返回 YES, 否则 NO
/// @param delta 等待时间(单位: 纳秒)
- (BOOL)wait:(int64_t)delta;

@end

NS_ASSUME_NONNULL_END
