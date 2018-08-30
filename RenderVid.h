#ifndef RENDERVID_H
#define RENDERVID_H

#include "TimeBased.h"
#include "Core.h"

void loopVideo();
void pollController();

void playPauseVid(string);
void muteVid(string);
void volumeUpDown(string, string);
void speedUpOrSlowDown(string, string);

#endif

