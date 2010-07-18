#ifndef CAGOUL__DEPTHFUNC_HPP
#define CAGOUL__DEPTHFUNC_HPP

#include <cagoul/enums/depthfunc.hpp>
#include <cagoul/getter_setter.hpp>

namespace cagoul {

static const getter_setter<
  enums::DepthFunc, 1,
  glDepthFunc,
  GL_DEPTH_FUNC
> DepthFunc;

}

#endif // CAGOUL__DEPTHFUNC_HPP

