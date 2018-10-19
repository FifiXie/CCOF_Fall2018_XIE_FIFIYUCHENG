#pragma once

#include "ofMain.h"

class Leaf
{
public:
	Leaf();
	~Leaf();

	void setup();
	void update();
	void draw();
	void checkEdges();

	ofPoint leafPos;
	float angle = 1;
	ofPoint leafPosNew;
	ofPoint vel;
	float mass; 
};

