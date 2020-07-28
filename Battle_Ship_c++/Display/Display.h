void showLetters(){
	char letter[10]={'A','B','C','D','E','F','G','H','I','J'};
	gotoxy(7,4);
	printf("%c",letter[0]);

	gotoxy(11,4);
	printf("%c",letter[1]);

	gotoxy(15,4);
	printf("%c",letter[2]);

	gotoxy(19,4);
	printf("%c",letter[3]);

	gotoxy(23,4);
	printf("%c",letter[4]);

	gotoxy(27,4);
	printf("%c",letter[5]);

	gotoxy(31,4);
	printf("%c",letter[6]);

	gotoxy(35,4);
	printf("%c",letter[7]);

	gotoxy(39,4);
	printf("%c",letter[8]);

	gotoxy(43,4);
	printf("%c",letter[9]);
}

void showLettersShots(){
	char letter[10]={'A','B','C','D','E','F','G','H','I','J'};
	gotoxy(64,4);
	printf("%c",letter[0]);

	gotoxy(68,4);
	printf("%c",letter[1]);

	gotoxy(72,4);
	printf("%c",letter[2]);

	gotoxy(76,4);
	printf("%c",letter[3]);

	gotoxy(80,4);
	printf("%c",letter[4]);

	gotoxy(84,4);
	printf("%c",letter[5]);

	gotoxy(88,4);
	printf("%c",letter[6]);

	gotoxy(92,4);
	printf("%c",letter[7]);

	gotoxy(96,4);
	printf("%c",letter[8]);

	gotoxy(100,4);
	printf("%c",letter[9]);

}

bool find(int value){
	int positions[11]={5,9,13,17,21,25,29,33,37,41,45};
	for (int i = 0; i < 11; ++i){
		if (positions[i]==value)
			return true;
	}
	return false;
}

bool findS(int value){
	int positions[11]={62,66,70,74,78,82,86,90,94,98,102};
	for (int i = 0; i < 11; ++i){
		if (positions[i]==value)
			return true;
	}
	return false;
}


void printPlayerBoard(){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console,14);

	int x,y,i,d;
	int number=0;
	showLetters();
	for(i=4;i<46;i++){	
		gotoxy(i,5);
		printf("%c",196);


		gotoxy(i,7);
		printf("%c",196);

		gotoxy(i,9);
		printf("%c",196);

		gotoxy(i,11);
		printf("%c",196);

		gotoxy(i,13);
		printf("%c",196);

		gotoxy(i,15);
		printf("%c",196);

		gotoxy(i,17);
		printf("%c",196);

		gotoxy(i,19);
		printf("%c",196);

		gotoxy(i,21);
		printf("%c",196);

		gotoxy(i,23);
		printf("%c",196);

		gotoxy(i,25);
		if (find(i))
			printf("%c",193);
		else printf("%c",196);

	}


	for (d=4;d<25;d++){
		gotoxy(3,d+2);

		if (d%2==0 & number<10){
			printf("%d",number);
			number++;
		}


		gotoxy(5,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(9,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);
		
		gotoxy(13,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(17,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(21,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(25,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);
		
		gotoxy(29,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(33,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(37,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);
		
		gotoxy(41,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(45,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",180);
	}

	gotoxy(45,25);
	printf("%c",217);
	
	cout<<endl;
}

void printShots(){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console,10);
	int x,y,i,d;
	int number=0;
	showLettersShots();
	for(i=60;i<102;i++){
		gotoxy(i,5);
		printf("%c",196);


		gotoxy(i,7);
		printf("%c",196);

		gotoxy(i,9);
		printf("%c",196);

		gotoxy(i,11);
		printf("%c",196);

		gotoxy(i,13);
		printf("%c",196);

		gotoxy(i,15);
		printf("%c",196);

		gotoxy(i,17);
		printf("%c",196);

		gotoxy(i,19);
		printf("%c",196);

		gotoxy(i,21);
		printf("%c",196);

		gotoxy(i,23);
		printf("%c",196);

		gotoxy(i,25);
		if (findS(i))
			printf("%c",193);
		else printf("%c",196);

	}


	for (d=4;d<25;d++){
		gotoxy(60,d+2);

		if (d%2==0 & number<10){
			printf("%d",number);
			number++;
		}


		gotoxy(62,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(66,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);
		
		gotoxy(70,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);


		gotoxy(74,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(78,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);
		
		gotoxy(82,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(86,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(90,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);
		
		gotoxy(94,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(98,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",197);

		gotoxy(102,d);
		if(d%2==0)
			printf("%c",179);
		else printf("%c",180);
	}

	gotoxy(102,25);
	printf("%c",217);
	
	cout<<endl;
}


void Display(Fleet * pFleet, Queue * Chat, Debris * pDebris){ 
	clearScreen(); 				// limpia toda la pantalla
    printPlayerBoard(); 		// muestra el tablero de barcos
    pFleet->displayFleet();		// muestra la flota de barcos
    Chat->showChat();			// muestra los mesajes del chat
    pDebris->displayDebris();	// muestra los disparos resibidos
    printShots();				// muestra el tablero de disparos

    // cambia el color del texto a blanco
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console,15);  
}

void startWindow(){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console,9);
	clearScreen();
	cout <<"		     JJJJJJJJJJJJJJJJJJJJJJJJJJJJ   IIIIIIIIIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCCCCCCCCCC"<<endl;
	cout <<"		     JJJJJJJJJJJJJJJJJJJJJJJJJJJJ   IIIIIIIIIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCCCCCCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		               JJJJJJJJ                     IIIIIIII            CCCCCC"<<endl;
	cout <<"		     JJJJJJJJJJJJJJJJJJ             IIIIIIIIIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCCCCCCCCCC"<<endl;
	cout <<"		     JJJJJJJJJJJJJJJJJJ             IIIIIIIIIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCCCCCCCCCC"<<endl;
	cout<<"\n"<<endl;
	SetConsoleTextAttribute(console,15); 
}

void setScreenSize()
{
	// changes console dimensions
	HWND console = GetConsoleWindow();
	RECT r;
  	GetWindowRect(console, &r); //stores the console's current dimensions
  	MoveWindow(console, r.left, r.top, 1300, r.bottom - r.top, TRUE);
}