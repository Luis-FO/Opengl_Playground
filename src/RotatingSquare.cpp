#include "../include/Shapes.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>


float angle = 45.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    drawGrid(1.0, 1.0, 0.5);
    
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawSquare(-0.25f , -0.25f, 0.5f);
    glFlush();
}

void idle() {
    angle -= 0.001f; 
    if (angle > 360.0f)
        angle -= 360.0f;
    glutPostRedisplay(); 
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drawing Shapes with OpenGL");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
