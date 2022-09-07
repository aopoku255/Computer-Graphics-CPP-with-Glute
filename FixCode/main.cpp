// A simple testing program for OpenGL with GLUT
#include <windows.h>
#include <GL/glut.h>
void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

void bgColor(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}
int main(int arg, char * argv[])
{
    glutInit(&arg, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    bgColor();
    glutMainLoop();
    return 0;
}
