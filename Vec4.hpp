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
 * @version 1.0.0
 *
 * 2013-11-15 13:57
 *  - Initial version.
 */

#ifndef __CC_MATH_VEC4__
#define	__CC_MATH_VEC4__

#include <iostream>
#include <cassert>
#include "Vec3.hpp" // For conversion from and to Vec3.

namespace cc {
  namespace math {
    template<typename T>
    class Vec4 {
    public:
      union {
        struct {
          T x, y, z, w;
        };
        struct {
          T r, g, b, a;
        };
      };

      Vec4<T>()
        : x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0)), w(static_cast<T>(1)) {
      }
      Vec4<T>( const Vec4<T>& rhs )
        : x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {
      }
      Vec4<T>( const T& val )
        : x(val), y(val), z(val), w(val) {
      }
      Vec4<T>( const T& x, const T& y, const T& z )
        : x(x), y(y), z(z), w(static_cast<T>(1)) {
      }
      Vec4<T>( const T& x, const T& y, const T& z, const T& w )
        : x(x), y(y), z(z), w(w) {
      }
      Vec4<T>( const Vec3<T>& rhs )
        : x(rhs.x), y(rhs.y), z(rhs.z), w(static_cast<T>(1)) {
      }
      Vec4<T>( const Vec3<T>& rhs, const T& w )
        : x(rhs.x), y(rhs.y), z(rhs.z), w(w) {
      }
      ~Vec4<T>() {
      }

      T& operator[]( unsigned int index ) {
        assert(index < 4);
        return (&x)[index];
      }
      const T& operator[]( unsigned int index ) const {
        assert(index < 4);
        return (&x)[index];
      }
      T& operator()( unsigned int index ) {
        assert(index < 4);
        return (*this)[index];
      }
      const T& operator()( unsigned int index ) const {
        assert(index < 4);
        return (*this)[index];
      }

      void standardize() {
        x /= w;
        y /= w;
        z /= w;
      }

      Vec4<T> standardized() const {
        return Vec4<T>(x/w, y/w, z/w, w);
      }
      
      Vec3<T> truncated() const {
        return Vec3<T>(x, y, z);
      }

      // Unary arithmetic operators.
      Vec4<T>& operator=( const Vec4<T>& val ) {
        this->x = val.x;
        this->y = val.y;
        this->z = val.z;
        this->w = val.w;
        return *this;
      }
      Vec4<T>& operator+=( const T& val ) {
        this->x += val;
        this->y += val;
        this->z += val;
        this->w += val;
        return *this;
      }
      Vec4<T>& operator+=( const Vec4<T>& val ) {
        this->x += val.x;
        this->y += val.y;
        this->z += val.z;
        this->w += val.w;
        return *this;
      }
      Vec4<T>& operator-=( const T& val ) {
        this->x -= val;
        this->y -= val;
        this->z -= val;
        this->w -= val;
        return *this;
      }
      Vec4<T>& operator-=( const Vec4<T>& val ) {
        this->x -= val.x;
        this->y -= val.y;
        this->z -= val.z;
        this->w -= val.w;
        return *this;
      }
      Vec4<T>& operator*=( const T& val ) {
        this->x *= val;
        this->y *= val;
        this->z *= val;
        this->w *= val;
        return *this;
      }
      Vec4<T>& operator*=( const Vec4<T>& val ) {
        this->x *= val.x;
        this->y *= val.y;
        this->z *= val.z;
        this->w *= val.w;
        return *this;
      }
      Vec4<T>& operator/=( const T& val ) {
        this->x /= val;
        this->y /= val;
        this->z /= val;
        this->w /= val;
        return *this;
      }
      Vec4<T>& operator/=( const Vec4<T>& val ) {
        this->x /= val.x;
        this->y /= val.y;
        this->z /= val.z;
        this->w /= val.w;
        return *this;
      }

      // Unary stuff.
      inline friend std::ostream& operator<<( std::ostream& os, const Vec4<T>& vec ) {
        os << "x[" << vec.x << "], y[" << vec.y << "], z[" << vec.z << "], w[" << vec.w << "]" << std::endl;
          return os;
      }

      // Binary arithmetic operators.
      friend Vec4<T> operator+( const Vec4<T>& lhs, const T& rhs ) {
        return Vec4<T>(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
      }
      friend Vec4<T> operator+( const T& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w);
      }
      friend Vec4<T> operator+( const Vec4<T>& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
      }
      friend Vec4<T> operator-( const Vec4<T>& lhs, const T& rhs ) {
        return Vec4<T>(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
      }
      friend Vec4<T> operator-( const T& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w);
      }
      friend Vec4<T> operator-( const Vec4<T>& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
      }
      friend Vec4<T> operator*( const Vec4<T>& lhs, const T& rhs ) {
        return Vec4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
      }
      friend Vec4<T> operator*( const T& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
      }
      friend Vec4<T> operator*( const Vec4<T>& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
      }
      friend Vec4<T> operator/( const Vec4<T>& lhs, const T& rhs ) {
        return Vec4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
      }
      friend Vec4<T> operator/( const T& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w);
      }
      friend Vec4<T> operator/( const Vec4<T>& lhs, const Vec4<T>& rhs ) {
        return Vec4<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
      }
    };
  } /* math */
  
  // Typedefs.
  typedef cc::math::Vec4<float>        Vec4f;
  typedef cc::math::Vec4<double>       Vec4d;
  typedef cc::math::Vec4<int>          Vec4i;
  typedef cc::math::Vec4<unsigned int> Vec4ui;
  
} /* cc */

#endif	/* __CC_MATH_VEC4__ */

