//
//  GCDQueue.h
//  GCD
//
//  Created by Sun on 2020/6/9.
//  Copyright © 2020 Qing Class. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class GCDGroup;

@interface GCDQueue : NSObject

/// 内部持有的 GCD 队列
@property (strong, readonly, nonatomic) dispatch_queue_t dispatchQueue;

/// 获取主队列
+ (GCDQueue *)mainQueue;

/// 获取全局并发队列
+ (GCDQueue *)globalQueue;

/// 获取全局并发队列(高优先级)
+ (GCDQueue *)highPriorityGlobalQueue;
/// 获取全局并发队列(低优先级)
+ (GCDQueue *)lowPriorityGlobalQueue;
/// 获取全局并发队列(后台优先级)
+ (GCDQueue *)backgroundPriorityGlobalQueue;

#pragma mark - 便利的构造方法

/// 在主队列 async 方式执行任务
/// @param block 任务
+ (void)executeInMainQueue:(dispatch_block_t)block;

/// 在全局并发队列 async 方式执行任务
/// @param block 任务
+ (void)executeInGlobalQueue:(dispatch_block_t)block;

/// 在全局并发队列(高优先级) async 方式执行任务
/// @param block 任务
+ (void)executeInHighPriorityGlobalQueue:(dispatch_block_t)block;

/// 在全局并发队列(低优先级) async 方式执行任务
/// @param block 任务
+ (void)executeInLowPriorityGlobalQueue:(dispatch_block_t)block;

/// 在全局并发队列(后台优先级) async 方式执行任务
/// @param block 任务
+ (void)executeInBackgroundPriorityGlobalQueue:(dispatch_block_t)block;

/// 在主队列 async 方式延时执行任务
/// @param block 任务
/// @param sec 延时时间(单位: 秒)
+ (void)executeInMainQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;

/// 在全局并发队列 async 方式延时执行任务
/// @param block 任务
/// @param sec 延时时间(单位: 秒)
+ (void)executeInGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;

/// 在全局并发队列(高优先级) async 方式延时执行任务
/// @param block 任务
/// @param sec 延时时间(单位: 秒)
+ (void)executeInHighPriorityGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;

/// 在全局并发队列(低优先级) async 方式延时执行任务
/// @param block 任务
/// @param sec 延时时间(单位: 秒)
+ (void)executeInLowPriorityGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;

/// 在全局并发队列(后台优先级) async 方式延时执行任务
/// @param block 任务
/// @param sec 延时时间(单位: 秒)
+ (void)executeInBackgroundPriorityGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;

#pragma 初始化

/// 构造一个串行队列(默认即为串行)
- (instancetype)init;

/// 构造一个串行队列
- (instancetype)initSerial;

/// 构造一个串行队列
/// @param label 队列标签
- (instancetype)initSerialWithLabel:(nullable NSString *)label;

/// 构造一个并发队列
- (instancetype)initConcurrent;

/// 构造一个并发队列
/// @param label 队列标签
- (instancetype)initConcurrentWithLabel:(nullable NSString *)label;

#pragma mark - 用法


/// async 执行任务
/// @param block 任务
- (void)execute:(dispatch_block_t)block;

/// async 执行任务
/// @param block 任务
/// @param delta 延时时间(单位: 纳秒)
- (void)execute:(dispatch_block_t)block afterDelay:(int64_t)delta;

/// async 执行任务
/// @param block 任务
/// @param delta 延时时间(单位: 秒)
- (void)execute:(dispatch_block_t)block afterDelaySecs:(float)delta;

/// sync 执行任务
/// @param block 任务
- (void)waitExecute:(dispatch_block_t)block;

/// async 栅栏任务
/// @param block 任务
- (void)barrierExecute:(dispatch_block_t)block;

/// sync 栅栏任务
/// @param block 任务
- (void)waitBarrierExecute:(dispatch_block_t)block;

/// 队列挂起
- (void)suspend;

/// 队列恢复
- (void)resume;

#pragma mark - 与GCDGroup相关

/// 调度组内 async 执行任务
/// @param block 任务 block
/// @param group 调度组
- (void)execute:(dispatch_block_t)block inGroup:(GCDGroup *)group;

/// 获取调度组内任务的通知
/// @param block 通知 block
/// @param group 调度组
- (void)notify:(dispatch_block_t)block inGroup:(GCDGroup *)group;

@end

NS_ASSUME_NONNULL_END
