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
int CreateFile(void);
int ReadFile(void);
int UpdateFile(void);
int DeleteFile(void);
enum Types FileInputHandler(void);

#endif
