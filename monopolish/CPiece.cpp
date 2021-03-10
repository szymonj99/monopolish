// Szymon Janusz G20792986

#include "CPiece.h"

const std::string& CPiece::GetName() const
{
	return mName;
}

const bool CPiece::SetName(const std::string& kName)
{
	mName = kName;
	return true;
}