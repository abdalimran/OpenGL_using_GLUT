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
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5.0);
    glLineWidth(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800.0, 1000.0, -1000.0, 800.0);
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    //Drawing 3 points
    glBegin(GL_POINTS);
        glColor3f (1.0, 0.0, 0.0);
        glVertex2i(-750, 750);
        glVertex2i(-700, 750);
        glVertex2i(-650, 750);
        glVertex2i(-600, 750);
    glEnd();

    //Drawing a line
    glBegin(GL_LINES);
        glColor3f (1.0, 0.0, 1.0);
        glVertex2i(-750, 600);
        glVertex2i(-600, 600);
    glEnd();

    //Drawing a triangle
    glBegin(GL_TRIANGLES);
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(-750, 300); //A
        glVertex2i(-450, 300); //B
        glVertex2i(-600, 500); //C
    glEnd();

    //Drawing a rectangle
    glBegin(GL_QUADS);
        glColor3f (1.0, 0.0, 0.0);
        glVertex2i(-750, 0); //A
        glVertex2i(-750, 200); //B
        glVertex2i(-450, 200); //C
        glVertex2i(-450, 0); //D
    glEnd();


    //Drawing a Pentagon
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.0, 1.0);
        glVertex2i(-600, -100); //A
        glVertex2i(-750, -200); //B
        glVertex2i(-650, -400); //C
        glVertex2i(-550, -400); //D
        glVertex2i(-450, -200); //E
        glVertex2i(-450, -200); //E
    glEnd();


    //Drawing a Hexagon
    glBegin(GL_POLYGON);
        glColor3f (0.0, 1.0, 0.0);
        glVertex2i(-650, -800); //A
        glVertex2i(-750, -650); //B
        glVertex2i(-650, -500); //C
        glVertex2i(-550, -500); //D
        glVertex2i(-450, -650); //E
        glVertex2i(-550, -800); //F
    glEnd();

    //Drawing a Heptagon
    glBegin(GL_POLYGON);
        glColor3f (0.0, 1.0, 0.0);
        glVertex2i(450, 750); //B
        glVertex2i(350, 750); //A
        glVertex2i(250, 650); //C
        glVertex2i(300, 550); //D
        glVertex2i(400, 450); //E
        glVertex2i(500, 550); //F
        glVertex2i(550, 650); //G
    glEnd();

    //Drawing a Octagon
    glBegin(GL_POLYGON);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2i(400, 400); //B
        glVertex2i(300, 350); //A
        glVertex2i(250, 250); //C
        glVertex2i(300, 150); //D
        glVertex2i(400, 100); //E
        glVertex2i(500, 150); //F
        glVertex2i(550, 250); //G
        glVertex2i(500, 350); //H
    glEnd();

    //Drawing a Nonagon
    glBegin(GL_POLYGON);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(280, -300); //A
        glVertex2i(250, -200); //B
        glVertex2i(300, -100); //C
        glVertex2i(400, -50); //D
        glVertex2i(500, -100); //E
        glVertex2i(550, -200); //F
        glVertex2i(520, -300); //G
        glVertex2i(450, -380); //H
        glVertex2i(350, -380); //I
    glEnd();

    //Drawing a Decagon
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.0, 0.0);
        glVertex2i(400, -450); //A
        glVertex2i(300, -500); //B
        glVertex2i(250, -600); //C
        glVertex2i(280, -700); //D
        glVertex2i(330, -750); //E
        glVertex2i(400, -780); //F
        glVertex2i(480, -750); //G
        glVertex2i(520, -700); //H
        glVertex2i(550, -600); //I
        glVertex2i(500, -500); //J
    glEnd();

    glFlush ();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("OpenGL Shapes");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();

    return 0;
}
