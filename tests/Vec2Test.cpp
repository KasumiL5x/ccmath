#include "CppUnitTest.h"
#include <cc/Vec2.hpp>
#include "Common.hpp"
#include "Random.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(Vec2Test) {
private:
	Random<float, int> rnd;

	cc::Vec2f randomVector() {
		return cc::Vec2f(rnd.nextReal(), rnd.nextReal());
	}

public:
	TEST_METHOD(Constructor) {
		const cc::Vec2f blank;
		Assert::AreEqual(0.0f, blank.x, TOLERANCE);
		Assert::AreEqual(0.0f, blank.y, TOLERANCE);

		const float rnd_a = rnd.nextReal();
		const cc::Vec2f single(rnd_a);
		Assert::AreEqual(rnd_a, single.x, TOLERANCE);
		Assert::AreEqual(rnd_a, single.y, TOLERANCE);

		const float rnd_b = rnd.nextReal();
		const cc::Vec2f doubleVec(rnd_a, rnd_b);
		Assert::AreEqual(rnd_a, doubleVec.x, TOLERANCE);
		Assert::AreEqual(rnd_b, doubleVec.y, TOLERANCE);

		const cc::Vec2f copy(doubleVec);
		Assert::AreEqual(doubleVec.x, copy.x, TOLERANCE);
		Assert::AreEqual(doubleVec.y, copy.y, TOLERANCE);
	}

	TEST_METHOD(Accessors) {
		const float rnd_a = rnd.nextReal();
		const float rnd_b = rnd.nextReal();

		const cc::Vec2f vec1(rnd_a, rnd_b);
		Assert::AreEqual(rnd_a, vec1[0], TOLERANCE);
		Assert::AreEqual(rnd_b, vec1[1], TOLERANCE);
		Assert::AreEqual(rnd_a, vec1(0), TOLERANCE);
		Assert::AreEqual(rnd_b, vec1(1), TOLERANCE);

		cc::Vec2f vec2(rnd_a, rnd_b);
		Assert::AreEqual(rnd_a, vec2[0], TOLERANCE);
		Assert::AreEqual(rnd_b, vec2[1], TOLERANCE);
		Assert::AreEqual(rnd_a, vec2(0), TOLERANCE);
		Assert::AreEqual(rnd_b, vec2(1), TOLERANCE);
	}

	TEST_METHOD(UnaryOperators) {
		const cc::Vec2f vec = randomVector();

		// =
		cc::Vec2f equals; equals = vec;
		Assert::AreEqual(vec.x, equals.x, TOLERANCE);
		Assert::AreEqual(vec.y, equals.y, TOLERANCE);

		// +=
		cc::Vec2f plusEquals; plusEquals += vec;
		Assert::AreEqual(vec.x, plusEquals.x, TOLERANCE);
		Assert::AreEqual(vec.y, plusEquals.y, TOLERANCE);

		// -=
		cc::Vec2f minusEquals; minusEquals -= vec;
		Assert::AreEqual(-vec.x, minusEquals.x, TOLERANCE);
		Assert::AreEqual(-vec.y, minusEquals.y, TOLERANCE);

		// *=
		cc::Vec2f mulEquals(3.0f); mulEquals *= vec;
		Assert::AreEqual(vec.x*3.0f, mulEquals.x, TOLERANCE);
		Assert::AreEqual(vec.y*3.0f, mulEquals.y, TOLERANCE);

		// /=
		cc::Vec2f divEquals(3.0f); divEquals /= vec;
		Assert::AreEqual(3.0f/vec.x, divEquals.x, TOLERANCE);
		Assert::AreEqual(3.0f/vec.y, divEquals.y, TOLERANCE);
	}

	TEST_METHOD(BinaryOperators) {
		const cc::Vec2f vec1 = randomVector();
		const cc::Vec2f vec2 = randomVector();
		const float scalar = rnd.nextReal();

		// vec + vec
		const cc::Vec2f vecPlusVec = vec1 + vec2;
		Assert::AreEqual(vec1.x+vec2.x, vecPlusVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y+vec2.y, vecPlusVec.y, TOLERANCE);
		// scalar + vec
		const cc::Vec2f sclPlusVec = scalar + vec1;
		Assert::AreEqual(scalar+vec1.x, sclPlusVec.x, TOLERANCE);
		Assert::AreEqual(scalar+vec1.y, sclPlusVec.y, TOLERANCE);
		// vec + scalar
		const cc::Vec2f vecPlusScl = vec1 + scalar;
		Assert::AreEqual(vec1.x+scalar, vecPlusScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y+scalar, vecPlusScl.y, TOLERANCE);

		// vec - vec
		const cc::Vec2f vecMinVec = vec1 - vec2;
		Assert::AreEqual(vec1.x-vec2.x, vecMinVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y-vec2.y, vecMinVec.y, TOLERANCE);
		// scalar - vec
		const cc::Vec2f sclMinVec = scalar - vec1;
		Assert::AreEqual(scalar-vec1.x, sclMinVec.x, TOLERANCE);
		Assert::AreEqual(scalar-vec1.y, sclMinVec.y, TOLERANCE);
		// vec - scalar
		const cc::Vec2f vecMinScl = vec1 - scalar;
		Assert::AreEqual(vec1.x-scalar, vecMinScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y-scalar, vecMinScl.y, TOLERANCE);

		// vec * vec
		const cc::Vec2f vecMulVec = vec1 * vec2;
		Assert::AreEqual(vec1.x*vec2.x, vecMulVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y*vec2.y, vecMulVec.y, TOLERANCE);
		// scalar * vec
		const cc::Vec2f sclMulVec = scalar * vec1;
		Assert::AreEqual(scalar*vec1.x, sclMulVec.x, TOLERANCE);
		Assert::AreEqual(scalar*vec1.y, sclMulVec.y, TOLERANCE);
		// vec * scalar
		const cc::Vec2f vecMulScl = vec1 * scalar;
		Assert::AreEqual(vec1.x*scalar, vecMulScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y*scalar, vecMulScl.y, TOLERANCE);

		// vec / vec
		const cc::Vec2f vecDivVec = vec1 / vec2;
		Assert::AreEqual(vec1.x/vec2.x, vecDivVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y/vec2.y, vecDivVec.y, TOLERANCE);
		// scalar / vec
		const cc::Vec2f sclDivVec = scalar / vec1;
		Assert::AreEqual(scalar/vec1.x, sclDivVec.x, TOLERANCE);
		Assert::AreEqual(scalar/vec1.y, sclDivVec.y, TOLERANCE);
		// vec / scalar
		const cc::Vec2f vecDivScl = vec1 / scalar;
		Assert::AreEqual(vec1.x/scalar, vecDivScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y/scalar, vecDivScl.y, TOLERANCE);
	}

	TEST_METHOD(BinaryComparisonOperators) {
		const cc::Vec2f a = cc::Vec2f(1.0f, 2.0f);
		const cc::Vec2f b = cc::Vec2f(2.0f, 3.0f);
		const bool equal = a == a;
		Assert::IsTrue(equal);

		const bool notEqual = a != b;
		Assert::IsTrue(notEqual);
	}

	TEST_METHOD(UnaryConstantOperators) {
		const cc::Vec2f vec = randomVector();
		const cc::Vec2f neg = -vec;
		Assert::AreEqual(-vec.x, neg.x, TOLERANCE);
		Assert::AreEqual(-vec.y, neg.y, TOLERANCE);
	}

	TEST_METHOD(Magnitude) {
		const cc::Vec2f vec(1.0f, 2.0f);
		Assert::AreEqual(2.23607f, vec.magnitude(), TOLERANCE);
		Assert::AreEqual(5.0f, vec.sqrMagnitude(), TOLERANCE);
	}

	TEST_METHOD(Normalize) {
		const cc::Vec2f vec(1.0f, 2.0f);

		cc::Vec2f nrm1 = vec; nrm1.normalize();
		Assert::AreEqual(0.447214f, nrm1.x, TOLERANCE);
		Assert::AreEqual(0.894427f, nrm1.y, TOLERANCE);

		const cc::Vec2f nrm2 = vec.normalized();
		Assert::AreEqual(0.447214f, nrm2.x, TOLERANCE);
		Assert::AreEqual(0.894427f, nrm2.y, TOLERANCE);
	}

	TEST_METHOD(Equality) {
		const cc::Vec2f a(1.0f, 2.0f);
		const cc::Vec2f b(1.0f, 2.0f);
		const bool equal = a.equalTo(b);
		Assert::IsTrue(equal);
	}

	TEST_METHOD(Dot) {
		const cc::Vec2f vec(1.0f, 2.0f);
		const float dot = vec.dot(cc::Vec2f(3.0f, 4.0f));
		Assert::AreEqual(11.0f, dot, TOLERANCE);
	}

	TEST_METHOD(Cross) {
		Logger::WriteMessage("TODO: Vec2::cross3d()");
		Logger::WriteMessage("TODO: Vec2::cross2d()");
	}

	TEST_METHOD(Distance) {
		const cc::Vec2f vec(1.0f, 2.0f);
		const float distance = vec.distance(cc::Vec2f(3.0f, 4.0f));
		Assert::AreEqual(2.82843f, distance, TOLERANCE);
		const float sqrDistance = vec.sqrDistance(cc::Vec2f(3.0f, 4.0f));
		Assert::AreEqual(8.0f, sqrDistance, TOLERANCE);
	}

	TEST_METHOD(MinMax) {
		const cc::Vec2f small(1.0f, 2.0f);
		const cc::Vec2f big(10.0f, 11.0f);

		const cc::Vec2f min = small.minimum(big);
		Assert::AreEqual(1.0f, min.x, TOLERANCE);
		Assert::AreEqual(2.0f, min.y, TOLERANCE);

		const cc::Vec2f max = small.maximum(big);
		Assert::AreEqual(10.0f, max.x, TOLERANCE);
		Assert::AreEqual(11.0f, max.y, TOLERANCE);
	}

	TEST_METHOD(Lerp) {
		const cc::Vec2f a(0.0f, 0.0f);
		const cc::Vec2f b(5.0f, 10.0f);

		const cc::Vec2f zero = a.lerp(b, 0.0f);
		Assert::AreEqual(a.x, zero.x, TOLERANCE);
		Assert::AreEqual(a.y, zero.y, TOLERANCE);

		const cc::Vec2f half = a.lerp(b, 0.5f);
		Assert::AreEqual(2.5f, half.x, TOLERANCE);
		Assert::AreEqual(5.0f, half.y, TOLERANCE);

		const cc::Vec2f one = a.lerp(b, 1.0f);
		Assert::AreEqual(b.x, one.x, TOLERANCE);
		Assert::AreEqual(b.y, one.y, TOLERANCE);
	}

	TEST_METHOD(Defaults) {
		const cc::Vec2f zero = cc::Vec2f::zero();
		Assert::AreEqual(0.0f, zero.x, TOLERANCE);
		Assert::AreEqual(0.0f, zero.y, TOLERANCE);

		const cc::Vec2f one = cc::Vec2f::one();
		Assert::AreEqual(1.0f, one.x, TOLERANCE);
		Assert::AreEqual(1.0f, one.y, TOLERANCE);
	}
};
