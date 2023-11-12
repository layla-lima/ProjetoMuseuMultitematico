#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>


char tema1[100] = "100 anos da semana de arte moderna";
char tema2[100] = "150 Anos de Santos Dumont";
char tema3[100] = "Jogos Olimpicos de Paris 2024";
char tema4[100] = "Literatura Brasileira Contemporanea";

//metodo para verificar se determinado valor existe no arquivo csv
int valorJaExiste(const char *valor, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return 0;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, valor) != NULL) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

//metodo que retorna o caminho para guardar a quantidade de resposta do usuario na primeira pergunta
char* devolverArquivoContador1(char *valor, char tema[100]) {
   char arquivo[100];

   if(strcmp(tema1, tema)==0){
     strcpy(arquivo, "tema1/pergunta1");
   }else if(strcmp(tema2, tema)==0){
     strcpy(arquivo, "tema2/pergunta1");
   }else if(strcmp(tema3, tema)==0){
     strcpy(arquivo, "tema3/pergunta1");
   }else if(strcmp(tema4, tema)==0){
     strcpy(arquivo, "tema4/pergunta1");
   }


   strlwr(valor);
   char *nomeDoArquivo = malloc(strlen(arquivo) + strlen(valor) + 10);
   strcpy(nomeDoArquivo, arquivo);


   if (strcmp(valor, "sim") == 0) {
        strcat(nomeDoArquivo, "/sim.txt");
    } else if (strcmp(valor, "nao") == 0) {
        strcat(nomeDoArquivo, "/nao.txt");
    } else {
        free(nomeDoArquivo);
        return NULL;
    }

    return nomeDoArquivo;
}

//metodo que retorna o caminho para guardar a quantidade de resposta do usuario na segunda pergunta
char* devolverArquivoContador2(char *valor, char tema[100]) {
   char arquivo[100];

   if(strcmp(tema1, tema)==0){
     strcpy(arquivo, "tema1/pergunta2");
   }else if(strcmp(tema2, tema)==0){
     strcpy(arquivo, "tema2/pergunta2");
   }else if(strcmp(tema3, tema)==0){
     strcpy(arquivo, "tema3/pergunta2");
   }else if(strcmp(tema4, tema)==0){
     strcpy(arquivo, "tema4/pergunta2");
   }


   strlwr(valor);
   char *nomeDoArquivo = malloc(strlen(arquivo) + strlen(valor) + 10);
   strcpy(nomeDoArquivo, arquivo);


   if (strcmp(valor, "sim") == 0) {
        strcat(nomeDoArquivo, "/sim.txt");
    } else if (strcmp(valor, "nao") == 0) {
        strcat(nomeDoArquivo, "/nao.txt");
    } else {
        free(nomeDoArquivo);
        return NULL;
    }

    return nomeDoArquivo;
}


//metodo de descobrimento do valor no contador para saber a quantidade de vezes que a opção foi escolhida pelos usuarios na pergunta 1
int descobreSegundaParte(char arquivoAlterado[100], char tema[100], char resposta[10]) {
    char arquivoNaoAlterado[100];

    if(strcmp(tema, tema1)==0){
      if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema1/pergunta1/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema1/pergunta1/sim.txt");
      }
    }else if(strcasecmp(tema, tema2)==0){
       if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema2/pergunta1/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema2/pergunta1/sim.txt");
      }
    }else if(strcasecmp(tema, tema3)==0){
       if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema3/pergunta1/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema3/pergunta1/sim.txt");
      }
    }else if(strcasecmp(tema, tema4)==0){
      if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema4/pergunta1/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema4/pergunta1/sim.txt");
      }
    }

    FILE *arquivo = fopen(arquivoNaoAlterado, "r");
    int valorLido;
    if (fscanf(arquivo, "%d", &valorLido) != 1) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    return valorLido;
}

//metodo de descobrimento do valor no contador para saber a quantidade de vezes que a opção foi escolhida pelos usuarios na pergunta 2
int descobreSegundaParte2(char arquivoAlterado[100], char tema[100], char resposta[10]) {
    char arquivoNaoAlterado[100];

    if(strcmp(tema, tema1)==0){
      if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema1/pergunta2/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema1/pergunta2/sim.txt");
      }
    }else if(strcasecmp(tema, tema2)==0){
       if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema2/pergunta2/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema2/pergunta2/sim.txt");
      }
    }else if(strcasecmp(tema, tema3)==0){
       if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema3/pergunta2/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema3/pergunta2/sim.txt");
      }
    }else if(strcasecmp(tema, tema4)==0){
      if(strcasecmp(resposta, "sim")==0){
        strcpy(arquivoNaoAlterado, "tema4/pergunta2/nao.txt");
      }else{
        strcpy(arquivoNaoAlterado, "tema4/pergunta2/sim.txt");
      }
    }

    FILE *arquivo = fopen(arquivoNaoAlterado, "r");
    int valorLido;
    if (fscanf(arquivo, "%d", &valorLido) != 1) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    return valorLido;
}

//metodo que aumenta +1 no contadores, a cada chamada do usuario
int aumentarContador (char file[100]){
    int valorAtual;
    char linha[100];
    int contador = 0;
    FILE *contadorQuestionario;
    contadorQuestionario = fopen(file, "r+");

    if(contadorQuestionario != NULL){
        fscanf(contadorQuestionario, "%d", &contador);
        contador++;
        rewind(contadorQuestionario);
        fprintf(contadorQuestionario, "%d", contador);
        fclose(contadorQuestionario);
        return contador;
    }
}

//metodo pra descobrir o "total" dos usuarios com base no tema escolhido
int contadorTema (char tema[100]){
    char arquivo[100];

    if(strcmp(tema, tema1)==0){
        strcpy(arquivo, "tema1/contador.txt");
    }else if(strcmp(tema, tema2)==0){
        strcpy(arquivo, "tema2/contador.txt");
    }else if(strcmp(tema, tema3)==0){
        strcpy(arquivo, "tema3/contador.txt");
    }else if(strcmp(tema, tema4)==0){
        strcpy(arquivo, "tema4/contador.txt");
    }

    return aumentarContador(arquivo);
}

//metodo para salvar as porcetagens no arquivo csv
void salvarNotaParaTema(const char *nomeArquivo, const char *tema, const char *pergunta, double porcentagem, double porcentagem2, char *valorPassadoPeloUsuario) {

    FILE *arquivoOriginal = fopen(nomeArquivo, "r");
    if (arquivoOriginal == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *arquivoTemporario = fopen("temporario.csv", "w");
    if (arquivoTemporario == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivoOriginal);
        return;
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivoOriginal) != NULL) {
        char temaOriginal[100];
        char perguntaOriginal[100];
        double sim;
        double nao;
        sscanf(linha, "%99[^;]; %99[^;]; %2.f; %2.f",
               temaOriginal, perguntaOriginal, &sim, &nao);

        if (strstr(linha, tema) != NULL && strstr(linha, pergunta) != NULL) {
            // Modificar a linha no arquivo temporário
            strlwr(valorPassadoPeloUsuario);
            if (strcmp(valorPassadoPeloUsuario, "sim") == 0) {
                sim = porcentagem;
                nao = porcentagem2;
            } else if (strcmp(valorPassadoPeloUsuario, "nao") == 0) {
                nao = porcentagem;
                sim = porcentagem2;
            }

            char porcent[2];
            strcpy(porcent, "%");

            char simPor[100], naoPor[100];
            sprintf(simPor, "%.2f", sim);
            sprintf(naoPor, "%.2f", nao);

            strcat(simPor, porcent);
            strcat(naoPor, porcent);

            fprintf(arquivoTemporario, "%s; %s; %s; %s\n", tema, pergunta, simPor, naoPor);
        } else {
            // Copiar a linha original para o arquivo temporário
            fprintf(arquivoTemporario, "%s", linha);
        }
    }

    // Fechar os arquivos
    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    // Remover o arquivo original
    remove(nomeArquivo);

    // Renomear o arquivo temporário para o nome do arquivo original
    rename("temporario.csv", nomeArquivo);
}


//Funcao para questionario e coleta de respostas
void questionario(int numeroDaExbicao, char tema[100]){

    int todo = contadorTema(tema);
    int parte1Pergunta1, parte2Pergunta1;
    int parte1Pergunta2, parte2Pergunta2;

    char respostaPerguntaUm[10], respostaPerguntaDois[10];
    char pergunta1[100] = "Voce esta satisfeito com a exposicao?";
    char pergunta2[100] = "Voce recomendaria essa exibicao a um amigo?";


    do{
       printf("Responda com Sim ou Nao \n\n");
       printf("%s \n", pergunta1);
       scanf("%s", respostaPerguntaUm);
       char* nomeDoArquivo = devolverArquivoContador1(respostaPerguntaUm, tema);
       parte1Pergunta1 = aumentarContador(nomeDoArquivo);
       parte2Pergunta1 = descobreSegundaParte(nomeDoArquivo, tema, respostaPerguntaUm);


       printf("%s \n", pergunta2);
       scanf("%s", respostaPerguntaDois);
       char* nomeDoArquivo2 = devolverArquivoContador2(respostaPerguntaDois, tema);
       parte1Pergunta2 = aumentarContador(nomeDoArquivo2);
       parte2Pergunta2 = descobreSegundaParte2(nomeDoArquivo2, tema, respostaPerguntaDois);

       strlwr(respostaPerguntaUm);
       strlwr(respostaPerguntaDois);

        if (strcmp(respostaPerguntaUm, "nao") != 0 && strcmp(respostaPerguntaUm, "sim") != 0 &&
            strcmp(respostaPerguntaDois, "nao") != 0 && strcmp(respostaPerguntaDois, "sim") != 0) {
            printf("Por favor, insira Sim ou Nao, apenas. Tente novamente!\n\n\n\n");
        }
    } while (strcmp(respostaPerguntaUm, "nao") != 0 && strcmp(respostaPerguntaUm, "sim") != 0 &&
             strcmp(respostaPerguntaDois, "nao") != 0 && strcmp(respostaPerguntaDois, "sim") != 0);


    FILE *arquivo;
    arquivo = fopen("estatistica.csv", "a");

    double porcetagemPrimeira, porcetagem2Primeira;
    double porcetagemSegunda, porcetagem2Segunda;

    porcetagemPrimeira = ((double)parte1Pergunta1/todo)*100.0;
    porcetagem2Primeira = ((double)parte2Pergunta1/todo)*100;
    porcetagemSegunda = ((double)parte1Pergunta2/todo)*100;
    porcetagem2Segunda = ((double)parte2Pergunta2/todo)*100;

    if(arquivo == NULL){
        printf("Não foi possivel abrir o arquivo. \n");
        return 1;
    }

    if(valorJaExiste(tema, "estatistica.csv") == 0){
       if (valorJaExiste("Tema; Pergunta; Sim; Nao", "estatistica.csv") == 0) {
            fprintf(arquivo, "Tema; Pergunta; Sim; Nao \n");
        }
        fprintf(arquivo, "%s; %s\n", tema, pergunta1);
        fprintf(arquivo, "%s; %s\n", tema, pergunta2);
    }
    fclose(arquivo);
    salvarNotaParaTema("estatistica.csv", tema, pergunta1, porcetagemPrimeira, porcetagem2Primeira, respostaPerguntaUm);
    salvarNotaParaTema("estatistica.csv", tema, pergunta2, porcetagemSegunda, porcetagem2Segunda, respostaPerguntaDois);
    printf("Obrigado pelas respostas validas!\n");
}

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
        char tema[100];
        printf("\n\n ========= TEMAS =========\n");
        printf("1 - 100 anos da semana de arte moderna \n");
        printf("2 - 150 Anos de Santos Dumont \n");
        printf("3 - Jogos Olimpicos de Paris 2024\n");
        printf("4 - Literatura Brasileira Contemporanea\n");
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
            strcpy(tema, "Literatura Brasileira Contemporanea");
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
