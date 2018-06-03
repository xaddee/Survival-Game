#pragma once

#include "Map.h"
#include <random>

class Agent
{
	Position _position;
	int _movement = 1; // the blocks every agent is allowed to move.
	int _vision = 1;	// how much distance from his position is he allowed to see
	bool _win_next_fight = false;
public:
	Agent();
	virtual ~Agent();
	virtual Position moveToPosition(Position) = 0;
	virtual char showName() = 0;

	int showMovement();
	bool showWin();
	Position showCoords();

	void winNextFight(bool);
	void increaseMovement(int);
	void increaseVision(int);

	void setCoords(Position);
	Position pickNextPosition(Map&, int, int);

};

