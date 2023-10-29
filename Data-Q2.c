#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

/* Add 100 randomly generated numbers to the list, write the c code that sorts all the
   numbers entered from largest to smallestand prints them on the screen*/
int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}
int main(){
	
    srand(time(NULL));

    int number, i;
    
    printf("How many numbers to be entered: ");
    scanf("%d", &number);
    int n[number];

    // creating numbers randomly
    for(i=0; i<number; i++){
        n[i] = rand()%100;
    }

    // printing the generated numbers to the screen
    printf("\n Randomly generated numbers \n");
    for(i=0; i<number; i++){
        printf("%d, ", n[i]);
    }
    qsort(n, number, sizeof(int), compare);

    printf("\n Numbers from largest to smallest:\n");
    for (i=0; i<number; i++) {
        printf("%d ", n[i]);
    }
    free(n);

    return 0;
}

