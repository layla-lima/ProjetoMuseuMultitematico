#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <locale.h>


// Funções pra ler os arquivos txt

void questionario(int numeroDaExbicao, char tema[100]){

    int contador = 0;
    FILE *arquivoContador;

    arquivoContador = fopen("contador.txt", "r+");

    if (arquivoContador != NULL) {
        fscanf(arquivoContador, "%d", &contador);
        contador++;
        rewind(arquivoContador);
        fprintf(arquivoContador, "%d", contador);
        fclose(arquivoContador);
    }

    int respostaPerguntaUm, respostaPerguntaDois;
    char pergunta1[100] = " Em uma escala de 1 a 5, quao satisfeito voce esta com a exposicao?";
    char pergunta2[100] = " Em uma escala de 1 a 5, qual a proprabilidade de vc recomendar essa exibicao a um amigo?";

    do{
       printf("%s %c \n", pergunta1);
       scanf("%i", &respostaPerguntaUm);
       printf("%s %c \n", pergunta2);
       scanf("%i", &respostaPerguntaDois);
       if (respostaPerguntaUm > 5 || respostaPerguntaDois > 5) {
            printf("Por favor, insira um valor entre 0 e 5. Tente novamente! \n\n\n\n");
       }
 //      switch(respostaPerguntaUm){
 //        case 1:
 //            (1/contador)*100
//
 //      }


    }while(respostaPerguntaUm > 5 || respostaPerguntaDois > 5);


    FILE *arquivo;
    arquivo = fopen("estatistica.csv", "w");

    if(arquivo == NULL){
        printf("Não foi possivel abrir o arquivo. \n");
        return 1;
    }
    fprintf(arquivo, "Tema; Pergunta; nota1; Nota2; Nota3; Nota4; Nota5 \n");
    fprintf(arquivo, "%s; %s\n", tema, pergunta1);
    fprintf(arquivo, "%s; %s\n", tema, pergunta2);

    fclose(arquivo);

    printf("Obrigado pelas respostas validas!\n");
    return 0;

}


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
        char tema[100];
        printf("\n\n ========= TEMAS =========\n");
        printf("1 - 100 Anos de Arte Moderna \n");
        printf("2 - 150 Anos de Santos Dumont \n");
        printf("3 - Jogos Olimpicos de Paris 2024\n");
        printf("4 - Literatura Brasileira Comtemporanea\n");
        printf("5 - Voltar\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
          case 1:
            exibirConteudoArquivo1("tema1.txt");
            strcpy(tema, "100 anos da semana de arte moderna");
            break;
          case 2:
            exibirConteudoArquivo2("tema2.txt");
            strcpy(tema, "150 Anos de Santos Dumont");
            break;
          case 3:
            exibirConteudoArquivo3("tema3.txt");
            strcpy(tema, "Jogos Olimpicos de Paris 2024");
            break;
          case 4:
            exibirConteudoArquivo4("tema4.txt");
            strcpy(tema, "Literatura Brasileira Comtemporanea");
            break;
          case 5:
            main();
            break;
          case 6:
            printf("Encerrando Programa... \n");
            exit(0);
            break;
          default:
            printf("Digito incorreto, tente novamente \n");
            exibicao();
            break;
        }
       system("\n\n pause");
       questionario(opcao, tema);
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
