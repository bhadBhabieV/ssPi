#ifndef TIMEBASED_H
#define TIMEBASED_H

#include "Core.h"
#include "RenderVid.h"

void timeBasedStuff();

int timeHHMMSS_toSec(string, bool);
string timeHHMMSS(string);
string secToHHMMSS(int);

string getTime(string);

#endif
