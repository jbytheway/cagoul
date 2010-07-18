#ifndef CAGOUL__GETTER_SETTER_HPP
#define CAGOUL__GETTER_SETTER_HPP

#include <cagoul/getter.hpp>
#include <cagoul/setter.hpp>

namespace cagoul {

/** \brief Allows a single GL value to be accessed and set through the same
 * interface.
 *
 * An instance of getter_setter combines the interfaces of getter and setter.
 * This brings together the disparate interfaces GL offers to a single concept.
 * For example, cagoul::ClearColor is an instance of getter_setter.  It can be
 * used like
 *
 * \code
 * cagoul::ClearColor(a, b, c, d);
 * \endcode
 *
 * which is equivalent to
 *
 * \code
 * glClearColor(a, b, c, d);
 * \endcode
 *
 * but the same values can be retrieved through the getter interface, thus:
 *
 * \code
 * boost::fusion::vector_tie(a, b, c, d) = cagoul::ClearColor()
 * \endcode
 *
 * which is implemented via
 *
 * \code
 * glGet(GL_COLOR_CLEAR_VALUE, ...)
 * \endcode
 *
 * By combining them in this way we not only reduce the number of things a
 * developer needs to remember (e.g. that glClearColor goes with
 * GL_COLOR_CLEAR_VALUE) but also make it impossible to glGet with the wrong
 * type or arity.
 *
 * Cagoul provides getter_setters wrapping common GL values, such as
 * cagoul::ClearColor, but if you need any others then it is easy to add your
 * own in the same way, simply by defining a global static const variable which
 * is an instance of an appropriate instantiation of getter_setter.  These
 * instances are stateless, so having them as global variables should pose no
 * concurrency issues; indeed they should be entirely optimized away in release
 * builds.
 */
template<
  typename T,
  arity_type Arity,
  typename detail::homogenous_function<T, Arity>::type* Setter,
  GLenum SymbolicConstant
>
class getter_setter :
  public getter<T, Arity, SymbolicConstant>,
  public setter<T, Arity, Setter>
{
  public:
    // Non-default default constructor so that we can const instances
    getter_setter() {}

    using getter<T, Arity, SymbolicConstant>::operator();
    using setter<T, Arity, Setter>::operator();
};

}

#endif // CAGOUL__GETTER_SETTER_HPP
