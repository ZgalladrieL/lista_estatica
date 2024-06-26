#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int qtd;
    struct aluno dados[MAX];    
}Lista;

Lista *cria_lista() {
    Lista *nova_lista = (Lista*)malloc(sizeof(Lista));

    if(nova_lista != NULL) 
        nova_lista -> qtd = 0;
    return nova_lista;
} 

void libera_lista(Lista *li) {
    free(li);
}

int tamanho_lista(Lista *li) {
    if(li == NULL) {
        return -1;
    } else
        return li -> qtd;
}

bool lista_cheia(Lista *li) {
   if(li == NULL) return -1;
    return li -> qtd == MAX;
}

// inserindo elementos 

int insere_lista_final(Lista *li, struct aluno al) {
    if(li == NULL) return -1;
    if(lista_cheia(li)) return -1;

    li -> dados[li -> qtd] = al;
    li -> qtd++;
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al) {
    if(li == NULL) return -1;
    if(li -> qtd == MAX) return -1;
    int i;

    for(i = li -> qtd-1; i>= 0; i--) {
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;

    return 1;
}

int insere_lista_ordenado(Lista *li, struct aluno al) {
    if(li == NULL) return -1;
    if(li -> qtd == MAX) return -1;
    int k, i = 0;


    while(i < li -> qtd && li -> dados[i].matricula < al.matricula){
        i++;
    }

    for(k = li -> qtd-1; k>=i; k--) {
        li->dados[k+1] = li->dados[k];
    }
    li-> dados[i] = al;
    li-> qtd++;
    return 1;
}

// Removendo elementos

int remove_lista_final(Lista *li) {
    if(li == NULL) return -1;
    if(li-> qtd == 0) return -1;

    li-> qtd--;
    return 1;
}

int remove_lista_inicio(Lista *li) {
    if(li == NULL) return -1;
    if(li-> qtd == 0) return -1;

    int k = 0;

    for(k=0; k < li->qtd; k++){
        li->dados[k] = li->dados[k+1];
    }
    li-> qtd--;
    return 1;
}

int remove_lista_meio(Lista *li, int mat) {
    if(li == NULL) return -1;
    if(li-> qtd == 0) return -1;
    int i, k = 0;

    while (i < li-> qtd && li->dados[i].matricula != mat) {
        i++;
    }
    if(i == li-> qtd) return -1;

    for(k=i; k < li->qtd; k++){
            li->dados[k] = li->dados[k+1];
        }
    li-> qtd--;
    return 1;
}

// Consultar elemento 

int consulta_lista_pos(Lista *li, int pos, struct aluno *al) {
    if(li == NULL || pos <= 0 || pos > li->qtd) return -1;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista *li, int mat, struct aluno *al) {
    if(li == NULL) return -1;
    int i = 0;

    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd) return -1;

    *al = li->dados[i];
    return 1;
}

