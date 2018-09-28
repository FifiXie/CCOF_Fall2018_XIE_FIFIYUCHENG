#pragma once

#include "ofMain.h"
#define TRICIRCLE 9

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		
		ofPoint pos1[TRICIRCLE];
		ofPoint pos2[TRICIRCLE];
		ofPoint pos3[TRICIRCLE];
		ofPoint pos4[TRICIRCLE];
		float distance[TRICIRCLE];
		ofPoint Center0;
		ofPoint Center1;
		ofPoint Center2;
		ofPoint Center3;
		float radius[TRICIRCLE];
		float angle = 0;
};
