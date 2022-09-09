#include <windows.h>
#include <GL/glut.h>
int state = 1;
void bgColor(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
    gluPerspective(60, 1, 2.0, 300.0);
    glMatrixMode(GL_MODELVIEW);

}

int XPosition = -10;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -1.0);
    glBegin(GL_QUADS);
       //front
    glColor3f(1.0,0.0,0.0);
    glVertex3d(-300.0,300.0,300.0);
    glVertex3d(-300.0,-300.0,300.0);
    glVertex3d(300.0,-300.0,300.0);
    glVertex3d(300.0,300.0,300.0);
    //back
    glColor3f(0.0,1.0,0.0);
    glVertex3d(300.0,300.0,-300.0);
    glVertex3d(300.0,-300.0,-300.0);
    glVertex3d(-300.0,-300.0,-300.0);
    glVertex3d(-300.0,300.0,-300.0);
    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3d(300.0,300.0,300.0);
    glVertex3d(300.0,-300.0,300.0);
    glVertex3d(300.0,-300.0,-300.0);
    glVertex3d(300.0,300.0,-300.0);
    //left
    glColor3f(1.0,1.0,0.0);
    glVertex3d(-300.0,300.0,-300.0);
    glVertex3d(-300.0,-300.0,-300.0);
    glVertex3d(-300.0,-300.0,300.0);
    glVertex3d(-300.0,300.0,300.0);
    //top
    glColor3f(0.0,1.0,1.0);
    glVertex3d(-300.0,300.0,-300.0);
    glVertex3d(-300.0,300.0,300.0);
    glVertex3d(300.0,300.0,300.0);
    glVertex3d(300.0,300.0,-300.0);
    //bottom
    glColor3f(1.0,0.0,1.0);
    glVertex3d(-300.0,-300.0,-300.0);
    glVertex3d(-300.0,-300.0,300.0);
    glVertex3d(300.0,-300.0,300.0);
    glVertex3d(300.0,-300.0,-300.0);
    glEnd();

    glFlush();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/300, timer, 0);
//      switch(state){
//  case 1:
//      if(XPosition < 275){
//          XPosition += 5;
//      }
//      else {
//          state = -1;
//      }
//      break;
//  case -1:
//      if(XPosition > -275){
//          XPosition -= 5;
//      }
//      else{
//          state = 1;
//      }
//      break;
//  }

}


int main(int argc, char * argv[]){
     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Draw Line");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
//    glutTimerFunc(0, timer, 0);
    bgColor();
    glutMainLoop();

    return 0;
}
