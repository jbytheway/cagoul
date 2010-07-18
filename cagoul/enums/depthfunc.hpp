#ifndef CAGOUL_ENUMS__DEPTHFUNC_HPP
#define CAGOUL_ENUMS__DEPTHFUNC_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_DEPTHFUNC_VALUES \
  (NEVER)    \
  (LESS)     \
  (EQUAL)    \
  (LEQUAL)   \
  (GREATER)  \
  (NOTEQUAL) \
  (GEQUAL)   \
  (ALWAYS)

CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(DepthFunc, CAGOUL_ENUMS_DEPTHFUNC_VALUES)

}}

#endif // CAGOUL_ENUMS__DEPTHFUNC_HPP

