#include <GL/freeglut.h>
#include "station.h"

void drawStation() {
    // Main building
    glColor3f(0.9f, 0.75f, 0.5f);
    glRectf(-500, -100, 500, 120);

    // Roof
    glColor3f(0.8f, 0.2f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-520,120); glVertex2f(0,250); glVertex2f(520,120);
    glEnd();

    // Platform roof support
    glColor3f(0.7f, 0.3f, 0.2f);
    for(float x=-450; x<=450; x+=150) {
        glRectf(x-10, -100, x+10, 120);
    }

    // "Airport Railway Station" Text
    glColor3f(1,1,1);
    glRasterPos2f(-100, 80);
    const char* txt = "Airport Railway Station";
    for(int i=0; txt[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[i]);
}
