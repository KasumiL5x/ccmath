#include "CppUnitTest.h"
#include <cc/Vec2.hpp>
#include "Common.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(Vec2Test) {
public:
	TEST_METHOD(Constructor) {
		// blank constructor should construct to zero
		const cc::Vec2f blankVector;
		Assert::AreEqual(0.0f, blankVector.x, TOLERANCE);
		Assert::AreEqual(0.0f, blankVector.y, TOLERANCE);

		// single argument sets x and y
		const cc::Vec2f singleArg(1.0f);
		Assert::AreEqual(1.0f, singleArg.x, TOLERANCE);
		Assert::AreEqual(1.0f, singleArg.y, TOLERANCE);

		// double argument sets x and y
		const cc::Vec2f doubleArg(1.0f, 2.0f);
		Assert::AreEqual(1.0f, doubleArg.x, TOLERANCE);
		Assert::AreEqual(2.0f, doubleArg.y, TOLERANCE);

		// copy constructor
		const cc::Vec2f copy(doubleArg);
		Assert::AreEqual(1.0f, copy.x, TOLERANCE);
		Assert::AreEqual(2.0f, copy.y, TOLERANCE);
	}

	TEST_METHOD(Accessors) {
		cc::Vec2f vec(1.0f, 2.0f);
		// access with []
		Assert::AreEqual(1.0f, vec[0], TOLERANCE);
		Assert::AreEqual(2.0f, vec[1], TOLERANCE);
		// access with ()
		Assert::AreEqual(1.0f, vec(0), TOLERANCE);
		Assert::AreEqual(2.0f, vec(1), TOLERANCE);
		
		// access w/ const []
		const cc::Vec2f constVec(1.0f, 2.0f);
		const float val0 = constVec[0];
		const float val1 = constVec[1];
		Assert::AreEqual(1.0f, val0, TOLERANCE);
		Assert::AreEqual(2.0f, val1, TOLERANCE);
	}

	TEST_METHOD(UnaryOperators) {
		const cc::Vec2f a(1.0f, 2.0f);

		// =
		cc::Vec2f equals;
		equals = a;
		Assert::AreEqual(1.0f, equals.x, TOLERANCE);
		Assert::AreEqual(2.0f, equals.y, TOLERANCE);

		// +=
		cc::Vec2f plusEquals;
		plusEquals += a;
		Assert::AreEqual(1.0f, plusEquals.x, TOLERANCE);
		Assert::AreEqual(2.0f, plusEquals.y, TOLERANCE);

		// -=
		cc::Vec2f minusEquals;
		minusEquals -= a;
		Assert::AreEqual(-1.0f, minusEquals.x, TOLERANCE);
		Assert::AreEqual(-2.0f, minusEquals.y, TOLERANCE);

		// *=
		cc::Vec2f mulEquals(3.0f);
		mulEquals *= a;
		Assert::AreEqual(3.0f, mulEquals.x, TOLERANCE);
		Assert::AreEqual(6.0f, mulEquals.y, TOLERANCE);

		// /=
		cc::Vec2f divEquals(3.0f);
		divEquals /= a;
		Assert::AreEqual(3.0f, divEquals.x, TOLERANCE);
		Assert::AreEqual(1.5f, divEquals.y, TOLERANCE);
	}

	TEST_METHOD(BinaryOperators) {
		const cc::Vec2f vec1(1.0f, 2.0f);
		const cc::Vec2f vec2(3.0f, 4.0f);
		const float scalar1 = 5.0f;

		// vec + vec
		const cc::Vec2f vpv = vec1 + vec2;
		Assert::AreEqual(4.0f, vpv.x, TOLERANCE);
		Assert::AreEqual(6.0f, vpv.y, TOLERANCE);

		// scalar + vec
		const cc::Vec2f spv = scalar1 + vec1;
		Assert::AreEqual(6.0f, spv.x, TOLERANCE);
		Assert::AreEqual(7.0f, spv.y, TOLERANCE);

		// vec + scalar
		const cc::Vec2f vps = vec1 + scalar1;
		Assert::AreEqual(6.0f, vps.x, TOLERANCE);
		Assert::AreEqual(7.0f, vps.y, TOLERANCE);

		// vec - vec
		const cc::Vec2f vmv = vec1 - vec2;
		Assert::AreEqual(-2.0f, vmv.x, TOLERANCE);
		Assert::AreEqual(-2.0f, vmv.y, TOLERANCE);

		// scalar - vec
		const cc::Vec2f smv = scalar1 - vec1;
		Assert::AreEqual(4.0f, smv.x, TOLERANCE);
		Assert::AreEqual(3.0f, smv.y, TOLERANCE);

		// vec - scalar
		const cc::Vec2f vms = vec1 - scalar1;
		Assert::AreEqual(-4.0f, vms.x, TOLERANCE);
		Assert::AreEqual(-3.0f, vms.y, TOLERANCE);

		// vec * vec
		const cc::Vec2f vmulv = vec1 * vec2;
		Assert::AreEqual(3.0f, vmulv.x, TOLERANCE);
		Assert::AreEqual(8.0f, vmulv.y, TOLERANCE);

		// scalar * vec
		const cc::Vec2f smulv = scalar1 * vec1;
		Assert::AreEqual(5.0f, smulv.x, TOLERANCE);
		Assert::AreEqual(10.0f, smulv.y, TOLERANCE);

		// vec * scalar
		const cc::Vec2f vmuls = vec1 * scalar1;
		Assert::AreEqual(5.0f, vmuls.x, TOLERANCE);
		Assert::AreEqual(10.0f, vmuls.y, TOLERANCE);

		// vec / vec
		const cc::Vec2f vdv = vec1 / vec2;
		Assert::AreEqual(0.33f, vdv.x, TOLERANCE);
		Assert::AreEqual(0.5f, vdv.y, TOLERANCE);

		// scalar / vec
		const cc::Vec2f sdv = scalar1 / vec1;
		Assert::AreEqual(5.0f, sdv.x, TOLERANCE);
		Assert::AreEqual(2.5f, sdv.y, TOLERANCE);

		// vec / scalar
		const cc::Vec2f vds = vec1 / scalar1;
		Assert::AreEqual(0.2f, vds.x, TOLERANCE);
		Assert::AreEqual(0.4f, vds.y, TOLERANCE);
	}

	TEST_METHOD(BinaryComparisonOperators) {
		const bool equal = cc::Vec2f(1.0f, 2.0f) == cc::Vec2f(1.0f, 2.0f);
		Assert::IsTrue(equal);

		const bool notEqual = cc::Vec2f(1.0f, 2.0f) != cc::Vec2f(3.0f, 4.0f);
		Assert::IsTrue(notEqual);
	}

	TEST_METHOD(UnaryConstantOperators) {
		const cc::Vec2f neg = -cc::Vec2f(1.0f, 2.0f);
		Assert::AreEqual(neg.x, -1.0f, TOLERANCE);
		Assert::AreEqual(neg.y, -2.0f, TOLERANCE);
	}

	TEST_METHOD(Other) {
		// http://www.wolframalpha.com/input/?i=vector+%7B1.0%2C+2.0%7D
		const cc::Vec2f vec(1.0f, 2.0f);

		// magnitude
		Assert::AreEqual(2.23607f, vec.magnitude(), TOLERANCE);

		// square magnitude
		Assert::AreEqual(5.0f, vec.sqrMagnitude(), TOLERANCE);

		// normalize
		cc::Vec2f normalizeMe = vec;
		normalizeMe.normalize();
		Assert::AreEqual(0.447214f, normalizeMe.x, TOLERANCE);
		Assert::AreEqual(0.894427f, normalizeMe.y, TOLERANCE);

		// normalized
		const cc::Vec2f normalized = vec.normalized();
		Assert::AreEqual(0.447214f, normalized.x, TOLERANCE);
		Assert::AreEqual(0.894427f, normalized.y, TOLERANCE);

		// equalTo
		const bool equalTo = vec.equalTo(cc::Vec2f(1.0f, 2.0f));
		Assert::IsTrue(equalTo);

		// dot product (http://www.wolframalpha.com/input/?i=vector%7B1.0%2C+2.0%7D+DOT+vector%7B3.0%2C+4.0%7D)
		const float dot = vec.dot(cc::Vec2f(3.0f, 4.0f));
		Assert::AreEqual(11.0f, dot, TOLERANCE);

		// cross3d
		Logger::WriteMessage("TODO: Vec2::cross3d()");

		// cross2d
		Logger::WriteMessage("TODO: Vec2::cross2d()");

		// distance
		const float distance = vec.distance(cc::Vec2f(3.0f, 4.0f));
		Assert::AreEqual(2.82843f, distance, TOLERANCE);

		// square distance
		const float sqrDistance = vec.sqrDistance(cc::Vec2f(3.0f, 4.0f));
		Assert::AreEqual(8.0f, sqrDistance, TOLERANCE);

		// minimum
		const cc::Vec2f min = vec.minimum(cc::Vec2f(-1.0f, 4.0f));
		Assert::AreEqual(-1.0f, min.x, TOLERANCE);
		Assert::AreEqual(2.0f, min.y, TOLERANCE);

		// maximum
		const cc::Vec2f max = vec.maximum(cc::Vec2f(-1.0f, 4.0f));
		Assert::AreEqual(1.0f, max.x, TOLERANCE);
		Assert::AreEqual(4.0f, max.y, TOLERANCE);

		// lerp
		const cc::Vec2f zeroLerp = vec.lerp(cc::Vec2f(3.0f, 4.0f), 0.0f);
		Assert::AreEqual(zeroLerp.x, 1.0f, TOLERANCE);
		Assert::AreEqual(zeroLerp.y, 2.0f, TOLERANCE);
		const cc::Vec2f halfLerp = vec.lerp(cc::Vec2f(3.0f, 4.0f), 0.5f);
		Assert::AreEqual(2.0f, halfLerp.x, TOLERANCE);
		Assert::AreEqual(3.0f, halfLerp.y, TOLERANCE);
		const cc::Vec2f oneLerp = vec.lerp(cc::Vec2f(3.0f, 4.0f), 1.0f);
		Assert::AreEqual(oneLerp.x, 3.0f, TOLERANCE);
		Assert::AreEqual(oneLerp.y, 4.0f, TOLERANCE);

		// zero
		const cc::Vec2f zero = cc::Vec2f::zero();
		Assert::AreEqual(0.0f, zero.x, TOLERANCE);
		Assert::AreEqual(0.0f, zero.y, TOLERANCE);

		// one
		const cc::Vec2f one = cc::Vec2f::one();
		Assert::AreEqual(1.0f, one.x, TOLERANCE);
		Assert::AreEqual(1.0f, one.y, TOLERANCE);
	}
};
