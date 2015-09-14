#pragma once
#include "Vector.h"
#include "Ball.h"

struct Player
{
	Vector2 size;
	Vector2 pos;
	Vector2 acc;
	Vector2 vel;

	char name[4];

	int score;
	int ID;
};

Player createPlayer(int playerNum);

Player movePlayer(Player p);

Ball ballCollision(Ball b, Player p);

void scoreCheck(Player &leftPlayer, Player &rightPlayer, Ball &b);

int playerNumberCheck(int input);

void singlePlayerGame(Player p1, Ball b);

void twoPlayerGame(Player p1, Player p2, Ball b);

void drawPlayer(Player p);