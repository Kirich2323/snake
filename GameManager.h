#pragma once
#include "Snake.h"
#include "Map.h"
#include "Spawner.h"

#include<thread>
#include<chrono>
#include<conio.h>
#include<atomic>

class GameManager
{
public:
	GameManager(size_t n, size_t start_x, size_t start_y) : map(n), snake(map, start_x + 1, start_y + 1) {}
	~GameManager() {}
	void GameLoop();
private:
	void ReadInput();
	void ShowScore();
	Map map;
	Snake snake;
	Spawner spawner;
};