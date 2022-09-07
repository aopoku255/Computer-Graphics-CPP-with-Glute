#include <GL/glut.h>

void bgColor(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200, 0.0, 150);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
   // glLoadIdentity();
    glColor3f(1.0, 0.5, 0.2);
    glBegin(GL_LINES);
        glVertex2i(150, 15);
        glVertex2i(10, 100);
    glEnd();
    glFlush();
}


int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Draw Line");
    glutDisplayFunc(display);
    bgColor();
    glutMainLoop();

    return 0;
}
