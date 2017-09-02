// Aluno : Cleide Reis

/*
 Sintese
   Objetivo: lista simplesmente encadeada que verifica se a palavra é palindromo 
 
   Entrada : palavra

   Saida   : listar

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Registro {
	char palavra[30];
	struct Registro *prox;
} Registro;

void incluir(struct Registro **); 
void receberChave(struct Registro *p);
void listar( struct Registro * p );
void palindromo(const char *s); 
int menu(void);

int main(void)
{
// Declaracoes
	int opcao;
	struct Registro *inicio = NULL, *p = NULL;
// Instrucoes
	do{
		opcao = menu();
		system("cls");
		switch (opcao)
		{
			case 1: incluir(&inicio);   break;
			case 2: listar(inicio);     break;
			case 0: exit(0);            break;	
		}
	}while(opcao != 0);
	
	while (inicio != NULL) {
	    p = inicio;
	    inicio = inicio->prox;
	    free(p);
    }

  	getch();
  	return 0;
}

int menu(void)
{
	int op;
	
	do{
		printf("[----- MENU -----]\n\n");
		printf("(1) Incluir\n");
		printf("(2) Listar\n");
		printf("(0) Sair\n\n->");
		scanf("%d",&op);
		if(op < 0 || op > 2)
			printf("Opcao invalida!\n");	
	}while(op < 0 || op > 2);
	
	return op;
}

// incluir na lista
void incluir(struct Registro **ini) 
{
	struct Registro *novo, *p;

	novo = (struct Registro *) malloc(sizeof(struct Registro));
	receberChave(novo);
	
	if (*ini == NULL) {
		novo->prox = NULL;
		*ini = novo;
		palindromo(novo->palavra);
	}
	else 
	{
		if (stricmp(novo->palavra,(*ini)->palavra) < 0) 
		{
			palindromo(novo->palavra);
			
			novo->prox = *ini;
			*ini = novo;
			
		}
		else 
		{
			p = *ini;
			while ((p != NULL) && (p->prox != NULL)) {
				if (stricmp(p->palavra,novo->palavra) == -1) 
				{
					palindromo(novo->palavra);
					
					novo->prox = p->prox;
					p->prox = novo;
					p = NULL;
				}
				else
					p = p->prox;
			}
			if (p != NULL) {
				palindromo(novo->palavra);
				
				novo->prox = NULL;
				p->prox = novo;
			}
		}
	}
}

// ler dados
void receberChave(struct Registro *p)
{
	printf("Informe a palavra: \n");
	fflush(stdin);
	fgets(p->palavra,30,stdin);
	fflush(stdin);
	if(p->palavra[strlen(p->palavra)-1]=='\n'){
		p->palavra[strlen(p->palavra)-1]='\0';
	}
}

// verifica se a palavra é um palídromo
void palindromo(const char *s)
{
	const char *p;
	
	for (p = s; *p; p++);
	
	for (--p; s < p; s++, p--) 
		if (*p != *s) break;
		
	if(s < p)
		printf("Nao e palindromo.\n");
	else 
		printf("E palindromo.\n");
	
}

// listar dados da lista
void listar( struct Registro * p ) 
{
	if(p == NULL)
	{
		printf("Nao existe dados cadastrados.\n");
	}else{
		printf("----------------------------------\n");
	    printf("| %-30.30s |\n","PALAVRA");
	    printf("----------------------------------\n");
	    while (p != NULL) {
	    	printf("| %-30.30s |\n", p->palavra);
	    	p = p->prox;
	    }
	    printf("----------------------------------\n");
	}
}


