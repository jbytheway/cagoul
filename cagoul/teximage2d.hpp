#ifndef CAGOUL__TEXIMAGE_D_HPP
#define CAGOUL__TEXIMAGE_D_HPP

#include <GL/gl.h>

#include <cagoul/enums/teximage2dtarget.hpp>
#include <cagoul/enums/teximage2dinternalformat.hpp>
#include <cagoul/enums/teximage2dformat.hpp>
#include <cagoul/enums/teximage2dtype.hpp>
#include <cagoul/toggler.hpp>
#include <cagoul/format_for_gil_view.hpp>
#include <cagoul/type_for_gil_view.hpp>

namespace cagoul {

namespace detail {

class TexImage2D_type :
  /** \bug There are two things one might wish to toggle: GL_TEXTURE_2D and
   * GL_TEXTURE_CUBE_MAP.  This provides access only to the former. */
  public toggler<GL_TEXTURE_2D> {
  public:
    TexImage2D_type() {}

    template<typename View>
    void operator()(
      enums::TexImage2DTarget const target,
      GLint const level,
      enums::TexImage2DInternalFormat const internal_format,
      View const& image_view
    ) const {
      (*this)(
        target, level, internal_format,
        image_view.width(), image_view.height(),
        0,
        format_for_gil_view(image_view),
        type_for_gil_view(image_view),
        &*image_view.row_begin(0)
      );
    }

    void operator()(
      enums::TexImage2DTarget const target,
      GLint const level,
      enums::TexImage2DInternalFormat const internal_format,
      GLsizei const width,
      GLsizei const height,
      GLint const border,
      enums::TexImage2DFormat const format,
      enums::TexImage2DType const type,
      GLvoid const* data
    ) const {
      glTexImage2D(
        target, level, internal_format, width, height, border,
        format, type, data
      );
    }
};

}

static const detail::TexImage2D_type TexImage2D;

}

#endif // CAGOUL__TEXIMAGE_D_HPP

