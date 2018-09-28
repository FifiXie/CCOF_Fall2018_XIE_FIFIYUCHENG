#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableSmoothing();
	ofSetWindowShape(1500, 1300);
	ofSetCircleResolution(80);
	Center0.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	Center1.set(ofGetWindowWidth() / 3, ofGetWindowHeight() * 2 / 3);
	Center2.set(ofGetWindowWidth() * 2 / 3, ofGetWindowHeight() / 3);
	Center3.set(ofGetWindowWidth() * 3 / 5, ofGetWindowHeight() / 4);
	angle = 1;

}

//--------------------------------------------------------------
void ofApp::update(){

		pos1[TRICIRCLE].x = Center0.x + cos(angle*5) * 60 ;
		pos1[TRICIRCLE].y = Center0.y + sin(angle*5) * 60;

		pos2[TRICIRCLE].x = Center1.x + cos(angle) * 180;
		pos2[TRICIRCLE].y = Center1.y + sin(angle) * 180;

		pos3[TRICIRCLE].x = Center2.x + cos(-(angle+45)) * 30;
		pos3[TRICIRCLE].y = Center2.y + sin(-(angle+45)) * 30;

		pos4[TRICIRCLE].x = Center3.x + cos(-angle*2) * 80;
		pos4[TRICIRCLE].y = Center3.y + sin(-angle*2) * 40;

		angle += ofDegToRad(1);
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	for (int i = 9; i >= TRICIRCLE; i--) {
		ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(98, 100));
		ofDrawCircle(pos1[i], 27);
		ofDrawCircle(pos2[i], 36);
		ofDrawCircle(pos3[i], 45);
		ofDrawCircle(pos4[i], 21);

	}

	for (int i = 9; i >= TRICIRCLE; i--) {
		ofSetColor(ofRandom(105, 185), ofRandom(100, 150), ofRandom(220, 255), 99);
		ofDrawCircle(pos1[i]-181, 9);
		ofDrawCircle(pos2[i]+120, 40);
		ofDrawCircle(pos3[i]+90, 18);
		ofDrawCircle(pos4[i]+180, 25);

	}

	for (int i = 9; i >= TRICIRCLE; i--) {
		ofSetColor(ofRandom(0, 255), ofRandom(185, 255), ofRandom(185, 255), ofRandom(75, 80));
		ofDrawCircle(pos1[i]+181, ofRandom(9,36));
		ofDrawCircle(pos2[i]-90, ofRandom(9, 36));
		ofDrawCircle(pos3[i]+127, ofRandom(9, 36));
		ofDrawCircle(pos4[i]-100, ofRandom(9, 36));

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
