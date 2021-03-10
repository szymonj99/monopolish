// Szymon Janusz G20792986

#include "CSquareProperty.h"

CSquareProperty::CSquareProperty(const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour)
{
	mName = kName;
	mCost = kCost;
	mRent = kRent;
	mColour = kColour;
}

const std::string& CSquareProperty::GetName() const
{
	return mName;
}

const bool CSquareProperty::SetName(const std::string& kName)
{
	mName = kName;
	return true;
}

const int32_t CSquareProperty::GetCost() const
{
	return mCost;
}

const bool CSquareProperty::SetCost(const int32_t kCost)
{
	mCost = kCost;
	return true;
}

const int32_t CSquareProperty::GetRent() const
{
	return mRent;
}

const bool CSquareProperty::SetRent(const int32_t kRent)
{
	mRent = kRent;
	return true;
}

const ESquareColour CSquareProperty::GetSquareColour() const
{
	return mColour;
}

const bool CSquareProperty::SetSquareColour(const ESquareColour kColour)
{
	mColour = kColour;
	return true;
}

const std::shared_ptr<CPlayer> CSquareProperty::GetPropertyOwner() const
{
	return mOwner;
}

const bool CSquareProperty::SetPropertyOwner(const std::shared_ptr<CPlayer> player)
{
	mOwner = player;
	return true;
}

const bool CSquareProperty::IsOwnedByPlayer(const std::shared_ptr<CPlayer> player)
{
	return mOwner == player;
}


//const bool CSquareProperty::LandOnSquare(std::unique_ptr<CPlayer> player)
//{
//	// If !propertyOwned
//	// player.buyProperty(this);
//	// Either tryBuyProperty(this), where TryBuyProperty checks player's funds
//	// Or check player funds here, and only then BuyProperty;
//	// 
//
//	// If PropertyOwnedByPlayer(player)
//	// nothing happens
//
//	// If PropertyOwnedButNotByPlayer(player)
//	// player.PayRentToPlayer(this.GetOwnerPtr());
//	return true;
//}



// Check if nullptr
// Check if owned 