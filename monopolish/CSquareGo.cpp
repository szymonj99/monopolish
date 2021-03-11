// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareGo.h"

CSquareGo::CSquareGo(const ESquareType kType, const std::string& kName)
{
	mName = kName;
	mType = kType;
}