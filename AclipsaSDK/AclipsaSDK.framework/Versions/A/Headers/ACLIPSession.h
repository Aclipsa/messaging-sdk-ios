//
//  ACLIPSession.h
//  AclipsaSDK
//
//  Copyright (c) 2013 Aclipsa Mobile Video Solutions, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "ACLIPConstants.h"

typedef NS_ENUM(NSInteger, ACLIPServerEnvironment)
{
	ACLIPDevelopmentServer = 0,
	ACLIPProductionServer = 1,
	ACLIPStagingServer = 2,
	ACLIPADHocServer = 3,
	ACLIPADHocDevelopmentServer = 4,
};

@class ACLIPVideo, ACLIPMessage;

/** An ACLIPSession encapsulates the communication session between the client application and the Aclipsa server.  A session MUST be created before any other calls to the AclipsaSDK can occur. An ACLIPInvalidSessionExecption will be thrown if a session has not been created. */

@interface ACLIPSession : NSObject

/** The appID of the active session */
@property(nonatomic, readonly) NSString *appID;

/** The userID currently logged into the active session */
@property(nonatomic, readonly) NSString *userID;

/** The flag indicating which server should be used.  Defaults to ACLIPDevelopmentServer */
@property(nonatomic, readonly) ACLIPServerEnvironment serverEnvironment;

/** An appication may get or set the current active session.

 Only one ACLIPSession can be created.  Calling createSessionWithAppID: more than once will result in the same object being returned that is initialized to the appID used in the first call to it.

 @param appID The id string for the app provided by the AclipsaSDK admin site.
 @param serverType An ACLIPServerEnvironment value for which server environment should be used.
 @return An active ACLIPSession for the appID.
 */
+ (ACLIPSession *)createSessionWithAppID:(NSString *)appID serverEnvironment:(ACLIPServerEnvironment)serverType;


/** An appication may get or set the current active session.
 
 Only one ACLIPSession can be created.  Calling createSessionWithAppID: more than once will result in the same object being returned that is initialized to the appID used in the first call to it.
 
 @param appID The id string for the app provided by the AclipsaSDK admin site.
 @param serverType An ACLIPServerEnvironment value for which server environment should be used.
 @param hostName The host name that will be used for all server API communication.
 @return An active ACLIPSession for the appID.
 */
+ (ACLIPSession *)createSessionWithAppID:(NSString *)appID serverEnvironment:(ACLIPServerEnvironment)serverType hostName:(NSString *)hostName;

/** An appication may get or set the current active session.

 @warning *Important:* An ACLIPInvalidSessionExecption will be thrown if a session has not been created first.
 */

+ (ACLIPSession *)activeSession;

/** Logs the user with userID in as the user for the session

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating.

 @param userID The id string for the user to be logged in.
 @param completedBlock A block that gets called upon successfully logging in.  completedBlock can be nil if no post login action is required.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)loginWithUserID:(NSString *)userID completionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Logs the user out for the session

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. Any method that requires a user to be logged in will fail after completion until loginWithUserID:completionBlock:errorBlock: is called again.

 @param completedBlock A block that gets called upon successfully logging out.  completedBlock can be nil if no post login action is required.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)logoutWithCompletionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Deletes the user associated with the session

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. Any method that requires a user to be logged in will fail after completion until deleteUserWithUserID:completionBlock:errorBlock: is called again.

 @param userID The id string for the user to be deleted.
 @param completedBlock A block that gets called upon successfully deleting the user.  completedBlock can be nil if no post deletion action is required.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)deleteUserWithID:(NSString *)userID completionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Uploads the video file at videoURL.

 The complete block gets called once the video has been successfully transmitted to the Aclipsa Servers and the ACLIPVideo object is put into the ACLIPVideoProcessingState state.  *Note:* The video is not available for playback until the state changes to ACLIPVideoCompletedState from ACLIPVideoProcessingState.

 The upload call happens asyncronously.  The caller should expect the complete and error blocks to happen at an indeterminate time in the future to properly handle the error and only post successful action that it need to perform.

 @param videoURL A URL that points to the video to be uploaded. Can not be nil.
 @param title A title for the video.
 @param attributes The attributes of the video. All values must be of types suppored by NSJSONSerialization.
 @param completedBlock A block that gets called upon successfully uploading the video.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new video object that represents the video being uploaded.
 */
- (ACLIPVideo *)uploadVideoAtURL:(NSURL *)videoURL title:(NSString *)title attributes:(NSDictionary *)attributes completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Uploads the video file at videoURL.

 The complete block gets called once the video has been successfully transmitted to the Aclipsa Servers and the ACLIPVideo object is put into the ACLIPVideoProcessingState state.  *Note:* The video is not available for playback until the state changes to ACLIPVideoCompletedState from ACLIPVideoProcessingState.

 The upload call happens asyncronously.  The caller should expect the complete and error blocks to happen at an indeterminate time in the future to properly handle the error and only post successful action that it need to perform.

 @param videoURL A URL that points to the video to be uploaded. Can not be nil.
 @param title A title for the video.
 @param attributes The attributes of the video. All values must be of types suppored by NSJSONSerialization.
 @param skipEncoding BOOL to bypass Elemental encoding and encryption.
 @param completedBlock A block that gets called upon successfully uploading the video.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new video object that represents the video being uploaded.
 */
- (ACLIPVideo *)uploadVideoAtURL:(NSURL *)videoURL title:(NSString *)title attributes:(NSDictionary *)attributes skipEncoding:(BOOL)skipEncoding completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Loads the video for the given videoID.

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. The video will be returned as an ACLIPVideo in the completedBlock's parameter.

 @param videoID The ID of the video to load.
 @param completedBlock A block that gets called upon successfully loading the video. The completedBlock parameter will be the ACLIPVideo for the videoID.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)loadUserVideoWithID:(NSString *)videoID completionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Loads the videos for the logged in user.

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. The videos will be returned as an NSArray in the completedBlock's parameter.

 @param completedBlock A block that gets called upon successfully loading the video list. The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)loadUserVideosWithCompletionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Loads the videos for the logged in user.

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. The videos will be returned as an NSArray in the completedBlock's parameter.

 @param predicate An NSPredicate that will filter the results based the video's custom attributes. Currently only is equal (==) operators are supported.
 @param completedBlock A block that gets called upon successfully loading the video list. The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)loadUserVideosWithFilter:(NSPredicate *)predicate completionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Loads the message for the given guid.

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. The message will be returned as an ACLIPMessage in the completedBlock's parameter.

 @param guid The ID of the message to load.
 @param completedBlock A block that gets called upon successfully loading the video. The completedBlock parameter will be the ACLIPMessage for the guid.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)loadMessageWithGUID:(NSString *)guid completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Registers the completion and error blocks for message loading.

 The call registers a completion and error block for loading messages.  The completion block will be called when ever messages are available.  Multiple calls will replace the previous blocks with the new blocks.

 @param completedBlock A block that gets called upon successfully loading the messages list. The first NSArray paramater will return a list of all messages for the user. The second will contain an array of ACLIPMessageThread objects.  The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)registerMessageLoadingCompletionBlock:(ACLIPMessageLoadCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Registers the completion and error blocks for message loading.
 
 The call registers a completion and error block for loading messages.  The completion block will be called when ever messages are available.  Multiple calls will replace the previous blocks with the new blocks.
 
 @param a NSDate where only messages newer than the date will be loaded.
 @param completedBlock A block that gets called upon successfully loading the messages list. The first NSArray paramater will return a list of all messages for the user. The second will contain an array of ACLIPMessageThread objects.  The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)registerMessageLoadingSinceDate:(NSDate *)date completionBlock:(ACLIPMessageLoadCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Unregisters the completion and error blocks that were registered in registerMessageLoadingCompletionBlock:errorBlock:. The blocks will not be called again.

 */
- (void)unregisterMessageLoading;

/** Sends a message to recipients

 @param title An optional title for the message.
 @param messageText An optional text message that can be included in the message
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param videoURL An optional URL that points to the video to be uploaded.
 @param attributes The attributes of the message. All values must be of types suppored by NSJSONSerialization.
 @param completedBlock A block that gets called upon successfully sending the message.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new message object that represents the message being sent.
 */
- (ACLIPMessage *)sendMessage:(NSString *)title messageText:(NSString *)messageText recipients:(NSArray *)recipients videoURL:(NSURL *)videoURL attributes:(NSDictionary *)attributes completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Sends a message to recipients while providing your own message guid

 @param title An optional title for the message.
 @param messageText An optional text message that can be included in the message
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param videoURL An optional URL that points to the video to be uploaded.
 @param messageGuid An optional message GUID to use for the message.
 @param attributes The attributes of the message. All values must be of types suppored by NSJSONSerialization.
 @param completedBlock A block that gets called upon successfully sending the message.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new message object that represents the message being sent.
 */
- (ACLIPMessage *)sendMessage:(NSString *)title messageText:(NSString *)messageText recipients:(NSArray *)recipients videoURL:(NSURL *)videoURL messageGuid:(NSString *)messageGuid attributes:(NSDictionary *)attributes completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Sends a message to recipients with the option to skip encoding the video

 @param title An optional title for the message.
 @param messageText An optional text message that can be included in the message
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param videoURL An optional URL that points to the video to be uploaded.
 @param skipEncoding BOOL to bypass Elemental encoding and encryption.
 @param attributes The attributes of the message. All values must be of types suppored by NSJSONSerialization.
 @param completedBlock A block that gets called upon successfully sending the message.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new message object that represents the message being sent.
 */
- (ACLIPMessage *)sendMessage:(NSString *)title messageText:(NSString *)messageText recipients:(NSArray *)recipients videoURL:(NSURL *)videoURL skipEncoding:(BOOL)skipEncoding attributes:(NSDictionary *)attributes completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Sends a message to recipients with the option to skip encoding the video while providing your own message guid

 @param title An optional title for the message.
 @param messageText An optional text message that can be included in the message
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param videoURL An optional URL that points to the video to be uploaded.
 @param skipEncoding BOOL to bypass Elemental encoding and encryption.
 @param messageGuid An optional message GUID to use for the message.
 @param attributes The attributes of the message. All values must be of types suppored by NSJSONSerialization.
 @param completedBlock A block that gets called upon successfully sending the message.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new message object that represents the message being sent.
 */
- (ACLIPMessage *)sendMessage:(NSString *)title messageText:(NSString *)messageText recipients:(NSArray *)recipients videoURL:(NSURL *)videoURL skipEncoding:(BOOL)skipEncoding messageGuid:(NSString *)messageGuid attributes:(NSDictionary *)attributes completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Forwards a message to recipients

 @param title An optional title for the message.
 @param messageText An optional text message that can be included in the message
 @param recipients An array of recipient user IDs.  The array must contain at least one user ID.
 @param video An optional ACLIPVideo belonging to the forwarded message.
 @param oldMessageGuid The guid of the message that is being forwarded.
 @param newMessageGuid The guid of the new message=.
 @param completedBlock A block that gets called upon successfully sending the message.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.

 @return A new message object that represents the message being sent.
 */
- (ACLIPMessage *)forwardMessage:(NSString *)title messageText:(NSString *)messageText recipients:(NSArray *)recipients video:(ACLIPVideo *)video oldMessageGuid:(NSString *)oldMessageGuid newMessageGuid:(NSString *)newMessageGuid completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Deletes the ACLIPMessage objects

 The call is asyncronous and either the completedBlock or the errorBlock will be called upon the network connection terminating. The messages are not deleted from the data store until the network connections successfully completes.

 @param messages An NSArray of ACLIPMessage objects to be deleted.
 @param completedBlock A block that gets called upon successfully loading the video list. The completeBlock may be called more then once if cached results exist.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)deleteMessages:(NSArray *)messages completeBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

/** Register the device to receive push notifications. This should be called inside the application's "didRegisterForRemoteNotificationsWithDeviceToken" method

 @param deviceToken The NSData token included in the application's "didRegisterForRemoteNotificationsWithDeviceToken" method.
 */
- (void)registerAPNSToken:(NSData *)deviceToken;

/** Check for session's ability to encode videos

 @return BOOL stating whether or not the session should encode videos.
 */
- (BOOL)canEncodeVideos;

@end
