#include <cagoul/scoped/orthographicprojection.hpp>

#include <cagoul/scoped/matrixmode.hpp>

namespace cagoul { namespace scoped {

namespace {

  void impl(
    double minx, double maxx, double miny, double maxy, bool invert
  )
  {
    MatrixMode scope(enums::MatrixMode::PROJECTION);
    // save previous matrix which contains the
    // settings for the perspective projection
    glPushMatrix();
    // reset matrix
    glLoadIdentity();
    // set a 2D orthographic projection
    glOrtho(minx, maxx, miny, maxy, -1, 1);
    if (invert) {
      // invert the y axis, down is positive
      glScalef(1, -1, 1);
      // move the origin from the bottom left corner
      // to the upper left corner
      glTranslatef(0, -maxy-miny, 0);
    }
  }

}

OrthographicProjection::OrthographicProjection(
  double width, double height, bool invert
)
{
  impl(0, width, 0, height, invert);
}

OrthographicProjection::OrthographicProjection(
  double minx, double maxx, double miny, double maxy, bool invert
)
{
  impl(minx, maxx, miny, maxy, invert);
}

OrthographicProjection::~OrthographicProjection()
{
  MatrixMode scope(enums::MatrixMode::PROJECTION);
  glPopMatrix();
}

}}

