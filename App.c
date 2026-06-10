#include <stdio.h>
#include <stdlib.h>
#include "Commands.h"
#include "User.h"
#include "History.h"

void CreateTerminal(void){
    system("cls");
    int Exit = 0;
    int count = 0;
    char CurrentUsername[255] = {0};
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

        default:
            system("cls");
            printf("\nERROR: Command not found!!!\n");
            break;
        }
    }
}