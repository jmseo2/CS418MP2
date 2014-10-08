#ifndef FLIGHT_H
#define FLIGHT_H

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

void initPlane();
void lookAt();
void roll(double angle);
void pitch(double angle);
void updatePos();
Vector getPlanePos();
Vector getPlaneDir();

#endif
