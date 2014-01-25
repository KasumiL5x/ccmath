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
 *
 * 2014-01-25 17:11
 *  - Added zero, one, up, down, left, right, forward, and backward.
 *
 * 2013-11-15 13:57
 *  - Initial version.
 */

#ifndef __CC_MATH_VEC3__
#define	__CC_MATH_VEC3__

namespace cc {
  namespace math {
    template<typename T>
    class Vec3 {
    public:
      inline Vec3();
      inline Vec3( const Vec3<T>& vec );
      inline Vec3( const T& val);
      inline Vec3( const T& x, const T& y, const T& z );

      // Accessors.
      inline T&       operator[]( unsigned int index );
      inline const T& operator[]( unsigned int index ) const;
      inline T&       operator()( unsigned int index );

      // Unary arithmetic operators.
      inline Vec3<T>& operator= ( const Vec3<T>& vec );
      inline Vec3<T>& operator+=( const Vec3<T>& vec );
      inline Vec3<T>& operator-=( const Vec3<T>& vec );
      inline Vec3<T>& operator*=( const Vec3<T>& vec );
      inline Vec3<T>& operator/=( const Vec3<T>& vec );

      // Binary arithmetic operators.
      // All defined in vec3.inl.

      // Unary constant operators.
      // All defined in vec3.inl.

      // Other things.
      inline T       magnitude   () const;
      inline T       sqrMagnitude() const;
      inline void    normalize   ();
      inline Vec3<T> normalized  () const;
      inline bool    equalTo     ( const Vec3<T>& rhs ) const;
      inline T       dot         ( const Vec3<T>& rhs ) const;
      inline Vec3<T> cross       ( const Vec3<T>& rhs ) const;
      inline T       distance    ( const Vec3<T>& rhs ) const;
      inline T       sqrDistance ( const Vec3<T>& rhs ) const;
      inline Vec3<T> min         ( const Vec3<T>& rhs ) const;
      inline Vec3<T> max         ( const Vec3<T>& rhs ) const;
      inline Vec3<T> lerp        ( const Vec3<T>& to, const float& t );
      inline Vec3<T> reflect     ( const Vec3<T>& direction ); // Where this vector is the position.

      // Static stuff.
      inline static Vec3<T> zero    ();
      inline static Vec3<T> one     ();
      inline static Vec3<T> up      ();
      inline static Vec3<T> down    ();
      inline static Vec3<T> left    ();
      inline static Vec3<T> right   ();
      inline static Vec3<T> forward ();
      inline static Vec3<T> backward();

    public:
      union {
        struct {
          T x, y, z;
        };
        struct {
          T r, g, b;
        };
      };
    };
  } /* math */
  
  // Typedefs
  typedef cc::math::Vec3<float>        Vec3f;
  typedef cc::math::Vec3<double>       Vec3d;
  typedef cc::math::Vec3<int>          Vec3i;
  typedef cc::math::Vec3<unsigned int> Vec3ui;
  
} /* cc */

#include "Vec3.inl"

#endif	/* __CC_MATH_VEC3__ */

