#pragma once
#include"vec2i.h"
#include<map>

#define SNAKE_SYMBOL '#'
#define SPACE_SYMBOL ' '
#define APPLE_SYMBOL '.'
#define VERTICAL_BORDER '|'
#define HORIZONTAL_BORDER '-'

#define SCORE_PER_APPLE 10
#define TURN_TIME_MILISECONDS 400
#define MIN_TURN_TIME_MILISECONDS 150

std::map<int, vec2i> directions = { 
	{77, vec2i(1, 0)},
	{80, vec2i(0, 1)},
	{75, vec2i(-1, 0)},
	{72, vec2i(0, -1)} 
};