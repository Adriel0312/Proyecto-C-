#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") 	//Required for WinSock
#include <WinSock2.h> 				//For win sockets
#include <string>
#include <iostream> 				//For std::cout, std::endl, std::cin.getline
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <ctime>

using namespace std;

#include "/C proyects/Battle_Ship_c++/Defense/Node.h"
#include "/C proyects/Battle_Ship_c++/Defense/List.h"
#include "/C proyects/Battle_Ship_c++/Display/ClearConsole.h"
#include "/C proyects/Battle_Ship_c++/Chat/Message.h"
#include "/C proyects/Battle_Ship_c++/Chat/ChatQueue.h"
#include "/C proyects/Battle_Ship_c++/Ships/debrisNode.h"
#include "/C proyects/Battle_Ship_c++/Ships/Debris.h"
#include "/C proyects/Battle_Ship_c++/Ships/shipNode.h"
#include "/C proyects/Battle_Ship_c++/Ships/ship.h"
#include "/C proyects/Battle_Ship_c++/Ships/Fleet.h"
#include "/C proyects/Battle_Ship_c++/Ships/CollisionHandler.h"
#include "/C proyects/Battle_Ship_c++/Display/Display.h"
#include "/C proyects/Battle_Ship_c++/Game/Game.h"
#include "/C proyects/Battle_Ship_c++/Networking/Comunication.h"
#include "/C proyects/Battle_Ship_c++/Networking/Connection.h"
#include "/C proyects/Battle_Ship_c++/Ships/BuildFleet.h"
#include "/C proyects/Battle_Ship_c++/Game/Gameplay.h"

int main()
{
	setScreenSize();

	Game * myGame = new Game();
	Queue * myChat = new Queue();

	startWindow();

	startWinsock();

	string IP; 
	int Port;
	Connet(IP,Port);

	myGame->startTurn(getconnectionNumber());
	setsCurrentGame(myGame);
	setsGameChat(myChat);

	shipBuilder(myGame-> getGameFleet(),myChat, myGame->getGameDebris());

	while(true)
	{
		Display(myGame-> getGameFleet(),myChat, myGame->getGameDebris());

		if (myGame->isMyTurn())
		{
			Menu(myGame,myChat);
		}
		else
		{
			cout<<"\nIs not your turn yet. . ."<<endl;
			string input;
			while(true)
			{
				do
				{
					Display(myGame-> getGameFleet(),myChat, myGame->getGameDebris());
					cout<<"\nIs not your turn yet. . ."<<endl;
					cout<<"Input Message:"<<endl;
					getline(cin,input);
				}while(input == "" || input == " " || input == "\n");

				if(input== "OK")
				{
					break;
				}
				myChat->insert(input,"SEN");

				input = "MSG|"+input;
				if (!SendString(input))
					break;
			}
		}
	}
}