#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>

#include "sky.h"
#include "ground.h"
#include "station.h"
#include "train.h"
#include "extras.h"

float trainPos = -900.0f;
float timeVal = 0.0f;
bool isNight = true;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSky(isNight);
    drawGround();
    drawStation();
    drawExtras(timeVal);
    drawTrain(trainPos);
    glutSwapBuffers();
}

void timer(int = 0) {
    trainPos += 1.8f;
    if (trainPos > 1000) trainPos = -900;
    timeVal += 0.05f;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char k, int, int) {
    if (k == 'n' || k == 'N') isNight = true;
    if (k == 'd' || k == 'D') isNight = false;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Airport Railway Station");
    gluOrtho2D(-640, 640, -360, 360);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
