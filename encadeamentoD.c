/***
  ** UFMT - Ciencia da Computacao
  ** Estrutura de Dados I - Prof. Ivairton M. Santos
  ** Alunos - Bruno Azevedo Dias Paes, Pedro Lucas Silva Correia
  **
  ** Implementacao de Lista dinamica de encadeamento duplo
  **/

//Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definindo lista

typedef struct estLista {
    int valor;
    struct estLista *prox;
    struct estLista *ant;
} tipoLista;

//Definindo funções

//Inserir no inicio da lista
void insereInicio(tipoLista **lst, int valorNovo){
    tipoLista *nova, *aux;
    aux = *lst;
    nova = malloc(sizeof(tipoLista));
    nova->ant = NULL;
    nova->valor = valorNovo;
    //Verifica o caso da lista estar vazia
    if(*lst == NULL){
        nova->prox = NULL;
        *lst = nova;
    } else {
        //Percorre até o inicio da lista
        while(aux->ant != NULL){
            aux = aux->ant;
        }
        aux->ant = nova;
        nova->prox = aux;
        
    }
}

//Inserir no fim da lista
void insereFim(tipoLista **lst, int valorNovo){
    tipoLista *nova, *aux;
    aux = *lst;
    nova = malloc(sizeof(tipoLista));
    nova->valor = valorNovo;
    nova->prox = NULL;
    //Verifica se lista está vazia
    if(*lst == NULL){
        nova->ant = NULL;
        *lst = nova;
    } else {
        //Percorre até o final da lista
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
        nova->ant = aux;
    }
    
}

//Inserir na posição desejada
void inserePosicao(tipoLista **lst, int valorNovo, int posicao){
    tipoLista *nova, *aux;
    aux = *lst;
    nova = malloc(sizeof(tipoLista));
    nova->valor = valorNovo;
    int contador = 0;

    //Verifica o caso da lista estar vazia
    if(*lst == NULL){
        nova->prox = NULL;
        *lst = nova;
    } else {
        //Percorre até o inicio da lista
        while(aux->ant != NULL){
            aux = aux->ant;
        }
	    //Percorre a lista até a posição desejada ou até a lista acabar
        while((contador < posicao) && (aux->prox != NULL)){
            contador++;
            aux = aux->prox;
        }
        
        } if((contador == posicao) && (posicao > 0)){
            nova->ant = aux->ant;
            nova->prox = aux;
            aux->ant->prox = nova;
            aux->ant = nova;
        }

}

//Printa a lista
void printaLista(tipoLista *lst){
    tipoLista *aux;
    aux = lst;
    if(aux == NULL){
    } else {
        while(aux->ant != NULL){
            aux = aux->ant;
        }
        do{
            printf("%d ", aux->valor);
            aux = aux->prox;
        } while (aux != NULL);
        printf("\n");
    }
}


int main(void){
    
    clock_t timer;
    double temporizador[10], media;

	//Realiza as inserções(1/3 no inicio; 1/3 no fim; 1/3 posições aleatorias)
    for(int k = 0; k < 10; k++){
        int j = 0, dados = 0;
        tipoLista *lista = NULL;
        
        srand(time(0));

        timer = clock();

        do{
            insereInicio(&lista, rand());
            j++;
            dados++;
        } while (j < (10000 / 3));

        j = 0;
        
        do{
            insereFim(&lista, rand());
            j++;
            dados++;;
        } while (j < (10000 / 3));

        j = 0;

        do{
            inserePosicao(&lista, rand(), (rand() % dados));
            dados++;
        } while (dados <= 10000);

        double Tempo = (clock() - timer) * 1000.0 / (double)CLOCKS_PER_SEC;
        temporizador[k] = Tempo;
        printf("TIMER %d: %lf\n",k+1,Tempo);
    }

	//Realiza a média, dentre as 10 operações realizadas	
    for(int l = 0; l < 10; l++){
        media += temporizador[l]; 
    }
    media = media / 10;
    printf("O tempo medio da fila dinamica de encadeamento duplo foi de %.4lf ms\n", media);

    return 1;
}
