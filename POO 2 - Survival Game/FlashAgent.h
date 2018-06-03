#pragma once
#include "Agent.h"
class FlashAgent : // moves 2 blocks every round
	public Agent
{
	char _name = 'F';
public:
	FlashAgent();
	~FlashAgent();

	Position moveToPosition(Position);

	char showName();
};

