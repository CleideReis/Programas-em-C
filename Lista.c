// Aluno : Cleide Reis

/*
 Sintese
   Objetivo: Lista Simplesmente Encadeada com inclusão, alteração, exclusão, consulta e listagem
 
   Entrada : codigo, descrição e preço

   Saida   : dados cadastrados por ordem crescente de código do produto

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.c>
#define TAM_DESC 30

typedef struct Produto{
	int codigo;
	char descricao[TAM_DESC];
	float preco;
	struct Produto *prox;
}Produto;

void incluir(struct Produto**);
int menu( void );
void listar(struct Produto * lista);
void lerDados(struct Produto*);
void excluir(struct Produto**); 
void alterar(struct Produto*); 
void consultar(struct Produto*);

int main(void)
{
// Declaracoes
	struct Produto *p = NULL, *q;
	int opcao;
// Instrucoes
	do{
		opcao = menu();
		system("cls");
		switch(opcao)
		{
			case 1: incluir(&p); break;
			case 2: alterar(p); break;
			case 3: excluir(&p); break;
			case 4: consultar(p); break;
			case 5: listar(p);   break;
			case 0: exit(0); break;
		}	
	}while(opcao != 0);
	
	while(p != NULL){
		q = p;
		p = p->prox;
		free(q);
	}

  getch();
  return 0;
}

// menu 
int menu( void )
{ 
	int op;
	printf("[----- MENU -----]\n\n");
	printf("(1) - Incluir\n");
	printf("(2) - Alterar\n");
	printf("(3) - Excluir\n");
	printf("(4) - Consultar\n");
	printf("(5) - Listar\n");
	printf("(0) - Sair\n->");
	scanf("%d",&op);
	
	return op;
}

// incluir dados na lista
void incluir(struct Produto **ini)
{
	struct Produto *p, *novo;
	
	novo = (struct Produto*) malloc (sizeof(struct Produto));
	
	lerDados(novo);		
	
	if(*ini == NULL){
		novo->prox = NULL;
		*ini = novo;
	}else{
		if(novo->codigo < (*ini)->codigo){
			if(novo->codigo != (*ini)->codigo){
				novo->prox = *ini;
				*ini = novo;
			}else{
				printf("Codigo ja existe!\n");
				return;	
			}
		}else{
			p = *ini;
			while((p != NULL) && (p->prox != NULL)){
				if(p->prox->codigo > novo->codigo){ 
					if(novo->codigo != p->codigo){
						novo->prox = p->prox;
						p->prox = novo;
						p = NULL;
					}else{
						printf("Codigo ja existe!\n");
						return;	
					}
				}else{
					p = p->prox;
				}
			}
			if(p != NULL){
				if(p->codigo == novo->codigo){
					printf("Codigo ja existe!\n");	
				}else{
					novo->prox = NULL;
					p->prox = novo;
				}
			}
		}
	}
}

// ler os dados
void lerDados(struct Produto * p)
{
	printf("Informe o codigo do produto: \n");
	scanf("%d",&p->codigo);
	printf("Informe a descricao do produto: \n");
	fflush(stdin);
	fgets(p->descricao,TAM_DESC,stdin);
	fflush(stdin);
	if(p->descricao[strlen(p->descricao)-1]=='\n'){
		p->descricao[strlen(p->descricao)-1]='\0';
	}
	printf("Informe o preco do produto: \n");
	scanf("%f",&p->preco);
	
}

// listar produtos
void listar(struct Produto * lista)
{
	if(lista == NULL)
	{
		printf("Nao existe dados cadastrados.\n");
	}else{
		printf("===== Listar =====\n\n");
		while(lista != NULL){
			printf("Codigo....: %d\n",lista->codigo);
			printf("Descricao.: %s\n",lista->descricao);
			printf("Preco.....: %.2f\n",lista->preco);
			lista = lista->prox;
		}
	}
	
}

// consultar produto
void consultar(struct Produto * p) 
{
	int cod;
	int aux = 0;
	
	if(p == NULL){
		printf("Lista vazia.\n");
		return;
	}
	
	printf("Informe o codigo para consulta: \n");
	scanf("%d",&cod);
	
    while (p != NULL) {
    	if(p->codigo == cod)
    	{
		    printf("Codigo ......: %d \n",p->codigo);
		    printf("Descricao ...: %s \n",p->descricao);
		    printf("Preco .......: %.2f \n",p->preco);
			aux = 1;	
		}
    	p = p->prox;
    }
    if(aux==0)
    {
		printf("Produto nao encontrado.\n");
	}
}

// excluir dados
void excluir(struct Produto ** ini) 
{
	struct Produto * p, *q;
	int cod;
	int aux = 0;
	
	if((*ini) == NULL){
		printf("Lista vazia.\n");
		return;
	}else{
		printf("Informe o codigo que deseja excluir: \n");
		scanf("%d",&cod);		
		if((*ini)->codigo == cod){
			aux = 1;
			q = (*ini);
			(*ini)= (*ini)->prox;
		}
		else{
			p = (*ini);
			while(p!= NULL && p->prox != NULL){
				if(p->prox->codigo == cod){
					aux = 1;
					q = p->prox;
					p->prox = p->prox->prox;
					p = NULL;
				}
				else{
					p = p->prox;
				}
			}
		}
	}
	if(p == NULL){
		free(q);
		q = NULL;
	}
	
	if(aux == 1)
	{
		printf("Dado excluido com sucesso!\n");
	}else{
		printf("Dado nao encontrado!\n");
	}
}
// alterar dado
void alterar(struct Produto * p) 
{
	int cod;
	int aux = 0;
	
	if(p == NULL){
		printf("Lista vazia.\n");
		return;
	}
	
	printf("Informe o codigo para alteracao: \n");
	scanf("%d",&cod);
	
    while (p != NULL) {
    	if(cod == p->codigo)
    	{
    		printf("Informe a descricao do produto: \n");
			fflush(stdin);
			fgets(p->descricao,TAM_DESC,stdin);
			fflush(stdin);
			if(p->descricao[strlen(p->descricao)-1]=='\n'){
				p->descricao[strlen(p->descricao)-1]='\0';
			}
			printf("Informe o preco do produto: \n");
			scanf("%f",&p->preco);
    		aux = 1;
			return;	
		}
    	p = p->prox;
    }
    if(aux==0)
    {
		printf("Produto nao encontrado.\n");
	}
}









  
