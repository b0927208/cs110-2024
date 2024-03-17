#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    inputFile = fopen("main2.c", "r");
    outputFile = fopen("main2.txt", "w");
    int linenum=1;
    fprintf(outputFile,"0%d ",linenum);
    linenum++;
    while ((ch = fgetc(inputFile)) != EOF) {
        if(ch!='\n'){
            fputc(ch, outputFile);
        }
        else{
            if(linenum<10)fprintf(outputFile,"0%d ",linenum);
            else fprintf(outputFile,"%d ",linenum);
            linenum++;
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
