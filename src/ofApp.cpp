#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofBackground(ofColor::black);
		fontNumber.loadFont("digital-7_mono.ttf", 12);
		fontLove.loadFont("MyriadPro-Bold.otf", 240);
		getImage = false;
		textOne = "DIGITAL";
		textTwo = "LOVE";
		ofSetFrameRate(1);
		ofSetFullscreen(true);
		ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
//		ofLogNotice("0W:"+ofToString(fontNumber.stringWidth("0")));
//		ofLogNotice("1W:"+ofToString(fontNumber.stringWidth("1")));
//		ofLogNotice("0H:"+ofToString(fontNumber.stringHeight("0")));
//		ofLogNotice("1H:"+ofToString(fontNumber.stringHeight("1")));
}

//--------------------------------------------------------------
void ofApp::draw(){
		if (!getImage) {
				ofPushStyle();
				ofSetColor(ofColor::white);
				ofRectangle rectangle = fontLove.getStringBoundingBox(textOne, (ofGetWidth()-fontLove.stringWidth(textOne))*0.5, (ofGetHeight()+fontLove.stringHeight("LOVE")-fontLove.stringHeight("LOVE"))*0.5);
				float margin = ofGetHeight()*0.05;
				fontLove.drawString(textOne, (ofGetWidth()-fontLove.stringWidth(textOne))*0.5, ofGetHeight()*0.5-margin);
				fontLove.drawString(textTwo, (ofGetWidth()-fontLove.stringWidth(textTwo))*0.5, ofGetHeight()*0.5+fontLove.stringHeight(textTwo)+margin);
				textImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
				getImage = true;
				ofPopStyle();				
		}
		
		ofPushStyle();
		ofSetColor(ofColor::black);
		
		// 0
		for (int i=0; i<50000; i++) {
				// ofPoint point(ofRandom(fontNumber.stringWidth("0"), ofGetWidth()), ofRandom(-fontNumber.stringHeight("0"), ofGetHeight()+fontNumber.stringHeight("0")));
				ofPoint point(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
				if (textImage.getColor(point.x , point.y).r == 255) {
						// LOVEの中
//						ofSetColor(ofColor::black);
				}else{
						// LOVEの外
						ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
						fontNumber.drawString("0", point.x, point.y);
				}
//				fontNumber.drawString("0", point.x, point.y);
		}
		
		// 1
		for (int i=0; i<50000; i++) {
				ofPoint point(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
				if (textImage.getColor(point.x , point.y).r == 255) {
						// LOVEの中
//						ofSetColor(ofColor::black);
				}else{
						// LOVEの外
						ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
						fontNumber.drawString("1", point.x, point.y);
				}
//				fontNumber.drawString("1", point.x, point.y);
		}
				
				
//				fontNumber.drawString("0", ofRandom(fontNumber.stringWidth("0"), ofGetWidth()), ofRandom(-fontNumber.stringHeight("1"), ofGetHeight()+fontNumber.stringHeight("1")));
		
//		ofSetColor(ofColor::white);
//		fontLove.drawString(text, (ofGetWidth()-fontLove.stringWidth(text))*0.5, (ofGetHeight()+fontLove.stringHeight(text))*0.5);
//		
//		for (int i=0; i<5000; i++) {
//				fontNumber.drawString("1", ofRandom(fontNumber.stringWidth("1"), ofGetWidth()), ofRandom(-fontNumber.stringHeight("0"), ofGetHeight()+fontNumber.stringHeight("0")));
//				fontNumber.drawString("0", ofRandom(fontNumber.stringWidth("0"), ofGetWidth()), ofRandom(-fontNumber.stringHeight("1"), ofGetHeight()+fontNumber.stringHeight("1")));
//		}
		
		
		//debug
//		ofPopStyle();
//		textImage.draw(0,0,ofGetWidth(), ofGetHeight());
//		
//		ofPushStyle();
//		ofSetColor(ofColor::red);
//		ofLine(ofGetWidth()/2.0, 0, ofGetWidth()/2.0, ofGetHeight());
//		ofLine(0, ofGetHeight()/2.0, ofGetWidth(), ofGetHeight()/2.0);
//		ofNoFill();
//		ofSetLineWidth(1);
//		ofRect(fontLove.getStringBoundingBox(text, (ofGetWidth()-fontLove.stringWidth(text))*0.5, (ofGetHeight()+fontLove.stringHeight("LOVE")-fontLove.stringHeight("LOVE"))*0.5));
		ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
		switch (key) {
				case 'f':
						ofToggleFullscreen();
						break;
				case 'c':{
						ofImage image;
						image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
						//キャプチャーした画像データを「grabbedImage.png」で保存
						image.saveImage(ofGetTimestampString()+"_grabbedImage.png");
						break;
				}
				default:
						break;
		}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
