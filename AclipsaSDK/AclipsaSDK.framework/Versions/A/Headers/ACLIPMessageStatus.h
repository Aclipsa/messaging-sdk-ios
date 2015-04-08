#import <CoreData/CoreData.h>

/** An ACLIPMessageStatus encapulates metadata for an ACLIPMessage.
 
 */

@interface ACLIPMessageStatus : NSManagedObject {}

/** BOOL indicating that the user in this message status has seen the message */
@property (nonatomic, readonly) BOOL messageRead;

/** NSDate of when the user in this message status took a screenshot. nil if no screenshot taken */
@property (nonatomic, readonly) NSDate *screenshotDate;

/** Finds the message status.
 
 Finds the message status (if it exists) for a user and a message.
 
 @param userGuid The user guid who messageStatus belongs to.
 @param messageGuid The message GUID of the message that the messageStatus belongs to.
 */
+ (ACLIPMessageStatus*)statusForUser:(NSString*)userGuid messageGuid:(NSString *)messageGuid;

/** Mark the messageStatus as read.
 
 Mark the message status for a given user guid and message guid.
 
 @param messageGuid The message GUID of the message that the messageStatus belongs to.
 @param userGuid The user GUID of the user that the messageStatus belongs to.
 */
+ (void)markMessageRead:(NSString *)messageGuid forUser:(NSString *)userGuid;

@end