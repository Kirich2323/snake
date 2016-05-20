#pragma once
#include<iostream>
#include<vector>
#include"Constants.h"
#include<queue>
#include <windows.h>

class Map
{
public:
	Map(size_t n);
	~Map() {}
	void Draw();
	bool PathExist(vec2i);
	size_t Size() { return map.size(); }
	size_t Size(size_t stroke);
	char GetSymb(vec2i pos) { return map[pos.y][pos.x]; }
	void UpdateSymbol(vec2i pos, char symbol);
	void ReDraw();
private:
	std::vector<std::vector<char>> map;
	std::queue<vec2i> draw_queue;
};
