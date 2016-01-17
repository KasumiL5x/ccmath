#include "CppUnitTest.h"
#include <cc/Vec3.hpp>
#include "Common.hpp"
#include "Random.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(Vec3Test) {
private:
	Random<float, int> rnd;

	cc::Vec3f randomVector() {
		return cc::Vec3f(rnd.nextReal(), rnd.nextReal(), rnd.nextReal());
	}

public:
	TEST_METHOD(Constructor) {
		const cc::Vec3f blank;
		Assert::AreEqual(0.0f, blank.x, TOLERANCE);
		Assert::AreEqual(0.0f, blank.y, TOLERANCE);
		Assert::AreEqual(0.0f, blank.z, TOLERANCE);

		const float rnd_a = rnd.nextReal();
		const cc::Vec3f single(rnd_a);
		Assert::AreEqual(rnd_a, single.x, TOLERANCE);
		Assert::AreEqual(rnd_a, single.y, TOLERANCE);
		Assert::AreEqual(rnd_a, single.z, TOLERANCE);

		const float rnd_b = rnd.nextReal();
		const float rnd_c = rnd.nextReal();
		const cc::Vec3f triple(rnd_a, rnd_b, rnd_c);
		Assert::AreEqual(rnd_a, triple.x, TOLERANCE);
		Assert::AreEqual(rnd_b, triple.y, TOLERANCE);
		Assert::AreEqual(rnd_c, triple.z, TOLERANCE);

		const cc::Vec3f copy(triple);
		Assert::AreEqual(triple.x, copy.x, TOLERANCE);
		Assert::AreEqual(triple.y, copy.y, TOLERANCE);
		Assert::AreEqual(triple.z, copy.z, TOLERANCE);
	}

	TEST_METHOD(Accessors) {
		const float rnd_a = rnd.nextReal();
		const float rnd_b = rnd.nextReal();
		const float rnd_c = rnd.nextReal();

		const cc::Vec3f vec1(rnd_a, rnd_b, rnd_c);
		Assert::AreEqual(rnd_a, vec1[0], TOLERANCE);
		Assert::AreEqual(rnd_b, vec1[1], TOLERANCE);
		Assert::AreEqual(rnd_c, vec1[2], TOLERANCE);
		Assert::AreEqual(rnd_a, vec1(0), TOLERANCE);
		Assert::AreEqual(rnd_b, vec1(1), TOLERANCE);
		Assert::AreEqual(rnd_c, vec1(2), TOLERANCE);

		cc::Vec3f vec2(rnd_a, rnd_b, rnd_c);
		Assert::AreEqual(rnd_a, vec2[0], TOLERANCE);
		Assert::AreEqual(rnd_b, vec2[1], TOLERANCE);
		Assert::AreEqual(rnd_c, vec2[2], TOLERANCE);
		Assert::AreEqual(rnd_a, vec2(0), TOLERANCE);
		Assert::AreEqual(rnd_b, vec2(1), TOLERANCE);
		Assert::AreEqual(rnd_c, vec2(2), TOLERANCE);
	}

	TEST_METHOD(UnaryOperators) {
		const cc::Vec3f vec = randomVector();

		// =
		cc::Vec3f equals; equals = vec;
		Assert::AreEqual(vec.x, equals.x, TOLERANCE);
		Assert::AreEqual(vec.y, equals.y, TOLERANCE);
		Assert::AreEqual(vec.z, equals.z, TOLERANCE);

		// +=
		cc::Vec3f plusEquals; plusEquals += vec;
		Assert::AreEqual(vec.x, plusEquals.x, TOLERANCE);
		Assert::AreEqual(vec.y, plusEquals.y, TOLERANCE);
		Assert::AreEqual(vec.z, plusEquals.z, TOLERANCE);

		// -=
		cc::Vec3f minusEquals; minusEquals -= vec;
		Assert::AreEqual(-vec.x, minusEquals.x, TOLERANCE);
		Assert::AreEqual(-vec.y, minusEquals.y, TOLERANCE);
		Assert::AreEqual(-vec.z, minusEquals.z, TOLERANCE);

		// *=
		cc::Vec3f mulEquals(3.0f); mulEquals *= vec;
		Assert::AreEqual(vec.x*3.0f, mulEquals.x, TOLERANCE);
		Assert::AreEqual(vec.y*3.0f, mulEquals.y, TOLERANCE);
		Assert::AreEqual(vec.z*3.0f, mulEquals.z, TOLERANCE);

		// /=
		cc::Vec3f divEquals(3.0f); divEquals /= vec;
		Assert::AreEqual(3.0f/vec.x, divEquals.x, TOLERANCE);
		Assert::AreEqual(3.0f/vec.y, divEquals.y, TOLERANCE);
		Assert::AreEqual(3.0f/vec.z, divEquals.z, TOLERANCE);
	}

	TEST_METHOD(BinaryOperators) {
		const cc::Vec3f vec1 = randomVector();
		const cc::Vec3f vec2 = randomVector();
		const float scalar = rnd.nextReal();

		// vec + vec
		const cc::Vec3f vecPlusVec = vec1 + vec2;
		Assert::AreEqual(vec1.x+vec2.x, vecPlusVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y+vec2.y, vecPlusVec.y, TOLERANCE);
		Assert::AreEqual(vec1.z+vec2.z, vecPlusVec.z, TOLERANCE);
		// scalar + vec
		const cc::Vec3f sclPlusVec = scalar + vec1;
		Assert::AreEqual(scalar+vec1.x, sclPlusVec.x, TOLERANCE);
		Assert::AreEqual(scalar+vec1.y, sclPlusVec.y, TOLERANCE);
		Assert::AreEqual(scalar+vec1.z, sclPlusVec.z, TOLERANCE);
		// vec + scalar
		const cc::Vec3f vecPlusScl = vec1 + scalar;
		Assert::AreEqual(vec1.x+scalar, vecPlusScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y+scalar, vecPlusScl.y, TOLERANCE);
		Assert::AreEqual(vec1.z+scalar, vecPlusScl.z, TOLERANCE);

		// vec - vec
		const cc::Vec3f vecMinVec = vec1 - vec2;
		Assert::AreEqual(vec1.x-vec2.x, vecMinVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y-vec2.y, vecMinVec.y, TOLERANCE);
		Assert::AreEqual(vec1.z-vec2.z, vecMinVec.z, TOLERANCE);
		// scalar - vec
		const cc::Vec3f sclMinVec = scalar - vec1;
		Assert::AreEqual(scalar-vec1.x, sclMinVec.x, TOLERANCE);
		Assert::AreEqual(scalar-vec1.y, sclMinVec.y, TOLERANCE);
		Assert::AreEqual(scalar-vec1.z, sclMinVec.z, TOLERANCE);
		// vec - scalar
		const cc::Vec3f vecMinScl = vec1 - scalar;
		Assert::AreEqual(vec1.x-scalar, vecMinScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y-scalar, vecMinScl.y, TOLERANCE);
		Assert::AreEqual(vec1.z-scalar, vecMinScl.z, TOLERANCE);

		// vec * vec
		const cc::Vec3f vecMulVec = vec1 * vec2;
		Assert::AreEqual(vec1.x*vec2.x, vecMulVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y*vec2.y, vecMulVec.y, TOLERANCE);
		Assert::AreEqual(vec1.z*vec2.z, vecMulVec.z, TOLERANCE);
		// scalar * vec
		const cc::Vec3f sclMulVec = scalar * vec1;
		Assert::AreEqual(scalar*vec1.x, sclMulVec.x, TOLERANCE);
		Assert::AreEqual(scalar*vec1.y, sclMulVec.y, TOLERANCE);
		Assert::AreEqual(scalar*vec1.z, sclMulVec.z, TOLERANCE);
		// vec * scalar
		const cc::Vec3f vecMulScl = vec1 * scalar;
		Assert::AreEqual(vec1.x*scalar, vecMulScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y*scalar, vecMulScl.y, TOLERANCE);
		Assert::AreEqual(vec1.z*scalar, vecMulScl.z, TOLERANCE);

		// vec / vec
		const cc::Vec3f vecDivVec = vec1 / vec2;
		Assert::AreEqual(vec1.x/vec2.x, vecDivVec.x, TOLERANCE);
		Assert::AreEqual(vec1.y/vec2.y, vecDivVec.y, TOLERANCE);
		Assert::AreEqual(vec1.z/vec2.z, vecDivVec.z, TOLERANCE);
		// scalar / vec
		const cc::Vec3f sclDivVec = scalar / vec1;
		Assert::AreEqual(scalar/vec1.x, sclDivVec.x, TOLERANCE);
		Assert::AreEqual(scalar/vec1.y, sclDivVec.y, TOLERANCE);
		Assert::AreEqual(scalar/vec1.z, sclDivVec.z, TOLERANCE);
		// vec / scalar
		const cc::Vec3f vecDivScl = vec1 / scalar;
		Assert::AreEqual(vec1.x/scalar, vecDivScl.x, TOLERANCE);
		Assert::AreEqual(vec1.y/scalar, vecDivScl.y, TOLERANCE);
		Assert::AreEqual(vec1.z/scalar, vecDivScl.z, TOLERANCE);
	}

	TEST_METHOD(UnaryConstantOperator) {
		const cc::Vec3f vec = randomVector();
		const cc::Vec3f neg = -vec;
		Assert::AreEqual(-vec.x, neg.x, TOLERANCE);
		Assert::AreEqual(-vec.y, neg.y, TOLERANCE);
		Assert::AreEqual(-vec.z, neg.z, TOLERANCE);
	}

	TEST_METHOD(Magnitude) {
		const cc::Vec3f vec(1.0f, 2.0f, 3.0f);
		Assert::AreEqual(3.74166f, vec.magnitude(), TOLERANCE);
		Assert::AreEqual(14.0f, vec.sqrMagnitude(), TOLERANCE);
	}

	TEST_METHOD(Normalize) {
		const cc::Vec3f vec(1.0f, 2.0f, 3.0f);

		cc::Vec3f nrm1 = vec; nrm1.normalize();
		Assert::AreEqual(0.267261f, nrm1.x, TOLERANCE);
		Assert::AreEqual(0.534522f, nrm1.y, TOLERANCE);
		Assert::AreEqual(0.801784f, nrm1.z, TOLERANCE);

		const cc::Vec3f nrm2 = vec.normalized();
		Assert::AreEqual(0.267261f, nrm2.x, TOLERANCE);
		Assert::AreEqual(0.534522f, nrm2.y, TOLERANCE);
		Assert::AreEqual(0.801784f, nrm2.z, TOLERANCE);
	}

	TEST_METHOD(Equality) {
		const cc::Vec3f a(1.0f, 2.0f, 3.0f);
		const cc::Vec3f b(1.0f, 2.0f, 3.0f);
		const bool equal = a.equalTo(b);
		Assert::IsTrue(equal);
	}

	TEST_METHOD(Dot) {
		const cc::Vec3f a(0.267261f, 0.534522f, 0.801784f);
		const cc::Vec3f b(0.717137f, 0.358569f, 0.597614f);
		const float dp = a.dot(b);
		Assert::AreEqual(0.862483114151f, dp, TOLERANCE);
	}

	TEST_METHOD(Cross) {
		const cc::Vec3f a(0.267261f, 0.534522f, 0.801784f);
		const cc::Vec3f b(0.717137f, 0.358569f, 0.597614f);
		const cc::Vec3f cross = a.cross(b);
		Assert::AreEqual(0.0319429f, cross.x, TOLERANCE);
		Assert::AreEqual(0.41527f, cross.y, TOLERANCE);
		Assert::AreEqual(-0.287494f, cross.z, TOLERANCE);
	}

	TEST_METHOD(Distance) {
		const cc::Vec3f a(1.0f, 2.0f, 3.0f);
		const cc::Vec3f b(4.0f, 5.0f, 6.0f);
		Assert::AreEqual(5.19615f, a.distance(b), TOLERANCE);
		Assert::AreEqual(27.0f, a.sqrDistance(b), TOLERANCE);
	}

	TEST_METHOD(MinMax) {
		const cc::Vec3f small(1.0f, 2.0f, 3.0f);
		const cc::Vec3f big(10.0f, 11.0f, 12.0f);

		const cc::Vec3f min = small.minimum(big);
		Assert::AreEqual(1.0f, min.x, TOLERANCE);
		Assert::AreEqual(2.0f, min.y, TOLERANCE);
		Assert::AreEqual(3.0f, min.z, TOLERANCE);

		const cc::Vec3f max = small.maximum(big);
		Assert::AreEqual(10.0f, max.x, TOLERANCE);
		Assert::AreEqual(11.0f, max.y, TOLERANCE);
		Assert::AreEqual(12.0f, max.z, TOLERANCE);
	}

	TEST_METHOD(Lerp) {
		const cc::Vec3f a(0.0f, 0.0f, 0.0f);
		const cc::Vec3f b(5.0f, 10.0f, 15.0f);

		const cc::Vec3f zero = a.lerp(b, 0.0f);
		Assert::AreEqual(a.x, zero.x, TOLERANCE);
		Assert::AreEqual(a.y, zero.y, TOLERANCE);
		Assert::AreEqual(a.z, zero.z, TOLERANCE);

		const cc::Vec3f half = a.lerp(b, 0.5f);
		Assert::AreEqual(2.5f, half.x, TOLERANCE);
		Assert::AreEqual(5.0f, half.y, TOLERANCE);
		Assert::AreEqual(7.5f, half.z, TOLERANCE);

		const cc::Vec3f one = a.lerp(b, 1.0f);
		Assert::AreEqual(b.x, one.x, TOLERANCE);
		Assert::AreEqual(b.y, one.y, TOLERANCE);
		Assert::AreEqual(b.z, one.z, TOLERANCE);
	}

	TEST_METHOD(Reflect) {
		Logger::WriteMessage("TODO: Vec3::reflect()");
	}

	TEST_METHOD(Defaults) {
		const cc::Vec3f zero = cc::Vec3f::zero();
		Assert::AreEqual(0.0f, zero.x, TOLERANCE);
		Assert::AreEqual(0.0f, zero.y, TOLERANCE);
		Assert::AreEqual(0.0f, zero.z, TOLERANCE);

		const cc::Vec3f one = cc::Vec3f::one();
		Assert::AreEqual(1.0f, one.x, TOLERANCE);
		Assert::AreEqual(1.0f, one.y, TOLERANCE);
		Assert::AreEqual(1.0f, one.z, TOLERANCE);

		const cc::Vec3f up = cc::Vec3f::up();
		Assert::AreEqual(0.0f, up.x, TOLERANCE);
		Assert::AreEqual(1.0f, up.y, TOLERANCE);
		Assert::AreEqual(0.0f, up.x, TOLERANCE);

		const cc::Vec3f down = cc::Vec3f::down();
		Assert::AreEqual(0.0f, down.x, TOLERANCE);
		Assert::AreEqual(-1.0f, down.y, TOLERANCE);
		Assert::AreEqual(0.0f, down.z, TOLERANCE);

		const cc::Vec3f left = cc::Vec3f::left();
		Assert::AreEqual(-1.0f, left.x, TOLERANCE);
		Assert::AreEqual(0.0f, left.y, TOLERANCE);
		Assert::AreEqual(0.0f, left.z, TOLERANCE);

		const cc::Vec3f right = cc::Vec3f::right();
		Assert::AreEqual(1.0f, right.x, TOLERANCE);
		Assert::AreEqual(0.0f, right.y, TOLERANCE);
		Assert::AreEqual(0.0f, right.z, TOLERANCE);

		const cc::Vec3f forward = cc::Vec3f::forward();
		Assert::AreEqual(0.0f, forward.x, TOLERANCE);
		Assert::AreEqual(0.0f, forward.y, TOLERANCE);
		Assert::AreEqual(-1.0f, forward.z, TOLERANCE);

		const cc::Vec3f backward = cc::Vec3f::backward();
		Assert::AreEqual(0.0f, backward.x, TOLERANCE);
		Assert::AreEqual(0.0f, backward.y, TOLERANCE);
		Assert::AreEqual(1.0f, backward.z, TOLERANCE);
	}
};
