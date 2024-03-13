// TrainingFolder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define WIDTH 40
#define HEIGHT 40
#define PACMAN 'C'
#define WALL '*'
#define FOOD '.' 
#define EMPTY ' ' 
#define DEMON 'X' 

//Adding global variables

int res = 0;
int score = 0;
int pacman_x, pacman_y;
char board[HEIGHT][WIDTH];

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