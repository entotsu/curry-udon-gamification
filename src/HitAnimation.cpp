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

#define SIZE_INCREACE_SPEED 2.5
#define MAX_SIZE 100

void HitAnimation::setup() {
    //フォント設定
    ofTrueTypeFont::setGlobalDpi(700);//72);
	scoreFont.loadFont("kremlin.ttf", 10, true, true, true);
    scoreFont.setLineHeight(18.0f);
    scoreFont.setLetterSpacing(1.037);
    alpha = 0;
    
    hitImage.loadImage("point4.png");
    
    //debug
//    position.x = ofRandom(ofGetWidth());
//    position.y = ofRandom(ofGetHeight());
//    scoreText = toString(ofRandom(999));
//    alpha = 1;
}




void HitAnimation::start(int score,float x, float y) {
    alpha = 255;
    scoreAlpha = 0;
    scoreScale = 0;
    size = 0;
    scoreText = toString(score);
    position.x = x;
    position.y = y;
}





// -------- loop --------

void HitAnimation::update() {
    if (alpha > 0) {
//        position.y -= 2;
        if (size <= MAX_SIZE) {
            size += SIZE_INCREACE_SPEED;
        }
        else {
            //            alpha -= 5;
        }
        if (scoreAlpha <= 255) {
            scoreAlpha += 5;
            scoreScale += 0.02;
        }
    }
}

void HitAnimation::draw() {
    if (alpha > 0) {
        ofSetColor(0,0,0, scoreAlpha);
        float scoreX = position.x;
        float scoreY = position.y - MAX_SIZE + 20;
        ofPushMatrix();
            ofTranslate(scoreX, scoreY);
            ofScale(scoreScale, scoreScale, 1);
            float fontWidth = scoreFont.stringWidth(scoreText);
            scoreFont.drawString(scoreText, -fontWidth/2, 0);
        ofPopMatrix();
        
        //色の設定
        ofSetColor(255, 255, 255);
        float imgX = position.x - ((size + SIZE_INCREACE_SPEED) / 2);
        float imgY = position.y - ((size + SIZE_INCREACE_SPEED) / 2);
        hitImage.draw(imgX, imgY, size, size);
    }
}





// -------------------- private ---------------------
string HitAnimation::toString(int n) {
    std::ostringstream stream;
    stream << n;
    std::string result = stream.str();
    return result;
}