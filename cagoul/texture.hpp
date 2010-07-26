#ifndef CAGOUL__TEXTURE_HPP
#define CAGOUL__TEXTURE_HPP

#include <cagoul/gluint_wrapper.hpp>
#include <cagoul/enums/bindtexturetarget.hpp>

namespace cagoul {

/** \brief RAII wrapper round GLuint representing a texture.
 *
 * A cagoul::texture stores a GLuint which is made a texture using
 * glGenTextures at construction time, and deleted using glDeleteTextures at
 * destruction time.
 */
class texture : public GLuint_wrapper {
  public:
    /** \brief Constructs a texture which will be bound to the given \c target.
     *
     * The texture will be created with glGenTextures.  The \c target argument
     * will be stored for later use in calls to Bind().
     */
    texture(enums::BindTextureTarget target) :
      target_(target)
    {
      glGenTextures(1, &value_);
    }
    ~texture() {
      glDeleteTextures(1, &value_);
    }

    /** \brief Bind this texture using glBindTexture. */
    void Bind() const {
      glBindTexture(target_, value_);
    }
  private:
    texture(texture const&);
    texture& operator=(texture const&);

    enums::BindTextureTarget target_;
};

}

#endif // CAGOUL__TEXTURE_HPP

