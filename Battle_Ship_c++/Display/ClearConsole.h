#include <windows.h>
#include <iostream>

void clearScreen()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = {0,0};									// home for the cursor
	DWORD 	charsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD consoleSize;

	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(console, &csbi))
	{
		return;
	}
	consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(console, (TCHAR) ' ', consoleSize, coordScreen, &charsWritten))
	{
		return;
	}

	// Get the current text attribute.
	if(!FillConsoleOutputAttribute(console, csbi.wAttributes, consoleSize, coordScreen, &charsWritten))
	{
		return;
	} 

	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(console, coordScreen);
}

void clearScreen(int x, int y, int width, int height)
{
	for (int j = y; j< height; j++)
	{
		for(int i = x; i< width; i++)
		{
			COORD cursor = {(SHORT)i,(SHORT)j};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
			cout<<' ';
		}
	}
}