#include "GL/freeglut.h"
#include "ctime"
#include <time.h>
#include <iostream>
#include <array>
#include <cmath>
#include <cstdlib>
#include "DrawLib.hpp"
#include "Figure.h"
#include "FirstScene.hpp"
#include "SecondScene.hpp"
#include "ThirdScene.hpp"

Figure f = { .0, .0 };
Figure f2 = { .0, -1.0 };
Figure f3 = { .0, -2.0 };
Figure f4 = { .0, -2.0 };
Figure f5 = { .0, -2.0 };

Figure s = { .0, .0 };
Figure s1 = { .0, -1.0 };

Figure o = { .0, .0 };
Figure o1 = { 0.4, -0.6 };

Figure B  = { .0, .0 };
Figure B2 = { .0,-1.0 };
Figure B3 = { .0,-2.0 };
Figure B4 = { .0,-2.0 };

float SpeedX = 0.0025f;
float SpeedY = 0.0040f;
float CoordY = 0.000001f;

void animate(int value) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, animate, 0);

}

void drawAnima() {
	FirstBackground();

	f.pos.y += SpeedY;
	B.pos.y += SpeedY;

	DrawSpaceboard(f);
	Burn(B);
	 Oblako(o);
	if (f.pos.y > 2) {
		 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		SecondBackground();
		Oblako(o);
		Oblako(o1);
		glPushMatrix();
		glRotatef(-55, 1, 1, 1);
		glTranslatef(-1,0.8, 0);
		f2.pos.x += SpeedX;
		f2.pos.y += SpeedY;
		DrawSpaceboard(f2);
		Burn(B);
		glPopMatrix();
		if (f2.pos.y > 2) {
			 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			ThirdBackground();
			glPushMatrix();
			glRotatef(-55, 1, 1, 1);
			glTranslatef(-1, 0.8, 0);
			f3.pos.x += SpeedX;
			f3.pos.y += SpeedY;
			DrawSpaceboard(f3);
			glPopMatrix();
			Burn(B);
			if (f3.pos.y > 2) {
				FourthBackground();
				DrawMoon();
				glPushMatrix();
				glRotatef(-55, 1, 1, 1);
				glTranslatef(-1, 0.8, 0);
				f4.pos.x += SpeedX;
				f4.pos.y += SpeedY;
				DrawSpaceboard(f4);
				glPopMatrix();
				Burn(B);
				if (f4.pos.y > 2) {
					FifthBackground();
					glPushMatrix();
					glTranslatef(0, 4, 0);
					DrawSpaceboard(f5);
					if (f5.pos.y > -3.6) 
					f5.pos.y -= SpeedY;
					glPopMatrix();

				}

			}
		}
	}
}


int main(int argc, char* argv[]) {
	srand(0);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL Start Application");
	glutDisplayFunc(renderScene);
	glutTimerFunc(1000 / 60, animate, 1);

	glutMainLoop();

	return 0;

}
void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	FirstBackground();
	SecondBackground();
	ThirdBackground();
	FourthBackground();
	FifthBackground();

	Oblako(o);
	DrawSpaceboard(f);

	drawAnima();

	glutSwapBuffers();

}