// Szymon Janusz G20792986

#pragma once
#include <string>
#include <memory>
#include "CMonopolish.h"
#include "CPiece.h"
#include "random.h"
#include <vector>
#include "Constants.h"
#include "CSquare.h"

using GlobalConstants::ESquareColour;

class CMonopolish;
class CSquare;

class CPlayer
{
private:
	std::shared_ptr<CPiece> mPiece = nullptr;
	int64_t mMoney = 1500;
	int32_t mPosition = 0;
	bool mIsBankrupt = false;
	std::vector<uint32_t> mOwnedPropertiesIndexes;
	std::vector<uint32_t> mCountOfOwnedPropertiesByColour;

public:
	CPlayer(const std::string kPieceName, const int64_t kMoney = 1500, const int32_t kPosition = 0);
	CPlayer(const std::shared_ptr<CPiece> kPiece, const int64_t kMoney = 1500, const int32_t kPosition = 0);
	bool SubtractMoney(const int64_t kMoney);
	bool AddMoney(const int64_t kMoney);
	int64_t GetMoney() const;
	uint32_t RollNumber() const;
	std::string GetName() const;
	bool MoveForward(const uint32_t kRoll);
	int32_t GetPosition() const;
	bool PassGo(const int32_t kNewPosition);
	bool SetPosition(const int32_t kPosition);
	bool GoToJail();
	bool SetBankrupt();
	bool ClearOwnedProperties();
	bool AddOwnedPropertyIndex(const uint32_t kIndex);
	uint32_t GetOwnedColouredPropertyCount(const ESquareColour kColour) const;
	bool ManageMortgage(CMonopolish* gameManager);
	bool UnownAllProperties(std::vector<std::shared_ptr<CSquare>>& allSquares);
	bool UnmortgageAllProperties(std::vector<std::shared_ptr<CSquare>>& allSquares);
};