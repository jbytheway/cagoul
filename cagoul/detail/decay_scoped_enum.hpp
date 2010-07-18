#ifndef CAGOUL_DETAIL__DECAY_SCOPED_ENUM_HPP
#define CAGOUL_DETAIL__DECAY_SCOPED_ENUM_HPP

#include <cagoul/enums/is_scoped_enum.hpp>

namespace cagoul { namespace detail {

/** \internal \brief Metafunction returning GLenum if T is a scoped enum, T
 * otherwise. */
template<typename T>
struct decay_scoped_enum :
  boost::mpl::if_<enums::is_scoped_enum<T>, GLenum, T>
{};

}}

#endif // CAGOUL_DETAIL__DECAY_SCOPED_ENUM_HPP

