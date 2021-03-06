#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//#include <windows.h>
//#include <cmath>

//tb = tembok
//lt = lantai

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
int is_depth;

float cameraAngle = 0.0;
float x = 0, y = 3, z = 25;//posisi kamera
float lx = 0, ly = 0, lz = -1;

void rotateCamera(float ang) {
    // rotate the camera (left / right)
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
}

void moveCamera(int h_direction, int v_direction) {
    // move the camera (forward, backward, up, down)
    x = x + h_direction*(lx)*0.3;
    z = z + h_direction*(lz)*0.3;
    y = y + v_direction*0.1;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
}

void pressKey(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_LEFT :
            cameraAngle -= 0.02;
            rotateCamera(cameraAngle);
            break;
        case GLUT_KEY_RIGHT :
            cameraAngle += 0.02;
            rotateCamera(cameraAngle);
            break;
        case GLUT_KEY_UP :
            moveCamera(1, 0);
            break;
        case GLUT_KEY_DOWN :
            moveCamera(-1, 0);
            break;
        case GLUT_KEY_PAGE_UP :
            moveCamera(0, 1);
            break;
        case GLUT_KEY_PAGE_DOWN :
            moveCamera(0, -1);
            break;
    }

    glutPostRedisplay();
}

void awan(void){
   //awan 1
 glPushMatrix();
 glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
 glColor3ub(224, 224, 225);
 glTranslatef(0,95,1); //0,85, 1 +10
 glutSolidSphere(10, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(10,95,1);
 glutSolidSphere(5, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-2,101,-2);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-10,91,0);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(6,93,2);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();

 //awan 2
 glPushMatrix();
 //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
 glColor3ub(224, 224, 225);
 glTranslatef(-30,85,-70); // -5 -56 // 1,1,-2,0,2
 glutSolidSphere(10, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-20,85,-70);
 glutSolidSphere(5, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-28,91,-67);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-40,81,-69);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-24,83,-71);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();

 //awan 3
 glPushMatrix();
 //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
 glColor3ub(224, 224, 225);
 glTranslatef(70,85,-40); //0, 85, 1
 glutSolidSphere(10, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(80,85,-40);
 glutSolidSphere(5, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(68,91,-42);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(60,81,-40);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(76,83,-39);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();

 }

//lt1
void pojokandpn(){

   //pojokan segi kiri
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(-60, 20, 10);
	glVertex3f(-60, -20, 10);
	glVertex3f(-65, -20, 20);
	glVertex3f(-65, 20, 20);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(-65, 20, 20);
	glVertex3f(-65, -20, 20);
	glVertex3f(-70, -20, 20);
	glVertex3f(-70, 20, 20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(-70, 20, 20);
	glVertex3f(-70, -20, 20);
	glVertex3f(-75, -20, 15);
	glVertex3f(-75, 20, 15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-75, 20, 15);
	glVertex3f(-75, -20, 15);
	glVertex3f(-75, -20, 5);
	glVertex3f(-75, 20, 5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-75, 20, 5);
	glVertex3f(-75, -20, 5);
	glVertex3f(-70, -20, 0);
	glVertex3f(-70, 20, 0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(-70, 20, 0);
	glVertex3f(-70, -20, 0);
	glVertex3f(-65, -20, 0);
	glVertex3f(-65, 20, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(-60, 20, 10);
	glVertex3f(-65, 20, 20);
	glVertex3f(-70, 20, 20);
	glVertex3f(-75, 20, 15);
	glVertex3f(-75, 20, 5);
	glVertex3f(-70, 20, 0);
	glVertex3f(-65, 20, 0);
    glEnd();

    //pojokan segi kanan
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(60, 20, 10);
	glVertex3f(60, -20, 10);
	glVertex3f(65, -20, 20);
	glVertex3f(65, 20, 20);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(65, 20, 20);
	glVertex3f(65, -20, 20);
	glVertex3f(70, -20, 20);
	glVertex3f(70, 20, 20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(70, 20, 20);
	glVertex3f(70, -20, 20);
	glVertex3f(75, -20, 15);
	glVertex3f(75, 20, 15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(75, 20, 15);
	glVertex3f(75, -20, 15);
	glVertex3f(75, -20, 5);
	glVertex3f(75, 20, 5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(75, 20, 5);
	glVertex3f(75, -20, 5);
	glVertex3f(70, -20, 0);
	glVertex3f(70, 20, 0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(70, 20, 0);
	glVertex3f(70, -20, 0);
	glVertex3f(65, -20, 0);
	glVertex3f(65, 20, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(60, 20, 10);
	glVertex3f(65, 20, 20);
	glVertex3f(70, 20, 20);
	glVertex3f(75, 20, 15);
	glVertex3f(75, 20, 5);
	glVertex3f(70, 20, 0);
	glVertex3f(65, 20, 0);
    glEnd();

}

void tbdpn(){

    pojokandpn();
    //Tb,kiridpn
	glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(-65, 20, 10);
	glVertex3f(-20, 20, 10);
	glVertex3f(-20, -20, 10);
	glVertex3f(-65,-20, 10);
	glEnd();
	//miringan kiri
	glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(-55, 20, 10);
	glVertex3f(-55, -20, 10);
	glVertex3f(-35, -20, 40);
	glVertex3f(-35, 20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(-50, 20, 10);
	glVertex3f(-50, -20, 10);
	glVertex3f(-30, -20, 40);
	glVertex3f(-30, 20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(222, 209, 124);
	glVertex3f(-55, 20, 10);
	glVertex3f(-50, 20, 10);
	glVertex3f(-30, 20, 40);
	glVertex3f(-35, 20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(-35, 20, 40);
	glVertex3f(-30, 20, 40);
	glVertex3f(-30, -20, 40);
	glVertex3f(-35, -20, 40);
	glEnd();

    //segi lima kiri
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(-20, 20, 10);
	glVertex3f(-20, -20, 10);
	glVertex3f(-20, -20, 15);
	glVertex3f(-20, 20, 15);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(-20, 20, 15);
	glVertex3f(-20, -20, 15);
	glVertex3f(-15, -20, 20);
	glVertex3f(-15, 20, 20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(201, 189, 107);
	glVertex3f(-15, 20, 20);
	glVertex3f(-15, -20, 20);
	glVertex3f(-10, -20, 20);
	glVertex3f(-10, 20, 20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-10, 20, 20);
	glVertex3f(-10, -20, 20);
	glVertex3f(-5, -20, 15);
	glVertex3f(-5, 20, 15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-5, 20, 15);
	glVertex3f(-5, -20, 15);
	glVertex3f(-5, -20, 10);
	glVertex3f(-5, 20, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 151, 82);
	glVertex3f(-20, 20, 10);
	glVertex3f(-20, 20, 15);
	glVertex3f(-15, 20, 20);
	glVertex3f(-10, 20, 20);
	glVertex3f(-5, 20, 15);
	glVertex3f(-5, 20, 10);
    glEnd();

    //area pintu
    glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(-5,20,10);
	glVertex3f(5, 20, 10);
	glVertex3f(5, -20, 10);
	glVertex3f(-5,-20,10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(112, 99, 73);
	glVertex3f(-2,5,10);
	glVertex3f(-2, 10, 10);
	glVertex3f(0, 13, 10);
	glVertex3f(2, 10,10);
	glVertex3f(2, 5, 10);
	glEnd();
    glBegin(GL_POLYGON);
	glColor3ub(181, 177, 168);
	glVertex3f(-2,5,10);
	glVertex3f(2, 5, 10);
	glVertex3f(2, 5, 30);
	glVertex3f(-2, 5,30);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(181, 177, 168);
	glVertex3f(-2,5,30);
	glVertex3f(2, 5, 30);
	glVertex3f(2, 3, 30);
	glVertex3f(-2, 3,30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(-3,3,10);
	glVertex3f(3, 3, 10);
	glVertex3f(3, 3, 30);
	glVertex3f(-3, 3,30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(-3,3,10);
	glVertex3f(-3, 6, 10);
	glVertex3f(-3, 6, 30);
	glVertex3f(-3, 3,30);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(3,3,10);
	glVertex3f(3, 6, 10);
	glVertex3f(3, 6, 30);
	glVertex3f(3, 3,30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(-3,6,10);
	glVertex3f(-2, 6, 10);
	glVertex3f(-2, 6, 30);
	glVertex3f(-3, 3,30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(3,6,10);
	glVertex3f(2, 6, 10);
	glVertex3f(2, 6, 30);
	glVertex3f(3, 3,30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150, 149, 144);
	glVertex3f(-2,6,10);
	glVertex3f(-2, 6, 30);
	glVertex3f(-2, 5, 30);
	glVertex3f(-2, 5,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150, 149, 144);
	glVertex3f(2,6,10);
	glVertex3f(2, 6, 30);
	glVertex3f(2, 5, 30);
	glVertex3f(2, 5,10);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(3, 6, 30);
	glVertex3f(2, 6, 30);
	glVertex3f(2, 3, 30);
	glVertex3f(3, 3, 30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(181, 177, 168);
	glVertex3f(-3, 6, 30);
	glVertex3f(-2, 6, 30);
	glVertex3f(-2, 3, 30);
	glVertex3f(-3, 3, 30);
	glEnd();


	//Tb,knandpn
	glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(20,20,10);
	glVertex3f(65, 20, 10);
	glVertex3f(65, -20, 10);
	glVertex3f(20,-20,10);
	glEnd();
	//segi lima kanan
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(20, 20, 10);
	glVertex3f(20, -20, 10);
	glVertex3f(20, -20, 15);
	glVertex3f(20, 20, 15);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(20, 20, 15);
	glVertex3f(20, -20, 15);
	glVertex3f(15, -20, 20);
	glVertex3f(15, 20, 20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(15, 20, 20);
	glVertex3f(15, -20, 20);
	glVertex3f(10, -20, 20);
	glVertex3f(10, 20, 20);
    glEnd();
	glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(10, 20, 20);
	glVertex3f(10, -20, 20);
	glVertex3f(5, -20, 15);
	glVertex3f(5, 20, 15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(5, 20, 15);
	glVertex3f(5, -20, 15);
	glVertex3f(5, -20, 10);
	glVertex3f(5, 20, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 151, 82);
	glVertex3f(20, 20, 10);
	glVertex3f(20, 20, 15);
	glVertex3f(15, 20, 20);
	glVertex3f(10, 20, 20);
	glVertex3f(5, 20, 15);
	glVertex3f(5, 20, 10);
    glEnd();

}

void tbkanan(){

    //Tb,knan
	glBegin(GL_POLYGON);
	glColor3ub(148, 139, 84);
	glVertex3f(65,20,10);
	glVertex3f(65, -20, 10);
	glVertex3f(65, -20, -100);
	glVertex3f(65,20,-100);
	glEnd();

}

void tbblkang(){

    //Tbblkng
    glBegin(GL_POLYGON);
	glColor3ub(148, 139, 84);
	glVertex3f(65,20,-100);
	glVertex3f(-65, 20, -100);
	glVertex3f(-65, -20, -100);
	glVertex3f(65,-20,-100);
	glEnd();

	//pojokan segi kiri
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(-60, 20, -100);
	glVertex3f(-60, -20, -100);
	glVertex3f(-65, -20, -110);
	glVertex3f(-65, 20, -110);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(-65, 20, -110);
	glVertex3f(-65, -20, -110);
	glVertex3f(-70, -20, -110);
	glVertex3f(-70, 20, -110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(-70, 20, -110);
	glVertex3f(-70, -20, -110);
	glVertex3f(-75, -20, -105);
	glVertex3f(-75, 20, -105);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-75, 20, -105);
	glVertex3f(-75, -20, -105);
	glVertex3f(-75, -20, -95);
	glVertex3f(-75, 20, -95);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-75, 20, -95);
	glVertex3f(-75, -20, -95);
	glVertex3f(-70, -20, -90);
	glVertex3f(-70, 20, -90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(-70, 20, -90);
	glVertex3f(-70, -20, -90);
	glVertex3f(-65, -20, -90);
	glVertex3f(-65, 20, -90);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(-60, 20, -100);
	glVertex3f(-65, 20, -110);
	glVertex3f(-70, 20, -110);
	glVertex3f(-75, 20, -105);
	glVertex3f(-75, 20, -95);
	glVertex3f(-70, 20, -90);
	glVertex3f(-65, 20, -90);
    glEnd();

    //pojokan segi kiri
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(60, 20, -100);
	glVertex3f(60, -20, -100);
	glVertex3f(65, -20, -110);
	glVertex3f(65, 20, -110);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(65, 20, -110);
	glVertex3f(65, -20, -110);
	glVertex3f(70, -20, -110);
	glVertex3f(70, 20, -110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(70, 20, -110);
	glVertex3f(70, -20, -110);
	glVertex3f(75, -20, -105);
	glVertex3f(75, 20, -105);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(75, 20, -105);
	glVertex3f(75, -20, -105);
	glVertex3f(75, -20, -95);
	glVertex3f(75, 20, -95);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(75, 20, -95);
	glVertex3f(75, -20, -95);
	glVertex3f(70, -20, -90);
	glVertex3f(70, 20, -90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(70, 20, -90);
	glVertex3f(70, -20, -90);
	glVertex3f(65, -20, -90);
	glVertex3f(65, 20, -90);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(60, 20, -100);
	glVertex3f(65, 20, -110);
	glVertex3f(70, 20, -110);
	glVertex3f(75, 20, -105);
	glVertex3f(75, 20, -95);
	glVertex3f(70, 20, -90);
	glVertex3f(65, 20, -90);
	glEnd();


}

void tbkiri(){

    //tbkiri
    glBegin(GL_POLYGON);
	glColor3ub(148, 139, 84);
	glVertex3f(-65,20,10);
	glVertex3f(-65, -20, 10);
	glVertex3f(-65, -20, -100);
	glVertex3f(-65,20,-100);
	glEnd();


}

void furnitur(){

    glBegin(GL_POLYGON);
	glColor3ub(54, 112, 35);
	glVertex3f(-80,-20,40);
	glVertex3f(80, -20, 40);
	glVertex3f(80, -20, -120);
	glVertex3f(-80,-20,-120);
	glEnd();
    //lantai
	glBegin(GL_POLYGON);
	glColor3ub(247, 241, 218);
	glVertex3f(-65,-20,10);
	glVertex3f(65, -20, 10);
	glVertex3f(65, -20, -100);
	glVertex3f(-65,-20,-100);
	glEnd();


	//kasurkanan
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(55,-20,-20);
	glVertex3f(35, -20, -20);
	glVertex3f(35, -20, -5);
	glVertex3f(55,-20,-5);
	glEnd();
	//dpn
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(55,-20,-5);
	glVertex3f(35, -20, -5);
	glVertex3f(35, -18, -5);
	glVertex3f(55,-18,-5);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(35,-20,-20);
	glVertex3f(35, -18, -20);
	glVertex3f(35, -18, -5);
	glVertex3f(35,-20,-5);
	glEnd();
	//kasur
	glBegin(GL_POLYGON);
	glColor3ub(43, 49, 82);
	glVertex3f(55,-18,-20);
	glVertex3f(35, -18, -20);
	glVertex3f(35, -18, -5);
	glVertex3f(55,-18,-5);
	glEnd();
	//dpn
	glBegin(GL_POLYGON);
	glColor3ub(28, 34, 64);
	glVertex3f(55,-18,-5);
	glVertex3f(35, -18, -5);
	glVertex3f(35, -16, -5);
	glVertex3f(55,-16,-5);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3ub(28, 34, 64);
	glVertex3f(35,-18,-20);
	glVertex3f(35, -16, -20);
	glVertex3f(35, -16, -5);
	glVertex3f(35,-18,-5);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3ub(43, 49, 82);
	glVertex3f(55,-16,-20);
	glVertex3f(35, -16, -20);
	glVertex3f(35, -16, -5);
	glVertex3f(55,-16,-5);
	glEnd();

	//kasurkiri
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(-55,-20,-20);
	glVertex3f(-35, -20, -20);
	glVertex3f(-35, -20, -5);
	glVertex3f(-55,-20,-5);
	glEnd();
	//dpn
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(-55,-20,-5);
	glVertex3f(-35, -20, -5);
	glVertex3f(-35, -18, -5);
	glVertex3f(-55,-18,-5);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(-35,-20,-20);
	glVertex3f(-35, -18, -20);
	glVertex3f(-35, -18, -5);
	glVertex3f(-35,-20,-5);
	glEnd();
	//kasur
	glBegin(GL_POLYGON);
	glColor3ub(43, 49, 82);
	glVertex3f(-55,-18,-20);
	glVertex3f(-35, -18, -20);
	glVertex3f(-35, -18, -5);
	glVertex3f(-55,-18,-5);
	glEnd();
	//dpn
	glBegin(GL_POLYGON);
	glColor3ub(28, 34, 64);
	glVertex3f(-55,-18,-5);
	glVertex3f(-35, -18, -5);
	glVertex3f(-35, -16, -5);
	glVertex3f(-55,-16,-5);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3ub(28, 34, 64);
	glVertex3f(-35,-18,-20);
	glVertex3f(-35, -16, -20);
	glVertex3f(-35, -16, -5);
	glVertex3f(-35,-18,-5);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3ub(43, 49, 82);
	glVertex3f(-55,-16,-20);
	glVertex3f(-35, -16, -20);
	glVertex3f(-35, -16, -5);
	glVertex3f(-55,-16,-5);
	glEnd();

	//lemarikanan
	glBegin(GL_POLYGON);
	glColor3ub(84, 71, 20);
	glVertex3f(20,-20,20);
	glVertex3f(35, -20, 20);
	glVertex3f(35, -20, 10);
	glVertex3f(20,-20,10);
	glEnd();
	//blkang
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(20,-20,10);
	glVertex3f(35,-20, 10);
	glVertex3f(35, 6, 10);
	glVertex3f(20, 6,10);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(35,-20,10);
	glVertex3f(35, 6, 10);
	glVertex3f(35, 6, 20);
	glVertex3f(35,-20,20);
	glEnd();
	//atas
    glBegin(GL_POLYGON);
	glColor3ub(84, 71, 20);
	glVertex3f(20, 6,20);
	glVertex3f(35, 6, 20);
	glVertex3f(35, 6, 10);
	glVertex3f(20, 6,10);
	glEnd();

	//lemarikiri
	glBegin(GL_POLYGON);
	glColor3ub(84, 71, 20);
	glVertex3f(-20,-20,20);
	glVertex3f(-35, -20, 20);
	glVertex3f(-35, -20, 10);
	glVertex3f(-20,-20,10);
	glEnd();
	//blkang
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(-20,-20,10);
	glVertex3f(-35,-20, 10);
	glVertex3f(-35, 6, 10);
	glVertex3f(-20, 6,10);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3ub(184, 160, 64);
	glVertex3f(-35,-20,10);
	glVertex3f(-35, 6, 10);
	glVertex3f(-35, 6, 20);
	glVertex3f(-35,-20,20);
	glEnd();
	//atas
    glBegin(GL_POLYGON);
	glColor3ub(84, 71, 20);
	glVertex3f(-20, 6,20);
	glVertex3f(-35, 6, 20);
	glVertex3f(-35, 6, 10);
	glVertex3f(-20, 6,10);
	glEnd();

	//tempatsampahkanan
	glBegin(GL_POLYGON);
	glColor3ub(74, 73, 68);
	glVertex3f(55,-20, 20);
	glVertex3f(50,-20, 20);
	glVertex3f(50,-20, 15);
	glVertex3f(55,-20, 15);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3ub(204, 202, 192);
	glVertex3f(50,-20, 20);
	glVertex3f(50,-15, 20);
	glVertex3f(50,-15, 15);
	glVertex3f(50,-20, 15);
	glEnd();
	//blkng
	glBegin(GL_POLYGON);
	glColor3ub(204, 202, 192);
	glVertex3f(50,-20, 15);
	glVertex3f(55,-20, 15);
	glVertex3f(55,-15, 15);
	glVertex3f(50,-15, 15);
	glEnd();

	//tempatsampahkiri
	glBegin(GL_POLYGON);
	glColor3ub(74, 73, 68);
	glVertex3f(-55,-20, 20);
	glVertex3f(-50,-20, 20);
	glVertex3f(-50,-20, 15);
	glVertex3f(-55,-20, 15);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3ub(204, 202, 192);
	glVertex3f(-50,-20, 20);
	glVertex3f(-50,-15, 20);
	glVertex3f(-50,-15, 15);
	glVertex3f(-50,-20, 15);
	glEnd();
	//blkng
	glBegin(GL_POLYGON);
	glColor3ub(204, 202, 192);
	glVertex3f(-50,-20, 15);
	glVertex3f(-55,-20, 15);
	glVertex3f(-55,-15, 15);
	glVertex3f(-50,-15, 15);
	glEnd();

	//karpet
	glBegin(GL_POLYGON);
	glColor3ub(81, 176, 171);
	glVertex3f(55, -20,-40);
	glVertex3f(20, -20,-40);
	glVertex3f(20, -20,-80);
	glVertex3f(55, -20,-80);
	glEnd();

	//kulkas
	glBegin(GL_POLYGON);
	glColor3ub(122, 91, 106);
	glVertex3f(-55, -20,-65);
	glVertex3f(-40, -20,-65);
	glVertex3f(-40, -20,-80);
	glVertex3f(-55, -20,-80);
	glEnd();
	//dpn
	glBegin(GL_POLYGON);
	glColor3ub(168, 111, 139);
	glVertex3f(-55, -20,-65);
	glVertex3f(-40, -20,-65);
	glVertex3f(-40, 0,-65);
	glVertex3f(-55, 0,-65);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3ub(168, 111, 139);
	glVertex3f(-40, -20,-80);
	glVertex3f(-40, 5,-80);
	glVertex3f(-40, 5,-65);
	glVertex3f(-40, -20,-65);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3ub(122, 91, 106);
	glVertex3f(-55, 5,-65);
	glVertex3f(-40, 5,-65);
	glVertex3f(-40, 5,-80);
	glVertex3f(-55, 5,-80);
	glEnd();

	 //pohon
    glPushMatrix();
	glColor3ub(135, 120, 70);
    glTranslatef(20,-20,30);
    glRotatef(-180.0f,0.0f,20.0f,20.0f);
    glutSolidCone(1, 8, 5,10);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(141, 230, 106);
    glTranslated(20, -10, 30);
    glScaled(5, 5, 5);
    glutSolidDodecahedron();
    glPopMatrix();


}

void atap(){

    //atapnya dag(dicor)
	glBegin(GL_POLYGON);
	glColor3ub(173, 170, 161);
	glVertex3f(-65, 20, 10);
	glVertex3f(65,  20, 10);
	glVertex3f(65,  20, -100);
	glVertex3f(-65, 20,-100);
	glEnd();

}

void barier(){

    //lampu
    glPushMatrix();
	glColor3ub(217, 191, 197);
    glTranslatef(10,6,42);
    glRotatef(-180.0f,0.0f,20.0f,20.0f);
    glutSolidCone(1, 8, 5,10);
    glPopMatrix();
    glPushMatrix();
	glColor3ub(240, 227, 46);
    glTranslatef(10,13,42);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();

    glPushMatrix();
	glColor3ub(217, 191, 197);
    glTranslatef(-10,6,42);
    glRotatef(-180.0f,0.0f,20.0f,20.0f);
    glutSolidCone(1, 8, 5,10);
    glPopMatrix();
    glPushMatrix();
	glColor3ub(240, 227, 46);
    glTranslatef(-10,13,42);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();


    //kiridpn
    glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-80, 6, 40);
	glVertex3f(-10, 6, 40);
	glVertex3f(-10, -20, 40);
	glVertex3f(-80, -20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-10, 6, 40);
	glVertex3f(-3, 6, 30);
	glVertex3f(-3, -20, 30);
	glVertex3f(-10, -20, 40);
	glEnd();


	//tnegah
    glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-3, 3, 30);
	glVertex3f(3, 3, 30);
	glVertex3f(3, -20, 30);
	glVertex3f(-3, -20, 30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-85, 6, 50);
	glVertex3f(85, 6, 50);
	glVertex3f(85, -20, 50);
	glVertex3f(-85, -20, 50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-85, 5, 40);
	glVertex3f(85, 5, 40);
	glVertex3f(85, 5, 50);
	glVertex3f(-85, 5, 50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-10, 5, 40);
	glVertex3f(-3, 5, 30);
	glVertex3f(3, 5, 30);
	glVertex3f(10, 5, 40);
	glEnd();

	//kanandpn
    glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(80, 6, 40);
	glVertex3f(10, 6, 40);
	glVertex3f(10, -20, 40);
	glVertex3f(80, -20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(10, 6, 40);
	glVertex3f(3, 6, 30);
	glVertex3f(3, -20, 30);
	glVertex3f(10, -20, 40);
	glEnd();

	//kiri
    glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-80, 6, 40);
	glVertex3f(-80, 6, -120);
	glVertex3f(-80, -20, -120);
	glVertex3f(-80, -20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-85, 6, 50);
	glVertex3f(-85, 6, -125);
	glVertex3f(-85, -20, -125);
	glVertex3f(-85, -20, 50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-80, 5, 50);
	glVertex3f(-85, 5, 50);
	glVertex3f(-85, 5, -125);
	glVertex3f(-80, 5, -125);
	glEnd();

	//kanan
    glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(80, 6, 40);
	glVertex3f(80, 6, -120);
	glVertex3f(80, -20, -120);
	glVertex3f(80, -20, 40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(85, 6, 50);
	glVertex3f(85, 6, -125);
	glVertex3f(85, -20, -125);
	glVertex3f(85, -20, 50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(80, 5, 50);
	glVertex3f(85, 5, 50);
	glVertex3f(85, 5, -125);
	glVertex3f(80, 5, -125);
	glEnd();

	//blakang
    glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(80, 6, -120);
	glVertex3f(-80, 6, -120);
	glVertex3f(-80, -20, -120);
	glVertex3f(80, -20, -120);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-85, 6, -125);
	glVertex3f(85, 6, -125);
	glVertex3f(85, -20, -125);
	glVertex3f(-85, -20, -125);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(99, 99, 94);
	glVertex3f(-85, 5, -120);
	glVertex3f(85, 5, -120);
	glVertex3f(85, 5, -125);
	glVertex3f(-85, 5, -125);
	glEnd();
}

//lt2
void tbdpn2(){

    //tbdpn
    glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(-35,60,-15);
	glVertex3f(30, 60, -15);
	glVertex3f(30, 20, -15);
	glVertex3f(-35,20,-15);
	glEnd();

	//towerkotak
	glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(30, 60, -30);
	glVertex3f(30, 20, -30);
	glVertex3f(30, 20, -5);
	glVertex3f(30, 60, -5);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(201, 189, 107);
	glVertex3f(30, 60, -5);
	glVertex3f(50, 60, -5);
	glVertex3f(50, 20, -5);
	glVertex3f(30, 20, -5);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(50, 60, -5);
	glVertex3f(50, 20, -5);
	glVertex3f(50, 20, -30);
	glVertex3f(50, 60, -30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(50, 60, -30);
	glVertex3f(50, 20, -30);
	glVertex3f(30, 20, -30);
	glVertex3f(30, 60, -30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(30, 60, -5);
	glVertex3f(50, 60, -5);
	glVertex3f(50, 60, -30);
	glVertex3f(30, 60, -30);
	glEnd();

	//pojokan segi kiri
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(-30, 60, -15);
	glVertex3f(-30, 20, -15);
	glVertex3f(-35, 20, -5);
	glVertex3f(-35, 60, -5);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(-35, 60, -5);
	glVertex3f(-35, 20, -5);
	glVertex3f(-40, 20, -5);
	glVertex3f(-40, 60, -5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(-40, 60, -5);
	glVertex3f(-40, 20, -5);
	glVertex3f(-45, 20, -10);
	glVertex3f(-45, 60, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-45, 60, -10);
	glVertex3f(-45, 20, -10);
	glVertex3f(-45, 20, -20);
	glVertex3f(-45, 60, -20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-45, 60, -20);
	glVertex3f(-45, 20, -20);
	glVertex3f(-40, 20, -25);
	glVertex3f(-40, 60, -25);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(-40, 60, -25);
	glVertex3f(-40, 20, -25);
	glVertex3f(-35, 20, -25);
	glVertex3f(-35, 60, -25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(-30, 60, -15);
	glVertex3f(-35, 60, -25);
	glVertex3f(-40, 60, -25);
	glVertex3f(-45, 60, -20);
	glVertex3f(-45, 60, -10);
	glVertex3f(-40, 60, -5);
	glVertex3f(-35, 60, -5);
    glEnd();
    //lt
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(-35, 60, -15);
	glVertex3f(35, 60, -15);
	glVertex3f(30, 60, -20);
	glVertex3f(-30, 60, -20);
	glEnd();
}

void tbkiri2(){
    //tb
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(-35,60,-15);
	glVertex3f(-35, 20, -15);
	glVertex3f(-35, 20, -70);
	glVertex3f(-35,60,-70);
	glEnd();
    //lt
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(-35, 60, -15);
	glVertex3f(-30, 60, -15);
	glVertex3f(-30, 60, -70);
	glVertex3f(-35, 60, -70);
	glEnd();
}

void tbkanan2(){

    //tembok
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(35, 60, -15);
	glVertex3f(35, 20, -15);
	glVertex3f(35, 20, -70);
	glVertex3f(35, 60, -70);
	glEnd();

    //lt
	glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(35, 60, -15);
	glVertex3f(30, 60, -15);
	glVertex3f(30, 60, -15);
	glVertex3f(35, 60, -15);
	glEnd();



}

void tbblkang2(){
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(-35, 60, -70);
	glVertex3f(-35, 20, -70);
	glVertex3f(35, 20, -70);
	glVertex3f(35, 60, -70);
	glEnd();

    //pojokan segi kiri
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(-30, 60, -70);
	glVertex3f(-30, 20, -70);
	glVertex3f(-35, 20, -80);
	glVertex3f(-35, 60, -80);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(-35, 60, -80);
	glVertex3f(-35, 20, -80);
	glVertex3f(-40, 20, -80);
	glVertex3f(-40, 60, -80);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(-40, 60, -80);
	glVertex3f(-40, 20, -80);
	glVertex3f(-45, 20, -75);
	glVertex3f(-45, 60, -75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-45, 60, -75);
	glVertex3f(-45, 20, -75);
	glVertex3f(-45, 20, -70);
	glVertex3f(-45, 60, -70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(-45, 60, -70);
	glVertex3f(-45, 20, -70);
	glVertex3f(-40, 20, -65);
	glVertex3f(-40, 60, -65);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(-40, 60, -65);
	glVertex3f(-40, 20, -65);
	glVertex3f(-35, 20, -65);
	glVertex3f(-35, 60, -65);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(-30, 60, -70);
	glVertex3f(-35, 60, -80);
	glVertex3f(-40, 60, -80);
	glVertex3f(-45, 60, -75);
	glVertex3f(-45, 60, -70);
	glVertex3f(-40, 60, -65);
	glVertex3f(-35, 60, -65);
    glEnd();

    //pojokan segi kanan
    glBegin(GL_QUADS);
	glColor3ub(166, 155, 80);
	glVertex3f(30, 60, -70);
	glVertex3f(30, 20, -70);
	glVertex3f(35, 20, -80);
	glVertex3f(35, 60, -80);
	glEnd();
    glBegin(GL_QUADS);
	glColor3ub(179, 167, 91);
	glVertex3f(35, 60, -80);
	glVertex3f(35, 20, -80);
	glVertex3f(40, 20, -80);
	glVertex3f(40, 60, -80);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 167, 91);
	glVertex3f(40, 60, -80);
	glVertex3f(40, 20, -80);
	glVertex3f(45, 20, -75);
	glVertex3f(45, 60, -75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(45, 60, -75);
	glVertex3f(45, 20, -75);
	glVertex3f(45, 20, -70);
	glVertex3f(45, 60, -70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(166, 155, 80);
	glVertex3f(45, 60, -70);
	glVertex3f(45, 20, -70);
	glVertex3f(40, 20, -65);
	glVertex3f(40, 60, -65);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(148, 139, 84);
	glVertex3f(40, 60, -65);
	glVertex3f(40, 20, -65);
	glVertex3f(35, 20, -65);
	glVertex3f(35, 60, -65);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(166, 155, 80);
	glVertex3f(30, 60, -70);
	glVertex3f(35, 60, -80);
	glVertex3f(40, 60, -80);
	glVertex3f(45, 60, -75);
	glVertex3f(45, 60, -70);
	glVertex3f(40, 60, -65);
	glVertex3f(35, 60, -65);
    glEnd();
    //lt
    glBegin(GL_QUADS);
	glColor3ub(148, 139, 84);
	glVertex3f(-35, 60, -70);
	glVertex3f(35, 60, -70);
	glVertex3f(30, 60, -65);
	glVertex3f(-30, 60, -65);
	glEnd();


}

void atap2(){

    //atapdpn
    glBegin(GL_QUADS);
	glColor3ub(201, 99, 26);
	glVertex3f(-30, 60, -20);
	glVertex3f(30, 60, -20);
	glVertex3f(20, 60, -30);
	glVertex3f(-20, 60, -30);
	glEnd();

	//atapkiri
    glBegin(GL_QUADS);
	glColor3ub(201, 99, 26);
	glVertex3f(-30, 60, -15);
	glVertex3f(-20, 60, -15);
	glVertex3f(-20, 60, -65);
	glVertex3f(-30, 60, -65);
	glEnd();

    //atapkanan
    glBegin(GL_QUADS);
	glColor3ub(201, 99, 26);
	glVertex3f(30, 60, -15);
	glVertex3f(20, 60, -15);
	glVertex3f(20, 60, -65);
	glVertex3f(30, 60, -65);
	glEnd();

    //atapblkng
	glBegin(GL_QUADS);
	glColor3ub(201, 99, 26);
	glVertex3f(-30, 60, -65);
	glVertex3f(30, 60, -65);
	glVertex3f(20, 60, -55);
	glVertex3f(-20, 60, -55);
	glEnd();


}


void hilang(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    awan();tbdpn();tbkiri();tbkanan();tbblkang();furnitur();barier();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();;
}

void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    awan();
    furnitur();
    tbblkang();
    tbkiri();
    tbkanan();
    atap();
    tbblkang2();
    tbkiri2();
    tbkanan2();
    atap2();
    tbdpn2();
    tbdpn();
    barier();
	glPushMatrix();
	glPopMatrix();

    glutSwapBuffers();

}
void display(){

     if (is_depth)
        tampil();
    else
        hilang();
}

void idle()
{
    if (!mouseDown)
    {
        xrot == 0.3f;
        yrot == 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}
void lookat()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}
void mouseMotion(int x, int y)
{
    lookat();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'q':
    case 'Q':

        break;
	case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
	case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6'://putar kanan
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4'://putar kiri
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            tampil();
        }
        else
        {
            is_depth = 1;
            hilang();
        }
    }
    display();
}


void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0.5, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Castillo de Coca, Kel. 9");
    init();
	glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();
    return 0;
}
