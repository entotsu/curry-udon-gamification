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
#define ENDING_MODE_ALPHA 100

void HitAnimation::setup() {
    //フォント設定
    ofTrueTypeFont::setGlobalDpi(700);//72);
	scoreFont.loadFont("kremlin.ttf", 10, true, true, true);
    scoreFont.setLineHeight(18.0f);
    scoreFont.setLetterSpacing(1.037);
    alpha = 0;
    hitImage.loadImage("point4.png");
    hitSound.loadSound("coin.wav");
    hitSound.setMultiPlay(true);
    
    //debug
//    position.x = ofRandom(ofGetWidth());
//    position.y = ofRandom(ofGetHeight());
//    scoreText = toString(ofRandom(999));
//    alpha = 1;
}




void HitAnimation::start(int score,float x, float y) {
    //音の再生
    hitSound.play();

    alpha = 255;
    scoreAlpha = 255;
    scoreScale = 0;
    size = 0;
    scoreText = toString(score);
    position.x = x;
    position.y = y;
    scorePosition.x = x;
    scorePosition.y = y;
}





// -------- loop --------

void HitAnimation::update() {
    if (alpha > 0) {
        if (size <= MAX_SIZE) {
            size += SIZE_INCREACE_SPEED;
        }
        
        //遅れてスコアの表示開始
        if (size >= MAX_SIZE / 2) {
            if (scoreScale <= 1) {
                scoreScale += 0.02;
            }else {
                scorePosition.x -= 2;
            }
            scoreAlpha -= 2.5;
        }
    }
}

void HitAnimation::draw() {
    if (alpha > 0) {
        //スコアの描画
        ofSetColor(0, 255, 0, scoreAlpha);
        if (isEndingMode) ofSetColor(0, 255, 0, ENDING_MODE_ALPHA);
        float scoreX = scorePosition.x - 65;
        float scoreY = scorePosition.y;
        ofPushMatrix();
            ofTranslate(scoreX, scoreY);
            ofScale(scoreScale, scoreScale, 1);
            ofRotateZ(-90);
            float fontWidth = scoreFont.stringWidth(scoreText);
            scoreFont.drawString(scoreText, -fontWidth/2,0);
        ofPopMatrix();
        
        //画像の描画
        ofSetColor(255, 255, 255);
        if (isEndingMode) ofSetColor(255, 255, 255, ENDING_MODE_ALPHA);
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
