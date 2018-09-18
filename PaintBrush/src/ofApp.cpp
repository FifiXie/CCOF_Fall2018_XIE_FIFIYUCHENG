#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1500, 1300);
	ofSetBackgroundColor(0);
	// Don't Clear the Background
	ofSetBackgroundAuto(false);
	counter = 0;
	//cout << "hi" << endl;
	//cout << counter << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//if there are more than x circles on the canvas, stop  here
	if (counter >= 10000) return;
	if (!ofGetMousePressed()) return;
	float radius = 20;
	//float w = ofGetWindowWidth();
	//float h = ofGetWindowHeight();

	ofPushMatrix();
   //ofTranslate(w / 2, h / 2);
		ofTranslate(ofGetMouseX(), ofGetMouseY());


		for (int i = 0; i < 15; i++)
		{
			//cout <<"The current Value of i:" << i << endl;
			float posX;
			//posX = ofRandom(w / 2 - radius, w / 2 + radius);
			posX = ofRandom(-radius, radius);
			float posY;
			//posY = ofRandom(h/2 -radius, h/2 +radius);
			posY = ofRandom(-radius, radius);

		//distance between the drawn dots and the center
		
			float distance = ofDist(posX, posY,0,0);
			//check is the radius is bigger the distance	
			if (distance < radius) {
				ofSetColor(ofRandom(175,255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(60,98));
				float size = ofRandom(5, 15);

				cout << "am i here" << endl;
				ofDrawCircle(posX, posY, size);
				counter++;
				//cout << "The current Value of counter:" << counter << endl;
			}
	}
		
		
		ofPopMatrix();
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
