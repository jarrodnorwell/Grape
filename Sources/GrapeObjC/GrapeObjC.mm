//
//  GrapeObjC.mm
//
//
//  Created by Jarrod Norwell on 26/2/2024.
//

#import "GrapeObjC.h"
#import "GrapeSysDataDirectoryManager.h"

#include "core.h"
#include "nds_icon.h"
#include "settings.h"
#include "screen_layout.h"

Core* grapeEmulator = nullptr;
ScreenLayout screenLayout;

@implementation GrapeObjC
+(GrapeObjC *) sharedInstance {
    static dispatch_once_t onceToken;
    static GrapeObjC *sharedInstance = NULL;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

-(void) insertGame:(NSURL *)url {
    if (!Settings::load(std::string(GrapeSysDataDirectory()) + "/settings.ini")) {
        auto path = std::string(GrapeSysDataDirectory());
        
        Settings::setBios7Path(path + "/bios7.bin");
        Settings::setBios7Path(path + "/bios9.bin");
        Settings::setFirmwarePath(path + "/firmware.bin");
        Settings::setGbaBiosPath(path + "/gba_bios.bin");
        Settings::setSdImagePath(path + "/sd.img");
        Settings::save();
    }
    
    if ([url.pathExtension.lowercaseString isEqualToString:@"nds"]) {
        grapeEmulator = new Core([url.path UTF8String], "");
    } else {
        grapeEmulator = new Core("", [url.path UTF8String]);
    }
}

-(void) step {
    grapeEmulator->runFrame();
}

-(uint32_t *) icon:(NSURL *)url {
    uint32_t* data = new uint32_t[32 * 32];
    CARTRIDGE cartridge([url.path UTF8String]);
    memcpy(data, cartridge.GetIcon(), 32 * 32 * sizeof(uint32_t));
    return data;
}

-(int16_t *) audioBuffer {
    static std::vector<int16_t> buffer(1024 * 2);
    uint32_t *original = grapeEmulator->spu.getSamples(699);
    for (int i = 0; i < 1024; i++) {
        uint32_t sample = original[i * 699 / 1024];
        buffer[i * 2 + 0] = sample >>  0;
        buffer[i * 2 + 1] = sample >> 16;
    }
    delete[] original;
    return buffer.data();
}

-(uint32_t*) screenFramebuffer:(BOOL)isGBA {
    static std::vector<uint32_t> framebuffer;
    if (isGBA)
        framebuffer.resize(240 * 160);
    else
        framebuffer.resize(256 * 192 * 2);
    grapeEmulator->gpu.getFrame(framebuffer.data(), isGBA);
    return framebuffer.data();
}

-(void) updateScreenLayout:(CGSize)size {
    screenLayout.update(size.width, size.height, false);
}

-(void) touchBeganAtPoint:(CGPoint)point {
    grapeEmulator->input.pressScreen();
    
    auto x = screenLayout.getTouchX(point.x, point.y);
    auto y = screenLayout.getTouchY(point.x, point.y);
    
    grapeEmulator->spi.setTouch(x, y);
}

-(void) touchEnded {
    grapeEmulator->input.releaseScreen();
    grapeEmulator->spi.clearTouch();
}

-(void) touchMovedAtPoint:(CGPoint)point {
    auto x = screenLayout.getTouchX(point.x, point.y);
    auto y = screenLayout.getTouchY(point.x, point.y);
    
    grapeEmulator->spi.setTouch(x, y);
}

-(void) virtualControllerButtonDown:(int)button {
    grapeEmulator->input.pressKey(button);
}

-(void) virtualControllerButtonUp:(int)button {
    grapeEmulator->input.releaseKey(button);
}
@end
