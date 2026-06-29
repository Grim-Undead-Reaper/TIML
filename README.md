# TIML

**TIML** é um projeto em C que implementa um sistema de gerenciamento de arquivos de terminal com funcionalidades de histórico de comandos e gerenciamento de usuários.

## Comandos de usuário

#### Pega o ultimo nome de usuário salvo.
``` c
  void Getuser(void);
```

| Retorno |
| :------ |
| `void`  |
#### Salva um novo nome de usuário.
``` c
  void Setuser(void);
```

| Retorno |
| :------ |
| `void`  |
## Comandos de gerenciamento de arquivos.

#### Criar um novo arquivo
``` c
  int CreateFile(void);
```

| Retorno | Significado |
| :------ | :---------- |
| `0`     | `Sucesso`   |
| `-1`    | `Falha`     |
#### Lê um arquivo no terminal.
``` c
  int ReadFile(void);
```
| Retorno | Significado |
| :------ | :---------- |
| `0`     | `Sucesso`   |
| `-1`    | `Falha`     |
#### Sobrescrever o conteudo de um arquivo.
``` c
  int UpdateFile(void);
```
| Retorno | Significado |
| :------ | :---------- |
| `0`     | `Sucesso`   |
| `-1`    | `Falha`     |
#### Deleta um arquivo
``` c
  int DeleteFile(void);
```
| Retorno | Significado |
| :------ | :---------- |
| `0`     | `Sucesso`   |
| `-1`    | `Falha`     |

## Comandos de histórico

#### Retorna um array com todos os comandos usados durante a sessão atual
``` c
  void GetHistory(int size, char commandList[100][255]);
```

| Retorno |
| :------ |
| `void`  |
#### **Parâmetros**:
**`int size`:** Tamanho atual da [commandList](## "É a array onde será armazenada os comandos usados."), usado num loop *for* para exibir cada item da array.

**`char commandList`:** É a array onde está armazenado os comandos usados.

### Exemplo de código
``` c 
void GetHistory(int size, char commandList[100][255]){
printf("ID | Command name\n");
for (int i = 0; i < size; i++){
    printf("%d | %s\n", i, commandList[i]);
    }
}
```

#### Adiciona um novo comando ao histórico de comandos
``` c
  void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand); 
```

| Retorno |
| :------ |
| `void`  |
#### **Parâmetros**:

**`int count`:** é o valor para representar o index atual da lista de comandos, a função adiciona o novo valor (*currentCommand*) e incrementa o count.

**`char commandList`:** É a array onde será armazenada os comandos usados.

**`char currentCommand`:** É a array que representa o comando inserido pelo usuário, essa *string* é armazenada dentro de [commandList](## "É a array onde será armazenada os comandos usados."), tendo o valor [count](## "é o valor para representar o index atual da lista de comandos, a função adiciona o novo valor (*currentCommand*) e incrementa o count.") como index.

### Exemplo de código

``` c 
void AddNewCommandToHistory(int* count, char commandList[100][255], char* currentCommand){
  strcpy(commandList[*count], currentCommand);
  *count = *count + 1;
}
```

## Features

- Adição de banco de dados para ter dados permanentes.
- Criar um simples sistema para calculos matemático básicos.
- Melhorar o gerenciamento de arquivos.

## References

- [<stdio.h>](https://pubs.opengroup.org/onlinepubs/7908799/xsh/stdio.h.html) - O arquivo include <stdio.h> define constantes, macros e tipos e declara funções de entrada e de saída de fluxo
- [<stdlib.h>](https://pubs.opengroup.org/onlinepubs/009604599/basedefs/stdlib.h.html) - O arquivo include <stdlib.h> Fornece funções para alocação de memória, conversão de tipos, geração de números aleatórios e outras funções utilitárias.
- [<string.h>](https://pubs.opengroup.org/onlinepubs/7908799/xsh/string.h.html) - O arquivo include <string.h> fornece funções, macros e manipulação de cadeias de caracteres e regiões de memória.