#pragma once

#include "ofMain.h"

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
		
		float yoff = 0;
		float r;
		float b;
		ofSerial serial;
		int sec;
		
		char AccX[9];
		char AccY[9];
		char AccZ[9];
		char GyrX[9];
		char GyrY[9];
		char GyrZ[9];
		
		float locx;
		float locy;


		float x, y, x2, y2, rad, rad2, dist, dist2;
		float deg, incr, yIn, rotateBy, ang;



	 
		int R;
		int G;
		int B;
		int A;

		ofImage img;

		float hori;
		float verti;

		ofSoundPlayer dvsn;
		float * fftSmooth;
		int bands;

		ofFbo fbo;
		ofFbo fbo1;

};
