#ifndef CAGOUL_DETAIL__HOMOGENOUS_FUNCTION_HPP
#define CAGOUL_DETAIL__HOMOGENOUS_FUNCTION_HPP

#include <boost/function_types/function_type.hpp>

#include <cagoul/detail/homogenous_sequence.hpp>

namespace cagoul { namespace detail {

template<typename T, arity_type Arity, typename ReturnType = void>
struct homogenous_function {
  typedef typename boost::function_types::function_type<
    typename boost::mpl::push_front<
      typename homogenous_sequence<T, Arity>::type,
      ReturnType
    >::type
  >::type type;
};

BOOST_MPL_ASSERT((boost::is_same<void(), homogenous_function<int, 0>::type>));

}}

#endif // CAGOUL_DETAIL__HOMOGENOUS_FUNCTION_HPP

