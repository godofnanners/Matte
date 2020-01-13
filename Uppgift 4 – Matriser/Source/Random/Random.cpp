#include "Random.hpp"
namespace CommonUtilities
{
	std::mt19937 rndEngine(globalSeed);
	float GetRandomFloat(float aMin, float aMax)
	{
		std::uniform_real_distribution<float> rnd(aMin, aMax);
		return rnd(rndEngine);
	}
	double GetRandomDouble(double aMin, double aMax)
	{
		std::uniform_real_distribution<double> rnd(aMin, aMax);
		return rnd(rndEngine);
	}
	int GetRandomInt(int aMin, int aMax)
	{
		std::uniform_int_distribution<int> rnd(aMin, aMax);
		return rnd(rndEngine);
	}
}