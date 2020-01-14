#include"..\\Test\pch.h"
#include "Random/Random.hpp"

using namespace CommonUtilities;
static std::mt19937 rndEngine(6);
float Random::GetRandomFloat(float aMin, float aMax)
{
	std::uniform_real_distribution<float> rnd(aMin, aMax);
	return rnd(rndEngine);
}
double Random::GetRandomDouble(double aMin, double aMax)
{
	std::uniform_real_distribution<double> rnd(aMin, aMax);
	return rnd(rndEngine);
}
int Random::GetRandomInt(int aMin, int aMax)
{
	std::uniform_int_distribution<int> rnd(aMin, aMax);
	return rnd(rndEngine);
}
