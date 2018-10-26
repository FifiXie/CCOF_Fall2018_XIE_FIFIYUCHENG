#include "Leaf.h"



Leaf::Leaf()
{
}


Leaf::~Leaf()
{
}


void Leaf::setup() {
	leafPos.set(ofRandom(80, ofGetWindowWidth()-80), ofRandom(80, ofGetWindowHeight() -225 ) );
	leafPosNew.set(ofRandom(80, ofGetWindowWidth() - 80), ofRandom(80, ofGetWindowHeight() - 225));
	
	angle = 1;
}


void Leaf::update() {

	/*if (angle > 0 && angle < 90) {
		newX = x + cos(angle) * 49;
		newY = y + 1;
		angle += ofDegToRad(1);
		ofPushMatrix();
		ofTranslate(newX, newY);
		ofPopMatrix();
	
	}
	else 	if (angle > 90) {
		newX = x + cos(-angle) * 80;
		newY = y+1;
		angle += ofDegToRad(1);
		ofPushMatrix();
		ofTranslate(newX, newY);
		ofPopMatrix();
	}*/
	
	/*for (int i = 0; i < ofGetWindowHeight(); i++)
	{
		newX = x * i;
		newY = (y + 2) * i;
		ofPushMatrix();
		ofTranslate(newX, newY, 0);
		ofPopMatrix();
	}*/

	if (angle > 0 && angle < 90) {
		leafPos.x = leafPos.x - cos(angle) * (ofRandom(0.6,0.9));
		leafPos.y +=0.8;
		leafPosNew.x = leafPosNew.x - cos(angle) * (ofRandom(1, 1.5));
		leafPosNew.y += 0.2;
		angle += ofDegToRad(1);
		checkEdges();

	}
	else 	if (angle > 90) {
		leafPos.x = leafPos.x - cos(-angle) * ofRandom(0.4,0.7);
		leafPos.y +=0.8;
		leafPosNew.x = leafPosNew.x - cos(angle) * (ofRandom(0.8, 1.2));
		leafPosNew.y += 0.2;
		angle += ofDegToRad(1);
		checkEdges();
	}


}


void Leaf::draw() {
	ofPushMatrix();
	ofTranslate(leafPos);
	ofRotateZDeg(ofRandom(-ofGetElapsedTimef()*0.5, ofGetElapsedTimef()*0.5));

	create();
	/*if (angle == 0) {
		ofPushMatrix();
		ofTranslate(leafPos.x,leafPos.y);
		ofRotateZDeg(ofRandom(25, 112));
		create();
		ofPopMatrix();
	}*/

	ofPopMatrix();
}

void Leaf::create() {
	//ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(80, 92));
	//ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	//ofBeginShape();
	//ofVertex(leafPos.x - 70, leafPos.y + 7.5);
	//ofVertex(leafPos.x - 37.5, leafPos.y - 7.5);
	//ofVertex(leafPos.x - 55, leafPos.y - 45);
	//ofVertex(leafPos.x - 15, leafPos.y - 22.5);
	//ofVertex(leafPos.x, leafPos.y - 70);
	//ofVertex(leafPos.x + 15, leafPos.y - 22.5);
	//ofVertex(leafPos.x + 55, leafPos.y - 45);
	//ofVertex(leafPos.x + 37.5, leafPos.y - 7.5);
	//ofVertex(leafPos.x + 70, leafPos.y + 7.5);
	//ofVertex(leafPos.x + 20, leafPos.y + 17.5);
	//ofVertex(leafPos.x + 27.5, leafPos.y + 30);
	//ofVertex(leafPos.x, leafPos.y + 20);
	//ofVertex(leafPos.x + 1, leafPos.y + 5);
	//ofVertex(leafPos.x + 3, leafPos.y + 75);
	//ofVertex(leafPos.x - 3, leafPos.y + 75);
	//ofVertex(leafPos.x - 1, leafPos.y + 5);
	//ofVertex(leafPos.x, leafPos.y + 20);
	//ofVertex(leafPos.x - 27.5, leafPos.y + 30);
	//ofVertex(leafPos.x - 20, leafPos.y + 17.5);
	//ofVertex(leafPos.x - 70, leafPos.y + 7.5);
	//ofEndShape();

	ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(80, 92));
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofVertex( - 70,  7.5);
	ofVertex(0 - 37.5, 0 - 7.5);
	ofVertex(0 - 55, 0 - 45);
	ofVertex(0 - 15, 0 - 22.5);
	ofVertex(0, 0 - 70);
	ofVertex( 15, 0 - 22.5);
	ofVertex(55, 0 - 45);
	ofVertex( 37.5, 0 - 7.5);
	ofVertex(70, 0 + 7.5);
	ofVertex( 20, 0 + 17.5);
	ofVertex( 27.5, 0 + 30);
	ofVertex(0, 0 + 20);
	ofVertex( 1, 0 + 5);
	ofVertex(3, 0 + 75);
	ofVertex(0 - 3, 0+ 75);
	ofVertex(0 - 1, 0 + 5);
	ofVertex(0, 0 + 20);
	ofVertex(0 - 27.5, 0 + 30);
	ofVertex(0 - 20, 0 + 17.5);
	ofVertex(0 - 70, 0 + 7.5);
	ofEndShape();

	/*ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(99, 100));
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofVertex(leafPosNew.x - 47, leafPosNew.y + 5);
	ofVertex(leafPosNew.x - 25, leafPosNew.y - 5);
	ofVertex(leafPosNew.x - 37, leafPosNew.y - 30);
	ofVertex(leafPosNew.x - 10, leafPosNew.y - 15);
	ofVertex(leafPosNew.x, leafPosNew.y - 47);
	ofVertex(leafPosNew.x + 10, leafPosNew.y - 15);
	ofVertex(leafPosNew.x + 37, leafPosNew.y - 30);
	ofVertex(leafPosNew.x + 25, leafPosNew.y - 5);
	ofVertex(leafPosNew.x + 47, leafPosNew.y + 5);
	ofVertex(leafPosNew.x + 13, leafPosNew.y + 12);
	ofVertex(leafPosNew.x + 18, leafPosNew.y + 20);
	ofVertex(leafPosNew.x, leafPosNew.y + 13);
	ofVertex(leafPosNew.x + 1, leafPosNew.y + 5);
	ofVertex(leafPosNew.x + 1.5, leafPosNew.y + 50);
	ofVertex(leafPosNew.x - 1.5, leafPosNew.y + 50);
	ofVertex(leafPosNew.x - 1, leafPosNew.y + 5);
	ofVertex(leafPosNew.x, leafPosNew.y + 13);
	ofVertex(leafPosNew.x - 18, leafPosNew.y + 20);
	ofVertex(leafPosNew.x - 13, leafPosNew.y + 12);
	ofVertex(leafPosNew.x - 47, leafPosNew.y + 5);
	ofEndShape();*/

	ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(99, 100));
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofVertex(0 - 47, 0 + 5);
	ofVertex(0 - 25, 0 - 5);
	ofVertex(0 - 37, 0 - 30);
	ofVertex(0 - 10,0- 15);
	ofVertex(0, 0- 47);
	ofVertex(0+ 10, 0- 15);
	ofVertex(0+ 37, 0- 30);
	ofVertex(0 + 25, 0 - 5);
	ofVertex(0 + 47, 0 + 5);
	ofVertex(0 + 13, 0+ 12);
	ofVertex(0 + 18, 0 + 20);
	ofVertex(0, 0 + 13);
	ofVertex(0 + 1, 0 + 5);
	ofVertex(0 + 1.5, 0 + 50);
	ofVertex(0 - 1.5, 0 + 50);
	ofVertex(0 - 1, 0+ 5);
	ofVertex(0, 0 + 13);
	ofVertex(0 - 18, 0 + 20);
	ofVertex(0 - 13, 0 + 12);
	ofVertex(0 - 47, 0 + 5);
	ofEndShape();

	/*ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(99, 100));
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofVertex(ofRandom(90,180) - 47, ofRandom(90, 180) + 5);
	ofVertex(ofRandom(90, 180) - 25, ofRandom(90, 180) - 5);
	ofVertex(ofRandom(90, 180) - 37, ofRandom(90, 180) - 30);
	ofVertex(ofRandom(90, 180) - 10, ofRandom(90, 180) - 15);
	ofVertex(ofRandom(90, 180), ofRandom(90, 180) - 47);
	ofVertex(ofRandom(90, 180) + 10, ofRandom(90, 180) - 15);
	ofVertex(ofRandom(90, 180) + 37, ofRandom(90, 180) - 30);
	ofVertex(ofRandom(90, 180) + 25, ofRandom(90, 180) - 5);
	ofVertex(ofRandom(90, 180) + 47, ofRandom(90, 180) + 5);
	ofVertex(ofRandom(90, 180) + 13, ofRandom(90, 180) + 12);
	ofVertex(ofRandom(90, 180) + 18, ofRandom(90, 180) + 20);
	ofVertex(ofRandom(90, 180), ofRandom(90, 180) + 13);
	ofVertex(ofRandom(90, 180) + 1, ofRandom(90, 180) + 5);
	ofVertex(ofRandom(90, 180) + 1.5, ofRandom(90, 180) + 50);
	ofVertex(ofRandom(90, 180) - 1.5, ofRandom(90, 180) + 50);
	ofVertex(ofRandom(90, 180) - 1, ofRandom(90, 180) + 5);
	ofVertex(ofRandom(90, 180), ofRandom(90, 180) + 13);
	ofVertex(ofRandom(90, 180) - 18, ofRandom(90, 180) + 20);
	ofVertex(ofRandom(90, 180) - 13, ofRandom(90, 180) + 12);
	ofVertex(ofRandom(90, 180) - 47, ofRandom(90, 180) + 5);
	ofEndShape();*/

}


void Leaf::checkEdges() {

	if (leafPos.y >= ofGetWindowHeight()-75) {
		leafPos.y = ofGetWindowHeight() - 75;
		angle = 0;
		
	}

	if (leafPosNew.y >= ofGetWindowWidth() - 50) {
		leafPosNew.y = ofGetWindowHeight() - 50;
		angle = 0;
	}

}