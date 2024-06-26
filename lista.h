#ifndef LISTA_H
#define LISTA_H
#define MAX 100
#include <stdbool.h>

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct  lista Lista;

// Manipulando a lista

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
bool lista_cheia(Lista *li); 

// Inserindo elementos na lista

int insere_lista_final(Lista *li, struct aluno al);
int insere_lista_inicio(Lista *li, struct aluno al);
int insere_lista_ordenado(Lista *li, struct aluno al);

// Inserindo elementos na lista

int remove_lista_final(Lista *li);
int remove_lista_inicio(Lista *li);
int remove_lista_meio(Lista *li, int mat);

// Consulta de elemento
int consulta_lista_pos(Lista *li, int pos, struct aluno *al);
int consulta_lista_mat(Lista *li, int mat, struct aluno *al);

#endif