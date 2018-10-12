#include "Attractor.h"



Attractor::Attractor()
{
}


Attractor::~Attractor()
{
}


void Attractor::setup(ofPoint _pos, float _radius, float _angle, float _vel) {
	pos = _pos;
	radius = _radius;
	angle = _angle;
	vel = _vel;

}

//--------------------------------------------------------------
void Attractor::update(float _updatedRadius) {

	radius = _updatedRadius;
	angle += vel;

	float x = radius * cos(angle);
	float y = radius * sin(angle);

	pos.set(ofGetWindowWidth() / 2 + x, ofGetWindowHeight() / 2 + y);

}

//--------------------------------------------------------------
void Attractor::draw() {
	ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), 98);
	ofDrawCircle(pos, 9);

}