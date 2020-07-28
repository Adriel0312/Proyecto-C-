class shipNode
{
	private:
		int j;
		char i;
		char type;
		bool hit;
		shipNode * nextNode;
	public:
		shipNode(char pI,int pJ,char pType)
		{
			this-> i = pI;
			this-> j = pJ;
			this-> type = pType;
			this-> hit = false;
			this-> nextNode = NULL;
		}

		void setNextNode(shipNode * next)
		{
			this-> nextNode = next;
		}

		shipNode * getNextNode()
		{
			return nextNode;
		}

		char getType()
		{
			return type;
		}

		void setI(char  newi){
			this->i=newi;
		}
		void setJ(int  newj){
			this->j=newj;
		}
		
		char getI()
		{
			return i;
		}

		int getJ()
		{
			return j;
		}

		void hitted()
		{
			hit = true;
		}

		bool isHit()
		{
			return hit;
		}
};