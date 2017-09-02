// Aluno : Cleide

/*
 Sintese
   Objetivo: ler tres nomes e concatena-los
 
   Entrada : tres nomes

   Saida   : os tres nomes lidos, a qtde de letras 'a' ou 'A', se os tres nomes lidos contem 'se' ou 'Se' ou sE ou SE
             
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 30

//Prototipos
void leValidaString(char titulo[],char mensErro[],int tamanhoMin,int tamanhoMax,char texto[]);

int main(void)
{
// Declaracoes
	char nome1[10], nome2[10], nome3[10], nomeCompleto[TAM_NOME];
	int somaLetraA, cont;
// Instrucoes
	somaLetraA=0;
	leValidaString("Digite o nome 1: \n"," Nome invalido...\n",2,TAM_NOME,nome1);
	leValidaString("Digite o nome 2: \n"," Nome invalido...\n",2,TAM_NOME,nome2);
	leValidaString("Digite o nome 3: \n"," Nome invalido...\n",2,TAM_NOME,nome3);
	strcat(nomeCompleto,nome3);
	strcat(nomeCompleto,", ");
	strcat(nomeCompleto,nome1);
	strcat(nomeCompleto," ");
	strcat(nomeCompleto,nome2);
	for(cont = 0; cont <= strlen(nomeCompleto)-1; cont++){
		if(nomeCompleto[cont] == 'A' || nomeCompleto[cont] == 'a'){
		     somaLetraA = somaLetraA + 1;
		}
	}
	system("cls");
	
	printf("Nome completo = %s\n",nomeCompleto);
	printf("Quantidade de letras 'a' ou 'A' = %d\n",somaLetraA);
	if((stricmp(nome1,"se")==0) || (stricmp(nome2,"se")==0) || (stricmp(nome3,"se")==0)){
		printf("Os tres nomes lidos contem 'se'...\n");
	}else{
		printf("Os tres nomes lidos nao contem 'se'...\n");
	}
	
	getch();
	return 0;
}
// Objetivo: ler e validar uma string
// Parametros: ref. titulo,ref. msg de erro,tamanho minimo,tamanho maximo,ref. texto
// Retorno: nenhum
void leValidaString(char titulo[],char mensErro[],int tamanhoMin,int tamanhoMax,char texto[])
{	
	do{
		printf(titulo);
		fflush(stdin);
		fgets(texto,tamanhoMax,stdin);
		fflush(stdin);
		system("cls");
		if(texto[strlen(texto)-1]=='\n'){
			texto[strlen(texto)-1]='\0';
		}
		if(strlen(texto)<tamanhoMin){
			printf("%s \n",mensErro);
		}
	}while(strlen(texto)<tamanhoMin);
}
