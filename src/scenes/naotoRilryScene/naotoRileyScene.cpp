
#include "naotoRileyScene.h"

void naotoRileyScene::setup(){
    height.set("height", 40, 40, 80);
    width.set("width", 0.0525, 0.01, 0.075);
    num.set("num", 63, 28, 78);
    shiftSlider.set("shift", 0.35, -0.5, 0.5);
    shiftX.set("shiftX", 0, -20, 20);
    shiftY.set("shiftY", -20, -20, 20);
    
    parameters.add(height);
    parameters.add(width);
    parameters.add(num);
    parameters.add(shiftSlider);
    parameters.add(shiftX);
    parameters.add(shiftY);
    
    loadCode("naotoRileyScene/code.txt");
    
}

void naotoRileyScene::update(){
    width = width.getMin() + ofMap(cos(ofGetElapsedTimef()*.3), -1, 1, 0, 1) * (width.getMax() - width.getMin());
}

void naotoRileyScene::draw(){
    int frameNum = ofGetFrameNum();
    
    if(frameNum % 120 ==0 || frameNum % 220 == 0 ){
        height= ofRandom(height.getMin(), height.getMax());
    }
    shiftX =  ofMap( ofNoise( ofGetElapsedTimef()*.3), 0, 1, shiftX.getMin(), shiftX.getMax());
    shiftY =  ofMap( ofNoise( ofGetElapsedTimef()*.5), 0, 1, shiftY.getMin(), shiftY.getMax());
    
    ofBackground(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(dimensions.width*(1.0 - ofMap(shiftX, shiftX.getMin(), shiftX.getMax(), 0.3, 0.7)), dimensions.height*(1.0 - ofMap(shiftY, shiftY.getMin(), shiftY.getMax(), 0.3, 0.7)));
    ofRotate(ofGetFrameNum()*.5);
    
    ofFill();
    
    float arcLength = 0;
    for(int j = 0; j < 12; j++){
        if(j!=1){
            if(j % 2 == 0){
                shift = shiftSlider;
            }else{
                shift = -shiftSlider;
            }
        }else{
            shift =0;
        }
        
        for (int i = 0; i < num; i++) {
            
            ofPath path;
            path.setColor(ofColor(0));
            
            int radius = height * j;
            arcLength += radius*TWO_PI/num;
            float theta = arcLength /radius;
            
            int x0 = radius*cos(theta+j+shift)+shiftX*j;
            int y0 = radius*sin(theta+j+shift)+shiftY*j;
            
            path.moveTo(x0,y0);
            
            int x1 = radius*cos(theta+width+j+shift)+shiftX*j;
            int y1 = radius*sin(theta+width+j+shift)+shiftY*j;
            
            path.lineTo(x1,y1);
            
            int x2 = (radius+height+0.1)*cos(theta+width+j)+shiftX*(j+1);
            int y2 = (radius+height+0.1)*sin(theta+width+j)+shiftY*(j+1);
            
            path.lineTo(x2,y2);
            
            int x3 = (radius+height+0.1)*cos(theta+j)+shiftX*(j+1);
            int y3 = (radius+height+0.1)*sin(theta+j)+shiftY*(j+1);
            
            path.lineTo(x3,y3);
            
            path.close();
            path.draw();
            
        }
    }
    
    ofPopMatrix();
    
}
