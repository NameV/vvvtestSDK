//
//  QYExpressReward.h
//  QySdk
//
//  Created by Peiran Zhang on 2021/1/8.
//  Copyright © 2021 iqiyi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYExpressBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface QYExpressReward : QYExpressBase

@property (nonatomic, assign) NSInteger impressionTimesWithoutEnd; //没看完情况下的再次曝光，在点击挽留弹窗再看一个时会触发

- (instancetype) initWithSlotId:(NSString *)slotId;
- (void) presentFromController:(UIViewController *)controller;
//设置静音，默认有声播放
- (void) setMute:(BOOL)mute;

// pravite fucntion
- (void)rewardCallbackSubPageSuccess:(QY_PULLING_PAGETYPE)type;
- (void)rewardCallbackSubPageClosed:(QY_PULLING_PAGETYPE)type;

// 传递剩余请求次数
- (void)loadData:(NSInteger)remainTimes;
@end

NS_ASSUME_NONNULL_END
