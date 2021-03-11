// Szymon Janusz G20792986

#pragma once
#include <string>

class CPiece
{
private:
	std::string mName;

public:
	std::string GetName() const;
	bool SetName(const std::string& kName);
};

