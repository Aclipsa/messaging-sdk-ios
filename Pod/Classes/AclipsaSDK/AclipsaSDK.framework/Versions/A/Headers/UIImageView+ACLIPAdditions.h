//
//  UIImageView+CPAdditions.h
//  PushNotificationTest
//
//  Created by Brad Miller on 11/19/10.
//  Copyright 2011 Cynical Peak Software. All rights reserved.
//

@class ACLIPVideo;

typedef void(^ACLIPImageLoadCompleteBlock)(id);

/** Defines extensions to UIImageView that adds network image loading */

@interface UIImageView (ACLIPAdditions)

/** Loads the thumbnail from video.
 
 The thumbnail is loaded asynchronously.
 
 @param video The video for which the thumbnail is to be shown.
 */
- (void)setImageWithVideo:(ACLIPVideo*)video;

/** Loads the thumbnail from video with a completion block.
 
 The thumbnail is loaded asynchronously.
 
 @param video The video for which the thumbnail is to be shown.
 @param completeBlock Completion block when image finishes loading.
 */
- (void)setImageWithVideo:(ACLIPVideo*)video completeBlock:(ACLIPImageLoadCompleteBlock)completeBlock;

/** Loads the image located at url.
 
 The URL is loaded asynchronously.
 
 @param video The video for which the thumbnail is to be shown.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 */
- (void)setImageWithVideo:(ACLIPVideo*)video placeholderImage:(UIImage*)placeholderImage;

/** Loads the image located at url with a completion block.
 
 The URL is loaded asynchronously.
 
 @param video The video for which the thumbnail is to be shown.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 @param completeBlock Completion block when image finishes loading.
 */
- (void)setImageWithVideo:(ACLIPVideo*)video placeholderImage:(UIImage*)placeholderImage completeBlock:(ACLIPImageLoadCompleteBlock)completeBlock;

/** Loads the image located at url.
 
 The URL is loaded asynchronously.
 
 @param url The location of the image to be loaded into the imageView.
 */

- (void)setImageWithURL:(NSURL*)url;

/** Loads the image located at url with a completion block.
 
 The URL is loaded asynchronously.
 
 @param url The location of the image to be loaded into the imageView.
 @param completeBlock Completion block when image finishes loading.
 */

- (void)setImageWithURL:(NSURL*)url completeBlock:(ACLIPImageLoadCompleteBlock)completeBlock;

/** Loads the image located at url.
 
 The URL is loaded asynchronously.
 
 @param url The location of the image to be loaded into the imageView.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholderImage;

/** Loads the image located at url.
 
 The URL is loaded asynchronously.
 
 @param url The location of the image to be loaded into the imageView.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 @param completeBlock Completion block when image finishes loading.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholderImage completeBlock:(ACLIPImageLoadCompleteBlock)completeBlock;

@end
