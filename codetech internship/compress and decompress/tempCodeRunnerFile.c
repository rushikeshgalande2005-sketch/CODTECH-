
#include <stdio.h>

void compressFile() {
    FILE *fp1, *fp2;
    char ch, prev;
    int count = 1;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("compressed.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File error!\n");
        return;
    }

    prev = fgetc(fp1);

    while ((ch = fgetc(fp1)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(fp2, "%c%d", prev, count);
            prev = ch;
            count = 1;
        }
    }

    fprintf(fp2, "%c%d", prev, count);

    fclose(fp1);
    fclose(fp2);
    printf("File compressed successfully!\n");
}

void decompressFile() {
    FILE *fp1, *fp2;
    char ch;
    int count;

    fp1 = fopen("compressed.txt", "r");
    fp2 = fopen("decompressed.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File error!\n");
        return;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        fscanf(fp1, "%d", &count);
        for (int i = 0; i < count; i++) {
            fputc(ch, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    printf("File decompressed successfully!\n");
}

int main() {
    int choice;

    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        compressFile();
    else if (choice == 2)
        decompressFile();
    else
        printf("Invalid choice!\n");

    return 0;
}