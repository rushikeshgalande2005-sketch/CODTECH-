
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[10][10] = {
    "int", "float", "if", "else", "while",
    "return", "for", "char", "double", "void"
};

int isKeyword(char word[]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[20];
    int i = 0;

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // Identifier or Keyword
        if (isalpha(ch)) {
            word[i++] = ch;

            while (isalnum(ch = fgetc(fp))) {
                word[i++] = ch;
            }

            word[i] = '\0';
            i = 0;

            if (isKeyword(word))
                printf("Keyword: %s\n", word);
            else
                printf("Identifier: %s\n", word);
        }

        // Operator
        if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '=' || ch == '<' || ch == '>') {
            printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}