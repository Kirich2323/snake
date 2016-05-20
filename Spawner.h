#pragma once
#include"Map.h"
#include<queue>
#include<random>
#include<vector>
#include<list>

class Spawner
{
public:
	Spawner();
	void Spawn(Map& map);
	~Spawner() {};
private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<size_t> dist;
	//std::list<vec2i> spawned_objs;
	vec2i apple_position;
	vec2i Search(Map& map, vec2i pos);
	bool CheckBounds(Map& map, vec2i pos);
};