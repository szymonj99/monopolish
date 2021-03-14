// Szymon Janusz G20792986

#pragma once
#include <iostream>
#include <chrono>
#include <string>

#include "MyTypeDefs.h"

class CTimer
{
private:
	MyTypes::TimePoint_T mStart, mEnd;
	MyTypes::Duration_T mDuration;
	std::string mInfo;

public:
	CTimer(const std::string& kInfo);
	CTimer();
	~CTimer();
};