#pragma once
#include "Agent.h"

class EagleAgent : // sees 2 extra rows;
	public Agent
{
	char _name = 'E';
public:
	EagleAgent();
	~EagleAgent();

	Position moveToPosition(Position);

	char showName();
};

