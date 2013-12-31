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

#include "Mat4.hpp"
#include "Vec4.hpp"

#ifndef __CC_MATH_MATRIXFUNC__
#define	__CC_MATH_MATRIXFUNC__

namespace cc {
  namespace math {
    /**
     * Creates a translation matrix.
     * @param[in] position Position for the matrix to represent.
     * @return Translation matrix.
     */
    template<typename T>
    inline Mat4<T> translate( const Vec3<T>& position );

    /**
     * Creates a rotation matrix around a given axis and angle.
     * @param[in] angle Angle of the rotation.
     * @param[in] axis  The axis to rotate around.
     * @return Rotation matrix.
     */
    template<typename T>
    inline Mat4<T> rotate( const T& angle, const Vec3<T>& axis );

    /**
     * Creates a scaling matrix.
     * @param[in] size Scale values for the matrix.
     * @return Scaling matrix.
     */
    template<typename T>
    inline Mat4<T> scale( const Vec3<T>& size );

    /**
     * Creates an orthographic projection matrix.
     * @param[in] left   Left coordinate of the viewport.
     * @param[in] right  Right coordinate of the viewport.
     * @param[in] bottom Bottom coordinate of the viewport.
     * @param[in] top    Top coordinate of the viewport.
     * @return Orthographic projection matrix.
     */
    template<typename T>
    inline Mat4<T> orthographic( const T& left, const T& right, const T& bottom, const T& top );

    /**
     * Creates a frustum matrix.
     * @param[in] left   Left coordinate of the viewport.
     * @param[in] right  Right coordinate of the viewport.
     * @param[in] bottom Bottom coordinate of the viewport.
     * @param[in] top    Top coordinate of the viewport.
     * @param[in] near   Distance to the near plane.
     * @param[in] far    Distance to the far plane.
     * @return Frustum matrix.
     */
    template<typename T>
    inline Mat4<T> frustum( const T& left, const T& right, const T& bottom, const T& top, const T& near, const T& far );

    /**
     * Creates a perspective projection matrix.
     * @param[in] fovY   Field of view vertically.
     * @param[in] aspect Aspect ratio.
     * @param[in] near   Distance to the near plane.
     * @param[in] far    Distance to the far plane.
     * @return Perspective matrix.
     */
    template<typename T>
    inline Mat4<T> perspective( const T& fovY, const T& aspect, const T& near, const T& far );

    /**
     * Creates a lookat matrix.
     * @param[in] eye    Position of the eye.
     * @param[in] target Target to look at.
     * @param[in] up     Local up vector.
     * @return Lookat matrix.
     */
    template<typename T>
    inline Mat4<T> lookAt( const Vec3<T>& eye, const Vec3<T>& target, const Vec3<T>& up );

    /**
     * Inverses a matrix.
     * @param[in] mat Matrix to be inversed.
     * @return An inversed copy of the given matrix.
     */
    template<typename T>
    inline Mat4<T> inverse( const Mat4<T>& mat );

    /**
     * Creates an axis-angle matrix.
     * @param[in] axis  Axis of rotation.
     * @param[in] angle Angle of rotation.
     * @return Axis-angle matrix.
     */
    template<typename T>
    inline Mat4<T> axisAngle( const Vec3<T>& axis, float angle );
  } /* math */
} /* cc */

#include "MatrixFunc.inl"

#endif	/* __CC_MATH_MATRIXFUNC__ */

