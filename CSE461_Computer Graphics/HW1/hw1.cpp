/*

  Onur SEZER
  121044074

  Computer Graphics
  
  HW1


*/

#include <cstdlib>
#include <GL/glut.h>
#include <GL/gl.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <cmath>

#define sign(x) ((x>0)?1:((x<0)?-1:0))

using namespace std;


int ddaTime, breTime;
clock_t start, finish;
int selection;
int counter = 0;
int dashLength =2 ;
int x_0, y_0, x_1, y_1;//selected coordinates

void setPixel(GLint x, GLint y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}
float round_value(float v)
{
  return floor(v + 0.5);
}
void DDAAlgorithm(int x0, int y0, int x1, int y1)
{
	double dx=(x1-x0);
	double dy=(y1-y0);
	double steps;
	float xInc,yInc,x=x0,y=y0;
	/* Find out whether to increment x or y */
	steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	xInc=dx/(float)steps;
	yInc=dy/(float)steps;

	/* Clears buffers to preset values */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Plot the points */
	glBegin(GL_POINTS);
	/* Plot the first point */
	glVertex2d(x,y);
	int k;
	/* For every step, find an intermediate vertex */
	for(k=0;k<steps;k++)
	{
		x+=xInc;
		y+=yInc;
		/* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
		glVertex2d(round_value(x), round_value(y));
	}
	glEnd();

	glFlush();
}

void bresenhamAlgorithm(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y, d, s1, s2, swap=0, temp;
	cout << "İcerde 1" << endl;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	s1 = sign(x2-x1);
	s2 = sign(y2-y1);

	/* Check if dx or dy has a greater range */
	/* if dy has a greater range than dx swap dx and dy */
	if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}
	cout << "İcerde 2" << endl;

	/* Set the initial decision parameter and the initial point */
	d = 2 * dy - dx;
	x = x1;
	y = y1;
	cout << "İcerde 3" << endl;

	int i;
	for(i = 1; i <= dx; i++)
	{
		setPixel(x,y);
	cout << "İcerde 4" << endl;

		while(d >= 0) 
		{
				//cout << "İcerde 4.1" << endl;

		  if(swap) 
		  	x = x + s1;
		  else 
		  {
		  		cout << "İcerde 4.2" << endl;

		    y = y + s2;
		    d = d - 2* dx;
		  }
		}
		if(swap) 
			y = y + s2;
		else 
			x = x + s1;
		d = d + 2 * dy;
			cout << "İcerde 4.3" << endl;

	}
	cout << "İcerde 5 " << endl;
	glEnd();
	glFlush();
}


void drawLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x0, y0, x1, y1;
	cout << "1" << endl;
	int c=0;
	start = clock();
	while (c < 100) {

		x0 = 1 + (rand() % (int)(500 - 1 + 1));
					cout << "*1" << endl;

		y0 = 1 + (rand() % (int)(500 - 1 + 1));
					cout << "*2" << endl;

		x1 = 1 + (rand() % (int)(500 - 1 + 1));
					cout << "*3" << endl;

		y1 = 1 + (rand() % (int)(500 - 1 + 1));
					cout << "*4" << endl;
		cout << "x0 : " << x0 << "y0 : " << y0 << "x1 : " << x0 << "y1 : " << y1 << endl; 

		bresenhamAlgorithm(x0, y0, x1, y1);
					cout << "*5" << endl;

		c++;
			cout << "1" << endl;

	}
	finish = clock(); 
	//breTime = start - finish;
	breTime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "2" << endl;

	int t = 0;
	start = clock();
	while (t < 100) {
		x0 = 1 + rand() % 500;
		y0 = 1 + rand() % 500;
		x1 = 1 + rand() % 500;
		y1 = 1 + rand() % 500;

		cout << "x0 : " << x0 << "y0 : " << y0 << "x1 : " << x0 << "y1 : " << y1 << endl; 

		DDAAlgorithm(x0, y0, x1, y1);
		t++;
	}
	finish = clock();
	//ddaTime = start - finish;
	ddaTime = (double)(finish - start) / CLOCKS_PER_SEC;

	if (breTime > ddaTime)
		printf("\nDDA is faster..");
	else if(ddaTime > breTime)
		printf("\nBresenham is faster..");
	else
		printf("\nThey have equal speed..");
	
}
void draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
 
  /* Draw rectangle */
  bresenhamAlgorithm(20,40,620,40);
  bresenhamAlgorithm(620,40,620,440);
  bresenhamAlgorithm(620,440,20,440);
  bresenhamAlgorithm(20,440,20,40);

  /* Draw rhombus */
  bresenhamAlgorithm(320,440,20,240);
  bresenhamAlgorithm(20,240,320,40);
  bresenhamAlgorithm(320,40,620,240);
  bresenhamAlgorithm(620,240,320,440);

  /* 1 */
  bresenhamAlgorithm(250,150,250,250);
  /* 0 */
  bresenhamAlgorithm(300,150,300,250);
  bresenhamAlgorithm(300,250,400,250);
  bresenhamAlgorithm(400,250,400,150);
  bresenhamAlgorithm(400,150,300,150);

  glFlush();
}

void init() {  
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640, 640);
  glutCreateWindow("Green Window");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0,640,0,640);
  
}

int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(drawLine);
  glutMainLoop();
  return 0;
}