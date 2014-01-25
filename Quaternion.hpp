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
 * 2013-11-15 13:57
 *  - Initial version.
 */

#ifndef __CC_MATH_QUATERNION__
#define	__CC_MATH_QUATERNION__

namespace cc {
  namespace math {
    template<typename T>
    class Quaternion {
    public:
      inline Quaternion();
      inline Quaternion( const T& x, const T& y, const T& z );
      inline Quaternion( const T& x, const T& y, const T& z, const T& w );
      inline Quaternion( const Vec3<T>& vec );
      inline Quaternion( const Vec3<T>& vec, const T& w );

      // Get the scalar component.
      inline T scalar() const;
      // Get the vector component.
      inline Vec3<T> vector() const;

      // Get the length.
      inline T length() const;
      // Get the conjugate.
      inline Quaternion<T> conjugate() const;
      // Get the angle this quaternion represents.
      inline T angle() const;
      // Get the axis of rotation this quaternion represents.
      inline Vec3<T> axis() const;
      // Rotate a quaternion by this quaternion.
      inline Quaternion<T> rotate( const Quaternion<T>& rhs ) const;
      // Rotate a vector around this quaternion.
      inline Vec3<T> rotate( const Vec3<T>& vec ) const;
      // Normalize this quaternion.
      inline void normalize();
      // Get a normalized version of this quaternion.
      inline Quaternion<T> normalized() const;
      // Add a scaled vector.
      inline void addScaledVector( const Vec3<T>& vec, const float scale );
      // Rotate a vector by this quaternion.
      inline Vec3<T> rotateVector( const Vec3<T>& vec ) const;
      // Return the inverse of this quaternion.
      inline Quaternion<T> inverse() const;
      // Dot product with another quaternion.
      inline T dot( const Quaternion<T>& rhs ) const;

      // Create a quaternion from an angle and an axis.
      static Quaternion<T> angleAxis( const Vec3<T>& axis, const T& angle );
      // Create a quaternion from Euler angles.
      static Quaternion<T> createFromEulerAngles( const T& x, const T& y, const T& z );
      // Extract Euler angles from a quaternion.
      static Vec3<T> createEulerAngles( const Quaternion<T>& q );
      // Create a quaternion from a matrix.
      static Quaternion<T> createFromMatrix( const Mat4<T>& m );
      // Create a matrix from a quaternion.
      static Mat4<T> createMatrixFromQuaternion( const Quaternion<T>& q );


    public:
      T _x;
      T _y;
      T _z;
      T _w;
    };
  } /* math */
  
  // Typedefs.
  typedef cc::math::Quaternion<float>        Quatf;
  typedef cc::math::Quaternion<double>       Quatd;
  typedef cc::math::Quaternion<int>          Quati;
  typedef cc::math::Quaternion<unsigned int> Quatui;
  
} /* cc */

#include "Quaternion.inl"

#endif	/* __CC_MATH_QUATERNION__ */

