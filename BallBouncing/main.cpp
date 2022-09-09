#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#define PI 3.14159265

GLint circle_points = 20;
void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius)
{

     GLdouble angle;
     glBegin(GL_POLYGON);
     for(int i = 0; i < circle_points; i++)
     {
     angle=2*PI*i/circle_points;
     glVertex2f(centerx+radius*cos(angle),
     centery + radius * sin(angle));
 }

  glEnd();
}
int refreshMills = 1000/60;
double count = 0.1;
int factor = 1;
void Timer(int value)
{
    glutPostRedisplay(); // Post re-paint request to activate display();
    glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}
float randomColor(void)
{
float randomColorNumber = static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
return randomColorNumber;
}
void display(void)
{
.
    glClear(GL_COLOR_BUFFER_BIT);
    if( count < 10.0)
    factor = 1;
    else if( count > 100.0)
    factor = -3;
    glColor3f(randomColor(), randomColor(), randomColor());
    count = count + ( factor * 1);
    //cout << count << endl;
    glPushMatrix();
    glTranslatef(80 , count, 0.0);
    glColor3f(1.0, 0.6, 0.0);
    MyCircle2f(0.0,5.0, 15);
    //glBegin(GL_POINTS);
    // Color the first point
    //glVertex2f(10.0, 10.0);
    //glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
void init(void){

    // Perform some initialization before we begin to render.
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glViewport(0, 0, 320, 240);
    glPointSize(10);
    gluOrtho2D(0.0, 160.0, 0.0, 120);
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    // BUFFER MODE IS ONLY SINGLE or SINGLE BUFFER MODE.
    // Colors will be defined in RGB Format.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(320, 240);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bouncing Ball");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, Timer, 0);
    glutMainLoop();
    return 0;
}
