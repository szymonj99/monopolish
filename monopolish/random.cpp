// Szymon Janusz G20792986

#include <iostream>

// Return a random number from 0 to 6.
const uint8_t Random()
{
	return static_cast<int>(static_cast<double>(rand()) / (static_cast<int64_t>(RAND_MAX + 1)) * 6.0f + 1);
}