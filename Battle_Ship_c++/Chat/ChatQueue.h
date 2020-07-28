class Queue
{
private:
	int messageCounter;
	Message * firstMessage;
	int getCounter()
	{
		return messageCounter;
	}
	void setFirst(Message * pMessage)
	{
		this->firstMessage = pMessage;
	}
public:
	Queue()
	{
		this->firstMessage = NULL;
		this->messageCounter = 0;
	}

	void insert(string pMessage, string pType)
	{
		if (getCounter() < 11)
		{
			Message * newMessage = new Message(pMessage, pType);
			if(getCounter() == 0)
			{
				setFirst(newMessage);
				messageCounter++;
			}
			else
			{
				Message * current = firstMessage;
				while  (current->getNextMessage() != NULL)
				{
					current = current->getNextMessage();
				}
				current->setNextMessage(newMessage);
			}
			messageCounter++;
		}
		else 
		{ 
			Message *temp = firstMessage;
			firstMessage = firstMessage->getNextMessage();
			Message * current = firstMessage;
			while  (current->getNextMessage() != NULL)
			{
				current = current->getNextMessage();
			}
			temp->setMessage(pMessage);
			temp->setType(pType);
			temp->setNextMessage(NULL);
			current->setNextMessage(temp);
		}
	}

	void showChat()
	{
		if (firstMessage != NULL)
		{
			CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo = { 0 };
    		GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ), &ScreenBufferInfo ); 
			COORD cursor = {105,0};
			COORD output;

			SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ),15);
			SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), cursor);
			cout<<"BattleShip Chat";

			int y = 2;

			for(Message * current = firstMessage; current != NULL; current = current->getNextMessage())
			{
				if (current->getType() == "REC")
				{
					output.X = 105;
				}
				else if(current->getType() == "SEN")
				{
					output.X  = 115;
				}

				string message = current->getMessage();

				if (message.size()>41)
				{
					string buffer;
					for (int i = 0; i<=message.size();i++)
					{
						if ((i%41 == 0 && i!=0) || i == message.size())
						{
							output.Y = y;
							SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), output);
							cout<<buffer;
							buffer = "";
							y++;
						}
						buffer += message[i];
					}
					y++;
				}
				else
				{
					output.Y = y;
					SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), output);
					cout<<message;
					y +=2;
				}
			}
			//SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), cursor);
		}
	}
};