#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELP "Show all commands."
#define SET_NEW_NAME "Set a new user name."
#define CLEAR "Clear console."
#define GET_CURRENT_USERNAME "Get Current User."
#define EXIT "Closes the terminal."
#define VERSION "Version 0.0.7"

int help();
int ClearConsole();
void SetNewName(char *Array);
void GetUsername(char *Array);
int ClearArray(char *Array);
void CurrentVersion();

int main()
{
    system("cls");
    int Exit = 0;
    while(Exit == 0){
        char CurrentInput[255];
        char CurrentUsername[255];
        printf("\n");
        scanf("%s", CurrentInput);

        if (strcmp(CurrentInput, "help") == 0){
            help();
        } else if (strcmp(CurrentInput, "set_new_name") == 0 || strcmp(CurrentInput, "setuser") == 0){
            SetNewName(CurrentUsername);
        } else if (strcmp(CurrentInput, "get_current_username") == 0 || strcmp(CurrentInput, "getuser") == 0){
            GetUsername(CurrentUsername);
        } else if (strcmp(CurrentInput, "clear") == 0 || strcmp(CurrentInput, "cls") == 0){
            ClearConsole();
        } else if (strcmp(CurrentInput, "--version") == 0){
            CurrentVersion();
        } else if (strcmp(CurrentInput, "exit") == 0){
            Exit = 1;
            system("cls");
        } else{
            system("cls");
            printf("\nERROR: Command not found!!!");
        }
    }
    return 0;
}

int help(){
    printf("\n");
    printf("help: %s\n", HELP);
    printf("set_new_name/setuser: %s\n", SET_NEW_NAME);
    printf("get_current_username/getuser: %s\n", GET_CURRENT_USERNAME);
    printf("clear/cls: %s\n", CLEAR);
    printf("--version: %s\n", VERSION);

    printf("exit: %s\n", EXIT);
    printf("\n");
    return 0;
}   

void SetNewName(char *Array){
    printf("\n");
    printf("New username: ");
    scanf("%s", Array);
    printf("\nName added Succeessify!\n");
}

void GetUsername(char *Array){

    if (strcmp(Array, "?") == 0){
        Array = "Default";
    }

    printf("\nActive user: [%s]\n", Array);
}

int ClearConsole(){
    system("cls");
}

void CurrentVersion(){
    printf("\n[Author]: {Grim-Undead-Reaper}\n[StringName]: {First_C_UI}\n[Version]: {%s}\n", VERSION);
}

int ClearArray(char *Array){
    for (int i = 0; i < sizeof(Array)/sizeof(Array[0]); i++){
        Array[i] = '\0';
    }
    return 0;
}
