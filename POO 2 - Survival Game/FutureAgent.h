#pragma once
#include "Agent.h"
class FutureAgent : // once at 3 rounds he can teleport to a location, otherwise he cant move
	public Agent
{
	char _name = 'T';
public:
	FutureAgent();
	~FutureAgent();

	Position moveToPosition(Position);
	void teleport(Position);

	char showName();
};

