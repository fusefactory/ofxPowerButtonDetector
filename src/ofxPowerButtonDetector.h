//
//  gistfile1.pch
//  TestSwitchOff
//
//  Created by Matteo on 11/05/16.
//
//
//
//#pragma once
//#ifdef __APPLE__
//#include "ofMain.h"
//
//class ofxPowerButtonDetector : public ofThread{
//public:
//    void setup();
//    void exit();
//
//protected:
////    void threadedFunction();
//
//private:
//
//    enum STATE
//    {
//        INIT,
//        RUN
//    };
//    STATE state;
//};
//
//#endif

#pragma once
#ifdef __APPLE__
#include "ofMain.h"

class ofxPowerButtonDetector : public ofThread{
public:
    void setup();
};

#endif
