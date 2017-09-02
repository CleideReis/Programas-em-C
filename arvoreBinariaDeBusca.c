// Aluno : Cleide Ferreira de Oliveira Reis

/*
 Sintese
   Objetivo: arvore binária de busca
 
   Entrada : dado

   Saida   : dados

*/

#include <stdio.h>
#include <conio.c>

typedef struct No{
	int valor;
	struct No *esq;
	struct No *dir;
}No;

int menu( void );
void incluir(struct No **, int);
void preOrder(struct No *);
void inOrder(struct No *);
void posOrder(struct No *);
int buscar(struct No *, int);
void destruir(struct No *);
void espelhar(struct No *p);

int main(void)
{
// Declaracoes
	struct No *raiz = NULL;
	int opcao, valor;
// Instrucoes
	
	do{
		opcao = menu();
		system("cls");
		switch (opcao)
		{
			case 1:
				printf("Informe o dado: \n");
				scanf("%d",&valor);
				incluir(&raiz, valor);
				break;
			case 2:
				preOrder(raiz);
				getch();
				espelhar(raiz);
				preOrder(raiz);
				break;
			case 3:
				inOrder(raiz);
				break;
			case 4:
				posOrder(raiz);
				break;
			case 5:
				printf("Digite o valor: ");
    			scanf("%d", &valor);
				if(buscar(raiz, valor))
					printf("Achou!\n");
				else
					printf("Nao achou!\n");
				break;
			case 0:
				exit(0);
			break;
		}
	}while(opcao != 0);
	
	destruir(raiz);
  getch();
  return 0;
}

int menu( void )
{
	int op;
	do{
		printf("\n[----- MENU -----]\n\n");
		printf("(1) - Incluir\n");
		printf("(2) - PreOrder\n");
		printf("(3) - InOrder\n");
		printf("(4) - PosOrder\n");
		printf("(5) - Busca\n");
		printf("(0) - Sair\n-> ");
		scanf("%d",&op);
		if(op < 0 || op > 5)
			printf("Opcao invalida!");
	}while(op < 0 || op > 5);
	return op;
}

void destruir(struct No *p) 
{
	if (p != NULL) {
		destruir(p->esq);
		destruir(p->dir);
	    free(p);
	}
}

void incluir(struct No **raiz, int val)
{
	struct No *p;
	
	if((*raiz) == NULL)
	{
		(*raiz) = malloc(sizeof(struct Dado*));
		(*raiz)->valor = val;
		(*raiz)->dir = (*raiz)->esq = NULL;
	}else{
		p = (*raiz);
		if(val < p->valor)
			incluir(&(p->esq), val);
		if(val > p->valor)
			incluir(&(p->dir), val);
	}
  
}

void espelhar(struct No *p)
{
	struct No *q;
	
	if(p == NULL)
		return;
	espelhar(p->esq);
	espelhar(p->dir);
	q = p->esq;
	p->esq = p->dir;
	p->dir = q;
}

void preOrder(struct No *p)
{
	if(p != NULL)
	{
		printf("%d - ",p->valor);
		preOrder(p->esq);
		preOrder(p->dir);
	}
}

void inOrder(struct No *p)
{
	if(p != NULL)
	{
		inOrder(p->esq);
		printf("%d - ",p->valor);
		inOrder(p->dir);
	}
}

void posOrder(struct No *p)
{
	if(p != NULL)
	{		
		posOrder(p->esq);
		posOrder(p->dir);
		printf("%d - ",p->valor);
	}
}
          
int buscar(struct No *p, int val) 
{  
	if(p == NULL)
    	return 0;
	printf("%d - ", p->valor);
  	if(val == p->valor)
    	return 1;
  	if(val < p->valor)
    	return buscar(p->esq, val);
  	return buscar(p->dir, val);
}


