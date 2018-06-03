#pragma once
#include "Item.h"
class AlwaysWin :  // wins the next fight 100%
	public Item
{
public:
	AlwaysWin();
	~AlwaysWin();

	void powerUp(Agent*);
};

