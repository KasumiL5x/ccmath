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
#include "Onb.hpp"
#include "Constants.hpp"

namespace cc {
  namespace math {
    template<typename T>
    inline Onb<T>::Onb( ) {
    }

    template<typename T>
    inline Onb<T>::Onb( const Vec3<T>& a, const Vec3<T>& b, const Vec3<T>& c )
      : _u(a), _v(b), _w(c) {
    }

    template<typename T>
    inline const Vec3<T>& Onb<T>::u( ) const {
      return _u;
    }

    template<typename T>
    inline const Vec3<T>& Onb<T>::v( ) const {
      return _v;
    }

    template<typename T>
    inline const Vec3<T>& Onb<T>::w( ) const {
      return _w;
    }


    template<typename T>
    inline void Onb<T>::initFromU( const Vec3<T>& u ) {
      const Vec3<T> n(1, 0, 0);
      const Vec3<T> m(0, 1, 0);
      _u = u.normalized();
      _v = _u.cross(n);
      if( _v.magnitude() < EPSILON ) {
        _v = _u.cross(m);
      }
      _w = _u.cross(_v);
    }

    template<typename T>
    inline void Onb<T>::initFromV( const Vec3<T>& v ) {
      const Vec3<T> n(1, 0, 0);
      const Vec3<T> m(0, 1, 0);
      _v = v.normalized();
      _u = _v.cross(n);
      if( _u.sqrMagnitude() < EPSILON ) {
        _u = _v.cross(m);
      }
      _w = _u.cross(_v);
    }

    template<typename T>
    inline void Onb<T>::initFromW( const Vec3<T>& w ) {
      const Vec3<T> n(1, 0, 0);
      const Vec3<T> m(0, 1, 0);
      _w = w.normalized();
      _u = _w.cross(n);
      if( _u.magnitude() < EPSILON ) {
        _u = _w.cross(m);
      }
      _v = _w.cross(_u);
    }

    template<typename T>
    inline void Onb<T>::initFromUV( const Vec3<T>& u, const Vec3<T>& v ) {
      _u = u.normalized();
      _w = u.cross(v).normalized();
      _v = _w.cross(_u);
    }

    template<typename T>
    inline void Onb<T>::initFromVU( const Vec3<T>& v, const Vec3<T>& u ) {
      _v = v.normalized();
      _w = u.cross(v).normalized();
      _u = _v.cross(_w);
    }

    template<typename T>
    inline void Onb<T>::initFromUW( const Vec3<T>& u, const Vec3<T>& w ) {
      _u = u.normalized();
      _v = w.cross(u).normalized();
      _w = _u.cross(_v);
    }

    template<typename T>
    inline void Onb<T>::initFromWU( const Vec3<T>& w, const Vec3<T>& u ) {
      _w = w.normalized();
      _v = w.cross(u).normalized();
      _u = _v.cross(_w);
    }

    template<typename T>
    inline void Onb<T>::initFromVW( const Vec3<T>& v, const Vec3<T>& w ) {
      _v = v.normalized();
      _u = v.cross(w).normalized();
      _w = _u.cross(_v);
    }

    template<typename T>
    inline void Onb<T>::initFromWV( const Vec3<T>& w, const Vec3<T>& v ) {
      _w = w.normalized();
      _u = v.cross(w).normalized();
      _v = _w.cross(_u);
    }

    template<typename T>
    inline void Onb<T>::set( const Vec3<T>& a, const Vec3<T>& b, const Vec3<T>& c ) {
      _u = a;
      _v = b;
      _w = c;
    }

    template<typename T>
    inline bool operator==( const Onb<T>& lhs, const Onb<T>& rhs ) {
      return ( lhs.u().equalTo(rhs.u()) && lhs.v().equalTo(rhs.v()) && lhs.w().equalTo(rhs.w()) );
    }

    template<typename T>
    std::ostream& operator<<( std::ostream& os, const Onb<T>& rhs ) {
      os << "U: " << rhs.u() << "V: " << rhs.v() << "W: " << rhs.w();
      return os;
    }

  } /* math */
} /* cc */
