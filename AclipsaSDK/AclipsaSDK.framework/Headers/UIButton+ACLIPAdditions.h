//
//  UIButton+ACLIPAdditions.h
//  AclipsaSDK
//
//  Created by bmiller on 10/2/13.
//  Copyright (c) 2013 Aclipsa. All rights reserved.
//

@class ACLIPVideo;

typedef void (^ACLIPButtonImageLoadCompleteBlock)(id);

/** Defines extensions to UIButton that adds network image loading */

@interface UIButton (ACLIPAdditions)

/** Loads the thumbnail from video.

 The thumbnail is loaded asynchronously.

 @param video The video for which the thumbnail is to be shown.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 */
- (void)setImageWithVideo:(ACLIPVideo *)video forState:(UIControlState)state;

/** Loads the thumbnail from video with a completion block.

 The thumbnail is loaded asynchronously.

 @param video The video for which the thumbnail is to be shown.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 @param completeBlock Completion block when image finishes loading.
 */
- (void)setImageWithVideo:(ACLIPVideo *)video forState:(UIControlState)state completeBlock:(ACLIPButtonImageLoadCompleteBlock)completeBlock;

/** Loads the image located at url.

 The URL is loaded asynchronously.

 @param video The video for which the thumbnail is to be shown.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 */
- (void)setImageWithVideo:(ACLIPVideo *)video placeholderImage:(UIImage *)placeholderImage forState:(UIControlState)state;

/** Loads the image located at url with a completion block.

 The URL is loaded asynchronously.

 @param video The video for which the thumbnail is to be shown.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 @param completeBlock Completion block when image finishes loading.
 */
- (void)setImageWithVideo:(ACLIPVideo *)video placeholderImage:(UIImage *)placeholderImage forState:(UIControlState)state completeBlock:(ACLIPButtonImageLoadCompleteBlock)completeBlock;

/** Loads the image located at url.

 The URL is loaded asynchronously.

 @param url The location of the image to be loaded into the imageView.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 */

- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state;

/** Loads the image located at url with a completion block.

 The URL is loaded asynchronously.

 @param url The location of the image to be loaded into the imageView.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 @param completeBlock Completion block when image finishes loading.
 */

- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state completeBlock:(ACLIPButtonImageLoadCompleteBlock)completeBlock;

/** Loads the image located at url.

 The URL is loaded asynchronously.

 @param url The location of the image to be loaded into the imageView.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholderImage forState:(UIControlState)state;

/** Loads the image located at url.

 The URL is loaded asynchronously.

 @param url The location of the image to be loaded into the imageView.
 @param placeholderImage An image that is displayed in the imageView until the URL image is loaded.
 @param state The state that uses the specified title. The possible values are described in UIControlState.
 @param completeBlock Completion block when image finishes loading.
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholderImage forState:(UIControlState)state completeBlock:(ACLIPButtonImageLoadCompleteBlock)completeBlock;

@end
