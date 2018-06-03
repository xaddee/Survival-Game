#include "Agent.h"



Agent::Agent()
{
}

Agent::~Agent()
{
}

bool Agent::showWin()
{
	return _win_next_fight;
}

int Agent::showMovement()
{
	return _movement;
}

void Agent::increaseMovement(int x)
{
	_movement += x;
}

void Agent::increaseVision(int x)
{
	_vision += x;
}

void Agent::winNextFight(bool state)
{
	_win_next_fight = state;
}

void Agent::setCoords(Position new_position)
{
	
	_position = new_position;
}

Position Agent::pickNextPosition( Map& map, int agents_left,int items_left)
{
	Position coords = { 0,0 };
	
	if (!items_left || agents_left < 11) // daca nu mai sunt iteme sau sunt prea putini agenti tot agentii merg spre mijlocul mapei
	{
		coords.x = map.showSize() / 2;
		coords.y = map.showSize() / 2;
		return coords;
	}

	for(int i = _position.x - _vision; i<= _position.x + _vision; i++) // daca mai sunt iteme cauta in jurul lor daca exista unul
	{
		for (int j = _position.y - _vision; j <= _position.y + _vision; j++)
		{
			if (i != _position.x && j != _position.y) 
			{
				Position to_show = { i, j };
				char value = map.showValueAtCoords(to_show);

				if (value == 'a' || value == 'm' || value == 'v')
				{
					coords.x = i;
					coords.y = j;

					return coords;
				}
				 if (value != ' ' && value != 'n') // daca gaseste un agent ii salveaza coordonatele in caz ca nu gaseste iteme
				{
					coords.x = i;
					coords.y = j;

				}
			}
		}
	}
	if (coords.x && coords.y) return coords; // in caz ca nu a returnat un item , returneaza ultimele coordonate salvate, adica un agent.


		std::random_device generator;
		std::mt19937 mt(generator());
		std::uniform_int_distribution <int> x(_position.x - _vision, _position.x + _vision + 1), y(_position.y - _vision, _position.y + _vision + 1);

		int ok;

		do {

			coords.x = x(mt);
			coords.y = y(mt);

			if (coords.x == _position.x && coords.y == _position.y) ok = 0;
			else ok = 1;

		} while (map.showValueAtCoords(coords) == 'n' || !ok);	
	
	return coords;
}

Position Agent::showCoords()
{
	return _position;
}