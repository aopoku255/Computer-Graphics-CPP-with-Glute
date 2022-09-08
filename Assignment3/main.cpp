#include <windows.h>
#include <gl\glut.h>
void Refresh_timer( int )
{
     glutPostRedisplay();
     glutTimerFunc(3000/60, Refresh_timer, 0);
}
void Display(void)
{
 //clear all piiels with the specified clear color
    glClear(GL_COLOR_BUFFER_BIT);
    //draw the four points in four colors
    glPointSize(100);
    glBegin(GL_POINTS);
    glColor3ub(rand()%255, rand()%255, rand()%255);// green
    glVertex2f(10.0,10.1);
    glColor3ub(rand()%255, rand()%255, rand()%255); // yellow
    glVertex2f(10.,110);
    glColor3ub(rand()%255, rand()%255, rand()%255);// blue
    glVertex2f( 150.,110.);
    glColor3ub(rand()%255, rand()%255, rand()%255); //white
    glVertex2f(150,10.);
    glEnd();
    //dont wait, start flushing OpenGL calls to display buffer
    glutSwapBuffers();
}
void reshape (int w, int h)
{
// on reshape and on startup, keep the viewport to be the entire size of the window
    glViewport (0,0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    // keep our world coordinate system constant
    gluOrtho2D(-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);
}
void init(void){
    glClearColor( 0.1, 0.1, 0.05, 0.0);
    // set the point size to be 5.0 pixels
    glPointSize(5.0);

}

int main( int argc, char** argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); //uses two buffers ie. visible and RGB shows the colors
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Colors window");
    init();
    glutTimerFunc(0, Refresh_timer, 0);
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
