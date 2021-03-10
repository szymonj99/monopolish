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
	constexpr float MILLISECONDS = 1000.0f;
	if (mInfo == "")
	{
		std::cout << mDuration.count() * MILLISECONDS << "\n";
		return;
	}
	std::cout << mInfo << " took " << mDuration.count() * MILLISECONDS << " ms.\n";
}