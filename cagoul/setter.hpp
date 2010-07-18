#ifndef CAGOUL__SETTER_HPP
#define CAGOUL__SETTER_HPP

#include <cagoul/detail/homogenous_function.hpp>

namespace cagoul {

template<
  typename T,
  arity_type Arity,
  typename detail::homogenous_function<T, Arity>::type* Setter
>
class setter;

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

}

#endif // CAGOUL__SETTER_HPP

