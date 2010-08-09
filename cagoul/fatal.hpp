#ifndef CAGOUL__FATAL_HPP
#define CAGOUL__FATAL_HPP

#include <cstdlib>
#include <ostream>

namespace cagoul {

extern std::ostream& error_stream;

}

#define CAGOUL_FATAL(msg) \
  do { \
    cagoul::error_stream << __FILE__ << ":" << __LINE__ << ":" << \
      __PRETTY_FUNCTION__ <<  ": fatal error: " << msg << std::endl; \
    std::abort(); \
  } while(false)

#endif // CAGOUL__FATAL_HPP

