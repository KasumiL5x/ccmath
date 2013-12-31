/*
  ccmath is a collection of helpful mathematical functions and classes.
  It was developed for use in small, personal projects and should not be
  used as a replacement for more complex mathematical libraries.
  
  Copyright (C) 2013, Daniel Green

  ccmath is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  ccmath is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with ccmath.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @author  Daniel Green
 * @version 1.0.2
 *
 * 2013-11-15 13:57
 *  - Initial version.
 */

#include <iostream>
#include <cassert>

namespace cc {
  namespace math {
    template<typename T>
    inline Mat4<T>::Mat4() {
      const T zero = static_cast<T>(0);
      const T one  = static_cast<T>(1);
      data[0] = Vec4<T>(one, zero, zero, zero);
      data[1] = Vec4<T>(zero, one, zero, zero);
      data[2] = Vec4<T>(zero, zero, one, zero);
      data[3] = Vec4<T>(zero, zero, zero, one);
    }

    template<typename T>
    inline Mat4<T>::Mat4( const T& val ) {
      const T zero = static_cast<T>(0);
      data[0] = Vec4<T>(val, zero, zero, zero);
      data[1] = Vec4<T>(zero, val, zero, zero);
      data[2] = Vec4<T>(zero, zero, val, zero);
      data[3] = Vec4<T>(zero, zero, zero, val);
    }

    template<typename T>
    inline Mat4<T>::Mat4( const T& x0, const T& y0, const T& z0, const T& w0,
          const T& x1, const T& y1, const T& z1, const T& w1,
          const T& x2, const T& y2, const T& z2, const T& w2,
          const T& x3, const T& y3, const T& z3, const T& w3 ) {
      this->data[0] = Vec4<T>(x0, y0, z0, w0);
      this->data[1] = Vec4<T>(x1, y1, z1, w1);
      this->data[2] = Vec4<T>(x2, y2, z2, w2);
      this->data[3] = Vec4<T>(x3, y3, z3, w3);
    }

    template<typename T>
    inline Mat4<T>::Mat4( const Mat4<T>& val ) {
      this->data[0] = val.data[0];
      this->data[1] = val.data[1];
      this->data[2] = val.data[2];
      this->data[3] = val.data[3];
    }

    // Accessors.
    template<typename T>
    inline Vec4<T>& Mat4<T>::operator[]( unsigned int index ) {
      assert(index < 4);
      return this->data[index];
    }

    template<typename T>
    inline const Vec4<T>& Mat4<T>::operator[]( unsigned int index ) const {
      assert(index < 4);
      return this->data[index];
    }

    template<typename T>
    inline T& Mat4<T>::operator()( unsigned int row, unsigned int column ) {
      assert(row < 4 && column < 4);
      return this->data[row][column];
    }

    template<typename T>
    inline const T& Mat4<T>::operator()( unsigned int row, unsigned int column ) const {
      assert(row < 4 && column < 4);
      return this->data[row][column];
    }

    // Unary arithmetic operators.
    template<typename T>
    inline Mat4<T>& Mat4<T>::operator=( const Mat4<T>& val ) {
      this->data[0] = val.data[0];
      this->data[1] = val.data[1];
      this->data[2] = val.data[2];
      this->data[3] = val.data[3];
      return *this;
    }

    // Binary arithmetic operators.
    template<typename T>
    inline Vec4<T> operator*( const Mat4<T>& lhs, const Vec4<T>& rhs ) {
      return Vec4<T>(lhs[0][0] * rhs.x + lhs[1][0] * rhs.y + lhs[2][0] * rhs.z + lhs[3][0] * rhs.w,
                     lhs[0][1] * rhs.x + lhs[1][1] * rhs.y + lhs[2][1] * rhs.z + lhs[3][1] * rhs.w,
                     lhs[0][2] * rhs.x + lhs[1][2] * rhs.y + lhs[2][2] * rhs.z + lhs[3][2] * rhs.w,
                     lhs[0][3] * rhs.x + lhs[1][3] * rhs.y + lhs[2][3] * rhs.z + lhs[3][3] * rhs.w);
    }

    template<typename T>
    inline Vec4<T> operator*( const Vec4<T>& lhs, const Mat4<T>& rhs ) {
      return Vec4<T>(rhs[0][0] * lhs.x + rhs[0][1] * lhs.y + rhs[0][2] * lhs.z + rhs[0][3] * lhs.w,
                      rhs[1][0] * lhs.x + rhs[1][1] * lhs.y + rhs[1][2] * lhs.z + rhs[1][3] * lhs.w,
                      rhs[2][0] * lhs.x + rhs[2][1] * lhs.y + rhs[2][2] * lhs.z + rhs[2][3] * lhs.w,
                      rhs[3][0] * lhs.x + rhs[3][1] * lhs.y + rhs[3][2] * lhs.z + rhs[3][3] * lhs.w);

    }

    template<typename T>
    inline Mat4<T> operator*( const Mat4<T>& lhs, const Mat4<T>& rhs ) {
      const Vec4<T> srcA0 = lhs[0];
      const Vec4<T> srcA1 = lhs[1];
      const Vec4<T> srcA2 = lhs[2];
      const Vec4<T> srcA3 = lhs[3];

      const Vec4<T> srcB0 = rhs[0];
      const Vec4<T> srcB1 = rhs[1];
      const Vec4<T> srcB2 = rhs[2];
      const Vec4<T> srcB3 = rhs[3];

      Mat4<T> result;
      result[0] = srcA0 * srcB0[0] + srcA1 * srcB0[1] + srcA2 * srcB0[2] + srcA3 * srcB0[3];
		  result[1] = srcA0 * srcB1[0] + srcA1 * srcB1[1] + srcA2 * srcB1[2] + srcA3 * srcB1[3];
		  result[2] = srcA0 * srcB2[0] + srcA1 * srcB2[1] + srcA2 * srcB2[2] + srcA3 * srcB2[3];
		  result[3] = srcA0 * srcB3[0] + srcA1 * srcB3[1] + srcA2 * srcB3[2] + srcA3 * srcB3[3];
      return result;
    }

    template<typename T>
    inline std::ostream& operator<<( std::ostream& os, const Mat4<T>& m ) {
      os << m.data[0] << m.data[1] << m.data[2] << m.data[3];
      return os;
    }
  } /* math */
} /* cc */
