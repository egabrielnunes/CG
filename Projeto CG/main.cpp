#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>
#include "texture.cpp"

float lx=0.0f,lz=-1.0f;
float x=0.0f,z=7.0f;
float door_angle = 0.0f;
float angle = 0.0f;

void init(void) {
    // sky color
    glClearColor(0.0, 0.7, 1.0, 1.0);

    GLfloat luzAmbiente[4]={0.4,0.4,0.4,1.0};
    GLfloat luzDifusa[4]={1.5,1.5,1.5,1.0};	   // "cor"
    GLfloat luzEspecular[4]={3.0, 5.0, 2.0, 1.0};// "brilho"
    GLfloat posicaoLuz[4]={-5, -2, -3, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={0.5,0.5,0.5,1.0};
    GLint especMaterial = 60;

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    loadTextures();

}

void drawBack(){

    //============== BEGIN BACK ==================

    // Back side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);

    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0,-6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,-6);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_TRIANGLES);  // triangle center back
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0,0.5,-6); //center
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0,-6); //left
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,0,-6); //right
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[3]);
    glBegin(GL_QUADS);  // Roof right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0,0.5,-6); //top  right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0,0.5,1); // top left
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,0,1); // bootom left
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,0,-6); // bootom right
    glEnd();

}

void drawSides(){
    //============== BEGIN LATERAIS ===================

    // wall right side
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);

    glTranslatef(0.0f, 1.3f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,1);
    glEnd();
    glPopMatrix();


    // wall left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,0,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-1.5,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,1);
    glEnd();

    //============== END LATERAIS ===================
}

void drawWindowsLeft(){

    // door left outside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(2.0001,-0.3,0);
    glVertex3f(2.0001,-0.3,-0.5);
    glVertex3f(2.0001,-1.5,-0.5);
    glVertex3f(2.0001,-1.5,0);
    glEnd();

    // door left inside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.9999,-0.3,0);
    glVertex3f(1.9999,-0.3,-0.5);
    glVertex3f(1.9999,-1.5,-0.5);
    glVertex3f(1.9999,-1.5,0);
    glEnd();

    // window 1 outside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(2.0001,-0.3,-2);
    glVertex3f(2.0001,-0.3,-2.5);
    glVertex3f(2.0001,-0.8,-2.5);
    glVertex3f(2.0001,-0.8,-2);
    glEnd();

    // window 1 inside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.9999,-0.3,-2);
    glVertex3f(1.9999,-0.3,-2.5);
    glVertex3f(1.9999,-0.8,-2.5);
    glVertex3f(1.9999,-0.8,-2);
    glEnd();

    // window 2 outside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(2.0001,-0.3,-5);
    glVertex3f(2.0001,-0.3,-5.5);
    glVertex3f(2.0001,-0.8,-5.5);
    glVertex3f(2.0001,-0.8,-5);
    glEnd();

    // window 2 inside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.9999,-0.3,-5);
    glVertex3f(1.9999,-0.3,-5.5);
    glVertex3f(1.9999,-0.8,-5.5);
    glVertex3f(1.9999,-0.8,-5);
    glEnd();
}

void drawWindowsRight(){

    // door left outside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-2.0001,-0.3,0);
    glVertex3f(-2.0001,-0.3,-0.5);
    glVertex3f(-2.0001,-1.5,-0.5);
    glVertex3f(-2.0001,-1.5,0);
    glEnd();

    // door left inside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9999,-0.3,0);
    glVertex3f(-1.9999,-0.3,-0.5);
    glVertex3f(-1.9999,-1.5,-0.5);
    glVertex3f(-1.9999,-1.5,0);
    glEnd();

    // window 1 outside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-2.0001,-0.3,-2);
    glVertex3f(-2.0001,-0.3,-2.5);
    glVertex3f(-2.0001,-0.8,-2.5);
    glVertex3f(-2.0001,-0.8,-2);
    glEnd();

    // window 1 inside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9999,-0.3,-2);
    glVertex3f(-1.9999,-0.3,-2.5);
    glVertex3f(-1.9999,-0.8,-2.5);
    glVertex3f(-1.9999,-0.8,-2);
    glEnd();

    // window 2 outside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-2.0001,-0.3,-5);
    glVertex3f(-2.0001,-0.3,-5.5);
    glVertex3f(-2.0001,-0.8,-5.5);
    glVertex3f(-2.0001,-0.8,-5);
    glEnd();

    // window 2 inside
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9999,-0.3,-5);
    glVertex3f(-1.9999,-0.3,-5.5);
    glVertex3f(-1.9999,-0.8,-5.5);
    glVertex3f(-1.9999,-0.8,-5);
    glEnd();
}

void drawFront(){
    //============== BEGIN FACHADA ===================

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_TRIANGLES);  // triangle center
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5,1,1); //center
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1,0.5,1); //left
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(2,0.5,1); //right
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.8,0.5,1);//top left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0.5,1);//top right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5,1);//bottom right
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.8,-1.5,1);//bottom left
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall FRONT LEFT
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.2,0.5,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.2,-1.5,1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,1);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall FRONT MIDDLE
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.8, 0.5, 1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.3, 0.5, 1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.3, -0.25, 1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.8,-0.25, 1);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[3]);
    glBegin(GL_QUADS);  // Roof left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0,0.5,-6); //left top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0,0.5,1); //right top
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,0,1); //right bottom
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,0,-6); //left bottom
    glEnd();


    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);  // sino torre
    glVertex3f(-1.7,1.1,1.0001);
    glVertex3f(-1.3,1.1,1.0001);
    glVertex3f(-1.3,0.4,1.0001);
    glVertex3f(-1.7,0.4,1.0001);
    glEnd();

    glPopMatrix();

    //============== END FACHADA ===================

}

void drawTower(){
    //============== BEGIN TORRE ===================

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall torre left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,1.2,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,1.2,0.5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1,0,0.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1,0,1);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall torre right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,1.2,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,1.2,0.5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,0,0.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,0,1);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall torre FRONT
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,1.2,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1,1.2,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1,-1.5,1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,1);
    glEnd();

    glBegin(GL_QUADS);  // Wall torre back
    glVertex3f(-2,1.2,0.5);
    glVertex3f(-1,1.2,0.5);
    glVertex3f(-1,0,0.5);
    glVertex3f(-2,0,0.5);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_TRIANGLES);  // Wall torre top front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.5,1.7,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,1.2,1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1,1.2,1);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_TRIANGLES);  // Wall torre top bac
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.5,1.7,0.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,1.2,0.5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1,1.2,0.5);
    glEnd();

    //============== END TORRE ===================
}

void drawAltar(){

    //============== BEGIN ALTAR ===================
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[2]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1,-0.5,-5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1,-0.5,-5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1,-1.5,-5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1,-1.5,-5);
    glEnd();

    // back
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[2]);

    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(-1,-0.5,-5.5);
    glTexCoord2f(1.0f, 1.0f);

    glVertex3f(1,-0.5,-5.5);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(1,-1.5,-5.5);
    glTexCoord2f(0.0f, 0.0f);

    glVertex3f(-1,-1.5,-5.5);
    glEnd();

    // left
    glBegin(GL_QUADS);

    glVertex3f(-1,-0.5,-5);


    glVertex3f(1,-1.5,-5);
    glVertex3f(1,-1.5,-5.5);
    glVertex3f(-1,-0.5,-5.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(1,-0.5,-5);
    glVertex3f(1,-1.5,-5);
    glVertex3f(1,-1.5,-5.5);
    glVertex3f(1,-0.5,-5.5);
    glEnd();

    //============== END ALTER ===================
}

void drawCruz(){
    //============== BEGIN CRUZ DENTRO ===================

    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-0.05,0.2,-5.9);
    glVertex3f(0.05,0.2,-5.9);
    glVertex3f(0.05,-0.4,-5.9);
    glVertex3f(-0.05,-0.4,-5.9);
    glEnd();

    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-0.25,0,-5.9);
    glVertex3f(0.25,0,-5.9);
    glVertex3f(0.25,-0.1,-5.9);
    glVertex3f(-0.25,-0.1,-5.9);
    glEnd();

    //============== END CRUZ ===================

    //============== BEGIN CRUZ CENTRAL ===================

    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(0.45,1.45,1.0001);
    glVertex3f(0.55,1.45,1.0001);
    glVertex3f(0.55,0.95,1.0001);
    glVertex3f(0.45,0.95,1.0001);
    glEnd();

    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(0.72,1.3,1.0001);
    glVertex3f(0.27,1.3,1.0001);
    glVertex3f(0.27,1.2,1.0001);
    glVertex3f(0.72,1.2,1.0001);
    glEnd();

    //============== END CRUZ ===================

    //============== BEGIN LINHA CENTRAL ===================

    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.0f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(2,0.2,1.0001);
    glVertex3f(-2,0.2,1.0001);
    glVertex3f(-2,0.1,1.0001);
    glVertex3f(2,0.1,1.0001);
    glEnd();

    //============== END CRUZ ===================

    //============== BEGIN CRUZ TOPO ===================

    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-1.45,2.15,1.0001);
    glVertex3f(-1.55,2.15,1.0001);
    glVertex3f(-1.55,1.65,1.0001);
    glVertex3f(-1.45,1.65,1.0001);
    glEnd();

    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-1.7,2,1.0001);
    glVertex3f(-1.3,2,1.0001);
    glVertex3f(-1.3,1.9,1.0001);
    glVertex3f(-1.7,1.9,1.0001);
    glEnd();

    //============== END CRUZ ===================
}

void drawChair(){
    //============== BEGIN CADEIRA ESQUERDA ===================

    // PRIMEIRA

    // front
    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9,-0.5,-3);
    glVertex3f(-0.9,-0.5,-3);
    glVertex3f(-0.9,-1.5,-3);
    glVertex3f(-1.9,-1.5,-3);
    glEnd();

    // back
    glPushMatrix();
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-1.9,-0.75,-3.5);
    glVertex3f(-0.9,-0.75,-3.5);
    glVertex3f(-0.9,-1.5,-3.5);
    glVertex3f(-1.9,-1.5,-3.5);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glVertex3f(-1.9,-0.75,-3);
    glVertex3f(-0.9,-1.5,-3);
    glVertex3f(-0.9,-1.5,-3.5);
    glVertex3f(-1.9,-0.75,-3.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(-0.9,-0.75,-3);
    glVertex3f(-0.9,-1.5,-3);
    glVertex3f(-0.9,-1.5,-3.5);
    glVertex3f(-0.9,-0.75,-3.5);
    glEnd();


    // SEGUNDA

    // front
    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9,-0.5,-2);
    glVertex3f(-0.9,-0.5,-2);
    glVertex3f(-0.9,-1.5,-2);
    glVertex3f(-1.9,-1.5,-2);
    glEnd();

    // back
    glPushMatrix();
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-1.9,-0.75,-2.5);
    glVertex3f(-0.9,-0.75,-2.5);
    glVertex3f(-0.9,-1.5,-2.5);
    glVertex3f(-1.9,-1.5,-2.5);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glVertex3f(-1.9,-0.75,-2);
    glVertex3f(-0.9,-1.5,-2);
    glVertex3f(-0.9,-1.5,-2.5);
    glVertex3f(-1.9,-0.75,-2.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(-0.9,-0.75,-2);
    glVertex3f(-0.9,-1.5,-2);
    glVertex3f(-0.9,-1.5,-2.5);
    glVertex3f(-0.9,-0.75,-2.5);
    glEnd();

    // TERCEIRA

    // front
    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9,-0.5,-1);
    glVertex3f(-0.9,-0.5,-1);
    glVertex3f(-0.9,-1.5,-1);
    glVertex3f(-1.9,-1.5,-1);
    glEnd();

    // back
    glPushMatrix();
    glBegin(GL_QUADS);  // Wall
    glVertex3f(-1.9,-0.75,-1.5);
    glVertex3f(-0.9,-0.75,-1.5);
    glVertex3f(-0.9,-1.5,-1.5);
    glVertex3f(-1.9,-1.5,-1.5);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glVertex3f(-1.9,-0.75,-1);
    glVertex3f(-0.9,-1.5,-1);
    glVertex3f(-0.9,-1.5,-1.5);
    glVertex3f(-1.9,-0.75,-1.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(-0.9,-0.75,-1);
    glVertex3f(-0.9,-1.5,-1);
    glVertex3f(-0.9,-1.5,-1.5);
    glVertex3f(-0.9,-0.75,-1.5);
    glEnd();

    //============== END CADEIRA ESQUERDA ===================

    //============== BEGIN CADEIRA DIREITA ===================

    // PRIMEIRA

    // front
    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.9,-0.5,-3);
    glVertex3f(0.9,-0.5,-3);
    glVertex3f(0.9,-1.5,-3);
    glVertex3f(1.9,-1.5,-3);
    glEnd();

    // back
    glPushMatrix();
    glBegin(GL_QUADS);  // Wall
    glVertex3f(1.9,-0.75,-3.5);
    glVertex3f(0.9,-0.75,-3.5);
    glVertex3f(0.9,-1.5,-3.5);
    glVertex3f(1.9,-1.5,-3.5);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glVertex3f(1.9,-0.75,-3);
    glVertex3f(0.9,-1.5,-3);
    glVertex3f(0.9,-1.5,-3.5);
    glVertex3f(1.9,-0.75,-3.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(0.9,-0.75,-3);
    glVertex3f(0.9,-1.5,-3);
    glVertex3f(0.9,-1.5,-3.5);
    glVertex3f(0.9,-0.75,-3.5);
    glEnd();


    // SEGUNDA

    // front
    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.9,-0.5,-2);
    glVertex3f(0.9,-0.5,-2);
    glVertex3f(0.9,-1.5,-2);
    glVertex3f(1.9,-1.5,-2);
    glEnd();

    // back
    glPushMatrix();
    glBegin(GL_QUADS);  // Wall
    glVertex3f(1.9,-0.75,-2.5);
    glVertex3f(0.9,-0.75,-2.5);
    glVertex3f(0.9,-1.5,-2.5);
    glVertex3f(1.9,-1.5,-2.5);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glVertex3f(1.9,-0.75,-2);
    glVertex3f(0.9,-1.5,-2);
    glVertex3f(0.9,-1.5,-2.5);
    glVertex3f(1.9,-0.75,-2.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(0.9,-0.75,-2);
    glVertex3f(0.9,-1.5,-2);
    glVertex3f(0.9,-1.5,-2.5);
    glVertex3f(0.9,-0.75,-2.5);
    glEnd();

    // TERCEIRA

    // front
    glPushMatrix();
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(1.9,-0.5,-1);
    glVertex3f(0.9,-0.5,-1);
    glVertex3f(0.9,-1.5,-1);
    glVertex3f(1.9,-1.5,-1);
    glEnd();

    // back
    glPushMatrix();
    glBegin(GL_QUADS);  // Wall
    glVertex3f(1.9,-0.75,-1.5);
    glVertex3f(0.9,-0.75,-1.5);
    glVertex3f(0.9,-1.5,-1.5);
    glVertex3f(1.9,-1.5,-1.5);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glVertex3f(1.9,-0.75,-1);
    glVertex3f(0.9,-1.5,-1);
    glVertex3f(0.9,-1.5,-1.5);
    glVertex3f(1.9,-0.75,-1.5);
    glEnd();

    glBegin(GL_QUADS); //right
    glVertex3f(0.9,-0.75,-1);
    glVertex3f(0.9,-1.5,-1);
    glVertex3f(0.9,-1.5,-1.5);
    glVertex3f(0.9,-0.75,-1.5);
    glEnd();

    //============== END CADEIRA DIREITA ===================


    glPopMatrix();
}

void drawFloor(){

    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glBegin(GL_QUADS);  // Floor 1
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.0f, -1.2001f, -6.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.0f, -1.2001f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 2.0f, -1.2001f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 2.0f, -1.2001f, -6.0f);
    glEnd();
}

void drawChurch(){

    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glLineWidth(2.5);

    drawFloor();
    drawTower();
    drawFront();
    drawBack();
    drawSides();
    drawWindowsLeft();
    drawWindowsRight();
    drawAltar();
    drawCruz();
    drawChair();
}

void drawDoor() {

    glPushMatrix();
    glTranslatef(-0.3, 0.5f, 1);
    glRotatef (door_angle, 0,1,0);
    glTranslatef(0.8, 0, 0);
    glColor3f(0.0f, 0.5f, 0.0f);
    glScalef(0.6, 1.1, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void changeSize(int w, int h){

    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void drawGround(){
    // Draw ground
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();
}

void renderScene(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Set the camera
    gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    drawGround();
    drawChurch();
    drawDoor();

    glFlush();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
            break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
            break;

        case 27:
            exit(0);
            break;
    }
}

void processSpecialKeys(int key, int xx, int yy){

    float fraction = 0.5f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("Igreja de São Gonçalo");

    init();

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 1;
}