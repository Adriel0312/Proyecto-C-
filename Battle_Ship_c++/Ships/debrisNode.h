class debrisNode
{
	private:
		int j;
		char i;
		debrisNode * nextNode;
	public:
		debrisNode(char pI,int pJ)
		{
			this-> i = pI;
			this-> j = pJ;
			this-> nextNode = NULL;
		}

		void setNextNode(debrisNode * next)
		{
			this-> nextNode = next;
		}

		debrisNode * getNextNode()
		{
			return nextNode;
		}

		char getI()
		{
			return i;
		}

		int getJ()
		{
			return j;
		}
};