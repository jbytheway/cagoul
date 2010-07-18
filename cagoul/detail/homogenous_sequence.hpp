#ifndef CAGOUL_DETAIL__HOMOGENOUS_SEQUENCE_HPP
#define CAGOUL_DETAIL__HOMOGENOUS_SEQUENCE_HPP

#include <boost/mpl/transform.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/vector.hpp>

namespace cagoul { namespace detail {

/** \internal \brief Metafunction returning an MPL sequence of \c Size copies
 * of \c T */
template<typename T, arity_type Size>
struct homogenous_sequence {
  /** \internal */
  typedef typename boost::mpl::transform<
    boost::mpl::range_c<arity_type, 0, Size>,
    boost::mpl::always<T>,
    boost::mpl::back_inserter<boost::mpl::vector0<> >
  >::type type;
};

}}

#endif // CAGOUL_DETAIL__HOMOGENOUS_SEQUENCE_HPP

