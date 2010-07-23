#ifndef CAGOUL__DEPTHFUNC_HPP
#define CAGOUL__DEPTHFUNC_HPP

#include <cagoul/enums/depthfunc.hpp>
#include <cagoul/getter_setter_toggler.hpp>

namespace cagoul {

static const getter_setter_toggler<
  enums::DepthFunc, 1,
  glDepthFunc,
  GL_DEPTH_FUNC,
  GL_DEPTH_TEST
> DepthFunc;

}

#endif // CAGOUL__DEPTHFUNC_HPP

