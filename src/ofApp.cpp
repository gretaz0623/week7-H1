#include "ofApp.h"
ofFbo fbo;
float x,y,z;

void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    p0 = ofPoint(-20, 0);
    p1 = ofPoint( 20, 0);
    sTime = ofGetElapsedTimef();
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();

}
float rX = 0;
float rY = 0;
float rZ = 0;


//--------------------------------------------------------------
void ofApp::update(){
    float time = sTime + ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.3) * 360.0;
    rY = ofSignedNoise(time * 0.5) * 360.0;
    rZ = ofSignedNoise(time * 0.7) * 360.0;
    
    x = ofMap(ofSignedNoise(time * 0.2), -20, 20, 0, ofGetWidth());
    y = ofMap(ofSignedNoise(time * 0.4), -20, 20, 0,ofGetHeight()) ;
    z = ofSignedNoise(time * 0.6 )* 360;
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
        ofPushStyle();
        ofSetColor(0,0,0,2);
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
        ofPopStyle();
    
    ofPushMatrix();

        ofTranslate(x, y, z);
        ofScale(10,10,10);
        ofRotateX(rX);
        ofRotateY(rY);
        ofRotateZ(rZ);

    ofSetColor(255,20,147,200);
    ofDrawLine(p0,p1);
    ofPopMatrix();
    
    fbo.end();
    
    fbo.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
