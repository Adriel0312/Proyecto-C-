class List {
	private:
		Node *first; 	// pointer type nodo, saves the address of the first nodo in the list 
		int len; 	// saves the number of nodos (elements) that are in the list
	public:
		List () { 		// constructor 
			first = NULL;	// the list is created empty, there are no elements so the pointer primero points to NULL
			len = 0;	// the list is created empty, there are no elements so the count of elements is 0
		}

		void insert (int data) {			// void function that adds a new element to the list
			Node *newNode = new Node(data);	// creates a pointer to a new nodo type object  

			if (len == 0)			// cantidad = to 0, means there is no elements in the list 	
				first = newNode;		// the address of the nuevo nodo is assigned to the primero pointer
			else {
				Node *current = first;
				while (current->returnNext () != NULL)
					current = current->returnNext();
					current->changeNext(newNode);
			}

			len++;
		}

		
		void imprimir () {
			if (len>0){
				int i = 0;
				Node *actual = first;
				cout << "La lista contiene " << len << " elementos\n";
				while (actual != NULL) {
					cout << "[" << i << "]	" << actual->returnData () << "\n";
					actual = actual->returnNext();
					i++;
				}
			}
			else {cout << "Lista vacia.\n";}
		}
		
		Node* returnFirst(){
			return first;
		}
		
		int returnLen(){
			return len;
		}
};