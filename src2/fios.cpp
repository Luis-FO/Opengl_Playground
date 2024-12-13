#include "../include/Shapes.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>


const float GRAVITY = -0.0025f;
const float DELTA_TIME = 0.5f;

float angularVelocity = 0.0f;
float angularAcceleration = 0.0f;
float angle = 3.14f/2.0;
float pivotX = 0.0f; 
float speed_axe = 0.0f;

float node_center_x = 0.0f;
float node_center_y = 0.0f;
float node_radius =  0.025;
float segment_width = 0.025f;
float segment_height = 0.3f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    glPushMatrix();
    drawGrid(1.0, 1.0, 0.5);
    glTranslatef(pivotX, 0.0f, 0);
    glRotatef(angle* 180.0f / M_PI, 0.0f, 0.0f, 1.0f);
    drawRect(node_center_x-(segment_width/2), node_center_x, segment_width, segment_height);
    drawCircle(node_center_x, node_center_y,  node_radius);
    //glFlush();
    glPopMatrix();
    
    glutSwapBuffers();
}

// void idle() {

//     angularAcceleration = (-GRAVITY / segment_height) * sin(angle);
//     angularVelocity += angularAcceleration * DELTA_TIME;
//     angle += angularVelocity * DELTA_TIME;
//     glutPostRedisplay(); 
// }

void handleKeys(unsigned char key, int x, int y) {
    if (key == 'a') {
        speed_axe -= 0.001f; // Mover o eixo para a esquerda
    } else if (key == 'd') {
        speed_axe += 0.001f; // Mover o eixo para a direita
    }
    glutPostRedisplay();
}

void update(int value) {
    angularAcceleration = (-GRAVITY / segment_height) * sin(angle);
    angularVelocity += (angularAcceleration+(speed_axe/10)) * DELTA_TIME;
    angle += angularVelocity * DELTA_TIME;
    pivotX+= speed_axe;
    glutPostRedisplay(); 
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); 
    
}
/* opengl options */
void initgLOptions() {
   glEnable(GL_BLEND);
   glEnable(GL_LINE_SMOOTH);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drawing Shapes with OpenGL");

    init();
    //initgLOptions();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(handleKeys);
    
    //glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
