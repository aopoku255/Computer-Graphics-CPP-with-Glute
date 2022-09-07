#include <GL/glut.h>
#include <cstdlib>
void Refresh_timer( int value )
{
     glutPostRedisplay();
     glutTimerFunc( 200, Refresh_timer, 0);
}
void display()
{
     glClear( GL_COLOR_BUFFER_BIT );
     float r=rand()%256/255.0f;
     float g=rand()%256/255.0f;
     float b=rand()%256/255.0f;
     glClearColor( r, g, b ,1.0);
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glutSwapBuffers();
}
int main( int argc, char** argv )
{
     glutInit( &argc, argv );
     glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
     glutInitWindowSize( 600, 400 );
     glutCreateWindow( "Computer" );
     glutDisplayFunc( display );
     glutTimerFunc( 50, Refresh_timer, 0 );
     glutMainLoop();
     return 0;
}
