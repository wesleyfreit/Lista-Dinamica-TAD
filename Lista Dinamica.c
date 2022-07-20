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

// ADICIONAR À LISTA;
cad_lista *adicionar(Lista *lista)
{
   cad_lista *aux, *p = malloc(sizeof(cad_lista));// o ponteiro *p criando dentro de cad_lista para receber a alocação de memória e criar as próximas alocações utilizando o malloc(sizeof(STRUCT_NAME));
   
    if (p)
    {
    	printf("\n-------------------------------------");
        printf("\n|------------ CADASTRO -------------|\n");
        printf("-------------------------------------\n\n");

        printf("| Nome: ");
        fflush(stdin);
        gets(p->nome);

        p->proximo = NULL;

        if (lista->inicio == NULL){ // Se a lista apontada ao início ainda não estiver cadastrada, então insira aqui os valores;
        	lista->inicio = p;
            p->id = 1;
		}
        else
        {
            aux = lista->inicio;
            int x = 2; // variável para controlar a id, sem ser necessário inserí-la;

            while (aux->proximo){//Se o início da lista já estiver preenchido, então vamos caminhar a lista apontando aux ao proximo enquanto proximo != NULL;
            	aux = aux->proximo;
                x++;	
			}
            p->	id = x;
            
            aux->proximo = p; //Quando o aux->proximo == NULL, então receberá p->nome;
         }
        printf("\n-------------------------------------");
        printf("\n|----------- ADICIONADO ------------|\n");  
	    printf("-------------------------------------\n\n");
            
    }
    else
        printf("\nErro ao alocar memória!\n\n");

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
    	printf("\n| Não há dados nessa lista para remover!\n");//Verificação se a lista já foi preenchida;
        printf("\n-------------------------------------\n\n");
	} 
    else
    {
        printf("|------------- REMOÇÃO -------------|\n");
        printf("-------------------------------------\n");
        int n;
        printf("\n| Insira o ID que deseja remover: ");//A partir do ID você poderá remover, podendo consultar o id usando o procedimento imprimir;
        scanf("%d", &n);

        if (lista->inicio->id == n)
        {
            remover = lista->inicio; //tratando igual a forma de adição, caso o id seja igual ao ínicio da lista, remove o primeiro;
            lista->inicio = remover->proximo;
            x = 1;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && aux->proximo->id != n)// tratando igual a forma de adição a lista também, caso não seja o primeiro id, vamos caminhar a lista enquanto id != n;
                aux = aux->proximo;

            if (aux->proximo == NULL)
            {
				printf("\n-------------------------------------\n");
				printf("\n| Esse ID ainda não foi cadastrado nessa lista.\n");//Detalhe, caso o id já seja NULL, é porque o id ainda não foi cadastrado, então esse if serve
				printf("\n-------------------------------------\n\n");       //para não crashar o programa inserindo um id ainda não cadastrado
			}
            else
			{
            	remover = aux->proximo;//Caso o id não seja igual a NULL, então o remover receberá o aux->proximo e aux->proximo será = remover->proximo(que será o valor NULL);
                aux->proximo = remover->proximo;
                x = 1;
			}
        }
        if(x != 0){
        	while (p)
        	{
	            if (p->id > n)
	                p->id--; // E como o que está manipulando tudo é o Id, então vamos reduzir todos os id's também,  todos os p->id serão iguais a id--; 
	
	            p = p->proximo;
        	}
        	printf("\n-------------------------------------");
	        printf("\n|------------ REMOVIDO -------------|\n");
	        printf("-------------------------------------\n\n");
	        return remover;// retornou remover para liberar o espaço lá no subprograma;
		}
    }
}

//IMPRESSÃO DA LISTA;
void imprimir(Lista lista)
{
	cad_lista *p = lista.inicio;

    printf("-------------------------------------\n");
    if (p == NULL)
        printf("\n| Não há dados nessa lista para mostrar!\n");//Se não ouver no inicio da lista então não há dados na lista para mostrar;
    else
    {   
        while(p){
            printf("\n%3d. ", p->id);
            printf("%s", p->nome);//Dessa vez vamos caminhar a lista e imprimir os valores da struct já cadastrados enquanto p, ou enquanto p != NULL, que é a mesma coisa;
            p=p->proximo;
        }       
    }

    printf("\n-------------------------------------\n");
}
//A partir daqui os próximos subprogramas são para fazer a busca entre as 4 listas
//Fazer busca na lista professor
void buscar(Lista lista)
{
	printf("\n-------------------------------------");

    cad_lista *aux, *p = lista.inicio;

    if (p == NULL)
        printf("\n\n| Não há dados cadastrados nessa lista para buscar!\n");//Se não ouver no inicio da lista então não há dados na lista para mostrar;

    else
    {
        printf("\n|-------------- BUSCA --------------|");
        printf("\n-------------------------------------\n\n");
        int n;
        printf("| Insira o ID que deseja buscar: ");// Caso haja dados, entrará na condição de inserir a id para buscar;
        scanf("%d", &n);

        if (lista.inicio->id == n)
        {
            printf("\n-------------------------------------\n");
            printf("-------------------------------------\n");
            printf("\n%3d. ", p->id);//caso a id seja do começo da lista, id = 1, irá imprimir o primeiro valor
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
				printf("\n| Esse ID ainda não foi cadastrado nessa lista.\n");//Se o id for igaul a NULL, ele não foi cadastrado ainda, então entra nesta condição;
			}
			else{
				printf("\n-------------------------------------\n");
	            printf("-------------------------------------\n");
	            printf("\n%3d. ", aux->proximo->id);//Se não for igual a NULL, irá imprimir o correspondente a parada da lista;
	            printf("%s\n", aux->proximo->nome);
			}
			printf("\n-------------------------------------");  
        }
	}
	printf("\n-------------------------------------\n\n");
	
    system("pause");
}
