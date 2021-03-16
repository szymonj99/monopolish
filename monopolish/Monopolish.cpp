// Szymon Janusz G20792986

// Disable warning about using enum class over enum.
#pragma warning(disable: 26812)

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CMonopolish.h"

int main()
{
	{
		auto Game = std::make_unique<CMonopolish>();
		Game->StartGame();
	}

	_CrtDumpMemoryLeaks();
	std::cout << "Program execution finished. Press enter to exit.\n";
	std::cin.get();
	return (int32_t)GlobalConstants::EExitCodes::SuccessFinish;
}