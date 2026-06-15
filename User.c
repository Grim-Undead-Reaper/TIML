#include <stdio.h>
#include <string.h>

void SetNewName(char* Array){
    printf("\n");
    printf("New username: ");
    scanf("%254s", Array);
    printf("\nName added Succeessify!\n");
}

void GetUsername(char* Array){

    if (strcmp(Array, "?") == 0){
        strcpy(Array, "Default");
    }

    printf("\nActive user: [%s]\n", Array);
}