#ifndef CAGOUL_ENUMS__TEXIMAGE_DFORMAT_HPP
#define CAGOUL_ENUMS__TEXIMAGE_DFORMAT_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_TEXIMAGE2DFORMAT_VALUES \
  (COLOR_INDEX) \
  (RED) \
  (GREEN) \
  (BLUE) \
  (ALPHA) \
  (RGB) \
  (BGR) \
  (RGBA) \
  (BGRA) \
  (LUMINANCE) \
  (LUMINANCE_ALPHA)

/** \brief Scoped enumeration of potential arguments to the format argument of
 * glTexImage2D / cagoul::TexImage2D. */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(
  TexImage2DFormat, CAGOUL_ENUMS_TEXIMAGE2DFORMAT_VALUES
)

}}

#endif // CAGOUL_ENUMS__TEXIMAGE_DFORMAT_HPP

