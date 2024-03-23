/******************************************************************************

Fila Estática

*******************************************************************************/
#include <stdio.h>
#define MAX 5

typedef struct Fila{//cria estrutura de fila apelidando de F
    int vetor[MAX];//cria vetor com tamanho fixo
    int inicio, fim; //define início e fim para o vetor (onde começa e termina a fila)
}F;

void insere(F *f, int info){
    if(f->inicio == -1){//verifica se fila está vazia
        f->inicio = f->inicio + 1;//incrementa início
        f->vetor[f->inicio] = info;//vetor na nova posição de início recebe a informação
        f->fim = f->inicio;//fim recebe mesmo index de início, que é zero nesse caso 
        return;//sai da função neste ponto, caso a fila estiver vazia
    }
    //chega aqui caso a fila não estava vazia quando entrou na função
    f->fim = f->fim + 1;//incrementa fim
    f->vetor[f->fim] = info;//vetor na nova posição de fim recebe info
}

int removeFila(F *f){
    if(f->inicio == -1) return 0;//sai da função se fila vazia
    int info = f->vetor[f->inicio];//guarda a info a ser removida
    f->inicio = f->inicio + 1;//incrementa inicio
    if(f->inicio > f->fim){//se após incrementa info, a lista ficar vazia, então reseta ela
        f->inicio = -1;
        f->fim = 0;
    }
    return info;
}

void printFila(F f){
    if(f.inicio == -1){
       printf("\nFila vazia");
       return;
    } 
    printf("\nImprima fila:");
    for(int i=f.inicio; i<=f.fim;i++){
        printf("\n%d",f.vetor[i]);
    }
}

int main()
{
    F f;
    f.inicio = -1;
    insere(&f, 9);
    insere(&f,10);
    printFila(f);
    printf("\nRemove: %d",removeFila(&f));
    printf("\nRemove: %d",removeFila(&f));
    printf("\nRemove: %d",removeFila(&f));
    printFila(f);

    return 0;
}
