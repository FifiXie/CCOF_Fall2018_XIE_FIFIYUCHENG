#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	serial.setup(0, 9600);
	serial.listDevices();
	if (serial.isInitialized()) {
		cout << "yes" << endl;

	}
	else {
		cout << "no" << endl;
	}


	ofBackground(0);
	ofSetFrameRate(27);
	ofEnableAlphaBlending();
	ofSetBackgroundAuto(false);
	ofSetCircleResolution(50);



	//dvsn.loadSound("OGHeartthrob.mp3");
	dvsn.loadSound("dis.mp3");
	dvsn.play();
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}

	bands = 64;
	dvsn.setLoop(true);

	incr = 27; 
	rad = -20;
	rad2 = -160;
	dist = 850;
	dist2 = 420;

	//fbo.allocate(2736, 1824, GL_RGBA);
	//fbo.begin();
	//ofClear(0, 0, 0, 0);
	//fbo.end();

	//fbo1.allocate(2736, 1824, GL_RGBA);
	//fbo1.begin();
	//ofClear(0, 0, 0, 0);
	//fbo1.end();

}

//--------------------------------------------------------------
void ofApp::update(){
	int resultax = serial.readBytes(&AccX[0], 6 );
	string resultaxs(AccX);
	int AX = ofToInt(resultaxs);

	//cout << "AX: " << AX << endl;

	int resultay = serial.readBytes(&AccY[0], 6);
	string resultays(AccY);
	int AY = ofToInt(resultays);

	//cout << "AY: " << AY << endl;

	int resultaz = serial.readBytes(&AccZ[0], 6);
	string resultazs(AccZ);
	int AZ = ofToInt(resultazs);

	//cout << "AZ: " << AZ << endl;

	int resultgx = serial.readBytes(&GyrX[0], 6);
	string resultgxs(GyrX);
	int GX = ofToInt(resultgxs);

	//cout << "GX: " << GX << endl;

	int resultgy = serial.readBytes(&GyrY[0], 6);
	string resultgys(GyrY);
	int GY = ofToInt(resultgys);

	//cout << "GY: " << GY << endl;

	int resultgz = serial.readBytes(&GyrZ[0], 6);
	string resultgzs(GyrZ);
	int GZ = ofToInt(resultgzs);

	//cout << "GZ: "<< GZ << endl;

	locx = ofClamp(AX, 0, 2500);
	cout << "Xunmap " << locx << endl;
	locx = ofMap(locx, 0, 2500, ofRandom(100,1900), ofGetWindowWidth()+100);
	cout << "Xmapped " << locx << endl;

	locy = ofClamp(AY, 0, 2500);
	locy = ofMap(locy, 0, 2500, ofRandom(100, 600), ofGetWindowHeight()+100);

	//locx = AX;
	//locy = AY;

	R = ofClamp(AZ, -40000, 40000);
	R= ofMap(AZ, -40000, 40000, 190, 255);
	
	G = ofClamp(GX, -40000, 40000);
	G = ofMap(G, -40000, 40000, 120, 165);

	B = ofClamp(GY, -40000, 40000);
	B = ofMap(B, -40000, 40000, 180, 255);

	A = ofClamp(GZ, -40000, 40000);
	A = ofMap(A, -40000, 40000, 120, 220);

	locx = sin(exp(cos(locx*0.8))) * 2 * locx;
	locy = sin(pow(8, (sin(locy)))) * locy;


	//float datanew = ofDegToRad(data);
	//float locxnew = sin(exp(cos(datanew*0.8))) * 2 * locx / 2;
	//float locynew = sin(pow(8, (sin(datanew)))) * locy;

	if (AX == -858993460||AY == -858993460) {
		locx = ofRandom(800, 1420);
		locy = ofRandom(200, 1200);
	}



	ofSoundUpdate();
	float * value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= 0.9f;
		if (fftSmooth[i] < value[i])
		{
			fftSmooth[i] = value[i];
		}
	}




}

//--------------------------------------------------------------
void ofApp::draw(){

	sec = ofGetElapsedTimef();
	
	//ofBeginSaveScreenAsPDF("screenshot4.pdf", false);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	//ofPushStyle();
	//ofSetColor(0, 0, 0, 5);
	//ofSetLineWidth(25);
	//ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	//ofPopStyle();
	//ofTranslate(ofGetMouseX(), ofGetMouseY());
	ofNoFill();
	//ofSetColor(ofRandom(10,25), ofRandom(20, 50), ofRandom(130, 150), 200);
	//ofSetColor(255);
	//ofSetColor(ofRandom(locx1-locy1,locx1+locy1), ofRandom(locx1,locy1), ofRandom(locy1, locx1),ofRandom(100,120));
	//ofSetLineWidth(ofRandom(0.5,0.9));
	//ofColor c = ofColor::fromHsb(R, G, ofRandom(A, B));
	//ofSetColor(c);
	ofSetColor(R, G, B, A);
	ofSetLineWidth(ofRandom(0.6, 0.9));
	//ofSetLineWidth(0.7);
	//fbo.begin();
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
	ofPushMatrix();
	ofTranslate(locx, locy);
	ofBeginShape();
	float xoff = 0;

	for (float i = 0; i < TWO_PI; i += 0.1)
	{
		float off = ofMap(ofNoise(xoff + yoff), 0, 1, -9, 9);
		r = r + off;
		float dx = b * cos(i);
		float dy = b * sin(i);
		float x = r * cos(i);
		float y = r * sin(i);
		ofVertex(x, y);
		//ofVertex(dx, dy);
		xoff += 0.21;

	}
	//ofEndShape();
	//for (float i = 0; i < TWO_PI; i += 0.1)
	//{
	//	float off = ofMap(ofNoise(xoff + yoff), 0, 1, -9, 9);
	//	float dx = b * cos(i);
	//	float dy = b * sin(i);
	//	ofVertex(dx, dy);
	//	ofVertex(dx, dy);
	//	xoff += 0.21;

	//}
	ofEndShape();
	yoff += 0.23;
	//ofPopMatrix();
	//glDisable(GL_BLEND);
	//fbo.end();
	
	ofPushStyle();
	ofFill();
	ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), ofRandom(60, 98));
	//ofSetLineWidth(25);
	//fbo1.begin();
	//ofPushMatrix();
	//ofTranslate(locx, locy);

	for (int v = 0; v < bands; v++) {
		b = -(fftSmooth[v] * ofRandom(1.8, 2.7));
		ofDrawCircle(0, 0, b);
	}
	ofPopStyle();
	ofDisableBlendMode();
	ofPopMatrix();



	
	rotateBy += .003;
	ofPushMatrix();
	ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	
	//ofPushStyle();
	//ofFill();
	//ofSetColor(0,0,0,100);
	//ofDrawCircle(0, 0, 480);
	//ofPopStyle();

	ofPushStyle();
	ofSetLineWidth(0.3);
	ofSetColor(ofRandom(0,255), 255, 255, 15);
	ofRotate(rotateBy);
	deg = 0;
	while (deg <= 360) {
		deg += incr;
		ang = ofDegToRad(deg);
		x = cos(ang) * (rad + (dist * ofNoise(y / 100, yIn)));
		y = sin(ang) * (rad + (dist * ofNoise(x / 80, yIn)));
		ofDrawCircle(x, y, 0.4, 0.4);
		x2 = sin(ang) * (rad2 + (dist2 * ofNoise(y2 / 72, yIn)));
		y2 = cos(ang) * (rad2 + (dist2 * ofNoise(y2 / 9, yIn)));
		ofDrawCircle(x2, y2, 0.9, 0.9);
	}
	yIn += .009;
	ofPopStyle();
	ofPopMatrix();


	
	//glEnable(GL_BLEND);
	//glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
	//ofSetLineWidth(ofRandom(0.2, 0.6));
	//fbo.draw(0, 0);
	//fbo1.draw(0, 0);
	//glDisable(GL_BLEND);


	
	




	int t = ofGetElapsedTimef();
	if (t % 36 == 0) {

		ofSetBackgroundAuto(true);
		ofSaveFrame();

	}
	else {
		ofSetBackgroundAuto(false);
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//if (key == 'x') {
	//	//ofSaveScreen("screenkey.png");
	//	img.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	//	img.save("screen.png");
	//}

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
