#include <GL/glut.h>
#include <cmath>

void drawArrow(float startX, float startY, float endX, float endY) {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0); 


    glVertex2f(startX, startY);
    glVertex2f(endX, endY);

    float arrowAngle = 0.5; 
    float arrowLength = 0.1; 

    float angle = atan2(endY - startY, endX - startX);
    float arrowX1 = endX - arrowLength * cos(angle + arrowAngle);
    float arrowY1 = endY - arrowLength * sin(angle + arrowAngle);
    float arrowX2 = endX - arrowLength * cos(angle - arrowAngle);
    float arrowY2 = endY - arrowLength * sin(angle - arrowAngle);

    glVertex2f(endX, endY);
    glVertex2f(arrowX1, arrowY1);

    glVertex2f(endX, endY);
    glVertex2f(arrowX2, arrowY2);

    glEnd();
}

void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5); 
    glVertex2f(0.5, -0.5);  
    glVertex2f(0.5, 0.5);   
    glVertex2f(-0.5, 0.5);
    glEnd();
}

void drawCircle(float centerX, float centerY, float radius) {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 0.0); 
    int sides = 100;
    for (int i = 0; i < sides; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(sides); 
        float x = centerX + radius * std::cos(theta); 
        float y = centerY + radius * std::sin(theta); 
        glVertex2f(x, y);
    }

    glEnd();
}

void drawLines(float startX, float startY, float  endX, float endY/*, float thickness*/) {
    //glLineWidth(thickness);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0); 

    glVertex2f(startX, startY); 
    glVertex2f(endX, endY);
    glEnd();
}

void drawText(const char *text, float x, float y) {
    glColor3f(1.0, 1.0, 1.0); 

    glRasterPos2f(x, y);

    for (const char *c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}