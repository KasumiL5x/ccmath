#include "CppUnitTest.h"
#include <cc/Random.hpp>
#include <array>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(RandomTest) {
public:
	TEST_METHOD(Statics) {
		const int MIN = -1000;
		const int MAX = 1000;
		for( int i = 0; i < 1000; ++i ) {
			const int val = cc::math::Random<float, int>::rangedInt(MIN, MAX);
			if( val < MIN || val > MAX ) {
				Assert::Fail(L"Random::rangedInt result out of range.\n");
			}
		}

		const int MIN_F = -1000.0f;
		const int MAX_F = 1000.0f;
		for( int i = 0; i < 1000; ++i ) {
			const float val = cc::math::Random<float, int>::rangedReal(MIN_F, MAX_F);
			if( val < MIN_F || val > MAX_F ) {
				Assert::Fail(L"Random::rangedReal result out of range.\n");
			}
		}
	}

	TEST_METHOD(Ranges) {
		// ranged floats and ints
		cc::math::Random<float, int> RandFloatInt;
		const float MIN_FLOAT = -100.0f;
		const float MAX_FLOAT = 100.0f;
		for( int i = 0; i < 1000; ++i ) {
			const float val = RandFloatInt.nextReal(MIN_FLOAT, MAX_FLOAT);
			if( val < MIN_FLOAT || val > MAX_FLOAT ) {
				Assert::Fail(L"RandFloatInt.nextReal result out of range.\n");
			}
		}
		const int MIN_INT = -100;
		const int MAX_INT = 100;
		for( int i = 0; i < 1000; ++i ) {
			const int val = RandFloatInt.nextInt(MIN_INT, MAX_INT);
			if( val < MIN_INT || val > MAX_INT ) {
				Assert::Fail(L"RandFloatInt.nextInt result out of range.\n");
			}
		}
	}

	TEST_METHOD(Seeds) {
		const int seed = 42;

		// store two randoms' results and compare the arrays
		const int RESULTS = 1000;
		std::array<int, RESULTS> a = {};
		std::array<int, RESULTS> b = {};
		cc::math::Random<float, int> randomA(seed);
		cc::math::Random<float, int> randomB(seed);
		for( int i = 0; i < RESULTS; ++i ) {
			a[i] = randomA.nextInt();
			b[i] = randomB.nextInt();
		}

		Assert::IsTrue(a == b);
	}
};