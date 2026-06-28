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

int CreateFile(void){
  char filepath[1000] = {0};
  FILE* file;

  scanf("%999s", filepath);
  file = fopen(filepath, "w");

  if(file != NULL){
    fclose(file);
    return 0;
  } else {
    return -1;
  }
}

int ReadFile(void){

  char FileContent[100];
  char filepath[1000] = {0};
  FILE* file;

  scanf("%999s", filepath);
  file = fopen(filepath, "r");

  if (file == NULL){
    printf("\nFile not found!\n");
    return 1;
  } else {
    printf("\nFilePath: %s\n", filepath);
    while(fgets(FileContent, 100, file)){
      printf("%s", FileContent);
    }
    fclose(file);
    return 0;
  }
}

int UpdateFile(void){
  char filepath[1000] = {0};
  char UserInput[500] = {0};
  FILE *file;

  scanf("%999s", filepath);
  file = fopen(filepath, "a");
  
  if (file != NULL){
    scanf("%499s", UserInput);
    fprintf(file, UserInput);
    fclose(file);
    return 0;
 } else {
   printf("\nFile not found\n");
   return -1;
  }
}

void DeleteFile(void){
  char filepath[1000] = {0};
  scanf("%999s", filepath);

  if (remove(filepath) == 0){
    printf("File '%s' deleted sucessfully.\n", filepath);
    return 0;
  } else {
    printf("\nFile not found\n");
    return -1;
  }
}

enum Types FileInputHandler(void){
  char UserInput;
  printf("Command type: ");
  scanf(" %c", &UserInput);
  printf("\n");

  int ch;
  while((ch = getchar()) != '\n' && ch != EOF);

  for (int i = 0; i < COMMANDTYPESIZE; i++){
    if(UserInput == cmdType[i].CommandName){
      return cmdType[i].type;
    }
  }

  return NOTFOUND;
}

void FileHandler(void){

  printf("\nCommands\n'c': Create a new file\n'r': Read a file\n'u': Update a file\n'd': Delete a file\n\n");

  switch(FileInputHandler()){
    case CREATE:
      printf("Filepath or Filename: ");
      CreateFile();
      break;

    case READ:
      printf("Filepath or Filename: ");
      ReadFile();
      break;

    case UPDATE:
      printf("Filepath or Filename: ");
      UpdateFile();
      break;

    case DELETE:
      printf("Filepath or Filename: ");
      DeleteFile();
      break;

    case NOTFOUND:
      printf("Command not found!\n\n");
      break;
    }
}
