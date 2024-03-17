#include <stdio.h>
#include <string.h>

int main() {
    FILE * inputFile, * outputFile;
    char buffer[1000];
    int lineNumber = 0;
    int found = 0;
    inputFile = fopen("main3.c", "r");
    outputFile = fopen("main3.txt", "w");
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        lineNumber++;
        if (strstr(buffer, "int main() {") != NULL) {
            found = 1;
            break;
        }
    }
    if (found) {
        fprintf(outputFile, "%d int main() {\n", lineNumber);
    } else {
        fprintf(outputFile, "int main() {not found\n");
    }
    fclose(inputFile);
    fclose(outputFile);
    

    return 0;
}
