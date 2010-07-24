#ifndef CAGOUL_ENUMS__BEGIN_HPP
#define CAGOUL_ENUMS__BEGIN_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_BEGIN_VALUES \
  (POINTS)         \
  (LINES)          \
  (LINE_STRIP)     \
  (LINE_LOOP)      \
  (TRIANGLES)      \
  (TRIANGLE_STRIP) \
  (TRIANGLE_FAN)   \
  (QUADS)          \
  (QUAD_STRIP)     \
  (POLYGON)

/** \brief Scoped enumeration of potential glBegin / cagoul::Begin arguments.
 */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(Begin, CAGOUL_ENUMS_BEGIN_VALUES)

}}

#endif // CAGOUL_ENUMS__BEGIN_HPP

