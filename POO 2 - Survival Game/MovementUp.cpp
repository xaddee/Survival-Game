#include "MovementUp.h"



MovementUp::MovementUp()
{
}


MovementUp::~MovementUp()
{
}

void MovementUp::powerUp(Agent* pick_uper)
{
	pick_uper->increaseMovement(1);
	pick_uper->increaseVision(1);
}