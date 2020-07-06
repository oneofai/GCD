//
//  GCDTimer.h
//  GCD
//
//  Created by Sun on 2020/6/9.
//  Copyright © 2020 Qing Class. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class GCDQueue;

@interface GCDTimer : NSObject

/// 内部维护的 GCD 定时器
@property (strong, readonly, nonatomic) dispatch_source_t dispatchSource;

#pragma 初始化

/// 构造方法，默认在全局并发队列
- (instancetype)init;


/// 在指定队列上构造定时器
/// @param queue 指定队列
- (instancetype)initInQueue:(GCDQueue *)queue;

#pragma mark - 用法

/// 定时执行任务
/// @param block 任务
/// @param interval 间隔(单位：纳秒)
- (void)event:(dispatch_block_t)block timeInterval:(uint64_t)interval;

/// 定时执行任务
/// @param block 任务
/// @param cancelEvent 定时取消后的回调
/// @param interval 间隔(单位：纳秒)
- (void)event:(dispatch_block_t)block cancelEvent:(nullable dispatch_block_t)cancelEvent timeInterval:(uint64_t)interval;

/// 定时执行任务
/// @param block 任务
/// @param interval 间隔(单位：纳秒)
/// @param delay 延迟(单位：纳秒)
- (void)event:(dispatch_block_t)block timeInterval:(uint64_t)interval delay:(uint64_t)delay;

/// 定时执行任务
/// @param block 任务
/// @param cancelEvent 定时取消后的回调
/// @param interval 间隔(单位：纳秒)
/// @param delay 延迟(单位：纳秒)
- (void)event:(dispatch_block_t)block cancelEvent:(nullable dispatch_block_t)cancelEvent timeInterval:(uint64_t)interval delay:(uint64_t)delay;

/// 定时执行任务
/// @param block 任务
/// @param secs 间隔(单位：秒)
- (void)event:(dispatch_block_t)block timeIntervalWithSecs:(float)secs;

/// 定时执行任务
/// @param block 任务
/// @param cancelEvent 定时取消后的回调
/// @param secs 间隔(单位：秒)
- (void)event:(dispatch_block_t)block cancelEvent:(nullable dispatch_block_t)cancelEvent timeIntervalWithSecs:(float)secs;

/// 定时执行任务
/// @param block 任务
/// @param secs 间隔(单位：秒)
/// @param delaySecs 延迟(单位：秒)
- (void)event:(dispatch_block_t)block timeIntervalWithSecs:(float)secs delaySecs:(float)delaySecs;

/// 定时执行任务
/// @param block 任务
/// @param cancelEvent 定时取消后的回调
/// @param secs 间隔(单位：秒)
/// @param delaySecs 延迟(单位：秒)
- (void)event:(dispatch_block_t)block cancelEvent:(nullable dispatch_block_t)cancelEvent timeIntervalWithSecs:(float)secs delaySecs:(float)delaySecs;

/// 倒计时执行任务
/// @param block 任务
/// @param completionEvent 计时完成的回调
/// @param cancelEvent 取消后的回调
/// @param secs 间隔(单位：秒)
/// @param totalSecs 总时长(单位：秒)
- (void)countDownEvent:(void(^)(float leftTime))block
       completionEvent:(nullable dispatch_block_t)completionEvent
           cancelEvent:(nullable dispatch_block_t)cancelEvent
  timeIntervalWithSecs:(float)secs
             totalSecs:(float)totalSecs;

/// 开启定时
- (void)start;

/// 关闭定时(摧毁)
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
