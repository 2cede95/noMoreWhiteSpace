#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
/*counting number of vertical lines in file*/
    FILE *fp;
    int count = 0;
    char input[100];
    char c;

    printf("Enter input file name: ");
    scanf("%s", input);

    fp = fopen(input, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", input);
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;

    fclose(fp);

/*initializing variables*/
    char output[100] = {'\0'};
    char text[][255] = {'\0'};
    char line[255] = {'\0'};
    FILE * original = original;
    FILE * noWhiteSpace = noWhiteSpace;

/*prompt and recieve file locations*/
    original = fopen(input, "r");
/*error check*/
    if (original == NULL){
    printf("Input file does not exist or is in another location.");
    return 1;
    }
    printf("Enter output file path: ");
    scanf("%s", output);
    noWhiteSpace = fopen(output, "w");
/*error check*/
    if (output == NULL){
        printf("Error creating file.");
        return 1;
    }
/*cycles through vertical lines*/
for(int j = 0; j < count; j++){
/*gets input*/
        fgets(line, 255, original);
/*removes whitespace horizontally*/
    for (int i = 0; i < sizeof(line);i++){
        if (isspace(line[i]) != 0){
        } else{
/*output text*/
            fprintf(noWhiteSpace, "%c", line[i]);
            line[255] = '\0';
        }
    }
/* new line vertical*/
    fprintf(noWhiteSpace, "\n");
/*clearing line array*/
    memset(line, 0, sizeof line);
}
/*close files*/
    fclose(original);
    fclose(noWhiteSpace);
    return 0;
}
