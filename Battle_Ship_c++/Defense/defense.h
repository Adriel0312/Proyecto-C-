#include <iostream>
#include <string.h>
#include <sstream>
#include "ship.h"
#include "ShipNode.h"
#include "Fleet.h"

class defense{
	Fleet* hunting(char i,int j,Fleet *ships){
		shipNode *ship=ships->getFirstShip();
		string array[4];
		char* intV[10];
		string temp;
		int counter;
		while (ship!=NULL){
			if (i+1==ship->getI() | j+1==ship->getJ()){
				temp=itoa(ship->getJ(),intV,10);
				array[counter]+=ship->getI()+temp;
				ship->getNextNode();
				counter++;
			}
			else if(j+1=ship->getJ() | j-1=ship->getJ()){
				temp=itoa(ship->getJ(),intV,10);
				array[counter]+=ship->getI()+temp;
				ship->getNextNode();
				counter++;
			}
			ship->getNextNode();

		return coor;
	}

	 int tracker(char i,int j,Fleet *ships){
	 	shipNode *ship=ships->getFirstShip();
	 	int counter=0;
		while (ship!=NULL){
			if (j+1==ship->getJ() | j-1==ship->getJ())
				counter++;
			if(i+1==ship->getI() | i-1=ship->getI())
				counter++;
			if(i+1=ship->getI() & (j+1=ship->getJ() | j-1=ship->getJ()))
				counter++;
			if(i-1=ship->getI() & (j+1=ship->getJ() | j-1=ship->getJ()))
				counter++;

			ship->getNextNode();
		}
		return counter; 

	 }
}