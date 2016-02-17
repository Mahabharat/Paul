#include<GL/glut.h>
#include<stdio.h>
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 250.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int x0,y0,xn, yn, dx, dy,p,x,y;
	x0=0;
	y0=0;
	xn=330;
	yn=218;
	dx=xn-x0;
	dy=yn-y0;
	x=x0;
	y=y0;
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	p=2*dy-dx;
	while(x!=xn&&y!=yn)
	{
		dx=xn-x;
		dy=yn-y;
		if(p>0)
		{
			
			x=x+1;
			y=y+1;
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
			p=p+2*dy-2*dx;
			glFlush();
		}
		else
		{
			
			x=x+1;
			y=y;
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
			p=p+2*dy;
			glFlush();
		}
	}
	
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Bresenhem's");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
