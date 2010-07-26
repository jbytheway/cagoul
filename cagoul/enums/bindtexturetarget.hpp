#ifndef CAGOUL_ENUMS__BINDTEXTURETARGET_HPP
#define CAGOUL_ENUMS__BINDTEXTURETARGET_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_BINDTEXTURETARGET_VALUES \
  (TEXTURE_1D) \
  (TEXTURE_2D) \
  (TEXTURE_3D) \
  (TEXTURE_CUBE_MAP)

/** \brief Scoped enumeration of potential arguments to the target argument of
 * glBindTexture. */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(
  BindTextureTarget, CAGOUL_ENUMS_BINDTEXTURETARGET_VALUES
)

}}

#endif // CAGOUL_ENUMS__BINDTEXTURETARGET_HPP

