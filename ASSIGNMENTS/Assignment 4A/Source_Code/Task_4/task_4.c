#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char text[256], words[100][64];
    int m, n;
    bool dp[257] = {false};

    printf("Enter text (no spaces): ");
    scanf("%255s", text);
    printf("Enter number of dictionary words: ");
    scanf("%d", &m);
    if (m < 0 || m > 100) return 1;

    for (int i = 0; i < m; i++) {
        printf("Enter dictionary word: ");
        scanf("%63s", words[i]);
    }

    n = (int)strlen(text);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int len = i - j;
            char piece[256];
            if (!dp[j]) continue;
            memcpy(piece, text + j, len);
            piece[len] = '\0';
            for (int k = 0; k < m; k++) {
                if (strcmp(piece, words[k]) == 0) {
                    dp[i] = true;
                    break;
                }
            }
            if (dp[i]) break;
        }
    }

    printf("Can the text be segmented? %s\n", dp[n] ? "TRUE" : "FALSE");
    return 0;
}
