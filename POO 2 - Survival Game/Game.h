#pragma 

#include <random>

#include "Map.h"

#include "MovementUp.h"
#include "AlwaysWin.h"
#include "VisionUp.h"

#include "FlashAgent.h"
#include "EagleAgent.h"
#include "FutureAgent.h"

class Game
{
	int _map_dimension;
	int _number_of_agents;
	int _number_of_items;

	Map _map;

	std::vector<Agent*> _agents ;
	std::vector<Item*> _items;

	void setup(int, int, int);
	void setAgents();
	void setItems();

	void update();

	Position pickPosition();
	int findItemByCoords(Position);
	int findAgentByCoords(Position, int);

	void Fight(int, int);

public:
	Game();
	~Game();
	void start(int, int, int);
};

