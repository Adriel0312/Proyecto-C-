SOCKET Connection;					//This client's connection to the server

bool SendInt(int _int)
{
	int RetnCheck = send(Connection, (char*)&_int, sizeof(int), NULL); 	// send int: _int
	if (RetnCheck == SOCKET_ERROR) 										// If int failed to send due to connection issue
		return false; 													// Return false: Connection issue
	return true; 														// Return true: int successfully sent
}

bool GetInt(int & _int)
{
	int RetnCheck = recv(Connection, (char*)&_int, sizeof(int), NULL); 	// receive integer
	if (RetnCheck == SOCKET_ERROR) 										// If there is a connection issue
		return false; 													// return false since we did not get the integer
	return true;														// Return true if we were successful in retrieving the int
}

bool SendString(string & _string)
{
	int bufferlength = _string.size(); 										// Find string buffer length
	if (!SendInt(bufferlength)) 											// Send length of string buffer, If sending buffer length fails...
		return false; 														// Return false: Failed to send string buffer length
	int RetnCheck = send(Connection, _string.c_str(), bufferlength, NULL); 	// Send string buffer
	if (RetnCheck == SOCKET_ERROR) 											// If failed to send string buffer
		return false; 														// Return false: Failed to send string buffer
	return true; 															// Return true: string successfully sent
}

bool GetString(string & _string)
{
	int bufferlength;					 							// Holds length of the message
	if (!GetInt(bufferlength)) 										// Get length of buffer and store it in variable: bufferlength
		return false; 												// If get int fails, return false
	char * buffer = new char[bufferlength + 1];	 					// Allocate buffer
	buffer[bufferlength] = '\0'; 									// Set last character of buffer to be a null terminator so we aren't printing memory that we shouldn't be looking at
	int RetnCheck = recv(Connection, buffer, bufferlength, NULL); 	// receive message and store the message in buffer array, set RetnCheck to be the value recv returns to see if there is an issue with the connection
	_string = buffer;	 											// set string to received buffer message
	delete[] buffer; 												// Deallocate buffer memory (cleanup to prevent memory leak)
	if (RetnCheck == SOCKET_ERROR)	 								// If connection is lost while getting message
		return false; 												// If there is an issue with connection, return false
	return true;													// Return true if we were successful in retrieving the string
}

void sendElements(int low, int high)
{
	srand(time(NULL));
	int range = low+rand()%(high+1);
	int randNumber;
	string message;
	for(int i = 0; i<range;i++)
	{
		randNumber=rand()%1000;
		message = "ELM|"+to_string(randNumber);
		SendString(message);
	}
	message = "ELM|0";
	SendString(message);
}

int getIDType(string & ID)
{
	if (ID == "MSG")
		return 1;
	if (ID == "UBI")
		return 2;
	if (ID == "CAC")
		return 3;
	if (ID == "RCC")
		return 4;
	if (ID == "BAL")
		return 5;
	if (ID == "ORD")
		return 6;
	if (ID == "BUS")
		return 7;
	if (ID == "ELM")
		return 8;
	if (ID == "RST")
		return 9;
	if (ID == "RRS")
		return 10;
	if (ID == "HIT")
		return 11;
	if (ID == "MSS")
		return 12;
	if (ID == "DST")
		return 13;
	if (ID == "PSS")
		return 14;
	if (ID == "END")
		return 15;
	if (ID == "SUR")
		return 16;
	return 0;
}