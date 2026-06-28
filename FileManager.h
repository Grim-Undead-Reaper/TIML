#ifndef FILEMANAGER_H
#define FILEMANAGER_H

enum Types {
    CREATE,
    READ,
    UPDATE,
    DELETE,
    NOTFOUND
};

typedef struct {
    char CommandName;
    enum Types type;
} CommandTypes;

extern CommandTypes cmdType[];
extern const int COMMANDTYPESIZE;

void FileHandler(void);
void CreateFile(void);
void ReadFile(void);
void UpdateFile(void);
void DeleteFile(void);
enum Types FileInputHandler(void);

#endif
