#import <CoreData/CoreData.h>

@class ACLIPMessage;

/** An ACLIPMessageThread is a collection of messages between n number of users.  
 
 */

@interface ACLIPMessageThread : NSManagedObject {}

/** The threads ID */
@property (nonatomic, readonly) NSString *threadID;

/** The the ACLIPUsers that belong to the thread*/
@property (nonatomic, readonly) NSSet *users;

/** The messages that belong to the thread */
@property (nonatomic, readonly) NSSet *messages;

/** The last message that was sent that belongs to the thread */
@property (nonatomic, readonly) ACLIPMessage *lastMessage;

/** Returns the messages sorted in assending order by date  */
@property (nonatomic, readonly) NSArray *sortedMessages;

/** Returns a comma-separated string of all the user GUIDs in the message thread for display  */
- (NSString *)userListString;

@end