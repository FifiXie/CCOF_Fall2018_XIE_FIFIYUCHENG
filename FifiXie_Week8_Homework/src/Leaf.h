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

	void create();
	void checkEdges();

	ofPoint leafPos;
	ofPoint leafPosNew;
	float x;
	float y;
	float angle;
};

