#include <stdio.h>
#include <string.h>
#include "FileManager.h"

CommandTypes cmdType[] = {
    {'c', CREATE},
    {'r', READ},
    {'u', UPDATE},
    {'d', DELETE},
};

void CreateFile(char* filemame){
    FILE *file = fopen(filemame, "w");

    if(file != NULL){
        fclose(file);
    }
}

void ReadFile(char* filepath){}

void UpdateFile(char* filepath){}

void DeleteFile(char* filepath){}

void FileHandler(CommandTypes cmdType){}

const int COMMANDSIZE = (sizeof(cmdType)/sizeof(cmdType[0]));

enum types FileInputHandler(){
    char UserInput;
    scanf("%c", &UserInput);
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);

    for (int i = 0; i < COMMANDSIZE; i++){
        if(strcmp(UserInput, cmdType[i].CommandName) == 0){
            return cmdType[i].type;
        }
    }

    return -1;
}