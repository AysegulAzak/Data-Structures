#include <stdio.h>
#include <string.h>

/* write the function that prints the record with the longest name in the list */
void longestName(char record[][50], int n) {
    int maxLength = 0;
    char theLongest[50];
    int i;

    for (i=0; i<n; i++) {
        if (strlen(record[i]) > maxLength) { // the length of each name is checked
            maxLength = strlen(record[i]);
            strcpy(theLongest, record[i]);
        }
    }
    printf("Longest name on the list: %s\n", theLongest);
    printf("Length: %d\n", strlen(theLongest));
}
int main() {
    char record[][50] = {"Aysegul", "Abdurrahmangazi", "Deniz" };

    int n = sizeof(record) / sizeof(record[0]); //finding how many elements there are in a record array

    longestName(record, n);

    return 0;
}



