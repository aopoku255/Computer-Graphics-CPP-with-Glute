#include <windows.h>
#include <GL/glut.h>

void init(){
    glClearColor(1.0, 1.0, 0.1, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200, 0.0, 150);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(180, 15);
        glVertex2i(10, 145);
    glEnd();
    glFlush();

}

int main(int argc, char * argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tutorial 2");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
