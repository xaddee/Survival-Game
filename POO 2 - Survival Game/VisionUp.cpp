#include "VisionUp.h"



VisionUp::VisionUp()
{
}


VisionUp::~VisionUp()
{
}

void VisionUp::powerUp(Agent* pick_uper)
{
	pick_uper->increaseVision(2);
}