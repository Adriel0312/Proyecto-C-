SOCKADDR_IN addr;				 	//Address to be binded to our Connection socket
int sizeofaddr = sizeof(addr); 		//Need sizeofaddr(address) for the connect function
int connectionNumber;
Game * currentGame;
Queue * myChat;
string attack;
List* elementsList = new List();


//Prototypes
void startWinsock(string IP, int Port);
bool tryToConnect();
bool listenForConnection(int Port);
void receiverThread();
bool ProcessString(string &buffer);

void startWinsock()
{
	//Winsock Startup
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
	}
}

bool tryToConnect(string IP, int Port)
{
	addr.sin_addr.s_addr = inet_addr(IP.c_str()); 	//Address = localhost (this pc)
	addr.sin_port = htons(Port);					//Port 
	addr.sin_family = AF_INET; 						//IPv4 Socket

	Connection = socket(AF_INET, SOCK_STREAM, NULL); 									//Set Connection socket
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) 						//If we are unable to connect...
	{
		cout<<"Connection attempt failed..."<<endl;
		return false; 																	//Failed to Connect
	}
	connectionNumber = 2;
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)receiverThread, NULL, NULL, NULL); 	//Create the client thread that will receive any data that the server sends.
	return true;
}

bool listenForConnection(int Port)
{
	cout<<"Listening for connections instead..."<<endl;
	addr.sin_addr.s_addr = inet_addr("0.0.0.0"); 						//Address = localhost (this pc)
	addr.sin_port = htons(Port); 										//Port 
	addr.sin_family = AF_INET; 											//IPv4 Socket

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); 						// Bind the address to the socket
	listen(sListen, SOMAXCONN); 										// Places sListen socket in a state in which it is listening for an incoming connection. Note:SOMAXCONN = Socket Oustanding Max Connections
		
	SOCKET newConnection;												// Socket to hold the client's connection
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);		// Accept a new connection
	if (newConnection==0)												// If accepting the client connection failed
	{
		cout <<"Connection failed..."<<endl;
		return false;
	}
	connectionNumber = 1;
	Connection = newConnection;															// Set the Connection socket to the new Connection 
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)receiverThread, NULL, NULL, NULL); 	// Create the client thread that will receive any data that the server sends.
	return true;
}

void receiverThread()
{

	string userinput;
	while (true)
	{
		
		if (!GetString(userinput))		// Get ID type
		{
			break;						// If there is an issue getting the String, exit this loop
		}
		if (!ProcessString(userinput))	// Process ID (ID type)
		{
			break;						// If there is an issue processing the String, exit this loop
		}
	}

	cout<<"\nLost connection..."<<endl;
	closesocket(Connection);
}

bool ProcessString(string &buffer)
{
	string ID = buffer.substr(0,3);
	switch (getIDType(ID))
	{
		case 1: 
		{
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
			int x = csbi.dwCursorPosition.X;
			int y = csbi.dwCursorPosition.Y;

			clearScreen(105,0,csbi.dwSize.X,35);

			string message = buffer.erase(0,4);
			myChat->insert(message,"REC");
			myChat->showChat();

			COORD cursor = {(SHORT)x,(SHORT)y};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			string message;
			string coordinates = buffer.erase(0,4);
			currentGame->getGameDebris()->insert(coordinates[0],coordinates[1]-'0');
			
			bool shield,destroyed;
			if(currentGame->getGameFleet()->hittedShip(coordinates,shield,destroyed,1))
			{
				if(shield)
				{
					message = "HIT|V";
				}
				else
				{
					message = "HIT|F";
				}
				SendString(message);
				if (destroyed)
				{

					message = "DST|";
					SendString(message);
				}
			}
			else
			{
				currentGame->getGameFleet()->deletShip();
				string message = "MSS|";
				SendString(message);
			}
			break;
		}
		case 6:
		{
			string message;
			string coordinates = buffer.erase(0,4);
			currentGame->getGameDebris()->insert(coordinates[0],coordinates[1]-'0');
			
			bool shield,destroyed;
			if(currentGame->getGameFleet()->hittedShip(coordinates,shield,destroyed,2))
			{
				if(shield)
				{
					message = "HIT|V";
				}
				else
				{
					message = "HIT|F";
				}
				SendString(message);
				if (destroyed)
				{

					message = "DST|";
					SendString(message);
				}
			}
			else
			{
				currentGame->getGameFleet()->deletShip();
				string message = "MSS|";
				SendString(message);
			}
			break;
		}
		case 7:
		{
			string message;
			string coordinates = buffer.erase(0,4);
			currentGame->getGameDebris()->insert(coordinates[0],coordinates[1]-'0');
			
			bool shield,destroyed;
			if(currentGame->getGameFleet()->hittedShip(coordinates,shield,destroyed,4))
			{
				if(shield)
				{
					message = "HIT|V";
				}
				else
				{
					message = "HIT|F";
				}
				SendString(message);
				if (destroyed)
				{

					message = "DST|";
					SendString(message);
				}
			}
			else
			{
				currentGame->getGameFleet()->deletShip();
				string message = "MSS|";
				SendString(message);
			}
			break;
		}
		case 8:
		{
			int element = stoi(buffer.erase(0,4));
			if(element !=0)
			{
				elementsList->insert(element);
			}
			else
			{
				string message = "END";
				SendString(message);
			}
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			string shieldUpDown =buffer.erase(0,4);
			if(shieldUpDown == "V")
			{
				if (attack == "BAL")
				{
					sendElements(100,500);
				}
				if (attack == "ORD")
				{
					sendElements(300,600);
				}
				if (attack == "BUS")
				{
					sendElements(1000,2500);
				}
			}
			break;
		}
		case 12:
		{
			Sleep(1000);
			cout<<"Your attack Missed.\nInput 'OK'to continue."<<endl;
			break;
		}
		case 13:
		{
			Sleep(1000);
			cout<<"Ship destroyed."<<endl;
			break;
		}
		case 14:
		{
			currentGame->setMyTurn();
			cout<<"The your oponent turn ended.\nInput 'OK'to continue."<<endl;
			break;
		}
		case 15:
		{
			Sleep(1000);
			cout<<"Attack ended input 'OK' to continue."<<endl;
			break;
		}
		case 16:
		{
			break;
		}
		default: 													//If ID type is not accounted for
			cout<<"Unrecognized ID:"<<ID<<endl; 					//Display that ID was not found
			break;
	}
	return true;
}

int getconnectionNumber()
{
	return connectionNumber;
}
void setsCurrentGame(Game * Game)
{
	currentGame = Game;
}
void setsGameChat(Queue * Chat)
{
	myChat = Chat;
}

void Connet(string & IP, int & Port)
{
	cout<<"IP address you want to connect to: ";
	cin>>IP;
	cin.ignore();

	cout<<"Port you want to open: ";
	cin>>Port;
	cin.ignore();

	if (!tryToConnect(IP, Port)) //If client fails to connect...
	{
		listenForConnection(Port);
	}
}