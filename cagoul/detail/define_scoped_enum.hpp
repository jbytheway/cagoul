#ifndef CAGOUL_DETAIL__DEFINE_SCOPED_ENUM_HPP
#define CAGOUL_DETAIL__DEFINE_SCOPED_ENUM_HPP

#include <boost/preprocessor/seq/for_each.hpp>

#include <GL/gl.h>

#include <cagoul/enums/is_scoped_enum.hpp>

#define CAGOUL_DETAIL_DEFINE_SCOPED_ENUM_VALUE(r, d, value) \
  value = BOOST_PP_CAT(GL_,value),

#define CAGOUL_DETAIL_DEFINE_SCOPED_ENUM(name, value_seq) \
  struct name##_values {                               \
    enum internal_enum {                               \
      BOOST_PP_SEQ_FOR_EACH(                           \
        CAGOUL_DETAIL_DEFINE_SCOPED_ENUM_VALUE, _, value_seq \
      )                                                \
    };                                                 \
  };                                                   \
                                                       \
  class name : public name##_values {                  \
    public:                                            \
      typedef name##_values values;                    \
      name() {}                                        \
      name(internal_enum const v) : value_(v) {}       \
      operator internal_enum() const { return value_; } \
    private:                                           \
      internal_enum value_;                            \
  };                                                   \
                                                       \
  template<>                                           \
  struct is_scoped_enum<name> : boost::mpl::true_      \
  {};

#endif // CAGOUL_DETAIL__DEFINE_SCOPED_ENUM_HPP

