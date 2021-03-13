// Szymon Janusz G20792986

#include <iostream>

// Return a random number from 1 to 6.
const uint32_t Random()
{
	return static_cast<uint32_t>(static_cast<double>(rand()) / (static_cast<int64_t>(RAND_MAX + 1)) * 6.0f + 1);
}