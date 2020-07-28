#include <iostream>
#include <string.h>

using namespace std;

#include "Node.h"
#include "List.h"
#include "Search.h"
#include "Sort.h"

//#include "List.h"


int main () {
	List *enteros = new List ();
	Node *prim=enteros->returnFirst();
	enteros->insert(12);
	enteros->insert(4);
	enteros->insert(53);
	enteros->insert(6);
	enteros->insert(85);
	enteros->insert(9);
	//enteros->push(prim,12);
	//enteros->push(prim,4);
	//enteros->push(prim,53);
	//enteros->push(prim,6);
	//enteros->push(prim,85);
	//enteros->push(prim,9);
	Sort::MergeSort(enteros->returnFirst());
	//bool result=Search::binarySearch(enteros,6,53);
	//if (result==true)
		//cout<<"Hola"<<endl;
	//else cout<<"No"<<endl;

	//enteros->dynamicMerge(enteros,0,6);
	//enteros->imprimir ();
	/*
	nodo *buscado = enteros->buscar (85);
	if (buscado != NULL)
		cout << "Encontrado: "<< buscado->retornaDato () << "\n";
	else cout << "No encontrado\n";

	enteros->borrar (12);
	*/
	enteros->imprimir ();
	enteros->printList(prim);

}