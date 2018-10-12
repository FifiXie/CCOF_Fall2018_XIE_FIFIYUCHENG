#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(1500, 1300);
	ofSetBackgroundColor(0);
	ofSetBackgroundAuto(false);
	ofSetCircleResolution(80);
	Center.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	pos[GROUP].x = ofRandom(-radius, radius);
	pos[GROUP].y = ofRandom(-radius, radius);
}

//--------------------------------------------------------------
void ofApp::update() {

	newpos.x = pos[GROUP].x + cos(angle) * 60;
	newpos.y = pos[GROUP].y + sin(angle) * 60;

	angle += ofDegToRad(1);

}

//--------------------------------------------------------------
void ofApp::draw() {



	for (int i = 27; i >= GROUP; i--)
	{

		//float distance = ofDist(newpos.x, newpos.y, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
		//if (distance < radius) {
		ofPushMatrix();
		ofTranslate(ofGetMouseX(), ofGetMouseY());
		ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(60, 98));
		size = ofRandom(5, 15);
		ofDrawCircle(newpos.x, newpos.y, size);
		//}

	}
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
