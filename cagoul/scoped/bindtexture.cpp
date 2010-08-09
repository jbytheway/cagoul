#include <cagoul/scoped/bindtexture.hpp>

#include <cagoul/fatal.hpp>
#include <cagoul/get.hpp>

namespace cagoul { namespace scoped {

BindTexture::BindTexture(cagoul::texture const& tex) :
  target_(tex.target())
{
  switch (target_) {
    case enums::BindTextureTarget::TEXTURE_1D:
      Get(GL_TEXTURE_BINDING_1D, &old_texture_);
      break;
    case enums::BindTextureTarget::TEXTURE_2D:
      Get(GL_TEXTURE_BINDING_2D, &old_texture_);
      break;
    case enums::BindTextureTarget::TEXTURE_3D:
      Get(GL_TEXTURE_BINDING_3D, &old_texture_);
      break;
    default:
      CAGOUL_FATAL("unexpected BindTextureTarget");
  }
  tex.Bind();
}

BindTexture::~BindTexture()
{
  glBindTexture(target_, old_texture_);
}

}}

