#include "Leaf.h"



Leaf::Leaf()
{
}


Leaf::~Leaf()
{
}


void Leaf::setup()
{
	leafPos.set(ofRandom(ofGetWindowWidth() / 3,  ofGetWindowWidth()* 2 / 3), ofRandom(ofGetWindowHeight()/3, ofRandom(ofGetWindowHeight() *2 / 3)));
	mass = ofRandom(80, 120);
}

void Leaf::update()
{
	
	
	leafPos.y += mass/100;

	if (angle > 0 && angle < 90) {
		leafPosNew.x = leafPos.x + cos(angle)*49;
		leafPosNew.y = leafPos.y;
		angle += ofDegToRad(1);
		checkEdges();
	} else 	if (angle > 90) {
		leafPosNew.x = leafPos.x + cos(-angle) * 80;
		leafPosNew.y =leafPos.y;
		angle += ofDegToRad(1);
		checkEdges();
	}
}

void Leaf::draw()
{
	ofSetColor(7, 108, 49,98);

			ofDrawEllipse(leafPosNew, 60, mass);

	

}

void Leaf::checkEdges() {
	
	if (leafPosNew.y >= ofGetWindowHeight() - 40.5) {
		leafPosNew.y = ofGetWindowHeight() - 40.5;
		angle = 0;
	}

}