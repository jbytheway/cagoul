#ifndef CAGOUL_SCOPED__MATRIXMODE_HPP
#define CAGOUL_SCOPED__MATRIXMODE_HPP

#include <cagoul/matrixmode.hpp>

namespace cagoul { namespace scoped {

/** \brief Class which changes the GL matrix mode temporarily.
 *
 * While an instance of this class is in scope the matrix mode is changed; when
 * it goes out of scope the mode is reset to its previous value.
 */
class MatrixMode {
  public:
    /** \brief Store old matrix mode and change it to \c new_mode.
     *
     * The old mode will be resumed when the destructor is called.
     */
    MatrixMode(enums::MatrixMode const new_mode) :
      old_mode_(cagoul::MatrixMode())
    {
      cagoul::MatrixMode(new_mode);
    }

    ~MatrixMode() {
      cagoul::MatrixMode(old_mode_);
    }
  private:
    MatrixMode(MatrixMode const&);
    MatrixMode& operator=(MatrixMode const&);
    enums::MatrixMode old_mode_;
};

}}

#endif // CAGOUL_SCOPED__MATRIXMODE_HPP

