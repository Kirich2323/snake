#include"Spawner.h"

Spawner::Spawner()
{
	mt = std::mt19937(rd());
	dist = std::uniform_int_distribution<size_t>(0, 100);
}

void Spawner::Spawn(Map & map)
{
	if (map.GetSymb(apple_position) == APPLE_SYMBOL)
		return;

	size_t y = dist(mt) % map.Size();
	size_t x = dist(mt) % map.Size(y);

	vec2i pos = Search(map, vec2i(x, y));
	if (pos != vec2i(-1, -1))
	{
		map.UpdateSymbol(pos, APPLE_SYMBOL);
		apple_position = pos;
	}
}

vec2i Spawner::Search(Map& map, vec2i pos)
{
	std::queue<vec2i> queue;
	queue.push(pos);
	std::vector<std::vector<bool>> visited(map.Size(), std::vector<bool>(map.Size(), false));

	while (!queue.empty())
	{
		vec2i current_loc = queue.front();
		queue.pop();

		if (map.GetSymb(current_loc) == SPACE_SYMBOL)
			return current_loc;

		for (auto direction : directions)
		{
			vec2i new_pos = current_loc + direction.second;
			if (CheckBounds(map, new_pos) && visited[new_pos.y][new_pos.x] == false)
			{
				queue.push(new_pos);
				visited[new_pos.y][new_pos.x] = true;
			}
		}
	}
	return vec2i(-1, -1);
}

inline bool Spawner::CheckBounds(Map & map, vec2i pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.y < map.Size() && pos.x < map.Size(pos.y);
}
