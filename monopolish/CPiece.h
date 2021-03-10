// Szymon Janusz G20792986

#pragma once
#include <string>

class CPiece
{
private:
	std::string mName = "";

public:
	const std::string& GetName() const;
	const bool SetName(const std::string& kName);
};

