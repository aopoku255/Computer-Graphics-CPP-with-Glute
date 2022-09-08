#include <windows.h>
#include <GL/glut.h>
int state = 1;
void bgColor(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluOrtho2D(-300, 300, -300, 300);
    gluPerspective(60, 1, 2.0, 300.0);
    glMatrixMode(GL_MODELVIEW);

}

int XPosition = -10;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   glShadeModel(GL_SMOOTH);
    glColor3f(0.0, 1.0, 0.0);
//    glPointSize(30);
    glTranslated(0.0, 0.0, -300.0);
    glBegin(GL_POLYGON);
        glVertex3i(XPosition, 10, 0);
        glVertex3i(XPosition + 20, 10, 0);
        glVertex3i(XPosition + 20, -10, 0);
        glVertex3i(XPosition, -10, 0);
    glEnd();

     glBegin(GL_TRIANGLES);
     glColor3f(1.0, 0.0, 0.0);
      glVertex2i(-150, 0);
      glColor3f(0.0, 1.0, 0.0);
      glVertex2i(150, 0);
      glColor3f(0.0, 0.0, 1.0);
      glVertex2i(0, 180);

     glEnd();
    glutSwapBuffers();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
     switch(state){
 case 1:
     if(XPosition < 275){
         XPosition += 5;
     }
     else {
         state = -1;
     }
     break;
 case -1:
     if(XPosition > -275){
         XPosition -= 5;
     }
     else{
         state = 1;
     }
     break;
 }

}


int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Draw Line");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    bgColor();
    glutMainLoop();

    return 0;
}
