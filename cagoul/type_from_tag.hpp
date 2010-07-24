#ifndef CAGOUL__TYPE_FROM_TAG_HPP
#define CAGOUL__TYPE_FROM_TAG_HPP

#include <GL/gl.h>

namespace cagoul {

/** \brief Converts GL type tags into types.
 *
 * For each GL one or two letter abbreviation of a type, type_from_tag provides
 * a member typedef defining it as its corresponding real type.
 *
 * This is intended to facilitate preprocessor metaprogramming which forwards
 * calls to GL functions.
 */
class type_from_tag {
  public:
    //@{
    /** \brief Member typedef to convert short name into real types. */
    typedef GLbyte b;
    typedef GLshort s;
    typedef GLint i;
    typedef GLfloat f;
    typedef GLdouble d;
    typedef GLubyte ub;
    typedef GLushort us;
    typedef GLuint ui;
    //@}
  private:
    type_from_tag();
    type_from_tag(type_from_tag const&);
    type_from_tag& operator=(type_from_tag const&);
    ~type_from_tag();
};

}

#endif // CAGOUL__TYPE_FROM_TAG_HPP

