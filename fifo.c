#include <stdio.h>
#include <stdlib.h>

//Se o sistema for Windows adiciona determinada biblioteca, e definindo comandos de limpar e esperar
#ifdef WIN32
    #include <windows.h>
    #define LIMPA_TELA system("cls")
//Sen‹o for Windows (se for Linux)
#else
    #include <unistd.h>
    #define LIMPA_TELA system("/usr/bin/clear")
#endif

//Estrutura da lista que ser‡ criada
typedef struct Fila {
    int valor;
    struct Fila *proximo;
}

Dados;

//Inicializando os dados da lista
Dados *principal = NULL;
Dados *final = NULL;

//Inser‹o
void insere(){
    int val;
    LIMPA_TELA;
    printf("\nInser‹o: \n");
    printf("--------------------------------------\n");
    printf("Insira o valor a ser inserido: ");
    scanf("%d",&val);
    Dados *atual = (Dados*)malloc(sizeof(Dados));
    atual -> valor = val;
    atual -> proximo = NULL;
    //se o principal estiver vazio, ser‡ o atual
    if(principal == NULL){
        principal = final = atual;
    }
    //sen‹o, o pr—ximo valor que ser‡ o atual
    else{
        final->proximo=atual;
        final=atual;
    }
    printf("\nValor inserido!\n");
    printf("--------------------------------------");
    getchar();
}


//Exclus‹o
void exclui(){
    Dados *auxiliar;
    printf("\nExclus‹o: \n");
    printf("--------------------------------------\n");
    //o auxiliar ser‡ o pr—ximo da principal
    auxiliar=principal->proximo;
    //limpando a principal
    free(principal);
    //a principal ser‡ a auxiliar
    principal=auxiliar;
    printf("\nValor excluido!\n");
    printf("--------------------------------------");
    getchar();
}


//Mostrando
void mostra(){
    int posicao=0;
    Dados *nova=principal;
    LIMPA_TELA;
    printf("\nMostrando valores: \n");
    printf("--------------------------------------\n");
    //lao de repeti‹o para mostrar os valores
    for (; nova != NULL; nova = nova->proximo) {
        posicao++;
        printf("Posi‹o %d, contŽm o valor %d\n", posicao, nova->valor);
    }
    printf("--------------------------------------");
    getchar();
}


//Mostrando erro de digita‹o
void mostra_erro(){
    LIMPA_TELA;
    printf("\nErro de Digita‹o: \n");
    printf("--------------------------------------\n");
    printf("\nDigite uma op‹o v‡lida (pressione -Enter- p/ continuar)!\n\n");
    printf("--------------------------------------");
    getchar();
}

int main(){
    char escolha;
    //Lao que ir‡ mostrar o menu esperando uma op‹o (char)
    do {
        //Limpando a tela, e mostrando o menu
        LIMPA_TELA;
        printf("\nMŽtodo Fila\n\n");
        printf("Escolha uma op‹o: \n");
        printf("1 - Inserir valor na Fila\n");
        printf("2 - Remover valor da Fila\n");
        printf("3 - Mostrar valores da Fila\n");
        printf("4 - Sair\n\n");
        printf("Resposta: ");
        scanf("%c", &escolha);
        switch(escolha) {
            //Inserindo
            case '1':
                insere();
                break;
            //Excluindo
            case '2':
                if(principal!=NULL){
                    exclui();
                }
                else{
                    printf("\nA Fila est‡ vazia!\n");
                    getchar();
                }
                break;
            //Mostrando
            case '3':
                if(principal!=NULL){
                    mostra();
                }
                else{
                    printf("\n A Fila est‡ vazia! \n");
                    getchar();
                }
                break;
            case '4':
                printf("\n Obrigado por utilizar esse programa! \n");
                sleep(3);
                exit(0);
                break;
            //Se foi algum valor inv‡lido
            default:
                mostra_erro();
                break;
        }
        //Impedindo sujeira na grava‹o da escolha
        getchar();
    }
    while (escolha > 0); //Loop Infinito
    return (-1);
}
