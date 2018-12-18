#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255);
	ofSetFrameRate(12);
	ofEnableAlphaBlending();
	ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//ofSetColor(0);
	//ofDrawCircle(100,100,50,50);

	ofPushMatrix();
	ofTranslate(ofGetMouseX(), ofGetMouseY());
	//ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofNoFill();
	//ofSetColor(ofRandom(110,125), ofRandom(20, 50), ofRandom(130, 150), 200);
	//ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(198, 200));
	//ofSetColor(255,0,0);
    ofSetColor(ofRandom(100, 155), ofRandom(40, 90), ofRandom(190, 255), 200);
	//ofSetColor(238, 50, 37);
	ofSetLineWidth(ofRandom(0.6, 0.9));
	//ofSetLineWidth(1);
	ofBeginShape();
	float xoff = 0;

	for (float i = 0; i <TWO_PI; i += 0.1)
	{
		float off = ofMap(ofNoise(xoff + yoff), 0, 1, -7, 7);
		r = r + off;
		float x = r * cos(i);
		float y = r * sin(i);
		ofVertex(x, y);
		xoff += 0.21;

	}
	ofEndShape();
	yoff += 0.21;

	//ofPushStyle();
	////ofFill();
	//ofSetLineWidth(0.4);
	//ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), 20);
	//for (int v = 0; v < 86; v++) {
	//	float b = ofRandom(1.8, 5.4);
	//	ofDrawCircle(-18,9, b);
	//}
	//ofPopStyle();
	ofDisableBlendMode();
	ofPopMatrix();
	//yoff += 0.23;


	//ofSaveFrame();

	int t = ofGetElapsedTimef();
	if (t %63 ==0) {
		
		ofSetBackgroundAuto(true);
		ofSaveFrame();
		//ofBeginSaveScreenAsPDF("screenshot4.pdf", false);
		
	}
	else {
		ofSetBackgroundAuto(false);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){



	

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'x') {
		//ofSaveScreen("screenkey.png");

		//img.save("screengrab1.png");

		ofSaveFrame();

	}
	else {
		ofSetBackgroundAuto(false);
	}
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
