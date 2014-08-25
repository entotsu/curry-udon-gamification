#include "ofApp.h"






void ofApp::hit(int score, float x, float y){
    
    hits[animationIndex].start(score, x, y);
    
    //アニメ−ションさせる要素をずらしていく
    if (++animationIndex == MAX_ANIMATION) animationIndex = 0;
}









//--------------------------------------------------------------
void ofApp::setup(){
    
    animationIndex = 0;

    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < MAX_ANIMATION; i++) {
        hits[i].draw();
    }
    
    ofSetColor(0, 0, 0, 255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    float posX = ofRandom(ofGetWidth());
    float posY = ofRandom(ofGetHeight());
    int score = ofRandom(999);
    hit(score, posX, posY);
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
