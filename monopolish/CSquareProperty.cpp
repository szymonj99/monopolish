// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#include "CSquareProperty.h"

CSquareProperty::CSquareProperty(const ESquareType kType, const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour)
{
	this->mType = kType;
	//mType = kType;
	//mName = kName;
	//mCost = kCost;
	//mRent = kRent;
	//mColour = kColour;
}

bool CSquareProperty::LandOnSquare(std::unique_ptr<CPlayer> player)
{
	return true;
}

//int32_t CSquareProperty::GetCost() const
//{
//	return mCost;
//}

//bool CSquareProperty::SetCost(const int32_t kCost)
//{
//	mCost = kCost;
//	return true;
//}
//
//int32_t CSquareProperty::GetRent() const
//{
//	return mRent;
//}
//
//bool CSquareProperty::SetRent(const int32_t kRent)
//{
//	mRent = kRent;
//	return true;
//}
//
//ESquareColour CSquareProperty::GetSquareColour() const
//{
//	return mColour;
//}
//
//bool CSquareProperty::SetSquareColour(const ESquareColour kColour)
//{
//	mColour = kColour;
//	return true;
//}
//
//std::shared_ptr<CPlayer> CSquareProperty::GetPropertyOwner() const
//{
//	return mOwner;
//}
//
//bool CSquareProperty::SetPropertyOwner(const std::shared_ptr<CPlayer> player)
//{
//	mOwner = player;
//	return true;
//}
//
//bool CSquareProperty::IsOwnedByPlayer(const std::shared_ptr<CPlayer> player)
//{
//	return mOwner == player;
//}

//bool CSquareProperty::LandOnSquare(std::unique_ptr<CPlayer> player)
//{
//	return true;
//}

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