// train.cpp – 100% Working Version
#include <GL/freeglut.h>
#include <cmath>
#include "train.h"

extern float trainPos;

void drawTrain(float x) {
    glPushMatrix();
    glTranslatef(-x, -120, 0);

    float wheel = trainPos * 6;

    // Engine (Red-Green – Bangladesh Railway)
    glColor3f(0.8f, 0.0f, 0.0f); glRectf(-80, 0, 40, 90);
    glColor3f(0.0f, 0.6f, 0.0f); glRectf(40, 0, 140, 90);

    // Coaches
    glColor3f(0.0f, 0.0f, 1.0f);  glRectf(160, 0, 280, 90);
    glColor3f(0.8f, 0.0f, 0.8f); glRectf(300, 0, 420, 90);
    glColor3f(1.0f, 0.0f, 0.0f);  glRectf(440, 0, 560, 90);
    glColor3f(1.0f, 0.9f, 0.0f); glRectf(580, 0, 700, 90);

    // Windows
    glColor3f(1.0f, 1.0f, 0.8f);
    float winX[6] = {-40, 60, 200, 340, 480, 620};
    for(int i = 0; i < 6; i++)
        glRectf(winX[i], 35, winX[i] + 60, 75);

    // Wheels (rotating)
    glColor3f(0.1f, 0.1f, 0.1f);
    float wheelX[6] = {-40, 60, 200, 340, 480, 620};
    for(int i = 0; i < 6; i++) {
        glPushMatrix();
        glTranslatef(wheelX[i], -30, 0);
        glRotatef(wheel, 0, 0, 1);
        glBegin(GL_TRIANGLE_FAN);
        for(int j = 0; j < 360; j += 30)
            glVertex2f(25 * cos(j * M_PI / 180), 25 * sin(j * M_PI / 180));
        glEnd();
        glPopMatrix();
    }

    // Smoke (only when train is visible)
    if (x > -700 && x < 700) {
        glColor4f(0.7f, 0.7f, 0.7f, 0.6f);
        for(int i = 0; i < 5; i++) {
            float sx = 100 + sin(trainPos * 0.1f + i) * 25;
            float sy = 100 + i * 35;
            glPushMatrix();
            glTranslatef(sx, sy, 0);
            glBegin(GL_TRIANGLE_FAN);
            for(int j = 0; j < 360; j += 30)
                glVertex2f(22 * cos(j * M_PI / 180), 22 * sin(j * M_PI / 180));
            glEnd();
            glPopMatrix();
        }
    }

    glPopMatrix();
}
