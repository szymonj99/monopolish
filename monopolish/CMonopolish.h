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
	// Vector of vectors.
	// First vector contains vectors of coloured properties.
	// EG. Vector{Red Properties{Red Road, Red Street}, Yellow Properties{Yellow Road, Yellow Street}} 
	using mVectorOfSquareVectors_T = std::vector<std::vector<std::shared_ptr<CSquare>>>;
	
	using mSquaresVector_T = std::vector<std::shared_ptr<CSquare>>;
	using mPlayersVector_T = std::vector<std::shared_ptr<CPlayer>>;
	int32_t mCurrentRound = 0;
	mSquaresVector_T mSquares;
	mPlayersVector_T mPlayers;

public:
	bool PrintWelcomeMessage();
	int64_t GetSeed(const std::string& kSeedFile);
	bool SetUpRandom();
	bool StartGame();
	bool LoadSquares(const std::string& kFileName);
	bool SetUpPlayers();
	bool PlayGame();
	std::string GetWinningPlayer() const;
};