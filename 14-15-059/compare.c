#include<GL/glut.h>
#include<stdio.h>
void bresenhm(void);
void dd(void);
void crcle(void);
void piixel(int xc,int yc,int x,int y);
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 350.0);
}
void display(void)
{
	
	
	bresenhm();
	
	dd();

	crcle();
}
	
void bresenhm(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x0,y0,xn, yn, dx, dy,p,x,y;
	float m;
	x0=0;
	y0=0;
	xn=250;
	yn=250;
	dx=xn-x0;
	dy=yn-y0;
	//m=dy/dx;
	x=x0;
	y=y0;
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
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
void dd(void)
{
	
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
void crcle(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int dx, dy,x,y,r, xc, yc;
	xc=10;
	yc=10;
	float p;
	r=10;
	x=0;
	y=r;
	piixel(xc,yc,x,y);
	p=1-r;
	while(x<y)
	{
		
		if(p>0)
		{
			x=x+1;
			y=y-1;
			p=p+2*x-2*y+1;			
		}
		else
		{
			x=x+1;
			y=y;
			p=p+2*x+1;
		}
		piixel(xc,yc,x,y);
		glFlush();
	
	}
	
}
void putpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
 void piixel(int xc,int yc,int x,int y)
{
            putpixel(xc+x,yc+y);
            putpixel(xc+y,yc+x);
            putpixel(xc-y,yc+x);
            putpixel(xc-x,yc+y);
            putpixel(xc-x,yc-y);
            putpixel(xc-y,yc-x);
            putpixel(xc+y,yc-x);
            putpixel(xc+x,yc-y);
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
