//
//  Grape.swift
//
//
//  Created by Jarrod Norwell on 26/2/2024.
//

import GrapeObjC
import Foundation

public struct Grape {
    public static let shared = Grape()
    
    fileprivate let grapeObjC = GrapeObjC.shared()
    
    public func insert(game url: URL) {
        grapeObjC.insert(game: url)
    }
    
    public func step() {
        grapeObjC.step()
    }
    
    public func icon(from url: URL) -> UnsafeMutablePointer<UInt32> {
        grapeObjC.icon(from: url)
    }
    
    public func audioBuffer() -> UnsafeMutablePointer<Int16> {
        grapeObjC.audioBuffer()
    }
    
    public func screenFramebuffer(isGBA: Bool) -> UnsafeMutablePointer<UInt32> {
        grapeObjC.screenFramebuffer(isGBA)
    }
    
    public func updateScreenLayout(with size: CGSize) {
        grapeObjC.updateScreenLayout(size)
    }
    
    public func touchBegan(at point: CGPoint) {
        grapeObjC.touchBegan(at: point)
    }
    
    public func touchEnded() {
        grapeObjC.touchEnded()
    }
    
    public func touchMoved(at point: CGPoint) {
        grapeObjC.touchMoved(at: point)
    }
    
    public func virtualControllerButtonDown(_ button: Int32) {
        grapeObjC.virtualControllerButtonDown(button)
    }
    
    public func virtualControllerButtonUp(_ button: Int32) {
        grapeObjC.virtualControllerButtonUp(button)
    }
}
