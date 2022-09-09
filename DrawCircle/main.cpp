#include <windows.h>
#include <GL/glut.h>
#include <math.h>
GLint halfCircle = 180;

void bgColor(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);
    float theta;
        for(int i = 0; i < 360; i++){
            theta = 3.142 * i / 360;
            glVertex2f(0 + 0.3 * cos(theta), 0 + 0.3* sin(theta));
        }

    glEnd();
    glFlush();
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Draw Circle");
    bgColor();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
