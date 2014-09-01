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
 * 2014-01-25 17:16
 *  - Added zero, one.
 *
 * 2013-12-31 22:52
 *  - Fixed missing iostream include.
 *
 * 2013-11-15 13:57
 *  - Initial version.
 */

#ifndef __CC_MATH_VEC2__
#define	__CC_MATH_VEC2__

namespace cc {
  namespace math {
    template<typename T>
    class Vec2 {
    public:
      inline Vec2();
      inline Vec2( const Vec2<T>& vec );
      inline Vec2( const T& val );
      inline Vec2( const T& x, const T& y );

      // Accessors.
      inline T&       operator[]( unsigned int index );
      inline const T& operator[]( const unsigned int index ) const;
      inline T&       operator()( unsigned int index );

      // Unary arithmetic operators.
      inline Vec2<T>& operator= ( const Vec2<T>& vec );
      inline Vec2<T>& operator+=( const Vec2<T>& vec );
      inline Vec2<T>& operator-=( const Vec2<T>& vec );
      inline Vec2<T>& operator*=( const Vec2<T>& vec );
      inline Vec2<T>& operator/=( const Vec2<T>& vec );

      // Binary arithmetic operators.
      // All defined in vec2.inl.

      // Unary constant operators.
      // All defined in vec2.inl.

      // Other things.
      inline T       magnitude   ( const Vec2<T>& rhs ) const;
      inline T       sqrMagnitude( const Vec2<T>& rhs ) const;
      inline void    normalize   ();
      inline Vec2<T> normalized  () const;
      inline bool    equalTo     ( const Vec2<T>& rhs ) const;
      inline T       dot         ( const Vec2<T>& rhs ) const;
      // Treats as 3d vectors and returns the magnitude of the 3d cross product
      // where the Z component is zero.  Returned value is the area of the parallelogram
      // created by the two vectors.
      inline T       cross3d     ( const Vec2<T>& rhs ) const;
      // Returns a vector perpendicular to this one.
      inline Vec2<T> cross2d     () const;
      inline T       distance    ( const Vec2<T>& rhs ) const;
      inline Vec2<T> minimum     ( const Vec2<T>& rhs ) const;
      inline Vec2<T> maximum     ( const Vec2<T>& rhs ) const;
      inline Vec2<T> lerp        ( const Vec2<T>& to, const float& t ) const;

      // Static stuff.
      inline static Vec2<T> zero();
      inline static Vec2<T> one();

    public:
      union {
        struct {
          T x, y;
        };
        struct {
          T r, g;
        };
      };
    };
  } /* math */
  
  // Typedefs.
  typedef cc::math::Vec2<float>        Vec2f;
  typedef cc::math::Vec2<double>       Vec2d;
  typedef cc::math::Vec2<int>          Vec2i;
  typedef cc::math::Vec2<unsigned int> Vec2ui;
  
} /* cc */

// Inline implementations.
#include "Vec2.inl"

#endif	/* __CC_MATH_VEC2__ */

