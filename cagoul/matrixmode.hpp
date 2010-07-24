#ifndef CAGOUL__MATRIXMODE_HPP
#define CAGOUL__MATRIXMODE_HPP

#include <cagoul/enums/matrixmode.hpp>
#include <cagoul/getter_setter_toggler.hpp>

namespace cagoul {

static const getter_setter_toggler<
  enums::MatrixMode, 1,
  glMatrixMode,
  GL_MATRIX_MODE
> MatrixMode;

}

#endif // CAGOUL__MATRIXMODE_HPP

