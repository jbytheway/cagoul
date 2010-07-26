#ifndef CAGOUL__TYPE_FOR_GIL_VIEW_HPP
#define CAGOUL__TYPE_FOR_GIL_VIEW_HPP

#include <boost/gil/typedefs.hpp>

#include <cagoul/enums/teximage2dtype.hpp>

namespace cagoul {

namespace detail {

  /** \bug Implementation incomplete; probably shouldn't overload specific
   * pixel types, but rather work from the GIL ColorBase concept. */
  inline enums::TexImage2DType type_for_gil_color_base(
    boost::gil::rgb8_pixel_t const&
  ) {
    return enums::TexImage2DType::UNSIGNED_BYTE;
  }

}

template<typename View>
inline enums::TexImage2DType type_for_gil_view(View const&) {
  return detail::type_for_gil_color_base(typename View::value_type());
}

}

#endif // CAGOUL__TYPE_FOR_GIL_VIEW_HPP

