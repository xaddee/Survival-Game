#include "FutureAgent.h"



FutureAgent::FutureAgent()
{
}


FutureAgent::~FutureAgent()
{
}

char FutureAgent::showName()
{
	return _name;
}

void FutureAgent::teleport(Position new_position)
{
	setCoords(new_position);
}

Position FutureAgent::moveToPosition(Position new_position)
{
	teleport(new_position);

	return new_position;
}