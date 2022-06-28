#include<Windows.h>
#include<glut.h>
#include<math.h> //needed so that we can create a circle

#define PI  3.14159265359
void clouds();
void circle();
void street();
void house();
void eyeMonster();
void Person();
void myKeyboard();
void animation();

GLfloat moverx = -47;
GLfloat moveP = -80;
GLfloat move = 0;
GLfloat flagt = 0;

void sky() {
	glClearColor(135.0 / 255, 206.0 / 255, 235.0 / 255, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 0, 220, 0, 0, 0, 0, 1, 0);
	//glclearcolour value ranges from 0 - 1 so must convert our hex colour.
	//the sun

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	//lighting for sun
	GLfloat sunlight[] = { 1,1,1,1 };

	GLfloat glow[] = { 0.97,0.96,0.93,1 };

	GLfloat spc[] = { 1.0,1.0,1.0,0 };
	GLfloat pos[] = { 0.0,0.0,-1.0, 0 };//the light source is directional

	glLightfv(GL_LIGHT0, GL_AMBIENT, sunlight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, glow);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spc);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);


	glColor3ub(250, 218, 7);

	glPushMatrix();
	glScaled(35, 35, 0);
	glTranslated(-2.5, 2.5, 0);
	circle();
	glPopMatrix();


	clouds();

	street();

	animation();

	glutSwapBuffers();
}
void clouds() {
	//cloud 1
	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(60, 60, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(50, 60, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(70, 60, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(60, 67, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();

	//cloud 2

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(50, 75, 0);
	glScaled(15, 15, 15);
	circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(40, 80, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(30, 75, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(242, 239, 244);
	glTranslatef(40, 74, 0);
	glScaled(20, 20, 20);
	circle();
	glPopMatrix();
}

void street()
{
	//changed all gl_quads into solid cubes is due to the fact solidcubes werent affected by the lighting.

	//grass
	glColor3ub(120, 200, 80);
	glPushMatrix();
	glTranslated(0, -46.2, 0);
	glScaled(18, 1.2, 1);
	glutSolidCube(12);
	glPopMatrix();

	//pavement

	glColor3ub(171, 169, 161);
	glPushMatrix();
	glTranslated(0, -60, 0);
	glScaled(18, 1, 1);
	glutSolidCube(10);
	glPopMatrix();


	glColor3ub(153, 152, 147);
	//pavement lines
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2d(-100, -55);
	glVertex2d(-90, -67);
	glVertex2d(-60, -55);
	glVertex2d(-50, -67);
	glVertex2d(-20, -55);
	glVertex2d(-10, -67);
	glVertex2d(20, -55);
	glVertex2d(30, -67);
	glVertex2d(60, -55);
	glVertex2d(70, -67);
	glEnd();
	glBegin(GL_QUADS); // for the pavement shadow
	glVertex2d(-100, -100);
	glVertex2d(-100, -66);
	glVertex2d(100, -66);
	glVertex2d(100, -100);
	glEnd();

	//street
	glColor3ub(102, 109, 114);
	glBegin(GL_QUADS);
	glVertex2d(-100, -100);
	glVertex2d(-100, -68);
	glVertex2d(100, -68);
	glVertex2d(100, -100);
	glEnd();

	//street lines

	glColor3ub(255, 255, 20);

	glBegin(GL_QUADS);
	glVertex2d(-100, -75);
	glVertex2d(-100, -80);
	glVertex2d(-80, -80);
	glVertex2d(-80, -75);

	glVertex2d(-60, -75);
	glVertex2d(-60, -80);
	glVertex2d(20, -80);
	glVertex2d(20, -75);

	glVertex2d(40, -75);
	glVertex2d(40, -80);
	glVertex2d(100, -80);
	glVertex2d(100, -75);
	glEnd();

	//hotel
	glPushMatrix();
	glTranslatef(-50, 11, 0);
	glScalef(0.2, 0.2, 0.2);
	house();
	glPopMatrix();

	//house
	glPushMatrix();
	glTranslatef(60, -22, 0);
	glScalef(0.3, 0.1, 0.2);
	house();
	glPopMatrix();

	//lamps
	glColor3ub(117, 74, 21);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(73, 4, -40); // x z -y
	gluCylinder(gluNewQuadric(), 1.5, 1.5, 80, 100, 100); //long pole
	glTranslated(0, 0, 66);
	gluCylinder(gluNewQuadric(), 3, 3, 30, 100, 100); //bottom pole
	glPopMatrix();
	glPushMatrix();
	glTranslated(70, 33, 5);
	glRotated(1, 0, 1, 0);
	gluCylinder(gluNewQuadric(), 1.5, 1.5, 44, 100, 100); //pole carrying the light
	glPopMatrix();
}

void eyeMonster() {
	glEnable(GL_BLEND); //must be enabled for opacity to work
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//the eye
	glTranslated(0, 8, 0);
	glColor3ub(155, 25, 25);
	glutSolidSphere(8, 50, 50);

	glColor3ub(255, 255, 255);
	glutSolidSphere(6, 50, 50);

	glColor3ub(100, 31, 51);
	glutSolidSphere(2, 50, 50);

	glColor3ub(1, 1, 1);
	glutSolidSphere(1, 50, 50);

	glScaled(15, 14, 1);
	int numpoints = 400;
	float rad = 0.5;

	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		float angle = i * (2.0 * PI / numpoints);
		float x = cos(angle) * rad;
		float y = sin(angle) * rad;

		glVertex2d(x, y);
	}
	glEnd();

}

void circle() {
	int numpoints = 400;
	float rad = 0.5;

	glBegin(GL_POLYGON);
	for (int i = 0; i < numpoints; i++)
	{
		float angle = i * (2.0 * PI / numpoints);
		float x = cos(angle) * rad;
		float y = sin(angle) * rad;

		glVertex2d(x, y);
	}
	glEnd();

}

void house() {

	//house structure 
	glColor3ub(255, 215, 174);

	glPushMatrix();
	glScaled(1, 3, 0);
	glutSolidCube(220);
	glPopMatrix();


	// front door 
	glColor3ub(106, 53, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-50, -70);
	glVertex2f(50, -70);
	glVertex2f(-50, -279);
	glVertex2f(50, -279);
	glVertex2f(50, -115);
	glVertex2f(50, -80);
	glVertex2i(50, -71);

	glEnd();

	//door line 
	glColor3ub(66, 33, 0);

	glBegin(GL_LINES);
	glVertex2f(0, -70);
	glVertex2f(0, -279);
	glEnd();
	glPointSize(5);
	glColor3ub(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(10, -200);
	glVertex2i(-10, -200);
	glEnd();

	//lower left window 
	glColor3f(0.3, 0.5, 0.7);

	glBegin(GL_POLYGON);
	glVertex2f(-20, 25);
	glVertex2f(-20, 100);
	glVertex2f(-60, 100);
	glVertex2f(-60, 25);
	glEnd();

	//lowwer right window 
	glColor3f(0.3, 0.5, 0.7);

	glBegin(GL_POLYGON);
	glVertex2f(20, 25);
	glVertex2f(20, 100);
	glVertex2f(60, 100);
	glVertex2f(60, 25);
	glEnd();

	//uper left window 
	glColor3f(0.3, 0.5, 0.7);

	glBegin(GL_POLYGON);
	glVertex2f(-20, 225);
	glVertex2f(-20, 150);
	glVertex2f(-60, 150);
	glVertex2f(-60, 225);
	glEnd();

	//upper right window 
	glColor3f(0.3, 0.5, 0.7);

	glBegin(GL_POLYGON);
	glVertex2f(20, 225);
	glVertex2f(20, 150);
	glVertex2f(60, 150);
	glVertex2f(60, 225);
	glEnd();
}

void Person() {

	//head 

	glColor3ub(193, 138, 108);
	glutSolidSphere(100, 10, 70);

	//body

	glColor3ub(0, 138, 108);
	glBegin(GL_POLYGON);
	glVertex2i(-100, -100);
	glVertex2i(-100, -400);
	glVertex2i(100, -100);
	glVertex2i(100, -400);
	glVertex2i(0, -400);
	glVertex2i(-90, -400);
	glEnd();

	//legs

	glColor3ub(0, 0, 108);
	glLineWidth(8);
	glBegin(GL_LINES);
	glVertex2i(-70, -401);
	glVertex2i(-70, -580);
	glVertex2i(70, -401);
	glVertex2i(70, -580);

	glEnd();

	//eyes
	glPointSize(5);
	glColor3ub(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(-30, 40);
	glVertex2i(30, 40);
	glEnd();

	//smile 
	glLineWidth(3);
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(-30, -20);
	glVertex2i(30, -20);
	glEnd();

	//hands 
  //left hand

	glLineWidth(10);
	glColor3ub(0, 138, 108);
	glBegin(GL_LINES);
	glVertex2i(-80, -100);
	glVertex2i(-200, -400);
	glEnd();
	//right hand 
	glLineWidth(10);
	glColor3ub(0, 138, 108);
	glBegin(GL_LINES);
	glVertex2i(80, -100);
	glVertex2i(200, -400);
	glEnd();


	//SwapBuffers();


}

void animation() {

	//the move variable controls movement of object once clicking q or w
	//the moveP and moverx variables controls movement of object once clicking a or e

	//used y = a sin (bx + c) to implement bouncing of monster
	//as a increases so does the peak of amplitude.
	//as 
	glPushMatrix();
	glTranslated(moveP + move, -60 + 4 * sin(move / 5), 0); //used sine instead of cosine because sin(0) is 0
	eyeMonster();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(moverx + move, -30, 0);
	glScalef(0.5, 0.5, 0.1);
	glScalef(0.1, 0.1, 0.1);
	Person();
	glPopMatrix();

	if (flagt == 1) {
		move = move + 0.5;
	}
	if (flagt == -1) {
		move = 0;
		moveP = -80;
		moverx = -47;
		flagt = 0;
	}
	if (moveP + move > 110)
		moveP -= 200;
	if (moverx + move > 110)
		moverx -= 200;


}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	switch (theKey)
	{
	case 'a':
		moverx += 3;
		break;
	case 'e':
		moveP += 3;
		break;
	case 'q':
		flagt = 1;
		break;
	case 'w':
		flagt = -1;
		break;
	default:
		break;
	}
}


int main() {

	//initialising functions
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
	//glut_double needed for animation
	//glut_depth helps in drawing objects on top one anorther.

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("The house");

	//rendering functions
	glutDisplayFunc(sky);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 30, 220); //aparently z-near should be positive
	glMatrixMode(GL_MODELVIEW);
	glutIdleFunc(sky);

	glutKeyboardFunc(myKeyboard);
	glutMainLoop();

}