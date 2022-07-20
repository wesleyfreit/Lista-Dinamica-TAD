#include "Menu.h"

typedef struct no{ //Struct para unir a Lista;
	char nome[40];
    int id;
	struct no *proximo;
} cad_lista;

//ZERANDO O INICIO DA LISTA
void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
}

// ADICIONAR � LISTA;
cad_lista *adicionar(Lista *lista)
{
   cad_lista *aux, *p = malloc(sizeof(cad_lista));// o ponteiro *p criando dentro de cad_lista para receber a aloca��o de mem�ria e criar as pr�ximas aloca��es utilizando o malloc(sizeof(STRUCT_NAME));
   
    if (p)
    {
    	printf("\n-------------------------------------");
        printf("\n|------------ CADASTRO -------------|\n");
        printf("-------------------------------------\n\n");

        printf("| Nome: ");
        fflush(stdin);
        gets(p->nome);

        p->proximo = NULL;

        if (lista->inicio == NULL){ // Se a lista apontada ao in�cio ainda n�o estiver cadastrada, ent�o insira aqui os valores;
        	lista->inicio = p;
            p->id = 1;
		}
        else
        {
            aux = lista->inicio;
            int x = 2; // vari�vel para controlar a id, sem ser necess�rio inser�-la;

            while (aux->proximo){//Se o in�cio da lista j� estiver preenchido, ent�o vamos caminhar a lista apontando aux ao proximo enquanto proximo != NULL;
            	aux = aux->proximo;
                x++;	
			}
            p->	id = x;
            
            aux->proximo = p; //Quando o aux->proximo == NULL, ent�o receber� p->nome;
         }
        printf("\n-------------------------------------");
        printf("\n|----------- ADICIONADO ------------|\n");  
	    printf("-------------------------------------\n\n");
            
    }
    else
        printf("\nErro ao alocar mem�ria!\n\n");

    system("pause");	
}
// REMOVER DA LISTA;
cad_lista *remover(Lista *lista)
{
	printf("\n-------------------------------------\n");

    cad_lista *remover, *aux = NULL;
    cad_lista *p = lista->inicio;
    int x = 0;

    if (p == NULL){
    	printf("\n| N�o h� dados nessa lista para remover!\n");//Verifica��o se a lista j� foi preenchida;
        printf("\n-------------------------------------\n\n");
	} 
    else
    {
        printf("|------------- REMO��O -------------|\n");
        printf("-------------------------------------\n");
        int n;
        printf("\n| Insira o ID que deseja remover: ");//A partir do ID voc� poder� remover, podendo consultar o id usando o procedimento imprimir;
        scanf("%d", &n);

        if (lista->inicio->id == n)
        {
            remover = lista->inicio; //tratando igual a forma de adi��o, caso o id seja igual ao �nicio da lista, remove o primeiro;
            lista->inicio = remover->proximo;
            x = 1;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && aux->proximo->id != n)// tratando igual a forma de adi��o a lista tamb�m, caso n�o seja o primeiro id, vamos caminhar a lista enquanto id != n;
                aux = aux->proximo;

            if (aux->proximo == NULL)
            {
				printf("\n-------------------------------------\n");
				printf("\n| Esse ID ainda n�o foi cadastrado nessa lista.\n");//Detalhe, caso o id j� seja NULL, � porque o id ainda n�o foi cadastrado, ent�o esse if serve
				printf("\n-------------------------------------\n\n");       //para n�o crashar o programa inserindo um id ainda n�o cadastrado
			}
            else
			{
            	remover = aux->proximo;//Caso o id n�o seja igual a NULL, ent�o o remover receber� o aux->proximo e aux->proximo ser� = remover->proximo(que ser� o valor NULL);
                aux->proximo = remover->proximo;
                x = 1;
			}
        }
        if(x != 0){
        	while (p)
        	{
	            if (p->id > n)
	                p->id--; // E como o que est� manipulando tudo � o Id, ent�o vamos reduzir todos os id's tamb�m,  todos os p->id ser�o iguais a id--; 
	
	            p = p->proximo;
        	}
        	printf("\n-------------------------------------");
	        printf("\n|------------ REMOVIDO -------------|\n");
	        printf("-------------------------------------\n\n");
	        return remover;// retornou remover para liberar o espa�o l� no subprograma;
		}
    }
}

//IMPRESS�O DA LISTA;
void imprimir(Lista lista)
{
	cad_lista *p = lista.inicio;

    printf("-------------------------------------\n");
    if (p == NULL)
        printf("\n| N�o h� dados nessa lista para mostrar!\n");//Se n�o ouver no inicio da lista ent�o n�o h� dados na lista para mostrar;
    else
    {   
        while(p){
            printf("\n%3d. ", p->id);
            printf("%s", p->nome);//Dessa vez vamos caminhar a lista e imprimir os valores da struct j� cadastrados enquanto p, ou enquanto p != NULL, que � a mesma coisa;
            p=p->proximo;
        }       
    }

    printf("\n-------------------------------------\n");
}
//A partir daqui os pr�ximos subprogramas s�o para fazer a busca entre as 4 listas
//Fazer busca na lista professor
void buscar(Lista lista)
{
	printf("\n-------------------------------------");

    cad_lista *aux, *p = lista.inicio;

    if (p == NULL)
        printf("\n\n| N�o h� dados cadastrados nessa lista para buscar!\n");//Se n�o ouver no inicio da lista ent�o n�o h� dados na lista para mostrar;

    else
    {
        printf("\n|-------------- BUSCA --------------|");
        printf("\n-------------------------------------\n\n");
        int n;
        printf("| Insira o ID que deseja buscar: ");// Caso haja dados, entrar� na condi��o de inserir a id para buscar;
        scanf("%d", &n);

        if (lista.inicio->id == n)
        {
            printf("\n-------------------------------------\n");
            printf("-------------------------------------\n");
            printf("\n%3d. ", p->id);//caso a id seja do come�o da lista, id = 1, ir� imprimir o primeiro valor
            printf("%s\n", p->nome);
            printf("\n-------------------------------------");
        }
        else
        {
            aux = lista.inicio;
            while (aux->proximo && aux->proximo->id != n)//Caso seja depois do id 1, temos quecaminhar a lista enquanto id != n para igualar lista e n;
                aux = aux->proximo;

			if(aux->proximo == NULL){
				printf("\n-------------------------------------\n");
				printf("\n| Esse ID ainda n�o foi cadastrado nessa lista.\n");//Se o id for igaul a NULL, ele n�o foi cadastrado ainda, ent�o entra nesta condi��o;
			}
			else{
				printf("\n-------------------------------------\n");
	            printf("-------------------------------------\n");
	            printf("\n%3d. ", aux->proximo->id);//Se n�o for igual a NULL, ir� imprimir o correspondente a parada da lista;
	            printf("%s\n", aux->proximo->nome);
			}
			printf("\n-------------------------------------");  
        }
	}
	printf("\n-------------------------------------\n\n");
	
    system("pause");
}
