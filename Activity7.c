#include <stdio.h>
#include <string.h>

// function to remove the second duplicate character
void remove_second_duplicate_char(char* s, char c) {
    int len = strlen(s);
    int j = 0;
    int has_occurred = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            if (!has_occurred) {
                s[j++] = s[i];
                has_occurred = 1;
            }
        } else {
            s[j++] = s[i];
            has_occurred = 0;
        }
    }

    // Remove the trailing whitespace if any
    while (j > 0 && s[j - 1] == ' ') {
        j--;
    }

    s[j] = '\0';
}

int main() {
    char s1[] = "Hello";
    char c1 = 'l';
    remove_second_duplicate_char(s1, c1);
    printf("Result: %s\n", s1); // Output: Helo

    char s2[] = "Hello World";
    char c2 = 'l';
    remove_second_duplicate_char(s2, c2);
    printf("Result: %s\n", s2); // Output: Helo Word

    return 0;
}
