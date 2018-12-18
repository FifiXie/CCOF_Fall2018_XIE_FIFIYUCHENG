#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	ofBackground(0);
	for (int i = 0; i < TOTALNUM; i++) {
		Particles p;
		p.setup();
		particle.push_back(p);
	}
	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < TOTALNUM; i++) {
		particle[i].update();
	}

	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushStyle();
	ofSetColor(0, 0, 0, 10);
	ofDrawRectangle(0,0,2600, 1734);
	ofPopStyle();
	for (int i = 0; i < TOTALNUM; i++) {
		particle[i].draw();
	}
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
