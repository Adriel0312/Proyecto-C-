
class Game
{
private:
	int playerNumber;
	bool myTurn;
	bool attacked;
	bool moved;
	Fleet * gameFleet;
	Debris * gameDebris;

public:
	Game()
	{
		this->gameFleet = new Fleet();
		this->gameDebris = new Debris();
		this->attacked = false;
		this->moved = false;
	}

	void startTurn(int playerNumber)
	{
		this->playerNumber = playerNumber;
		if (playerNumber == 1)
		{
			myTurn = true;
		}
		else
		{
			myTurn = false;
		}
	}

	void setGameFleet(Fleet * newfleet)
	{
		this->gameFleet = newfleet;
	}

	void setGameDebris(Debris * newDebris)
	{
		this->gameDebris =  newDebris;
	}

	Debris * getGameDebris()
	{
		return gameDebris;
	}

	Fleet * getGameFleet()
	{
		return gameFleet;
	}

	void setMyTurn()
	{
		if (myTurn)
		{
			myTurn = false;
		}
		else
		{
			myTurn = true;
		}
	}

	bool isMyTurn()
	{
		return myTurn;
	}

	bool haveAttacked()
	{
		return attacked;
	}

	void switchAttack()
	{
		this->attacked = !attacked;
	}

	void switchMove()
	{
		this->moved = !moved;
	}

	bool haveMoved()
	{
		return moved;
	}
};