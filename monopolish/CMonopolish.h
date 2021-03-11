// Szymon Janusz G20792986

#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "CSquare.h"
#include "Constants.h"

class CMonopolish
{
private:
	int32_t mCurrentRound = 0;
	std::vector<std::shared_ptr<CSquare>> mSquares;

public:
	bool StartGame();
	bool LoadSquares(const std::string& kFileName);
};