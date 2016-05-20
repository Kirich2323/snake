#include"Snake.h"

Snake::Snake(Map& map, size_t start_x, size_t start_y)
{
	parts.push_back(vec2i(start_x, start_y));
	dir = directions.begin()->second;
	last_used_dir = dir;
	map.UpdateSymbol(vec2i(start_x, start_y), SNAKE_SYMBOL);
}


bool Snake::Move(Map& map)
{
	vec2i new_pos = parts.front() + dir;
	last_used_dir = dir;
	if (map.PathExist(new_pos))
	{
		parts.push_front(new_pos);
		char buf_char = map.GetSymb(new_pos);

		if (buf_char == SNAKE_SYMBOL)
			return false;
		else if (buf_char != APPLE_SYMBOL)
		{
			map.UpdateSymbol(parts.back(), SPACE_SYMBOL);
			parts.pop_back();
		}

		map.UpdateSymbol(new_pos, SNAKE_SYMBOL);

		return true;
	}
	return false;
}

size_t Snake::GetScore()
{
	return SCORE_PER_APPLE * (parts.size() - 1);
}

void Snake::ChangeDirection(vec2i new_dir)
{
	if (parts.size() == 1)
	{
		dir = new_dir;
		return;
	}

	if (new_dir + last_used_dir != vec2i(0, 0))
	{
		dir = new_dir;
	}
}