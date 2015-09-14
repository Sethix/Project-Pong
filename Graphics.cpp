#include "Player.h"
#include "Ball.h"
#include "sfwdraw.h"

void drawPlayer(Player p)
{
	//This function uses the players current position added by their size to draw them.
	//Remember - the players position is their top left point.
	sfw::drawLine(p.pos.x, p.pos.y, p.pos.x + p.size.x, p.pos.y);
	sfw::drawLine(p.pos.x, p.pos.y, p.pos.x, p.pos.y + p.size.y);
	sfw::drawLine(p.pos.x + p.size.x, p.pos.y + p.size.y, p.pos.x + p.size.x, p.pos.y);
	sfw::drawLine(p.pos.x + p.size.x, p.pos.y + p.size.y, p.pos.x, p.pos.y + p.size.y);
}

void drawBall(Ball b)
{
	sfw::drawCircle(b.pos.x, b.pos.y, b.size.x);
}