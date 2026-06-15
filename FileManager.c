#include <stdio.h>
#include "FileManager.h"

CommandTypes cmdType[] = {
    {'c', CREATE},
    {'r', READ},
    {'u', UPDATE},
    {'d', DELETE},
};

void CreateFile(char* filemame){
    FILE *file = open(filemame, "w");

    if(file == NULL){
        fclose(file);
    }
}

void ReadFile(char* filepath){}

void UpdateFile(char* filepath){}

void DeleteFile(char* filepath){}

void FileHandler(CommandTypes cmdType){}