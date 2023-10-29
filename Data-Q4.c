#include <stdio.h>
#include <string.h>

/* write the function that searches records by student name in the list */
typedef struct {
    char name[50];
    char surname[50];
    int no;
} Student;

// The function took the Student array and number of students information,
//  and the searched name as parameters.
void SearchRecords(Student students[], int numberOfStudent, char searchedName[]) {
    int i;
    for (i=0; i<numberOfStudent; i++) { // Checking incoming student information
        if (strcmp(students[i].name, searchedName) == 0) {
            printf("Found record! \n");
            printf("Name: %s\n", students[i].name);
            printf("Surname: %s\n", students[i].surname);
            printf("Numara: %d\n", students[i].no);
            return;
        }
    }
    printf("No records found! \n"); 
}

//  added student information to the student array
int main() { 
    Student students[2];
    strcpy(students[0].name, "Aysegul");
    strcpy(students[0].surname, "Azak");
    students[0].no = 598;

    strcpy(students[1].name, "Deniz");
    strcpy(students[1].surname, "Ay");
    students[1].no = 256;
    
    SearchRecords(students, 2, "Aysegul");

    return 0;
}



