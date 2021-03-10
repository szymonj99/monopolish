// Szymon Janusz G20792986

#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "ISquare.h"
#include "Constants.h"

class CMonopolish
{
private:
	int32_t mCurrentRound = 0;

public:
	const bool StartGame();
	std::vector<std::unique_ptr<ISquare>> LoadSquares(const std::string& kFileName);
};