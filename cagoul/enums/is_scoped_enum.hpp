#ifndef CAGOUL_ENUMS__IS_SCOPED_ENUM_HPP
#define CAGOUL_ENUMS__IS_SCOPED_ENUM_HPP

#include <boost/mpl/bool.hpp>

namespace cagoul { namespace enums {

/** \brief Boolean metafunction indicating whether \c T is a Cagoul scoped
 * enum. */
template<typename T>
struct is_scoped_enum : boost::mpl::false_
{};

}}

#endif // CAGOUL_ENUMS__IS_SCOPED_ENUM_HPP

