// Computer Graphics Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <GL/glut.h>

const float degreesToRadians = 3.14159 / 180;

void drawAll();

void drawSquares();

void drawCircle(float, float, float);

void drawTriangle(float point1[2], float point2[2], float point3[2]);

void drawArc(float, float, float, float, float);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Simple Line");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-3.3, 10, -10, 3.3);
	glutDisplayFunc(drawAll);
	glutMainLoop();
}

void drawAll() {
	float point1[2] = { -3, -5 };
	float point2[2] = { 1, -5 };
	float point3[2] = { -1, sqrt(12) - 5 };
	float point4[2] = { -3, sqrt(12) / 2 - 4.5 };
	float point5[2] = { 1, sqrt(12) / 2 - 4.5 };
	float point6[2] = { -1, (-9 - sqrt(12)) / 2 };
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	drawSquares();
	drawCircle(5.5, 1.5, 1.5);
	drawCircle(7, 1.5, 1.5);
	drawCircle(7, 1.5, 1.5);
	drawCircle(6.25, 0.2, 1.5);
	drawTriangle(point1, point2, point3);
	drawTriangle(point4, point5, point6);
	drawArc(6, -5, 3, -30, 180);
	glFlush();
}

void drawSquares() {
	glBegin(GL_LINE_LOOP);
	glVertex2f(-3, 3);
	glVertex2f(1, 3);
	glVertex2f(1, -1);
	glVertex2f(-3, -1);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-2.5, 2.5);
	glVertex2f(0.5, 2.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-2.5, -0.5);
	glEnd();
}

void drawCircle(float startX, float startY,float radius) {
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 360; i++){
		float degreesInRadians = i * degreesToRadians;
		glVertex2f(cos(degreesInRadians) * radius + startX, sin(degreesInRadians) * radius + startY);
	}
	glEnd();
}

void drawTriangle(float point1[2], float point2[2], float point3[2]) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(point1[0], point1[1]);
	glVertex2f(point2[0], point2[1]);
	glVertex2f(point3[0], point3[1]);
	glEnd();
}

void drawArc(float startX, float startY, float radius, float start, float size) {
	glBegin(GL_LINE_STRIP);
	for (int i = start; i < size + start; i++) {
		float degreesInRadians = i * degreesToRadians;
		glVertex2f(cos(degreesInRadians) * radius + startX, sin(degreesInRadians) * radius + startY);
	}
	glEnd();
}
