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

#ifndef __CC_MATH_ONB__
#define __CC_MATH_ONB__

#include "Vec3.hpp"

namespace cc {
  namespace math {
    // Orthonormal basis
    template<typename T>
    class Onb {
    public:
      inline Onb( );
      inline Onb( const Vec3<T>& a, const Vec3<T>& b, const Vec3<T>& c );

      inline const Vec3<T>& u( ) const;
      inline const Vec3<T>& v( ) const;
      inline const Vec3<T>& w( ) const;

      inline void initFromU ( const Vec3<T>& u );
      inline void initFromV ( const Vec3<T>& v );
      inline void initFromW ( const Vec3<T>& w );
      inline void initFromUV( const Vec3<T>& u, const Vec3<T>& v );
      inline void initFromVU( const Vec3<T>& v, const Vec3<T>& u );
      inline void initFromUW( const Vec3<T>& u, const Vec3<T>& w );
      inline void initFromWU( const Vec3<T>& w, const Vec3<T>& u );
      inline void initFromVW( const Vec3<T>& v, const Vec3<T>& w );
      inline void initFromWV( const Vec3<T>& w, const Vec3<T>& v );

      inline void set( const Vec3<T>& a, const Vec3<T>& b, const Vec3<T>& c );

    private:
      Vec3<T> _u;
      Vec3<T> _v;
      Vec3<T> _w;
    };
  } /* math */

  // Typedefs.
  typedef cc::math::Onb<float>        Onbf;
  typedef cc::math::Onb<double>       Onbd;
  typedef cc::math::Onb<int>          Onbi;
  typedef cc::math::Onb<unsigned int> Onbui;

} /* cc */

#include "Onb.inl"

#endif /* __CC_MATH_ONB__ */
