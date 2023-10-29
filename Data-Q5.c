#include <stdio.h>
#include <stdlib.h>

/* write the function that deletes the next node from the node with the searched student name in the list */
typedef struct Node {
    int data;
    struct Node* next;
    char name; 
} Node;

// Function that displays linked list content
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function that deletes the next node of the given node
void deleteNextNode(Node* node) {
    Node* temp = node->next; // node to delete
    node->next = temp->next;
    free(temp); // recall node from memory
}

// Function that deletes the next node from the node containing the given student name
void deleteNextNodeByName(Node* head, char* name) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->next -> name, name) == 0) {
            deleteNextNode(current);
            return;
        }
        current = current->next;
    }
}

int main() {
    //  create linked list
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
   
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = NULL;
    
    char* name = "Searched student name";
    deleteNextNodeByName(head, name);

    displayList(head);

    // clearing memory
    free(head);
    free(second);

    return 0;
}



