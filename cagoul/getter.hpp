#ifndef CAGOUL__GETTER_HPP
#define CAGOUL__GETTER_HPP

#include <boost/fusion/include/at_c.hpp>

#include <cagoul/arity_type.hpp>
#include <cagoul/detail/homogenous_vector.hpp>
#include <cagoul/get.hpp>

namespace cagoul {

template<
  typename T,
  arity_type Arity,
  GLenum SymbolicConstant
>
class getter {
  public:
    typedef typename detail::homogenous_vector<T, Arity>::type vector;
    // Ensure that there's no padding in the results vector
    BOOST_MPL_ASSERT_RELATION(sizeof(vector),==,Arity*sizeof(T));
    vector operator()() const {
      vector result;
      Get(SymbolicConstant, &boost::fusion::at_c<0>(result));
      return result;
    }
};

}

#endif // CAGOUL__GETTER_HPP

