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

#include <iostream>
#include <cassert>
#include <cmath>
#include "Common.hpp"
#include "Constants.hpp"

namespace cc {
  namespace math {
    template<typename T>
    inline Vec3<T>::Vec3() {
      this->x = static_cast<T>(0);
      this->y = static_cast<T>(0);
      this->z = static_cast<T>(0);
    }

    template<typename T>
    inline Vec3<T>::Vec3( const Vec3<T>& vec ) {
      this->x = vec.x;
      this->y = vec.y;
      this->z = vec.z;
    }

    template<typename T>
    inline Vec3<T>::Vec3( const T& val ) {
      this->x = val;
      this->y = val;
      this->z = val;
    }

    template<typename T>
    inline Vec3<T>::Vec3( const T& x, const T& y, const T& z ) {
      this->x = x;
      this->y = y;
      this->z = z;
    }

    // Accessors.
    template<typename T>
    inline T& Vec3<T>::operator[]( unsigned int index ) {
      assert(index < 3);
      return (&x)[index];
    }

    template<typename T>
    inline const T& Vec3<T>::operator[]( unsigned int index ) const {
      assert(index < 3);
      return (&x)[index];
    }

    template<typename T>
    inline T& Vec3<T>::operator()( unsigned int index ) {
      assert(index < 3);
      return (&x)[index];
    }

    // Unary arithmetic operators.
    template<typename T>
    inline Vec3<T>& Vec3<T>::operator=( const Vec3<T>& vec ) {
      this->x = vec.x;
      this->y = vec.y;
      this->z = vec.z;
      return *this;
    }

    template<typename T>
    inline Vec3<T>& Vec3<T>::operator+=( const Vec3<T>& vec ) {
      this->x += vec.x;
      this->y += vec.y;
      this->z += vec.z;
      return *this;
    }

    template<typename T>
    inline Vec3<T>& Vec3<T>::operator-=( const Vec3<T>& vec ) {
      this->x -= vec.x;
      this->y -= vec.y;
      this->z -= vec.z;
      return *this;
    }

    template<typename T>
    inline Vec3<T>& Vec3<T>::operator*=( const Vec3<T>& vec ) {
      this->x *= vec.x;
      this->y *= vec.y;
      this->z *= vec.z;
      return *this;
    }

    template<typename T>
    inline Vec3<T>& Vec3<T>::operator/=( const Vec3<T>& vec ) {
      this->x /= vec.x;
      this->y /= vec.y;
      this->z /= vec.z;
      return *this;
    }

    // Binary arithmetic operators.
    template<typename T>
    inline Vec3<T> operator+( const Vec3<T>& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator+( const T& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator+( const Vec3<T>& lhs, const T& rhs ) {
      return Vec3<T>(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
    }

    template<typename T>
    inline Vec3<T> operator-( const Vec3<T>& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator-( const T& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator-( const Vec3<T>& lhs, const T& rhs ) {
      return Vec3<T>(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
    }

    template<typename T>
    inline Vec3<T> operator*( const Vec3<T>& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator*( const T& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator*( const Vec3<T>& lhs, const T& rhs ) {
      return Vec3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    }

    template<typename T>
    inline Vec3<T> operator/( const Vec3<T>& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator/( const T& lhs, const Vec3<T>& rhs ) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
    }
    template<typename T>
    inline Vec3<T> operator/( const Vec3<T>& lhs, const T& rhs ) {
      return Vec3<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
    }

    // Unary constant operators.
    template<typename T>
    inline Vec3<T> operator-( const Vec3<T>& vec ) {
      return Vec3<T>(-vec.x, -vec.y, -vec.z);
    }

    template<typename T>
    inline std::ostream& operator<<( std::ostream& os, const Vec3<T>& vec ) {
      os << "x[" << vec.x << "], y[" << vec.y << "], z[" << vec.z << "]" << std::endl;
      return os;
    }

    // Other things.
    template<typename T>
    inline T Vec3<T>::magnitude() const {
      return static_cast<T>(sqrt(x*x + y*y + z*z));
    }
    
    template<typename T>
    inline T Vec3<T>::sqrMagnitude() const {
      return x*x + y*y + z*z;
    }
    
    template<typename T>
    inline void Vec3<T>::normalize() {
      const T eps = static_cast<T>(EPSILON);
      T mag = magnitude();
      mag = (mag <= eps) ? static_cast<T>(1) : mag;

      x /= mag;
      y /= mag;
      z /= mag;
      x = (fabs(x) < eps) ? static_cast<T>(0) : x;
      y = (fabs(y) < eps) ? static_cast<T>(0) : y;
      z = (fabs(z) < eps) ? static_cast<T>(0) : z;
    }
    
    template<typename T>
    inline Vec3<T> Vec3<T>::normalized() const {
      const T eps = static_cast<T>(EPSILON);
      T mag = magnitude();
      mag = (mag <= eps) ? static_cast<T>(1) : mag;

      Vec3<T> result(*this);
      result.x /= mag;
      result.y /= mag;
      result.z /= mag;

      result.x = (fabs(result.x) < eps) ? static_cast<T>(0) : result.x;
      result.y = (fabs(result.y) < eps) ? static_cast<T>(0) : result.y;
      result.z = (fabs(result.z) < eps) ? static_cast<T>(0) : result.z;
      return result;
    }
    
    template<typename T>
    inline bool Vec3<T>::equalTo( const Vec3<T>& rhs ) const {
      return (*this - rhs).sqrMagnitude() < static_cast<T>(EPSILON);
    }
    
    template<typename T>
    inline T Vec3<T>::dot( const Vec3<T>& rhs ) const {
      return x*rhs.x + y*rhs.y + z*rhs.z;
    }
    
    template<typename T>
    inline Vec3<T> Vec3<T>::cross( const Vec3<T>& rhs ) const {
      return Vec3<T>(y * rhs.z - z * rhs.y, -x * rhs.z + z * rhs.x, x * rhs.y - y * rhs.x);
    }
    
    template<typename T>
    inline T Vec3<T>::distance( const Vec3<T>& rhs ) const {
      return (*this - rhs).magnitude();
    }
    template<typename T>
    inline T Vec3<T>::sqrDistance( const Vec3<T>& rhs ) const {
      return (*this - rhs).sqrMagnitude();
    }
    
    template<typename T>
    inline Vec3<T> Vec3<T>::min( const Vec3<T>& rhs ) const {
      return Vec3<T>(math::min<T>(x, rhs.x), math::min<T>(y, rhs.y), math::min<T>(z, rhs.z));
    }
    
    template<typename T>
    inline Vec3<T> Vec3<T>::max( const Vec3<T>& rhs ) const {
      return Vec3<T>(math::max<T>(x, rhs.x), math::max<T>(y, rhs.y), math::max<T>(z, rhs.z));
    }
    
    template<typename T>
    inline Vec3<T> Vec3<T>::lerp( const Vec3<T>& to, const float& t ) {
      const float s = clamp<float>(0.0f, 1.0f, t);
      return Vec3<T>(math::lerp<T>(x, to.x, s), math::lerp<T>(y, to.y, s), math::lerp<T>(z, to.z, s));
    }
    
    template<typename T>
    inline Vec3<T> Vec3<T>::reflect( const Vec3<T>& direction ) {
      return static_cast<T>(-2) * direction.dot(*this) * direction + (*this);
    }
  } /* math */
} /* cc */
