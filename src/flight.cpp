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

GLfloat x, y, z;
Vector xAxis(3), yAxis(3), zAxis(3);

void initPlane() {
	x = 0.5;
	y = 0.0;
	z = 0.5;
	xAxis[0] = 1; xAxis[1] = 0; xAxis[2] = 0;
	yAxis[0] = 0; yAxis[1] = 1; yAxis[2] = 0;
	zAxis[0] = 0; zAxis[1] = 0; zAxis[2] = 1;
}


Matrix multiply(Matrix &mat1, Matrix &mat2) {
	int m = (int)mat1.size();
	int n = (int)mat2[0].size();
	Matrix res(m, vector<GLfloat>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for(int k = 0; k < mat2.size(); k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return res;
}

double getNorm(Vector &v) {
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

Vector crossProduct(Vector &v1, Vector &v2) {
	Vector res(3);
	res[0] = v1[1] * v2[2] - v1[2] * v2[1];
	res[1] = v1[2] * v2[0] - v1[0] * v2[2];
	res[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return res;
}

Vector normalizedCrossProduct(Vector &v1, Vector &v2) {
	Vector res = crossProduct(v1, v2);
	double norm = getNorm(res);
	res[0] /= norm;
	res[1] /= norm;
	res[2] /= norm;
	return res;
}

void lookAt() {
	gluLookAt (x, y, z, x + yAxis[0], y + yAxis[1], z + yAxis[2], zAxis[0], zAxis[1], zAxis[2]);
}


bool isYAxisVector(Vector &v) {
	return v[0] == 0 && v[1] == 1 && v[2] == 0;
}


// rotateV: vector to rotate
// v: rotation axis
// angle: angle of rotation in degrees
Vector rotate(Vector &rotateV, Vector &v, double angle) {
	double angle_rad = angle * M_PI / 180;
	Vector r(3); 
	r[0] = 0;
	r[1] = 1;
	r[2] = 0;
	if (isYAxisVector(v)) {
		r[0] = 1;
		r[1] = 0;
		r[2] = 0;
	}
	Vector t = normalizedCrossProduct(r, v);
	Vector u = normalizedCrossProduct(v, t);

	Matrix mat1(4, Vector(4, 0));
	Matrix mat2(4, Vector(4, 0));
	Matrix mat3(4, Vector(4, 0));

	mat1[0][0] = t[0]; mat1[0][1] = u[0]; mat1[0][2] = v[0];
	mat1[1][0] = t[1]; mat1[1][1] = u[1]; mat1[1][2] = v[1];
	mat1[2][0] = t[2]; mat1[2][1] = u[2]; mat1[2][2] = v[2];
	mat1[3][3] = 1;

	mat2[0][0] = cos(-angle_rad); mat2[0][1] = -sin(-angle_rad);
	mat2[1][0] = sin(-angle_rad); mat2[1][1] = cos(-angle_rad);
	mat2[2][2] = mat2[3][3] = 1;

	mat3[0][0] = t[0]; mat3[0][1] = t[1]; mat3[0][2] = t[2];
	mat3[1][0] = u[0]; mat3[1][1] = u[1]; mat3[1][2] = u[2];
	mat3[2][0] = v[0]; mat3[2][1] = v[1]; mat3[2][2] = v[2];
	mat3[3][3] = 1;

	Matrix m1 = multiply(mat1, mat2);
	Matrix m2 = multiply(m1, mat3);

	Matrix vec(4, Vector(1, 0));
	vec[0][0] = rotateV[0];
	vec[1][0] = rotateV[1];
	vec[2][0] = rotateV[2];
	vec[3][0] = 1;

	Matrix resMat = multiply(m2, vec);
	Vector res(3);
	res[0] = resMat[0][0];
	res[1] = resMat[1][0];
	res[2] = resMat[2][0];

	double norm = getNorm(res);

	res[0] /= norm;
	res[1] /= norm;
	res[2] /= norm;
	return res;
}

void roll(double angle) {
	xAxis = rotate(xAxis, yAxis, angle);
	zAxis = rotate(zAxis, yAxis, angle);

	yAxis = rotate(yAxis, zAxis, -2 * angle);
	xAxis = rotate(xAxis, zAxis, -2 * angle);
}

void pitch(double angle) {
	yAxis = rotate(yAxis, xAxis, angle);
	zAxis = rotate(zAxis, xAxis, angle);
}

void updatePos() {
	x += yAxis[0] / 100;
	y += yAxis[1] / 100;
	z += yAxis[2] / 100;
}