#include "missile.h"
#include "flight.h"

vector<Missile> missiles;

GLfloat w = 0.001;
GLfloat vertices[][3] = {
	{-w, w, w},
	{w, w, w},
	{w, -w, w},
	{-w, -w, w},
	{-w, w, -w},
	{w, w, -w},
	{w, -w, -w},
	{-w, -w, -w},
};

GLfloat vertexIndex[][4] = {
	{0, 1, 2, 3},
	{4, 0, 3, 7},
	{1, 5, 6, 2},
	{0, 1, 5, 4},
	{3, 2, 6, 7},
	{4, 5, 6, 7},
};

GLfloat normals[][3] = {
	{0, 1, 0},
	{-1, 0, 0},
	{1, 0, 0},
	{0, 0, 1},
	{0, 0, -1},
	{0, -1, 0},
};

// Draw missile
void drawMissile(Missile missile) {
	GLfloat mx = missile.x;
	GLfloat my = missile.y;
	GLfloat mz = missile.z;
	glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable (GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	for (int i = 0; i < 6; i++) {
		glNormal3f(normals[i][0], normals[i][1], normals[i][2]);
		for(int j = 0;j < 4; j++) {
			int idx = vertexIndex[i][j];
			glVertex3f(mx + vertices[idx][0], my + vertices[idx][1], mz + vertices[idx][2]);
		}
	}
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
}

// Draw vector of missiles
void drawMissiles() {
	for (int i = 0; i < missiles.size(); i++) {
		drawMissile(missiles[i]);
	}
}

// Update missiles positions
void updateMissiles() {
	for (int i = 0; i < missiles.size(); i++) {
		missiles[i].x += missiles[i].dirX / 20;
		missiles[i].y += missiles[i].dirY / 20;
		missiles[i].z += missiles[i].dirZ / 20;

		// Remove missile from the vector after it is far away
		if (fabs(missiles[i].x) > 10 || fabs(missiles[i].y) > 10) {
			missiles.erase(missiles.begin() + i);
			i--;
		}
	}
}

// Add a new missile to the vector. This function is called when 'a' key is pressed
void addMissile() {
	Vector planeDir = getPlaneDir();
	Vector planePos = getPlanePos();
	Missile m = {planePos[0], planePos[1], planePos[2], planeDir[0], planeDir[1], planeDir[2]};
	missiles.push_back(m);
}

vector<Missile> getMissiles() {
	return missiles;
}