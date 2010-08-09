#ifndef CAGOUL__GET_HPP
#define CAGOUL__GET_HPP

#include <boost/mpl/assert.hpp>
#include <boost/utility/enable_if.hpp>

#include <GL/gl.h>

#include <cagoul/enums/is_scoped_enum.hpp>

namespace cagoul {

//@{
/** \brief Overloaded glGet wrapper.
 *
 * The Get functions are simple wrappers round the various versions of glGet
 * using overloading on parameter types to distinguish them, rather than the
 * function name.
 */
inline void Get(GLenum const pname, GLboolean* const params) {
  glGetBooleanv(pname, params);
}

inline void Get(GLenum const pname, GLdouble* const params) {
  glGetDoublev(pname, params);
}

inline void Get(GLenum const pname, GLfloat* const params) {
  glGetFloatv(pname, params);
}

inline void Get(GLenum const pname, GLint* const params) {
  glGetIntegerv(pname, params);
}

inline void Get(GLenum const pname, GLuint* const params) {
  glGetIntegerv(pname, reinterpret_cast<GLint*>(params));
}

/** \brief Fetch enumeration value using glGet.
 *
 * This overload is used when you call Get with a pointer to a scoped enum (as
 * defined in cagoul::enums).  It forwards to the integer overload.
 */
template<typename T>
inline typename boost::enable_if<enums::is_scoped_enum<T> >::type
Get(GLenum const pname, T* const params) {
  // Verify that the representations are binary compatible so we can
  // reinterpret_cast
  BOOST_MPL_ASSERT_RELATION(sizeof(T),==,sizeof(GLint));
  BOOST_MPL_ASSERT_RELATION(sizeof(typename T::internal_enum),==,sizeof(T));
  Get(pname, reinterpret_cast<GLint*>(params));
}
//@}

}

#endif // CAGOUL__GET_HPP

