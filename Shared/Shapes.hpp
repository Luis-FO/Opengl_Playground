#pragma once
#include <GL/glut.h>
#include <cmath>

void drawArrow(float startX, float startY, float endX, float endY);
void drawSquare(float x0, float y0, float size);
void drawCircle(float centerX, float centerY, float radius);
void drawLines(float startX, float startY, float  endX, float endY/*, float thickness*/);
void drawText(const char *text, float x, float y);
void drawGrid(float xEdgeDistanceFromCenter, float yEdgeDistanceFromCenter, float spacing);