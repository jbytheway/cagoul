#ifndef CAGOUL_ENUMS__SHADEMODEL_HPP
#define CAGOUL_ENUMS__SHADEMODEL_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_SHADEMODEL_VALUES \
  (FLAT)   \
  (SMOOTH)

/** \brief Scoped enumeration of potential glShadeModel / cagoul::ShadeModel
 * arguments. */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(ShadeModel, CAGOUL_ENUMS_SHADEMODEL_VALUES)

}}

#endif // CAGOUL_ENUMS__SHADEMODEL_HPP

