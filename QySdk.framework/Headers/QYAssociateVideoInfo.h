//
//  QYAssociateVideoInfo.h
//  QySdk
//
//  Created by liuyulei on 2021/12/1.
//  Copyright © 2021 iqiyi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QYAssociateVideoInfo : NSObject

@property(nonatomic, copy) NSString *tvId;          //垂线业务传递奇谱ID（episode id），外部媒体传递自定义剧集ID
@property(nonatomic, copy) NSString *albumId;

- (instancetype) initWithTvid:(NSString *)tvId albumId:(NSString *)albumId;

@end

NS_ASSUME_NONNULL_END
