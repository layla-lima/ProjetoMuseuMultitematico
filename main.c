 /*
 ==== PIM UNIP ====
 ANOTAÇÕES/MODIFICAÇÕES: 
 - Caracteres especiais (ç, ã, á[...]) não são reconhecidos pela linguagem C, será necessário aplicar o codigo de cada caractere para tornar o código legível no terminal.
 - Terminar [case 2] e [case 3] (Ln 48, 52).
  */

int main(int argc, char const *argv[])
{
    int tipoIngresso;
    int menu;
   
    printf("Seja bem-vindo(a) ao Museu Multitemático! Escolha uma das seguintes opções para prosseguir:\n");
    printf("1 - Comprar Ingresso\n");
    printf("2 - Validar Ingresso\n");
    printf("3 - Sair\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:

        printf("Qual é o tipo de ingresso?\n");
        printf("1- Normal\n");
        printf("2- Meia Entrada\n");
        printf("3- Entrada Isenta\n");
        scanf("%d", &tipoIngresso);

        switch (tipoIngresso)
        {
        case 1:
            printf("Valor total de 30 reais.");
            break;
        case 2:
            printf("Valor total de 15 reais.");
            break;
        case 3:
            printf("Valor Isento. (Mediante a apresentação de documentação comprovativa).");
            break;
        default:
            printf("Resposta inválida.");
            break;
        }

        break;

    /*
    case 2:

        printf("[...]");
    
    case 3:

        printf("[...]");
    */

    default:
        printf("Resposta inválida.");
        break;
    }

    return 0;

}
