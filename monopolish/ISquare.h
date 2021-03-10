// Szymon Janusz G20792986

#pragma once
#include <string>
#include <memory>
#include "CPlayer.h"
#include "Constants.h"

using GlobalConstants::ESquareColour;

class ISquare
{
public:
	ISquare() {}
	virtual ~ISquare(){}
	// Get the square's name.
	virtual const std::string& GetName() const = 0;
	// Set the square's name.
	virtual const bool SetName(const std::string& kName) = 0;
	// Get the square's purchase cost.
	virtual const int32_t GetCost() const = 0;
	// Set the square's purchase cost.
	virtual const bool SetCost(const int32_t kCost) = 0;
	// Get the square's rent cost.
	virtual const int32_t GetRent() const = 0;
	// Set the square's rent cost.
	virtual const bool SetRent(const int32_t kRent) = 0;
	// Get the square's colour.
	virtual const ESquareColour GetSquareColour() const = 0;
	// Set the square's colour.
	virtual const bool SetSquareColour(const ESquareColour kColour) = 0;
	// Get the property's owner. Returns a shared pointer to player, or nullptr.
	virtual const std::shared_ptr<CPlayer> GetPropertyOwner() const = 0;
	// Set's the square's new owner.
	virtual const bool SetPropertyOwner(std::shared_ptr<CPlayer> player) = 0;
	// Returns true if the current square is owned by the player.
	virtual const bool IsOwnedByPlayer(const std::shared_ptr<CPlayer> player) = 0;
	//// Perform actions when landing on the current square.
	//virtual const bool LandOnSquare(std::unique_ptr<CPlayer> player) = 0;	
	
	
};