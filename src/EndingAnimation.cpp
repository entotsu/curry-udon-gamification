//
//  EndingAnimation.cpp
//  animationFunction
//
//  Created by Takuya Okamoto on 2014/08/28.
//
//

#include "EndingAnimation.h"
#include <sstream>
#include <string>


void EndingAnimation::setup() {
    // フォント設定
    ofTrueTypeFont::setGlobalDpi(700);//72);
	font.loadFont("kremlin.ttf", 10, true, true, true);
    font.setLineHeight(18.0f);
    font.setLetterSpacing(1.037);
}




void EndingAnimation::start(int score) {
    alpha = 255;
    position.x = ofGetWidth() / 2;
    position.y = ofGetHeight() / 2;
    scoreText = toString(score);
}





// -------- loop --------

bool EndingAnimation::update() { //アニメ−ションが終わったらfalseを返す。
    if (alpha > 0) {
        position.y -= 2;
        alpha -= 5;
        return true;
    }
    else {
        return false;
    }
}

void EndingAnimation::draw() {
    if (alpha > 0) {
        ofSetColor(0,0,0, alpha);
        font.drawString(scoreText, position.x, position.y);
    }
}





// -------------------- private ---------------------
string EndingAnimation::toString(int n) {
    std::ostringstream stream;
    stream << n;
    std::string result = stream.str();
    return result;
}
