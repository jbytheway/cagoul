#ifndef CAGOUL__TEXTURE_HPP
#define CAGOUL__TEXTURE_HPP

#include <cagoul/gluint_wrapper.hpp>
#include <cagoul/enums/bindtexturetarget.hpp>

namespace cagoul {

class texture : public GLuint_wrapper {
  public:
    texture(enums::BindTextureTarget target) :
      target_(target)
    {
      glGenTextures(1, &value_);
    }
    ~texture() {
      glDeleteTextures(1, &value_);
    }

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

