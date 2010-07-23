#ifndef CAGOUL_DETAIL__INVALID_GLENUM_HPP
#define CAGOUL_DETAIL__INVALID_GLENUM_HPP

#include <boost/integer_traits.hpp>

namespace cagoul { namespace detail {

static const GLenum invalid_GLenum = boost::integer_traits<GLenum>::const_min;

}}

#endif // CAGOUL_DETAIL__INVALID_GLENUM_HPP

