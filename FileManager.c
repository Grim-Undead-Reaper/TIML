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

void CreateFile(){
  char filepath[1000] = {0};
  FILE* file;

  scanf("%999s", filepath);
  file = fopen(filepath, "w");

  if(file != NULL){
      fclose(file);
  }
}

void ReadFile(){

  char FileContent[100];
  char filepath[1000] = {0};
  FILE* file;

  scanf("%999s", filepath);
  file = fopen(filepath, "r");

  if (file == NULL){
    printf("\nFile not found!\n");
  } else {
    printf("\nFilePath: %s\n", filepath);
    while(fgets(FileContent, 100, file)){
      printf("%s", FileContent);
    }
    fclose(file);
  }
}

void UpdateFile(){
  char filepath[1000] = {0};
  char UserInput[500] = {0};
  FILE *file;

  scanf("%999s", filepath);
  file = fopen(filepath, "a");
  
  if (file != NULL){
    scanf("%499s", UserInput);
    fprintf(file, UserInput);
    fclose(file);
 } else {
   printf("\nFile not found\n");
  }
}

void DeleteFile(){
  char filepath[1000] = {0};
  scanf("%999s", filepath);

  if (remove(filepath) == 0){
    printf("File '%s' deleted sucessfully.\n", filepath);
  } else {
    printf("\nFile not found\n");
  }
}

enum Types FileInputHandler(void){
  char UserInput;
  scanf(" %c", &UserInput);

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

    default:
      printf("Nenhum arquivo escolhido/encontrado!");
      break;
    }
}