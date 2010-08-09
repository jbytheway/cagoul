#ifndef CAGOUL__FORMAT_FOR_GIL_VIEW_HPP
#define CAGOUL__FORMAT_FOR_GIL_VIEW_HPP

#include <boost/gil/typedefs.hpp>

#include <cagoul/enums/teximage2dformat.hpp>

namespace cagoul {

namespace detail {

  /** \bug Implementation incomplete; there are lots more layouts */
  inline enums::TexImage2DFormat format_for_gil_layout(
    boost::gil::rgb_layout_t const&
  ) {
    return enums::TexImage2DFormat::RGB;
  }

  inline enums::TexImage2DFormat format_for_gil_layout(
    boost::gil::gray_layout_t const&
  ) {
    return enums::TexImage2DFormat::LUMINANCE;
  }

}

/** \brief Get the GL format name for a Boost.GIL view.
 *
 * \return The value of enums::TexImage2DFormat which should be passed to
 * glTexImage2d or cagoul::TexImage2D to convert the data in this View into a
 * GL texture.
 */
template<typename View>
inline enums::TexImage2DFormat format_for_gil_view(View const&) {
  return detail::format_for_gil_layout(typename View::value_type::layout_t());
}

}

#endif // CAGOUL__FORMAT_FOR_GIL_VIEW_HPP

