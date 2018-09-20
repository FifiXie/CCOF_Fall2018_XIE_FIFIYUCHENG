#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	ofSetWindowShape(1500, 1300);
	gui.add(soundOn.setup("Sound On"," "));
	gui.add(sinParam.set("Toggle for X Position", 0.0, 0.0, 359.0));
	gui.add(cosParam.set("Toggle for Y Position", 0.0, 0.0, 359.0));

	ofSetBackgroundColor(0);
	dvsn.loadSound("OGHeartthrob.mp3");
	dvsn.play();
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}

	bands = 64;
	t = 10;
	origin = ofPoint(0, 0, 0);
	objectPos = origin;
		dvsn.setLoop(true);

}

//--------------------------------------------------------------
void ofApp::update(){
	t += 10;
	hori = sin(t)*sinParam;
	verti = cos(t)*cosParam;

	ofSoundUpdate();
	float * value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= 0.9f;
		if (fftSmooth[i] < value[i])
		{
			fftSmooth[i] = value[i];
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(75, 98));
	for (int i = 0; i < bands; i++)
	{
		ofCircle(hori, verti, -(fftSmooth[i] * 100));
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
