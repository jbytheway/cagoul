#ifndef CAGOUL_DETAIL__HOMOGENOUS_SEQUENCE_HPP
#define CAGOUL_DETAIL__HOMOGENOUS_SEQUENCE_HPP

#include <boost/mpl/transform.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/vector.hpp>

namespace cagoul { namespace detail {

template<typename T, arity_type Arity>
struct homogenous_sequence {
  typedef typename boost::mpl::transform<
    boost::mpl::range_c<arity_type, 0, Arity>,
    boost::mpl::always<T>,
    boost::mpl::back_inserter<boost::mpl::vector0<> >
  >::type type;
};

}}

#endif // CAGOUL_DETAIL__HOMOGENOUS_SEQUENCE_HPP

