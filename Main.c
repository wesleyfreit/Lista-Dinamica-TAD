#include "Menu.h"

//MENU GUIA
int busca(int v)
{ 
    do{
        printf("\n-------------------------------------\n");
        printf("--------------- GUIAS ---------------\n"); 
        printf("-------------------------------------\n"); 
		printf("\n   1 - PROFESSORES");
		printf("\n   2 - ESTUDANTES");
		printf("\n   3 - CURSOS");
		printf("\n   4 - TURMAS");
        printf("\n\n-------------------------------------\n"); 
        printf("-------------------------------------\n"); 
		
		printf("\n|- INSIRA A GUIA QUE DESEJA ENTRAR: ");
		scanf("%d", &v);
		if(v < 1 && v > 4){
			printf("\n| NÚMERO INCORRETO, TENTE NOVAMENTE! |");
		}
		else
			break;
	}while(v);
	
	return v;
}

//MENU PRINCIPAL
int menu(int n)
{
    system("cls");
    printf("\n---------------------------------------");
    printf("\n---------------- MENU -----------------");
    printf("\n---------------------------------------\n");
    printf("\n   1 - Adicionar Entidade");
    printf("\n   2 - Remover Entidade");
    printf("\n   3 - Listar Entidades");
    printf("\n   4 - Buscar Entidade");
    printf("\n   5 - Encerrar Programa\n");
    printf("\n---------------------------------------\n");
    printf("---------------------------------------\n");

    printf("\n|- INSIRA UMA OPCÃO: ");
	scanf("%d", &n);
	
	return n;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista listaA;//criar as 4 listas a partir da struct Lista;
    Lista listaP;
    Lista listaT;
    Lista listaC;
    
    cad_lista *remove; // variável para limpar o endereço de memória do cad_lista ao remover um item;
	
    criar_lista(&listaA);//igualar a NULL o inicio das 4 listas;
    criar_lista(&listaP);
    criar_lista(&listaT);
    criar_lista(&listaC);

    int n = 0, v = 0;

    do// repetidor infinito enquanto não inserir 5 no switch;
    {
        n = menu(n);//menu principal para guiar a qual aba entrar;

        switch (n)
        {
	        case 1:// CASO 1 ADICIONA A LISTA
	            system("cls");
	            
	            v = busca(v);//menu secundário para guiar a qual lista entrar;
	
	            system("cls");
	            if(v == 1)
					adicionar(&listaP);
				if(v == 2)
					adicionar(&listaA);
				if(v == 3)
					adicionar(&listaC);
				if(v == 4)
					adicionar(&listaT);
	            system("cls");
	            break;
	        case 2:// CASO 2 REMOVE DA LISTA
	        	system("cls");
	
	            v = busca(v);
	
	            system("cls");
				if(v == 1){
					remove = remover(&listaP);
					if (remove)
			            free(remove);//LIMPAR ENDEREÇO DE MEMÓRIA
				}
				if(v == 2){
					remove = remover(&listaA);
					if (remove)
			            free(remove);
				}
				if(v == 3){
					remove = remover(&listaC);
					if (remove)
			            free(remove);
				}
				if(v == 4){
					remove = remover(&listaT);
					if (remove)
			            free(remove);
				}
				system("pause");
	            system("cls");
	        	break;
	        case 3://IMPRESSÃO DE TUDO
	            system("cls");
	            printf("\n-------------------------------------\n");
	    		printf("------------ PROFESSORES ------------\n");
	            imprimir(listaP);
	    		printf("-------------- ALUNOS ---------------\n");
	            imprimir(listaA);
	    		printf("-------------- CURSOS ---------------\n");
	            imprimir(listaC);
	    		printf("-------------- TURMAS ---------------\n");
	            imprimir(listaT);
	            printf("-------------------------------------\n\n");
	            system("pause");
	            system("cls");
	            break;
	        case 4://BUSCA SELECIONADA POR ID
	        	system("cls");
	            
	            v = busca(v);
	
	            system("cls");
	            if(v == 1)
					buscar(listaP);
				if(v == 2)
					buscar(listaA);
				if(v == 3)
					buscar(listaC);
				if(v == 4)
					buscar(listaT);
	            
	            system("cls");
	        	break;
	        case 5:
	            system("cls");
	            printf("\n-------------- PROGRAMA FINALIZADO -------------\n\n");
	            break;
	        default:
	            system("cls");
	            printf("\n---------------------------------------\n");
	            printf("------------ OPÇÃO INVÁLIDA -----------\n");
	            printf("---------------------------------------\n");
	            printf("----------- TENTE NOVAMENTE -----------\n");
	            printf("---------------------------------------\n\n");
	            system("pause");
	            system("cls");
	            break;
        }
    } while (n != 5);
}
