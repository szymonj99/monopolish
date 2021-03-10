// Szymon Janusz G20792986

#pragma once
#include "ISquare.h"
#include "Constants.h"

using GlobalConstants::ESquareColour;

class CSquareProperty : public ISquare
{
private:
	std::string mName = "";
	int32_t mCost = 0;
	int32_t mRent = 0;
	ESquareColour mColour = ESquareColour::NONE;
	std::shared_ptr<CPlayer> mOwner = nullptr;
	CSquareProperty() {}; // We will never use default constructor.

public:
	CSquareProperty(const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour);
	~CSquareProperty() {};
	const std::string& GetName() const;
	const bool SetName(const std::string& kName);
	const int32_t GetCost() const;
	const bool SetCost(const int32_t kCost);
	const int32_t GetRent() const;
	const bool SetRent(const int32_t kRent);
	const ESquareColour GetSquareColour() const;
	const bool SetSquareColour(const ESquareColour kColour);
	const std::shared_ptr<CPlayer> GetPropertyOwner() const;
	const bool SetPropertyOwner(std::shared_ptr<CPlayer> player);
	const bool IsOwnedByPlayer(const std::shared_ptr<CPlayer> player);
	//const bool LandOnSquare(std::unique_ptr<CPlayer> player);
	
	
	
};

