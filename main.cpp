#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"GameManager.h"

using namespace std;

int main(void)
{
	GameManager gm(20, 5, 5);
	gm.GameLoop();
	return 0;
}