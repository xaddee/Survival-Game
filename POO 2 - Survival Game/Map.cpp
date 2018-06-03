#include "Map.h"

Map::Map()
{
	_size = 0;
}

Map::~Map()
{
	for (int i = 0; i < _size; i++)
	{
		delete[] _map_matrix[i];
	}

	delete[] _map_matrix;
}

void Map::resize(int size)
{
	_size = size;
	
	_map_matrix = new char*[size];

	for (int i = 0; i < size; i++)
	{
		_map_matrix[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			_map_matrix[i][j] = ' ';
			if (j == 0 || j == size - 1)
				_map_matrix[i][j] = '=';

			if (i == 0 || i == size - 1)
				_map_matrix[i][j] = '=';
		}
	}
}

int Map::showSize()
{
	return _size;
}

void Map::show() 
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			std::cout << _map_matrix[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::setValueAtCoords(Position position, char value)
{
	_map_matrix[position.x][position.y] = value;
}

char Map::showValueAtCoords(Position position)
{
	if (position.x > _size - 2 || position.y > _size - 2 || position.x < 1 || position.y < 1)
		return 'n'; // functia returneaza 'n' pt tot ce e in afara mapei

	return _map_matrix[position.x][position.y];
}

