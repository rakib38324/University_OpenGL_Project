
#include <iostream>
// #include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857
#include <iostream>
using namespace std;

int x = 0, y = 0;

void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}

void RingCircle(int h, int k, int rx, int ry, int r, int g, int b) // Works
{
    // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
    // glColor3ub(0,0,255);
    glPointSize(1);
    glColor3ub(r, g, b);
    glBegin(GL_POINTS);
    for (int i = 1; i <= 360; i++)                                                    // 360 kon
    {                                                                                 //(x=position+radius x(150))    (y=position+radius y(150))   //// y point=sin main point ; x point=cos main point
        glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180)); // main point + radius
    }                                                                                 // 3.14159*i/180   convert degree to radian
    glEnd();

    // glFlush();
}

void circle(float x, float y, float rd, int r, int g, int b)
{
    float x1, y1, x2, y2;
    float radius = rd;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    float angle;
    for (angle = 0; angle <= 360; angle += 0.5)
    {
        x2 = x1 + sin((angle * 3.1416) / 180) * radius;
        y2 = y1 + cos((angle * 3.1416) / 180) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void line(int x, int y, int r, int g, int b)
{
    glColor3ub(r, g, b);
    glLineWidth(2);
    glBegin(GL_POLYGON);
    glVertex2d(x + 0, y + 25);
    glVertex2d(x + 20, y + 10);
    glVertex2d(x + 20, y + 15);
    glVertex2d(x + 0, y + 30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(x + 20, y + 10);
    glVertex2d(x + 80, y + 10);
    glVertex2d(x + 80, y + 15);
    glVertex2d(x + 20, y + 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(x + 80, y + 15);
    glVertex2d(x + 100, y + 30);
    glVertex2d(x + 100, y + 25);
    glVertex2d(x + 80, y + 10);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 245); // color
    glVertex2d(0, 0);
    glVertex2d(100, 0);

    glColor3ub(25, 240, 120);
    glVertex2d(100, 100);
    glVertex2d(0, 100);
    glEnd();

    //     glColor3ub(0, 0, 0);
    //     glLineWidth(2);
    //     glBegin(GL_LINES);
    //     glVertex2d(0, 25);
    //     glVertex2d(20, 10);
    //     glEnd();

    //     glBegin(GL_LINES);
    //     glVertex2d(20, 10);
    //     glVertex2d(80, 10);
    //     glEnd();

    //     glBegin(GL_LINES);
    //     glVertex2d(100, 25);
    //     glVertex2d(80, 10);
    //     glEnd();

    //  glColor3ub(43, 120, 33);
    //     glBegin(GL_POLYGON);
    //     glVertex2d(10, 80);
    //     glVertex2d(80, 80);
    //     glVertex2d(80, 20);
    //     glVertex2d(10, 20);
    //     glEnd();

    //  glColor3ub(43, 0, 33);
    //     glBegin(GL_TRIANGLES );
    //     glVertex2d(10, 20);
    //     glVertex2d(40, 70);
    //     glVertex2d(70, 20);

    //     glEnd();

    // RingCircle(50, 50, 20, 10, 0, 0, 255);

    // circle(x + 50, y + 50, 10, 250, 0, 0);
    // circle(x + 20, y + 20, 10, 250, 0, 0);

    // x++;
    // y--;
    // if(x==50){
    //     x=-50;
    //     y=50;
    // }
    // line(0, 0, 0, 0, 0);
    line(0, 5, 0, 0, 0);

    line(0, 10, 0, 255, 0);
    line(0, 15, 0, 0, 255);

    glFlush();
}

void update(int val)
{

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();

    glutDisplayFunc(display);
    glutTimerFunc(500, update, 0);
    // update(0);

    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}