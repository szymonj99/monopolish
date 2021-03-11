// Szymon Janusz G20792986

#include "CPiece.h"

std::string CPiece::GetName() const
{
	return mName;
}

bool CPiece::SetName(const std::string& kName)
{
	mName = kName;
	return true;
}