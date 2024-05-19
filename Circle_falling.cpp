#include "include/Shapes.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>

float x = 0.0, y = 0.1;
float FPS = 1000/200;
bool isMovingUpward = false;

void calc_moviment(float& x0, float& y0){
    float g = 9;
    static float speed = 0;
    speed+=(g*FPS)/800000;
    y0 -= speed;
    if  (isMovingUpward) 
    {
        isMovingUpward = false;
        speed= -0.005;
    }
}

void animate(int value) {

    glutPostRedisplay(); // Solicita uma nova renderização
    glutTimerFunc(FPS, animate, 0); // Configura a próxima chamada de animação
    calc_moviment(x, y);
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == ' ') {
        // A tecla 'a' foi pressionada
        // Coloque aqui o código que você deseja executar quando 'a' for pressionado
        isMovingUpward = true;
        printf("Tecla 'a' foi pressionada!\n");
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity(); // Reinicia a matriz de transformação
    drawGrid(1.0, 1.0, 0.5);
    float radius = 0.1;
    // Desenha o círculo
    drawCircle(x, y, radius);
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
    glutTimerFunc(FPS, animate, 0); // Configura a função de animação
    glutKeyboardFunc(handleKeypress); // Adiciona a função de manipulação de teclas
    glutMainLoop();

    return 0;
}
