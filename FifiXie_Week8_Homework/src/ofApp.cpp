#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableSmoothing();
	ofSetCircleResolution(50);
	//ofSetBackgroundAuto(false);

	for (int i = 0; i < TOTALNUM; i++)
	{
		Leaf leaf;
		leaf.setup();
		leaves.push_back(leaf);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < TOTALNUM; i++)
	{

		leaves[i].update();

	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < TOTALNUM; i++)
	{
		leaves[i].draw();
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
