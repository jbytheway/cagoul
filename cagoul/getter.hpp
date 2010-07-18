#ifndef CAGOUL__GETTER_HPP
#define CAGOUL__GETTER_HPP

#include <boost/fusion/include/at_c.hpp>

#include <cagoul/arity_type.hpp>
#include <cagoul/detail/homogenous_vector.hpp>
#include <cagoul/get.hpp>

namespace cagoul {

/** \brief Provides a higher-level wrapper round glGet than cagoul::Get.
 *
 * An instance \c f of getter will be a function object such that \c f()
 * will return the values obtained through a call to cagoul::Get with first
 * parameter \c SymbolicConstant.  \c Arity specifies how many values are
 * fetched from cagoul::Get.
 */
template<
  typename T,
  arity_type Arity,
  GLenum SymbolicConstant
>
class getter {
  BOOST_MPL_ASSERT_RELATION(Arity,>,0);
  public:
    /** Return type of \c operator()() */
    typedef typename detail::homogenous_vector<T, Arity>::type vector;
    // Ensure that there's no padding in the results vector
    BOOST_MPL_ASSERT_RELATION(sizeof(vector),==,Arity*sizeof(T));

    /** \brief Returns values obtained via
     * <tt>cogoul::Get(SymbolicConstant,...)</tt>.
     *
     * When \c Arity is 1 returns a single value of type T, otherwise returns a
     * <tt>boost::fusion::vector<T,...></tt> with \c Arity entries.  In the
     * latter case the return type is exposed as \c getter::vector.
     */
    vector operator()() const {
      vector result;
      Get(SymbolicConstant, &boost::fusion::at_c<0>(result));
      return result;
    }
};

#ifndef DOXYGEN
template<
  typename T,
  GLenum SymbolicConstant
>
class getter<T, 1, SymbolicConstant> {
  public:
    T operator()() const {
      T result;
      Get(SymbolicConstant, &result);
      return result;
    }
};
#endif // DOXYGEN

}

#endif // CAGOUL__GETTER_HPP

