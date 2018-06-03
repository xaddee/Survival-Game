#pragma once
#include "Agent.h"
class Item
{
	Position _position;
public:
	Item();
	virtual ~Item();

	virtual void powerUp(Agent*) = 0;

	void setCoords(Position);
	Position showCoords();

};

