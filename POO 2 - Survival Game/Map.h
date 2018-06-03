#pragma once

#include <vector>
#include <iostream>

struct Position
{
	int x, y;
};

class Map
{
	char **_map_matrix;
	int _size;
public:
	Map();
	~Map();
	void resize(int);

	void show();
	int showSize();

	void setValueAtCoords(Position, char);
	char showValueAtCoords(Position);



};

