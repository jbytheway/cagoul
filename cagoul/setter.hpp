#if !defined(BOOST_PP_IS_ITERATING) || !BOOST_PP_IS_ITERATING

#ifndef CAGOUL__SETTER_HPP
#define CAGOUL__SETTER_HPP

#include <boost/preprocessor/iterate.hpp>
#include <boost/preprocessor/enum_params.hpp>

#include <cagoul/detail/homogenous_function.hpp>
#include <cagoul/detail/braces_if_doxygen.hpp>
#include <cagoul/detail/decay_scoped_enum.hpp>

namespace cagoul {

/** \brief A thin function object wrapper around the function \c Setter.
 *
 * An instance \c f of \c setter will be callable in the same way the function
 * \c Setter is.  \c Setter must be a function with \c Arity arguments all of
 * type \c T, and returning void.  This functionality in itself is not very
 * useful, but it is used in getter_setter to bring together access and
 * assignment to a GL value in one place.
 *
 * setter is only instantiated for Arity from 1 to 4.
 */
template<
  typename T,
  arity_type Arity,
  typename detail::homogenous_function<
    typename detail::decay_scoped_enum<T>::type, Arity
  >::type* Setter
>
class setter CAGOUL_DETAIL_BRACES_IF_DOXYGEN;

#ifndef DOXYGEN
#define BOOST_PP_ITERATION_PARAMS_1 \
  (3, (1, 4, "cagoul/setter.hpp"))
#include BOOST_PP_ITERATE()
#endif // DOXYGEN

}

#endif // CAGOUL__SETTER_HPP

#else // Here we are iterating

template<
  typename T,
  typename detail::homogenous_function<
    typename detail::decay_scoped_enum<T>::type, BOOST_PP_ITERATION()
  >::type* Setter
>
class setter<T, BOOST_PP_ITERATION(), Setter> {
  public:
    void
    operator()(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), T const t)) const {
      Setter(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), t));
    }
};

#endif // Iteration

