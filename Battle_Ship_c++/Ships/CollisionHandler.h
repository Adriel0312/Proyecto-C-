bool hitBoundary(string coordinates, char orientation, int size)
{
	if (orientation == 'V')
	{
		int iCoor = coordinates[1] -'0';
		if (iCoor+(size-1)>9)
		{
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
			return true;
		}
	}
	return false;
}

bool shipCollisions(Fleet * myFleet, string coordinates)
{
	if (myFleet->getFirstShip() != NULL)
	{
		for (ship* currentShip = myFleet->getFirstShip(); currentShip != NULL; currentShip = currentShip->getNextShip())
		{
			for (shipNode* shipPart = currentShip -> getShipNode(); shipPart !=NULL; shipPart = shipPart ->getNextNode())
			{
				string coor = shipPart->getI() + to_string(shipPart->getJ());
				if (coordinates == coor)
				{
					return true;
				}
			}
		}
	}
	return false;
}