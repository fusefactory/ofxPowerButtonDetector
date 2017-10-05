//
//  PowerButtonDetector.h
//  BootManager
//
//  Created by Akira on 4/7/15.
//
//

//#ifdef __APPLE__
//
//#include "ofxPowerButtonDetector.h"
//
//static const string shutdonwScript = "osascript -e \'tell app \"System Events\" to shut down\'";
//
//static void onPwrBtnPressed(CFNotificationCenterRef center,
//                            void *observer,
//                            CFStringRef name,
//                            const void *object,
//                            CFDictionaryRef userInfo)
//{
//    ofLog() << "Power Button Pressed";
//    ofSystem(shutdonwScript);
//}
//
//void ofxPowerButtonDetector::setup()
//{
//    state = INIT;
//    startThread();
//}
//
//void ofxPowerButtonDetector::exit()
//{
//    waitForThread();
//}
//
//void ofxPowerButtonDetector::threadedFunction()
//{
//    while(isThreadRunning())
//    {
//        if (state == INIT && lock())
//        {
//            CFNotificationCenterRef distCenter;
//            CFStringRef evtName = CFSTR("com.apple.shutdownInitiated");
//            distCenter = CFNotificationCenterGetDistributedCenter();
//            if (NULL == distCenter)
//                return 1;
//            CFNotificationCenterAddObserver(distCenter, NULL, &onPwrBtnPressed, evtName, NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
//            CFRunLoopRun();
//            state = RUN;
//            unlock();
//        }
//        sleep(1);
//    }
//}
//
//#endif

#ifdef __APPLE__

#include "ofxPowerButtonDetector.h"

static const string shutdonwScript = "osascript -e \'tell app \"System Events\" to shut down\'";

static void onPwrBtnPressed(CFNotificationCenterRef center,
                            void *observer,
                            CFStringRef name,
                            const void *object,
                            CFDictionaryRef userInfo)
{
    ofLog() << "Power Button Pressed";
    ofSystem(shutdonwScript);
}

void ofxPowerButtonDetector::setup()
{
    CFNotificationCenterRef distCenter;
    CFStringRef evtName = CFSTR("com.apple.shutdownInitiated");
    distCenter = CFNotificationCenterGetDistributedCenter();
    if (NULL == distCenter)
        return 1;
    CFNotificationCenterAddObserver(distCenter, NULL, &onPwrBtnPressed, evtName, NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
    CFRunLoopRun();
}

#endif


