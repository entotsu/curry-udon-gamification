//
//  GameTimer.cpp
//  animationFunction
//
//  Created by Takuya Okamoto on 2014/09/06.
//
//

#include "GameTimer.h"
#include <sstream>
#include <string>

#define TIME_LIMIT_SEC 30

void GameTimer::setup() {
    // フォント設定
    ofTrueTypeFont::setGlobalDpi(700);//72);
	font.loadFont("kremlin.ttf", 10, true, true, true);
    font.setLineHeight(18.0f);
    font.setLetterSpacing(1.037);
}




void GameTimer::start() {
    alpha = 255;
    remainSec = TIME_LIMIT_SEC;
    startClock = ofGetElapsedTimeMillis();
    position.x = ofGetWidth() - 350;
    position.y = 100;
}







// -------- loop --------

bool GameTimer::update() { //アニメ−ションが終わったらfalseを返す。
    if (remainSec > 0) {
        
        currentClock = ofGetElapsedTimeMillis();
        timeLimitSec = TIME_LIMIT_SEC;
        unsigned long long msec = currentClock - startClock;
        unsigned long long totalSec = msec / 1000;
        remainSec = timeLimitSec - totalSec;
        unsigned long long sec = remainSec;

        //sec string
        std::ostringstream stream_sec;
        stream_sec << std::setfill('0') << std::setw(2) << sec;
        std::string s_str = stream_sec.str();
        
        text = s_str;
        
        return true;
    }
    else {
        return false;
    }
}

void GameTimer::draw() {
    if (alpha > 0) {
        ofSetColor(0,0,0, alpha);
        font.drawString(text , position.x, position.y);
    }
}





// -------------------- private ---------------------
string GameTimer::toString(int n) {
    std::ostringstream stream;
    stream << n;
    std::string result = stream.str();
    return result;
}


