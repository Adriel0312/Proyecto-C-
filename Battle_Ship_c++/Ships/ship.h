class ship{
    private:
        bool shield;
        bool destroyed;

        int regeneration;
        int regenCounter;
        int resistance;

        int shipLength;
        char oriented;

        char type;
        int color;

        shipNode * coordinates;

        ship * next;

    public:
    	ship(char type,int regen,int resistance,int size,char oriented, string coor, int pcolor){
            this->shield          = true;
    		this->destroyed       = false;

    		this->regeneration    = regen;
    		this->regenCounter    = regen;
    		this->resistance      = resistance;

    		this->shipLength      = size;
    		this->oriented        = oriented;
            
            this->type            = type;
            this->color           = pcolor;

            this->next            = NULL;
            genShip(coor);
    	}

        void genShip(string coor)
        {  
            shipNode * newNode = new shipNode(coor[0],coor[1] -'0',type);
            this-> coordinates = newNode;

            char i;
            int j;
            int counter = 1;

            shipNode *current = newNode;

            while(counter<shipLength)
            {
                if (oriented == 'V')
                {
                    i = current->getI();
                    j = current->getJ()+1;
                }
                else if(oriented == 'H')
                {
                    i = current->getI()+1;
                    j = current->getJ();
                }
                shipNode * newNode = new shipNode(i,j,type);
                current->setNextNode(newNode);
                current = current->getNextNode();
                counter++;
            }
        }

        void swapActive(){
            this->shield=false;
        }

        void regenerate(){
            this->regenCounter--;
            if (regenCounter == 0)
            {
                this->shield=true;
                regenCounter = regeneration;
            }
        }

        void delayRegeneration(int delay)
        {
            this->regenCounter += delay;
        }

        bool decreaseResistance(){
            if (resistance==0)
            {
                this->destroyed = true;
                return false;
            }
            else
            {
                this->resistance--;
                return true;
            }
        }

        void resetRegeneration(int type){
            if (type==1)
                this->regeneration=1;
            else if (type==2)
                this->regeneration=2;
            else if (type==3)
                this->regeneration=4;
            else if (type==4)
                this->regeneration=4;
            else if (type==5)
                this->regeneration=5;
        }

        bool isDestroyed()
        {
            return destroyed;
        }

        shipNode * getShipNode()
        {
            return coordinates;
        }

        void setNextShip(ship * nextShip)
        {
            this->next = nextShip;
        }

        ship * getNextShip()
        {
            return next;
        }

        int getShipColor()
        {
            return color;
        }

        char getType()
        {
            return type;
        }

        bool getShield()
        {
            return shield;
        }
};