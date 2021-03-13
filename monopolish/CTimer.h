// Szymon Janusz G20792986

#pragma once
#include <iostream>
#include <chrono>
#include <string>

class CTimer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> mStart, mEnd;
	std::chrono::duration<float> mDuration;
	std::string mInfo;

public:
	CTimer(const std::string& kInfo);
	CTimer();
	~CTimer();
};