#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

void Item::setCoords(Position new_position)
{
	_position = new_position;
}

Position Item::showCoords()
{
	return _position;
}