#import <CoreData/CoreData.h>
#import "ACLIPConstants.h"

/** An ACLIPVideo encapulates all of the data of a video to be played.
 
 */

@interface ACLIPVideo : NSManagedObject {}

/** Unique identifier for the video */
@property (nonatomic, readonly) NSString *guid;

/** The title of the video */
@property (nonatomic, readonly) NSString *title;

/** The runtime of the video in seconds */
@property (nonatomic, readonly) NSTimeInterval runTime;

// TODO: Need to document the thumbnail sizes
/** URL to thumbnail for the video.  Should be used in conjunction with the UIImageView addition setImageWithURL: */
@property (nonatomic, readonly) NSURL *thumbnailSmallURL;

/** URL to thumbnail for the video.  Should be used in conjunction with the UIImageView addition setImageWithURL: */
@property (nonatomic, readonly) NSURL *thumbnailMediumURL;

/** URL to thumbnail for the video.  Should be used in conjunction with the UIImageView addition setImageWithURL: */
@property (nonatomic, readonly) NSURL *thumbnailLargeURL;

/** The current state of the video. */
@property (nonatomic, readonly) ACLIPVideoStateType state;

/** The upload progress of the video between 0-1.  Value is only valid if the state is ACLIPVideoUploadingState. */
@property (nonatomic, readonly) CGFloat uploadProgress;

/** The orientation of the video. */
@property (nonatomic, readonly) UIInterfaceOrientation orientation;

/** The aspect ratio of the video */
@property (nonatomic, readonly) ACLIPAspectRatio aspectRatio;

/** The created date of the video. */
@property (nonatomic, readonly) NSDate *createdDate;

/** The attributes of the video */
@property (nonatomic, readonly) NSDictionary *attributes;

/** Returns the maximum number of pixels allowed for the video.
 
 The video can be in any aspect ratio with the constraint that the width x hight is less than or equal to the maximum allowed.
 
 @return The maximum number of pixels for the video's size. */
+ (NSInteger)maximumAllowedPixels;

/** Returns the maximum length that a video may be.
 
 The video's duration must be less than or equal to returned value.
 
 @return The maximum length of the video in seconds. */
+ (NSInteger)maximumVideoLength;

/** Returns the amount of time the video should be rolled back before beginning playback.
 
 @return The amount of time the video should be rolled back in seconds. */
+ (NSInteger)resumeFactor;

/** Returns video for the guid.
 
 Retrieves the video for the guid from the video cache.
 
 @param guid The guid for the video to return.
 
 @return The cached video for the guid.  Returns nil if the cache does not contain the video. */
+ (ACLIPVideo*)cachedVideoForGUID:(NSString*)guid;

/** Deletes the video.
 
 Videos that are associated with an ALIPMessage can not be deleted.  An ACLIPCantDeleteMessageVideoError will be returned.
 
 @param completedBlock A block that gets called upon successfully deleting the video.  completedBlock can be nil.
 @param errorBlock A block that gets called when any error occurs.  The error can be either a Foundation network error or an ACLIPNetworkReturnType error. errorBlock can be nil in no error handling is requiried.
 */
- (void)deleteVideoCompletionBlock:(ACLIPNetworkCompleteBlock)completedBlock errorBlock:(ACLIPNetworkErrorBlock)errorBlock;

@end
