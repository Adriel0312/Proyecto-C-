class Node {
	private:
		int data;
		Node *next; 	// pointer type nodo, saves the address of the next nodo 

	public:
		Node (int data) {		// constructor 
			this->data = data;	// access the atribute dato from the instance created and assigns it the received argument  
			next = NULL;	// siguiente is a pointer, if it is not been use it needs to point to NULL, if not it will point to anything in memory causing a denied access to memory error 
		}

		int returnData() {		// int function that returns the data in the nodo object
			return data;
		}
		Node* returnNext() {	// nodo type function that returns the address to the next nodo object
			return next;
		}
		void changeNext(Node *next) {	// void function that changes the address of the pointer to the next nodo object
			this->next = next;
		}
		void changeData(int data){
			this->data = data;
		}
};