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

#ifndef __CC_MATH_MAT4__
#define	__CC_MATH_MAT4__

#include "Vec4.hpp"

namespace cc {
  namespace math {
    template<typename T>
    class Mat4 {
    public:
      inline Mat4<T>();
      inline Mat4<T>( const T& val );
      inline Mat4<T>( const T& x0, const T& y0, const T& z0, const T& w0,
                      const T& x1, const T& y1, const T& z1, const T& w1,
                      const T& x2, const T& y2, const T& z2, const T& w2,
                      const T& x3, const T& y3, const T& z3, const T& w3 );
      inline Mat4<T>( const Mat4<T>& val );

      // Accessors.
      inline Vec4<T>&       operator[]( unsigned int index );
      inline const Vec4<T>& operator[]( unsigned int index ) const;
      inline T&             operator()( unsigned int row, unsigned int column );
      inline const T&       operator()( unsigned int row, unsigned int column ) const;

      // Unary arithmetic operators.
      inline Mat4<T>& operator=( const Mat4<T>& val );

      // Binary arithmetic operators.
      // All defined in mat4.inl

    public:
      Vec4<T> data[4];
    };
  } /* math */
  
  // Typedefs.
  typedef cc::math::Mat4<float>        Mat4f;
  typedef cc::math::Mat4<double>       Mat4d;
  typedef cc::math::Mat4<int>          Mat4i;
  typedef cc::math::Mat4<unsigned int> Mat4ui;
  
} /* cc */

#include "Mat4.inl"

#endif	/* __CC_MATH_MAT4__ */

