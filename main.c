#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

	FILE *original = fopen(argv[1], "r");
	FILE *noWhiteSpace = fopen(argv[2], "w");
	
	/*Argument check*/
	if (argc > 3){
		printf("Invalid arguments");
		return 1;
	}
	/*original file check*/
	if (original == NULL) {
		printf ("Error reading file");
		return 1;
	}
	/*counting vertical lines*/
	FILE *originalCount = fopen(argv[1], "r");
	int count = 0;
	for (char c = getc(originalCount); c != EOF; c = getc(originalCount)){
		if (c= '\n'){
			count++;
			}
	}
	fclose(originalCount);
	/*printing non SP and \n characters*/
	char line[255];
	for (int j = 0; j < count + 1;j++){
		fgets(line, 255, original); 
		for (int i=0;i < strlen(line);i++){
		if (line[i] != 32 && line[i] != '\n'){
			fprintf(noWhiteSpace, "%c", line[i]);
			}
			}
	}
	fclose(original);
	fclose(noWhiteSpace);
	
	return 0;
}
