#pragma once
#include "Snake.h"
#include "Map.h"

#include<thread>
#include<chrono>
#include<conio.h>
#include<atomic>

class GameManager
{
public:
	GameManager(size_t n, size_t start_x, size_t start_y) : map(n), snake(map, start_x, start_y) {}
	~GameManager() {}
	void GameLoop();
	void StartSession();
private:
	void input(std::atomic<bool>* quit, Snake* snake);
	Map map;
	Snake snake;
};

void GameManager::GameLoop()
{
	std::atomic<bool> quit_thread = false;
	std::thread t(&GameManager::input, *this, &quit_thread, &snake);
	while (true)
	{
		if (!snake.Move(map))
		{
			quit_thread = true;
			return;
		}

		system("CLS");
		map.Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void GameManager::StartSession()
{

}

void GameManager::input(std::atomic<bool>* quit, Snake* snake)
{
	while (!(*quit))
	{
		int c = _getch();
		if (c == 224)
		{
			c = _getch();
			snake->ChangeDirection(directions[c]);
		}
	}
}
