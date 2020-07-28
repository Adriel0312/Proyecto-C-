class Sort{
public:
	static Node * jump (Node * node, int jumps){
		while (jumps > 0){
			node = node->returnNext();
			jumps--;
		}
		return node;
	}

	static void swap (Node * Node0, Node * Node1){
		int temp = Node0->returnData();
		Node0->changeData(Node1->returnData());
		Node1->changeData(temp);
	}

	static void dynamicShell(List * list, int lsize){
		int gap, i, j;
		gap = lsize/2;
		
		while (gap > 0){
			for (i=gap; i<lsize; i++){
				cout <<"\n";
				j = i-gap;
				while(j>=0){
					int k = j + gap;
					Node * firstJump = jump(list->returnFirst(),j);
					Node * secondJump = jump(list->returnFirst(),k);
					if (firstJump->returnData()<=secondJump->returnData()){
						j=-1;
					}
					else{
						Node * swapping = firstJump->returnNext();
						swap(firstJump,swapping);
						j-=gap;
					}
				}
			}
			gap = gap/2;
			list->imprimir();
		}
	}

	static void MergeSort( Node* headRef){
		Node* head = headRef;
	    Node* a;
		Node* b;
		 
		  /* Base case -- length 0 or 1 */
		if ((head == NULL) || (head->returnNext() == NULL)){
			return;
		}
		 
		  /* Split head into 'a' and 'b' sublists */
		FrontBackSplit(head, a, b); 
		 
		  /* Recursively sort the sublists */
		MergeSort(a);
		MergeSort(b);
		 
		  /* answer = merge the two sorted lists together */
		headRef = SortedMerge(a, b);
	}
		 
		
	static Node* SortedMerge( Node* a,  Node* b){
		Node* result = NULL;
		 
		  /* Base cases */
		if (a == NULL)
		    return(b);
		else if (b==NULL)
		    return(a);
		 
		  /* Pick either a or b, and recur */
		if (a->returnData() <= b->returnData()){
		    result = a;
		    result->changeNext(SortedMerge(a->returnNext(), b));
		}
		else {
		    result = b;
		    result->changeNext(SortedMerge(a, b->returnNext()));
		}
		return(result);
	}
		 
		/* UTILITY FUNCTIONS */
		/* Split the nodos of the given list into front and back halves,
		     and return the two lists using the reference parameters.
		     If the length is odd, the extra nodo should go in the front list.
		     Uses the fast/slow pointer strategy.  */
	static void FrontBackSplit( Node* source,Node* frontRef,  Node* backRef){
		Node* fast;
		Node* slow;
		if (source==NULL || source->returnNext()==NULL){
			frontRef = source;
		    backRef = NULL;
		}
		else{
		    slow = source;
		    fast = source->returnNext();
		 
		    /* Advance 'fast' two nodos, and advance 'slow' one nodo */
		    while (fast != NULL){
		      fast = fast->returnNext();
		      if (fast != NULL){
		        slow = slow->returnNext();
		        fast = fast->returnNext();
		      }
		    }
		 
		    /* 'slow' is before the midpoint in the list, so split it in two
		      at that point. */
		    frontRef = source;
		    backRef = slow->returnNext();
		    slow->changeNext(NULL);
		}
	}

};