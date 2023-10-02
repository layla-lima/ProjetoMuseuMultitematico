#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int menu;
    int menu2;
    int ingressoComprado = 0;  
    // Códigos de ingresso válidos
    char codigosIngressoNormal[][6] = {"n1700", "n9110", "n6210", "n5900", "n1610"}; 
    char codigosIngressoMeia[][6] = {"m1080", "m1010", "m2170", "m9600", "m1710"};
    char codigo[6];

    printf("Seja bem-vindo ao Museu Multitematico! Escolha uma opção para prosseguir:\n");
    printf("===== MENU =====\n");
    printf("1 - Comprar Ingresso\n");
    printf("2 - Validar Ingresso\n");
    printf("3 - Questionario\n");
    printf("4 - Sair\n");
    scanf("%d", &menu);

    switch (menu) {
    case 1:
        if (ingressoComprado) {
            printf("Você ja comprou um ingresso.\n");
        }
        else {
            printf("Selecione o tipo de ingresso:\n");
            printf("1 - Entrada Normal\n");
            printf("2 - Meia Entrada\n");
            printf("3 - Entrada Isenta\n");
            scanf("%d", &menu2);

            switch (menu2) {
            case 1:
                if (ingressoComprado) {
                    printf("Você ja comprou um ingresso.\n");
                }
                else {
                    printf("Valor de 30 reais. Codigo de ingresso gerado: ");
                    for (int i = 0; i < 5; i++) {
                        if (codigosIngressoNormal[i][0] != '\0') {
                            printf("%s\n", codigosIngressoNormal[i]);
                            strcpy(codigosIngressoNormal[i], ""); // Marcar código como usado
                            ingressoComprado = 1;
                            break;
                        }
                    }
                }
                break;
            case 2:
                if (ingressoComprado) {
                    printf("Você ja comprou um ingresso.\n");
                } else {
                    printf("Valor de 15 reais. Codigo de ingresso gerado: ");
                    for (int i = 0; i < 5; i++) {
                        if (codigosIngressoMeia[i][0] != '\0') {
                            printf("%s\n", codigosIngressoMeia[i]);
                            strcpy(codigosIngressoMeia[i], ""); // Marcar código como usado
                            ingressoComprado = 1;
                            break;
                        }
                    }
                }
                break;
            default:
                printf("Resposta invalida.\n");
                break;
            }
        }
        break;
    case 2:
        // Verificar se o código digitado está na lista de ingressos válidos
        printf("Digite o codigo de ingresso a ser validado: ");
        scanf("%s", codigo);

        bool codigoEncontrado = false;
        for (int i = 0; i < 5; i++) {
            if (strcmp(codigo, codigosIngressoNormal[i]) == 0 || strcmp(codigo, codigosIngressoMeia[i]) == 0) {
                printf("Codigo de ingresso valido.\n");
                codigoEncontrado = true;
                break;
            }
        }

        if (!codigoEncontrado) {
            printf("Codigo de ingresso invalido ou utilizado.\n");
        }
        break;

    case 3:
        // Criar código do questionário aqui
        break;

    case 4:
        printf("Programa finalizado com sucesso.\n");
        break;

    default:
        printf("Resposta invalida.\n");
        break;
    }

    return 0;
}
