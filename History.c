#include <stdio.h>
#include <string.h>

void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand){
    strcpy(commandList[*count], currentCommand);
    *count = *count + 1;
}

void GetHistory(int size, char commandList[100][255]){
    printf("ID | Command name\n");
    for (int i = 0; i < size; i++){
        printf("%d | %s\n", i, commandList[i]);
    }
}