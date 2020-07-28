void printMenu()
{
	cout<<"Choose an option."<<endl;
	cout<<"1. Attack"<<endl;
	cout<<"2. Move Ship"<<endl;
	cout<<"3. Send Message"<<endl;
	cout<<"4. Pass"<<endl;
	cout<<"5. Surrender"<<endl;
}

void printAttack()
{
	cout<<"Choose a type of Ammo."<<endl;
	cout<<"1. Caceria"<<endl;
	cout<<"2. Balanceo"<<endl;
	cout<<"3. Ordenamiento"<<endl;
	cout<<"4. Rastreador"<<endl;
	cout<<"5. Busqueda"<<endl;
	cout<<"6. Back"<<endl;
}

void printMove()
{
	cout<<"Choose a type of Ship you want move."<<endl;
	cout<<"1. Aircraft Carrier"<<endl;
	cout<<"2. Battle Ship"<<endl;
	cout<<"3. Cruise"<<endl;
	cout<<"4. Submarine"<<endl;
	cout<<"5. Destructor"<<endl;
}

void balanceo(Game* _Game, Queue * Chat)
{
	if (searchForShip(_Game-> getGameFleet(),'B'))
	{
		if (isShielded(_Game-> getGameFleet(),'B'))
		{	
			_Game->switchAttack();
			string userinput;
			bool flag;
			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cout<<"Set coordinates: ";
				cin>>userinput;
				flag = tryCooridnates(userinput);
			}while(!flag);
			attack = "BAL";
			string message = "BAL|"+userinput;
			SendString(message);

			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cin>>userinput;
			}while(userinput != "OK");

		}
		else
		{
			cout<<"The Battle Ship can't attack it's shield is down."<<endl;
		}
	}
	else
	{
		cout<<"There is no Ship able to do that attack."<<endl;
	}
}

void busqueda(Game* _Game, Queue * Chat)
{
	if (searchForShip(_Game-> getGameFleet(),'D'))
	{
		if (isShielded(_Game-> getGameFleet(),'D'))
		{	
			_Game->switchAttack();
			string userinput;
			bool flag;
			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cout<<"Set coordinates: ";
				cin>>userinput;
				flag = tryCooridnates(userinput);
			}while(!flag);
			attack = "BUS";
			string message = "BUS|"+userinput;
			SendString(message);

			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cin>>userinput;
			}while(userinput != "OK");

		}
		else
		{
			cout<<"The Battle Ship can't attack it's shield is down."<<endl;
		}
	}
	else
	{
		cout<<"There is no Ship able to do that attack."<<endl;
	}
}

void ordenamiento(Game* _Game, Queue * Chat)
{
	if (searchForShip(_Game-> getGameFleet(),'C'))
	{
		if (isShielded(_Game-> getGameFleet(),'C'))
		{	
			_Game->switchAttack();
			string userinput;
			bool flag;
			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cout<<"Set coordinates: ";
				cin>>userinput;
				flag = tryCooridnates(userinput);
			}while(!flag);
			attack = "ORD";
			string message = "ORD|"+userinput;
			SendString(message);

			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cin>>userinput;
			}while(userinput != "OK");

		}
		else
		{
			cout<<"The Battle Ship can't attack it's shield is down."<<endl;
		}
	}
	else
	{
		cout<<"There is no Ship able to do that attack."<<endl;
	}
}

void Caceria(Game* _Game, Queue * Chat)
{
	if (searchForShip(_Game-> getGameFleet(),'A')){
		if (isShielded(_Game-> getGameFleet(),'A')){
			_Game->switchAttack();
			string userinput;
			bool flag;
			do {
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cout<<"Set coordinates: ";
				cin>>userinput;
				flag=tryCooridnates(userinput);
			} while(!flag);
			string message= "CAC|"+userinput;
			SendString(message);

			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cin>>userinput;
			}while(userinput != "OK");

		}
		else{
			cout<<"The Battle Ship can't attack it's shield is down."<<endl;
		}
	}
	else{
		cout<<"There is no Ship able to do that attack."<<endl;
	}

}

void Rastreador(Game* _Game, Queue * Chat)
{
	if (searchForShip(_Game-> getGameFleet(),'S')){
		if (isShielded(_Game-> getGameFleet(),'S')){
			_Game->switchAttack();
			string userinput;
			bool flag;
			do {
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cout<<"Set coordinates: ";
				cin>>userinput;
				flag=tryCooridnates(userinput);
			} while(!flag);
			string message= "RST|"+userinput;
			SendString(message);

			do
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				cin>>userinput;
			}while(userinput != "OK");

		}
		else{
			cout<<"The Battle Ship can't attack it's shield is down."<<endl;
		}
	}
	else{
		cout<<"There is no Ship able to do that attack."<<endl;
	}

}

void attackMenu(Game* _Game, Queue * Chat)
{
	printAttack();
	int useroption;
	cin>>useroption;
	switch(useroption)
	{
		case 1:
		{
			Caceria(_Game,Chat);
			break;
		}
		case 2:
		{
			balanceo(_Game,Chat);
			break;
		}
		case 3:
		{
			ordenamiento(_Game,Chat);
			break;
		}
		case 4:
		{
			Rastreador(_Game,Chat);
			break;
		}
		case 5:
		{
			busqueda(_Game,Chat);
			break;
		}
		case 6:
		{
			break;
		}
		default:
			cout<<"Unrecognized Option: "<<useroption<<endl;
			break;
	}
}

void Messaging(Game* _Game,Queue * Chat)
{
	string input;
	while(true)
	{
		do
		{
			Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
			cout<<"Input Message:"<<endl;
			getline(cin,input);
			cin.ignore(0,'\n');
		}while(input == "" ||input == " ");

		if(input == "Exit" || input == "Back")
		{
			break;
		}

		Chat->insert(input,"SEN");

		input = "MSG|"+input;
		if (!SendString(input))
			break;

	}
}

void Movement(Game * _Game,Queue * Chat){
	_Game->switchMove();
	printMove();
	int useroption;
	cin>>useroption;
	switch(useroption)
	{
		case 1:
		{
			ship * currentShip = _Game-> getGameFleet()->getFirstShip();
			while  (currentShip->getNextShip() != NULL)
			{
				if(currentShip->getType() == 'A'){
					bool flag;
					string userinput;
					int useroptionS;
					do
					{
						Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
						cout<<"Choose direction of movement for Aircraft Carrier: "<<endl;
						cout<<"1. UP"<<endl;
						cout<<"2. DOWN"<<endl;
						cout<<"3. LEFT"<<endl;
						cout<<"4. RIGHT"<<endl;
						cin>>useroptionS;
						switch(useroptionS)
						{
							case 1:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 6){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()-1 ){
										temp->setJ(temp->getJ()-1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}



							case 2:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 6){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()+1 ){
										temp->setJ(temp->getJ()+1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}


						case 3:
							{
								if(currentShip->getShipNode()->getI() == 'A'){
									cout<<"you cant go up"<<endl;
									break;
								}
								else{
									int cont = 1;
									shipNode *temp=currentShip->getShipNode();
									while(cont != 6){
									if(temp->getI() == 0){
										cout<<"You cant go up"<<endl;
										break;
									}else{

									if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()-1 ){
										temp->setI(temp->getI()-1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
									}
								}
								Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
								flag = true;
								break;
								}
								break;
							}
							case 4:
							{
								if(currentShip->getShipNode()->getI() == 'J'){
									cout<<"you cant go up"<<endl;
									break;
								}
								else{
									if(currentShip->getShipNode()->getI() == 'A'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										int cont = 1;
										shipNode *temp=currentShip->getShipNode();
										while(cont != 6){
										if(temp->getI() == 0){
											cout<<"You cant go up"<<endl;
											break;
										}else{
											if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()+1 ){
												temp->setI(temp->getI()+1);
												temp=temp->getNextNode();
												cont++;
											}
											else {cout<<"Cant do this move"<<endl;break;}
										}
									}
									Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
									flag = true;
									break;
									}
									break;
								}
								break;
							}
							default:
								cout<<"Unrecognized Option: "<<useroption<<endl;
								break;
						}
					}while(!flag);
				}
				currentShip = currentShip->getNextShip();
			}
			break;
		}
		case 2:
		{
			ship * currentShip = _Game-> getGameFleet()->getFirstShip();
			while  (currentShip->getNextShip() != NULL)
			{
				if(currentShip->getType() == 'B'){
					bool flag;
					string userinput;
					int useroptionS;
					do
					{
						Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
						cout<<"Choose direction of movement for Battle Ship Carrier: "<<endl;
						cout<<"1. UP"<<endl;
						cout<<"2. DOWN"<<endl;
						cout<<"3. LEFT"<<endl;
						cout<<"4. RIGHT"<<endl;
						cin>>useroptionS;
						switch(useroptionS)
						{
							case 1:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 5){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()-1 ){
										temp->setJ(temp->getJ()-1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}



							case 2:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 5){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()+1 ){
										temp->setJ(temp->getJ()+1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}


							case 3:
								{
									if(currentShip->getShipNode()->getI() == 'A'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										int cont = 1;
										shipNode *temp=currentShip->getShipNode();
										while(cont != 5){
										if(temp->getI() == 0){
											cout<<"You cant go up"<<endl;
											break;
										}else{
										if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()-1 ){
											temp->setI(temp->getI()-1);
											temp=temp->getNextNode();
											cont++;
										}
										else {cout<<"Cant do this move"<<endl;break;}
										}
									}
									Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
									flag = true;
									break;
									}
									break;
								}
								case 4:
								{
									if(currentShip->getShipNode()->getI() == 'J'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										if(currentShip->getShipNode()->getI() == 'A'){
											cout<<"you cant go up"<<endl;
											break;
										}
										else{
											int cont = 1;
											shipNode *temp=currentShip->getShipNode();
											while(cont != 5){
											if(temp->getI() == 0){
												cout<<"You cant go up"<<endl;
												break;
											}else{
												if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()+1 ){
													temp->setI(temp->getI()+1);
													temp=temp->getNextNode();
													cont++;
												}
												else {cout<<"Cant do this move"<<endl;break;}
											}
										}
										Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
										flag = true;
										break;
										}
										break;
									}
									break;
								}
							default:
								cout<<"Unrecognized Option: "<<useroption<<endl;
								break;
						}
					}while(!flag);
				}
				currentShip = currentShip->getNextShip();
			}
			break;
		}
		case 3:
		{
			ship * currentShip = _Game-> getGameFleet()->getFirstShip();
			while  (currentShip->getNextShip() != NULL)
			{
				if(currentShip->getType() == 'C'){
					bool flag;
					string userinput;
					int useroptionS;
					do
					{
						Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
						cout<<"Choose direction of movement for Cazador: "<<endl;
						cout<<"1. UP"<<endl;
						cout<<"2. DOWN"<<endl;
						cout<<"3. LEFT"<<endl;
						cout<<"4. RIGHT"<<endl;
						cin>>useroptionS;
						switch(useroptionS)
						{
							case 1:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 4){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()-1 ){
										temp->setJ(temp->getJ()-1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}



							case 2:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 4){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()+1 ){
										temp->setJ(temp->getJ()+1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}


							case 3:
								{
									if(currentShip->getShipNode()->getI() == 'A'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										int cont = 1;
										shipNode *temp=currentShip->getShipNode();
										while(cont != 4){
										if(temp->getI() == 0){
											cout<<"You cant go up"<<endl;
											break;
										}else{
											if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()-1 ){
												temp->setI(temp->getI()-1);
												temp=temp->getNextNode();
												cont++;
											}
											else {cout<<"Cant do this move"<<endl;break;}
										}
									}
									Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
									flag = true;
									break;
									}
									break;
								}
								case 4:
								{
									if(currentShip->getShipNode()->getI() == 'J'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										if(currentShip->getShipNode()->getI() == 'A'){
											cout<<"you cant go up"<<endl;
											break;
										}
										else{
											int cont = 1;
											shipNode *temp=currentShip->getShipNode();
											while(cont != 4){
											if(temp->getI() == 0){
												cout<<"You cant go up"<<endl;
												break;
											}else{
												if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()+1 ){
													temp->setI(temp->getI()+1);
													temp=temp->getNextNode();
													cont++;
												}
												else {cout<<"Cant do this move"<<endl;break;}
											}
										}
										Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
										flag = true;
										break;
										}
										break;
									}
									break;
								}
								default:
								cout<<"Unrecognized Option: "<<useroption<<endl;
								break;
						}
					}while(!flag);
				}
				currentShip = currentShip->getNextShip();
			}
			break;
		}
		case 4:
		{
			ship * currentShip = _Game-> getGameFleet()->getFirstShip();
			while  (currentShip->getNextShip() != NULL)
			{
				if(currentShip->getType() == 'S'){
					bool flag;
					string userinput;
					int useroptionS;
					do
					{
						Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
						cout<<"Choose direction of movement for Scanner Carrier: "<<endl;
						cout<<"1. UP"<<endl;
						cout<<"2. DOWN"<<endl;
						cout<<"3. LEFT"<<endl;
						cout<<"4. RIGHT"<<endl;
						cin>>useroptionS;
						switch(useroptionS)
						{
							case 1:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 4){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()-1 ){
										temp->setJ(temp->getJ()-1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}



							case 2:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 4){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()+1 ){
										temp->setJ(temp->getJ()+1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}


							case 3:
								{
									if(currentShip->getShipNode()->getI() == 'A'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										int cont = 1;
										shipNode *temp=currentShip->getShipNode();
										while(cont != 4){
										if(temp->getI() == 0){
											cout<<"You cant go up"<<endl;
											break;
										}else{
											if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()-1 ){
												temp->setI(temp->getI()-1);
												temp=temp->getNextNode();
												cont++;
											}
											else {cout<<"Cant do this move"<<endl;break;}
										}
									}
									Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
									flag = true;
									break;
									}
									break;
								}
								case 4:
								{
									if(currentShip->getShipNode()->getI() == 'J'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										if(currentShip->getShipNode()->getI() == 'A'){
											cout<<"you cant go up"<<endl;
											break;
										}
										else{
											int cont = 1;
											shipNode *temp=currentShip->getShipNode();
											while(cont != 4){
											if(temp->getI() == 0){
												cout<<"You cant go up"<<endl;
												break;
											}else{
												if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()+1 ){
													temp->setI(temp->getI()+1);
													temp=temp->getNextNode();
													cont++;
												}
												else {cout<<"Cant do this move"<<endl;break;}
											}
										}
										Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
										flag = true;
										break;
										}
										break;
									}
									break;
								}
							default:
								cout<<"Unrecognized Option: "<<useroption<<endl;
								break;
						}
					}while(!flag);
				}
				currentShip = currentShip->getNextShip();
			}
			break;
		}
		case 5:
		{
			ship * currentShip = _Game-> getGameFleet()->getFirstShip();
			while  (currentShip->getNextShip() != NULL)
			{
				if(currentShip->getType() == 'D'){
					bool flag;
					string userinput;
					int useroptionS;
					do
					{
						Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
						cout<<"Choose direction of movement for Destructor: "<<endl;
						cout<<"1. UP"<<endl;
						cout<<"2. DOWN"<<endl;
						cout<<"3. LEFT"<<endl;
						cout<<"4. RIGHT"<<endl;
						cin>>useroptionS;
						switch(useroptionS)
						{
							case 1:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 3){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
								if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()-1 ){
									temp->setJ(temp->getJ()-1);
									temp=temp->getNextNode();
									cont++;
								}
								else {cout<<"Cant do this move"<<endl;break;}
							}
						}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}



							case 2:
							{
								int cont = 1;
								shipNode *temp=currentShip->getShipNode();
								while(cont != 3){
								if(temp->getJ() == 0){
									cout<<"You cant go up"<<endl;
									break;
								}else{
									if(currentShip->getNextShip()->getShipNode()->getJ() != temp->getJ()+1 ){
										temp->setJ(temp->getJ()+1);
										temp=temp->getNextNode();
										cont++;
									}
									else {cout<<"Cant do this move"<<endl;break;}
								}
							}
							Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
							flag = true;
							break;
							}


							case 3:
								{
									if(currentShip->getShipNode()->getI() == 'A'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										int cont = 1;
										shipNode *temp=currentShip->getShipNode();
										while(cont != 3){
										if(temp->getI() == 0){
											cout<<"You cant go up"<<endl;
											break;
										}else{
											if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()-1 ){
												temp->setI(temp->getI()-1);
												temp=temp->getNextNode();
												cont++;
											}
											else {cout<<"Cant do this move"<<endl;break;}
										}
									}
									Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
									flag = true;
									break;
									}
									break;
								}
								case 4:
								{
									if(currentShip->getShipNode()->getI() == 'J'){
										cout<<"you cant go up"<<endl;
										break;
									}
									else{
										if(currentShip->getShipNode()->getI() == 'A'){
											cout<<"you cant go up"<<endl;
											break;
										}
										else{
											int cont = 1;
											shipNode *temp=currentShip->getShipNode();
											while(cont != 3){
											if(temp->getI() == 0){
												cout<<"You cant go up"<<endl;
												break;
											}else{
												if(currentShip->getNextShip()->getShipNode()->getI() != temp->getI()+1 ){
													temp->setI(temp->getI()+1);
													temp=temp->getNextNode();
													cont++;
												}
												else {cout<<"Cant do this move"<<endl;break;}
											}
										}
										Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
										flag = true;
										break;
										}
										break;
									}
									break;
								}
							default:
								cout<<"Unrecognized Option: "<<useroption<<endl;
								break;
						}
					}while(!flag);
				}
				currentShip = currentShip->getNextShip();
			}
			break;
		}
		case 6:
		{
			break;
		}
		default:
			cout<<"Unrecognized Option: "<<useroption<<endl;
			break;
	}
}


void Menu(Game* _Game, Queue * Chat)
{
	if(_Game->haveAttacked() && _Game->haveMoved())
	{
		_Game->setMyTurn();
		_Game->switchAttack();
		_Game->switchMove();
		_Game->getGameFleet()->RegenerateShips();
		string Message = "PSS";
		SendString(Message);
		return;
	}
	else
	{
		printMenu();
		int useroption;
		cin>>useroption;
		switch (useroption)
		{
			case 1:
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				if (!_Game->haveAttacked())
				{
					attackMenu(_Game,Chat);
				}
				else
				{
					cout<<"Can't attack again"<<endl;
					cin.sync();
					cin.ignore();
				}
				cin.clear();
				break;
			}
			case 2:
			{
				Display(_Game-> getGameFleet(),Chat,_Game->getGameDebris());
				if (!_Game->haveMoved())
				{
					Movement(_Game,Chat);
				}
				else
				{
					cout<<"Can't move again"<<endl;
					cin.sync();
					cin.ignore();
				}
				cin.clear();
				break;
			}
			case 3:
			{
				Messaging(_Game,Chat);
				cin.clear();
				break;
			}
			case 4:
			{
				_Game->setMyTurn();
				_Game->switchAttack();
				_Game->switchMove();
				_Game->getGameFleet()->RegenerateShips();
				string Message = "PSS";
				SendString(Message);
				cin.clear();
				break;
			}
			case 5:
			{
				break;
			}
			default:
				cout<<"Unrecognized Option: "<<useroption<<endl;
				break;
		}
	}
}