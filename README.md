
# Project Title

A brief description of what this project does and who it's for

## Comandos de usuário

#### Pega o ultimo nome de usuário salvo.
``` c
  void Getuser(void);
```
***
#### Salva um novo nome de usuário.
``` c
  void Setuser(void);
```

## Comandos de gerenciamento de arquivos.

#### Criar um novo arquivo
``` c
  int CreateFile(void);
```
**Obs:** Retorna 0 em caso de sucesso ou retorna -1 em caso de erro.
***
#### Lê um arquivo no terminal.
``` c
  int ReadFile(void);
```
**Obs:** Retorna 0 em caso de sucesso ou retorna -1 em caso de erro.
***
#### Sobrescrever o conteudo de um arquivo.
``` c
  int UpdateFile(void);
```
**Obs:** Retorna 0 em caso de sucesso ou retorna -1 em caso de erro.
***
#### Deleta um arquivo
``` c
  int DeleteFile(void);
```
**Obs:** Retorna 0 em caso de sucesso ou retorna -1 em caso de erro.

## Comandos de histórico

#### Retorna um array com todos os comandos usados durante a sessão atual
``` c
  void GetHistory(int size, char commandList[100][255]);
```
##### Parâmetros:
**int size:** Tamanho atual da [commandList](## "É a array onde será amarzenada os comandos usados."), usado num loop *for* para exibir cada item da array.

**char commandList:** É a array onde está amarzenado os comandos usados.

***
#### Adiciona um novo comando ao histórico de comandos
``` c
  void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand); 
```
##### Parâmetros:

**int count:** é o valor para representar o index atual da lista de comandos, a função adiciona o novo valor (*currentCommand*) e incrementa o count.

**char commandList:** É a array onde será amarzenada os comandos usados.

**char currentCommand:** É a array que representa o comando inserido pelo usuário, essa *string* é amarzenada dentro de [commandList](## "É a array onde será amarzenada os comandos usados."), tendo o valor [count](## "é o valor para representar o index atual da lista de comandos, a função adiciona o novo valor (*currentCommand*) e incrementa o count.") como index.

### Exemplo de código

``` c 
void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand){
  strcpy(commandList[*count], currentCommand);
  *count = *count + 1;
}
```

***