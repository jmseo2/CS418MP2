#ifndef MISSILE_H
#define MISSILE_H

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Missile {
	GLfloat x, y, z;
	GLfloat dirX, dirY, dirZ;
};

void drawMissiles();
void updateMissiles();
void addMissile();
vector<Missile> getMissiles();

#endif