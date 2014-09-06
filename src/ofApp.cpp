#include "ofApp.h"



//=======================================================================
//   APIs
//=======================================================================



void ofApp::hit(int score, float x, float y){
    //アニメ−ションさせる要素をずらしていく
    hits[animationIndex].start(score, x, y);
    if (++animationIndex == MAX_ANIMATION) animationIndex = 0;

    totalScore += score;
}






void ofApp::startOpeningAnimation(){
    opAnimation.start();
    isRunningOpeningAnimation = true;
//    isPlayingGame = true;
}


void ofApp::startTimer() {
    timerGraphic.start();
    totalScore = 0;
    isRunningTimer = true;
}


void ofApp::startEndingAnimation(int totalScore){
    edAnimation.start(totalScore);
    isRunningEndingAnimation = true;
    
    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].isEndingMode = true;
    }
}









//=======================================================================
//   of の ライフサイクル
//=======================================================================

void ofApp::setup(){
    
    ofBackground(255,255,255);
    ofEnableSmoothing();
    
    animationIndex = 0;
    
    timerGraphic.setup();
    opAnimation.setup();
    edAnimation.setup();
    
    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Hit Animation
    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].update();
    }
    
    // Opening Animation
    if (isRunningOpeningAnimation) {
        if (! opAnimation.update()) {
            isRunningOpeningAnimation = false;
            startTimer();
        }
    }
    
    // Timer
    if (isRunningTimer) {
        if (! timerGraphic.update()) {
            isRunningTimer = false;
            startEndingAnimation(totalScore);
        }
    }
    
    // Ending Animation
    if (isRunningEndingAnimation) {
        if (! edAnimation.update()) {
            isRunningEndingAnimation = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Hit Animation
    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].draw();
    }
    
    // Opening Animation
    if (isRunningOpeningAnimation) {
        opAnimation.draw();
    }
    
    // Timer
    if (isRunningTimer) {
        timerGraphic.draw();
    }
    
    
    // Ending Animation
    if (isRunningEndingAnimation) {
        edAnimation.draw();
    }
    
    // FPS
    ofSetColor(0, 0, 0, 255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
	if (key == 'o') {
        startOpeningAnimation();
    }
    else if (key == 'e') {
        startEndingAnimation(ofRandom(9999));
    }
    else if (key == 't') {
        startTimer();
    }
    else {
        hit(ofRandom(999), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
