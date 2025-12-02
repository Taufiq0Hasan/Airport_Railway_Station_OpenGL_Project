// sky.cpp – Din hole surjo + raat hole chand + moving cloud
#include <GL/freeglut.h>
#include <cmath>
#include "sky.h"

extern bool isNight;
extern float timeVal;

void drawSky(bool night) {
    if (!night) {
        // Day sky – gradient (sundor blue → light blue → golden near horizon)
        glBegin(GL_QUADS);
        glColor3f(0.3f, 0.6f, 1.0f);   glVertex2f(-640, 360);
        glColor3f(0.3f, 0.6f, 1.0f);   glVertex2f(640, 360);
        glColor3f(0.7f, 0.85f, 1.0f);  glVertex2f(640, 100);
        glColor3f(1.0f, 0.9f, 0.7f);   glVertex2f(-640, 100);
        glEnd();

        // SUN (golden yellow + glow)
        float sunY = 250 + sin(timeVal * 0.02f) * 30;  // surjo slowly up-down
        glColor3f(1.0f, 0.95f, 0.6f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(450, sunY);
        for(int i = 0; i <= 360; i += 10)
            glVertex2f(450 + 80*cos(i*M_PI/180), sunY + 80*sin(i*M_PI/180));
        glEnd();

        // Sun glow (extra layer)
        glColor4f(1.0f, 0.8f, 0.4f, 0.3f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(450, sunY);
        for(int i = 0; i <= 360; i += 15)
            glVertex2f(450 + 120*cos(i*M_PI/180), sunY + 120*sin(i*M_PI/180));
        glEnd();

        // Few day clouds
        glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
        float cloudX = fmod(timeVal * 0.2f, 1500) - 750;
        for(int c = 0; c < 3; c++) {
            float cx = cloudX + c*500;
            glPushMatrix();
            glTranslatef(cx, 280, 0);
            glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < 360; i += 15)
                glVertex2f(90*cos(i*M_PI/180), 45*sin(i*M_PI/180));
            glEnd();
            glPopMatrix();
        }
    }
    else {
        // Night sky – deep blue-black
        glColor3f(0.02f, 0.02f, 0.12f);
        glRectf(-640, 360, 640, 0);

        // Moon
        glColor3f(1.0f, 1.0f, 0.85f);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < 360; i += 10)
            glVertex2f(450 + 65*cos(i*M_PI/180), 280 + 65*sin(i*M_PI/180));
        glEnd();

        // Moving night clouds
        glColor4f(0.25f, 0.25f, 0.35f, 0.7f);
        float cloudX = fmod(timeVal * 0.3f, 1500) - 750;
        for(int c = 0; c < 3; c++) {
            float cx = cloudX + c*400;
            glPushMatrix();
            glTranslatef(cx, 280, 0);
            glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < 360; i += 15)
                glVertex2f(80*cos(i*M_PI/180), 40*sin(i*M_PI/180));
            glEnd();
            glPopMatrix();
        }
    }
}
