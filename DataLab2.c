#include <stdio.h>
#include <stdlib.h>

// CREATE ALONKED LIST
// how we can delete node in the list?

struct student {
	int std_number;
	int age;
	int final;
	int midterm_exam;
	struct student *next; // sonraki, p, q.....
};

typedef struct student node; // now we think just node for struct student

//how we can write a fonk for addnodes in list
node *addNode(node *newNode, int new_data) {
	node *p = newNode;
	// if the list is empty. there is no any node here?
	if(newNode == NULL){
		newNode = (node *)malloc(sizeof(node));
		newNode->next = NULL;
		newNode->std_number = new_data;
		//the new data to be added is the std_number of newNode
		return newNode;
	}
	// if there is a node in list and if new_data is bigger than others..
	// lets add it on right, tail, we should traverse the list
	else if(newNode->std_number<new_data){
		while(p->next != NULL && p->next->std_number<new_data){
			p = p->next;
		}
		node *temp =(node *)malloc(sizeof(node));
		temp->next = NULL; // temp->next = p->next;
		p->next = temp; 
		temp->std_number = new_data;
		
		return newNode;
	}
	// id the new_data is less than head, we should add it on the head of the list
	else{
		node *temp = (node *)malloc(sizeof(node));
		temp->std_number = new_data;
		temp->next = newNode;
		newNode = temp;
		
		return newNode;
	}
}
//print func

void printNodes(node *n){
	//if we want to print all 
	while(n != NULL) {
		printf("%d", n->std_number);
		n = n->next;
	}
}
/// this func should delete nodes on the list
node *deleteNode(node *deletedNode, int data){
	node *temp;
	node *p;
	
	if(deletedNode -> std_number == data){
		temp = deletedNode;
		deletedNode = deletedNode -> next;
		free(temp); // this func delete item
		return deletedNode;
	}
	while(p->next != NULL && p->next->std_number != data){
		p = p->next;
		
	}
	// we cant find the node which is deleted node, we are on tail of the list
	if(p->next == NULL){
		printf("there is no node this std_number");
		return deletedNode;
	}
	temp = p->next;
	p->next = p->next->next;
	free(temp);
	return deletedNode;
}

int main(){
	// all list should have a head, tail=last.
	node *head = (node *)malloc(sizeof(node));
	head->std_number = 23;
	head->next = NULL;
	
	head = addNode(head, 10);
	head = addNode(head, 104);
	head = addNode(head, 41);
	head = addNode(head, 23);
	head = addNode(head, 25);
	head = addNode(head, 33);
	head = addNode(head, 140);
	head = addNode(head, 78);
	printf("our first node`s data ise: %d\n ", head->std_number);
	
	printNodes(head);
	
	head = deleteNode(head, 41);
	head = deleteNode(head, 140);
	head = deleteNode(head, 10);
	printf("\n after the deleting ...");
	
	printNodes(head);
}
