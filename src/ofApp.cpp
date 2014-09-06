#include "ofApp.h"






void ofApp::hit(int score, float x, float y){
    
    hits[animationIndex].start(score, x, y);
    
    //アニメ−ションさせる要素をずらしていく
    if (++animationIndex == MAX_ANIMATION) animationIndex = 0;
}






void ofApp::startOpeningAnimation(){
    opAnimation.start();
    isRunningOpeningAnimation = true;
}



void ofApp::startEndingAnimation(int totalScore){
    edAnimation.start(totalScore);
    isRunningEndingAnimation = true;
}







//--------------------------------------------------------------
void ofApp::setup(){
    
    animationIndex = 0;

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