#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"GameManager.h"

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<size_t> dist(0, 100);

int main(void)
{
	size_t map_size = 20;
	while (true)
	{
		GameManager gm(map_size, dist(mt) % (map_size - 6) + 3, dist(mt) % (map_size - 6) + 3);
		gm.GameLoop();
	}
	return 0;
}