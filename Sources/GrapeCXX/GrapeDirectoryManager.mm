//
//  GrapeSysDataDirectoryManager.mm
//
//
//  Created by Jarrod Norwell on 26/2/2024.
//

#import <Foundation/Foundation.h>

#import "GrapeSysDataDirectoryManager.h"

const char* GrapeSysDataDirectory() {
    return [[[[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject]
             URLByAppendingPathComponent:@"Grape"]
            URLByAppendingPathComponent:@"sysdata"].path UTF8String];
}
