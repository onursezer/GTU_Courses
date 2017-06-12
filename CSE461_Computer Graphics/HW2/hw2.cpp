/*

  Onur SEZER
  121044074

  Computer Graphics
  
  HW2


*/

#include <stdlib.h>
#include <GL/glut.h>

float Geometry[4][3] = { 
	{ 10,10,0 },	//	Point1
	{-10,10,-2 },	//	Point2
	{ 5,-5,0  },	//	Tangent1
	{ 5,15,0  }		//	Tangent2
};
unsigned int LOD=20;

//------------------------------------------------------------	onReshape()
//
void onReshape(int w, int h)
{
	// prevent a division by zero when minimised
	if (h==0)
		h=1;

	// set the drawable region of the window
	glViewport(0,0,w,h);

	// set up the projection matrix 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// just use a perspective projection
	gluPerspective(45,(float)w/h,0.1,100);

	// go back to modelview matrix so we can move the objects about
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//------------------------------------------------------------	Draw()
//
void onDraw() {

	// clear the screen & depth buffer
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	// clear the previous transform
	glLoadIdentity();

	// set the camera position
	gluLookAt(	1,10,30,	//	eye pos
				0,5,0,	//	aim point
				0,1,0);	//	up direction

	glColor3f(0.5,0.5,1);
	glBegin(GL_LINE_STRIP);

	// use the parametric time value 0 to 1
	for(int i=0;i!=LOD;++i) {

		float t = (float)i/(LOD-1);

		// calculate blending functions
		float b0 =  2*t*t*t - 3*t*t + 1;
		float b1 = -2*t*t*t + 3*t*t;
		float b2 = t*t*t - 2*t*t + t;
		float b3 = t*t*t - t*t;

		// calculate the x,y and z of the curve point
		float x = b0*Geometry[0][0] + 
				  b1*Geometry[1][0] + 
				  b2*Geometry[2][0] + 
				  b3*Geometry[3][0] ;

		float y = b0*Geometry[0][1] + 
				  b1*Geometry[1][1] + 
				  b2*Geometry[2][1] + 
				  b3*Geometry[3][1] ;

		float z = b0*Geometry[0][2] + 
				  b1*Geometry[1][2] + 
				  b2*Geometry[2][2] + 
				  b3*Geometry[3][2] ;

		// specify the point
		glVertex3f( x,y,z );
	}
	glEnd();


	glColor3f(0,1,0.5);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex3fv( Geometry[0] );
		glVertex3fv( Geometry[1] );
	glEnd();

	glColor3f(0.5,1,0.5);
	glPushMatrix();
		glTranslatef(Geometry[0][0],Geometry[0][1],Geometry[0][2]);
		glBegin(GL_LINES);
			glVertex3f( 0,0,0 );
			glVertex3fv( Geometry[2] );
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(Geometry[1][0],Geometry[1][1],Geometry[1][2]);
		glBegin(GL_LINES);
			glVertex3f( 0,0,0 );
			glVertex3fv( Geometry[3] );
		glEnd();
	glPopMatrix();

	// currently we've been drawing to the back buffer, we need
	// to swap the back buffer with the front one to make the image visible
	glutSwapBuffers();
}

void onInit() {
	// enable depth testing
	glEnable(GL_DEPTH_TEST);
}

void OnExit() {
}

int main(int argc,char** argv) {

	// initialise glut
	glutInit(&argc,argv);

	// request a depth buffer, RGBA display mode, and we want double buffering
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);

	// set the initial window size
	glutInitWindowSize(640,480);

	// create the window
	glutCreateWindow("Hermite Curve  / Computer Graphics HW2");

	// set the function to use to draw our scene
	glutDisplayFunc(onDraw);

	// set the function to handle changes in screen size
	glutReshapeFunc(onReshape);
	
	// run our custom initialisation
	onInit();

	// set the function to be called when we exit
	atexit(OnExit);

	// this function runs a while loop to keep the program running.
	glutMainLoop();
	return 0;
}
