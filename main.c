#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um ingresso
typedef struct {
    int numero;
    int valido;
} Ingresso;

// Função pra gerar um número de ingresso aleatório
int gerarNumeroIngresso() {
    return rand() % 10000 + 1000; // Números entre 1000 e 9999
}

// Função pra criar um novo ingresso com base no tipo
Ingresso criarIngresso(int tipo) {
    Ingresso novo;
    novo.numero = gerarNumeroIngresso();
    novo.valido = 1; // Ingresso é válido por padrão
    return novo;
}

//exibicao dos tesmas
void exibicao(){
        int opcao;
        printf("\n\n=== TEMAS MUSEU MULTITEMATICO ===\n");
        printf("1 - Exibicao 1\n");
        printf("2 - Exibicao 2\n");
        printf("3 - Exibicao 3\n");
        printf("4 - Exibicao 4\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
          case 1:
            printf("Exibicao 1");
            questionario(1);
            break;
          case 2:
            printf("Exibicao 2");
            break;
          case 3:
            printf("Exibicao 3");
            break;
          case 4:
            printf("Exibicao 4");
            break;
          case 5:
            main();
            break;
        }
}

void questionario (int exibicao){


}


// Função pra exibir o ingresso
void exibirIngresso(Ingresso ingresso) {
    printf("Numero do ingresso: %d\n", ingresso.numero);
    if (ingresso.valido) {
        printf("Status: Valido\n");
    } else {
        printf("Status: Invalido\n");
    }
}

int main() {
    srand(time(NULL)); // Inicializa números aleatórios
    int opcao;
    Ingresso ingresso;
    int codigoIngresso;
    int tipoIngresso;
    int limiteIngressos = 10; // Limite de 10 ingressos (pode ser alterado)
    int ingressosGerados = 0;

    do {
        printf("\n\n=== MENU MUSEU MULTITEMATICO ===\n");
        printf("1 - Comprar ingresso\n");
        printf("2 - Validar ingresso\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (ingressosGerados < limiteIngressos) {
                    printf("\nSelecione o tipo do ingresso:\n");
                    printf("1 - Entrada Normal: 6 reais\n");
                    printf("2 - Meia Entrada: 3 reais (mediante a comprovacao)\n");
                    printf("3 - Entrada Isenta: valor isento (mediante a comprovacao)\n");
                    printf("Escolha um tipo: ");
                    scanf("%d", &tipoIngresso);
                    ingresso = criarIngresso(tipoIngresso);
                    printf("\nNovo ingresso gerado:\n");
                    exibirIngresso(ingresso);
                    ingressosGerados++;
                } else {
                    printf("\nLimite de ingressos atingido. Nao e possivel gerar mais ingressos.\n");
                }
                break;
            case 2:
                printf("Digite o codigo do ingresso: ");
                scanf("%d", &codigoIngresso);
                if (codigoIngresso == ingresso.numero) {
                    if (ingresso.valido) {
                        printf("\nIngresso valido:\n");
                        exibirIngresso(ingresso);
                        ingresso.valido = 0; // Marca o ingresso como inválido após validação
                        exibicao();
                        return 0;
                    } else {
                        printf("\nEste ingresso já foi validado.\n");
                    }
                } else {
                    printf("\nCodigo de ingresso invalido.\n");
                }
                break;
            case 3:
                printf("Encerrando o programa...");
                return 0;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
