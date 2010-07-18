#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <cagoul/enums/depthfunc.hpp>

BOOST_AUTO_TEST_CASE(enum_values_match)
{
  BOOST_CHECK_EQUAL(GL_LESS, cagoul::enums::DepthFunc::LESS);
}

