#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "sfwdraw.h"

void singlePlayerGame(Player p1, Ball b)
{
	//This is the game function for a single player game of pong.
	//It creates the player and AI as well as the game loop.
	//The goal of the game loop is to get input, draw the players
	//And calculate the player and ball positions.
	p1 = createPlayer(1);

	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Singleplayer Pong");

	while (sfw::stepContext())
	{
		drawPlayer(p1);
		drawBall(b);
		b = ballCollision(b, p1);
		p1 = movePlayer(p1);
		b = moveBall(b);
	}

	sfw::termContext();
}

void twoPlayerGame(Player p1, Player p2, Ball b)
{
	//This is the game function for a two player game of pong.
	//It creates the players and creates the game loop.
	//The goal of the game loop is to get input, draw the players
	//And calculate the player and ball positions.
	//The game should end when a player reaches the score limit.
	p1 = createPlayer(1);

	p2 = createPlayer(2);


	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Multiplayer Pong");


	while (sfw::stepContext())
	{
		drawPlayer(p1);
		drawPlayer(p2);
		drawBall(b);
		b = ballCollision(b, p1);
		b = ballCollision(b, p2);
		p1 = movePlayer(p1);
		p2 = movePlayer(p2);
		b = moveBall(b);
		scoreCheck(p1, p2, b);
	}

	sfw::termContext();
}