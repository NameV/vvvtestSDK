//
//  QySdk.h
//  Cupid
//
//  Created by Peiran Zhang on 2020/3/17.
//  Copyright © 2020 iqiyi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QySdk/QYBannerView.h>
#import <QySdk/QYExpressRoll.h>
#import <QySdk/QYExpressBanner.h>
#import <QySdk/QYExpressReward.h>
#import <QySdk/QYExpressSplash.h>
#import <QySdk/QYExpressInterstitial.h>
#import <QySdk/QYNativeBanner.h>
#import <QySdk/QYCupidNative.h>
#import <QySdk/QYIADUserInfo.h>

#define QY_LOG_NONE      0
#define QY_LOG_ERROR     1
#define QY_LOG_DEBUG     2

extern NSString *EXTRA_KEY_COVER_URL;
extern NSString *STATUS_KEY_DEVICE_PRINT;
extern NSString *STATUS_KEY_MOBILE_KEY;
extern NSString *STATUS_KEY_IQID;
extern NSString *STATUS_KEY_SSID;

//property相关key
extern NSString *PROP_KEY_REWARD_COUNT; //激励金额
extern NSString *PROP_KEY_CLICK_AREA; //点击区域
extern NSString *PROP_KEY_TVID;
extern NSString *PROP_KEY_ALBUMID;
extern NSString *PROP_KEY_IMPRESSION_ID;

//广告级别相关Key
extern NSString *INFO_KEY_BOOK_ID;

@interface IAdSdk : NSObject

+ (void) setAppId:(NSString *)appId;
+ (void) setDebugLevel:(NSInteger)lvl;
+ (void) setLogPath:(NSString *)path;
+ (void) setGender:(NSString *)gender;
+ (void) setAge:(NSInteger)age;
+ (void) setAppMode:(NSInteger )appMode;
+ (void) setKeyWords:(NSArray *)words;
+ (void) setExtInfo:(NSDictionary *)info;
+ (void) setSplashForeRequest:(BOOL)b;
+ (void) setTestMode:(BOOL)test;
+ (void) start;
+ (void) setChannelId:(NSString *)channelId;
+ (void) clearCache;
+ (void) setAppOrientation:(UIInterfaceOrientation)orientation;
+ (void) setUaaUserId:(NSString *)uaaUserId;
+ (void) initService;
+ (void) setSdkStatus:(NSDictionary *)status;
+ (void) setAudioMix:(BOOL)mix;
+ (void) setItunesAppleId:(NSString *)appleId;
+ (void) requestLocationService;
+ (NSString *) sdkVersion;
+ (NSArray *) getAdLogFilePaths;
+ (void) setUserInfo:(QYIADUserInfo *)usrInfo;

@end

