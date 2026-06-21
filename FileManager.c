#include <stdio.h>
#include <string.h>
#include "FileManager.h"

CommandTypes cmdType[] = {
  {'c', CREATE},
  {'r', READ},
  {'u', UPDATE},
  {'d', DELETE}
};

const int COMMANDTYPESIZE = (sizeof(cmdType) / sizeof(cmdType[0]));

void CreateFile(char* filepath){
    FILE *file = fopen(filepath, "w");

    if(file != NULL){
        fclose(file);
    }
}

void ReadFile(char* filepath){
  char FileContent[100];
  FILE *file = fopen(filepath, "r");

  if (file == NULL){
    printf("\nFile not found!\n");
    fclose(file);
  } else {
    while(fgets(FileContent, 100, file)){}
      printf("%s", FileContent);
    fclose(file);
  }

}

void UpdateFile(char* filepath){
  FILE *file = fopen(filepath, "w");
  char UserInput[500] = {0};
  
  if (file != NULL){
    file = fopen(filepath, "a");
    scanf("%499s", UserInput);
    fprintf(file, filepath);
    fclose(file);
 } else {
   printf("\nFile not found\n");
  }
}

void DeleteFile(char* filepath){
  if (remove(filepath) == 0){
    printf("File '%s' deleted sucessfully.\n", filepath);
  } else {
    printf("\nFile not found\n");
  }
}

enum Types FileInputHandler(){
    char UserInput;
    scanf("%c", &UserInput);
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);

    for (int i = 0; i < COMMANDTYPESIZE; i++){
        if(UserInput == cmdType[i].CommandName){
            return cmdType[i].type;
        }
    }

    return -1;
}

void FileHandler(){
  
  char filepath[1000] = {0};

  switch(FileInputHandler()){
    case CREATE:
      scanf("%999s", filepath);
      CreateFile(filepath);
      break;

    case READ:
      scanf("%999s", filepath);
      ReadFile(filepath);
      break;

    case UPDATE:
      scanf("%999s", filepath);
      UpdateFile(filepath);
      break;

    case DELETE:
      scanf("%999s", filepath);
      DeleteFile(filepath);
      break;

    default:
      break;
    }
}