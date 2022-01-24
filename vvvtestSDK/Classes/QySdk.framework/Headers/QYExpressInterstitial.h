//
//  QYExpressInterstitial.h
//  QySdk
//
//  Created by liuyulei on 2021/10/14.
//  Copyright © 2021 iqiyi. All rights reserved.
//

#import <QySdk/QySdk.h>
#import "QYExpressBase.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface QYExpressInterstitial : QYExpressBase

/// 初始化--横屏插屏广告
/// @param rootController 当前控制器，保证正常跳转落地页
- (instancetype) initWithRootController:(UIViewController *)rootController;

/// 展示插屏广告
/// @param view 承载视图
- (void) presentInView:(UIView *)view;

// 广告消失
- (void) dismiss;

- (void)hidden;
- (void)show;


- (void) startVideo;
- (void) pauseVideo;

@end

NS_ASSUME_NONNULL_END
