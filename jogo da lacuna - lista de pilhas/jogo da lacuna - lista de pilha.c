#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<time.h>
#define MAX_BOLAS 4
//#include "pilha.h"
struct pilha
{
    //int itens;
    //No* prim;
    int n;
    int info;
    struct pilha* prox;
};
typedef struct pilha Pilha;

struct rodadas
{
    int n;
    int movimentos;//numero de pilhas
    struct rodadas *prox;//vetor de com as pilhas
};
typedef struct rodadas Historico;

Pilha** cria_pilhas(Pilha **l,int n){
  // srand(time(0));
   Pilha * aux;
   int pos,j;
   int n_cores = n-2;
   int cores[n_cores];
   srand(time(0));
   for(int i=0;i<n_cores;i++){//cria quantidade de cores para lacunas menos 2
     cores[i]=MAX_BOLAS ;
   }
   for(int i=0;i<n-2;i++){
        //l[i] = NULL;
        while(l[i]->n<MAX_BOLAS ){


            pos = rand() % n_cores;
            if(cores[pos]>0)
            {
                aux = malloc(sizeof(Pilha*));
                aux->info = pos;
                aux->prox = l[i]->prox;
                l[i]->prox = aux;
                cores[pos]--;
                l[i]->n++;
            }
          //  printf("\npos: %d",pos);
        }
   }


   return l;
}


Pilha ** ini(int n){
     Pilha **l=malloc(sizeof(n));
     return l;
}

void print_pilhas(Pilha **l,int n)
{
    Pilha *aux;
    printf("\n------------------\n");
    for(int i=0;i<n;i++)
    {
        aux = l[i]->prox;
        printf("Pilha %i: (topo) ",i);
        for(int j=0;j<MAX_BOLAS;j++)
        {
            if(aux!=NULL)
            {
                printf("%i ",aux->info);
                aux=aux->prox;
            }
            else
            {
                printf("- ");
            }

        }
        printf("\n");

    }
    printf("\n------------------\n");
}

Pilha ** jogar(Pilha **l, int orig,int dest, int **hist){
    if(l[dest]->n<MAX_BOLAS)
    {
        if(l[orig]->n>0)
        {
            if(l[dest]->n==0 || l[dest]->prox->info == l[orig]->prox->info )
            {
                Pilha *aux = l[orig]->prox;
                l[orig]->prox = l[orig]->prox->prox;
                l[orig]->n--;
                aux->prox =  l[dest]->prox;
                l[dest]->prox = aux;
                l[dest]->n++;
               // (*hist)->n=9;

            }
            else
            {
                printf("\nA bola de origem e destino são diferentes. Tente novamente...");
            }

        }
        else
        {
           printf("\nO origem nao possui nenhuma bola. Tente novamente...");
        }
    }
    else
    {
        printf("\nO destino ja possui 4 bolas. Tente novamente...");
    }

    return l;
}

void limpa_pilha(Pilha **l,int n)
{
    Pilha *aux,*remove;
    printf("\n------------------\n");
    for(int i=0;i<n;i++)
    {
        aux = l[i]->prox;
        for(int j=0;j<MAX_BOLAS;j++)
        {
            if(aux!=NULL)
            {
                remove = aux;
                aux=aux->prox;
                free(remove);
            }
        }
        free(l[i]);

    }
    free(l);
}

int main()
{
    int n=5,orig,dest,movimentos=0,radadas=0;
    Historico *hist = malloc(sizeof(Historico));
    hist->prox=NULL;
    Pilha **l = malloc(n*sizeof(Pilha));
    Pilha *aux;
    do{
        printf("\nDigite a quantidade de pilhas (de 6 a 12): ");
        scanf("%i",&n);
    }while(n<6 || n>12);
    hist->n = n;

    for(int i=0;i<n;i++){
       l[i] = malloc(sizeof(Pilha*));
       l[i] ->info = -1;
       l[i]->n = 0;
       l[i] ->prox=NULL;

       /*
       aux = malloc(sizeof(Pilha*));
       aux ->info = i;
       aux ->prox=NULL;
       l[i] ->prox=aux;
       printf("\n%i ", l[i]->prox->info);
       */

    }

    l=cria_pilhas(l,n);
    print_pilhas(l,n);
    /*
    l = jogar(l,1,3);
    printf("\n------------------\n");
    print_pilhas(l,n);
    */

    do{
        printf("\nDigite -1 para sair ou -2 para reinicar a rodada...\n");
        printf("\nDigite o valor da pilha de onde sera retirada a bola: ");
        scanf("%i",&orig);
        if(orig>=0)
        {
            printf("\nDigite o valor da pilha onde sera inserida a bola: ");
            scanf("%i",&dest);
            if(orig!=dest)
            {
               if(dest<n)
               {
                   l = jogar(l,orig,dest,&hist);
                   print_pilhas(l,n);
               }
               else
               {
                   printf("\no valor da pilha destino deve ser menor que n. Tente novamente... \n");
               }
            }
            else
            {
               printf("\nValores das pilhas devem ser diferentes. Tente novamente...\n");
            }

        }
    }while(orig>=0 && dest>=0);

    printf("\nNúmero de movimentos: %i",movimentos);

    //Pilha**l=ini(n);
    //l=cria_pilhas(n);
    //l=cria_pilhas(l);

    limpa_pilha(l,n);
    printf("\nSaindo...");
    return 0;
}
















