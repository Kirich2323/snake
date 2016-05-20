#pragma once
#include<list>
#include"vec2i.h"
#include"Constants.h"
#include"Map.h"

class Snake
{
public:
	Snake(Map& map, size_t start_x, size_t start_y);
	bool Move(Map& map);
	size_t GetScore();
	void ChangeDirection(vec2i new_dir);
	~Snake() {};
private:
	vec2i dir;
	vec2i last_used_dir;
	std::list<vec2i> parts;
};