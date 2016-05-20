#pragma once
#include<iostream>
#include<vector>
#include"Constants.h"

class Map
{
public:
	Map(size_t n);
	~Map();
	void Draw();
	bool PathExist(vec2i);
	char& GetSymb(vec2i pos) { return map[pos.y][pos.x]; }
private:
	std::vector<std::vector<char>> map;
};

Map::Map(size_t n)
{
	map.resize(n);
	for (int i = 0; i < n; ++i)
		map[i].resize(n, SPACE_SYMBOL);
}

Map::~Map()
{

}

bool Map::PathExist(vec2i pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < map.size() && pos.y < map.size();
}

void Map::Draw()
{
	for (size_t i = 0; i < map.size() + 2; ++i)
		printf("-");

	printf("\n");

	for (size_t i = 0; i < map.size(); ++i)
	{
		printf("|");
		for (size_t j = 0; j < map[i].size(); ++j)
			printf("%c", map[i][j]);
		printf("|\n");
	}

	for (size_t i = 0; i < map.size() + 2; ++i)
		printf("-");

}