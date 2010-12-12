#ifndef CAGOUL_SCOPED__BINDTEXTURE_HPP
#define CAGOUL_SCOPED__BINDTEXTURE_HPP

#include <cagoul/texture.hpp>

namespace cagoul { namespace scoped {

/** \brief Class which temporarily binds a texture, and then resets to the
 * previous binding.
 */
class BindTexture {
  public:
    /** \brief Bind the given texture while this instance is in scope.
     */
    BindTexture(cagoul::texture const&);
    ~BindTexture();
  private:
    enums::BindTextureTarget target_;
    GLuint old_texture_;
};

}}

#endif // CAGOUL_SCOPED__BINDTEXTURE_HPP

