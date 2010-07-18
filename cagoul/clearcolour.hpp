#ifndef CAGOUL__CLEARCOLOUR_HPP
#define CAGOUL__CLEARCOLOUR_HPP

#include <GL/gl.h>

#include <cagoul/getter_setter.hpp>

namespace cagoul {

static const getter_setter<
  GLfloat, 4,
  &glClearColor,
  GL_COLOR_CLEAR_VALUE
> ClearColor;

}

#endif // CAGOUL__CLEARCOLOUR_HPP


