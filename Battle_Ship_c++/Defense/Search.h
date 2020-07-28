#include "Sort.h"

class Search{
	public:
		static Node * jump (Node * node, int jumps){
			while (jumps > 0){
				node = node->returnNext();
				jumps--;
			}
			return node;
		}


		static bool binarySearch(List *list,int len,int search) {
			Sort::dynamicShell(list);
			int low=0;//variable para manejar el indice más bajo
			int up=len-1;//variable para manejar el indice más alto
			int index=0;//Indice que se utiliza para realizar el recorrido
			Node *first=list->returnFirst();
			while (up>=low){//Condición, mientras que el indice más alto no sea menor al indice más bajo no se ha recorrido todo el arreglo sin encontrar el elemento
				index=low+((up-low)/2);//Fórmula que se utiliza para la búsqueda binaria, determinar el indice en el que se va ubicar
				int compare=jump(first,index)->returnData();
				if (search==compare){//Comparación del elemento que se busca con el del arreglo
					return true;//Retorna el indice en el que se encontró
				}
				else {
					if (search>compare){//Compara si lo que se busca es mayor al elemento en el que se está
						low=index+1;//Modifica el indice menor para cortar el arreglo y partirlo, el menor será uno más que el indice actual
					}
					else {
						if (search<compare){//Compara si lo que se busca es menor al elemento en el que se está
							up=index-1;//Modifica el indice mayor para cortar el arreglo y partirlo, el mayor será uno menos que el indice actual
						}
					}
					
				}
			}
			return false;//Se recorrió todo el arreglo y no se encontró el elemento
				
		}
		/*
		Función en donde se utiliza el método de interpolación, este método permite acercarnos de una manera más rápida
		al elemento que se está buscando
		*/
		static bool interpolationSearch(List *list,int len,int search){
			Sort::dynamicShell(list);
			int low=0;//variable para manejar el indice más bajo
			int up=len-1;//variable para manejar el indice más alto
			float index1=0;//variable para realizar los recorridos, toma el valor entero de la variable anterior, este determina cual es el indice actual
			int index;
			Node *first=list->returnFirst();
			while (up>low){//Condición para saber cuando se terminó de realizar la búsqueda
				Node *nodeUp=jump(first,up);
				Node *nodeLow=jump(first,low);
				index1=0.5f+((up-low)*(search-nodeLow->returnData())/(nodeUp->returnData()-nodeLow->returnData()));//fórmula que se utiliza en la búsqueda por interpolación, se suma el 0.5 para efectos de redondeo y mejor precisión
				index=index1+low;
				int compare=jump(first,index)->returnData();
				if (search==compare){//Determina si los valores son iguales
					return true;//Retorna el indice en el que se encontró
				}
				else {
					if (search>compare){//Compara si lo que se busca es mayor al elemento en el que se está
						low=index+1;//modifica el indice menor, el nuevo indice menor es uno más que el indice actual en el que se está
					}
					else {
						if (search<compare){//Compara si lo que se busca es menor al elemento en el que se está
							up=index-1;//modifica el indice mayor, el nuevo indice mayor es uno menos que el indice actual en el que se está
						}
					}
				}
			}
			return false;//indica que no se encontró el elemnto
		}
};