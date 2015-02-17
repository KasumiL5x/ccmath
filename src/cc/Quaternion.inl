/*
  ccmath is a collection of helpful mathematical functions and classes.
  It was developed for use in small, personal projects and should not be
  used as a replacement for more complex mathematical libraries.
  
  The MIT License (MIT)

  Copyright (c) 2014 Daniel Green

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  Don't claim it as your own.  Give credit where credit is due.

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <iostream>

namespace cc {
  namespace math {
    template<typename T>
    inline Quaternion<T>::Quaternion() 
      : _x(static_cast<T>(0)), _y(static_cast<T>(0)), _z(static_cast<T>(0)), _w(static_cast<T>(1)) {
    }

    template<typename T>
    inline Quaternion<T>::Quaternion( const T& x, const T& y, const T& z )
      : _x(x), _y(y), _z(z), _w(static_cast<T>(1)) {
    }

    template<typename T>
    inline Quaternion<T>::Quaternion( const T& x, const T& y, const T& z, const T& w )
      : _x(x), _y(y), _z(z), _w(w) {
    }

    template<typename T>
    inline Quaternion<T>::Quaternion( const Vec3<T>& vec )
      : _x(vec.x), _y(vec.y), _z(vec.z), _w(static_cast<T>(1)) {
    }

    template<typename T>
    inline Quaternion<T>::Quaternion( const Vec3<T>& vec, const T& w )
      : _x(vec.x), _y(vec.y), _z(vec.z), _w(w) {
    }

    template<typename T>
    inline T Quaternion<T>::scalar() const {
      return _w;
    }

    template<typename T>
    inline Vec3<T> Quaternion<T>::vector() const {
      return Vec3<T>(_x, _y, _z);
    }

    template<typename T>
    inline T Quaternion<T>::length() const {
      return sqrt(_w*_w + _x*_x + _y*_y + _z*_z);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::conjugate() const {
      return Quaternion(-_x, -_y, -_z, _w);
    }

    template<typename T>
    inline T Quaternion<T>::angle() const {
      return static_cast<T>(2) * static_cast<T>(acos(_w));
    }

    template<typename T>
    inline Vec3<T> Quaternion<T>::axis() const {
      Vec3<T> v(_x, _y, _z);
      const T m = v.magnitude();
      return (m <= static_cast<T>(EPSILON)) ? Vec3<T>() : v/m;
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::rotate( const Quaternion<T>& rhs ) const {
      return *this * rhs * this->conjugate();
    }

    template<typename T>
    inline Vec3<T> Quaternion<T>::rotate( const Vec3<T>& vec ) const {
      const Quaternion<T> t = *this * vec * this->conjugate();
      return t.vector();
    }

    template<typename T>
    inline void Quaternion<T>::normalize() {
      T d = _w*_w + _x*_x + _y*_y + _z*_z;
      // If a zero-length Quaternion, set to identity and return.
      if( equal<T>(d, static_cast<T>(0)) )
      {
        _w = static_cast<T>(1);
        return;
      }
      d = (static_cast<T>(1) / static_cast<T>(sqrt(d)));
      _w *= d;
      _x *= d;
      _y *= d;
      _z *= d;
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::normalized() const {
      T d = _w*_w + _x*_x + _y*_y + _z*_z;
      // If a zero-length Quaternion, return identity.
      if( equal<T>(d, static_cast<T>(0)) )
      {
        return Quaternion();
      }
      d = (static_cast<T>(1) / static_cast<T>(sqrt(d)));
    
      return Quaternion(_x*d, _y*d, _z*d, _w*d);
    }

    template<typename T>
    Quaternion<T> Quaternion<T>::createFromEulerAngles( const T& x, const T& y, const T& z ) {
      const T roll  = degreesToRadians<T>(x);
      const T pitch = degreesToRadians<T>(y);
      const T yaw   = degreesToRadians<T>(z);
    
      const T cYaw   = static_cast<T>(cos(static_cast<T>(0.5) * yaw));
      const T cPitch = static_cast<T>(cos(static_cast<T>(0.5) * pitch));
      const T cRoll  = static_cast<T>(cos(static_cast<T>(0.5) * roll));
      const T sYaw   = static_cast<T>(sin(static_cast<T>(0.5) * yaw));
      const T sPitch = static_cast<T>(sin(static_cast<T>(0.5) * pitch));
      const T sRoll  = static_cast<T>(sin(static_cast<T>(0.5) * roll));
    
      const T cYawCPitch = cYaw * cPitch;
      const T sYawsPitch = sYaw * sPitch;
      const T cYawSPitch = cYaw * sPitch;
      const T sYawCPitch = sYaw * cPitch;
    
      Quaternion q;
      q._w = cYawCPitch * cRoll + sYawsPitch * sRoll;
      q._x = cYawCPitch * sRoll - sYawsPitch * cRoll;
      q._y = cYawSPitch * cRoll + sYawCPitch * sRoll;
      q._z = sYawCPitch * cRoll - cYawSPitch * sRoll;
      return q;
    }

    template<typename T>
    inline void Quaternion<T>::addScaledVector( const Vec3<T>& vec, const float scale ) {
      Quaternion<T> q(vec.x*scale, vec.y*scale, vec.z*scale, static_cast<T>(0));
      q = q * *this;
    
      _w += q._w * static_cast<T>(0.5);
      _x += q._x * static_cast<T>(0.5);
      _y += q._y * static_cast<T>(0.5);
      _z += q._z * static_cast<T>(0.5);
    }

    template<typename T>
    inline Vec3<T> Quaternion<T>::rotateVector( const Vec3<T>& vec ) const {
      Mat4<T> mat;
      mat[0][0] = static_cast<T>(1) - (static_cast<T>(2) * (this->_y*this->_y)) - (static_cast<T>(2) * (this->_z*this->_z));
      mat[0][1] = static_cast<T>(2) * (this->_x*this->_y + this->_w*this->_z);
      mat[0][2] = static_cast<T>(2) * (this->_x*this->_z + this->_w*this->_y);

      mat[1][0] = static_cast<T>(2) * (this->_x*this->_y + this->_w*this->_z);
      mat[1][1] = static_cast<T>(1) - (static_cast<T>(2) * (this->_x*this->_x)) - (static_cast<T>(2) * (this->_z*this->_z));
      mat[1][2] = static_cast<T>(2) * (this->_y*this->_z + this->_w*this->_x);

      mat[2][0] = static_cast<T>(2) * (this->_x*this->_z + this->_w*this->_y);
      mat[2][1] = static_cast<T>(2) * (this->_y*this->_z + this->_w*this->_x);
      mat[2][2] = static_cast<T>(1) - (static_cast<T>(2) * (this->_x*this->_x)) - (static_cast<T>(2) * (this->_y*this->_y));
      const Vec4<T> tmpVec = mat * Vec4<T>(vec.x, vec.y, vec.z, static_cast<T>(1));
      return Vec3<T>(tmpVec.x, tmpVec.y, tmpVec.z);
    }

    template<typename T>
    inline Quaternion<T> Quaternion<T>::inverse() const {
      return this->conjugate() / this->dot(*this);
    }

    template<typename T>
    inline T Quaternion<T>::dot( const Quaternion<T>& rhs ) const {
      return this->_x * rhs._x + this->_y * rhs._y + this->_z * rhs._z + this->_w * rhs._w;
    }

    template<typename T>
    Quaternion<T> Quaternion<T>::angleAxis( const Vec3<T>& axis, const T& angle ) {
      const T s = static_cast<T>(sin(angle * static_cast<T>(0.5)));
      Quaternion<T> q;
      q._w = static_cast<T>(cos(angle * static_cast<T>(0.5)));
      q._x = axis.x * s;
      q._y = axis.y * s;
      q._z = axis.z * s;
      return q;
    }

    template<typename T>
    Vec3<T> Quaternion<T>::createEulerAngles( const Quaternion<T>& q ) {
      const T q00 = q._w * q._w;
      const T q11 = q._x * q._x;
      const T q22 = q._y * q._y;
      const T q33 = q._z * q._z;
    
      const T r11 = q00 + q11 - q22 - q33;
      const T r21 = static_cast<T>(2) * (q._x*q._y + q._w*q._z);
      const T r31 = static_cast<T>(2) * (q._x*q._z - q._w*q._y);
      const T r32 = static_cast<T>(2) * (q._y*q._z + q._w*q._x);
      const T r33 = q00 - q11 - q22 + q33;
    
      const T tmp = static_cast<T>(fabs(r31));
      if( tmp > static_cast<T>(0.999999) )
      {
        const T r12 = static_cast<T>(2) * (q._x*q._y - q._w*q._z);
        const T r13 = static_cast<T>(2) * (q._x*q._z + q._w*q._y);
      
        Vec3<T> v;
        v.x = radiansToDegrees<T>(0.0);
        v.y = radiansToDegrees<T>(-(static_cast<T>(PI/2.0)) * r31/tmp);
        v.z = radiansToDegrees<T>(atan2(-r12, (-r31*r13)));
        return v;
      }
    
      Vec3<T> v1;
      v1.x = radiansToDegrees<T>(atan2(r32, r33));
      v1.y = radiansToDegrees<T>(asin(-r31));
      v1.z = radiansToDegrees<T>(atan2(r21, r11));
      return v1;
    }

    template<typename T>
    Quaternion<T> Quaternion<T>::createFromMatrix( const Mat4<T>& m ) {
      const T w  = static_cast<T>(sqrt((static_cast<T>(1) + m[0][0] + m[1][1] + m[2][2])) / static_cast<T>(2));
      const T w4 = (static_cast<T>(4) * w);
    
      Quaternion<T> q;
      q._w = w;
      q._x = (m[2][1] - m[1][2]) / w4;
      q._y = (m[0][2] - m[2][0]) / w4;
      q._z = (m[1][0] - m[0][1]) / w4;
      return q;
    }

    template<typename T>
    Mat4<T> Quaternion<T>::createMatrixFromQuaternion( const Quaternion<T>& q ) {
      const T r = q._w;
      const T x = q._x;
      const T y = q._y;
      const T z = q._z;
      Mat4<T> c;
      c[0][0] = static_cast<T>(1) - static_cast<T>(2)*y*y - static_cast<T>(2)*z*z;
      c[0][1] = static_cast<T>(2)*x*y - static_cast<T>(2)*r*z;
      c[0][2] = static_cast<T>(2)*x*z + static_cast<T>(2)*r*y;
    
      c[1][0] = static_cast<T>(2)*x*y + static_cast<T>(2)*r*z;
      c[1][1] = static_cast<T>(1) - static_cast<T>(2)*x*x - static_cast<T>(2)*z*z;
      c[1][2] = static_cast<T>(2)*y*z - static_cast<T>(2)*r*x;
    
      c[2][0] = static_cast<T>(2)*x*z - static_cast<T>(2)*r*y;
      c[2][1] = static_cast<T>(2)*y*z + static_cast<T>(2)*r*x;
      c[2][2] = static_cast<T>(1) - static_cast<T>(2)*x*x - static_cast<T>(2)*y*y;
    
      return c;
    }

    // Binary arithmetic operators.
    template<typename T>
    inline Quaternion<T> operator+( const Quaternion<T>& lhs, const Quaternion<T>& rhs ) {
      return Quaternion<T>(lhs._x + rhs._x, lhs._y + rhs._y, lhs._z + rhs._z, lhs._w + rhs._w);
    }
    template<typename T>
    inline Quaternion<T> operator-( const Quaternion<T>& lhs, const Quaternion<T>& rhs ) {
      return Quaternion<T>(lhs._x - rhs._x, lhs._y - rhs._y, lhs._z - rhs._z, lhs._w - rhs._w);
    }
    template<typename T>
    inline Quaternion<T> operator*( const Quaternion<T>& lhs, const T& rhs ) {
      return Quaternion<T>(lhs._x * rhs, lhs._y * rhs, lhs._z * rhs, lhs._w * rhs);
    }
    template<typename T>
    inline Quaternion<T> operator*( const Quaternion<T>& lhs, const Quaternion<T>& rhs ) {
      return Quaternion<T>(lhs._w*rhs._x + lhs._x*rhs._w + lhs._y*rhs._z - lhs._z*rhs._y,
                           lhs._w*rhs._y + lhs._y*rhs._w + lhs._z*rhs._x - lhs._x*rhs._z,
                           lhs._w*rhs._z + lhs._z*rhs._w + lhs._x*rhs._y - lhs._y*rhs._x,
                           lhs._w*rhs._w - lhs._x*rhs._x - lhs._y*rhs._y - lhs._z*rhs._z);
    }
    template<typename T>
    inline Quaternion<T> operator/( const Quaternion<T>& lhs, const T& rhs ) {
      return Quaternion<T>(lhs._x / rhs, lhs._y / rhs, lhs._z / rhs, lhs._w / rhs);
    }
    template<typename T>
    inline Vec3<T> operator*( const Quaternion<T>& q, const Vec3<T>& v ) {
		  const T two = static_cast<T>(2);

		  Vec3<T> uv, uuv;
		  Vec3<T> QuatVector(q._x, q._y, q._z);
		  uv = QuatVector.cross(v);
		  uuv = QuatVector.cross(uv);
		  uv *= (two * q._w); 
		  uuv *= two; 

		  return v + uv + uuv;
    }

    template<typename T>
    inline Vec3<T> operator*( const Vec3<T>& v, const Quaternion<T>& q ) {
      return q.inverse() * v;
    }

    template<typename T>
    inline std::ostream& operator<<( std::ostream& os, const Quaternion<T>& q ) {
      os << "x[" << q._x << "], y[" << q._y << "], z[" << q._z << "], w[" << q._w << "]" << std::endl;
      return os;
    }
  } /* math */
} /* cc */
