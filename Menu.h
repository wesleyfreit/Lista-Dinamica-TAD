#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no cad_lista;

typedef struct{//Struct apontada ao incio da struct cad_lista, aqui onde ficará o nó que une as duas structs;
    cad_lista *inicio;
} Lista;

cad_lista *adicionar(Lista *lista);

cad_lista *remover(Lista *lista);

void imprimir(Lista lista);

void buscar(Lista lista);
