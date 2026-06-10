#ifndef HISTORY_H
#define HISTORY_H

void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand);
void GetHistory(int size, char commandList[100][255]);

#endif