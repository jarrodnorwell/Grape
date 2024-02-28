//
//  GrapeObjC.h
//  
//
//  Created by Jarrod Norwell on 26/2/2024.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#include <algorithm>
#include <cstdint>
#include <vector>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface GrapeObjC : NSObject
+(GrapeObjC *) sharedInstance NS_SWIFT_NAME(shared());
-(void) insertGame:(NSURL *)url NS_SWIFT_NAME(insert(game:));
-(void) step;

-(uint32_t*) icon:(NSURL *)url NS_SWIFT_NAME(icon(from:));

-(int16_t*) audioBuffer;
-(uint32_t*) screenFramebuffer:(BOOL)isGBA;
-(void) updateScreenLayout:(CGSize)size;

-(void) touchBeganAtPoint:(CGPoint)point;
-(void) touchEnded;
-(void) touchMovedAtPoint:(CGPoint)point;

-(void) virtualControllerButtonDown:(int)button;
-(void) virtualControllerButtonUp:(int)button;
@end

NS_ASSUME_NONNULL_END
