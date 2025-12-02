// extras.cpp – Realistic Birds + Better Position
#include <GL/freeglut.h>
#include <cmath>
#include "extras.h"

extern float timeVal;

void drawExtras(float t) {
    // Super Realistic Flying Birds (3 ta pakhi ek sathe)
    float baseY = 220 + sin(t * 0.08f) * 50;
    float offsetX = fmod(t * 0.4f, 1400) - 700;

    glColor3f(0.0f, 0.5f, 0.0f);
    for(int b=0; b<3; b++) {
        float bx = offsetX + b*180;
        float flap = sin(t * 0.2f + b) * 20;  // wing flap

        glPushMatrix();
        glTranslatef(bx, baseY + b*30, 0);

        // Body
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        for(int i=0; i<=360; i+=30)
            glVertex2f(15*cos(i*M_PI/180), 8*sin(i*M_PI/180));
        glEnd();

        // Wings (flapping)
        glBegin(GL_TRIANGLES);
        // Left wing
        glVertex2f(-15, 0);
        glVertex2f(-45 + flap, 15);
        glVertex2f(-40 + flap, -10);
        // Right wing
        glVertex2f(15, 0);
        glVertex2f(45 - flap, 15);
        glVertex2f(40 - flap, -10);
        glEnd();

        // Beak
        glColor3f(1.0f, 0.7f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(15, 0); glVertex2f(25, 5); glVertex2f(25, -5);
        glEnd();
        glColor3f(0.0f, 0.5f, 0.0f);

        glPopMatrix();
    }

    // Bangladesh Flag (waving)
    glPushMatrix();
    glTranslatef(-520, 180, 0);
    glRotatef(sin(t * 0.05f) * 15, 0, 0, 1);
    glColor3f(0.0f, 0.45f, 0.15f);
    glRectf(-50, -30, 50, 30);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i+=10)
        glVertex2f(22 * cos(i*M_PI/180), 22 * sin(i*M_PI/180));
    glEnd();
    glPopMatrix();
}
