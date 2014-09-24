//
//  PCDatabaseCore.h
//  PCDatabaseCore
//
//  Created by Paweł Nużka on 02/09/14.
//  Copyright (c) 2014 Pilot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

typedef void (^ErrorHandleBlock)(NSError *error);

/*!
 *  Singleton class to manage CoreData database
 *  It eases use of concurrency and is thread-safe.
 */
extern const int kFetchBatchSize;
extern const int kSaveBatchSize;


@interface PCDatabaseCore : NSObject
@property (nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, strong, readonly) NSManagedObjectContext *mainObjectContext;
@property (nonatomic, readonly) NSManagedObjectContext *writerObjectContext;
@property (nonatomic, readonly) NSManagedObjectContext *backgroundObjectContext;

@property (nonatomic, strong) NSPersistentStoreCoordinator *persistentStoreCoordinator;

//*********************************************************************************************************
#pragma mark - Initialization

+ (instancetype)initWithName:(NSString *)databaseName;
+ (instancetype)sharedInstance;

#pragma mark - Getters & Setters
- (NSString *)databasePath;
- (NSString *)applicationDocumentsDirectory;
- (NSError *)saveDatabase;
- (NSArray *)objectsFromBackgroundThread:(NSArray *)objects;
- (id)objectFromBackgroundThread:(NSManagedObject *)object;
//*********************************************************************************************************
- (NSString *)databaseName;





@end
