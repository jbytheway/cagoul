#include <cagoul/fatal.hpp>

#include <iostream>

namespace cagoul {

/** \internal \brief Stream for printing errors to (c.f. CAGOUL_FATAL) */
std::ostream& error_stream = std::cerr;

}

