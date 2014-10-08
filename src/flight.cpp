//
//  flight.cpp
//  CS418MP2
//
//  Created by Seo Joon Young on 8/27/14.
//  Copyright (c) 2014 SeoJoon Young. All rights reserved.
//

#include "flight.h"
#include <math.h>
#include <float.h>
#include <vector>
#include <time.h>

GLfloat x, y, z;
Vector xAxis(3), yAxis(3), zAxis(3);

// Initialize plane position and orientation
void initPlane() {
	x = 0.5;
	y = 0.0;
	z = 0.5;
	xAxis[0] = 1; xAxis[1] = 0; xAxis[2] = 0;
	yAxis[0] = 0; yAxis[1] = 1; yAxis[2] = 0;
	zAxis[0] = 0; zAxis[1] = 0; zAxis[2] = 1;
}

void lookAt() {
	gluLookAt (x, y, z, x + yAxis[0], y + yAxis[1], z + yAxis[2], zAxis[0], zAxis[1], zAxis[2]);
}

// roll the plane (left/right) by angle degree
// rolling also makes the plane turn left/right
void roll(double angle) {
	xAxis = rotate(xAxis, yAxis, angle);
	zAxis = rotate(zAxis, yAxis, angle);

	yAxis = rotate(yAxis, zAxis, -2 * angle);
	xAxis = rotate(xAxis, zAxis, -2 * angle);
}

// pitch the plane up/down by angle degrees
void pitch(double angle) {
	yAxis = rotate(yAxis, xAxis, angle);
	zAxis = rotate(zAxis, xAxis, angle);
}

// moves the plane in the direction it faces
void updatePos() {
	x += yAxis[0] / 50;
	y += yAxis[1] / 50;
	z += yAxis[2] / 50;
}

// gets the direction the plane is facing
Vector getPlaneDir() {
	return yAxis;
}

// gets the plane position
Vector getPlanePos() {
	Vector res(3);
	res[0] = x; res[1] = y; res[2] = z;
	return res;
}

