#ifndef CAGOUL__SETTER_HPP
#define CAGOUL__SETTER_HPP

#include <cagoul/detail/homogenous_function.hpp>

namespace cagoul {

/** \brief A thin function object wrapper around the function \c Setter.
 *
 * An instance \c f of \c setter will be callable in the same way the function
 * \c Setter is.  \c Setter must be a function with \c Arity arguments all of
 * type \c T, and returning void.  This functionality in itself is not very
 * useful, but it is used in getter_setter to bring together access and
 * assignment to a GL value in one place.
 */
template<
  typename T,
  arity_type Arity,
  typename detail::homogenous_function<T, Arity>::type* Setter
>
class setter
#ifdef DOXYGEN
{}
#endif
;

#ifndef DOXYGEN
template<
  typename T,
  typename detail::homogenous_function<T, 4>::type* Setter
>
class setter<T, 4, Setter> {
  public:
    void operator()(T const t0, T const t1, T const t2, T const t3) const {
      Setter(t0, t1, t2, t3);
    }
};
#endif // DOXYGEN

}

#endif // CAGOUL__SETTER_HPP

