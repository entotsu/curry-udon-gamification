//
//  HitAnimation.cpp
//  animationFunction
//
//  Created by Takuya Okamoto on 2014/08/26.
//
//

#include "HitAnimation.h"
#include <sstream>
#include <string>


void HitAnimation::setup() {
    //フォント設定
    ofTrueTypeFont::setGlobalDpi(700);//72);
	scoreFont.loadFont("Batang.ttf", 10, true, true, true);
    scoreFont.setLineHeight(18.0f);
    scoreFont.setLetterSpacing(1.037);
    alpha = 0;
    //debug
//    position.x = ofRandom(ofGetWidth());
//    position.y = ofRandom(ofGetHeight());
//    scoreText = toString(ofRandom(999));
//    alpha = 1;
}




void HitAnimation::start(int score,float x, float y) {
    alpha = 255;
    scoreText = toString(score);
    position.x = x;
    position.y = y;
}





// -------- loop --------

void HitAnimation::update() {
    if (alpha > 0) {
        position.y -= 2;
        alpha -= 5;
    }
}

void HitAnimation::draw() {
    if (alpha > 0) {
        ofSetColor(0,0,0, alpha);
        scoreFont.drawString(scoreText, position.x, position.y);
    }
}





// -------------------- private ---------------------
string HitAnimation::toString(int n) {
    std::ostringstream stream;
    stream << n;
    std::string result = stream.str();
    return result;
}
