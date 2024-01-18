#include "Test.h"
#include <tuple>
#include <iostream>
#include "CTC.h"

#include "PepeComponent.h"
#include "PeponeComponent.h"
#include "PepopotamusComponent.h"

int main(int argc, char** argv)
{
	constexpr auto pepeID = PepeComponent::ID;
	constexpr auto peponeID = PeponeComponent::ID;
	constexpr auto pepopotamusID = PepopotamusComponent::ID;

	typename ComponentManager::list<> list;
	constexpr auto elCount = ComponentManager::GetElementCount();

	using PepeType = ComponentManager::type_by_index_t<pepeID>;
	PepeType pepeComp;
	pepeComp.pepe = 69;

	//pepeComp.pepe = 69;
	std::cout << "The fuck is going on!" << std::endl;
}