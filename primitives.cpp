#define _USE_MATH_DEFINES
#include<GL/glut.h>
#include <math.h>

void render(void);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Primitives");
	glutDisplayFunc(render);
	glutMainLoop();
}


void render(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	float iniX = -0.5;
	float maxIniY = 0.2;
	float minIniY = 0.0;
	float space = 0.05;
	float width = 0.1;
	
	//D
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX, maxIniY);
		glVertex2f(iniX, minIniY);
		glVertex2f(iniX + width, (maxIniY - minIniY)/2);

		iniX += width;
	glEnd();

	//O
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX + space, maxIniY);
		glVertex2f(iniX + space, minIniY);
		glVertex2f(iniX + space + width, minIniY);
		glVertex2f(iniX + space + width, maxIniY);

		iniX += space + width;
	glEnd();

	//U
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX + space, maxIniY);
		glVertex2f(iniX + space, minIniY);
		glVertex2f(iniX + space + width, minIniY);
		glVertex2f(iniX + space + width, maxIniY);

		iniX += space + width;
	glEnd();

	//G
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX + space + width, maxIniY);
		glVertex2f(iniX + space, maxIniY);
		glVertex2f(iniX + space, minIniY);
		glVertex2f(iniX + space + width, minIniY);
		glVertex2f(iniX + space + width, (maxIniY - minIniY)/2);
		glVertex2f(iniX + space + width, (maxIniY - minIniY)/2);

		iniX += space + width;
	glEnd();

	//L
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX + space, maxIniY);
		glVertex2f(iniX + space, minIniY);
		glVertex2f(iniX + space + width, minIniY);

		iniX += space + width;
	glEnd();

	//A
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX + space, 0.0);
		glVertex2f(iniX + space, maxIniY);
		glVertex2f(iniX + space + width, maxIniY);
		glVertex2f(iniX + space + width, minIniY);
		glVertex2f(iniX + space + width, (maxIniY - minIniY)/2);
		glVertex2f(iniX + space, (maxIniY - minIniY)/2);

		iniX += space + width;
	glEnd();

	//S
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(iniX + space + width, maxIniY);
		glVertex2f(iniX + space, maxIniY);
		glVertex2f(iniX + space, (maxIniY - minIniY)/2);
		glVertex2f(iniX + space + width, (maxIniY - minIniY)/2);
		glVertex2f(iniX + space + width, minIniY);
		glVertex2f(iniX + space, minIniY);

		iniX += space + width;
	glEnd();

	glutSwapBuffers();
  }