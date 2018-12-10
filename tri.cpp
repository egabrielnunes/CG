#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/glut.h>
#include <math.h>

void init (void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 600.0, 0.0, 400.0);
}

void displayRet(void){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	glRecti(50, 100, 200, 150);

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(200.0, -50.0, 0.0);
	glRecti(50,100,200,150);

	glFlush();

}

void exit(unsigned char key, int x, int y){

	if (key == 'q'){
		exit(0);
	}

}

int main (int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Retangulos");
	
	init();
	glutDisplayFunc(displayRet);
	glutKeyboardFunc(exit);
	glutMainLoop();
}