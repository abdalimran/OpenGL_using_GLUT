/*
    Name: Abdullah-Al-Imran
    ID: 14-26024-1
    Email: abdalimran@gmail.com
*/

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myInit (void)
{
    glClearColor(1.000, 0.843, 0.000,0.000);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(35.0);
    glLineWidth(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 800.0, 0.0);
}

void printPointLine1DX(int x1, int x2, int y, int i)
{
    for(int x=x1; x<=x2; x+=i)
    {
        glBegin(GL_POINTS);
            glColor3f (0.0, 0.0, 0.0);
            glVertex2i(x, y);
        glEnd();
    }
}

void printPointLine1DY(int y1, int y2, int x, int i)
{
    for(int y=y1; y<=y2; y+=i)
    {
        glBegin(GL_POINTS);
            glColor3f (0.0, 0.0, 0.0);
            glVertex2i(x, y);
        glEnd();
    }
}

void printPointLine2DXNeg(int x1, int y1, int x2, int y2, int i)
{
    for(int x=x1,y=y1; x>=x2 && y<=y2; x-=i,y+=i)
    {
        glBegin(GL_POINTS);
            glColor3f (0.0, 0.0, 0.0);
            glVertex2i(x,y);
        glEnd();
    }
}

void printPointLine2DYNeg(int x1, int y1, int x2, int y2, int i)
{
    for(int x=x1,y=y1; x<=x2 && y>=y2; x+=i,y-=i)
    {
        glBegin(GL_POINTS);
            glColor3f (0.0, 0.0, 0.0);
            glVertex2i(x,y);
        glEnd();
    }
}

void printPointLine2DXYPos(int x1, int y1, int x2, int y2, int i)
{
    for(int x=x1,y=y1; x<=x2 && y<=y2; x+=i,y+=i)
    {
        glBegin(GL_POINTS);
            glColor3f (0.0, 0.0, 0.0);
            glVertex2i(x,y);
        glEnd();
    }
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    printPointLine1DX(280,880,35,35);
    printPointLine1DX(280,880,735,35);
    printPointLine1DY(280,490,35,35);
    printPointLine1DY(280,490,1120,35);
    printPointLine2DXNeg(245,70,70,315,35);
    printPointLine2DYNeg(880,735,1090,525,35);
    printPointLine2DXYPos(910,70,1115,280,35);
    printPointLine2DXYPos(70,525,245,735,35);
    printPointLine1DX(140,1015,473,35);
    printPointLine1DX(175,980,508,35);

    printPointLine1DX(215,425,543,35);
    printPointLine1DX(500,675,543,35);
    printPointLine1DX(745,955,543,35);

    printPointLine1DX(250,395,575,35);
    printPointLine1DX(535,645,575,35);
    printPointLine1DX(775,920,575,35);

    printPointLine1DX(285,360,605,35);
    printPointLine1DX(570,615,605,35);
    printPointLine1DX(815,885,605,35);

    glBegin(GL_POINTS);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(355, 640);
        glVertex2i(588, 640);
        glVertex2i(815, 640);
    glEnd();



    glBegin(GL_QUADS);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(105, 315);
        glVertex2i(105, 455);
        glVertex2i(1050, 455);
        glVertex2i(1050, 315);
    glEnd();


    printPointLine1DX(145,385,300,35);
    printPointLine1DX(500,675,300,35);
    printPointLine1DX(800,1025,300,35);

    printPointLine1DX(185,355,265,35);
    printPointLine1DX(535,645,265,35);
    printPointLine1DX(835,990,265,35);

    printPointLine1DX(185,355,230,35);
    printPointLine1DX(535,645,230,35);
    printPointLine1DX(835,955,230,35);
    glBegin(GL_POINTS);
    glColor3f(1.000f, 0.843f, 0.000f);
    glVertex2i(185, 230);
    glEnd();

    printPointLine1DX(220,355,195,35);
    printPointLine1DX(535,645,195,35);
    printPointLine1DX(835,925,195,35);
    glBegin(GL_POINTS);
    glColor3f(1.000f, 0.843f, 0.000f);
    glVertex2i(220, 195);
    glEnd();

    printPointLine1DX(285,380,160,35);
    printPointLine1DX(535,645,160,35);
    printPointLine1DX(800,885,160,35);

    glBegin(GL_POINTS);
    glColor3f(0.000f, 0.000f, 0.000f);
    glVertex2i(535, 125);
    glVertex2i(640, 125);
    glEnd();

    glFlush ();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("OpenGL Batman");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}
