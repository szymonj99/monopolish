// Szymon Janusz G20792986

#include "CPlayer.h"
#include "Constants.h"

CPlayer::CPlayer(const std::string kPieceName, const int64_t kMoney, const int32_t kPosition)
{
	mPiece = std::make_shared<CPiece>(kPieceName);
	mMoney = kMoney;
	mPosition = kPosition;
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
	if (!(mPosition < GlobalConstants::kNUMBER_OF_SQUARES))
	{
		const int32_t kNewPosition = (GlobalConstants::kNUMBER_OF_SQUARES - 1) - mPosition;
		PassGo(kNewPosition);
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