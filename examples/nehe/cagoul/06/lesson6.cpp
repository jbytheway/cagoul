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
#include <stdio.h>              // Header file for standard file i/o.
#include <stdlib.h>             // Header file for malloc/free.
#include <unistd.h>             // needed to sleep.
#include <GL/glut.h>            // Header File For The GLUT Library
#include <GL/glu.h>             // Header File For The GLu32 Library
#include <boost/gil/typedefs.hpp>
#include <boost/gil/image.hpp>
#include <cagoul/all.hpp>

// workaround Boost.GIL bug https://svn.boost.org/trac/boost/ticket/3908
// (should be fixed in 1.44 or 1.45)
#ifndef png_infopp_NULL
#define png_infopp_NULL NULL
#endif
#ifndef int_p_NULL
#define int_p_NULL NULL
#endif
#include <boost/gil/extension/io/png_io.hpp>

/* ascii code for the escape key */
#define ESCAPE 27

/* The number of our GLUT window */
int window;

cagoul::texture texture(cagoul::enums::BindTextureTarget::TEXTURE_2D);

// Load image and convert to texture
void LoadGLTextures()
{
  char const* filename = "../../data/NeHe.png";
  boost::gil::rgb8_image_t image;
  boost::gil::png_read_image(filename, image);
  assert(image.width() == 256);
  assert(image.height() == 256);

  cagoul::scoped::BindTexture s(texture);

  // scale linearly when image bigger than texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // scale linearly when image smalled than texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  cagoul::TexImage2D(
    cagoul::enums::TexImage2DTarget::TEXTURE_2D,
    0 /*mipmap level*/,
    cagoul::enums::TexImage2DInternalFormat::RGB,
    const_view(image)
  );
};

/* A general OpenGL initialization function.  Sets all of the initial
 * parameters. */
// We call this right after our OpenGL window is created.
void InitGL(int Width, int Height)
{
  LoadGLTextures();             // Load The Texture(s)
  cagoul::TexImage2D.Enable();  // Enable Texture Mapping

  // Clear The Background Color To Blue
  cagoul::ClearColor(0.0f, 0.0f, 1.0f, 0.0f);
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

  glTranslatef(0.0f, 0.0f, -5.0f);      // move 5 units into the screen.

  /* floats for x rotation, y rotation, z rotation */
  static float xrot = 0, yrot = 0, zrot = 0;
  glRotatef(xrot, 1.0f, 0.0f, 0.0f);    // Rotate On The X Axis
  glRotatef(yrot, 0.0f, 1.0f, 0.0f);    // Rotate On The Y Axis
  glRotatef(zrot, 0.0f, 0.0f, 1.0f);    // Rotate On The Z Axis

  xrot += 0.003f;                // X Axis Rotation
  yrot += 0.002f;                // Y Axis Rotation
  zrot += 0.004f;                // Z Axis Rotation

  cagoul::scoped::BindTexture s(texture);     // choose the texture to use.

  cagoul::Begin(cagoul::Begin::QUADS)            // begin drawing a cube

    // Front Face (note that the texture's corners have to match the quad's
    // corners)
    .TexCoordf(0.0f, 1.0f)
    .Vertexf(-1.0f, -1.0f, 1.0f)       // Bottom Left Of The Texture and Quad
    .TexCoordf(1.0f, 1.0f)
    .Vertexf(1.0f, -1.0f, 1.0f)        // Bottom Right Of The Texture and Quad
    .TexCoordf(1.0f, 0.0f)
    .Vertexf(1.0f, 1.0f, 1.0f)         // Top Right Of The Texture and Quad
    .TexCoordf(0.0f, 0.0f)
    .Vertexf(-1.0f, 1.0f, 1.0f)        // Top Left Of The Texture and Quad

    // Back Face
    .TexCoordf(1.0f, 1.0f)
    .Vertexf(-1.0f, -1.0f, -1.0f)      // Bottom Right Of The Texture and Quad
    .TexCoordf(1.0f, 0.0f)
    .Vertexf(-1.0f, 1.0f, -1.0f)       // Top Right Of The Texture and Quad
    .TexCoordf(0.0f, 0.0f)
    .Vertexf(1.0f, 1.0f, -1.0f)        // Top Left Of The Texture and Quad
    .TexCoordf(0.0f, 1.0f)
    .Vertexf(1.0f, -1.0f, -1.0f)       // Bottom Left Of The Texture and Quad

    // Top Face
    .TexCoordf(0.0f, 0.0f)
    .Vertexf(-1.0f, 1.0f, -1.0f)       // Top Left Of The Texture and Quad
    .TexCoordf(0.0f, 1.0f)
    .Vertexf(-1.0f, 1.0f, 1.0f)        // Bottom Left Of The Texture and Quad
    .TexCoordf(1.0f, 1.0f)
    .Vertexf(1.0f, 1.0f, 1.0f)         // Bottom Right Of The Texture and Quad
    .TexCoordf(1.0f, 0.0f)
    .Vertexf(1.0f, 1.0f, -1.0f)        // Top Right Of The Texture and Quad

    // Bottom Face
    .TexCoordf(1.0f, 0.0f)
    .Vertexf(-1.0f, -1.0f, -1.0f)      // Top Right Of The Texture and Quad
    .TexCoordf(0.0f, 0.0f)
    .Vertexf(1.0f, -1.0f, -1.0f)       // Top Left Of The Texture and Quad
    .TexCoordf(0.0f, 1.0f)
    .Vertexf(1.0f, -1.0f, 1.0f)        // Bottom Left Of The Texture and Quad
    .TexCoordf(1.0f, 1.0f)
    .Vertexf(-1.0f, -1.0f, 1.0f)       // Bottom Right Of The Texture and Quad

    // Right face
    .TexCoordf(1.0f, 1.0f)
    .Vertexf(1.0f, -1.0f, -1.0f)       // Bottom Right Of The Texture and Quad
    .TexCoordf(1.0f, 0.0f)
    .Vertexf(1.0f, 1.0f, -1.0f)        // Top Right Of The Texture and Quad
    .TexCoordf(0.0f, 0.0f)
    .Vertexf(1.0f, 1.0f, 1.0f)         // Top Left Of The Texture and Quad
    .TexCoordf(0.0f, 1.0f)
    .Vertexf(1.0f, -1.0f, 1.0f)        // Bottom Left Of The Texture and Quad

    // Left Face
    .TexCoordf(0.0f, 1.0f)
    .Vertexf(-1.0f, -1.0f, -1.0f)      // Bottom Left Of The Texture and Quad
    .TexCoordf(1.0f, 1.0f)
    .Vertexf(-1.0f, -1.0f, 1.0f)       // Bottom Right Of The Texture and Quad
    .TexCoordf(1.0f, 0.0f)
    .Vertexf(-1.0f, 1.0f, 1.0f)        // Top Right Of The Texture and Quad
    .TexCoordf(0.0f, 0.0f)
    .Vertexf(-1.0f, 1.0f, -1.0f)       // Top Left Of The Texture and Quad
    ;

  // since this is double buffered, swap the buffers to display what just got
  // drawn.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int /*x*/, int /*y*/)
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
