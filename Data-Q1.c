#include <stdio.h>
#include <stdlib.h>

/* write a function that adds all odd numbers to the beginning of the list and 
   all even numbers to the end of the list until -1 is entered from the keyboard */
struct Node {
	int data;
	struct Node* next;
};   

/* func do that add new nodes, if its even end of the list or its odd beginning of the list*/
void insertNode(struct Node **head, int value){ // value = numbers entered from ky
    // there is not a list here
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); //first node,
    newNode -> data = value;
    newNode -> next = NULL;
    
    if(*head == NULL){
    	*head = newNode; /* first node is should be head, not important even or odd.
    	                    this node is also head and end of the list */
	}
	else if(newNode ->  data %2 != 0){ // this number is odd should add it head
		struct Node *current = newNode; // 7
		current -> data = value;
		current -> next = *head; // 5
		*head = current;
	}
	else{ // its data is even so add it end of the list
	     struct Node *current = *head; // the current pointer shows us head of the list
	     // should traverse the list because we need to go end of the list
	     while(current -> next != NULL){ // we are not on the end of the list
	           current = current -> next;
		 } /* end of the while loop means that the pointer shows the last node
		      we should add the newNode next to the last node. */
		      current -> next = newNode;
	}
}
int main(){
	int value;
	struct Node *head = NULL;
	
	printf("Enters datas to add the list(for exit -1) : \n "); // exit case: -1
	
	while(1){ // ýnfýnýte loop, true == 1
	     scanf("%d", &value);
	     if(value == -1)
	        break;
	        
	        //if the number is different from -1, should add it newNode s data
	        // we should call the func
	        insertNode(&head, value);
	}
	struct Node *current = head;
	
	// ý want to see all nodes on screen
	printf("List start with: ");
	
	while(current != NULL){
		printf("%d -> ", current -> data);
		current = current -> next;
	}
	printf("end of the list \n ");
}

