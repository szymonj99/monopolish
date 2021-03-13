// Szymon Janusz G20792986

#include "CTimer.h"

CTimer::CTimer(const std::string& kInfo)
{
	mInfo = kInfo;
	mStart = std::chrono::high_resolution_clock::now();
}

CTimer::CTimer()
{
	mStart = std::chrono::high_resolution_clock::now();
}

CTimer::~CTimer()
{
	mEnd = std::chrono::high_resolution_clock::now();
	mDuration = mEnd - mStart;

	// Get duration value in milliseconds
	constexpr float kMilliseconds = 1000.0f;
	if (!mInfo.empty())
	{
		std::cout << mDuration.count() * kMilliseconds << "\n";
		return;
	}
	std::cout << mInfo << " took " << mDuration.count() * kMilliseconds << " ms.\n";
}