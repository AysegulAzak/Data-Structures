#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    int length = 0;
    char* lastWord;
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        lastWord = word;
        word = strtok(NULL, " ");
    }
    length = strlen(lastWord);
    
    printf("Length of the last word: %d\n", length);
    
    return 0;
}

