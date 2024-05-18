#include "Shared/Shapes.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity(); // Reinicia a matriz de transformação
    drawCircle(0.0, 0.0, 0.05);
    
    drawGrid(1.0, 1.0, 0.20);
    glFlush(); // Força o processamento dos comandos OpenGL
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Cor de fundo (preto)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define a matriz de projeção ortográfica
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Desenhando Formas com OpenGL");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
