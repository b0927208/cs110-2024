#include <stdio.h>
int main() {
    FILE *inputFile,*outputFile;
    char ch;
    int linenum=1;
    inputFile = fopen("main2.c", "r");
    outputFile = fopen("main2.txt", "w");
    printf("0%d ",linenum);
    linenum++;
    while ((ch = fgetc(inputFile)) != EOF) {
        if(ch!='\n'){
        fputc(ch, outputFile);
        printf("%c",ch);
        }
        else{
            if(linenum<10)printf("0%d ",linenum);
            else printf("%d ",linenum);
            linenum++;
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
