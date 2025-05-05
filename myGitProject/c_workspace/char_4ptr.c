#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Split sentence into words (returns char**)
char **spaceSplit(char *sentence) {
    char **words = malloc(20 * sizeof(char *));
    int wcount = 0;
    char *saveptr;
    char *token = strtok_r(sentence, " ", &saveptr);
    while (token != NULL) {
        words[wcount++] = strdup(token);
        token = strtok_r(NULL, " ", &saveptr);
    }
    words[wcount] = NULL;
    return words;
}

// Main paragraph splitter
char ****splitParag(char *data) {
    char ****document = malloc(20 * sizeof(char ***)); // Lines
    int lineCount = 0;

    char *lineSavePtr;
    char *sentenceSavePtr;
    char *lineToken = strtok_r(data, "\n", &lineSavePtr);

    while (lineToken != NULL) {
        char ***line = malloc(20 * sizeof(char **)); // Sentences
        int sentCount = 0;

        sentenceSavePtr = NULL;  // Reset
        char *sentenceToken = strtok_r(lineToken, ".", &sentenceSavePtr);

        while (sentenceToken != NULL) {
            // Trim leading spaces (optional)
            while (*sentenceToken == ' ') sentenceToken++;

            line[sentCount++] = spaceSplit(sentenceToken);
            sentenceToken = strtok_r(NULL, ".", &sentenceSavePtr);
        }

        line[sentCount] = NULL; // NULL-terminate sentences
        document[lineCount++] = line;

        lineToken = strtok_r(NULL, "\n", &lineSavePtr);
    }

    document[lineCount] = NULL; // NULL-terminate lines
    return document;
}

int main() {
    char input[] = "Learning C is fun.\nLearning pointers is more fun. It is good to have pointers";

    char ****doc = splitParag(input);

    // Example print
    for (int i = 0; doc[i] != NULL; i++) {
        printf("Line %d:\n", i);
        for (int j = 0; doc[i][j] != NULL; j++) {
            printf("  Sentence %d: ", j);
            for (int k = 0; doc[i][j][k] != NULL; k++) {
                printf("[%s] ", doc[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}

