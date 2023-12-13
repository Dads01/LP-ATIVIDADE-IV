#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ContaBancaria
{
    int numeroDaConta;
    char nomeDoTitular[200];
    float saldo;
    char tipoDeConta[200];
};

void depositar(struct ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Dep�sito realizado com sucesso! Novo saldo: %.2f\n", conta->saldo);
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("\nSaque realizado com sucesso! \nNovo saldo: %.2f\n", conta->saldo);
    }
    else
    {
        printf("\nSaldo insuficiente. Opera��o n�o realizada.\n");
    }
}

void imprimirSaldo(struct ContaBancaria *conta)
{
    printf("Saldo atual da conta: %.2f\n", conta->saldo);
}
void VerificarSePodeFazerDeposito(struct ContaBancaria *conta)
{
    printf("Saldo atual da conta: %.2f\n", conta->saldo);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct ContaBancaria conta;
    int opcao;
    float valor;

    printf("Digite o n�mero da conta: ");
    scanf("%d", &conta.numeroDaConta);

    fflush(stdin);

    printf("Digite o nome do titular da conta: ");
    gets(conta.nomeDoTitular);

    fflush(stdin);

    printf("Qual o tipo da conta - POUPAN�A OU CORRENTE: ");
    gets(conta.tipoDeConta);

    printf("Digite o saldo da conta: ");
    scanf("%f", &conta.saldo);

    system("CLS || CLEAR");

    do
    {
        printf("\tOpera��es Banc�rias \n");
        printf("1|     Depositar            |\n");
        printf("2|     Sacar                |\n");
        printf("3|     Extrato              |\n");
        printf("4|     Empr�stimo           |\n");
        printf("5|     Sair                 |\n");
        printf("\nEscolha a op��o desejada: ");
        scanf("%d", &opcao);

        system("CLS || CLEAR");

        switch (opcao)
        {
        case 1:
            printf("Valor do dep�sito: ");
            scanf("%f", &valor);
            depositar(&conta, valor);
            break;

        case 2:
            printf("Valor do saque: ");
            scanf("%f", &valor);
            sacar(&conta, valor);
            break;

        case 3:
            imprimirSaldo(&conta);
            break;
        case 4:
            imprimirSaldo(&conta);
            break;

        case 5:
            printf("Programa encerrado.\n");
            break;

        default:
            printf("Op��o inv�lida. Tente novamente.\n");
            break;
        }

    } while (opcao != 4);

    return 0;
}