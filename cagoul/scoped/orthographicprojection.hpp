#ifndef CAGOUL_SCOPED__ORTHOGRAPHICPROJECTION_HPP
#define CAGOUL_SCOPED__ORTHOGRAPHICPROJECTION_HPP

namespace cagoul { namespace scoped {

/** \brief Class which changes the GL projection to orthographic temporarily.
 *
 * While an instance of this class is in scope the GL_PROJECTION is changed to
 * an orthographic projection with specified parameters.
 *
 * Typically this might be used to write e.g. a HUD atop the true-3D portion of
 * an image.
 */
class OrthographicProjection {
  public:
    /** \brief Equivalent to
     * OrthographicProjection(0, width, 0, height, invert)
     */
    OrthographicProjection(
      double width, double height, bool invert=false
    );
    /** \brief Sets viewport to see given coordinates.
     *
     * Arrange for the viewport to see the x range between minx and
     * maxx, the y range between miny and maxy.
     *
     * If invert is set, then reverses the y coordinate range (i.e. y
     * increases down the screen; the default is for y to increase up the
     * screen).
     */
    OrthographicProjection(
      double minx, double maxx, double miny, double maxy, bool invert=false
    );
    ~OrthographicProjection();
  private:
    OrthographicProjection(OrthographicProjection const&);
    OrthographicProjection& operator=(OrthographicProjection const&);
};

}}

#endif // CAGOUL_SCOPED__ORTHOGRAPHICPROJECTION_HPP

