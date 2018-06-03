#include "FlashAgent.h"



FlashAgent::FlashAgent()
{
	increaseMovement(1);
}


FlashAgent::~FlashAgent()
{
}

char FlashAgent::showName()
{
	return _name;
}

Position FlashAgent::moveToPosition(Position new_position)
{
	Position tmp = showCoords();

	int movement = showMovement();

	if (tmp.y < new_position.y)
	{
		if (std::abs(tmp.y - new_position.y) < movement)
			tmp.y = new_position.y;
		else
			tmp.y += movement;

		setCoords(tmp);
		return tmp;
	}

	if (tmp.y > new_position.y)
	{
		if (std::abs(tmp.y - new_position.y) < movement)
			tmp.y = new_position.y;
		else
			tmp.y -= movement;

		setCoords(tmp);
		return tmp;
	}

	if (tmp.x < new_position.x)
	{
		if (std::abs(tmp.x - new_position.x) < movement)
			tmp.x = new_position.x;
		else
			tmp.x += movement;

		setCoords(tmp);
		return tmp;
	}

	if (std::abs(tmp.x - new_position.x) < movement)
		tmp.x = new_position.x;
	else
		tmp.x -= movement;

	setCoords(tmp);
	return tmp;

}