#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct agendaTelefonica
{
    char nome[200];
    char numeroCelular[200];
    char email[200];
};

char EncontrarNumeroPeloNome(struct agendaTelefonica funcao[], char *opcao)
{
    int a;

    for (a = 0; a < 3; a++)
    {
        if (strcmp(funcao[a].nome, opcao) == 0)
        {
            return printf("Numero do contato de %s: %s", funcao[a].nome, funcao[a].numeroCelular);
            break;
        }
    }

    return printf("Contato inexistente!");
}

int main()
{
 
    setlocale(LC_ALL, "portuguese");
    struct agendaTelefonica funcao[3];
    int a;
    char opcao[200];

    for (a = 0; a < 3; a++)
    {

        printf("Digite o nome do %d° contato:", a + 1);
        gets(funcao[a].nome);

        printf("Digite o e-mail:", funcao[a].email);
        gets(funcao[a].email);

        printf("Digite o numero:", funcao[a].numeroCelular);
        gets(funcao[a].numeroCelular);

        system("CLS || CLEAR");
    }

    system("CLS || CLEAR");

    printf("Informe o nome do contato que deseja buscar:");
    gets(opcao);

    system("CLS || CLEAR");

    EncontrarNumeroPeloNome(funcao, opcao);

    return 0;
}