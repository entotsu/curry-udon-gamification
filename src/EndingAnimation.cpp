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
    ptsFont.loadFont("kremlin.ttf", 5, true, true, true);
    font.setLineHeight(18.0f);
    font.setLetterSpacing(1.037);
        
    bgImg.loadImage("total_score.png");
    drumrollSound.loadSound("dramroll.wav");
    newScoreImg.loadImage("newscore.png");
}




void EndingAnimation::start(int score) {
    drumrollSound.play();
    alpha = 255;
    position.x = ofGetWidth() / 2;
    position.y = ofGetHeight() / 2;
//    scoreText = toString(score);
    totalScore = score;
    startTime = ofGetElapsedTimeMillis();
    elapsedTime = 0;
}





// -------- loop --------

bool EndingAnimation::update() { //アニメ−ションが終わったらfalseを返す。
    //ドラムロール
    currentTime = ofGetElapsedTimeMillis();
    if (elapsedTime < 2000) {
        elapsedTime = currentTime - startTime;
        randScore = ofRandom(9999);
        scoreText = toString(randScore);
        return true;
    }
    //スコア表示後
    else {
        if (isNewScore) {
            if (int(currentTime / 400) % 2 == 0) newScoreAlpha = 0;
            else newScoreAlpha = 255;
        }
        if(elapsedTime < 6000) {
            scoreText = toString(totalScore);
            return true;
        }
        else {
            return false;
        }
    }
}

void EndingAnimation::draw() {
    if (alpha > 0) {
        ofSetColor(255,255,255, alpha);

        bgImg.draw(0, 80, 1000, 605);
        
        ofSetColor(0,0,0, alpha);
        // total score
        ofPushMatrix();
            ofTranslate(position.x, position.y);
            ofRotateZ(-90);
            font.drawString(scoreText, (-font.stringWidth(scoreText)/2) - 50, 0);
            ptsFont.drawString("pts", 100, 0);
        if (isNewScore && elapsedTime > 2000) {
            ofSetColor(255,255,255, newScoreAlpha);
            newScoreImg.draw(-230, 80);
        }
        ofPopMatrix();
    }
}





// -------------------- private ---------------------
string EndingAnimation::toString(int n) {
    std::ostringstream stream;
    stream << n;
    std::string result = stream.str();
    return result;
}
