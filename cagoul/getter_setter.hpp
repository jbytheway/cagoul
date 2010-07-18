#ifndef CAGOUL__GETTER_SETTER_HPP
#define CAGOUL__GETTER_SETTER_HPP

#include <cagoul/getter.hpp>
#include <cagoul/setter.hpp>

namespace cagoul {

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

