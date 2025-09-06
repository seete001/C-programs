#include <stdio.h>
#include <string.h>

#define MAX_SIZE_DATA 1000

int main() {
    int i = 0;
    char data[MAX_SIZE_DATA];
    char infile[256];

    printf("Enter the file name: ");
    if (fgets(infile, sizeof(infile), stdin) == NULL) {
        printf("Error reading filename.\n");
        return 1;
    }

    // Remove newline character
    size_t len = strlen(infile);
    if (len > 0 && infile[len - 1] == '\n') {
        infile[len - 1] = '\0';
    }

    printf("Filename entered: '%s'\n", infile);

    FILE *file = fopen(infile, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    int ch;
    while (i < MAX_SIZE_DATA && (ch = getc(file)) != EOF) {
        data[i++] = (char)ch;
    }
    fclose(file);

    // XOR encode
    for (int j = 0; j < i; j++) {
        data[j] ^= 0x60;
    }

    FILE *outfile = fopen(infile, "w");
    if (outfile == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fwrite(data, sizeof(char), i, outfile);
    fclose(outfile);

    printf("File '%s' encoded successfully.\n", infile);

    return 0;
}

