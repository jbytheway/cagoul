#ifndef CAGOUL__SHADEMODEL_HPP
#define CAGOUL__SHADEMODEL_HPP

#include <cagoul/getter_setter_toggler.hpp>
#include <cagoul/enums/shademodel.hpp>

namespace cagoul {

static const getter_setter_toggler<
  enums::ShadeModel, 1,
  glShadeModel,
  GL_SHADE_MODEL
> ShadeModel;

}

#endif // CAGOUL__SHADEMODEL_HPP

