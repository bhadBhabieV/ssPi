#ifndef RENDERVID_H
#define RENDERVID_H

#include "TimeBased.h"
#include "Core.h"

void loopVideo();
void pollController();

void playPauseVid();
void muteVid();
void volumeUpDown(string);
void speedUpOrSlowDown(string);

#endif

