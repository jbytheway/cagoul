#ifndef CAGOUL__GLUINT_WRAPPER_HPP
#define CAGOUL__GLUINT_WRAPPER_HPP

#include <GL/gl.h>

namespace cagoul {

/** \brief A simple wrapper round GLuint, to be a base class of strong
 * typedefs. */
class GLuint_wrapper {
  protected:
    /** \brief The wrapped GLuint; accessible to base classes. */
    GLuint value_;
};

}

#endif // CAGOUL__GLUINT_WRAPPER_HPP

