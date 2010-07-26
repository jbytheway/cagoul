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

}

template<typename View>
inline enums::TexImage2DFormat format_for_gil_view(View const&) {
  return detail::format_for_gil_layout(typename View::value_type::layout_t());
}

}

#endif // CAGOUL__FORMAT_FOR_GIL_VIEW_HPP

