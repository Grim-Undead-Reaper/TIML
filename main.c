#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Functions {
  HELP,
  SETUSER,
  GETUSER,
  CLEARCONSOLE,
  GETHISTORY,
  VERSION,
  EXIT,
  CREATETYPE,
  MATH
};

typedef struct {
    char *name;
    char *description;
    enum Functions func;
} Command;

Command commands[] = {
    {"help", "Show all commands.", HELP},
    {"setuser", "Set a new user name.", SETUSER},
    {"getuser", "Get Current User.", GETUSER},
    {"clear", "Clear console.", CLEARCONSOLE},
    {"cmdh", "Get all commands used.", GETHISTORY},
    {"--version", "Get current terminal version", VERSION},
    {"exit", "Close the terminal.", EXIT},
    {"Createtype", "Create a new file", CREATETYPE},
    {"math", "For simple math calcs", MATH}
};

#define CommandsSize (sizeof(commands) / sizeof(commands[0]))

enum Functions InputHandler(char* InputArray, int* count, char commandList[100][255]);
void Createtype();
int help();
int ClearConsole();
void SetNewName(char *Array);
void GetUsername(char *Array);
int ClearArray(char *Array);
void CurrentVersion();
void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand);
void GetHistory(int size, char commandList[100][255]);
void Math();

char version[] = "0.0.9";

int main()
{
    system("cls");
    int Exit = 0;
    int count = 0;
    char CurrentUsername[255];
    char commandList[100][255];
    
    printf("Welcome!\n\nUse command 'help' to see all commands\n\n");

    while(Exit == 0){
        char CurrentInput[255];

        switch (InputHandler(CurrentInput, &count, commandList))
        {
        case HELP:
            help();
            printf("\n");
            break;

        case SETUSER:
            SetNewName(CurrentUsername);
            printf("\n");
            break;
        
        case GETUSER:
            GetUsername(CurrentUsername);
            printf("\n");
            break;
        
        case CLEARCONSOLE:
            ClearConsole();
            printf("\n");
            break;

        case GETHISTORY:
            GetHistory(count, commandList);
            printf("\n");
            break;
        
        case VERSION:
            CurrentVersion();
            break;

        case EXIT:
            Exit = 1;
            system("cls");
            break;

        case CREATETYPE:
            Createtype();
            break;
            
        case MATH:
            Math();
            break;

        case -1:
            system("cls");
            printf("\nERROR: Command not found!!!");
            printf("\n\n");
            break;

        default:
            system("cls");
            printf("\nERROR: Command not found!!!");
            break;
        }
    }
    return 0;
}

enum Functions InputHandler(char* InputArray, int* count, char commandList[100][255]){
    scanf("%254s", InputArray);
    printf("\n");
    AddNewCommandToHistory(count, commandList, InputArray);
    for (int i = 0; i < CommandsSize; i++){
        if (strcmp(InputArray, commands[i].name) == 0){
            return commands[i].func;
        }
    }

    return -1;
}

int help(){
    for (int i = 0; i < CommandsSize; i++){
        printf("%s: %s\n", commands[i].name, commands[i].description);
    }
    return 0;
}

void SetNewName(char *Array){
    printf("\n");
    printf("New username: ");
    scanf("%254s", Array);
    printf("\nName added Succeessify!\n");
}

void GetUsername(char *Array){

    if (strcmp(Array, "?") == 0){
        strcpy(Array, "Default");
    }

    printf("\nActive user: [%s]\n", Array);
}

int ClearConsole(){
    system("cls");
}

void CurrentVersion(){
    printf("\n[Author]: {Grim-Undead-Reaper}\n[Software]: {First_C_UI}\n[Version]: {%s}\n", version);
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

void Createtype(){
    char type[255];
    char filename[255];
    
    printf("FileType FileName\n");
    scanf("%254s %254s", type, filename);
    
    if (strcmp(type, "file") == 0){
        printf("File '%s' created\n", filename);
    }else if (strcmp(type, "folder;") == 0){
        printf("Folder '%s' created\n");
    }
    printf("\n");
}