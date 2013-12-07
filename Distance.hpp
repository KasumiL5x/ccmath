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

#ifndef __CC_MATH_DISTANCE__
#define	__CC_MATH_DISTANCE__

#include "Vec3.hpp"

namespace cc {
  namespace math {
    /**
     * Compute the perpendicular distance from a point to a plane.
     * @param[in] point       Point to test from.
     * @param[in] planePoint  Point on the plane.
     * @param[in] planeNormal Normal of the plane.
     * @return perpendicular distance from the point to the plane.
     */
    template<typename T>
    inline float perpendicularDistanceToPointFromPlane( const Vec3<T>& point, const Vec3<T>& planePoint, const Vec3<T>& planeNormal ) {
      return point.dot(planeNormal) - planePoint.dot(planeNormal);
    }
  } /* math */
} /* cc */

#endif	/* __CC_MATH_DISTANCE__ */

