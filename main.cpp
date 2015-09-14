/*
/	This program is my first attempt at a Pong like game using C++.
/	Author: Justin Hamm, Justin.T.Hamm@gmail.com
/	
/
/
/	Help recieved
/	
/	SFW.lib - Graphics framework
/	Author: Esmeralda Salamone, esmes@aie.edu.au
*/


#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "Main.h"


int main()
{

	Player player[2];
	Ball ball;
	inputInt = 0;


	std::cout << "Input 1 for single player, 2 for multiplayer or 0 to exit." << std::endl << std::endl;

	std::cin >> inputInt;

	std::cout << std::endl;


	numOfPlayers = playerNumberCheck(inputInt);

	ball = createBall();


	if (numOfPlayers == 1) singlePlayerBotGame(player[0], ball);
	else if (numOfPlayers == 2) twoPlayerGame(player[0], player[1], ball);

	system("Pause");
	
	return 0;
}

