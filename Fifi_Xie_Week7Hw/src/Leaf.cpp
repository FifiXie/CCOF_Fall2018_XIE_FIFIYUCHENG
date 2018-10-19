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

}

void Leaf::update()
{
	
	
	leafPos.y += 0.6;

	if (angle > 0 && angle < 90) {
		leafPosNew.x = leafPos.x + cos(angle)*49;
		leafPosNew.y = leafPos.y;
		angle += ofDegToRad(1);
		checkEdges();
	} else 	if (angle > 90) {
		leafPosNew.x = leafPos.x + cos(-angle) * 49;
		leafPosNew.y =leafPos.y;
		angle += ofDegToRad(1);
		checkEdges();
	}
}

void Leaf::draw()
{
	ofSetColor(7, 108, 49);

			ofDrawEllipse(leafPosNew, 49, 81);

	

}

void Leaf::checkEdges() {
	
	if (leafPosNew.y >= ofGetWindowHeight() - 40.5) {
		leafPosNew.y = ofGetWindowHeight() - 40.5;
		angle = 0;
	}

}