#include <iostream>
#include "Game.h"
#include "Vector.h"
#include "Player.h"
#include "sfwdraw.h"

int playerNumberCheck(int input)
{
	while (true)
	{
		switch (input)
		{
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			std::cout << "Invalid number. Please try again." << std::endl;
			break;
		}
	}
}

Player createPlayer(int playerNum)
{
	//This function defines the player variables and gets the players initials.
	Player tempPlayer;

	char firstInitial;

	char secondInitial;

	char thirdInitial;


	std::cout << "Please input initials player " << playerNum << "." << std::endl;

	std::cin >> firstInitial >> secondInitial >> thirdInitial;


	tempPlayer.name[0] = firstInitial;
	tempPlayer.name[1] = secondInitial;
	tempPlayer.name[2] = thirdInitial;

	tempPlayer.score = 0;
	tempPlayer.ID = playerNum;

	tempPlayer.vel.x = 0;
	tempPlayer.vel.y = 0;

	tempPlayer.acc.x = 0;
	tempPlayer.acc.y = 0;

	tempPlayer.size.x = PADDLE_WIDTH;
	tempPlayer.size.y = PADDLE_HEIGHT;


	if (playerNum == 1)
	{
		tempPlayer.pos.x = 5;
		tempPlayer.pos.y = (SCREEN_HEIGHT / 2) - (tempPlayer.size.y / 2);
	}

	if (playerNum == 2)
	{
		tempPlayer.pos.x = SCREEN_WIDTH - PADDLE_WIDTH - 5;
		tempPlayer.pos.y = (SCREEN_HEIGHT / 2) - (tempPlayer.size.y / 2);
	}


	return tempPlayer;
}

Player movePlayer(Player p)
{
	//Formatting inspired by the "sfwexample.cpp" included in the SFW library.
	//This function sets the players acceleration according to key input
	//Then adds acceleration to velocity to determine position.

	Player tempPlayer = p;

	tempPlayer.pos.y += tempPlayer.vel.y * sfw::getDeltaTime();

	tempPlayer.acc.y = 0;


	if (tempPlayer.ID == 1)
	{
		if (sfw::getKey('w')) tempPlayer.acc.y = -PADDLE_SPEED;
		else if (sfw::getKey('s')) tempPlayer.acc.y = PADDLE_SPEED;
	}

	if (tempPlayer.ID == 2)
	{
		if (sfw::getKey('i')) tempPlayer.acc.y = -PADDLE_SPEED;
		else if (sfw::getKey('k')) tempPlayer.acc.y = PADDLE_SPEED;
	}


	if (tempPlayer.pos.y <= PADDLE_Y_LIMIT)
	{
		tempPlayer.vel.y = 0;
		tempPlayer.pos.y = PADDLE_Y_LIMIT;
	}
	else if (tempPlayer.pos.y >= SCREEN_HEIGHT - PADDLE_Y_LIMIT - PADDLE_HEIGHT)
	{
		tempPlayer.vel.y = 0;
		tempPlayer.pos.y = SCREEN_HEIGHT - PADDLE_Y_LIMIT - PADDLE_HEIGHT;
	}


	if (tempPlayer.acc.y != 0)
	{
		if (tempPlayer.vel.y > 0 && tempPlayer.acc.y < 0 ||
			tempPlayer.vel.y < 0 && tempPlayer.acc.y > 0)
				tempPlayer.vel.y += tempPlayer.acc.y * sfw::getDeltaTime() * 3;
		tempPlayer.vel.y += tempPlayer.acc.y * sfw::getDeltaTime();
	}
	else
	{
		if (tempPlayer.vel.y > 0) tempPlayer.vel.y -= PADDLE_SPEED * sfw::getDeltaTime();
		if (tempPlayer.vel.y < 0) tempPlayer.vel.y += PADDLE_SPEED * sfw::getDeltaTime();
		if (tempPlayer.vel.y < 2 || tempPlayer.vel.y > -2) tempPlayer.vel.y = 0;
	}

	if (tempPlayer.vel.y > PADDLE_VEL_LIMIT) tempPlayer.vel.y = PADDLE_VEL_LIMIT;
	if (tempPlayer.vel.y < -PADDLE_VEL_LIMIT) tempPlayer.vel.y = -PADDLE_VEL_LIMIT;


	return tempPlayer;
}

void scoreCheck(Player &leftPlayer, Player &rightPlayer, Ball &b)
{
	if (b.pos.x > SCREEN_WIDTH)
	{
		rightPlayer.score++;

		b.pos.x = SCREEN_WIDTH / 2;
		b.pos.y = SCREEN_HEIGHT / 2;

		b.vel.x = -BALL_DEFAULT_SPEED;
		b.vel.y = 0;
	}
	if (b.pos.x < 0)
	{
		leftPlayer.score++;

		b.pos.x = SCREEN_WIDTH / 2;
		b.pos.y = SCREEN_HEIGHT / 2;

		b.vel.x = BALL_DEFAULT_SPEED;
		b.vel.y = 0;
	}
}