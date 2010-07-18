#ifndef CAGOUL__GET_HPP
#define CAGOUL__GET_HPP

namespace cagoul {

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

}

#endif // CAGOUL__GET_HPP

