#ifndef CAGOUL_DETAIL__DEFINE_BITFIELD_HPP
#define CAGOUL_DETAIL__DEFINE_BITFIELD_HPP

#include <cagoul/detail/define_scoped_enum.hpp>

#define CAGOUL_DETAIL_DEFINE_BITFIELD(name, value_seq) \
  CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(name, value_seq)    \
                                                       \
  inline name                                          \
  operator|(name::internal_enum const l, name::internal_enum const r) { \
    return name::from_GLenum(GLenum(l) | GLenum(r));   \
  }

#endif // CAGOUL_DETAIL__DEFINE_BITFIELD_HPP

