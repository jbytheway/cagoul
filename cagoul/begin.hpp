#if (!defined(BOOST_PP_IS_ITERATING) || !BOOST_PP_IS_ITERATING) && \
  !defined(CAGOUL_BEGIN_MEMBER_NAME)

#ifndef CAGOUL__BEGIN_HPP
#define CAGOUL__BEGIN_HPP

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>

#include <cagoul/enums/begin.hpp>
#include <cagoul/type_from_tag.hpp>

namespace cagoul {

/** \brief cagoul wrapper around glBegin()/glEnd() constructs.
 *
 * cagoul::Begin provides a slightly safer interface to implement
 * glBegin()/glEnd() constructs.  An instance of cagoul::Begin calls glBegin()
 * in its constructor, passing through the mode provided, and glEnd() in its
 * destructor.  The valid enumeration values for the mode are pulled into the
 * scope of cagoul::Begin, so they can be accessed as cagoul::Begin::POLYGON,
 * etc.
 *
 * Member functions are provided for the commonly called functions
 * between a glBegin() and its corresponding glEnd().  Each such member
 * function returns a reference to the same cagoul::Begin object so that they
 * can be chained.  In line with Cagoul's
 * \ref overloadedwrappers "overloading philosophy" the
 * member functions borrow their names from the corresponding GL functions,
 * losing the arity indicator, but usually not the type indicator.
 *
 * Thus, code such as
 *
 * \code
 * glBegin(GL_POLYGON);
 *   glVertex3f(0.0f, 1.0f, 0.0f);
 *   glVertex3f(1.0f, -1.0f, 0.0f);
 *   glVertex3f(-1.0f, -1.0f, 0.0f);
 * glEnd();
 * \endcode
 *
 * becomes
 *
 * \code
 * cagoul::Begin(cagoul::Begin::POLYGON)
 *   .Vertexf(0.0f, 1.0f, 0.0f)
 *   .Vertexf(1.0f, -1.0f, 0.0f)
 *   .Vertexf(-1.0f, -1.0f, 0.0f)
 *   ;
 * \endcode
 *
 * The aim of this interface is to make it difficult to call a GL function
 * in a glBegin()/glEnd() pair when it should not be, and vice versa.
 *
 * Nevertheless, this might cause problems if you need to call a GL function
 * for which cagoul::Begin does not provide a corresponding member.  In this
 * case you have at least two options.
 *
 * Firstly, you can give a name to the cagoul::Begin instance and have glEnd be
 * called when it goes out of scope; for example
 *
 * \code
 * {
 *   cagoul::Begin scope(cagoul::Begin::POLYGON)
 *   glVertex3f(0.0f, 1.0f, 0.0f);
 *   glVertex3f(1.0f, -1.0f, 0.0f);
 *   glVertex3f(-1.0f, -1.0f, 0.0f);
 * }
 * \endcode
 *
 * Secondly, you can use the general \c call member function, to which you pass
 * a function object.  For example, a perverse implementation of the above code
 * would be
 *
 * \code
 * cagoul::Begin(cagoul::Begin::POLYGON)
 *   .call(boost::bind(glVertex3f, 0.0f, 1.0f, 0.0f))
 *   .call(boost::bind(glVertex3f, 1.0f, -1.0f, 0.0f))
 *   .call(boost::bind(glVertex3f, -1.0f, -1.0f, 0.0f))
 *   ;
 * \endcode
 */
class Begin : public enums::Begin::values {
  public:
    /** \brief Calls <tt>glBegin(mode)</tt>
     *
     * <tt>glEnd()</tt> will be called by the destructor.
     */
    Begin(enums::Begin const mode) { glBegin(mode); }
    ~Begin() { glEnd(); }

#ifndef DOXYGEN

#define CAGOUL_BEGIN_MEMBER_NAME Vertex
#define CAGOUL_BEGIN_MEMBER_TYPE_SEQ (s)(i)(f)(d)
#define CAGOUL_BEGIN_MEMBER_ARITY_SEQ (2)(3)(4)
#include <cagoul/begin.hpp>

#define CAGOUL_BEGIN_MEMBER_NAME Color
#define CAGOUL_BEGIN_MEMBER_TYPE_SEQ (b)(s)(i)(f)(d)(ub)(us)(ui)
#define CAGOUL_BEGIN_MEMBER_ARITY_SEQ (3)(4)
#include <cagoul/begin.hpp>

#define CAGOUL_BEGIN_MEMBER_NAME TexCoord
#define CAGOUL_BEGIN_MEMBER_TYPE_SEQ (s)(i)(f)(d)
#define CAGOUL_BEGIN_MEMBER_ARITY_SEQ (1)(2)(3)(4)
#include <cagoul/begin.hpp>

#endif // DOXYGEN

    /** \brief Calls the given NullaryFunction \c f. */
    template<typename NullaryFunction>
    Begin& call(NullaryFunction const& f) {
      f();
      return *this;
    }
  private:
    Begin(Begin const&);
    Begin& operator=(Begin const&);
};

}

#endif // CAGOUL__BEGIN_HPP

#elif (!defined(BOOST_PP_IS_ITERATING) || !BOOST_PP_IS_ITERATING) && \
  defined(CAGOUL_BEGIN_MEMBER_NAME)

// In this branch we need to generate all the overloads for a particular name;
// first we iterate over arities
#define BOOST_PP_ITERATION_PARAMS_1 \
  (3, (0, BOOST_PP_SUB(BOOST_PP_SEQ_SIZE(CAGOUL_BEGIN_MEMBER_ARITY_SEQ), 1), \
       "cagoul/begin.hpp"))
#include BOOST_PP_ITERATE()
#undef CAGOUL_BEGIN_MEMBER_NAME
#undef CAGOUL_BEGIN_MEMBER_TYPE_SEQ
#undef CAGOUL_BEGIN_MEMBER_ARITY_SEQ

#elif BOOST_PP_ITERATION_DEPTH() == 1

// Next we iterate over types
#define BOOST_PP_ITERATION_PARAMS_2 \
  (3, (0, BOOST_PP_SUB(BOOST_PP_SEQ_SIZE(CAGOUL_BEGIN_MEMBER_TYPE_SEQ), 1), \
       "cagoul/begin.hpp"))

#include BOOST_PP_ITERATE()

#elif BOOST_PP_ITERATION_DEPTH() == 2

// Finally we actually define the function
#define CAGOUL_BEGIN_ARITY \
  BOOST_PP_SEQ_ELEM(BOOST_PP_ITERATION_1, CAGOUL_BEGIN_MEMBER_ARITY_SEQ)
#define CAGOUL_BEGIN_TYPE \
  BOOST_PP_SEQ_ELEM(BOOST_PP_ITERATION_2, CAGOUL_BEGIN_MEMBER_TYPE_SEQ)

    Begin& BOOST_PP_CAT(CAGOUL_BEGIN_MEMBER_NAME, CAGOUL_BEGIN_TYPE)( \
      BOOST_PP_ENUM_PARAMS( \
        CAGOUL_BEGIN_ARITY, type_from_tag::CAGOUL_BEGIN_TYPE const x \
      ) \
    ) { \
      BOOST_PP_CAT(BOOST_PP_CAT(gl,CAGOUL_BEGIN_MEMBER_NAME), \
        BOOST_PP_CAT(CAGOUL_BEGIN_ARITY,CAGOUL_BEGIN_TYPE))( \
          BOOST_PP_ENUM_PARAMS(CAGOUL_BEGIN_ARITY, x) \
        ); \
      return *this; \
    }

#undef CAGOUL_BEGIN_ARITY
#undef CAGOUL_BEGIN_TYPE

#else

#error unexpected iteration depth

#endif // Iteration

