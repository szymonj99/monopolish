// Szymon Janusz G20792986

#include "CPlayer.h"
#include "Constants.h"
#include <algorithm>

CPlayer::CPlayer(const std::string kPieceName, const int64_t kMoney, const int32_t kPosition)
{
	mPiece = std::make_shared<CPiece>(kPieceName);
	mMoney = kMoney;
	mPosition = kPosition;

	for (int32_t i = 0; i < (int32_t)ESquareColour::TotalColours; i++)
	{
		mCountOfOwnedPropertiesByColour.push_back(0);
	}
}

CPlayer::CPlayer(const std::shared_ptr<CPiece> kPiece, const int64_t kMoney, const int32_t kPosition)
{
	mPiece = kPiece;
	mMoney = kMoney;
	mPosition = kPosition;
}

uint32_t CPlayer::RollNumber() const
{
	return Random();
}

std::string CPlayer::GetName() const
{
	return mPiece->GetName();
}

bool CPlayer::PassGo(const int32_t kNewPosition)
{
	mMoney += GlobalConstants::kGO_COLLECTION;
	mPosition = kNewPosition;
	std::cout << GetName() << " passes GO and collects " << GlobalConstants::kPOUND_SIGN << GlobalConstants::kGO_COLLECTION << std::endl;
	return true;
}

bool CPlayer::MoveForward(const uint32_t kRoll)
{
	mPosition += kRoll;
	if (mPosition >= GlobalConstants::kNUMBER_OF_SQUARES)
	{
		PassGo(mPosition % GlobalConstants::kNUMBER_OF_SQUARES);
	}
	return true;
}

int32_t CPlayer::GetPosition() const
{
	return mPosition;
}

int64_t CPlayer::GetMoney() const
{
	return mMoney;
}

bool CPlayer::SubtractMoney(const int64_t kMoney)
{
	mMoney -= kMoney;
	return true;
}

bool CPlayer::AddMoney(const int64_t kMoney)
{
	mMoney += kMoney;
	return true;
}

bool CPlayer::SetPosition(const int32_t kPosition)
{
	mPosition = kPosition;
	return true;
}

bool CPlayer::GoToJail()
{
	// Change this to a meaningful number rather than hard-coded 6.
	const int32_t kJailPosition = 6;
	// How do I get the jail index?
	SetPosition(kJailPosition);
	return true;
}

bool CPlayer::SetBankrupt()
{
	mIsBankrupt = true;
	return true;
}

bool CPlayer::ClearOwnedProperties()
{
	mOwnedPropertiesIndexes.clear();
	return true;
}

bool CPlayer::AddOwnedPropertyIndex(const uint32_t kIndex)
{
	mOwnedPropertiesIndexes.push_back(kIndex);
	return true;
}

uint32_t CPlayer::GetOwnedColouredPropertyCount(const ESquareColour kColour) const
{
	return mCountOfOwnedPropertiesByColour.at((int32_t)kColour);
}

bool CPlayer::IncrementColouredPropertyCount(const ESquareColour kColour)
{
	mCountOfOwnedPropertiesByColour.at((int32_t)kColour)++;
	return true;
}

// I don't think this method is as well-written as it could be.
// Honestly, it's quite a mess.
bool CPlayer::ManageMortgage(CMonopolish* gameManager)
{
	// Only try managing the mortgage if player's money is below 0
	if (GetMoney() < 0)
	{
		std::cout << this->GetName() << " is mortgaging properties..." << std::endl;
		// Maybe start by creating vector that stores all properties
		auto allProperties = gameManager->GetVectorOfAllSquares();

		using VectorOfProperties_T = std::vector<std::shared_ptr<CSquare>>;

		VectorOfProperties_T unmortgagedOwnedProperties;
		unmortgagedOwnedProperties.reserve(mOwnedPropertiesIndexes.size());

		for (uint32_t index = 0; index < mOwnedPropertiesIndexes.size(); index++)
		{
			if (!allProperties.at(mOwnedPropertiesIndexes.at(index))->IsMortgaged())
			{
				unmortgagedOwnedProperties.push_back(allProperties.at(mOwnedPropertiesIndexes.at(index)));
			}		
		}

		std::sort(unmortgagedOwnedProperties.begin(), unmortgagedOwnedProperties.end(), [](const std::shared_ptr<CSquare>& lhs, const std::shared_ptr<CSquare>& rhs) {
			return lhs->GetCost() < rhs->GetCost(); });

		// Check if the player can actually reach positive balance if they were to mortgage
		int64_t runningTotal = 0;
		uint32_t propertiesMortgaged = 0;
		bool canMortgage = false;
		for (uint32_t index = 0; index < unmortgagedOwnedProperties.size(); index++)
		{
			propertiesMortgaged++;
			runningTotal += unmortgagedOwnedProperties.at(index)->GetCost();	
			if ((GetMoney() + runningTotal) > 0)
			{
				canMortgage = true;
				break;
			}
		}
		if (!canMortgage)
		{
			return false;
		}

		// We can mortgage the properties.
		for (uint32_t index = 0; index < propertiesMortgaged; index++)
		{
			unmortgagedOwnedProperties.at(index)->SetMortgaged(true);
			this->AddMoney(unmortgagedOwnedProperties.at(index)->GetCost());
			std::cout << this->GetName() << " mortgages " << unmortgagedOwnedProperties.at(index)->GetName() << " for " << GlobalConstants::kPOUND_SIGN << unmortgagedOwnedProperties.at(index)->GetCost() << std::endl;
			std::cout << this->GetName() << " has " << GlobalConstants::kPOUND_SIGN << this->GetMoney() << std::endl;
		}
		return true;
	}

	// Otherwise, see if we can pay off the mortgage on properties that the player has mortgaged.
	if (GetMoney() > 0)
	{
		// Maybe start by creating vector that stores all properties
		auto allProperties = gameManager->GetVectorOfAllSquares();

		using VectorOfProperties_T = std::vector<std::shared_ptr<CSquare>>;
		VectorOfProperties_T mortgagedProperties;

		// I have indexes of owned properties by the player
		for (uint32_t index = 0; index < mOwnedPropertiesIndexes.size(); index++)
		{
			//ownedProperties
			if (allProperties.at(mOwnedPropertiesIndexes.at(index))->IsMortgaged())
			{
				mortgagedProperties.push_back(allProperties.at(mOwnedPropertiesIndexes.at(index)));
			}
		}

		if (mortgagedProperties.size() == 0)
		{
			return true;
		}

		// Sort in Ascending order of property cost
		std::sort(mortgagedProperties.begin(), mortgagedProperties.end(), [](const std::shared_ptr<CSquare>& lhs, const std::shared_ptr<CSquare>& rhs) {
			return lhs->GetCost() < rhs->GetCost(); });

		for (auto& square : mortgagedProperties)
		{
			if (GetMoney() - square->GetCost() > 0)
			{
				std::cout << GetName() << " unmortgages " << square->GetName() << " for " << GlobalConstants::kPOUND_SIGN << square->GetCost() << std::endl;
				square->SetMortgaged(false);
				SubtractMoney(square->GetCost());
				std::cout << GetName() << " has " << GlobalConstants::kPOUND_SIGN << GetMoney() << std::endl;
			}
			else
			{
				return true;
			}
		}

	}
	return true;
}

bool CPlayer::UnownAllProperties(std::vector<std::shared_ptr<CSquare>>& allSquares)
{
	for (auto index : mOwnedPropertiesIndexes)
	{
		allSquares.at(index)->SetPropertyOwner(nullptr);
	}
	return true;
}

bool CPlayer::UnmortgageAllProperties(std::vector<std::shared_ptr<CSquare>>& allSquares)
{
	for (auto index : mOwnedPropertiesIndexes)
	{
		allSquares.at(index)->SetMortgaged(false);
	}
	return true;
}