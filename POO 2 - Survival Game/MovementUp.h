#pragma once
#include "Item.h"
#include "Agent.h"
class MovementUp : // lets agents move 2 spots in one round
	public Item
{
public:
	MovementUp();
	~MovementUp();

	void powerUp(Agent*);
};

