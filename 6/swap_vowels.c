#include <stdio.h>
#include <string.h>

#define MAX_SIZE 128

int isvowel(char c) {
    switch (c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return 1;
    }
    return 0;
}

void swap_vowels(char str1[], char str2[]) {
    int i = 0, j = 0;

    while (str1[i] != 0 && str2[j] != 0) {
        // Skip to the next vowel in str1
        while (str1[i] != 0 && !isvowel(str1[i])) {
            i++;
        }

        // Skip to the next vowel in str2
        while (str2[j] != 0 && !isvowel(str2[j])) {
            j++;
        }

        // Write your code here
    }
}

int main() {
    char str1[MAX_SIZE] = { 0 };
    char str2[MAX_SIZE] = { 0 };

    printf("Enter the first string: ");
    fgets(str1, MAX_SIZE, stdin);
    str1[strlen(str1)-1] = 0;

    printf("Enter the second string: ");
    fgets(str2, MAX_SIZE, stdin);
    str2[strlen(str2)-1] = 0;

    // Swap the vowels
    swap_vowels(str1, str2);
    printf("%s\n%s\n", str1, str2);

    return 0;
}
