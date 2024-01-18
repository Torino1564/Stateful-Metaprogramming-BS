#pragma once
#include "PepeComponent.h"
#include <array>
#include <ranges>

class SomeSystem
{
public:
	static inline void Execute()
	{
		for (auto [index, pepeComponent] : std::ranges::views::enumerate(pepeArray))
		{
			pepeComponent.pepe = index;
			auto testID = pepeComponent.ID;
		}
	}
private:
	SomeSystem();
	static inline std::array<PepeComponent, 100> pepeArray;
};