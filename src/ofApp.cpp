#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){

	c1.set(105, 155, 245); //for background gradient
	c2.set(24, 86, 199);

	score = 0; //number of right answers chosen
	end = false; //ends the game after a set time
	stop = false; //stops the shapes being drawn if the quizzes end before the timer

	ofTrueTypeFont::setGlobalDpi(72); //keeps font from being too big
	font.loadFont("verdana.ttf", 18, true, true); //font for timers, score, etc
	ffont.loadFont("verdana.ttf", 26, true, true); //for final score only

//----Camera stuff----
	ofSetVerticalSync(true); //this is so our picture refreshes with the monitor so parts don't lag behind
	ofSetFrameRate(120);
	finder.setup("haarcascade_frontalface_alt2.xml"); //this is a code that tells the program how to find a face 

	finder.setPreset(ObjectFinder::Fast); //this is how specific it will be in finding those faces
	finder.getTracker().setSmoothingRate(.3);
	cam.initGrabber(640, 480);

	lastface = 0; //used when seeing if the face has looked away
	focus = 0;  //increases the longer you look at the screen

//---Shapes stuff----
	show1 = 0; //sets timers
	show2 = 0;
	show3 = 0;
	show4 = 0;
	show5 = 0;
	show6 = 0;
	show7 = 0;
	show8 = 0;
	show9 = 0;
	show10 = 0;

	numSteps = ofRandom(3, 5); //these pick out the number of sides the shapes will have during the game

	numSteps2 = ofRandom(6, 8);

	numSteps3 = ofRandom(10, 13);

	numSteps4 = ofRandom(5, 8);

	numSteps5 = ofRandom(9, 15);

	numSteps6 = ofRandom(21, 28);

	numSteps7 = ofRandom(15, 19);

	numSteps8 = ofRandom(27, 32);

	numSteps9 = ofRandom(8, 11);

	numSteps10 = ofRandom(25, 30);
	
	sh1 = true; //bools for showing shapes for memorization
	sh2 = false;
	sh3 = false;
	sh4 = false;
	sh5 = false;
	sh6 = false;
	sh7 = false;
	sh8 = false;
	sh9 = false;
	sh10 = false;

	q1 = false; //bools for showing quizzes
	q2 = false;
	q3 = false;
	q4 = false;
	q5 = false;
	q6 = false;
	q7 = false;
	q8 = false;
	q9 = false;
	q10 = false;

}

//--------------------------------------------------------------
void ofApp::update(){

		gameplay = ofGetElapsedTimef();
		if (gameplay >= 60) end = true; //limits game to 1 min

//----Camera Stuff------
		cam.update();
	if(cam.isFrameNew()) { //if the image from the camera has changed (like when the face moves), update it
		finder.update(cam);
	}

//-----Shapes Stuff-----
	if(sh1 == true){ //shows only the first shape for a few seconds
		for (int i = 0; i < gameplay; i++){
			show1+=0.01;
		}
		radius = 100; //radius when showing the shape
		cenX = 500; //x value of first shape center point
		cenY = 300; //y value of first shape center point
		posd = ofRandom(1, 4); //determing which position the quiz answers will be in (see near end of update)

	}
	if(gameplay >= 5){ //shows the first quiz
		sh1 = false;
		q1 = true;

	}
	if (q1 == true){
		radius = 80; //radius during quizzes
		cenX = pos.x; //x value of first shape cp during 1st quiz
		cenY = pos.y; //y value of first shape cp during 1st quiz
		cenX5 = pos2.x; //x value of fifth shape cp during 1st quiz (wrong answer)
		cenY5 = pos2.y; //y value of fifth shape cp during 1st quiz (wrong answer)
		cenX7 = pos3.x; //x value of seventh shape cp during 1st quiz (wrong answer)
		cenY7 = pos3.y; //y value of seventh shape cp during 1st quiz (wrong answer)
	}

	if(sh2 == true){ 
		for (int i = 0; i < gameplay; i++){
			show2+=0.01;
		}
		radius = 100;
		cenX2 = 500; 
		cenY2 = 300;
		posd = ofRandom(1, 4);
		q1 = false; //ends previous quiz 

	}
	if(show2 >= 5){ 
		sh2 = false;
		q2 = true;
	}
	if (q2 == true){
		radius = 80;
		cenX2 = pos.x; 
		cenY2 = pos.y; 
		cenX6 = pos2.x; 
		cenY6 = pos2.y; 
		cenX8 = pos3.x; 
		cenY8 = pos3.y;
		q1 = false; //these have to be here or the old quizzes will turn back on under the new ones
	}
		if(sh3 == true){ 
		for (int i = 0; i < gameplay; i++){
			show3+=0.01;
		}
		radius = 100;
		cenX3 = 500; 
		cenY3 = 300; 
		posd = ofRandom(1, 4);
		q1 = false;
		q2 = false; //this list will increase with each quiz, otherwise the old ones would turn back on
	}
	if(show3 >= 5){ 
		sh3 = false;
		q3 = true;
	}
	if (q3 == true){
		radius = 80;
		cenX3 = pos.x; 
		cenY3 = pos.y; 
		cenX7 = pos2.x; 
		cenY7 = pos2.y; 
		cenX9 = pos3.x; 
		cenY9 = pos3.y;
		q1 = false;
		q2 = false;
	}
		if(sh4 == true){ 
		for (int i = 0; i < gameplay; i++){
			show4+=0.01;
		}
		radius = 100;
		cenX4 = 500; 
		cenY4 = 300; 
		posd = ofRandom(1, 4);
		q1 = false;
		q2 = false;
		q3 = false;
	}
	if(show4 >= 5){ 
		sh4 = false;
		q4 = true;
	}
	if (q4 == true){
		radius = 80;
		cenX4 = pos.x; 
		cenY4 = pos.y; 
		cenX8 = pos2.x; 
		cenY8 = pos2.y; 
		cenX10 = pos3.x; 
		cenY10 = pos3.y; 
		q1 = false;
		q2 = false;
		q3 = false;
	}
		if(sh5 == true){ 
		for (int i = 0; i < gameplay; i++){
			show5+=0.01;
		}
		radius = 100;
		cenX5 = 500; 
		cenY5 = 300; 
		posd = ofRandom(1, 3);
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
	}
	if(show5 >= 5){ 
		sh5 = false;
		q5 = true;
	}
	if (q5 == true){
		radius = 80;
		cenX5 = pos.x; 
		cenY5 = pos.y; 
		cenX = pos2.x; 
		cenY = pos2.y; 
		cenX9 = pos3.x; 
		cenY9 = pos3.y; 
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
	}
		if(sh6 == true){ 
		for (int i = 0; i < gameplay; i++){
			show6+=0.01;
		}
		radius = 100;
		cenX6 = 500; 
		cenY6 = 300; 
		posd = ofRandom(1, 3);
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
	}
	if(show6 >= 5){ 
		sh6 = false;
		q6 = true;
	}
	if (q6 == true){
		radius = 80;
		cenX6 = pos.x; 
		cenY6 = pos.y; 
		cenX2 = pos2.x; 
		cenY2 = pos2.y; 
		cenX10 = pos3.x; 
		cenY10 = pos3.y;
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
	}
		if(sh7 == true){ 
		for (int i = 0; i < gameplay; i++){
			show7+=0.01;
		}
		radius = 100;
		cenX7 = 500; 
		cenY7 = 300; 
		posd = ofRandom(1, 3);
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
	}
	if(show7 >= 5){ 
		sh7 = false;
		q7 = true;
	}
	if (q7 == true){
		radius = 80;
		cenX7 = pos.x; 
		cenY7 = pos.y; 
		cenX = pos2.x; 
		cenY = pos2.y; 
		cenX3 = pos3.x; 
		cenY3 = pos3.y; 
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
	}
		if(sh8 == true){ 
		for (int i = 0; i < gameplay; i++){
			show8+=0.01;
		}
		radius = 100;
		cenX8 = 500; 
		cenY8 = 300;
		posd = ofRandom(1, 3);
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
		q7 = false;
	}
	if(show8 >= 5){ 
		sh8 = false;
		q8 = true;
	}
	if (q8 == true){
		radius = 80;
		cenX8 = pos.x; 
		cenY8 = pos.y; 
		cenX2 = pos2.x; 
		cenY2 = pos2.y; 
		cenX4 = pos3.x; 
		cenY4 = pos3.y;
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
		q7 = false;
	}
		if(sh9 == true){ 
		for (int i = 0; i < gameplay; i++){
			show9+=0.01;
		}
		radius = 100;
		cenX9 = 500; 
		cenY9 = 300; 
		posd = ofRandom(1, 3);
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
		q7 = false;
		q8 = false;
	}
	if(show9 >= 5){ 
		sh9 = false;
		q9 = true;
	}
	if (q9 == true){
		radius = 80;
		cenX9 = pos.x; 
		cenY9 = pos.y; 
		cenX3 = pos2.x; 
		cenY3 = pos2.y; 
		cenX5 = pos3.x; 
		cenY5 = pos3.y;
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
		q7 = false;
		q8 = false;
	}
		if(sh10 == true){ 
		for (int i = 0; i < gameplay; i++){
			show10+=0.01;
		}
		radius = 100; 
		cenX10 = 500; 
		cenY10 = 300; 
		posd = ofRandom(1, 3);
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
		q7 = false;
		q8 = false;
		q9 = false;
	}
	if(show10 >= 5){ 
		sh10 = false;
		q10 = true;
	}
	if (q10 == true){
		radius = 80; 
		cenX10 = pos.x; 
		cenY10 = pos.y; 
		cenX4 = pos2.x; 
		cenY4 = pos2.y; 
		cenX6 = pos3.x; 
		cenY6 = pos3.y; 
		q1 = false;
		q2 = false;
		q3 = false;
		q4 = false;
		q5 = false;
		q6 = false;
		q7 = false;
		q8 = false;
		q9 = false;
	}

	if (posd == 1){ //these are used to determine where the quiz choices will go, so it can change each gameplay
		pos = ofVec2f (200, 500);
		pos2 = ofVec2f (500, 500);
		pos3 = ofVec2f (800, 500);
	}
	if (posd == 2){ 
		pos = ofVec2f (500, 500);
		pos2 = ofVec2f (200, 500);
		pos3 = ofVec2f (800, 500);
	}
	if (posd == 3){ 
		pos = ofVec2f (800, 500);
		pos2 = ofVec2f (200, 500);
		pos3 = ofVec2f (500, 500);
	}
	
	if (end == true){ //adds focus bonus to score at end of game
		fbonus = score + (0.05*focus);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(c1, c2, OF_GRADIENT_CIRCULAR); //background gradient

if (end == false){ //the stuff here is only shown when the game is in play (before 1 min is up)
//----Camera Stuff----
	ofSetColor(255, 255, 255); //keeps the camera image (and some of the text) from being tinted
	ofPushMatrix();
		ofScale(0.5, 0.5); //scales down camera (easier than resizing it)
		ofTranslate(ofGetWindowWidth()+380, 0); //position of camera (top right corner)
		cam.draw(0, 0);
	ofPopMatrix();

		for(int i = 0; i < finder.size(); i++) { //this is for counting how many times you look away, and reseting the focus timer if you do
			for (int j = 0; j < gameplay; j++){
				focus+= 0.005; 
			
			if (finder.getLabel(i) > lastface){
				focus = 0;
				lastface = finder.getLabel(i);
			}
		}
			
		ofPushMatrix();
			ofTranslate(100, 100);
			font.drawString("Face Counter: " + ofToString(finder.getLabel(i)), 0, 0); //this is counting and showing the number of faces the camera has seen
		ofPopMatrix();
	}


		ofPushMatrix();
			ofTranslate(100, 200);
			font.drawString("Game Timer: "+ ofToString(gameplay), 0, 0); //gameplay timer
		ofPopMatrix();

//---Shapes Stuff----
if(stop == false){ //only draws these if there are more quizzes (stops after 10)
	output.fill(); //fills the shapes

	output.setColor(0xF5F25D); //shape color (yellow)
	 
	float scale = 1.0 + 0.6 * sin(ofGetElapsedTimef()); //makes the shapes pulse
	angle = 0.0; //used for building and rotating the shapes

	if(sh1 ==true || q1 == true || q5 == true || q7 == true){ //only show the shape for its memorization or during these quizzes
	
	output.beginShape(); //the start of this shape

		step = TWO_PI / (numSteps);
		
		for(int i = 0; i < numSteps; i++){
			//sides of shape
			float rx = cenX + cos(angle) * radius;
			float ry = cenY + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx, ry);
			}

			//end points for the beziers that give those curves
			float rx2 = cenX + cos(angle+step) * radius;
			float ry2 = cenY + sin(angle+step) * radius;

			//makes the shapes throb (moving the control points)
			float cx = cenX + cos(angle + step*0.5) * radius * scale;
			float cy = cenY + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx, cy, cx, cy, rx2, ry2);//makes it a bezier Vertex (lets us have those curves)

			angle += step; //rotates the shape
		}

	output.endShape(true); //the end of this shape
				
	}

	if(sh2 == true || q2 == true || q6 == true || q8 == true){
		
	output.beginShape();

		step = TWO_PI / (numSteps2);

		for(int i = 0; i < numSteps2; i++){
			float rrx = cenX2 + cos(angle) * radius;
			float rry = cenY2 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rrx, rry);
			}

			float rrx2 = cenX2 + cos(angle+step) * radius;
			float rry2 = cenY2 + sin(angle+step) * radius;

			float cx2 = cenX2 + cos(angle + step*0.5) * radius * scale;
			float cy2 = cenY2 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx2, cy2, cx2, cy2, rrx2, rry2);

			angle += step;
		}

	output.endShape(true);

	}

	if(sh3 == true || q3 == true || q7 == true || q9 == true){

	output.beginShape();

		step = TWO_PI / (numSteps3);

		for(int i = 0; i < numSteps3; i++){
			float rx3 = cenX3 + cos(angle) * radius;
			float ry3 = cenY3 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx3, ry3);
			}

			float rx23 = cenX3 + cos(angle+step) * radius;
			float ry23 = cenY3 + sin(angle+step) * radius;

			float cx3 = cenX3 + cos(angle + step*0.5) * radius * scale;
			float cy3 = cenY3 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx3, cy3, cx3, cy3, rx23, ry23);

			angle += step;
		}
		output.endShape(true);

	}

		if(sh4 == true || q4 == true || q8 == true || q10 == true){
				
		output.beginShape();

		step = TWO_PI / (numSteps4);

		for(int i = 0; i < numSteps4; i++){
			float rx4 = cenX4 + cos(angle) * radius;
			float ry4 = cenY4 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx4, ry4);
			}

			float rx24 = cenX4 + cos(angle+step) * radius;
			float ry24 = cenY4 + sin(angle+step) * radius;

			float cx4 = cenX4 + cos(angle + step*0.5) * radius * scale;
			float cy4 = cenY4 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx4, cy4, cx4, cy4, rx24, ry24);

			angle += step;
		}
		output.endShape(true);
			}

		if(sh5 == true || q5 == true || q1 == true || q9 == true){

		output.beginShape();

		step = TWO_PI / (numSteps5);

		for(int i = 0; i < numSteps5; i++){
			float rx5 = cenX5 + cos(angle) * radius;
			float ry5 = cenY5 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx5, ry5);
			}
			
			float rx25 = cenX5 + cos(angle+step) * radius;
			float ry25 = cenY5 + sin(angle+step) * radius;

			float cx5 = cenX5 + cos(angle + step*0.5) * radius * scale;
			float cy5 = cenY5 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx5, cy5, cx5, cy5, rx25, ry25);

			angle += step;
		}
		output.endShape(true);
	}

		if(sh6 == true || q6 == true || q2 == true || q10 == true){

		output.beginShape();

		step = TWO_PI / (numSteps6);

		for(int i = 0; i < numSteps6; i++){
			float rx6 = cenX6 + cos(angle) * radius;
			float ry6 = cenY6 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx6, ry6);
			}

			float rx26 = cenX6 + cos(angle+step) * radius;
			float ry26 = cenY6 + sin(angle+step) * radius;

			float cx6 = cenX6 + cos(angle + step*0.5) * radius * scale;
			float cy6 = cenY6 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx6, cy6, cx6, cy6, rx26, ry26);

			angle += step;
		}
		output.endShape(true);
	}

		if(sh7 == true || q7 == true || q1 == true || q3 == true){

		output.beginShape();

		step = TWO_PI / (numSteps7);

		for(int i = 0; i < numSteps7; i++){
			float rx7 = cenX7 + cos(angle) * radius;
			float ry7 = cenY7 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx7, ry7);
			}

			float rx27 = cenX7 + cos(angle+step) * radius;
			float ry27 = cenY7 + sin(angle+step) * radius;

			float cx7 = cenX7 + cos(angle + step*0.5) * radius * scale;
			float cy7 = cenY7 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx7, cy7, cx7, cy7, rx27, ry27);

			angle += step;
		}
		output.endShape(true);
	}

		if(sh8 == true || q8 == true || q2 == true || q4 == true){

		output.beginShape();

		step = TWO_PI / (numSteps8);

		for(int i = 0; i < numSteps8; i++){
			float rx8 = cenX8 + cos(angle) * radius;
			float ry8 = cenY8 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx8, ry8);
			}

			float rx28 = cenX8 + cos(angle+step) * radius;
			float ry28 = cenY8 + sin(angle+step) * radius;

			float cx8 = cenX8 + cos(angle + step*0.5) * radius * scale;
			float cy8 = cenY8 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx8, cy8, cx8, cy8, rx28, ry28);

			angle += step;
		}
		output.endShape(true);
	}

		if(sh9 == true || q9 == true || q3 == true || q5 == true){

		output.beginShape();

		step = TWO_PI / (numSteps9);

		for(int i = 0; i < numSteps9; i++){
			float rx9 = cenX9 + cos(angle) * radius;
			float ry9 = cenY9 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx9, ry9);
			}

			float rx29 = cenX9 + cos(angle+step) * radius;
			float ry29 = cenY9 + sin(angle+step) * radius;

			float cx9 = cenX9 + cos(angle + step*0.5) * radius * scale;
			float cy9 = cenY9 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx9, cy9, cx9, cy9, rx29, ry29);

			angle += step;
		}
		output.endShape(true);
	}

		if(sh10 == true || q10 == true || q4 == true || q6 == true){

		output.beginShape();

		step = TWO_PI / (numSteps10);

		for(int i = 0; i < numSteps10; i++){
			float rx10 = cenX10 + cos(angle) * radius;
			float ry10 = cenY10 + sin(angle) * radius;

			if(i == 0){
				output.polyVertex(rx10, ry10);
			}

			float rx210 = cenX10 + cos(angle+step) * radius;
			float ry210 = cenY10 + sin(angle+step) * radius;

			float cx10 = cenX10 + cos(angle + step*0.5) * radius * scale;
			float cy10 = cenY10 + sin(angle + step*0.5) * radius * scale;

			output.bezierVertex(cx10, cy10, cx10, cy10, rx210, ry210);

			angle += step;
		}
		output.endShape(true);
		}

	}
}

//---Gameplay Stuff that stays when game ends----
	ofSetColor(255, 255, 255); //font color (so it's not the color of the shapes)
	ofPushMatrix();
		ofTranslate(100, 250);
		font.drawString("Right Answers: " + ofToString(score), 0, 0); //showing the score on the screen
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(100, 150);
		font.drawString("Focus Timer: " + ofToString(focus), 0, 0); //focus timer
	ofPopMatrix();

if(end == true) { //only show final score at end of game
	ofPushMatrix();
		ofTranslate(400, 400);
		ffont.drawString("Final Score: " + ofToString(fbonus), 0, 0); //final score
	ofPopMatrix();
	}
}

//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button){
	if (end == false){
		if (ofGetMouseX() >= 150 && ofGetMouseX() <= 850){ //check to see if mouse is within quiz choice areas
			if (ofGetMouseY() >=450 && ofGetMouseY() <= 550){
				if (ofGetMouseX() >= (pos.x-50) && ofGetMouseX() <= (pos.x+50)){ //check to see if mouse is on correct answer
					if(ofGetMouseY() >= (pos.y-50) && ofGetMouseY() <= (pos.y+50)){
						score++; //add to the score if it is
					}
				}
				if (q1 == true)sh2 = true; //show the next shape
				if (q2 == true)sh3 = true;
				if (q3 == true)sh4 = true;
				if (q4 == true)sh5 = true;
				if (q5 == true)sh6 = true;
				if (q6 == true)sh7 = true;
				if (q7 == true)sh8 = true;
				if (q8 == true)sh9 = true;
				if (q9 == true)sh10 = true;
				if (q10 == true)stop = true;//stops quizzes but lets timer keep going	
		}
	}
	}
}

//--------------------------------------------------------------
