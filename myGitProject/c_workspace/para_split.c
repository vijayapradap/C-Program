#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word {
    char* data;
};

struct sentence {
    struct word* word;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* sen  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* para;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
    struct document doc;
    doc.para = malloc(5 * sizeof(struct paragraph));
    doc.paragraph_count = 0;

    char *lineSavePtr = NULL, *sentenceSavePtr = NULL, *wordSavePtr = NULL;
    
    char *temp = strdup(text);  // Create copy because strtok_r modifies it
    char *lineToken = strtok_r(temp, "\n", &lineSavePtr);

    while (lineToken != NULL) {
        struct paragraph *current_paragraph = &doc.para[doc.paragraph_count];
        current_paragraph->sen = malloc(50 * sizeof(struct sentence));
        current_paragraph->sentence_count = 0;

        sentenceSavePtr = NULL;
        char *sentenceToken = strtok_r(lineToken, ".", &sentenceSavePtr);

        while (sentenceToken != NULL) {
            struct sentence *current_sentence = &current_paragraph->sen[current_paragraph->sentence_count];
            current_sentence->word = malloc(50 * sizeof(struct word));
            current_sentence->word_count = 0;

            wordSavePtr = NULL;
            char *wordToken = strtok_r(sentenceToken, " ", &wordSavePtr);

            while (wordToken != NULL) {
                current_sentence->word[current_sentence->word_count].data = strdup(wordToken);
                current_sentence->word_count++;
                wordToken = strtok_r(NULL, " ", &wordSavePtr);
            }

            current_paragraph->sentence_count++;
            sentenceToken = strtok_r(NULL, ".", &sentenceSavePtr);
        }

        doc.paragraph_count++;
        lineToken = strtok_r(NULL, "\n", &lineSavePtr);
    }

    free(temp); // clean up copied text
    return doc;
}


int main()
{
    char input[] = "Learning C is fun.\nLearning pointers is more fun. It is good to have pointers";
    
    struct document mine = get_document(input);

    for(int i=0; i<mine.paragraph_count; i++) {
            for(int j=0; j<mine.para[i].sentence_count; j++) {
            for(int k=0; k<mine.para[i].sen[j].word_count; k++)
                printf("%s ", mine.para[i].sen[j].word[k].data);
        
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
