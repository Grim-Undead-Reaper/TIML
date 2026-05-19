#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct main
{
    char *name;
    char *description;
} Command;

Command commands[] = {
    {"help", "Show all commands."},
    {"setuser", "Set a new user name."},
    {"getuser", "Get Current User."},
    {"clear/cls", "Clear console."},
    {"cmdh", "Get all commands used."},
    {"--version", "Get current terminal version"},
    {"exit", "Close the terminal."}
};

int help();
int ClearConsole();
void SetNewName(char *Array);
void GetUsername(char *Array);
int ClearArray(char *Array);
void CurrentVersion();
void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand);
void GetHistory(int size, char commandList[100][255]);

char version[] = "0.0.9";

int main()
{
    system("cls");
    int Exit = 0;
    int count = 0;

    while(Exit == 0){
        char CurrentInput[255];
        char CurrentUsername[255];
        char commandList[100][255];
        printf("\n");
        scanf("%s", CurrentInput);
        AddNewCommandToHistory(&count, commandList, CurrentInput);

        if (strcmp(CurrentInput, "help") == 0){
            help();
        } else if (strcmp(CurrentInput, "setuser") == 0){
            SetNewName(CurrentUsername);
        } else if (strcmp(CurrentInput, "getuser") == 0){
            GetUsername(CurrentUsername);
        } else if (strcmp(CurrentInput, "clear") == 0 || strcmp(CurrentInput, "cls") == 0){
            ClearConsole();
        } else if (strcmp(CurrentInput, "--version") == 0){
            CurrentVersion();
        } else if (strcmp(CurrentInput, "exit") == 0){
            Exit = 1;
            system("cls");
        } else if (strcmp(CurrentInput, "cmdh") == 0){
            GetHistory(count, commandList);
        } else {
          system("cls");
          printf("\nERROR: Command not found!!!");
        }
    }
    return 0;
}

int help(){
    int size = sizeof(commands) / sizeof(commands[0]);
    for (int i = 0; i < size; i++){
        printf("%s: %s\n", commands[i].name, commands[i].description);
    }
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
    printf("\n[Author]: {Grim-Undead-Reaper}\n[StringName]: {First_C_UI}\n[Version]: {%s}\n", version);
}

int ClearArray(char *Array){
    for (int i = 0; i < sizeof(Array)/sizeof(Array[0]); i++){
        Array[i] = '\0';
    }
    return 0;
}

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