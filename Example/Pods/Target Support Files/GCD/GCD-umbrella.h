#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "GCD.h"
#import "GCDGroup.h"
#import "GCDQueue.h"
#import "GCDSemaphore.h"
#import "GCDTimer.h"

FOUNDATION_EXPORT double GCDVersionNumber;
FOUNDATION_EXPORT const unsigned char GCDVersionString[];

