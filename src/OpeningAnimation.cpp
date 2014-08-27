//
//  OpeningAnimation.cpp
//  animationFunction
//
//  Created by Takuya Okamoto on 2014/08/28.
//
//

#include "OpeningAnimation.h"
#include <sstream>
#include <string>


void OpeningAnimation::setup() {
    // フォント設定
    ofTrueTypeFont::setGlobalDpi(700);//72);
	font.loadFont("Batang.ttf", 10, true, true, true);
    font.setLineHeight(18.0f);
    font.setLetterSpacing(1.037);
}




void OpeningAnimation::start() {
    alpha = 255;
    position.x = ofGetWidth() / 2;
    position.y = ofGetHeight() / 2;
}





// -------- loop --------

bool OpeningAnimation::update() { //アニメ−ションが終わったらfalseを返す。
    if (alpha > 0) {
        position.y -= 2;
        alpha -= 5;
        return true;
    }
    else {
        return false;
    }
}

void OpeningAnimation::draw() {
    if (alpha > 0) {
        ofSetColor(0,0,0, alpha);
        font.drawString("start", position.x, position.y);
    }
}





// -------------------- private ---------------------
string OpeningAnimation::toString(int n) {
    std::ostringstream stream;
    stream << n;
    std::string result = stream.str();
    return result;
}
