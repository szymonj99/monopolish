// Szymon Janusz G20792986

#pragma once
#include <string>
#include <memory>
#include "CPiece.h"

class CPlayer
{
private:
	std::string mName = "";
	std::shared_ptr<CPiece> mPiece = nullptr;
	int64_t mMoney = 1500;
	int32_t mPosition = 0;

public:
	const bool SetName(const std::string& kName);
	const std::string& GetName() const;
	const bool SetPiece(const std::shared_ptr<CPiece> kPiece);
	const std::shared_ptr<CPiece> GetPiece() const;
	const bool SubtractMoney(const int64_t kMoney);
	const bool AddMoney(const int64_t kMoney);
	const bool SetMoney(const int64_t kMoney);
	const int64_t GetMoney() const;
};