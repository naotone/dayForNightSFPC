
#pragma once

#include "ofMain.h"
#include "baseScene.h"

class naotoRileyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofParameter<int> height;
    ofParameter<float> width;
    ofParameter<int> num;
    ofParameter<float> shiftSlider;
    ofParameter<float> shiftX, shiftY;
    
    float shift;
    
};