#include <GL/glut.h>

void bgColor(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200, 200, -200, 200);
    glMatrixMode(GL_MODELVIEW);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
   // glLoadIdentity();
    glColor3f(1.0, 0.5, 0.2);
    glLineWidth(10.0);
    glBegin(GL_POLYGON);
        glVertex2i(100, -100);
        glVertex2i(-100, 100);
        glVertex2i(-100, 100);
        glVertex2i(100, 100);
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Draw Line");
    glutDisplayFunc(display);
    bgColor();
    glutMainLoop();

    return 0;
}
