#ifndef CAGOUL_ENUMS__CLEAR_HPP
#define CAGOUL_ENUMS__CLEAR_HPP

#include <cagoul/detail/define_bitfield.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_CLEAR_VALUES \
  (COLOR_BUFFER_BIT)   \
  (DEPTH_BUFFER_BIT)   \
  (ACCUM_BUFFER_BIT)   \
  (STENCIL_BUFFER_BIT)

CAGOUL_DETAIL_DEFINE_BITFIELD(Clear, CAGOUL_ENUMS_CLEAR_VALUES)

}}

#endif // CAGOUL_ENUMS__CLEAR_HPP

