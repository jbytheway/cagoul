#ifndef CAGOUL_ENUMS__TEXIMAGE_DTARGET_HPP
#define CAGOUL_ENUMS__TEXIMAGE_DTARGET_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_TEXIMAGE2DTARGET_VALUES \
  (TEXTURE_2D) \
  (PROXY_TEXTURE_2D) \
  (TEXTURE_CUBE_MAP_POSITIVE_X) \
  (TEXTURE_CUBE_MAP_NEGATIVE_X) \
  (TEXTURE_CUBE_MAP_POSITIVE_Y) \
  (TEXTURE_CUBE_MAP_NEGATIVE_Y) \
  (TEXTURE_CUBE_MAP_POSITIVE_Z) \
  (TEXTURE_CUBE_MAP_NEGATIVE_Z) \
  (PROXY_TEXTURE_CUBE_MAP)

/** \brief Scoped enumeration of potential arguments to the target argument of
 * glTexImage2D / cagoul::TexImage2D. */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(
  TexImage2DTarget, CAGOUL_ENUMS_TEXIMAGE2DTARGET_VALUES
)

}}

#endif // CAGOUL_ENUMS__TEXIMAGE_DTARGET_HPP

