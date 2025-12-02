
#include <GL/freeglut.h>

// Manual Midpoint Circle Algorithm
void drawCircleMidpoint(int cx, int cy, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    auto plot8 = [&](int x, int y) {
        glVertex2i(cx + x, cy + y); glVertex2i(cx - x, cy + y);
        glVertex2i(cx + x, cy - y); glVertex2i(cx - x, cy - y);
        glVertex2i(cx + y, cy + x); glVertex2i(cx - y, cy + x);
        glVertex2i(cx + y, cy - x); glVertex2i(cx - y, cy - x);
    };

    glBegin(GL_POINTS);
    plot8(x, y);

    while (x < y) {
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        plot8(x, y);
    }
    glEnd();
}

// Manual Bresenham Line Algorithm
void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;
    int p = 2 * dy - dx;   // decision parameter

    glBegin(GL_POINTS);

    // First pixel
    glVertex2i(x, y);

    // Loop for all remaining pixels
    while (x < x2) {
        x = x + 1;         // always move right

        if (p < 0) {
            p = p + 2 * dy;
        }
        else {
            y = y + 1;     // move up
            p = p + 2 * dy - 2 * dx;
        }

        glVertex2i(x, y);  // plot current pixel
    }

    glEnd();
}
