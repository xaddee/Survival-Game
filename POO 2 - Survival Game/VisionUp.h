#pragma once
#include "Item.h"
class VisionUp : // lets players see an extra layer
	public Item
{
public:
	VisionUp();
	~VisionUp();

	void powerUp(Agent*);
};

