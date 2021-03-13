// Szymon Janusz G20792986

#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <chrono>

#include "CSquare.h"
#include "CPlayer.h"
#include "CSquareProperty.h"
#include "CSquareBonus.h"
#include "CSquarePenalty.h"
#include "CTimer.h"

namespace MyTypes
{
	typedef std::vector<std::shared_ptr<CSquare>> SquaresVector_T;
	typedef std::vector<std::shared_ptr<CPlayer>> PlayersVector_T;
	typedef std::vector<std::pair<std::string, int32_t>> BonusesVector_T;
	typedef std::pair<std::string, int32_t> Bonus_T;
	typedef std::vector<std::pair<std::string, int32_t>> PenaltiesVector_T;
	typedef std::pair<std::string, int32_t> Penalty_T;
	typedef int64_t Money_T;
	typedef int32_t  PlayerNum_T;
	typedef int32_t PlayerPos_T;
	typedef int64_t Seed_T;
	typedef uint32_t Roll_T;
	typedef int32_t Rent_T;
	typedef int32_t Cost_T;

	// Timer things.
	typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint_T;
	typedef std::chrono::duration<float> Duration_T;
}