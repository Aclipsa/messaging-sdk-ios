//
//  ACLIPMoviePlayerController.h
//  AclipsaSDK
//
//  Created by Kevin Macaulay on 3/3/15.
//  Copyright (c) 2015 Aclipsa Mobile Video Solutions, LLC. All rights reserved.
//

#import <MediaPlayer/MediaPlayer.h>

@class ACLIPMessage, ACLIPVideo;

@interface ACLIPMoviePlayerController : MPMoviePlayerController <UIAlertViewDelegate>

/** Initialize an ACLIPMoviePlayerController for the video
 
 @param video The ACLIPVideo that is to be loaded into the media player for playback.
 @return A movie player controller configured for the video.
 */
+ (ACLIPMoviePlayerController*)moviePlayerControllerForVideo:(ACLIPVideo*)video;

/** Initialize an ACLIPMoviePlayerController for the message (supports screenshot reporting)
 
 @param message The ACLIPMessage containing the video that is to be loaded into the media player for playback.
 @return A movie player controller configured for the video. Returns nil if screenshot reporting is enabled but camera roll access is denied
 */
+ (ACLIPMoviePlayerController*)moviePlayerControllerForMessage:(ACLIPMessage*)message;

@end
