//
//  HitAnimation.h
//  animationFunction
//
//  Created by Takuya Okamoto on 2014/08/26.
//
//

#ifndef __animationFunction__HitAnimation__
#define __animationFunction__HitAnimation__
#include <iostream>
#endif /* defined(__animationFunction__HitAnimation__) */
#pragma once
#include "ofMain.h"


class HitAnimation {
    
public:
    void setup();
    void draw();
    void update();
    void start(int score,float x, float y);

    string scoreText;
    ofTrueTypeFont scoreFont;
    ofVec2f position;
    int alpha;
    bool isEnd;

private:
    string toString(int n);
};