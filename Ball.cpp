#include "Game.h"
#include "Vector.h"
#include "Player.h"
#include "Ball.h"
#include "sfwdraw.h"

Ball createBall()
{
	Ball tempBall;

	tempBall.size.x = BALL_WIDTH;
	tempBall.size.y = BALL_HEIGHT;

	tempBall.pos.x = (SCREEN_WIDTH / 2) - (BALL_WIDTH / 2);
	tempBall.pos.y = (SCREEN_HEIGHT / 2) - (BALL_HEIGHT / 2);

	tempBall.acc.x = 0;
	tempBall.acc.y = 0;

	tempBall.vel.x = -BALL_DEFAULT_SPEED;
	tempBall.vel.y = 0;

	return tempBall;
}

Ball moveBall(Ball b)
{
	Ball tempBall = b;

	tempBall.pos.y += tempBall.vel.y * sfw::getDeltaTime();
	tempBall.pos.x += tempBall.vel.x * sfw::getDeltaTime();

	tempBall.acc.y = 0;
	tempBall.acc.x = 0;

	if (tempBall.pos.y > SCREEN_HEIGHT - PADDLE_Y_LIMIT)
	{
		tempBall.vel.y = -tempBall.vel.y;
	}
	if (tempBall.pos.y < PADDLE_Y_LIMIT)
	{
		tempBall.vel.y = -tempBall.vel.y;
	}

	tempBall.vel.x += tempBall.acc.x * sfw::getDeltaTime();
	tempBall.vel.y += tempBall.acc.y * sfw::getDeltaTime();

	return tempBall;
}

Ball ballCollision(Ball b, Player p)
{
	Ball tempBall = b;
	Player tempPlayer = p;

	if (tempBall.pos.x <= tempPlayer.pos.x + tempPlayer.size.x && tempBall.pos.x > tempPlayer.pos.x &&
		tempBall.pos.y <= tempPlayer.pos.y + tempPlayer.size.y && tempBall.pos.y > tempPlayer.pos.y)
	{
		if(tempBall.vel.y != 0)
			tempBall.vel.y += BALL_ADDITIONAL_SPEED;

		if (tempBall.vel.x > 0)
		{
			tempBall.pos.x = tempPlayer.pos.x - 1;
			tempBall.vel.x += BALL_ADDITIONAL_SPEED;
			if (tempBall.pos.y >= tempPlayer.pos.y && tempBall.pos.y <= tempPlayer.pos.y + (tempPlayer.size.y / 3))
				tempBall.vel.y -= BALL_ADDITIONAL_SPEED * 2;
			if (tempBall.pos.y <= tempPlayer.pos.y + tempPlayer.size.y && tempBall.pos.y >= tempPlayer.pos.y + ((tempPlayer.size.y / 3) * 2))
				tempBall.vel.y += BALL_ADDITIONAL_SPEED * 2;
		}
		if (tempBall.vel.x < 0)
		{
			tempBall.pos.x = tempPlayer.pos.x + tempPlayer.size.x + 1;
			tempBall.vel.x += -BALL_ADDITIONAL_SPEED;
			if (tempBall.pos.y >= tempPlayer.pos.y && tempBall.pos.y <= tempPlayer.pos.y + (tempPlayer.size.y / 3))
				tempBall.vel.y -= BALL_VERTICAL_SPEED;
			if (tempBall.pos.y <= tempPlayer.pos.y + tempPlayer.size.y && tempBall.pos.y >= tempPlayer.pos.y + ((tempPlayer.size.y / 3) * 2))
				tempBall.vel.y += BALL_VERTICAL_SPEED;
		}
		tempBall.vel.x = -tempBall.vel.x;
	}

	if (tempBall.vel.x > BALL_SPEED_LIMIT) tempBall.vel.x = BALL_SPEED_LIMIT;
	if (tempBall.vel.x < -BALL_SPEED_LIMIT) tempBall.vel.x = -BALL_SPEED_LIMIT;

	return tempBall;
}