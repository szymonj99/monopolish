// Szymon Janusz G20792986

#pragma once
#include <string>
#include <memory>
#include "CPiece.h"
#include "random.h"
#include "Constants.h"

using GlobalConstants::ESquareColour;

class CPlayer
{
private:
	std::shared_ptr<CPiece> mPiece = nullptr;
	int64_t mMoney = 1500;
	int32_t mPosition = 0;

public:
	CPlayer(const std::string kPieceName, const int64_t kMoney = 1500, const int32_t kPosition = 0);
	CPlayer(const std::shared_ptr<CPiece> kPiece, const int64_t kMoney = 1500, const int32_t kPosition = 0);
	bool SetPiece(const std::shared_ptr<CPiece> kPiece);
	std::shared_ptr<CPiece> GetPiece() const;
	bool SubtractMoney(const int64_t kMoney);
	bool AddMoney(const int64_t kMoney);
	bool SetMoney(const int64_t kMoney);
	int64_t GetMoney() const;
	uint32_t RollNumber() const;
	std::string GetName() const;
	bool MoveForward(const uint32_t kRoll);
	int32_t GetPosition() const;
	bool PassGo(const int32_t kNewPosition);
	bool SetPosition(const int32_t kPosition);
	bool GoToJail();
	bool OwnsAllPropertiesOfColour(const ESquareColour kColour) const;
};