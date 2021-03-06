#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
void init(void)  
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,20,0,15);
}
void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2i(5.0,5.0);
		glVertex2i(10.0,5.0);
		glVertex2i(10.0,10.0);
		glVertex2i(5.0,10.0);
	glEnd();
	glFlush();
}

void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(20,10);
	glutInitWindowSize(400,300);
	glutCreateWindow("Example 1");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
