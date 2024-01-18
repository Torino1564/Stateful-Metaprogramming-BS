#include "SomeClass.h"
#include <iostream>
#include <format>

void SomeClass::DoSomething()
{
	sum = pepeComp.pepe++ + peponeComp.pepone++ + pepopotamusComp.pepopotamus++;
	auto outString = std::format("Pepe[{}]: {}     Pepone[{}]: {}     Pepopotamus[{}]: {} ",
		pepeComp.ID, pepeComp.pepe,
		peponeComp.ID, peponeComp.pepone,
		pepopotamusComp.ID, pepopotamusComp.pepopotamus);
	std::cout << outString << "Sum: " << sum << '\n';
}
