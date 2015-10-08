#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;

    
    webCam.setDeviceID(0);
    cout << webCam.getWidth() << endl;
    webCam.setup(1280, 720);
    
    liveVideoFbo.allocate(webCam.getWidth(), webCam.getHeight());
    
    glitchEffect.setup(&liveVideoFbo);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    webCam.update();
    
    liveVideoFbo.begin();
    ofColor(0,255);
    webCam.setAnchorPercent(0.5, 0);
    webCam.draw(0, 0);
    
    liveVideoFbo.end();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    webCam.setAnchorPercent(0, 0);
    webCam.draw(0, 0);
    glitchEffect.generateFx();
    liveVideoFbo.draw(640, 0);

    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    
    baseArch.guideFrames( ofColor(0) );
    baseArch.drawEdgeCover( ofColor(0) );
    baseArch.guideLines();
    baseArch.guidePoints();
    
    ofPopMatrix();

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == '1') glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') glitchEffect.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') glitchEffect.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') glitchEffect.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == '6') glitchEffect.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == '7') glitchEffect.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') glitchEffect.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') glitchEffect.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'q') glitchEffect.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == '1') glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') glitchEffect.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') glitchEffect.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') glitchEffect.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == '6') glitchEffect.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == '7') glitchEffect.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') glitchEffect.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') glitchEffect.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'q') glitchEffect.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);

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

    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;

    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
