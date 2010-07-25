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
#include <stdlib.h>             // For exit()
#include <unistd.h>             // For sleeping.
#include <GL/glut.h>            // For The GLUT Library
#include <GL/glu.h>             // For The GLu32 Library
#include <cagoul/all.hpp>

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window;

/* A general OpenGL initialization function.  Sets all of the initial
 * parameters. */
// We call this right after our OpenGL window is created.
void InitGL(int Width, int Height)
{
  // This Will Clear The Background Color To Black
  cagoul::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  cagoul::ClearDepth(1.0);      // Enables Clearing Of The Depth Buffer
  cagoul::DepthFunc(cagoul::DepthFunc.LESS); // The Type Of Depth Test To Do
  cagoul::DepthFunc.Enable();   // Enables Depth Testing
  // Enables Smooth Color Shading
  cagoul::ShadeModel(cagoul::ShadeModel.SMOOTH);

  cagoul::scoped::MatrixMode scope(cagoul::MatrixMode.PROJECTION);
  glLoadIdentity();             // Reset The Projection Matrix

  // Calculate The Aspect Ratio Of The Window
  gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);
}

/* The function called when our window is resized (which shouldn't happen,
 * because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height == 0)  // Prevent A Divide By Zero If The Window Is Too Small
    Height = 1;

  // Reset The Current Viewport And Perspective Transformation
  glViewport(0, 0, Width, Height);

  cagoul::scoped::MatrixMode scope(cagoul::MatrixMode.PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);
}

/* The main drawing function. */
void DrawGLScene()
{
  // Clear The Screen And The Depth Buffer
  cagoul::Clear(
    cagoul::Clear.COLOR_BUFFER_BIT | cagoul::Clear.DEPTH_BUFFER_BIT
  );
  glLoadIdentity();             // Reset The View

  // Move Left 1.5 Units And Into The Screen 6.0
  glTranslatef(-1.5f, 0.0f, -6.0f);

  // draw a triangle (in smooth coloring mode)
  glBegin(GL_POLYGON);          // start drawing a polygon
  glColor3f(1.0f, 0.0f, 0.0f);  // Set The Color To Red
  glVertex3f(0.0f, 1.0f, 0.0f); // Top
  glColor3f(0.0f, 1.0f, 0.0f);  // Set The Color To Green
  glVertex3f(1.0f, -1.0f, 0.0f);        // Bottom Right
  glColor3f(0.0f, 0.0f, 1.0f);  // Set The Color To Blue
  glVertex3f(-1.0f, -1.0f, 0.0f);       // Bottom Left  
  glEnd();    // we're done with the polygon (smooth color interpolation)

  glTranslatef(3.0f, 0.0f, 0.0f);       // Move Right 3 Units

  // draw a square (quadrilateral)
  glColor3f(0.5f, 0.5f, 1.0f);  // set color to a blue shade.
  glBegin(GL_QUADS);            // start drawing a polygon (4 sided)
  glVertex3f(-1.0f, 1.0f, 0.0f);        // Top Left
  glVertex3f(1.0f, 1.0f, 0.0f); // Top Right
  glVertex3f(1.0f, -1.0f, 0.0f);        // Bottom Right
  glVertex3f(-1.0f, -1.0f, 0.0f);       // Bottom Left
  glEnd();                      // done with the polygon

  // we need to swap the buffer to display our drawing.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int /*x*/, int /*y*/)
{
  /* sleep to avoid thrashing this procedure */
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
  /* Initialize GLUT state - glut will take any command line arguments that
   * pertain to it or X Windows - look at its documentation at
   * http://reality.sgi.com/mjk/spec3/spec3.html */
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
