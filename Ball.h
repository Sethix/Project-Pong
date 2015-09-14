#pragma once
#include "Vector.h"
#include "Player.h"

struct Ball
{
	Vector2 size;
	Vector2 pos;
	Vector2 acc;
	Vector2 vel;
};

Ball createBall();

Ball moveBall(Ball b);

void drawBall(Ball b);