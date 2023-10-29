#include <stdio.h>
#include <stdlib.h>

/* Write a func that stores the student number, name and age, traverses all
   the nodes in the list, writes all the student information on the screen and counts it */
struct Student {
    int student_id;
    char name[50];
    int age;
    struct Student* next;
};

void student_info(struct Student* head) {
    struct Student* temp = head;
    int i = 0;

    while (temp != NULL) {
        printf("student_id: %d ", temp -> student_id);
        printf("name: %s ", temp -> name);
        printf("age: %d \n", temp -> age);

        i++;
        temp = temp -> next;
    }

    printf("Total number of students: %d\n", i);
}

int main() {
    // Create a student node
    struct Student* student1 = malloc(sizeof(struct Student));
    struct Student* student2 = malloc(sizeof(struct Student));
    

    // assignment of student information
    student1 -> student_id = 1;
    strcpy(student1 -> name, "Aysegul");
    student1 -> age = 21;
    student1 -> next = student2;

    student2 -> student_id = 2;
    strcpy(student2 -> name, "Berke");
    student2 -> age = 19;
    student2 -> next = NULL;

    // call the function
    student_info(student1);

    // memory clearing
    free(student1);
    free(student2);

    return 0;
}

