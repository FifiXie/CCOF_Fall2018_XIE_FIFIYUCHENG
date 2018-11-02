#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bg.load("images/bg.jpg");


	for (int i = 0; i < TOTALNUM; i++) {
		Crowds c;
		c.setup();
		crowds.push_back(c);
	}
	
	person.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	ofPoint attractor;
	attractor.set(mouseX, mouseY);
	for (int i = 0; i < crowds.size(); i++){
		crowds[i].update(attractor);
	}

	person.steeringWithArriveForce(ofPoint(mouseX, mouseY));
	person.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(225, 225, 225, 255);
	bg.draw(0, 0);
	person.draw();

	for (int i = 0; i < crowds.size(); i++) {

		crowds[i].draw();
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
