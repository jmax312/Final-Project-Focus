#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
		

//--------Stuff for the shapes------
		ofxVectorGraphics output; //using the addon? (the addon example and definition don't make it clear what this does)
		
		int numSteps, numSteps2, numSteps3, numSteps4, numSteps5, numSteps6, numSteps7, numSteps8, numSteps9, numSteps10; //used for number of sides of shapes
		float angle; //used in building and spinning shapes
		float radius;  //radius of shapes
		float step; //spins the shapes
		float cenX, cenX2, cenX3, cenX4, cenX5, cenX6, cenX7, cenX8, cenX9, cenX10; //x values of center points of shapes
		float cenY, cenY2, cenY3, cenY4, cenY5, cenY6, cenY7, cenY8, cenY9, cenY10; //y values of center points of shapes
		ofVec2f pos, pos2, pos3; //will be used for placing choices during quizzes
		int posd; //used for determining positions during quiz (to randomize them)

		bool sh1, sh2, sh3, sh4, sh5, sh6, sh7, sh8, sh9, sh10; //bools for showing shapes before their quiz
		bool q1, q2, q3, q4, q5, q6, q7, q8, q9, q10; //bools for showing the quizzes
		float show1, show2, show3, show4, show5, show6, show7, show8, show9, show10; //timers for memorization times

//-----Stuff for the camera------
		ofVideoGrabber cam; //using the computer's camera
		ofxCv::ObjectFinder finder; //finds the face

		float gameplay, focus; //timers for how long the game has been played, and for how long you have been looking at the camera
		int lastface; //used for resetting the focus timer

//-----Stuff for game play/misc------
		int score; //points scored
		float fbonus; //score bonus for focusing
		bool end, stop; //used to end game or stop quizzes
		ofTrueTypeFont	font, ffont; //font for bitmap strings (ffont is for final score)
		ofColor c1, c2; //colors for bg gradient
		
};
