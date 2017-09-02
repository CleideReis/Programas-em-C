// Aluno : Cleide Reis

/*
 Sintese
   Objetivo: Tabela hash. Espalhar 34 nomes com espalhamento de 70 
             posi��es causando no m�ximo 10% de colis�o  

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHOTABELA 70

struct tTabelaDispersao {
	char nome[60];
	int ocupado;
};

int hash(char[]);

int main(void) {
	FILE *arq = NULL;
	char linha[60];
	struct tTabelaDispersao tabelaDispersao[TAMANHOTABELA];
	struct tTabelaDispersao tabelaColisao[TAMANHOTABELA];
	// posicao � um contador
	int posicaoColisao=0, posicao, alunos=0;
	
	arq = fopen("lista.txt", "r");
	if (arq == NULL) {
		printf("Erro de abertura do arquivo!");
		return 1;
	}
	// esta inicializando todas as posi�oes com zero 
	for	 (posicao=0; posicao<TAMANHOTABELA; posicao++)
		tabelaDispersao[posicao].ocupado = 0;
	// esta lendo o arquivo
	while (fgets(linha, 60, arq)) {
		// retirando o \n
		linha[strlen(linha)-1] = '\0';
		// alunos � um contador
		//alunos++;
		// posicao que foi inicializado com zero, recebe a fun��o hash
		posicao = hash(linha);
		
		if (!tabelaDispersao[posicao].ocupado) {
			strcpy(tabelaDispersao[posicao].nome, linha);
			tabelaDispersao[posicao].ocupado = 1;
		}
		else 
			strcpy(tabelaColisao[posicaoColisao++].nome, linha);
	}
	// Apresentacao
	printf("Tabela de Dispersao:\n");
	
	for	 (posicao=0; posicao<TAMANHOTABELA; posicao++)
		if (tabelaDispersao[posicao].ocupado)
			printf("--> %2d - %s\n", posicao, tabelaDispersao[posicao].nome);
			
	printf("\nTabela de Colisao:\n");
	
	for	 (posicao=0; posicao<posicaoColisao; posicao++)
		printf("--> %2d - %s\n", hash(tabelaColisao[posicao].nome), tabelaColisao[posicao].nome);
	// fim da apresentacao	

	
	fclose(arq);
	return 0;
}
// a fun��o hash determina a posicao que o nome vai entrar
int hash(char nome[]) {
	int retorno=0, i;
	for	 (i=0; i<strlen(nome); i++) {
		retorno += nome[i];
	}
	return retorno % TAMANHOTABELA;
}


