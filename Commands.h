#ifndef COMMANDS_H
#define COMMANDS_H

enum Functions {
  HELP,
  SETUSER,
  GETUSER,
  CLEARCONSOLE,
  GETHISTORY,
  VERSION,
  FILEMANAGER,
  EXIT
};

typedef struct {
  char *name;
  char *description;
  enum Functions func;
} Command;

extern Command commands[];
extern const int COMMANDSIZE;

enum Functions InputHandler(char* InputArray, int* count, char commandList[100][255]);

int help();
void ClearConsole();
void CurrentVersion();

#endif