// The Swift Programming Language
// https://docs.swift.org/swift-book

import Foundation
import libclamshell
import Combine

public enum ClamshellChecker {

    // Is the laptop lid closed? (returns false if iMac)
    public static func isLidClosed() -> Bool {
        return IsLidClosed() == 1
    }

    // Emits the clamshell state every second
    public static func updates() -> AnyPublisher<Bool, Never> {
        let publisher = Timer.publish(every: 1, on: .main, in: .common)
            .autoconnect()
            .subscribe(on: DispatchQueue.global())
            .map { _ in ClamshellChecker.isLidClosed() }
            .prepend(ClamshellChecker.isLidClosed()) // start immediately with a value instead of waiting 1 second.
            .receive(on: DispatchQueue.main)
            .eraseToAnyPublisher()

        return publisher
    } 
}
