#import "include/libclamshell.h"
#include <stdarg.h>

// Taken from
// https://github.com/alin23/Lunar/blob/b519b28a80aae8388204509f8234285f1bcfe45f/Lunar/DDC/DDC.swift#L968
int IsLidClosed(void)
{
    bool isClosed = false;
    io_registry_entry_t rootDomain;
    mach_port_t masterPort;
    CFTypeRef clamShellStateRef = NULL;

    IOReturn ioReturn = IOMasterPort(MACH_PORT_NULL, &masterPort);
    if (ioReturn != 0) {
        return false;
    }

    // Check to see if the "AppleClamshellClosed" property is in the PM root domain:
    rootDomain = IORegistryEntryFromPath(masterPort, kIOPowerPlane ":/IOPowerConnection/IOPMrootDomain");

    clamShellStateRef = IORegistryEntryCreateCFProperty(rootDomain, CFSTR("AppleClamshellState"), kCFAllocatorDefault, 0);
    if (clamShellStateRef == NULL) {
        if (rootDomain) {
            IOObjectRelease(rootDomain);
            return false;
        }
    }

    if (CFBooleanGetValue((CFBooleanRef)(clamShellStateRef)) == true) {
        isClosed = true;
    }

    if (rootDomain) {
        IOObjectRelease(rootDomain);
    }

    if (clamShellStateRef) {
        CFRelease(clamShellStateRef);
    }

    return isClosed;
}
