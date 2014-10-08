#include "target.h"
#include "missile.h"

int score = 0;
GLfloat targetX = 0, targetY = 0, targetZ = 0.2;
GLfloat targetW = 0.2;

GLfloat targetVertices[][3] = {
	{-targetW, targetW, targetW},
	{targetW, targetW, targetW},
	{targetW, -targetW, targetW},
	{-targetW, -targetW, targetW},
	{-targetW, targetW, -targetW},
	{targetW, targetW, -targetW},
	{targetW, -targetW, -targetW},
	{-targetW, -targetW, -targetW},
};

GLfloat targetVertexIndex[][4] = {
	{0, 1, 2, 3},
	{4, 0, 3, 7},
	{1, 5, 6, 2},
	{0, 1, 5, 4},
	{3, 2, 6, 7},
	{4, 5, 6, 7},
};

GLfloat targetNormals[][3] = {
	{0, 1, 0},
	{-1, 0, 0},
	{1, 0, 0},
	{0, 0, 1},
	{0, 0, -1},
	{0, -1, 0},
};

// draw target
void drawTarget() {
	glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable (GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	for (int i = 0; i < 6; i++) {
		glNormal3f(targetNormals[i][0], targetNormals[i][1], targetNormals[i][2]);
		for(int j = 0;j < 4; j++) {
			int idx = targetVertexIndex[i][j];
			glVertex3f(targetX + targetVertices[idx][0], targetY + targetVertices[idx][1], targetZ + targetVertices[idx][2]);
		}
	}
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
}

// reset the position of the target randomly
void resetTargetPosition() {
	srand(time(NULL));
	targetX = -4 + 8 * ((float)rand()) / RAND_MAX;
	targetY = -4 + 8 * ((float)rand()) / RAND_MAX;
	targetZ = 0.5 * ((float)rand()) / RAND_MAX + 0.2;
	glutPostRedisplay();
}

// check collision of the target and missiles
// if the target is hit, reset its position
void checkCollision() {
	vector<Missile> missiles = getMissiles();
	for (int i = 0; i < missiles.size(); i++) {
		GLfloat mx = missiles[i].x, my = missiles[i].y, mz = missiles[i].z;
		if (mx >= targetX - targetW && mx <= targetX + targetW &&
			my >= targetY - targetW && my <= targetY + targetW &&
			mz >= targetZ - targetW && mz <= targetZ + targetW) {
			resetTargetPosition();
			score++;
			cout<<"Score: "<<score<<endl;
			break;
		}
	}
}

