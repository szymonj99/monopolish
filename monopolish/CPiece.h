// Szymon Janusz G20792986

#pragma once
#include <string>

class CPiece
{
private:
	std::string mName;

public:
	CPiece(const std::string& kName);
	std::string GetName() const;
	bool SetName(const std::string& kName);
};

