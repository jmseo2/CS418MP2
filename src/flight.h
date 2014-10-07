#ifndef FLIGHT_H
#define FLIGHT_H

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

#define Matrix vector<vector<GLfloat> >
#define Vector vector<GLfloat>

void initPlane();
Matrix multiply(Matrix &mat1, Matrix &mat2);
double getNorm(Vector &v);
Vector crossProduct(Vector &v1, Vector &v2);
Vector normalizedCrossProduct(Vector &v1, Vector &v2);
Vector rotate(Vector &rotateV, Vector &v, double angle);
void lookAt();
void roll(double angle);
void pitch(double angle);
void updatePos();

#endif
