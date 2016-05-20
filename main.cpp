#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"GameManager.h"

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<size_t> dist(0, 100);

int main(void)
{
		GameManager gm(20, dist(mt) % 20, dist(mt) % 20);
		gm.GameLoop();
	return 0;
}