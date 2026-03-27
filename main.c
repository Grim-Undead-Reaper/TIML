#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELP "Show all commands."
#define SET_NEW_NAME "Set a new user name."
#define CLEAR "Clear console."
#define GET_CURRENT_USERNAME "Get Current User."
#define EXIT "Closes the terminal."

int help();
int ClearConsole();
void SetNewName(char *Array);
void GetUsername(char *Array);
int ClearArray(char *Array);

int main()
{
    int Exit = 0;
    while(Exit == 0){
        char CurrentInput[255];
        char CurrentUsername[255];
        printf("Choice one command: ");
        scanf("%s", CurrentInput);

        if (strcmp(CurrentInput, "help") == 0){
            help();
        }
        
        if (strcmp(CurrentInput, "set_new_name") == 0 || strcmp(CurrentInput, "snn") == 0){
            SetNewName(CurrentUsername);
        }

        if (strcmp(CurrentInput, "get_current_username") == 0 || strcmp(CurrentInput, "getuser") == 0){
            GetUsername(CurrentUsername);
        }

        if (strcmp(CurrentInput, "clear") == 0 || strcmp(CurrentInput, "cls") == 0){
            ClearConsole();
        }

        if (strcmp(CurrentInput, "exit") == 0){
            Exit = 1;
            system("pause");
        }
    }
    return 0;
}

int help(){
    printf("\n");
    printf("help: %s\n", HELP);
    printf("set_new_name/snn: %s\n", SET_NEW_NAME);
    printf("get_current_username/getuser: %s\n", GET_CURRENT_USERNAME);
    printf("clear/cls: %s\n", CLEAR);
    printf("exit: %s\n", EXIT);
    printf("\n");
    return 0;
}   

void SetNewName(char *Array){
    printf("New username: ");
    scanf("%s\n", Array);
    printf("\n");
}

void GetUsername(char *Array){

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