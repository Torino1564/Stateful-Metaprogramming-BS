#pragma once
#include "PepeComponent.h"
#include "PeponeComponent.h"
#include "PepopotamusComponent.h"

class SomeClass
{
public:
	void DoSomething();
private:
	PepeComponent pepeComp;
	PeponeComponent  peponeComp;
	PepopotamusComponent pepopotamusComp;

	double sum = 0;
};