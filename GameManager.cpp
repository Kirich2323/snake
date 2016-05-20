#include"GameManager.h"

void GameManager::GameLoop()
{
	system("CLS");
	map.Draw();
	while (true)
	{
		ReadInput();
		spawner.Spawn(map);
		if (!snake.Move(map))
		{
			ShowScore();
			return;
		}
		map.ReDraw();
		std::this_thread::sleep_for(std::chrono::milliseconds(max(TURN_TIME_MILISECONDS - ((int)snake.GetScore()), MIN_TURN_TIME_MILISECONDS)));
	}
}

void GameManager::ShowScore()
{
	system("CLS");
	printf("Your score is %d\n", snake.GetScore());
	printf("Enter any key to restart...");
	_getch();
}

inline void GameManager::ReadInput()
{
	while (_kbhit())
	{
		int c = _getch();
		if (c == 224)
		{
			c = _getch();
			auto it = directions.find(c);
			if (it != directions.end())
				snake.ChangeDirection(it->second);
		}
	}
}
