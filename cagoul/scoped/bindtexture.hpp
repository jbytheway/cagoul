#ifndef CAGOUL_SCOPED__BINDTEXTURE_HPP
#define CAGOUL_SCOPED__BINDTEXTURE_HPP

#include <cagoul/texture.hpp>

namespace cagoul { namespace scoped {

class BindTexture {
  public:
    BindTexture(cagoul::texture const& tex);
    ~BindTexture();
  private:
    enums::BindTextureTarget target_;
    GLuint old_texture_;
};

}}

#endif // CAGOUL_SCOPED__BINDTEXTURE_HPP

