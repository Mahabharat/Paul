#include<GL/glut.h>
#include<stdio.h>
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 350.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(1.0, 0.0, 0.0);
	int x0,y0,xn, yn, dx, dy,p,x,y;
	float m;
	x0=0;
	y0=0;
	xn=150;
	yn=150;
	dx=xn-x0;
	dy=yn-y0;
	m=dy/dx;
	x=x0;
	y=y0;
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	
	while(x!=xn&&y!=yn)
	{	
		 m=(xn-x)/(yn-y);
		if(m>0)
		{
			if(m<=1)
			{
				
				x=x+1;
				y=y+m;
				
			}
			else
			{
				
				y=y+1;
				x=x+1/m;
				
			}
		}
		else
		{
			if(m<=1)
			{
				
				x=x-1;
				y=y-m;
			}
			else
			{
				
				x=x-1/m;
				y=y-1;
			}
		}
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
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
