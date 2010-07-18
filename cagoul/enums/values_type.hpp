#ifndef CAGOUL_ENUMS__VALUES_TYPE_HPP
#define CAGOUL_ENUMS__VALUES_TYPE_HPP

#include <boost/utility/enable_if.hpp>

#include <cagoul/detail/braces_if_doxygen.hpp>

namespace cagoul { namespace enums {

/** \brief From a scoped enumeration extracts a type defining its possible
 * values.
 *
 * If T is a scoped enumeration then this metafunction returns a type which has
 * all its valid values in scope.  By inheriting from this type you can bring
 * all the valid vcalues into the scope of your class.  This is used in
 * cagoul::getter_setter, for example.  The type is empty, so if your compiler
 * implements the empty base optimization then there should be no runtime
 * penalty for this inheritance (unless you are inheriting multiply).
 *
 * If T is not a scoped enumeration then it returns void.
 */
template<typename T, typename Enabler = void>
struct values_type CAGOUL_DETAIL_BRACES_IF_DOXYGEN;

#ifndef DOXYGEN
template<typename T>
struct values_type<T, typename boost::enable_if<is_scoped_enum<T> >::type> {
  typedef typename T::values type;
};

template<typename T>
struct values_type<T, typename boost::disable_if<is_scoped_enum<T> >::type> {
  typedef void type;
};
#endif // DOXYGEN

}}

#endif // CAGOUL_ENUMS__VALUES_TYPE_HPP

