#ifndef CAGOUL_DETAIL__HOMOGENOUS_VECTOR_HPP
#define CAGOUL_DETAIL__HOMOGENOUS_VECTOR_HPP

#include <boost/fusion/include/as_vector.hpp>
#include <boost/fusion/include/mpl.hpp>

#include <cagoul/detail/homogenous_sequence.hpp>

namespace cagoul { namespace detail {

template<typename T, arity_type Arity>
struct homogenous_vector {
  typedef typename boost::fusion::result_of::as_vector<
    typename homogenous_sequence<T, Arity>::type
  >::type type;
};

}}

#endif // CAGOUL_DETAIL__HOMOGENOUS_VECTOR_HPP

