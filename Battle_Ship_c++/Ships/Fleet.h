class Fleet{
private:
	ship * first;
	int counter;

	int itox(char i)
	{
		int base = 7;
		int res = 0;
		char letter[10]={'A','B','C','D','E','F','G','H','I','J'};
		for(int index = 0; index<10; index++)
		{
			if (i == letter[index])
			{
				base = base + (index*4);
			}
		}
		return base;
	}

	int jtoy(int j)
	{
		int base = 6;
		int res = 0;
		for(int i = 0; i<10;i++)
		{
			if (j == i)
			{
				base = base + (i*2);
			}
		}
		return base;
	}	

public:
	Fleet()
	{
		this->first = NULL;
		this->counter = 0;
	}
	void insert(ship * newShip) // inserta barcos a la flota
	{
		if (counter == 0)
		{
			first = newShip;
		}
		else
		{
			ship * currentShip = first;
			while  (currentShip->getNextShip() != NULL)
			{
				currentShip = currentShip->getNextShip();
			}
			currentShip->setNextShip(newShip);
		}

		counter++;
	}

	void displayFleet()
	{
		if (first != NULL) // si esta vacia no hay nada que mostrar
		{
			for (ship* currentShip = first; currentShip != NULL; currentShip = currentShip->getNextShip())     // recorre la lista de barcos
			{	
				for (shipNode* shipPart = currentShip -> getShipNode(); shipPart !=NULL; shipPart = shipPart ->getNextNode())	// recorre los nodos del barco
				{
					if (shipPart->isHit()) // si el estado es hit le cambia el color al nodo
					{
						HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(console,207);
					}
					else	// de lo contrario consigue el color del barco
					{
						HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(console,currentShip->getShipColor());
					}
					// muestra el nodo del barco en la consola
					gotoxy(itox(shipPart->getI()),jtoy(shipPart->getJ())); // mueve el puntero al posicion deseada
					printf("%c",currentShip->getType());
				}
			}
		}
	}

	ship * getFirstShip() // retorna el puentero al primer barco de la flota
	{
		return first;
	}

	bool hittedShip(string coor, bool &shield, bool &destroyed, int delay)
	{
		for (ship* currentShip = first; currentShip != NULL; currentShip = currentShip->getNextShip())     					// recorre la lista de barcos
		{	
			for (shipNode* shipPart = currentShip -> getShipNode(); shipPart !=NULL; shipPart = shipPart ->getNextNode())	// recorre los nodos de cada barco
			{
				if (shipPart->getI() == coor[0] && shipPart->getJ() == coor[1]-'0')											// si la coordenada coinciden (hubo hit)
				{
					shipPart->hitted();																						// modifica el estado de nodo (has been hit)
					shield = currentShip->getShield();																		// consigue el estado del escudo
					if (shield)											// si el ecudo esta arriba
					{
						currentShip->swapActive();						// lo desactiva
					}
					else												// si el ecudo esta abajo
					{
						currentShip->decreaseResistance();				// la resistencia disminuye
						destroyed = currentShip->isDestroyed();			// consige el estado del barco
						currentShip->delayRegeneration(delay);
					}
					return true;										// retorna true hubo hit
				}
			}
		}	
		return false;													// no hubo hit
	}

	void deletShip()
	{
		// revisa si el primer primer barco fue destruido
		if(first->isDestroyed())										// fue destruido
		{
			// lo saca de la lista
			ship* temp = first->getNextShip();
			first->setNextShip(NULL);
			first = temp;	
		} 
		// de lo contrario recorre la lista hast el final buscando un barco destruido
		else
		{
			ship* ShipBefore = first;
			for (ship* currentShip = first->getNextShip(); currentShip != NULL; currentShip = currentShip->getNextShip())
			{	
				if(currentShip->isDestroyed())
				{
					ShipBefore->setNextShip(currentShip->getNextShip());
					currentShip->setNextShip(NULL);
				}
				ShipBefore = currentShip;
			}
		}							
	}

	void RegenerateShips()
	{
		for (ship* currentShip = first; currentShip != NULL; currentShip = currentShip->getNextShip())
			{	
				currentShip->regenerate();
			}
	}
};