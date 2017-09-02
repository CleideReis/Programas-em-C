// Aluno : Cleide Reis

/*
 Sintese
   Objetivo: fazer copia de um arquivo texto para outro
 
   Entrada : nome do arquivo

   Saida   : arquivo copiado
   

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void leString(char *titulo,char *texto, int max);
void leValidaString(char *titulo,char *msgErro, char *texto, int tamanhoMax, int tamanhoMin);
void copiaArquivo(FILE *arquivo1, FILE *arquivo2);

int main(void)
{
// Declaracoes
	FILE *arquivo1;
	FILE *arquivo2;
	char nomeArq[20];
// Instrucoes
	setlocale(LC_ALL,"Portuguese");
		
	arquivo1=fopen("arquivo1.txt","w");
	fprintf(arquivo1,"Bom dia!");
	arquivo1=fopen("arquivo.txt","r");
	if(arquivo1==NULL){
		printf("Não foi possível abrir o arquivo.\n");
		return 1;
	}
	leValidaString("Informe o nome do arquivo: \n","Nome inválido.\n",nomeArq,20,2);
	sprintf(nomeArq,"%s.txt",nomeArq);
	arquivo2=fopen(nomeArq,"w");
	
	copiaArquivo(arquivo1,arquivo2);
	
	fclose(arquivo1);
	fclose(arquivo2);

  getch();
  return 0;
}
/*Objetivo: le uma string
 Parametro: end. ti/tulo, end. texto, tamanho maximo 
 Retorno: nenhum */
void leString(char *titulo,char *texto, int max)
{
	printf(titulo);
	fflush(stdin);
	fgets(texto,max,stdin);
	fflush(stdin);
	if(texto[strlen(texto)-1]=='\n'){
		texto[strlen(texto)-1]='\0';
	}	
}
/*Objetivo: ler e validar nome do aluno
 Parametros: end. titulo, end. msg de erro, end. nome, tamanho minimo, tamanho maximo 
 Retorna: nenhum */
void leValidaString(char *titulo,char *msgErro, char *texto, int tamanhoMax, int tamanhoMin)
{
	int cont, test, contadorDeEspaco;
	do{
		test=0;
		contadorDeEspaco=0;
		leString(titulo, texto, tamanhoMax);
		system("cls");
		for(cont=0;cont<strlen(texto);cont++){ 
			if(texto[cont]==' '){
				contadorDeEspaco++;
			}
		}
		if(contadorDeEspaco==strlen(texto)){
			printf("Não é possivel informar um texto todo em branco\n");
			test=1;
		}else{
			if(strlen(texto)<tamanhoMin)
				printf(msgErro);
		}
	}while(strlen(texto)<tamanhoMin || test==1);
	for(cont=0;cont<strlen(texto);cont++){
		texto[cont]=tolower(texto[cont]);
	}
}
/*Objetivo: copiar conteúdo de um arquivo para outro
 Parametros: end. arquivo1 e end. arquivo2
 Retorna: nenhum */
void copiaArquivo(FILE *arquivo1, FILE *arquivo2)
{
	char conteudo[500];
	
	while(!feof(arquivo1)){
		fgets(conteudo,500,arquivo1);
		fputs(conteudo,arquivo2);
	}
	
}












