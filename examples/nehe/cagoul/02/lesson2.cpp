//
// This code was created by Jeff Molofee '99
// (ported to Linux/GLUT by Richard Campbell '99)
// (and again to cagoul by John Bytheway 2010)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe
// (email Richard Campbell at ulmont@bellsouth.net)
//
#include <cstdlib>
#include <cassert>
#include <unistd.h>             // Header File For sleeping.
#include <GL/glut.h>            // Header File For The GLUT Library
#include <GL/glu.h>             // Header File For The GLu32 Library
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/equal_to.hpp>
#include <cagoul/all.hpp>

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window;

/* A general OpenGL initialization function.  Sets all of the initial
 * parameters. */
void InitGL(int Width, int Height)
{
  // This Will Clear The Background Color To Black
  cagoul::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  assert(
    cagoul::ClearColor() == boost::fusion::make_vector(0.0f, 0.0f, 0.0f, 0.0f)
  );
  cagoul::ClearDepth(1.0);      // Enables Clearing Of The Depth Buffer
  assert(cagoul::ClearDepth() == 1.0);
  cagoul::DepthFunc(cagoul::DepthFunc.LESS); // The Type Of Depth Test To Do
  assert(cagoul::DepthFunc() == cagoul::DepthFunc.LESS);
  assert(cagoul::DepthFunc.LESS == cagoul::enums::DepthFunc::LESS);
  assert(!cagoul::DepthFunc.IsEnabled());
  cagoul::DepthFunc.Enable();   // Enables Depth Testing
  assert(cagoul::DepthFunc.IsEnabled());
  glShadeModel(GL_SMOOTH);      // Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();             // Reset The Projection Matrix

  gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);      // Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height == 0)              // Prevent A Divide By Zero If The Window Is Too Small
    Height = 1;

  glViewport(0, 0, Width, Height);      // Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear The Screen And The Depth Buffer
  glLoadIdentity();             // Reset The View

  glTranslatef(-1.5f, 0.0f, -6.0f);     // Move Left 1.5 Units And Into The Screen 6.0

  // draw a triangle
  glBegin(GL_POLYGON);          // start drawing a polygon
  glVertex3f(0.0f, 1.0f, 0.0f); // Top
  glVertex3f(1.0f, -1.0f, 0.0f);        // Bottom Right
  glVertex3f(-1.0f, -1.0f, 0.0f);       // Bottom Left
  glEnd();                      // we're done with the polygon

  glTranslatef(3.0f, 0.0f, 0.0f);       // Move Right 3 Units

  // draw a square (quadrilateral)
  glBegin(GL_QUADS);            // start drawing a polygon (4 sided)
  glVertex3f(-1.0f, 1.0f, 0.0f);        // Top Left
  glVertex3f(1.0f, 1.0f, 0.0f); // Top Right
  glVertex3f(1.0f, -1.0f, 0.0f);        // Bottom Right
  glVertex3f(-1.0f, -1.0f, 0.0f);       // Bottom Left
  glEnd();                      // done with the polygon

  // swap buffers to display, since we're double buffered.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int, int)
{
  /* avoid thrashing this procedure */
  usleep(100);

  /* If escape is pressed, kill everything. */
  if (key == ESCAPE) {
    /* shut down our window */
    glutDestroyWindow(window);

    /* exit the program...normal termination. */
    exit(0);
  }
}

int main(int argc, char **argv)
{
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */
  glutInit(&argc, argv);

  /* Select type of Display mode:
     Double buffer
     RGBA color
     Alpha components supported
     Depth buffer */
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

  /* get a 640 x 480 window */
  glutInitWindowSize(640, 480);

  /* the window starts at the upper left corner of the screen */
  glutInitWindowPosition(0, 0);

  /* Open a window */
  window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");

  /* Register the function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);

  /* Go fullscreen.  This is the soonest we could possibly go fullscreen. */
  glutFullScreen();

  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */
  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */
  InitGL(640, 480);

  /* Start Event Processing Engine */
  glutMainLoop();

  return 1;
}
