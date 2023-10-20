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
        printf("\n1 - Descricao das Exibicoes\n");
        printf("2 - Comprar ingresso\n");
        printf("3 - Validar ingresso\n");
        printf("4 - Questionario\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Descricao das exibicoes:\n");
                printf("Exibicao 1: [...]\n");
                printf("Exibicao 2: [...]\n");
                // Adicionar as descrições aqui
                return 0;
            case 2:
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
            case 3:
                printf("Digite o codigo do ingresso: ");
                scanf("%d", &codigoIngresso);
                if (codigoIngresso == ingresso.numero) {
                    if (ingresso.valido) {
                        printf("\nIngresso valido:\n");
                        exibirIngresso(ingresso);
                        ingresso.valido = 0; // Marca o ingresso como inválido após validação
                        return 0;
                    } else {
                        printf("\nEste ingresso já foi validado.\n");
                    }
                } else {
                    printf("\nCodigo de ingresso invalido.\n");
                }
                break;
            case 4:
                // Codigo do questionario aqui
                break;
            case 5:
                printf("Encerrando o programa...");
                return 0;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
