#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


// Funções pra ler os arquivos txt


void exibirConteudoArquivo1(const char *nomeArquivo)
{
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo;
    char linha[1000]; // Tamanho max de uma linha

    arquivo = fopen("tema1.txt", "r"); // Abre o arquivo para leitura

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    // Lê e imprime o conteúdo do arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);

    }

    fclose(arquivo); // Fecha o arquivo após a leitura
}

void exibirConteudoArquivo2(const char *nomeArquivo)
{
    FILE *arquivo;
    char linha[1000];

    arquivo = fopen("tema2.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);

    }

    fclose(arquivo);
}

void exibirConteudoArquivo3(const char *nomeArquivo)
{
    FILE *arquivo;
    char linha[1000];

    arquivo = fopen("tema3.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);

    }

    fclose(arquivo);
}

void exibirConteudoArquivo4(const char *nomeArquivo)
{
    FILE *arquivo;
    char linha[1000];

    arquivo = fopen("tema4.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);

    }

    fclose(arquivo);
}



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

//exibicao dos temas
void exibicao(){
        setlocale(LC_ALL, "Portuguese");
        int opcao;
        printf("\n\n ========= TEMAS =========\n");
        printf("1 - 100 Anos de Arte Moderna \n");
        printf("2 - 150 Anos de Santos Dumont \n");
        printf("3 - Jogos Olimpicos de Paris 2024\n");
        printf("4 - Literatura Brasileira Comtemporanea\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
          case 1:
            exibirConteudoArquivo1("tema1.txt");
            break;
          case 2:
            exibirConteudoArquivo2("tema2.txt");
            break;
          case 3:
            exibirConteudoArquivo3("tema3.txt");
            break;
          case 4:
            exibirConteudoArquivo4("tema4.txt");
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

    setlocale(LC_ALL, "Portuguese"); //Coloca a linguagem em Português, aceitando caracteres especiais

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

    } while (opcao != 3);

    return 0;
}
