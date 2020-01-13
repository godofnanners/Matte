
#pragma once

#include <chrono>

namespace alib
{
	namespace core
	{
		class Timer
		{
		public:

		private:
			std::chrono::high_resolution_clock::time_point myLastTimePoint;
			std::chrono::duration<double> myDeltaTime;
			double myTotalTime;
		public:

			Timer& operator = (const Timer& aTimer) = delete;

			void Update()
			{
				std::chrono::high_resolution_clock::time_point currentTimePoint = std::chrono::high_resolution_clock::now();
				myDeltaTime = (currentTimePoint - myLastTimePoint);
				myTotalTime += myDeltaTime.count();
				myLastTimePoint = currentTimePoint;
			}

			float GetDeltaTime() const
			{
				return static_cast<float>(myDeltaTime.count());
			}

			double GetTotalTime() const
			{
				return myTotalTime;
			}

			Timer() : myTotalTime(0.0f), myDeltaTime(0.0f)
			{
				myLastTimePoint = std::chrono::high_resolution_clock::now();
			}

			Timer(const Timer& aTimer) = delete;
		};
	}

	using Timer = core::Timer;
}

