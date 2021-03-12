// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquare.h"

CSquare::CSquare(const ESquareType kType, const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour)
{
	mType = kType;
	mName = kName;
	mCost = kCost;
	mRent = kRent;
	mColour = kColour;
}

// Set the square's type.
bool CSquare::SetType(const ESquareType kType)
{
	mType = kType;
	return true;
}

// Set the square's type.
ESquareType CSquare::GetType() const
{
	return mType;
}

// Get the square's name.
std::string CSquare::GetName() const
{
	return mName;
}

// Set the square's name.
bool CSquare::SetName(const std::string& kName)
{
	mName = kName;
	return true;
}

int32_t CSquare::GetCost() const
{
	return mCost;
}

bool CSquare::SetCost(const int32_t kCost)
{
	mCost = kCost;
	return true;
}

int32_t CSquare::GetRent() const
{
	return mRent;
}

bool CSquare::SetRent(const int32_t kRent)
{
	mRent = kRent;
	return true;
}

ESquareColour CSquare::GetSquareColour() const
{
	return mColour;
}

bool CSquare::SetSquareColour(const ESquareColour kColour)
{
	mColour = kColour;
	return true;
}

std::shared_ptr<CPlayer> CSquare::GetPropertyOwner() const
{
	return mOwner;
}

bool CSquare::SetPropertyOwner(const std::shared_ptr<CPlayer> player)
{
	mOwner = player;
	return true;
}

bool CSquare::IsOwnedByPlayer(const std::shared_ptr<CPlayer> player)
{
	return mOwner == player;
}

bool CSquare::LandOnSquare(std::shared_ptr<CPlayer> player)
{
	std::cout << player->GetName() << " lands on " << mName << std::endl;
	return true;
}