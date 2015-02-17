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

#include <iostream>
#include <cassert>
#include <cmath>
#include "Common.hpp"
#include "Constants.hpp"

namespace cc {
  namespace math {
    template<typename T>
    inline Vec2<T>::Vec2() {
      this->x = static_cast<T>(0);
      this->y = static_cast<T>(0);
    }

    template<typename T>
    inline Vec2<T>::Vec2( const Vec2<T>& vec ) {
      this->x = vec.x;
      this->y = vec.y;
    }

    template<typename T>
    inline Vec2<T>::Vec2( const T& val ) {
      this->x = val;
      this->y = val;
    }

    template<typename T>
    inline Vec2<T>::Vec2( const T& x, const T& y ) {
      this->x = x;
      this->y = y;
    }

    // Accessors.
    template<typename T>
    inline T& Vec2<T>::operator[]( unsigned int index ) {
      assert(index < 2);
      return (&x)[index];
    }

    template<typename T>
    inline const T& Vec2<T>::operator[]( const unsigned int index ) const {
      assert(index < 2);
      return (&x)[index];
    }

    template<typename T>
    inline T& Vec2<T>::operator()( unsigned int index ) {
      assert(index < 2);
      return (&x)[index];
    }

    // Unary arithmetic operators.
    template<typename T>
    inline Vec2<T>& Vec2<T>::operator=( const Vec2<T>& vec ) {
      this->x = vec.x;
      this->y = vec.y;
      return *this;
    }

    template<typename T>
    inline Vec2<T>& Vec2<T>::operator+=( const Vec2<T>& vec ) {
      this->x += vec.x;
      this->y += vec.y;
      return *this;
    }

    template<typename T>
    inline Vec2<T>& Vec2<T>::operator-=( const Vec2<T>& vec ) {
      this->x -= vec.x;
      this->y -= vec.y;
      return *this;
    }

    template<typename T>
    inline Vec2<T>& Vec2<T>::operator*=( const Vec2<T>& vec ) {
      this->x *= vec.x;
      this->y *= vec.y;
      return *this;
    }

    template<typename T>
    inline Vec2<T>& Vec2<T>::operator/=( const Vec2<T>& vec ) {
      this->x /= vec.x;
      this->y /= vec.y;
      return *this;
    }
    
    // Binary arithmetic operators.
    template<typename T>
    inline Vec2<T> operator+( const Vec2<T>& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator+( const T& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs + rhs.x, lhs + rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator+( const Vec2<T>& lhs, const T& rhs ) {
      return Vec2<T>(lhs.x + rhs, lhs.y + rhs);
    }

    template<typename T>
    inline Vec2<T> operator-( const Vec2<T>& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator-( const T& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs - rhs.x, lhs - rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator-( const Vec2<T>& lhs, const T& rhs ) {
      return Vec2<T>(lhs.x - rhs, lhs.y - rhs);
    }

    template<typename T>
    inline Vec2<T> operator*( const Vec2<T>& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator*( const T& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator*( const Vec2<T>& lhs, const T& rhs ) {
      return Vec2<T>(lhs.x * rhs, lhs.y * rhs);
    }

    template<typename T>
    inline Vec2<T> operator/( const Vec2<T>& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator/( const T& lhs, const Vec2<T>& rhs ) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
    }
    template<typename T>
    inline Vec2<T> operator/( const Vec2<T>& lhs, const T& rhs ) {
      return Vec2<T>(lhs.x / rhs, lhs.y / rhs);
    }
    
    // Unary constant operators.
    template<typename T>
    inline Vec2<T> operator-( const Vec2<T>& vec ) {
      return Vec2<T>(-vec.x, -vec.y);
    }

    template<typename T>
    inline std::ostream& operator<<( std::ostream& os, const Vec2<T>& vec ) {
      os << "x[" << vec.x << "], y[" << vec.y << "]" << std::endl;
      return os;
    }

    // Other things.
    template<typename T>
    inline T Vec2<T>::magnitude( const Vec2<T>& rhs ) const {
      return static_cast<T>(sqrt(x*x + y*y));
    }
    template<typename T>
    inline T Vec2<T>::sqrMagnitude( const Vec2<T>& rhs ) const {
      return x*x + y*y;
    }
    template<typename T>
    inline void Vec2<T>::normalize() {
      const T eps = static_cast<T>(EPSILON);
      T mag = magnitude();
      mag = (mag <= eps) ? static_cast<T>(1) : mag;

      x /= mag;
      y /= mag;
      x = (fabs(x) < eps) ? static_cast<T>(0) : x;
      y = (fabs(y) < eps) ? static_cast<T>(0) : y;
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::normalized() const {
      const T eps = static_cast<T>(EPSILON);
      T mag = magnitude();
      mag = (mag <= eps) ? static_cast<T>(1) : mag;

      Vec2<T> result(*this);
      result.x /= mag;
      result.y /= mag;
      result.x = (fabs(result.x) < eps) ? static_cast<T>(0) : result.x;
      result.y = (fabs(result.y) < eps) ? static_cast<T>(0) : result.y;
      return result;
    }
    template<typename T>
    inline bool Vec2<T>::equalTo( const Vec2<T>& rhs ) const {
      return sqrMagnitude(*this - rhs) < static_cast<T>(EPSILON);
    }
    template<typename T>
    inline T Vec2<T>::dot( const Vec2<T>& rhs ) const {
      return x*rhs.x + y*rhs.y;
    }
    template<typename T>
    inline T Vec2<T>::cross3d( const Vec2<T>& rhs ) const {
      return x*rhs.y - y*rhs.x;
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::cross2d() const {
      return Vec2<T>(y, -x);
    }
    template<typename T>
    inline T Vec2<T>::distance( const Vec2<T>& rhs ) const {
      return magnitude(*this - rhs).magnitude();
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::minimum( const Vec2<T>& rhs ) const {
      return Vec2<T>(math::minimum<T>(x, rhs.x), math::minimum<T>(y, rhs.y));
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::maximum( const Vec2<T>& rhs ) const {
      return Vec2<T>(math::maximum<T>(x, rhs.x), math::maximum<T>(y, rhs.y));
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::lerp( const Vec2<T>& to, const float& t ) const {
      const float s = math::clamp<float>(0.0f, 1.0f, t);
      return Vec2<T>(math::lerp<T>(x, to.x, s), math::lerp<T>(y, to.y, s));
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::zero() {
      return Vec2<T>(static_cast<T>(0));
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::one() {
      return Vec2<T>(static_cast<T>(1));
    }

  } /* math */
} /* cc */
