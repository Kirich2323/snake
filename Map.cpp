#include"Map.h"

Map::Map(size_t n)
{
	map.resize(n + 2);
	map[0].resize(n + 2, HORIZONTAL_BORDER);
	for (int i = 1; i < n + 1; ++i)
	{
		map[i].resize(n + 2, SPACE_SYMBOL);
		map[i][0] = VERTICAL_BORDER;
		map[i][n + 1] = VERTICAL_BORDER;
	}
	map[n + 1].resize(n + 2, HORIZONTAL_BORDER);
}

bool Map::PathExist(vec2i pos)
{
	return map[pos.y][pos.x] == SPACE_SYMBOL || map[pos.y][pos.x] == APPLE_SYMBOL;
}

size_t Map::Size(size_t stroke)
{
	if (stroke < map.size())
		return map[stroke].size();
	return 0;
}

void Map::UpdateSymbol(vec2i pos, char symbol)
{
	map[pos.y][pos.x] = symbol;
	draw_queue.push(pos);
}

void Map::ReDraw()
{
	while (!draw_queue.empty())
	{
		vec2i pos = draw_queue.front();
		COORD p = { pos.x, pos.y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		printf("%c", map[pos.y][pos.x]);
		draw_queue.pop();
	}
}

void Map::Draw()
{
	for (size_t i = 0; i < map.size(); ++i)
	{
		for (size_t j = 0; j < map[i].size(); ++j)
			printf("%c", map[i][j]);
		printf("\n");
	}
}