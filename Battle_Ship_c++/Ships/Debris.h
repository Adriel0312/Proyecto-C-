class Debris
{
private:
	int counter;
	debrisNode * first;

	int itox(char i)
	{
		int base = 64;
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
	Debris()
	{
		this->first = NULL;
	}

	void insert(char pI,int pJ)
	{
		debrisNode * newDebris = new debrisNode (pI,pJ);
		if (counter == 0)
		{			
				first = newDebris;
		}
		else
		{
			debrisNode *current = first;
			while (current->getNextNode()!= NULL)
			{
				current = current->getNextNode();
			}
			current->setNextNode(newDebris);
		}
		counter++;
	}

	void displayDebris()
	{
		if (first != NULL)
		{
			for(debrisNode *current = first; current!= NULL; current = current->getNextNode())
			{
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(console,BACKGROUND_RED);
				gotoxy(itox(current->getI()),jtoy(current->getJ()));
				printf("%c",' ');
			}
		}
	}
};