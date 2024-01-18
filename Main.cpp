#include <tuple>
#include <iostream>
#include "CTC.h"

#include "PepeComponent.h"
#include "PepopotamusComponent.h"
#include "PeponeComponent.h"
#include "SomeSystem.h"
#include "SomeClass.h"

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

	SomeSystem::Execute();

	SomeClass sc1;

	for (int i = 0; i < 10; i++)
	{
		sc1.DoSomething();
	}

	std::cout << "The fuck is going on!" << std::endl;
}