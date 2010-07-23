#ifndef CAGOUL__TOGGLER_HPP
#define CAGOUL__TOGGLER_HPP

#include <GL/gl.h>

#include <cagoul/detail/invalid_glenum.hpp>

namespace cagoul {

/** \brief Wrapper round glEnable, glDisable, and glIsEnabled.
 *
 * An instance of toggler provides methods forwarding to glEnable, glDisable,
 * and glIsEnabled, with argument \c SymbolicConstant in each case.
 */
template<GLenum SymbolicConstant>
class toggler {
  public:
    /** \brief Equivalent to <tt>glEnable(SymbolicConstant)</tt>. */
    void Enable() const {
      glEnable(SymbolicConstant);
    }
    /** \brief Equivalent to <tt>glDisable(SymbolicConstant)</tt>. */
    void Disable() const {
      glDisable(SymbolicConstant);
    }
    /** \brief Equivalent to <tt>glIsEnabled(SymbolicConstant)</tt>. */
    GLboolean IsEnabled() const {
      return glIsEnabled(SymbolicConstant);
    }
};

#ifndef DOXYGEN
template<>
class toggler<detail::invalid_GLenum> {
  // No methods defined
};
#endif // DOXYGEN

}

#endif // CAGOUL__TOGGLER_HPP

