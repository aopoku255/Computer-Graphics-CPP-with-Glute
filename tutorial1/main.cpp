#include <GL/glut.h>
#include <windows.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glutSolidTeapot(.3);
    glFlush();
}




int main(int arg, char *argv[]){

    glutInit(&arg, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tutorial one");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
