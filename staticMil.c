/***
  ** UFMT - Ciencia da Computacao
  ** Estrutura de Dados I - Prof. Ivairton M. Santos
  ** Alunos - Bruno Azevedo Dias Paes, Pedro Lucas Silva Correia
  **
  ** Implementacao de Lista Estatica 1000 elementos
  **/

//Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Constante
#define N 1000

//Definindo lista
struct estLista {
    int vetLista[N];
    int qtdDados;
}; typedef struct estLista tipoLista;


//Definindo funções

//Verificar se lista está cheia.
int listaCheia(tipoLista lst){
    if (lst.qtdDados < N){
        return 0;
    } else {
        return 1;
    }
}

//Inserir no inicio da lista
void insereInicio(tipoLista *lst, int valor){
    int i;
    for(i = lst->qtdDados; i > 0; i--){
        lst->vetLista[i] = lst->vetLista[i-1];
    }
    lst->vetLista[0] = valor;
    lst->qtdDados++;
}

//Inserir no fim da lista
void insereFim(tipoLista *lst, int valor){
    lst->vetLista[lst->qtdDados] = valor;
    lst->qtdDados++;
    
}

//Inserir na posição escolhida
void inserePosicao(tipoLista *lst, int valor, int pos){
    int i;
    for(i = lst->qtdDados; i > pos; i--){
    lst->vetLista[i] = lst->vetLista[i-1];
    }
    lst->vetLista[pos] = valor;
    lst->qtdDados++;
    
}


int main(void){
    
    clock_t timer;
    double temporizador[10], media;

    for(int k = 0; k < 10; k++){
        int j = 0;
        tipoLista novaLista;
        novaLista.qtdDados = 0;
        
        srand(time(0));

        timer = clock();

        do{
            insereInicio(&novaLista, rand());
            j++;
        } while (j < (N / 3));

        j = 0;
        
        do{
            insereFim(&novaLista, rand());
            j++;
        } while (j < (N / 3));

        j = 0;

        do{
            inserePosicao(&novaLista, rand(), (rand() % N));
        } while (listaCheia(novaLista) != 1);


        double Tempo = (clock() - timer) * 1000.0 / (double)CLOCKS_PER_SEC;
        temporizador[k] = Tempo;
        printf("TIMER %d: %lf\n",k+1,Tempo);
    }

    for(int l = 0; l < 10; l++){
        media += temporizador[l]; 
    }
    media = media / 10;
    printf("O tempo medio da fila estatica de %d dados foi de %.4lf ms\n", N, media);

    return 1;
}
