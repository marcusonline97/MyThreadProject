// TrainingFolder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>

typedef struct Map_
{
	float xAxis;
	float yAxis;
}Map;

typedef struct Player_
{
	int Lives;

	bool playerAlive;
}Player;

void MapCreation(Map* map)
{
	map->xAxis = 12;
	map->yAxis = 12;
}

void PlayerCreate(Player* player)
{
	player->Lives = 3;
	player->playerAlive = true;
}


int main()
{
	return 0;
}

void PlayerBanana(void)
{
	int lives = 3;

	int death = 1;
}