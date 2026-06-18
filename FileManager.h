void FileHandler();

enum types {
    CREATE,
    READ,
    UPDATE,
    DELETE
};

typedef struct {
    char CommandName;
    enum types type;
} CommandTypes;

void CreateFile(char* filepath);
void ReadFile(char* filepath);
void UpdateFile(char* filepath);
void DeleteFile(char* filepath);
enum types FileInputHandler();

extern CommandTypes cmdType[];
extern const int COMMANDSIZE;
