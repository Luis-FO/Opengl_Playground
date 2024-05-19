#include "include/Shapes.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>

float angle_arrow = M_PI/2;
int secs = 0;

void animate(int value) {
    

    glutPostRedisplay(); // Solicita uma nova renderização
    glutTimerFunc(1000, animate, 0); // Configura a próxima chamada de animação
    angle_arrow -= M_PI/30; // Ajuste a velocidade da animação aqui
    secs += 1;
    if(secs == 60)
    {   
        secs = 0;
        angle_arrow = M_PI/2;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity(); // Reinicia a matriz de transformação


    // Desenha o círculo
    float radius = 0.8;
    char hora[3];
    int h = 12;
    drawCircle(0.0, 0.0, radius);
    float step = (2*M_PI)/12;
    for(float i = M_PI/2; i<(5*M_PI)/2 && h>0; i+=step, h--){
        drawLines(cos(i)*(radius-0.01), sin(i)*(radius-0.01), cos(i)*(radius+0.01), sin(i)*(radius+0.01));
        sprintf(hora, "%d", h);
        drawText(hora, cos(i)*(radius+0.08), sin(i)*(radius+0.08));
    }
    //char buffer[20];
    //sprintf(buffer, "%f", angle_arrow);
    //drawText(buffer, 0.0, 0.0);
    drawArrow(0.0, 0.0, cos(angle_arrow)*radius, sin(angle_arrow)*radius);
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
    glutTimerFunc(1000, animate, 0); // Configura a função de animação
    glutMainLoop();

    return 0;
}
