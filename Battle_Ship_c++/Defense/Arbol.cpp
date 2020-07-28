using namespace std;

#include "Tree.h"

int main () {
	AVLTree *enteros = new AVLTree ();

	enteros->insert(12);
	enteros->insert(4);
	enteros->insert(53);
	enteros->insert(6);
	enteros->insert(85);
	enteros->insert(9);
	
	enteros->preorden(enteros->getRoot());
}