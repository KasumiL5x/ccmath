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

#ifndef __CC_MATH_RANDOM__
#define __CC_MATH_RANDOM__

#include <random>

template <class RealType, class IntType>
class Random {
public:
	Random() {
		std::random_device dev;
		_mt = std::mt19937(dev());
	}
	Random( unsigned int seed ) {
		_mt = std::mt19937(seed);
	}
	~Random() {
	}

	RealType nextReal() {
		std::uniform_real_distribution<RealType> dist;
		return dist(_mt);
	}

	RealType nextReal( const RealType min, const RealType max ) {
		std::uniform_real_distribution<RealType> dist(min, max);
		return dist(_mt);
	}

	IntType nextInt() {
		std::uniform_int_distribution<IntType> dist;
		return dist(_mt);
	}

	IntType nextInt( const IntType min, const IntType max ) {
		std::uniform_int_distribution<IntType> dist(min, max);
		return dist(_mt);
	}

private:
	std::mt19937 _mt;
};

#endif /* __CC_MATH_RANDOM__ */
