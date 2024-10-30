#include <cmath>
#include <cstdint>
#include <iostream>

extern "C"
{
	float Hash(float x, float y, int32_t seed);
}

const uint32_t primeA{0b10011110001101110111100110110001};
const uint32_t primeB{0b10000101111010111100101001110111};
const uint32_t primeC{0b11000010101100101010111000111101};
const uint32_t primeD{0b00100111110101001110101100101111};
const uint32_t primeE{0b00010110010101100110011110110001};

float Mod(float a, float b) { return a - (b * std::floor(a / b)); }
float Frac(float t)
{
	float t1{std::floor(t)};
	t -= t1;
	return t;
}
uint32_t RotateLeft(uint32_t data, int32_t steps)
{
	return (data << steps) | (data >> (32 - steps));
}
float PerlinEase(float t) { return (t * t * t * (t * (t * 6 - 15) + 10)); }

int main() { std::cout << "Successfully loaded C++ noise" << '\n'; }

float Perlin2D(float x, float y, int seed, float scale)
{
	int32_t xi{(int32_t)std::floor(x / scale)};
	int32_t yi{(int32_t)std::floor(y / scale)};
	float xf{Mod(x, scale) / scale};
	float yf{Mod(y, scale) / scale};

	float u{PerlinEase(xf)};
	float v{PerlinEase(yf)};

	uint8_t h[4];
	for (int i = 0; i < 4; i++)
	{
		int xMod{i & 1};
		int yMod{(i < 2) ? -1 : 0};

		h[i] = (uint8_t)(Hash(xi + xMod, yi + yMod, seed) * 255);
	}

	float v1{};
	float v2{};
	float v3{};

	return 0.0f;
}
extern "C"
{
	float Hash(float x, float y, int32_t seed)
	{
		uint32_t accumulator{(unsigned int)seed + primeE};

		int32_t u{(int32_t)std::floor(x)};
		int32_t v{(int32_t)std::floor(y)};

		accumulator =
			RotateLeft(accumulator + (uint32_t)u * primeC, 17) * primeD;
		accumulator =
			RotateLeft(accumulator + (uint32_t)v * primeC, 17) * primeD;

		accumulator ^= accumulator >> 15;
		accumulator *= primeB;
		accumulator ^= accumulator >> 13;
		accumulator *= primeC;
		accumulator ^= accumulator >> 16;

		return (float)((accumulator & 255) * (1.0f / 256));
	}
}
