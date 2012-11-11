//
//  main.cpp
//  RecursivePlay
//
//  Created by Dibash Chhetri on 10/29/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include <cmath>
#include <ctime>
#include <string>
#include <array>

#include "utility.h"
#include "vmath.h"
#include "opengl_camera.h"
#include "City.h"

using namespace std;

namespace  {
    enum DisplayType{TWO_DIM, THREE_DIM};
    const DisplayType DISPLAY_MODE = THREE_DIM;
    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 800;
 
    Camera camera;
    City city;
}


void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    camera.Render();
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    city.render();
    
	glutSwapBuffers();
}


void changeSize(int w, int h){

    // Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0){h = 1;}
	float ratio = 1.0* w / h;
    
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
    
    // Reset Matrix
	glLoadIdentity();
    
    if(DISPLAY_MODE == TWO_DIM){
        gluOrtho2D(0,WINDOW_WIDTH,0, WINDOW_HEIGHT);
    }else{
        //3d move
        // Set the viewport to be the entire window
        glViewport(0, 0, w, h);
        // Set the correct perspective.
        gluPerspective(45,ratio,1,1000);
    }
    glTranslatef(0.0f,-1.0f, -10.0f);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
    
}

void handleNormalKeyPress(unsigned char key, int x, int y) {
    enum {ESCAPE = 27,
          KEY_1 = '1', KEY_2 = '2',
          KEY_W = 'w', KEY_S = 's', KEY_A = 'a', KEY_D = 'd', KEY_X = 'x', KEY_Y = 'y'};
    
    switch(key){
        case ESCAPE:
            std::exit(0);
            break;
        case KEY_X: camera.RotateX(5.0f);
            break;
        case KEY_Y: camera.RotateX(-5.0f);
            break;
        case KEY_A: camera.StrafeRight(-0.2f);
            break;
        case KEY_D: camera.StrafeRight(0.2f);
            break;
        case KEY_W: camera.MoveUpward(0.2f);
            break;
        case KEY_S: camera.MoveUpward(-0.2f);
            break;

    }
    glutPostRedisplay();
    
}

void pressKey(int key, int xx, int yy) {
    
	switch (key) {
		case GLUT_KEY_LEFT :
            camera.RotateY(1.0);
			break;
		case GLUT_KEY_RIGHT :
            camera.RotateY(-1.0);
			break;
		case GLUT_KEY_UP :
            camera.MoveForward(-0.2f);
			break;
		case GLUT_KEY_DOWN :
            camera.MoveForward(0.2f);
			break;
	}
    glutPostRedisplay();
}

void releaseKey(int key, int x, int y) {
    
	switch (key) {
		case GLUT_KEY_UP:
            break;
		case GLUT_KEY_DOWN :
            break;
	}
}

void initOpenGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    camera.Move( Vector3f(0.0, 0.0, 3.0 ));
	camera.MoveForward( 1.0 );
    
}
int main(int argc,char *argv[])
{
    srand( (unsigned int)time(0));
    // init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(150,150);
	glutInitWindowSize(800,600);
	glutCreateWindow("City");
    
    initOpenGL();
    
	glutDisplayFunc(renderScene);

	glutReshapeFunc(changeSize);
    
    glutKeyboardFunc(handleNormalKeyPress);
    glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
    
	// enter GLUT event processing cycle
	glutMainLoop();
    
    return 0;
}

