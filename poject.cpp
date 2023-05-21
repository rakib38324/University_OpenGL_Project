#include <iostream>
// #include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857
#include <iostream>
using namespace std;

int x = 1, y = 2;

void myInit()
{

    // glClearColor(0.0, 1.0, 0.0, 0.0);
    // glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
    // glColor3f(0.0, 0.2, 0.0);
    glClearColor(128.0f / 255.0f, 0, 0, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    glOrtho(0, 500, 0, 500, -10.0, 10.0);
}

void RingCircle(int h, int k, int rx, int ry) // Works
{
    // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
    // glColor3ub(0,0,255);
    glPointSize(1);
    glBegin(GL_POINTS);
    for (int i = 1; i <= 360; i++)                                                    // 360 kon
    {                                                                                 //(x=position+radius x(150))    (y=position+radius y(150))   //// y point=sin main point ; x point=cos main point
        glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180)); // main point + radius
    }                                                                                 // 3.14159*i/180   convert degree to radian
    glEnd();

    glFlush();
}

// void circle_kon(int h, int k, int rx, int ry) // Works
// {
//     // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
//     glColor3ub(0, 255, 0);
//     glBegin(GL_POLYGON);
//     for (int i = 1; i <= 360; i++)                                                    // 360 kon
//     {                                                                                 //(x=position+radius x(150))    (y=position+radius y(150))   //// y point=sin main point ; x point=cos main point
//         glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180)); // main point + radius
//     }                                                                                 // 3.14159*i/180   convert degree to radian
//     glEnd();

//     // glFlush();
// }

// void circle_kon1(int h, int k, int rx, int ry) // Works
// {
//     // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
//     glColor3ub(160, 50, 0);
//     glBegin(GL_POLYGON);
//     for (int i = 1; i <= 360; i++)                                                    // 360 kon
//     {                                                                                 //(x=position+radius x(150))    (y=position+radius y(150))   //// y point=sin main point ; x point=cos main point
//         glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180)); // main point + radius
//     }                                                                                 // 3.14159*i/180   convert degree to radian
//     glEnd();

//     // glFlush();
// }

// void circle_kon2(int h, int k, int rx, int ry) // Works
// {
//     // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
//     glColor3ub(255, 255, 255);
//     glBegin(GL_POLYGON);
//     for (int i = 1; i <= 360; i++)                                                    // 360 kon
//     {                                                                                 //(x=position+radius x(150))    (y=position+radius y(150))   //// y point=sin main point ; x point=cos main point
//         glVertex2f(h + rx * cos(3.14159 * i / 180), k + ry * sin(3.14159 * i / 180)); // main point + radius
//     }                                                                                 // 3.14159*i/180   convert degree to radian
//     glEnd();

//     // glFlush();
// }

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

void bus(int x, int y)
{

    glColor3ub(0, 150, 0);
    glBegin(GL_POLYGON);
    glVertex2d(x + 100, y + 60);
    glVertex2d(x + 200, y + 60);
    glVertex2d(x + 200, y + 10);
    glVertex2d(x + 100, y + 10);
    glEnd();

    //----------------------------- bus front start -----------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 150, 0);
    glVertex2d(x + 100, y + 60);
    glVertex2d(x + 100, y + 10);
    glVertex2d(x + 95, y + 10);
    glVertex2d(x + 95, y + 20);
    glVertex2d(x + 100, y + 60);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 150, 0);
    glVertex2d(x + 102, y + 55);
    glVertex2d(x + 104, y + 55);
    glVertex2d(x + 103, y + 40);
    glVertex2d(x + 102, y + 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2d(x + 95, y + 20);
    glVertex2d(x + 100, y + 20);
    glVertex2d(x + 100, y + 18);
    glVertex2d(x + 95, y + 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2d(x + 95, y + 15);
    glVertex2d(x + 100, y + 15);
    glVertex2d(x + 100, y + 12);
    glVertex2d(x + 95, y + 12);
    glEnd();

    //-----------------------------bus front end -----------------------------

    //-----------------------------bus chaka---------------------------------

    circle(x + 130, y + 8, 8, 0, 0, 0);
    circle(x + 130, y + 8, 5, 255, 255, 255);

    circle(x + 180, y + 8, 8, 0, 0, 0);
    circle(x + 180, y + 8, 5, 255, 255, 255);

    //----------------------------- bus chaka---------------------------------

    // bus door
    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 105, y + 55);
    glVertex2d(x + 115, y + 55);
    glVertex2d(x + 115, y + 17);
    glVertex2d(x + 105, y + 17);
    glEnd();

    //-----------------------------------bus body style start -----------------------------------

    glBegin(GL_POLYGON);
    glColor3ub(0, 130, 0);
    glVertex2d(x + 125, y + 33);
    glVertex2d(x + 135, y + 33);
    glVertex2d(x + 130, y + 25);
    glVertex2d(x + 135, y + 17);
    glVertex2d(x + 125, y + 17);
    glVertex2d(x + 120, y + 25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 130, 0);
    glVertex2d(x + 140, y + 33);
    glVertex2d(x + 155, y + 33);
    glVertex2d(x + 145, y + 25);
    glVertex2d(x + 155, y + 17);
    glVertex2d(x + 140, y + 17);
    glVertex2d(x + 135, y + 25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 130, 0);
    glVertex2d(x + 160, y + 33);
    glVertex2d(x + 180, y + 33);
    glVertex2d(x + 175, y + 25);
    glVertex2d(x + 180, y + 17);
    glVertex2d(x + 160, y + 17);
    glVertex2d(x + 155, y + 25);
    glEnd();

    //-----------------------------------bus body style end -----------------------------------

    //------------------------------------bus window start-----------------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 120, y + 58);
    glVertex2d(x + 130, y + 58);
    glVertex2d(x + 130, y + 35);
    glVertex2d(x + 120, y + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 132, y + 58);
    glVertex2d(x + 142, y + 58);
    glVertex2d(x + 142, y + 35);
    glVertex2d(x + 132, y + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 144, y + 58);
    glVertex2d(x + 154, y + 58);
    glVertex2d(x + 154, y + 35);
    glVertex2d(x + 144, y + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 156, y + 58);
    glVertex2d(x + 166, y + 58);
    glVertex2d(x + 166, y + 35);
    glVertex2d(x + 156, y + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 168, y + 58);
    glVertex2d(x + 178, y + 58);
    glVertex2d(x + 178, y + 35);
    glVertex2d(x + 168, y + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2d(x + 180, y + 58);
    glVertex2d(x + 190, y + 58);
    glVertex2d(x + 190, y + 35);
    glVertex2d(x + 180, y + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 0, 0);
    glVertex2d(x + 192, y + 58);
    glVertex2d(x + 194, y + 58);
    glVertex2d(x + 194, y + 20);
    glVertex2d(x + 192, y + 20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 0);
    glVertex2d(x + 196, y + 58);
    glVertex2d(x + 198, y + 58);
    glVertex2d(x + 198, y + 20);
    glVertex2d(x + 196, y + 20);
    glEnd();

    //------------------------------------bus bus window end-----------------------------------------
}

void trees(int x, int y)
{

    glBegin(GL_POLYGON);
    glColor3ub(60, 16, 16);
    glVertex2d(x + 100, y + 225);
    glVertex2d(x + 103, y + 225);
    glVertex2d(x + 103, y + 210);
    glVertex2d(x + 100, y + 210);
    glEnd();

    circle(x + 98, y + 225, 5, 26, 50, 0);
    circle(x + 102, y + 225, 5, 26, 50, 0);
    circle(x + 107, y + 230, 5, 26, 45, 0);
    circle(x + 100, y + 232, 5, 26, 50, 0);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    //--------------------------------------field-----------------------
    glColor3ub(43, 120, 33);
    glBegin(GL_POLYGON);
    glVertex2d(0, 50);
    glVertex2d(80, 220);
    glVertex2d(1500, 220);
    glVertex2d(1500, 50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2d(20, 65);
    glVertex2d(90, 210);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(90, 210);
    glVertex2d(490, 210);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(490, 210);
    glVertex2d(478, 65);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(478, 65);
    glVertex2d(20, 65);
    glEnd();

    //---------------------------------- CRICKET FIELD START-------------------------------------
    glColor3ub(192, 200, 180);

    glColor3ub(192, 200, 180);
    glBegin(GL_POLYGON);
    glVertex2d(230, 155);
    glVertex2d(290, 155);
    glVertex2d(288, 145);
    glVertex2d(228, 145);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2d(235, 165);
    glVertex2d(230, 135);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2d(287, 165);
    glVertex2d(282, 135);
    glEnd();

    RingCircle(270, 138, 160, 70);

    //---------------------------------- CRICKET FIELD END-------------------------------------

    // tree();

    // --------------------------------------building left side start -------------------------------
    glColor3ub(111, 119, 230);
    glBegin(GL_POLYGON);
    glVertex2d(0, 500);
    glVertex2d(1500, 500);
    glVertex2d(1500, 250);
    glVertex2d(0, 250);
    glEnd();

    glColor3ub(140, 140, 140);
    glBegin(GL_POLYGON);
    glVertex2d(0, 270);
    glVertex2d(1500, 270);
    glVertex2d(1500, 250);
    glVertex2d(0, 250);
    glEnd();

    glColor3ub(231, 240, 230);
    glBegin(GL_POLYGON);
    glVertex2d(90, 370);
    glVertex2d(140, 370);
    glVertex2d(140, 275);
    glVertex2d(90, 275);
    glEnd();

    //----------------3rd flor-----------
    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(90, 360);
    glVertex2d(125, 360);
    glVertex2d(125, 330);
    glVertex2d(90, 330);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(126, 360);
    glVertex2d(139, 360);
    glVertex2d(139, 330);
    glVertex2d(126, 330);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(140, 370);
    glVertex2d(150, 365);
    glVertex2d(150, 280);
    glVertex2d(140, 275);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(141, 360);
    glVertex2d(149, 358);
    glVertex2d(149, 335);
    glVertex2d(141, 330);
    glEnd();

    //----------------------------------2nd flor--------------
    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(90, 328);
    glVertex2d(125, 328);
    glVertex2d(125, 300);
    glVertex2d(90, 300);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(126, 328);
    glVertex2d(139, 328);
    glVertex2d(139, 300);
    glVertex2d(126, 300);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(141, 327);
    glVertex2d(149, 332);
    glVertex2d(149, 306);
    glVertex2d(141, 300);
    glEnd();

    //----------------------------------1st flor--------------
    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(90, 298);
    glVertex2d(125, 298);
    glVertex2d(125, 278);
    glVertex2d(90, 278);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(126, 298);
    glVertex2d(139, 298);
    glVertex2d(139, 278);
    glVertex2d(126, 278);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(141, 297);
    glVertex2d(149, 303);
    glVertex2d(149, 282);
    glVertex2d(141, 278);
    glEnd();

    //---------------------------main body=-----------------------------------------------
    glColor3ub(240, 240, 240);
    glBegin(GL_POLYGON);
    glVertex2d(150, 365);
    glVertex2d(300, 365);
    glVertex2d(300, 280);
    glVertex2d(150, 280);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(150, 358);
    glVertex2d(169, 358);
    glVertex2d(169, 334);
    glVertex2d(150, 334);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(150, 332);
    glVertex2d(169, 332);
    glVertex2d(169, 306);
    glVertex2d(150, 306);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(150, 304);
    glVertex2d(169, 304);
    glVertex2d(169, 282);
    glVertex2d(150, 282);
    glEnd();

    ///--------------------------------------
    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(170, 358);
    glVertex2d(189, 358);
    glVertex2d(189, 334);
    glVertex2d(170, 334);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(170, 332);
    glVertex2d(189, 332);
    glVertex2d(189, 306);
    glVertex2d(170, 306);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(170, 304);
    glVertex2d(189, 304);
    glVertex2d(189, 282);
    glVertex2d(170, 282);
    glEnd();

    ////-----------main body right side-------------------------------
    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(260, 358);
    glVertex2d(279, 358);
    glVertex2d(279, 334);
    glVertex2d(260, 334);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(260, 332);
    glVertex2d(279, 332);
    glVertex2d(279, 306);
    glVertex2d(260, 306);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(260, 304);
    glVertex2d(279, 304);
    glVertex2d(279, 282);
    glVertex2d(260, 282);
    glEnd();

    ///--------------------------------------
    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(280, 358);
    glVertex2d(299, 358);
    glVertex2d(299, 334);
    glVertex2d(280, 334);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(280, 332);
    glVertex2d(299, 332);
    glVertex2d(299, 306);
    glVertex2d(280, 306);
    glEnd();

    glColor3ub(111, 119, 45);
    glBegin(GL_POLYGON);
    glVertex2d(280, 304);
    glVertex2d(299, 304);
    glVertex2d(299, 282);
    glVertex2d(280, 282);
    glEnd();

    //----------------main body middle part------------------------------------------------
    glColor3ub(100, 25, 5);
    glBegin(GL_POLYGON);
    glVertex2d(190, 358);
    glVertex2d(259, 358);
    glVertex2d(259, 282);
    glVertex2d(190, 282);
    glEnd();

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2d(192, 356);
    glVertex2d(202, 356);
    glVertex2d(202, 334);
    glVertex2d(192, 334);
    glEnd();

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2d(206, 356);
    glVertex2d(216, 356);
    glVertex2d(216, 334);
    glVertex2d(206, 334);
    glEnd();

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2d(220, 356);
    glVertex2d(230, 356);
    glVertex2d(230, 334);
    glVertex2d(220, 334);
    glEnd();

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2d(234, 356);
    glVertex2d(244, 356);
    glVertex2d(244, 334);
    glVertex2d(234, 334);
    glEnd();

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2d(236, 356);
    glVertex2d(244, 356);
    glVertex2d(244, 334);
    glVertex2d(236, 334);
    glEnd();

    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2d(248, 356);
    glVertex2d(258, 356);
    glVertex2d(258, 334);
    glVertex2d(248, 334);
    glEnd();

    //---------------------------------------tree----------------------------------------
    // trees();
    trees(1, 2);
    trees(1, 2);
    trees(1, 2);
    trees(1, 2);
    trees(-40, -40);
    trees(-45, -50);
    trees(-50, -60);
    
    trees(-65, -100);
    trees(-68, -115);
    trees(-74, -120);
    trees(-78, -130);
    trees(-85, -145);
  
    trees(20, 2);
    trees(40, 2);
    trees(60, 2);
    trees(80, 2);
    trees(100, 2);
    trees(120, 2);
    trees(140, 2);
    trees(160, 2);
    trees(180, 2);
    trees(200, 2);
    trees(220, 2);
    trees(240, 2);
    trees(260, 2);
    trees(280, 2);
    trees(300, 2);
    trees(320, 2);
    trees(340, 2);
    trees(360, 2);
    trees(380, 2);
    trees(390, -50);
    trees(390, -20);
    trees(390, -10);
    trees(390, -40);
    trees(390, -60);
    trees(390, -80);
    trees(390, -100);
    trees(390, -120);
    trees(390, -140);
    trees(390, -150);
    trees(390, -160);
    glEnd();

    // --------------------------------------ROAD------------------------------------------
    glColor3ub(255, 255, 205);
    glBegin(GL_POLYGON);
    glVertex2d(0, 50);
    glVertex2d(1500, 50);
    glVertex2d(1500, 0);
    glVertex2d(0, 0);
    glEnd();

    bus(5, 5); //---------------bus call---------------------

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

    // giving window size in X- and Y- direction
    glutInitWindowSize(1500, 800);
    glutInitWindowPosition(50, 0);

    // Giving name to window
    glutCreateWindow("Aminul_202-15-3832_Forest");
    myInit();

    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0);
    // update(0);

    glutMainLoop();
}