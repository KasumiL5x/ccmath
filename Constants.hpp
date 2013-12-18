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
 * 2013-12-18 20:18
 *  - Added DEG_TO_RAD, RAD_TO_DEG.
 *  - Converted EPSILON, GRAVITY, and EARTH_RADIUS to floats from doubles.
 *
 * 2013-11-15 13:57
 *  - Initial version.
 */

#ifndef __CC_MATH_CONSTANTS__
#define	__CC_MATH_CONSTANTS__

namespace cc {
  namespace math {
    /**< Magic number to multiply by to approximately convert degrees to radians. */
    const static float DEG_TO_RAD = 0.0174532924f;
    /**< Magic number to multiply by to approximately convert radians to degrees. */
    const static float RAD_TO_DEG = 57.29578f;
    /**< Epsilon (Ε, http://mathworld.wolfram.com/Epsilon.html). */
    const static float EPSILON = 0.000001f;
    /**< Euler-Mascheroni constant, Gamma (γ, http://mathworld.wolfram.com/Euler-MascheroniConstant.html). */
    const static double GAMMA = 0.57721566490153286060651209008240243104215933593992;
    /**< ln(2). */
    const static double LN_TWO = 0.69314718055994530941723212145818;
    /**< Apéry's constant, (ζ, http://mathworld.wolfram.com/AperysConstant.html). */
    const static double ZETA = 1.2020569031595942854;
    /**< Pythagoras' constant (sqrt(2), http://mathworld.wolfram.com/PythagorassConstant.html). */
    const static double SQRT_TWO = 1.4142135623730950488016887242097;
    /**< Golden ratio (http://mathworld.wolfram.com/GoldenRatio.html). */
    const static double GOLDEN  = 1.6180339887498948482045868343656381177203091798057628;
    /**< Nested radical constant (http://mathworld.wolfram.com/NestedRadicalConstant.html) */
    const static double NEST_RADICAL = 1.757932756618004532708819638218138527653199922146837704310135;
    /**< Euler's number, e (http://mathworld.wolfram.com/e.html). */
    const static double e = 2.7182818284590452353602874713526624977572470936999595;
    /**< Archimedes' constant, pi (π, http://mathworld.wolfram.com/Pi.html). */
    const static double PI      = 3.14159265359;
    /**< Two pi. */
    const static double TWO_PI  = 6.28318530718;
    /**< Half pi. */
    const static double HALF_PI = 1.57079632679;
    /**< Acceleration due to gravity (on Earth). */
    const static float GRAVITY = 9.80665f; // m/s^2
    /**< Atomic mass unit in kilograms (1.66053886*10^-27, http://mathworld.wolfram.com/Pi.html). */
    const static double ATOMIC_MASS_UNIT = 1.66053886e-27;
    /**< Astronomical unit in meters. */
    const static double ASTRO_UNIT = 149597870700.0;
    /**< Avogadro constant (http://en.wikipedia.org/wiki/Avogadro_constant). */
    const static double AVOGADRO = 602214179000000000000000.0; // mol^-1 (6.02214179*10^23)
    /**< TODO: Verify and link. */
    const static double BOHR_MAGNETON = 0.00000000000000000000000927400915; // m2.A (9.27400915 * 10^-24)
    /**< TODO: Verify and link. */
    const static double BOLTZMANN = 0.000000000000000000000013806504; // J/K (1.3806504*10^-23)
    /**< TODO: Verify and link. */
    const static double QUANTUM_RATIO = 241798945400000.0; // A/J (2.417989454*10^14)
    /**< TODO: Verify and link. */
    const static double CONDUCTANCE_QUANTUM = 0.000077480917004; // S (7.7480917004*10^-5)
    /**< TODO: Verify and link. */
    const static double DAY_MEAN_SIDEREAL = 86164.0905380833; // S
    /**< TODO: Verify and link. */
    const static double DEUTERON_MASS = 3.3435832e-27; // Kg (3.34358320*10^-27)
    /**< TODO: Verify and link. */
    const static double EARTH_MASS = 5973500000000000000000000.0; // Kg (5.9735*10^24)
    /**< TODO: Verify and link. */
    const static float EARTH_RADIUS = 6378140.0f;// m (6.37814*10^6)
    /**< TODO: Verify and link. */
    const static double SPEED_OF_LIGHT = 299800000.0f; // m/s (2.998*10^8)
  }
}

#endif	/* __CC_MATH_CONSTANTS__ */

