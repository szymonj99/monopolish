// Szymon Janusz G20792986

#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "CSquare.h"
#include "Constants.h"

class CSquare;
class CPlayer;

class CMonopolish
{
private:
	int32_t mCurrentRound = 0;
	using mSquaresVector_T = std::vector<std::shared_ptr<CSquare>>;
	mSquaresVector_T mSquares;
	using mPlayersVector_T = std::vector<std::shared_ptr<CPlayer>>;
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
	mSquaresVector_T GetVectorOfAllSquares();
};