#ifndef FILEMANAGER_H
#define FILEMANAGER_H

enum Types {
    CREATE,
    READ,
    UPDATE,
    DELETE
};

typedef struct {
    char CommandName;
    enum Types type;
} CommandTypes;

extern CommandTypes cmdType[];
extern const int COMMANDTYPESIZE;

void FileHandler();
void CreateFile(char* filepath);
void ReadFile(char* filepath);
void UpdateFile(char* filepath);
void DeleteFile(char* filepath);
enum Types FileInputHandler();

#endif