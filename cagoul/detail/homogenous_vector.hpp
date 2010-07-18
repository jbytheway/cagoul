#ifndef CAGOUL_DETAIL__HOMOGENOUS_VECTOR_HPP
#define CAGOUL_DETAIL__HOMOGENOUS_VECTOR_HPP

#include <boost/fusion/include/as_vector.hpp>
#include <boost/fusion/include/mpl.hpp>

#include <cagoul/detail/homogenous_sequence.hpp>

namespace cagoul { namespace detail {

/** \internal \brief Metafunction returning a \c boost::fusion::vector of \c
 * Size copies of \c T.
 */
template<typename T, arity_type Size>
struct homogenous_vector {
  /** \internal */
  typedef typename boost::fusion::result_of::as_vector<
    typename homogenous_sequence<T, Size>::type
  >::type type;
};

}}

#endif // CAGOUL_DETAIL__HOMOGENOUS_VECTOR_HPP

