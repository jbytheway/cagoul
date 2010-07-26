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

/** \internal */
class TexImage2D_type :
  /** \bug There are two things one might wish to toggle: GL_TEXTURE_2D and
   * GL_TEXTURE_CUBE_MAP.  This provides access only to the former. */
  public toggler<GL_TEXTURE_2D> {
  public:
    TexImage2D_type() {}

    /** \brief Save a Boost.GIL image view as a GL texture.
     *
     * \param target GL texture to modify.
     * \param level Mipmap to modify.
     * \param internalFormat Format in which to store the texture.
     * \param imageView Boost.GIL view to use as source image.
     */
    template<typename View>
    void operator()(
      enums::TexImage2DTarget const target,
      GLint const level,
      enums::TexImage2DInternalFormat const internalFormat,
      View const& imageView
    ) const {
      (*this)(
        target, level, internalFormat,
        imageView.width(), imageView.height(),
        0,
        format_for_gil_view(imageView),
        type_for_gil_view(imageView),
        &*imageView.row_begin(0)
      );
    }

    /** \brief Wrapper round glTexImage2D. */
    void operator()(
      enums::TexImage2DTarget const target,
      GLint const level,
      enums::TexImage2DInternalFormat const internalFormat,
      GLsizei const width,
      GLsizei const height,
      GLint const border,
      enums::TexImage2DFormat const format,
      enums::TexImage2DType const type,
      GLvoid const* data
    ) const {
      glTexImage2D(
        target, level, internalFormat, width, height, border,
        format, type, data
      );
    }
};

}

static const detail::TexImage2D_type TexImage2D;

}

#endif // CAGOUL__TEXIMAGE_D_HPP

