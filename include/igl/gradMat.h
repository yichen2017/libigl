// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_GRAD_MAT_H
#define IGL_GRAD_MAT_H
#include "igl_inline.h"

#include <Eigen/Core>
#include <Eigen/Sparse>

namespace igl {
  // GRAD
  // G = grad(V,F)
  //
  // Compute the numerical gradient operator
  //
  // Inputs:
  //   V  #vertices by 3 list of mesh vertex positions
  //   F  #faces by 3 list of mesh face indices
  // Outputs:
  //   G  #faces*dim by #V Gradient operator
  //
  
  // Gradient of a scalar function defined on piecewise linear elements (mesh)
  // is constant on each triangle i,j,k:
  // grad(Xijk) = (Xj-Xi) * (Vi - Vk)^R90 / 2A + (Xk-Xi) * (Vj - Vi)^R90 / 2A
  // where Xi is the scalar value at vertex i, Vi is the 3D position of vertex
  // i, and A is the area of triangle (i,j,k). ^R90 represent a rotation of 
  // 90 degrees
  //
  template <typename T, typename S>
  IGL_INLINE void gradMat(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &V,
    const Eigen::Matrix<S, Eigen::Dynamic, Eigen::Dynamic> &F,
  Eigen::SparseMatrix<T> &G);
}

#ifndef IGL_STATIC_LIBRARY
#  include "gradMat.cpp"
#endif

#endif
