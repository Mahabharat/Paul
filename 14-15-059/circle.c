#include  <stdio.h>
#include <math.h> 
#include <GL/glut.h>
void crcle(void);
void piixel(int xc,int yc,int x,int y);
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0,0.0,0.0);
	 gluOrtho2D(0 , 640 , 0 , 480);
}
void crcle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int dx, dy,x,y;
	int xc = 320, yc = 240;
	float pk;
	int r=100;
	x=0;
	y=r;
	piixel(xc,yc,x,y);
	pk=(5.0/4.0)-r;
	int  k;
	while(x<y)
	{
		x=x+1;	
		if(pk < 0)       
			pk = pk + 2*x+1;
        	else
        	{       
			y = y -  1;
            		pk = pk + 2*(x - y) + 1;
        	}
	piixel(xc,yc,x,y);
	}
	glFlush();
}
 void piixel(int xc,int yc,int x,int y)
{	
	glBegin(GL_POINTS);
        glVertex2i(xc+x, yc+y);
    	glVertex2i(xc+x,  yc-y);
    	glVertex2i(xc+y, yc+x);
    	glVertex2i(xc+y, yc-x);
    	glVertex2i(xc-x, yc-y);
    	glVertex2i(xc-y, yc-x);
    	glVertex2i(xc-x,  yc+y);
    	glVertex2i(xc-y, yc+x);
	glEnd();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Bresenhem's");
	init();
	glutDisplayFunc(crcle);
	glutMainLoop();
}
