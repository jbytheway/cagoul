#ifndef CAGOUL_ENUMS__MATRIXMODE_HPP
#define CAGOUL_ENUMS__MATRIXMODE_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_MATRIXMODE_VALUES \
  (MODELVIEW)  \
  (PROJECTION) \
  (TEXTURE)

/** \brief Scoped enumeration of potential glMatrixMode / cagoul::MatrixMode
 * arguments. */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(MatrixMode, CAGOUL_ENUMS_MATRIXMODE_VALUES)

}}

#endif // CAGOUL_ENUMS__MATRIXMODE_HPP

