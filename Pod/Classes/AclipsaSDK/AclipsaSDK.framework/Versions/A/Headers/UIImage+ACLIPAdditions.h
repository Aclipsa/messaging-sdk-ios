//
//  UIImage+Thumbnails.h
//  Aclipsa360
//
//  Created by Kevin Macaulay on 7/26/12.
//  Copyright (c) 2012 Software Ops. All rights reserved.
//

/** Defines extensions to UIImage that adds thumbnail generation */

@interface UIImage (ACLIPAdditions)

/** Returns an image that is a thumbnail of the given image.
 
 Generates a thumbnail of size for the image located at url.
 
 @param url The location of the image to generate a thumbnail of.
 @param size The size that the generated thumbnail will be.
 @return A NSImage that contains a thumbnail of the image at url that is size.
 */
+ (UIImage*)getThumbnailFromURL:(NSURL*)url size:(CGSize)size;

/** Returns an image that is a thumbnail of the given image.
 
 Generates a thumbnail of size for the image.
 
 @param image The image to generate a thumbnail of.
 @param size The size that the generated thumbnail will be.
 @return A NSImage that contains a thumbnail of the image that is size.
 */
+ (UIImage*)getThumbnailFromImage:(UIImage*)image size:(CGSize)size;

@end
