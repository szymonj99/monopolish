// Szymon Janusz G20792986

#pragma once
#include "CSquare.h"

class CSquareGo : protected CSquare
{
public:
	CSquareGo(const ESquareType kType, const std::string& kName);
};
