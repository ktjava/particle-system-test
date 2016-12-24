#include "ofApp.h"

ofApp::ofApp() :
	mousePosition(ofGetWidth()/2,ofGetHeight()/2),
	mouseLeftPressedFlag(false),
	mouseRightPressedFlag(false)
{

}

//--------------------------------------------------------------
void ofApp::setup(){
	  ofSetLogLevel(OF_LOG_VERBOSE);
	  ofSetWindowTitle("Particle System Test");
	  ofSetVerticalSync(true);
	  ofSetFrameRate(DRAW_FPS);
	  ofSetBackgroundAuto(false);
	  ofBackground(0,0,0);
	  for(int i=0; i<NODE_NUMBER; ++i){
		  particleSet[i] = new Particle(ofRandomWidth(), ofRandomHeight(), 0, 0, 1);
	  }
}

//--------------------------------------------------------------
void ofApp::update(){
	  for(int i=0; i<NODE_NUMBER; ++i){
		  particleSet[i]->update(mousePosition, mouseLeftPressedFlag, mouseRightPressedFlag);
	  }
}

//--------------------------------------------------------------
void ofApp::draw(){
	  ofColor c;
	  c.set(255,255,255,255);
  	  ofSetColor(c);
	  for(int i=0; i<NODE_NUMBER; ++i){
		  particleSet[i]->draw();
	  }
	  c.set(0,0,0,16);
  	  ofSetColor(c);
  	  ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	mousePosition.x = x, mousePosition.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	switch(button){
	case 0:
		mouseLeftPressedFlag = true;
		break;
	case 2:
		mouseRightPressedFlag = true;
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	switch(button){
	case 0:
		mouseLeftPressedFlag = false;
		break;
	case 2:
		mouseRightPressedFlag = false;
		break;
	default:
		break;
	}
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
