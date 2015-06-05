//
//  ACLIPUser.h
//  AclipsaSDK
//
//  Copyright (c) 2013 Aclipsa Mobile Video Solutions, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>

/** An ACLIPUser encapulates the data of a user. Currently only holds the user's ID.
 
 */

@interface ACLIPUser : NSManagedObject {}

/** The user's ID */
@property (nonatomic, readonly) NSString *userID;

/** The statuses for the user */
@property (nonatomic, readonly) NSSet *statuses;

/** Returns the user object for the currently logged in user */
+ (ACLIPUser *)me;

/** Returns a user for the guid
 
 Returns the ACLIPUser objects for guid.
 
 @param userID An NSString of user guid.
 
 @return An ACLIPUser object
 */
+ (ACLIPUser*)userForID:(NSString*)userID;

/** Returns users for the guids
 
 Returns the ACLIPUser objects for guids.
 
 @param userIDs An NSArray of user guids.
 
 @return An NSArray of ACLIPUser objects
 */
+ (NSArray*)usersForIDs:(NSArray*)userIDs;

@end