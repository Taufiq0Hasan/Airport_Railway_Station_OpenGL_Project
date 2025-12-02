// ground.cpp – City Scenario (No Error – Tested)
#include <GL/freeglut.h>
#include <cmath>
#include "ground.h"

extern float timeVal;

void drawGround() {
    // Platform
    glColor3f(0.78f, 0.73f, 0.65f);
    glRectf(-640, -100, 640, -150);

    // Rail track + sleeper
    glColor3f(0.35f, 0.2f, 0.1f);
    glRectf(-640, -160, 640, -200);
    glColor3f(0.55f, 0.55f, 0.55f);
    for(float x = -640; x < 640; x += 60)
        glRectf(x, -185, x+45, -165);

    // City Road (black asphalt)
    glColor3f(0.15f, 0.15f, 0.15f);
    glRectf(-640, -360, 640, -200);

    // White lane divider (dashed)
    glColor3f(1.0f, 1.0f, 1.0f);
    for(float x = -640; x < 640; x += 80) {
        glRectf(x, -275, x+40, -270);
        glRectf(x, -285, x+40, -280);
    }

    // Yellow center line
    glColor3f(1.0f, 0.9f, 0.0f);
    for(float x = -640; x < 640; x += 60)
        glRectf(x, -280, x+30, -275);

    // MOVING CARS (6 cars + 1 truck)
    float carY[] = {-220, -240, -260, -300, -320, -340, -300};
    float carSpeed[] = {1.8f, 2.2f, 1.5f, 2.5f, 1.9f, 2.0f, 1.2f};
    float carR[] = {1.0f, 0.0f, 1.0f, 1.0f, 0.8f, 0.0f, 0.9f};
    float carG[] = {0.0f, 0.6f, 1.0f, 0.5f, 0.0f, 0.8f, 0.9f};
    float carB[] = {0.0f, 1.0f, 0.0f, 0.0f, 0.8f, 0.0f, 0.9f};

    for(int i = 0; i < 7; i++) {
        float carX = fmod(timeVal * carSpeed[i] * 30, 2000.0f) - 1000.0f;

        glPushMatrix();
        glTranslatef(carX, carY[i], 0);

        // Car body
        glColor3f(carR[i], carG[i], carB[i]);
        if(i == 6) glRectf(-60, -20, 80, 25);      // truck
        else       glRectf(-40, -15, 40, 20);

        // Car roof
        glColor3f(0.1f, 0.1f, 0.1f);
        if(i == 6) glRectf(-40, 5, 40, 30);
        else       glRectf(-25, 0, 25, 20);

        // Windows
        glColor3f(0.8f, 0.9f, 1.0f);
        if(i == 6) {
            glRectf(-35, 8, -15, 25);
            glRectf(15, 8, 35, 25);
        } else {
            glRectf(-20, 0, 3, 17);
            glRectf(3, 0, 20, 17);
        }

        // Headlights (only when coming towards viewer)
        if(carX < 0) {
            glColor3f(1.0f, 1.0f, 0.7f);
            glRectf(35, -10, 45, 0);
            glRectf(35, 5, 45, 15);
        }

        glPopMatrix();
    }

    // STREET LIGHTS
    for(float x = -550; x <= 550; x += 200) {
        glColor3f(0.3f, 0.3f, 0.3f);
        glRectf(x-5, -200, x+5, -50);

        glColor3f(1.0f, 0.9f, 0.4f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, -40);
        for(int j=0; j<=360; j+=20)
            glVertex2f(x + 25*cos(j*M_PI/180), -40 + 25*sin(j*M_PI/180));
        glEnd();
    }
}
