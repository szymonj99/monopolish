// Szymon Janusz G20792986

#include "CPiece.h"

CPiece::CPiece(const std::string& kName)
{
	mName = kName;
}

std::string CPiece::GetName() const
{
	return mName;
}

bool CPiece::SetName(const std::string& kName)
{
	mName = kName;
	return true;
}