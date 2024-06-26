#include <stdio.h>
#include "lista.c" 

int main() {
    Lista *li = cria_lista();
    
    struct aluno a1;
    a1.matricula = 123;
    snprintf(a1.nome, sizeof(a1.nome), "Caio");

    struct aluno a2;
    a2.matricula = 124;
    snprintf(a2.nome, sizeof(a2.nome), "Adriel");

    struct aluno a3;
    a3.matricula = 125;
    snprintf(a3.nome, sizeof(a3.nome), "Rego");
    
    printf("------------------------------------------------------\n");

    int inserido1 = insere_lista_inicio(li, a1);
    printf("Inserido com sucesso ? %d\n", inserido1);

    int inserido2 = insere_lista_final(li, a2);
    printf("Inserido com sucesso ? %d\n", inserido2);

    int inserido3 = insere_lista_ordenado(li,a3);
    printf("Inserido com sucesso ? %d\n", inserido3);

    int tamanho = tamanho_lista(li);
    printf("Tamanho lista : %d\n", tamanho);
    
    printf("------------------------------------------------------\n");

    int removido2 = remove_lista_final(li);
    printf("Removido com sucesso ? %d\n", removido2);

    int tamanho2 = tamanho_lista(li);
    printf("Tamanho lista : %d\n", tamanho2);

    printf("------------------------------------------------------\n");

    int consulta1 = consulta_lista_pos(li, 1, &a2);
    printf("Resultado consulta : %d", consulta1);
    return 0;
}
