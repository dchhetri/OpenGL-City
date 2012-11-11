#include "opengl_camera.h"
#include "vmath.h"
#include "utility.h"

/***************************************************************************************/

Camera::Camera()
{
	//Init with standard OGL values:
	Position = Vector3f (0.0, 0.0,	0.0);
	ViewDir = Vector3f( 0.0, 0.0, -1.0);
	RightVector = Vector3f (1.0, 0.0, 0.0);
	UpVector = Vector3f (0.0, 1.0, 0.0);
    
	//Only to be sure:
	RotatedX = RotatedY = RotatedZ = 0.0;
}

void Camera::Move(Vector3f Direction)
{
	Position = Position + Direction;
}

void Camera::RotateX (GLfloat Angle)
{
	RotatedX += Angle;
	
	//Rotate viewdir around the right vector:
    ViewDir = ViewDir * cos(Angle * Utility::PIdiv180) + UpVector * sin(Angle * Utility::PIdiv180);
    ViewDir.normalize();
    
	//now compute the new UpVector (by cross product)
	UpVector = ViewDir.crossProduct(RightVector) * -1;
	
}

void Camera::RotateY (GLfloat Angle)
{
	RotatedY += Angle;
	
	//Rotate viewdir around the up vector:
    ViewDir = ViewDir * cos(Angle * Utility::PIdiv180) - RightVector * sin(Angle * Utility::PIdiv180);
    ViewDir.normalize();
    
	//now compute the new RightVector (by cross product)
	RightVector = ViewDir.crossProduct(UpVector);
}

void Camera::RotateZ (GLfloat Angle)
{
	RotatedZ += Angle;
	
	//Rotate viewdir around the right vector:
    RightVector = RightVector * cos(Angle * Utility::PIdiv180) + UpVector * sin(Angle*Utility::PIdiv180);
    RightVector.normalize();
    
	//now compute the new UpVector (by cross product)
    UpVector = ViewDir.crossProduct(RightVector) * -1;
}

void Camera::Render( void )
{
    
	//The point at which the camera looks:
	Vector3f ViewPoint = Position+ViewDir;
    
	//as we know the up vector, we can easily use gluLookAt:
	gluLookAt(	Position.x,Position.y,Position.z,
              ViewPoint.x,ViewPoint.y,ViewPoint.z,
              UpVector.x,UpVector.y,UpVector.z);
    
}

void Camera::MoveForward( GLfloat Distance )
{
	Position = Position + (ViewDir*-Distance);
}

void Camera::StrafeRight ( GLfloat Distance )
{
	Position = Position + (RightVector*Distance);
}

void Camera::MoveUpward( GLfloat Distance )
{
	Position = Position + (UpVector*Distance);
}