#ifndef IGL_ON_BOUNDARY_H
#define IGL_ON_BOUNDARY_H
#include "igl_inline.h"

#ifndef IGL_NO_EIGEN
#  include <Eigen/Dense>
#endif

#include <vector>

namespace igl
{
  // BOUNDARY_FACES Determine boundary faces of tetrahedra stored in T
  //
  // Templates:
  //   IntegerT  integer-value: i.e. int
  //   IntegerF  integer-value: i.e. int
  // Input:
  //  T  tetrahedron index list, m by 4, where m is the number of tetrahedra
  // Output:
  //  I  m long list of bools whether tet is on boundary
  //  C  m by 4 list of bools whether opposite face is on boundary
  //
  template <typename IntegerT>
  IGL_INLINE void on_boundary(
    const std::vector<std::vector<IntegerT> > & T,
    std::vector<bool> & I,
    std::vector<std::vector<bool> > & C);

#ifndef IGL_NO_EIGEN
  // Templates:
  //   DerivedT  integer-value: i.e. from MatrixXi
  //   DerivedI  bool-value: i.e. from MatrixXi
  //   DerivedC  bool-value: i.e. from MatrixXi
  template <typename DerivedT, typename DerivedI, typename DerivedC>
  IGL_INLINE void on_boundary(
    const Eigen::PlainObjectBase<DerivedT>& T,
    Eigen::PlainObjectBase<DerivedI>& I,
    Eigen::PlainObjectBase<DerivedC>& C);
#endif
}

#ifdef IGL_HEADER_ONLY
#  include "on_boundary.cpp"
#endif

#endif

