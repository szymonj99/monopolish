// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#pragma once
#include <string>
#include <memory>
#include "CPlayer.h"
#include "Constants.h"

using GlobalConstants::ESquareColour;
using GlobalConstants::ESquareType;

class CPlayer;

class CSquare
{
private:
	ESquareType mType = ESquareType::None;
	std::string mName;
	int32_t mCost = 0;
	int32_t mRent = 0;
	ESquareColour mColour = ESquareColour::NONE;
	std::shared_ptr<CPlayer> mOwner = nullptr;

public:
	CSquare() {};
	CSquare(const ESquareType kType, const std::string& kName, const int32_t kCost, const int32_t kRent, const ESquareColour kColour);
	~CSquare() {};
	// Set the square's type.
	bool SetType(const ESquareType kType);
	// Set the square's type.
	ESquareType GetType() const;
	// Get the square's name.
	std::string GetName() const;
	// Set the square's name.
	bool SetName(const std::string& kName);
	// Get the square's purchase cost.
	int32_t GetCost() const;
	// Set the square's purchase cost.
	bool SetCost(const int32_t kCost);
	// Get the square's rent cost.
	int32_t GetRent() const;
	// Set the square's rent cost.
	bool SetRent(const int32_t kRent);
	// Get the square's colour.
	ESquareColour GetSquareColour() const;
	// Set the square's colour.
	bool SetSquareColour(const ESquareColour kColour);
	// Get the property's owner. Returns a shared pointer to player, or nullptr.
	std::shared_ptr<CPlayer> GetPropertyOwner() const;
	// Set's the square's new owner.
	bool SetPropertyOwner(std::shared_ptr<CPlayer> player);
	// Returns true if the current square is owned by the player.
	bool IsOwnedByPlayer(const std::shared_ptr<CPlayer> player);
	// Perform actions when landing on the current square.
	virtual bool LandOnSquare(std::shared_ptr<CPlayer> player) = 0;
};