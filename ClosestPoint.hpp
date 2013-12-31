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
 * @version 1.0.2
 *
 * 2013-11-15 13:57
 *  - Initial version.
 */

#ifndef __CC_MATH_CLOSESTPOINT__
#define	__CC_MATH_CLOSESTPOINT__

#include "Vec3.hpp"

namespace cc {
  namespace math {
    /**
     * Compute the closes point on a triangle.
     * @param[in] p  The point to test from.
     * @param[in] t0 The first vertex of the triangle.
     * @param[in] t1 The second vertex of the triangle.
     * @param[in] t2 The third vertex of the triangle.
     * @return The position of the closest point on the triangle.
     */
    template<typename T>
    inline Vec3<T> closestPointOnTriangle( const Vec3<T>& p, const Vec3<T>& t0, const Vec3<T>& t1, const Vec3<T>& t2 ) {
      /* Real-Time Collision Detection - Section 5.1.5 */

      // Check if P in vertex region outside A
      Vec3<T> ab = t1 - t0;
      Vec3<T> ac = t2 - t0;
      Vec3<T> ap = p - t0;
      float d1 = ab.dot(ap);
      float d2 = ac.dot(ap);
      if (d1 <= 0.0f && d2 <= 0.0f) return t0; // barycentric coordinates (1,0,0)

      // Check if P in vertex region outside B
      Vec3<T> bp = p - t1;
      float d3 = ab.dot(bp);
      float d4 = ac.dot(bp);
      if (d3 >= 0.0f && d4 <= d3) return t1; // barycentric coordinates (0,1,0)

      // Check if P in edge region of AB, if so return projection of P onto AB
      float vc = d1*d4 - d3*d2;
      if (vc <= 0.0f && d1 >= 0.0f && d3 <= 0.0f) {
          float v = d1 / (d1 - d3);
          return t0 + v * ab; // barycentric coordinates (1-v,v,0)
      }

      // Check if P in vertex region outside C
      Vec3<T> cp = p - t2;
      float d5 = ab.dot(cp);
      float d6 = ac.dot(cp);
      if (d6 >= 0.0f && d5 <= d6) return t2; // barycentric coordinates (0,0,1)

      // Check if P in edge region of AC, if so return projection of P onto AC
      float vb = d5*d2 - d1*d6;
      if (vb <= 0.0f && d2 >= 0.0f && d6 <= 0.0f) {
          float w = d2 / (d2 - d6);
          return t0 + w * ac; // barycentric coordinates (1-w,0,w)
      }

      // Check if P in edge region of BC, if so return projection of P onto BC
      float va = d3*d6 - d5*d4;
      if (va <= 0.0f && (d4 - d3) >= 0.0f && (d5 - d6) >= 0.0f) {
          float w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
          return t1 + w * (t2 - t1); // barycentric coordinates (0,1-w,w)
      }

      // P inside face region. Compute Q through its barycentric coordinates (u,v,w)
      float denom = 1.0f / (va + vb + vc);
      float v = vb * denom;
      float w = vc * denom;
      return t0 + ab * v + ac * w; // = u*a + v*b + w*c, u = va * denom = 1.0f - v - w
    }
    
   /**
     * Compute the closes point on a triangle.
     * @param[in]  p    The point to test from.
     * @param[in]  a    The beginning of the segment.
     * @param[in]  b    The end of the segment.
     * @param[out] outT The distance along the segment the point is located at.  This is clamped
     *                  to the segment and will never exceed it.
     * @param[out] outPos The closest point on the segment.
     */
    template<typename T>
    void closestPointOnSegment( const Vec3<T>& p, const Vec3<T>& a, const Vec3<T>& b, float* outT, Vec3<T>* outPos ) {
      // Safety check.
      if( outT == nullptr || outPos == nullptr ) {
        return;
      }

      const Vec3<T> ab = b - a;

      // Project point onto AB, but deferring divide by DP(ab,ab).
      *outT = (p - a).dot(ab);

      if( *outT <= 0.0f ) {
        // point projects outside the [A,B] interval, on the A side; clamp to A.
        *outT = 0.0f;
        *outPos = a;
      } else {
        const float denom = ab.dot(ab); // Always nonnegative since denom = ||ab||^2.
        if( *outT >= denom  ) {
          // point projects outside the [A,B] interval, on the B side; clamp to B.
          *outT = 1.0f;
          *outPos = b;
        } else {
          // point projects inside the [A,B] interval; must do deferred divide now.
          *outT = (*outT) / denom;
          *outPos = a + (*outT) * ab;
        }
      }
    }
    
  } /* math */
} /* cc */

#endif	/* __CC_MATH_CLOSESTPOINT__ */

