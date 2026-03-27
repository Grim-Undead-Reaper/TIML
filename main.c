#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELP "Show all commands."
#define SET_NEW_NAME "Set a new user name."
#define CLEAR "Clear console."
#define GET_CURRENT_USERNAME "Get Current User"

int help();
int ClearConsole();
void SetNewName(char *Array);
int GetUsername(char *Array);
int ClearArray(char *Array);

int main(){
    return 0;
}

int help(){
    printf("\n");
    printf("HELP: %s\n", HELP);
    printf("SET_NEW_NAME/snn: %s\n", SET_NEW_NAME);
    printf("GET_CURRENT_USERNAME/snn: %s\n", GET_CURRENT_USERNAME);
    printf("clear/cls: %s\n", CLEAR);
    printf("\n");
    return 0;
}   

void SetNewName(char *Array){
    char Array[255];
    scanf("%s\n", Array);
    printf("\n");
}

int GetUsername(char *Array){

    if (strcmp(Array, "\n") == 0 || strcmp(Array, "\0") == 0){
        Array = "Default";
    }

    printf("Active user: [%s]", Array);
}

int ClearConsole(){
    system("cls");
}

int ClearArray(char *Array){
    for (int i = 0; i < sizeof(Array)/sizeof(Array[0]); i++){
        Array[i] = '\0';
    }

    return 0;
}