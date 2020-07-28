int cmpr(char letter)
{
	string list = "ABCDEFGHIJ";
	for (int i = 0;i<10;i++)
	{
		if (letter == list[i])
		{
			return 1;
		}
	} 
	return 0;
}

bool tryCooridnates(string &coordinates)
{
	if (coordinates.length()==2)
	{
		char letter = coordinates[0];
		int num = (int) coordinates[1];
		if (!cmpr(letter))
		{
			return false;
		}
		if (num > 0 && num < 9)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool tryorientation(char &orientation)
{
	tolower(orientation);
	if (orientation == 'H' || orientation == 'V')
	{
		return true;
	}
	return false;
}

bool collisionHandler(string coordinates, char orientation, int size)
{
	if (orientation == 'V')
	{
		int iCoor = coordinates[1] -'0';
		if (iCoor+(size-1)>9)
		{
			cout<<coordinates<<endl;
			cout<<iCoor<<" + "<<size-1<<" = "<<iCoor+(size-1)<<endl;
			cout<<"Ship can't go there"<<endl;
			return true;
		}
	}
	if (orientation == 'H')
	{
		string list = "ABCDEJGHIJ";
		int letterindex;
		for (int i = 0;i<10;i++)
		{
			if (list[i] == coordinates[0])
			{
				letterindex = i;
			}
		}

		if (letterindex + (size-1) > 9)
		{
			cout<<coordinates<<endl;
			cout<<"Ship can't go there"<<endl;
			return true;
		}
	}
	return false;
}

void addAC(string &userinput, bool &flag, char &orientation)
{
	do
	{
		cout<<"\nInput the coordinates of the Aircraft Carrier: ";
		cin>>userinput;
		flag = tryCooridnates(userinput);
	}while(!flag);
			
	do
	{
		cout<<"Input the orientation of the Aircraft Carrier H/V: ";
		cin>>orientation;
		flag = tryorientation(orientation);
	}while(!flag);

}

void addBS(string &userinput, bool &flag, char &orientation)
{
	do
	{
		cout<<"\nInput the coordinates of the Battle Ship: ";
		cin>>userinput;
		flag = tryCooridnates(userinput);
	}while(!flag);
			
	do
	{
		cout<<"Input the orientation of the Battle Ship H/V: ";
		cin>>orientation;
		flag = tryorientation(orientation);
	}while(!flag);
}

void addCruise(string &userinput, bool &flag, char &orientation)
{
	do
	{
		cout<<"\nInput the coordinates of the Cruise: ";
		cin>>userinput;
		flag = tryCooridnates(userinput);
	}while(!flag);
			
	do
	{
		cout<<"Input the orientation of the Cruise H/V: ";
		cin>>orientation;
		flag = tryorientation(orientation);
	}while(!flag);

}

void addSM(string &userinput, bool &flag, char &orientation)
{
	do
	{
		cout<<"\nInput the coordinates of the Submarine: ";
		cin>>userinput;
		flag = tryCooridnates(userinput);
	}while(!flag);
			
	do
	{
		cout<<"Input the orientation of the Submarine H/V: ";
		cin>>orientation;
		flag = tryorientation(orientation);
	}while(!flag);
}

void addDestructor(string &userinput, bool &flag, char &orientation)
{
	do
	{
		cout<<"\nInput the coordinates of the Destructor: ";
		cin>>userinput;
		flag = tryCooridnates(userinput);
	}while(!flag);
			
	do
	{
		cout<<"Input the orientation of the Destructor H/V: ";
		cin>>orientation;
		flag = tryorientation(orientation);
	}while(!flag);
}

void shipBuilder(Fleet * playerFleet, Queue * Chat, Debris * pDebris)
{
	string userinput;
	bool flag, collision;
	char orientation;
	do
	{
		Display(playerFleet,Chat,pDebris);
		addAC(userinput, flag, orientation);
		if(!hitBoundary(userinput,orientation,5))
		{
			collision = shipCollisions(playerFleet,userinput);
		}
		else
		{
			collision = true;
		}
	}while(collision);
	ship * aircraftCarrier = new ship('A',1,5,5,orientation,userinput,121);
	playerFleet->insert(aircraftCarrier);

	do
	{
		Display(playerFleet,Chat,pDebris);
		addBS(userinput, flag, orientation);
		if(!hitBoundary(userinput,orientation,4))
		{
			collision = shipCollisions(playerFleet,userinput);
		}
		else
		{
			collision = true;
		}
	}while(collision);
	ship * batlleShip = new ship('B',2,4,4,orientation,userinput,129);
	playerFleet->insert(batlleShip);

	do
	{
		Display(playerFleet,Chat,pDebris);
		addCruise(userinput, flag, orientation);
		if(!hitBoundary(userinput,orientation,3))
		{
			collision = shipCollisions(playerFleet,userinput);
		}
		else
		{
			collision = true;
		}
	}while(collision);
	ship * cruser = new ship('C',4,3,3,orientation,userinput,159);
	playerFleet->insert(cruser);
	

	do
	{
		Display(playerFleet,Chat,pDebris);
		addSM(userinput, flag, orientation);
		if(!hitBoundary(userinput,orientation,3))
		{
			collision = shipCollisions(playerFleet,userinput);
		}
		else
		{
			collision = true;
		}
	}while(collision);
	ship * submarine = new ship('S',4,3,3,orientation,userinput,161);
	playerFleet->insert(submarine);

	do
	{
		Display(playerFleet,Chat,pDebris);
		addDestructor(userinput, flag, orientation);
		if(!hitBoundary(userinput,orientation,2))
		{
			collision = shipCollisions(playerFleet,userinput);
		}
		else
		{
			collision = true;
		}
	}while(collision);
	ship * destructor = new ship('D',5,2,2,orientation,userinput,241);
	playerFleet->insert(destructor);
}

bool searchForShip(Fleet * playerFleet, char pType)
{
	for(ship* currentShip = playerFleet->getFirstShip(); currentShip!=NULL;currentShip=currentShip->getNextShip())
	{
		if (currentShip->getType() == pType)
		{
			return true;
		}
	}
	return false;
}

bool isShielded(Fleet * playerFleet,char pType)
{
	for(ship* currentShip = playerFleet->getFirstShip(); currentShip!=NULL;currentShip=currentShip->getNextShip())
	{
		if (currentShip->getType() == pType)
		{
			if(currentShip->getShield())
			{
				return true;	
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}