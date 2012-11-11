//
//  opengl_camera.h
//  City
//
//  Created by Dibash Chhetri on 11/10/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#ifndef __City__opengl_camera__
#define __City__opengl_camera__

#include <GLUT/GLUT.h>		// Need to include it here because the GL* types are required
#include "utility.h"
#include "vmath.h"


/////////////////////////////////
//Note: All angles in degrees  //
/////////////////////////////////

class Camera
{
private:
	
	Vector3f ViewDir;
	Vector3f RightVector;
	Vector3f UpVector;
	Vector3f Position;
    
	GLfloat RotatedX, RotatedY, RotatedZ;
	
public:
	Camera();				//inits the values (Position: (0|0|0) Target: (0|0|-1) )
	void Render ( void );	//executes some glRotates and a glTranslate command
    //Note: You should call glLoadIdentity before using Render
    
	void Move ( Vector3f Direction );
	void RotateX ( GLfloat Angle );
	void RotateY ( GLfloat Angle );
	void RotateZ ( GLfloat Angle );
    
	void MoveForward ( GLfloat Distance );
	void MoveUpward ( GLfloat Distance );
	void StrafeRight ( GLfloat Distance );
    
    
};






#endif /* defined(__City__opengl_camera__) */
