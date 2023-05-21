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
    int countTree;
    int t1 = x;
    for (countTree = 1; countTree <= 16; countTree++)
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
        x = t1 + 25;
        t1 = x;
    }
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3ub(221, 236, 243);
    glVertex2d(0, 250);
    glVertex2f(500, 250);

    glColor3ub(121, 192, 216);
    glVertex2f(500, 500);

    glVertex2f(0, 500);
    glEnd();

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

    // --------------------------------------building left side start -------------------------------

    //---------------------------------------BUILDING FRONT ROAD------------------------------------
    glColor3ub(255, 221, 204);
    glBegin(GL_POLYGON);
    glVertex2d(0, 250);
    glVertex2d(1500, 250);
    glVertex2d(1500, 220);
    glVertex2d(0, 220);
    glEnd();

    //---------------------------------------BUILDING SIDE ROAD------------------------------------

    glColor3ub(255, 221, 204);
    glBegin(GL_POLYGON);
    glVertex2d(65, 225);
    glVertex2d(80, 220);
    glVertex2d(-22, 0);
    glVertex2d(-40, 0);
    glEnd();

    glColor3ub(231, 240, 230);
    glBegin(GL_POLYGON);
    glVertex2d(90, 350);
    glVertex2d(140, 350);
    glVertex2d(140, 255);
    glVertex2d(90, 255);
    glEnd();

    //----------------3rd flor-----------
    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(90, 340);
    glVertex2d(125, 340);
    glVertex2d(125, 310);
    glVertex2d(90, 310);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(126, 340);
    glVertex2d(139, 340);
    glVertex2d(139, 310);
    glVertex2d(126, 310);
    glEnd();

    ///---------------------------------------------
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(128, 335);
    glVertex2d(129, 335);
    glVertex2d(129, 315);
    glVertex2d(128, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(130, 335);
    glVertex2d(131, 335);
    glVertex2d(131, 315);
    glVertex2d(130, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(132, 335);
    glVertex2d(133, 335);
    glVertex2d(133, 315);
    glVertex2d(132, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(134, 335);
    glVertex2d(135, 335);
    glVertex2d(135, 315);
    glVertex2d(134, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(136, 335);
    glVertex2d(137, 335);
    glVertex2d(137, 315);
    glVertex2d(136, 315);
    glEnd();

    //---------------------------------------------------------------

    //--------------------------------------LEFT SIDE VIEW
    glColor3ub(166, 166, 166);
    glBegin(GL_POLYGON);
    glVertex2d(140, 350);
    glVertex2d(150, 345);
    glVertex2d(150, 260);
    glVertex2d(140, 255);
    glEnd();

    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(141, 340);
    glVertex2d(149, 338);
    glVertex2d(149, 315);
    glVertex2d(141, 310);
    glEnd();

    //----------------------------------2nd flor--------------
    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(90, 308);
    glVertex2d(125, 308);
    glVertex2d(125, 280);
    glVertex2d(90, 280);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(126, 308);
    glVertex2d(139, 308);
    glVertex2d(139, 280);
    glVertex2d(126, 280);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(141, 307);
    glVertex2d(149, 312);
    glVertex2d(149, 286);
    glVertex2d(141, 280);
    glEnd();

    ///---------------------------------------------
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(128, 303);
    glVertex2d(129, 303);
    glVertex2d(129, 285);
    glVertex2d(128, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(130, 303);
    glVertex2d(131, 303);
    glVertex2d(131, 285);
    glVertex2d(130, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(132, 303);
    glVertex2d(133, 303);
    glVertex2d(133, 285);
    glVertex2d(132, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(134, 303);
    glVertex2d(135, 303);
    glVertex2d(135, 285);
    glVertex2d(134, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(136, 303);
    glVertex2d(137, 303);
    glVertex2d(137, 285);
    glVertex2d(136, 285);
    glEnd();

    //---------------------------------------------------------------

    //----------------------------------1st flor--------------
    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(90, 278);
    glVertex2d(125, 278);
    glVertex2d(125, 258);
    glVertex2d(90, 258);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(126, 278);
    glVertex2d(139, 278);
    glVertex2d(139, 258);
    glVertex2d(126, 258);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(141, 277);
    glVertex2d(149, 283);
    glVertex2d(149, 262);
    glVertex2d(141, 258);
    glEnd();

    ///---------------------------------------------
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(128, 275);
    glVertex2d(129, 275);
    glVertex2d(129, 262);
    glVertex2d(128, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(130, 275);
    glVertex2d(131, 275);
    glVertex2d(131, 262);
    glVertex2d(130, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(132, 275);
    glVertex2d(133, 275);
    glVertex2d(133, 262);
    glVertex2d(132, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(134, 275);
    glVertex2d(135, 275);
    glVertex2d(135, 262);
    glVertex2d(134, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(136, 275);
    glVertex2d(137, 275);
    glVertex2d(137, 262);
    glVertex2d(136, 262);
    glEnd();

    //---------------------------------------------------------------

    //---------------------------main body left side -----------------------------------------------
    glColor3ub(240, 240, 240);
    glBegin(GL_POLYGON);
    glVertex2d(150, 345);
    glVertex2d(300, 345);
    glVertex2d(300, 260);
    glVertex2d(150, 260);
    glEnd();

    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(150, 338);
    glVertex2d(169, 338);
    glVertex2d(169, 314);
    glVertex2d(150, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(150, 312);
    glVertex2d(169, 312);
    glVertex2d(169, 286);
    glVertex2d(150, 286);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(150, 284);
    glVertex2d(169, 284);
    glVertex2d(169, 262);
    glVertex2d(150, 262);
    glEnd();

    ///--------------------------------------
    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(170, 338);
    glVertex2d(189, 338);
    glVertex2d(189, 314);
    glVertex2d(170, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(170, 312);
    glVertex2d(189, 312);
    glVertex2d(189, 286);
    glVertex2d(170, 286);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(170, 284);
    glVertex2d(189, 284);
    glVertex2d(189, 262);
    glVertex2d(170, 262);
    glEnd();

    ////-----------main body right side-------------------------------

    glBegin(GL_POLYGON);
    glVertex2d(260, 338);
    glVertex2d(279, 338);
    glVertex2d(279, 314);
    glVertex2d(260, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(260, 312);
    glVertex2d(279, 312);
    glVertex2d(279, 286);
    glVertex2d(260, 286);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(260, 284);
    glVertex2d(279, 284);
    glVertex2d(279, 262);
    glVertex2d(260, 262);
    glEnd();

    ///--------------------------------------

    glBegin(GL_POLYGON);
    glVertex2d(280, 338);
    glVertex2d(299, 338);
    glVertex2d(299, 314);
    glVertex2d(280, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(280, 312);
    glVertex2d(299, 312);
    glVertex2d(299, 286);
    glVertex2d(280, 286);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(280, 284);
    glVertex2d(299, 284);
    glVertex2d(299, 262);
    glVertex2d(280, 262);
    glEnd();

    //----------------main body middle part------------------------------------------------
    glColor3ub(38, 153, 0);
    glBegin(GL_POLYGON);
    glVertex2d(190, 338);
    glVertex2d(259, 338);
    glVertex2d(259, 262);
    glVertex2d(190, 262);
    glEnd();

    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(192, 336);
    glVertex2d(202, 336);
    glVertex2d(202, 314);
    glVertex2d(192, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(204, 336);
    glVertex2d(216, 336);
    glVertex2d(216, 314);
    glVertex2d(204, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(218, 336);
    glVertex2d(232, 336);
    glVertex2d(232, 314);
    glVertex2d(218, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(234, 336);
    glVertex2d(244, 336);
    glVertex2d(244, 314);
    glVertex2d(234, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(236, 336);
    glVertex2d(244, 336);
    glVertex2d(244, 314);
    glVertex2d(236, 314);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(247, 336);
    glVertex2d(257, 336);
    glVertex2d(257, 314);
    glVertex2d(247, 314);
    glEnd();

    //-----------------------------------

    glBegin(GL_POLYGON);
    glVertex2d(192, 312);
    glVertex2d(202, 312);
    glVertex2d(202, 290);
    glVertex2d(192, 290);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(204, 312);
    glVertex2d(224, 312);
    glVertex2d(224, 290);
    glVertex2d(204, 290);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(226, 312);
    glVertex2d(244, 312);
    glVertex2d(244, 290);
    glVertex2d(226, 290);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(247, 312);
    glVertex2d(257, 312);
    glVertex2d(257, 290);
    glVertex2d(247, 290);
    glEnd();

    //---------------------------------------
    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(192, 288);
    glVertex2d(202, 288);
    glVertex2d(202, 266);
    glVertex2d(192, 266);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(204, 288);
    glVertex2d(216, 288);
    glVertex2d(216, 266);
    glVertex2d(204, 266);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(218, 288);
    glVertex2d(232, 288);
    glVertex2d(232, 266);
    glVertex2d(218, 266);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(234, 288);
    glVertex2d(244, 288);
    glVertex2d(244, 266);
    glVertex2d(234, 266);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(236, 288);
    glVertex2d(244, 288);
    glVertex2d(244, 266);
    glVertex2d(236, 266);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(247, 288);
    glVertex2d(257, 288);
    glVertex2d(257, 266);
    glVertex2d(247, 266);
    glEnd();

    //-----------------------------------BUILDING RIGHT SIDE VIEW------------------------------------------

    glColor3ub(166, 166, 166);
    glBegin(GL_POLYGON);
    glVertex2d(300, 345);
    glVertex2d(310, 350);
    glVertex2d(310, 255);
    glVertex2d(300, 260);
    glEnd();

    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(300, 338);
    glVertex2d(309, 343);
    glVertex2d(309, 310);
    glVertex2d(300, 312);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(300, 310);
    glVertex2d(309, 308);
    glVertex2d(309, 283);
    glVertex2d(300, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(300, 283);
    glVertex2d(309, 279);
    glVertex2d(309, 258);
    glVertex2d(300, 262);
    glEnd();

    //-------------------BUILDING RIGHT -----------------------------

    glColor3ub(231, 240, 230);
    glBegin(GL_POLYGON);
    glVertex2d(310, 350);
    glVertex2d(360, 350);
    glVertex2d(360, 255);
    glVertex2d(310, 255);
    glEnd();

    //----------------3rd flor-----------

    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(311, 343);
    glVertex2d(326, 343);
    glVertex2d(326, 310);
    glVertex2d(311, 310);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(327, 343);
    glVertex2d(360, 343);
    glVertex2d(360, 310);
    glVertex2d(327, 310);
    glEnd();

    //-----------------------------------------------------------------------------------
    //------------------------------------
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(313, 339);
    glVertex2d(314, 339);
    glVertex2d(314, 315);
    glVertex2d(313, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(315, 339);
    glVertex2d(316, 339);
    glVertex2d(316, 315);
    glVertex2d(315, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(317, 339);
    glVertex2d(318, 339);
    glVertex2d(318, 315);
    glVertex2d(317, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(319, 339);
    glVertex2d(320, 339);
    glVertex2d(320, 315);
    glVertex2d(319, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(321, 339);
    glVertex2d(322, 339);
    glVertex2d(322, 315);
    glVertex2d(321, 315);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(323, 339);
    glVertex2d(324, 339);
    glVertex2d(324, 315);
    glVertex2d(323, 315);
    glEnd();

    // ----------------------------------2ND FLOR -----------------------------------

    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(311, 309);
    glVertex2d(326, 309);
    glVertex2d(326, 280);
    glVertex2d(311, 280);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(327, 309);
    glVertex2d(360, 309);
    glVertex2d(360, 280);
    glVertex2d(327, 280);
    glEnd();

    //-----------------------------------------------------------------------------------
    //------------------------------------
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(313, 306);
    glVertex2d(314, 306);
    glVertex2d(314, 283);
    glVertex2d(313, 283);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(315, 306);
    glVertex2d(316, 306);
    glVertex2d(316, 283);
    glVertex2d(315, 283);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(317, 306);
    glVertex2d(318, 306);
    glVertex2d(318, 283);
    glVertex2d(317, 283);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(319, 306);
    glVertex2d(320, 306);
    glVertex2d(320, 283);
    glVertex2d(319, 283);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(321, 306);
    glVertex2d(322, 306);
    glVertex2d(322, 283);
    glVertex2d(321, 283);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(323, 306);
    glVertex2d(324, 306);
    glVertex2d(324, 283);
    glVertex2d(323, 283);
    glEnd();

    //------------------------------------1ST FLOR-----------------------
    glColor3ub(17, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2d(311, 278);
    glVertex2d(326, 278);
    glVertex2d(326, 256);
    glVertex2d(311, 256);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(327, 278);
    glVertex2d(360, 278);
    glVertex2d(360, 256);
    glVertex2d(327, 256);
    glEnd();

    //------------------------------------
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(313, 275);
    glVertex2d(314, 275);
    glVertex2d(314, 262);
    glVertex2d(313, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(315, 275);
    glVertex2d(316, 275);
    glVertex2d(316, 262);
    glVertex2d(315, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(317, 275);
    glVertex2d(318, 275);
    glVertex2d(318, 262);
    glVertex2d(317, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(319, 275);
    glVertex2d(320, 275);
    glVertex2d(320, 262);
    glVertex2d(319, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(321, 275);
    glVertex2d(322, 275);
    glVertex2d(322, 262);
    glVertex2d(321, 262);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(323, 275);
    glVertex2d(324, 275);
    glVertex2d(324, 262);
    glVertex2d(323, 262);
    glEnd();

    //--------------------------------BUILDING FRONT GATE ------------------------------------

    glColor3ub(113, 112, 93);

    glBegin(GL_POLYGON);
    glVertex2d(80, 260);
    glVertex2d(220, 260);
    glVertex2d(220, 250);
    glVertex2d(80, 250);
    glEnd();

    glColor3ub(225, 217, 208);
    glBegin(GL_POLYGON);
    glVertex2d(220, 280);
    glVertex2d(240, 280);
    glVertex2d(240, 250);
    glVertex2d(220, 250);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(222, 278);
    glVertex2d(238, 278);
    glVertex2d(238, 272);
    glVertex2d(222, 272);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(226, 278);
    glVertex2d(234, 278);
    glVertex2d(234, 274);
    glVertex2d(226, 274);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(226, 270);
    glVertex2d(234, 270);
    glVertex2d(234, 252);
    glVertex2d(226, 252);
    glEnd();

    glColor3ub(113, 112, 93);
    glBegin(GL_POLYGON);
    glVertex2d(240, 260);
    glVertex2d(380, 260);
    glVertex2d(380, 250);
    glVertex2d(240, 250);
    glEnd();

    //-------------------------------------------MOSQUE---------------------------------------
    glColor3ub(128, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(410, 255);
    glVertex2d(470, 255);
    glVertex2d(470, 250);
    glVertex2d(410, 250);
    glEnd();

    glColor3ub(172, 172, 145);
    glBegin(GL_POLYGON);
    glVertex2d(415, 255);
    glVertex2d(390, 300);
    glVertex2d(485, 300);
    glVertex2d(465, 255);
    glEnd();

    glColor3ub(93, 93, 70);
    glBegin(GL_POLYGON);
    glVertex2d(385, 300);
    glVertex2d(385, 310);
    glVertex2d(490, 310);
    glVertex2d(490, 300);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2d(385, 300);
    glVertex2d(385, 310);

    glBegin(GL_LINES);
    glVertex2d(385, 310);
    glVertex2d(490, 310);

    glBegin(GL_LINES);
    glVertex2d(490, 310);
    glVertex2d(490, 300);

    glBegin(GL_LINES);
    glVertex2d(490, 300);
    glVertex2d(385, 300);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(420, 295);
    glVertex2d(460, 295);
    glVertex2d(460, 290);
    glVertex2d(420, 290);
    glEnd();

    glColor3ub(77, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(420, 285);
    glVertex2d(460, 285);
    glVertex2d(460, 255);
    glVertex2d(420, 255);
    glEnd();


    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(430, 275);
    glVertex2d(450, 275);
    glVertex2d(450, 255);
    glVertex2d(430, 255);
    glEnd();


    glColor3ub(0, 61, 102);
    glBegin(GL_POLYGON);
    glVertex2d(435, 265);
    glVertex2d(445, 265);
    glVertex2d(445, 255);
    glVertex2d(435, 255);
    glEnd();

    glColor3ub(0, 61, 102);
    glBegin(GL_TRIANGLES);
    glVertex2d(435, 265);
    glVertex2d(440, 270);
    glVertex2d(445, 265);
    
    glEnd();
    //---------------------------------------tree----------------------------------------

    trees(1, 2);

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
    // glutTimerFunc(50, update, 0);
    // update(0);

    glutMainLoop();
}