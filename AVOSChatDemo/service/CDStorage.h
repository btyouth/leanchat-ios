//
//  CDStorage.h
//  LeanChat
//
//  Created by lzw on 15/1/29.
//  Copyright (c) 2015年 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDCommon.h"
#import "FMDB.h"
#import "CDModels.h"

@interface CDStorage : NSObject

+(instancetype)sharedInstance;

-(void)close;

-(void)setupWithUserId:(NSString*)userId;

-(NSArray*)getMsgsWithConvid:(NSString*)convid maxTime:(int64_t)time limit:(int)limit db:(FMDatabase*)db;

-(int64_t)insertMsg:(AVIMTypedMessage*)msg;

-(BOOL)updateStatus:(AVIMMessageStatus)status byMsgId:(NSString*)msgId;

-(BOOL)updateFailedMsg:(AVIMTypedMessage*)msg byLocalId:(int)localId;

-(void)deleteMsgsByConvid:(NSString*)convid;

-(FMDatabaseQueue*)getDBQueue;

-(NSArray*)getRooms;

-(void)insertRoomWithConvid:(NSString*)convid;

-(void)deleteRoomByConvid:(NSString*)convid;

-(void)incrementUnreadWithConvid:(NSString*)convid;

-(void)clearUnreadWithConvid:(NSString*)convid;


@end
