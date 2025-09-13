#include <stdio.h>
#include <string.h>

// Function to expand from the middle and return palindrome length
int expandFromCenter(char *s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

void longestPalindrome(char *s) {
    int n = strlen(s);
    if (n == 0) {
        printf("Empty string\n");
        return;
    }

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expandFromCenter(s, i, i, n);     // Odd length palindrome
        int len2 = expandFromCenter(s, i, i + 1, n); // Even length palindrome
        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", s[i]);
    }
    printf("\nLength: %d\n", maxLen);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    longestPalindrome(str);

    return 0;
}
 
