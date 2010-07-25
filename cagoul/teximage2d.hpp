#ifndef CAGOUL__TEXIMAGE_D_HPP
#define CAGOUL__TEXIMAGE_D_HPP

#include <cagoul/toggler.hpp>

namespace cagoul {

namespace detail {

class TexImage2D_type :
  /** \bug There are two things one might wish to toggle: GL_TEXTURE_2D and
   * GL_TEXTURE_CUBE_MAP.  This provides access only to the former. */
  public toggler<GL_TEXTURE_2D> {
  public:
    TexImage2D_type() {}
};

}

static const detail::TexImage2D_type TexImage2D;

}

#endif // CAGOUL__TEXIMAGE_D_HPP

