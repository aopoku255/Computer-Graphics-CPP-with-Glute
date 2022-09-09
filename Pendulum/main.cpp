#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#define PI 3.142

GLfloat cx; GLfloat cy = -1.2;

GLfloat angle;

GLfloat radius; GLfloat rots = 0.4;

GLfloat check;

void Display()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Color of the pendulum 
glColor3f(1, 0,1);

check += rots;

if ((check > 45)||(check <-45))
    rots*= -1;

glRotatef (rots, 0, 0,1);

// Draw the ball of the pendulum

glBegin(GL_POLYGON); 
for (int i = 0; i < 100; i++){
    angle = 2 * PI * i / 100;
    glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
}
glEnd();

// Draw the line

glBegin(GL_LINES); 
    glVertex2f(0,0);
    glVertex2f(cx,cy);

glEnd();

glutSwapBuffers();

}

void Init()
{
glTranslatef(0, 0.5, 0);

}

int main(int argc, char * argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // glutInitWindowSize(300, 300);
    // glutInitWindowPosition(200, 200);
    glutCreateWindow("Pendulum");
    glutDisplayFunc(Display);
    Init();

    glutIdleFunc(Display);

    radius = 0.2;
    glutMainLoop();

    return 0;
}