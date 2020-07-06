//
//  GCDGroup.h
//  GCD
//
//  Created by Sun on 2020/6/9.
//  Copyright © 2020 Qing Class. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GCDGroup : NSObject

/// 内部持有的 GCD 调度组
@property (strong, nonatomic, readonly) dispatch_group_t dispatchGroup;

#pragma 初始化
- (instancetype)init;

#pragma mark - 用法

/// 进组
- (void)enter;

/// 离组
- (void)leave;

/// 等待
- (void)wait;

/// 等待指定时间, 返回 YES 意味着等待成功，否则 NO
/// @param delta 等待时间(单位: 纳秒)
- (BOOL)wait:(int64_t)delta;

@end

NS_ASSUME_NONNULL_END
