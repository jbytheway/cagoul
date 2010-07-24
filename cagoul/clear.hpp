#ifndef CAGOUL__CLEAR_HPP
#define CAGOUL__CLEAR_HPP

#include <cagoul/enums/clear.hpp>

namespace cagoul {

namespace detail {

/** \internal */
struct Clear_type : enums::Clear::values {
  Clear_type() {}

  /** \brief Calls glClear(mask) */
  void operator()(enums::Clear const mask) const {
    glClear(mask);
  }
};

}

static const detail::Clear_type Clear;

}

#endif // CAGOUL__CLEAR_HPP

