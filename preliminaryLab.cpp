#include <windows.h>
#include <GL\glut.h>
#include <math.h>

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Setting background color to black
	gluOrtho2D(-2, 2, -2, 2); // defining the cartesian plane
}

void MySquares() {

	float vertice = 1.0f;
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	//top line smaller square
	glVertex2f(-vertice, vertice);
	glVertex2f(vertice, vertice);
	//left line smaller square
	glVertex2f(-vertice, vertice);
	glVertex2f(-vertice, -vertice);
	//right line smaller square
	glVertex2f(vertice, vertice);
	glVertex2f(vertice, -vertice);
	//bottom line smaller square
	glVertex2f(-vertice, -vertice);
	glVertex2f(vertice, -vertice);
	//Drawing the small square
	glEnd();
	glFlush();


	float bigvertice = 1.3f;
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	//top line bigger square
	glVertex2f(-bigvertice, bigvertice);
	glVertex2f(bigvertice, bigvertice);
	//left line bigger square
	glVertex2f(-bigvertice, bigvertice);
	glVertex2f(-bigvertice, -bigvertice);
	//right line bigger square
	glVertex2f(bigvertice, bigvertice);
	glVertex2f(bigvertice, -bigvertice);
	//bottom line bigger square
	glVertex2f(-bigvertice, -bigvertice);
	glVertex2f(bigvertice, -bigvertice);
	//Drawing the big square
	glEnd();
	glFlush();

}

void MyTriangles() {

	float vertice = 1.0f;
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.6f, 0.2f);
	//bottom line upright triangle
		glVertex2f(vertice, -vertice);
		glVertex2f(-vertice, -vertice);
	//left line upright triangle
		glVertex2f(0, vertice);
		glVertex2f(-vertice, -vertice);
	//right line upright triangle
		glVertex2f(0, vertice);
		glVertex2f(vertice, -vertice);
	//Drawing the upright triangle
		glEnd();
		glFlush();

		float space = 0.5f;
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.6f, 0.2f);
		//bottom line upright triangle
		glVertex2f(-vertice, vertice - space);
		glVertex2f(vertice, vertice - space);
		//right line upright triangle
		glVertex2f(0, -vertice - space);
		glVertex2f(vertice, vertice - space);
		//left line upright triangle
		glVertex2f(0, -vertice - space);
		glVertex2f(-vertice, vertice - space);
		//Drawing the upright triangle
		glEnd();
		glFlush();
}

void MyCircles() {
	float theta;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.6f, 0.2f);

	//top circle
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f( 0.2 + cos(theta),0.7 + sin(theta));
	}
	glEnd();
	glFlush();

	//left circle
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(-0.5 + cos(theta),-0.5 + sin(theta));
	}
	glEnd();
	glFlush();

	//right circle
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.5 + cos(theta), -0.4 + sin(theta));
	}
	glEnd();
	glFlush();
}

void MyArc() {
	float theta;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);

	//Drawing the full blue circle
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f( cos(theta), sin(theta));
	}
	glEnd();
	glFlush();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 140; i < 320; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(cos(theta), sin(theta));
	}
	glEnd();
	glFlush();
}

int main(int argc, char**argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Hello guys");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	init();
	//glutDisplayFunc(MySquares);
	//glutDisplayFunc(MyTriangles);
	//glutDisplayFunc(MyCircles);
	glutDisplayFunc(MyArc);


	glutMainLoop();// Enter the event processing loop
}

