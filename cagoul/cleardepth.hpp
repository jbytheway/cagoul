#ifndef CAGOUL__CLEARDEPTH_HPP
#define CAGOUL__CLEARDEPTH_HPP

#include <cagoul/getter_setter.hpp>

namespace cagoul {

static const getter_setter<
  double, 1,
  glClearDepth,
  GL_DEPTH_CLEAR_VALUE
> ClearDepth;

}

#endif // CAGOUL__CLEARDEPTH_HPP

