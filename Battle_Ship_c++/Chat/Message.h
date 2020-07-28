class Message
{
private:
	string time;
	string message;
	string type;
	Message * nextMessage;

public:
	Message(string pMessage, string pType)
	{
		this->nextMessage = NULL;
		this->message 	= pMessage;
		this->type 		= pType;
	}

	void setNextMessage(Message * pNextMessage)
	{
		this->nextMessage = pNextMessage;
	}
	void setMessage(string pMessage)
	{
		this->message = pMessage;
	}

	void setType(string pType)
	{
		this->type = pType;
	}
	string getMessage()
	{
		return message;
	}

	Message * getNextMessage()
	{
		return nextMessage;
	}

	string getType()
	{
		return type;
	}
};