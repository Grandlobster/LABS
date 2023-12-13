#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
class Drawing
{
public:
    static void drawLine(int x1, int y1, int x2, int y2)
    {
        float dx = x2 - x1;
        float dy = y2 - y1;
        float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float xinc = dx / steps;
        float yinc = dy / steps;
        float x = x1;
        float y = y1;
        glBegin(GL_POINTS);
        for (int i = 0; i <= steps; i++)
        {
            glVertex2f(x, y);
            x += xinc;
            y += yinc;
        }
        glEnd();
    }
};
class Circle
{
public:
    static void drawBresenhamCircle(int radius)
    {
        int x = 0;
        int y = radius;
        int decisionParam = 3 - (2 * radius);
        while (x <= y)
        {
            plotPoints(x, y);
            plotPoints(x, -y);
            plotPoints(-x, y);
            plotPoints(-x, -y);
            plotPoints(y, x);
            plotPoints(-y, x);
            plotPoints(y, -x);
            plotPoints(-y, -x);
            if (decisionParam <= 0)
            {
                x = x + 1;
                y = y;
                decisionParam = decisionParam + (4 * x) + 6;
            }
            else
            {
                x = x + 1;
                y = y - 1;
                decisionParam = decisionParam + 4 * (x - y) + 10;
            }
        }
    }

private:
    static void plotPoints(int x, int y)
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
};
class Triangle
{
public:
    static void drawEquilateralTriangle()
    {
        int x1 = -87.5, y1 = -50;
        int sideLength = 175;
        int height = (int)(sqrt(3) / 2 * sideLength);
        int x2 = x1 + sideLength, y2 = y1;
        int x3 = x1 + sideLength / 2, y3 = y1 + height;
        Drawing::drawLine(x1, y1, x2, y2);
        Drawing::drawLine(x2, y2, x3, y3);
        Drawing::drawLine(x3, y3, x1, y1);
    }
};
class Canvas
{
public:
    static void display()
    {
        glPointSize(2.5);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        Circle::drawBresenhamCircle(102);
        Circle::drawBresenhamCircle(50);
        Triangle::drawEquilateralTriangle();
        glFlush();
    }
    static void run(int argc, char **argv)
    {
        glutInit(&argc, argv);
        glutInitWindowSize(800, 800);
        glutCreateWindow("Circle Triangle Pattern");
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glutDisplayFunc(display);
        glViewport(0, 0, 800, 800);
        glOrtho(275.0, -275.0, 275.0, -275.0, 0.0, 1.0);
        glutMainLoop();
    }
};
int main(int argc, char **argv)
{
    Canvas::run(argc, argv);
    return 0;
}
