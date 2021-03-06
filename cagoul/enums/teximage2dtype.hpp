#ifndef CAGOUL_ENUMS__TEXIMAGE_DTYPE_HPP
#define CAGOUL_ENUMS__TEXIMAGE_DTYPE_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

namespace cagoul { namespace enums {

#define CAGOUL_ENUMS_TEXIMAGE2DTYPE_VALUES \
  (UNSIGNED_BYTE) \
  (BYTE) \
  (BITMAP) \
  (UNSIGNED_SHORT) \
  (SHORT) \
  (UNSIGNED_INT) \
  (INT) \
  (FLOAT) \
  (UNSIGNED_BYTE_3_3_2) \
  (UNSIGNED_BYTE_2_3_3_REV) \
  (UNSIGNED_SHORT_5_6_5) \
  (UNSIGNED_SHORT_5_6_5_REV) \
  (UNSIGNED_SHORT_4_4_4_4) \
  (UNSIGNED_SHORT_4_4_4_4_REV) \
  (UNSIGNED_SHORT_5_5_5_1) \
  (UNSIGNED_SHORT_1_5_5_5_REV) \
  (UNSIGNED_INT_8_8_8_8) \
  (UNSIGNED_INT_8_8_8_8_REV) \
  (UNSIGNED_INT_10_10_10_2) \
  (UNSIGNED_INT_2_10_10_10_REV)

/** \brief Scoped enumeration of potential arguments to the type argument of
 * glTexImage2D / cagoul::TexImage2D. */
CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(
  TexImage2DType, CAGOUL_ENUMS_TEXIMAGE2DTYPE_VALUES
)

}}

#endif // CAGOUL_ENUMS__TEXIMAGE_DTYPE_HPP

