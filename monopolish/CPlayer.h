// Szymon Janusz G20792986

#pragma once
#include <string>
#include <memory>
#include "CPiece.h"

class CPlayer
{
private:
	std::string mName;
	std::shared_ptr<CPiece> mPiece = nullptr;
	int64_t mMoney = 1500;
	int32_t mPosition = 0;

public:
	bool SetName(const std::string& kName);
	std::string GetName() const;
	bool SetPiece(const std::shared_ptr<CPiece> kPiece);
	std::shared_ptr<CPiece> GetPiece() const;
	bool SubtractMoney(const int64_t kMoney);
	bool AddMoney(const int64_t kMoney);
	bool SetMoney(const int64_t kMoney);
	int64_t GetMoney() const;
};