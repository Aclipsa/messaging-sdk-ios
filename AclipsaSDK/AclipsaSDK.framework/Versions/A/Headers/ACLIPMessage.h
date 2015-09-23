//
//  ACLIPMessage.h
//  AclipsaSDK
//
//  Copyright (c) 2013 Aclipsa Mobile Video Solutions, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>
#import "ACLIPConstants.h"

/** An ACLIPMessage encapulates the data of a message.
 
 */

@class ACLIPVideo, ACLIPUser, ACLIPMessageThread;

@interface ACLIPMessage : NSManagedObject {}

/** Unique identifier for the message */
@property (nonatomic, readonly) NSString *guid;

/** The title of the message */
@property (nonatomic, readonly) NSString *title;

/** The descriptive text associated with this message */
@property (nonatomic, readonly) NSString *messageText;

/** The user who sent the message */
@property (nonatomic, readonly) ACLIPUser *sender;

/** The recipients of the message */
@property (nonatomic, readonly) NSSet *recipients;

/** The statuses for the message */
@property (nonatomic, readonly) NSSet *statuses;

/** The message's video */
@property (nonatomic, readonly) ACLIPVideo *video;

/** The date the video was sent */
@property (nonatomic, readonly) NSDate *createdDate;

/** The message thread that the message belongs to */
@property (nonatomic, readonly) ACLIPMessageThread *messageThread;

/** Has the message been read by the current user. */
@property (nonatomic, readonly, getter=isRead) BOOL read;

/** Has the message been yanked by the sender. */
@property (nonatomic, readonly, getter=isYanked) BOOL yanked;

/** Returns a message for the guid
 
 Returns the ACLIPMessage objects for guid.
 
 @param guid An NSString of message guid.
 
 @return An ACLIPMessage object
 */
+ (ACLIPMessage*)messageForGUID:(NSString*)guid;

/** Returns messages for the guids
 
 Returns the ACLIPMessage objects for guids.
 
 @param guids An NSArray of message guids.
 
 @return An NSArray of ACLIPMessage objects
 */
+ (NSArray*)messagesForGUIDs:(NSArray*)guids;

/** Deletes the message.
 
 The call deletes the message from the user's message list.
 
 @param completedBlock A block that gets called upon successfully loading the messages list. The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)deleteMessageCompleteBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Marks the message as being read by the user.
 
 @param completedBlock A block that gets called upon successfully marking the message read.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)markMessageReadCompleteBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Marks the message as unread by the user.
 
 @param completedBlock A block that gets called upon successfully marking the message unread.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)markMessageUnreadCompleteBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Removes the message from being able to be seen by the recipients.
 
 Yanking causes the message to no longer be viewable by the users in the recipients list. It does not delete the message or cause it to not be viewable by people who originally recieved it but are not in the recipients list. Messages can only be yanked by the sender.
 
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param completedBlock A block that gets called upon successfully loading the messages list. The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)yankMessageForRecipients:(NSArray*)recipients completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Allows the message to be seen by the recipients again.
 
 Unyanking causes the message to be viewable again by the users in the recipients list. It will not allow a user in the recipients list to be able to view the message if the user was not a recipient when the message was originally sent. Messages can only be unyanked by the sender.
 
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param completedBlock A block that gets called upon successfully loading the messages list. The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)unyankMessageForRecipients:(NSArray*)recipients completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

@end