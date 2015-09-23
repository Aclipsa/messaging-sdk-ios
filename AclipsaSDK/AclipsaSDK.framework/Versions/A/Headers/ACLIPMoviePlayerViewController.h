//
//  ACLIPMoviePlayerViewController.h
//  Aclipsa360
//
//  Copyright (c) 2013 Aclipsa Mobile Video Solutions, LLC. All rights reserved.
//

#import <MediaPlayer/MediaPlayer.h>

@class ACLIPVideo, ACLIPMessage;

typedef BOOL(^ACLIPAssetsLoadCompleteBlock)(void);
typedef BOOL(^ACLIPAssetsLoadErrorBlock)(NSError *);

/** ACLIPMoviePlayerViewController is used for all playback of videos from Aclipsa.
 */

@interface ACLIPMoviePlayerViewController : MPMoviePlayerViewController <UIAlertViewDelegate>
{
}

/** Initialize an ACLIPMoviePlayerViewController for the video
 
 @param video The ACLIPVideo that is to be loaded into the media player for playback. 
 @return A movie player controller configured for the video.
*/
+ (ACLIPMoviePlayerViewController*)moviePlayerViewControllerForVideo:(ACLIPVideo*)video;


/** Initialize an ACLIPMoviePlayerViewController for the video
 
 @param video The ACLIPVideo that is to be loaded into the media player for playback.
 @param withAutoScaling BOOL indicating whether or not the video should be automatically scaled by the player
 @param orientationMask NSInteger indicating the possible orientations of the player
 @return A movie player controller configured for the video.
 */
+ (ACLIPMoviePlayerViewController*)moviePlayerViewControllerForVideo:(ACLIPVideo*)video withAutoScaling:(BOOL)withAutoScaling orientationMask:(NSInteger)orientationMask;

/** Initialize an ACLIPMoviePlayerViewController for the message (supports screenshot reporting)
 
 @param message The ACLIPMessage containing the video that is to be loaded into the media player for playback.
 @return A movie player controller configured for the video. Returns nil if screenshot reporting is enabled but camera roll access is denied
 */
+ (ACLIPMoviePlayerViewController*)moviePlayerViewControllerForMessage:(ACLIPMessage*)message;


/** Initialize an ACLIPMoviePlayerViewController for the message (supports screenshot reporting)
 
 @param message The ACLIPMessage containing the video that is to be loaded into the media player for playback.
 @param withAutoScaling BOOL indicating whether or not the video should be automatically scaled by the player
 @param orientationMask NSInteger indicating the possible orientations of the player
 @return A movie player controller configured for the video. Returns nil if screenshot reporting is enabled but camera roll access is denied
 */
+ (ACLIPMoviePlayerViewController*)moviePlayerViewControllerForMessage:(ACLIPMessage*)message withAutoScaling:(BOOL)withAutoScaling orientationMask:(NSInteger)orientationMask;

@end
