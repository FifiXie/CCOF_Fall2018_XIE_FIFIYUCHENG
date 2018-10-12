#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofEnableSmoothing();
	ofSetCircleResolution(50);

	radius = 100;

	rMin = 5;
	rMax = 400;

	for (int i = 0; i < SEGMENT; i++)
	{
		//360/SEGMENT - 90
		float angle = ofDegToRad((360 / SEGMENT)*i);
		float x = radius * cos(angle);
		float y = radius * sin(angle);

		Attractor a;
		a.setup(ofPoint(ofGetWindowWidth() / 2 + x, ofGetWindowHeight() / 2 + y), radius, angle, 0.01);
		attractors.push_back(a);

		for (int i = 0; i < TOTALNUM; i++) {
			int randomInt;
			randomInt = (int)ofRandom(0, SEGMENT);
			Particles p;
			p.init();
			p.groupId = randomInt;
			particles.push_back(p);
		}

	}

}

//--------------------------------------------------------------
void ofApp::update() {

	//radius += 1;


	if (rPct > 1) {
		rPct = 1;
		rPctVel *= -1;
	}

	if (rPct < 0) {
		rPct = 0;
		rPctVel *= -1;
	}


	rPct += rPctVel;
	float rPctOut = powf(rPct, 3);
	radius = (1 - rPctOut) * rMin + rPctOut * rMax;



	for (int i = 0; i < attractors.size(); i++)
	{
		attractors[i].update(radius);
	}




	for (int i = 0; i < particles.size(); i++)
	{
		int index = particles[i].groupId;
		particles[i].updateParticles(attractors[index].pos);
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < attractors.size(); i++)
	{
		attractors[i].draw();
	}
	
	for (int i = 0; i < particles.size(); i++) {
		particles[i].drawParticles();
	}
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
