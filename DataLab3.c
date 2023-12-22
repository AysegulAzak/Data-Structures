#include <stdio.h>
#include <stdlib.h>

struct student {
	int std_number;
	int age;
	int midterm_exam;
	int final;
	struct student *next;
};
typedef struct student node;

node *addNode(node *newNode, int new_data){
	node *p = newNode;
	
	if(newNode == NULL){
		newNode = (node*)malloc(sizeof(node));
		newNode -> next = NULL;
		newNode -> std_number = new_data;
		return newNode;
	}
	else if(newNode -> std_number < new_data){
		while(p -> next != NULL && p -> next -> std_number < new_data){
			p = p -> next;
		}
	    node *temp = (node*)malloc(sizeof(node));
		temp -> next = NULL;
		p -> next = temp;
		temp -> std_number = new_data;
		return newNode;
	}
}
void printNodes(node *n){
	while(n != NULL){
		printf("%d\t", n -> std_number);
		n = n -> next;
	}
}

int main(){
	node *head = (node*)malloc(sizeof(node));
	head -> std_number = 23;
	head -> next = NULL;
	
	head = addNode(head,10);
	head = addNode(head,104);
	head = addNode(head,41);
	head = addNode(head,23);
	head = addNode(head,25);
	head = addNode(head,33);
	head = addNode(head,140);
	head = addNode(head,78);
	

	printf("our first node's data ise: %d\n", head -> std_number);
	
	printNodes(head);
}
