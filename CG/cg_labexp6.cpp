#include <GL/glut.h>

float sun_x = -0.3;
float sun_y = -0.2;
float sun_z = 0.2;

void drawMountain(float x, float y)
{
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.3, y);
    glVertex2f(x, y + 0.3);
    glVertex2f(x + 0.3, y);
    glEnd();
}
void drawSun()
{
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(sun_x, sun_z, sun_y);
    glutSolidSphere(0.1, 50, 50);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawMountain(-0.6, -0.15);
    drawMountain(0.0, -0.15);
    drawMountain(0.6, -0.15);
    drawSun();
    glFlush();
}
void update(int value)
{
    sun_x += 0.005;
    sun_y -= 0.005;
    sun_z += 0.002;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Mountains and Sun");
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}