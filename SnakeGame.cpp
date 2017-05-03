#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

int N = 45, M = 30;
int Scale = 25;
int w = Scale * N;
int h = Scale * M;

int direction, num = 4, score=0;

char sScore[15];

struct
{
    int x;
    int y;
}s[100];

class Fructs
{
    public:
        int x, y;

    void New()
    {
        x = rand() % N;
        y = rand() % M;
    }

    void DrawFood()
    {
        glColor3f(0.863, 0.078, 0.235);
        glRectf(x * Scale, y * Scale, (x + 1) * Scale, (y + 1) * Scale);
    }

}m[10];

void draw_string(void *font, const char* string)
{
    while(*string)
        glutStrokeCharacter(font, *string++);
}

void DrawField()
{
    glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_LINES);

    for (int i = 0; i < w; i += Scale)
    {
        glVertex2f(i, 0);
        glVertex2f(i, h);
    }

    for (int j = 0; j < h; j += Scale)
    {
        glVertex2f(0, j);
        glVertex2f(w, j);
    }

    glEnd();
}

void SnakeControl()
{
    for (int i = num; i > 0; --i)
    {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (direction == 0)
        s[0].y += 1;

    if (direction == 1)
        s[0].x -= 1;

    if (direction == 2)
        s[0].x += 1;

    if (direction == 3)
        s[0].y -= 1;

    for (int i = 0; i < 10; i++)
    {
        if ((s[0].x == m[i].x) && (s[0].y == m[i].y))
        {
            num++;
            m[i].New();
            score++;
        }
    }

    if (s[0].x > N)
        direction = 1;

    if (s[0].x < 0)
        direction = 2;

    if (s[0].y > M)
        direction = 3;

    if (s[0].y < 0)
        direction = 0;

    for (int i = 1; i < num; i++)
    {
        if (s[0].x == s[i].x && s[0].y == s[i].y)
        {
            num = i;
            score=0;
        }

    }
}

void DrawSnake()
{
    glColor3f(0.678, 1.000, 0.184);
    for (int i = 0; i < num; i++)
    {
        glRectf(s[i].x * Scale, s[i].y * Scale, (s[i].x + 0.9) * Scale,(s[i].y + 0.9) * Scale);
    }
}

void KeyboardControl(int key, int a, int b)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            direction = 0;
            break;
        case GLUT_KEY_RIGHT:
            direction = 2;
            break;
        case GLUT_KEY_LEFT:
            direction = 1;
            break;
        case GLUT_KEY_DOWN:
            direction = 3;
            break;
    }
}

void DisplayScore()
{
    glLineWidth(3.5f);
    glColor3f (1.000, 0.973, 0.863);
    glPushMatrix();
    glTranslatef(w/(1.3), h/(1.06), 0);
    glScalef(0.2f, 0.3f, 0.3f);
    draw_string(GLUT_STROKE_MONO_ROMAN, "Score:");
    glPopMatrix();

    sprintf(sScore,"%9d", score);
    glPushMatrix();
    glTranslatef(w/(1.35), h/(1.06), 0);
    glScalef(0.2f, 0.3f, 0.3f);
    draw_string(GLUT_STROKE_MONO_ROMAN, sScore);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < 5; i++)
    {
        m[i].DrawFood();
    }

    DrawField();
    DrawSnake();
    DisplayScore();

    glFlush();
}

void SnakeSpeed(int = 0)
{
    display();
    SnakeControl();
    glutTimerFunc(100, SnakeSpeed, 0);
}

int main(int argc, char **argv)
{
    for (int i = 0; i < 10; i++)
    {
        m[i].New();
    }

    s[0].x = 10;
    s[0].y = 10;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutCreateWindow("Snake Game");
    glClearColor(0.133, 0.545, 0.133, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glutDisplayFunc(display);
    glutTimerFunc(100, SnakeSpeed, 0);
    glutSpecialFunc(KeyboardControl);

    glutMainLoop();

    return 0;
}
