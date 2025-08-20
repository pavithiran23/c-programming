#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

void preprocess(const char* input, char* modified) {
    int len = strlen(input);
    int j = 0;
    modified[j++] = '^';
    int i;
	for (i = 0; i < len; i++) {
        modified[j++] = '#';
        modified[j++] = input[i];
    }
    modified[j++] = '#';
    modified[j++] = '$';
    modified[j] = '\0';
}

void findLongestPalindromeManacher(const char* input) {
    char modified[2 * MAX_LEN];
    preprocess(input, modified);

    int len = strlen(modified);
    int P[2 * MAX_LEN] = {0};
    int center = 0, right = 0;
	int i;
    for (i = 1; i < len - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            P[i] = (P[mirror] < (right - i)) ? P[mirror] : (right - i);
        }

        while (modified[i + (P[i] + 1)] == modified[i - (P[i] + 1)]) {
            P[i]++;
        }

        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    int max_len = 0;
    int center_index = 0;

	for (i=1; i < len - 1; i++) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }

    int start = (center_index - max_len) / 2;
    printf("Longest palindrome substring is: ");
    for (i = start; i < start + max_len; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
}

int main() {
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; 

    findLongestPalindromeManacher(str);
    return 0;
}


