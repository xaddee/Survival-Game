#include "AlwaysWin.h"


AlwaysWin::AlwaysWin()
{

}

AlwaysWin::~AlwaysWin()
{

}

void AlwaysWin::powerUp(Agent* pick_uper)
{
	pick_uper->winNextFight(true);
}