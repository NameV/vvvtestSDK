//
//  QYExpressBase.h
//  Cupid_DEMO
//
//  Created by Peiran Zhang on 2020/5/15.
//  Copyright © 2020 iqiyi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QYAssociateVideoInfo.h"

NS_ASSUME_NONNULL_BEGIN

@class QYWrapperHolder;
@class QYCupidWrapper;
@class QYCupidSlot;
@class QYCupid;
@class QYNetProtocol;

typedef NS_ENUM(NSInteger, QY_JUMP_STYLE) {
    QY_JUMP_STYLE_NORMAL        = 0, // 普通跳转
    QY_JUMP_STYLE_SECOND_PAGE   = 1  // 跳转二级页
};

typedef NS_ENUM(NSInteger, QY_PULLING_PAGETYPE) { //三方拉起类型
    QY_PULLING_TYPE_NONE          = 0, // 落地页类型未知
    QY_PULLING_TYPE_WEBVIEW       = 1, // WEBVIEW
    QY_PULLING_TYPE_STORE         = 2, // app store
    QY_PULLING_TYPE_DPLINK        = 3, // 第三方应用
    QY_PULLING_TYPE_SAFARI        = 4 // 第三方应用
};

@class QYExpressBase;

@protocol QYExpressDelegate <NSObject>
@optional
- (void) onExpressLoadFailed;
- (void) onExpressLoadSuccess:(QYExpressBase *)express;
- (void) onExpressShow;
- (void) onExpressPlayStart;
- (void) onExpressPlayEnd;
- (void) onExpressPlayError;
- (void) onExpressClosed;
- (void) onExpressClicked:(id __nullable)obj;
//子页面关闭回调：仅支持QY_PULLING_TYPE_WEBVIEW和QY_PULLING_TYPE_STORE两种类型
- (void) onExpressSubPageClosed:(QY_PULLING_PAGETYPE)type;
- (void) onExpressSubPageOpen:(QY_PULLING_PAGETYPE)type;
- (void) onExpressInteraction;
- (void) onExpressReward:(NSDictionary *)extraInfo;
@end

@interface QYExpressBase : NSObject
@property(nonatomic, weak) UIViewController *rootController;
@property(nonatomic, copy) NSString *bundleId;      //identifier of unique ad obj
@property(nonatomic, copy) NSString *slotId;        //ali slot id
@property(nonatomic, copy) NSString *wrapperId;     //identifier of unique resp, as m-key
@property(nonatomic, copy) NSString *videoId;       //video id defined by media
@property(nonatomic, copy) NSString *videoEventId;  //video event id defined by i
@property(nonatomic, copy) NSString *sessionId;

@property(nonatomic, assign) NSInteger iSlotType;    //ali slot type
@property(nonatomic, assign) NSInteger requestCount; //how many ads to req
@property(nonatomic, assign) NSInteger reqDuration;  //time req spend
@property(nonatomic, assign) NSInteger reqTimeOut;  //how long to req
@property(nonatomic, assign) NSInteger retryTimes;  //how many times to req
@property(nonatomic, assign) BOOL isAdReady;
@property(nonatomic, strong) NSDictionary *extraInfo;
@property(nonatomic, strong) QYAssociateVideoInfo *videoInfo;

@property(nonatomic, strong) NSMutableSet *realRidRecord;
@property(nonatomic, weak) id<QYExpressDelegate> delegate;

- (void) loadData;
- (void) loadDataRealTime:(BOOL)realtime;
- (void) dealWithClickEvent:(QYCupid *)ad prop:(NSDictionary *)prop jumpStyle:(QY_JUMP_STYLE)jStyle extend:(NSDictionary * __nullable)ext;
- (void) handleEmptyTracking:(QYCupidSlot *)slot;
- (void) cacheStoreController:(QYCupid *)cupid;
- (nullable QYCupidWrapper *)processMixerResponse:(nonnull NSString *)url andRid:(nonnull NSString *)rid resp:(nonnull NSData *)response;
- (void) schemePull:(NSString *)scheme callback:(nullable void(^)(BOOL result))callback;
#pragma mark 回调
- (void) callbackReady;
- (void) callbackFailed;
- (void) callbackError;
- (void) callbackEnd;
- (void) callbackClosed;
- (void) callbackClicked:(id __nullable)obj;
- (void) callbackShow;

- (void) callbackSubPageSuccess:(QY_PULLING_PAGETYPE)type; //应用内页面拉起成功
- (void) callbackSubPageFailed;
- (void) callbackSubPageClosed:(QY_PULLING_PAGETYPE)type;
- (void) callbackReward:(NSDictionary *)extraInfo;
- (void) callbackInteraction;

#pragma mark QYCupidBuilderDelegate
- (void) onCupidSuccess:(NSString *)wrapperId;
- (void) onCupidFailed;

#pragma mark fore&back ground
- (void) doEnterForeground;
- (void) doEnterBackground;
@end

NS_ASSUME_NONNULL_END
