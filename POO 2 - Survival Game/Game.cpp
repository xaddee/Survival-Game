#include "Game.h"

Game::Game()
{
	_map_dimension = 0;
	_map_dimension = 0;
	_number_of_items = 0;
	_agents = { 0 };
	_items = { 0 };
}

Game::~Game()
{
	for (Agent* i : _agents)
		delete[] i;
	for (Item* i : _items)
		delete[] i;
}

Position Game::pickPosition()
{
	std::default_random_engine generator;
	std::uniform_int_distribution <int> x(1,_map_dimension - 2), y(1,_map_dimension - 2);

	Position pos;

	pos.x = (int)x(generator);
	pos.y = (int)y(generator);

	while (_map.showValueAtCoords(pos) != ' ' && _map.showValueAtCoords(pos) != '=') 
	{
		pos.x = (int)x(generator);
		pos.y = (int)y(generator);
	}

	return pos;
}

void Game::setItems()
{
	Position coords;

	_items.resize(_number_of_items);

	for (int i = 0; i < _number_of_items / 3; i++)
	{
		_items[i] = new MovementUp;
		coords = pickPosition();
		_items[i]->setCoords(coords);
		_map.setValueAtCoords(coords, 'm');
	}

	for (int i = _number_of_items / 3; i < 2 * _number_of_items / 3; i++)
	{
		_items[i] = new AlwaysWin;
		coords = pickPosition();
		_items[i]->setCoords(coords);
		_map.setValueAtCoords(coords, 'a');
	}

	for (int i = 2 * _number_of_items / 3; i < _number_of_items; i++)
	{
		_items[i] = new VisionUp;
		coords = pickPosition();
		_items[i]->setCoords(coords);
		_map.setValueAtCoords(coords, 'v');
	}
}

void Game::setAgents()
{
	Position coords;

	_agents.resize(_number_of_agents);

	for (int i = 0; i < _number_of_agents / 3; i++)
	{
		_agents[i] = new EagleAgent;
		coords = pickPosition();
		_agents[i]->setCoords(coords);
		_map.setValueAtCoords(coords, 'E');
	}

	for (int i = _number_of_agents / 3; i < 2 * _number_of_agents / 3; i++)
	{
		_agents[i] = new FlashAgent;
		coords = pickPosition();
		_agents[i]->setCoords(coords);
		_map.setValueAtCoords(coords, 'F');
	}

	for (int i = 2 * _number_of_agents / 3; i < _number_of_agents; i++)
	{
		_agents[i] = new FutureAgent;
		coords = pickPosition();
		_agents[i]->setCoords(coords);
		_map.setValueAtCoords(coords, 'T');
	}
}

void Game::setup(int map_dimension, int number_of_agents, int number_of_items)
{
	_map_dimension = map_dimension;
	_number_of_agents = number_of_agents;
	_number_of_items = number_of_items;
	_map.resize(map_dimension);
	setItems();
	setAgents();
}


int Game::findItemByCoords(Position position)
{
	for (int i = 0; i < _number_of_items; i++)
	{
		Position tmp = _items[i]->showCoords();
		if (tmp.x == position.x && tmp.y == position.y)
			return i;
	}
	return -1;
}

int Game::findAgentByCoords(Position position, int index)
{
	for (int i = 0; i < _number_of_agents; i++)
	{
		Position tmp = _agents[i]->showCoords();
		if (tmp.x == position.x && tmp.y == position.y && i != index)
		{
			return i;
		}
	}
	return -1;
}

void Game::Fight(int first, int second)
{
	if (_agents[first]->showWin() &&  !_agents[second]->showWin()) // verifica daca unul dintre agenti a luat itemul win next fight, automat acela este castigatorul luptei
	{
		_agents[first]->winNextFight(false);
		Position tmp = _agents[first]->showCoords();
		_map.setValueAtCoords(tmp, _agents[first]->showName());
		_agents.erase(_agents.begin() + second);

	}

	else if (!_agents[first]->showWin() && _agents[second]->showWin()) // la fel doar ca pt celalalt agent
	{
		_agents[second]->winNextFight(false);
		Position tmp = _agents[second]->showCoords();
		_map.setValueAtCoords(tmp, _agents[second]->showName());
		_agents.erase(_agents.begin() + first);
	}
	else
	{
		std::random_device generator;
		std::mt19937 mt(generator());
		std::uniform_int_distribution <int> picker(1, 3);
		
		if (picker(mt) % 2)
		{
			Position tmp = _agents[first]->showCoords();
			_map.setValueAtCoords(tmp, _agents[first]->showName());
			_agents.erase(_agents.begin() + second);

		}
		else
		{
			Position tmp = _agents[second]->showCoords();
			_map.setValueAtCoords(tmp, _agents[second]->showName());
			_agents.erase(_agents.begin() + first);
		}
			 
	}
	_number_of_agents--;
}

void Game::update()
{
	for (int i = 0; i < _number_of_agents; i++)
	{
		if (_agents[i])
		{
			Position wished_position, current_position;
			
			wished_position = _agents[i]->pickNextPosition(_map,_number_of_agents,_number_of_items);
			current_position = _agents[i]->showCoords();
			
			_map.setValueAtCoords(current_position, ' ');
			
			current_position = _agents[i]->moveToPosition(wished_position);
			
			char value = _map.showValueAtCoords(current_position);

			if (value == ' ')
			{
				_map.setValueAtCoords(current_position, _agents[i]->showName());
			}
			else if (value == 'v' || value == 'a' || value == 'm')
			{
				int tmp; // reprezinta indicele itemului pe care am ajuns
				tmp = findItemByCoords(current_position);

				if (tmp > -1) 
				{
					_items[tmp]->powerUp(_agents[i]);

					Position temp = _agents[i]->showCoords();
					_map.setValueAtCoords(temp, _agents[i]->showName());
					_number_of_items--;
				}
			}
			else
			{
				int index = findAgentByCoords(current_position, i);
				if(index > -1)
				Fight(i, index);
			}
		}
	}

}

void Game::start(int map_dimension, int number_of_agents, int number_of_items)
{
	setup(map_dimension, number_of_agents, number_of_items);

	int contor = 1;
	int check = 1;
	while (_number_of_agents > 1)
	{
		std::cout << "Runda: " << contor << std::endl;
		_map.show();
		if (check)
		{
			std::cout << "Treceti la runda urmatoare sau la sfarsitul jocului? (1-pt runda urmatoare, 0-pt sfarsitul jocului):";
			std::cin >> check;
			update();
			std::cout << "Nr de agenti ramasi: " << _number_of_agents << std::endl;
			std::cout << "Nr de iteme ramase: " << _number_of_items << std::endl;
		}
		else
		{

			update();
			std::cout << "Nr de agenti ramasi: " << _number_of_agents << std::endl;
			std::cout << "Nr de iteme ramase: " << _number_of_items << std::endl;
			_map.show();
		}

		if (_number_of_agents == 1)
		{
			std::cout << "Runda: " << contor << std::endl;
			std::cout << "Nr de agenti ramasi: " << _number_of_agents << std::endl;
			std::cout << "Nr de iteme ramase: " << _number_of_items << std::endl;
			_map.show();
		}
		contor++;
	}

}