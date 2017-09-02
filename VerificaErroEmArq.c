// Aluno : Cleide Reis

/*
 Sintese
   Objetivo: receber dados de um arquivo de entrada
 
   Entrada : caso não ocorra erro: endereco ou parte dele e opcao de continuar

   Saida   : arquivo de erros ou arquivo(s) de saida contendo os dados dos endereços de imoveis pesquisados, 
             a data e a hora do processamento

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#define NOME_ARQUIVO_MAX_TAM   (128)
#define ENDERECO_MAX_TAM       (256)
#define LINHA_MAX_TAM          (1024)
#define DATA_HORA_MAX_TAM      (32)
#define PALAVRA_CHAVE_MAX_TAM  (64)
#define ARQUIVO_ENTRADA        "imoveis.txt"
#define ARQUIVO_ERROS          "erros.txt"



typedef struct imovel_s
{
	int cod;
	char endereco[ ENDERECO_MAX_TAM + 1 ];
} imovel_t;


/* ************************************************************************* */
/* *                             Prototipos                                * */
/* ************************************************************************* */

int leDados( imovel_t ** imov, int * count );
int gravaDados( const char * palavra_chave, imovel_t * imov, int count );
const char * obter_data_hora_local( void );
const char * stristr( const char * palheiro, const char * agulha );
int verificar_cod_imovel_repetido( imovel_t * imov, int qtd, int cod );
void ordenar_imoveis( imovel_t * imov, int qtde );
const char * obter_nome_arquivo_saida( const char * str );
void validaNomeArq(char *titulo, int tamMin, char *texto);
char leValidaChar( char * titulo, char * msgErro, char *opcoes );


int main( int argc, char * argv[] )
{
	// Declaracoes
	imovel_t * imovel = NULL;
	int qtd = 0;
	int ret = 0;
	char opcao, palavra_chave[PALAVRA_CHAVE_MAX_TAM+1] = {0};
	// Instrucoes
	setlocale(LC_ALL,"Portuguese");
	
	ret = leDados( &imovel, &qtd );

	if( ret != 0 )
	{
		printf("Erro: Arquivo de Entrada Inconsistente. (Detalhes em: '%s')\n", ARQUIVO_ERROS );
		return 1;
	}
	
	
	do{
		validaNomeArq("Entre com o endereco ou parte dele para pesquisa \n-> ", 2, palavra_chave);
		
		ret = gravaDados( palavra_chave, imovel, qtd );

		if( ret != 0 )
		{
			printf("Erro: Falha ao gravar dados dos imoveis no arquivo de saida\n" );
			break;
		}
		opcao = leValidaChar( "Deseja continuar? (S/N)\n","Opcao invalida!\n","SN" );	
	}while(opcao == 'S');

	free( imovel );

	return 0;
}

/*Objetivo: ler e validar string
 Parametros: end. titulo, tamanho minimo, end. texto
 Retorna: nenhum*/
void validaNomeArq(char *titulo, int tamMin, char *texto)
{
	FILE *arqSaida = NULL;
	int aux, contaEspaco, teste;
	do{
		contaEspaco=0;
		teste=0;
		printf(titulo);
		fflush(stdin);
		fgets(texto,PALAVRA_CHAVE_MAX_TAM,stdin);
		fflush(stdin);
		system("cls");
		if(texto[strlen(texto)-1]=='\n')
			texto[strlen(texto)-1]='\0';
		for(aux=0;aux<strlen(texto);aux++){
			if(texto[aux]==' '){
				contaEspaco++;
			}
		}			
		if(contaEspaco==strlen(texto)){
			printf("Não é permitido um texto todo em branco.\n");
			teste=1;
		}else if(strlen(texto)<tamMin){
			printf("Endereço inválido!\n");
		}
		arqSaida = fopen( obter_nome_arquivo_saida( texto ), "r" );				
		if(arqSaida!=NULL){
			printf("O arquivo já existe!\n");
			fclose(arqSaida);
		}
	}while(strlen(texto)<tamMin || teste==1 || arqSaida!=NULL);
	
}

/*Objetivo: obter o nome do arquivo
 Parametros: end. nome
 Retorna: nome */
const char * obter_nome_arquivo_saida( const char * str )
{
	static char nome[ NOME_ARQUIVO_MAX_TAM + 1 ] = {0};
	const char * palavra = str;
	int cont = 0;
	
	while( *palavra )
	{
		if( isalnum(*palavra) )
			nome[cont++] = tolower(*palavra);
		
		palavra++;
	}
	
	nome[cont] = 0;
	
	strcat( nome, ".txt" );
	
	return nome;
}

/*Objetivo: ler e validar char
 Parametros: end. titulo, end. msg de erro, end. opcoes
 Retorno: caracter */
char leValidaChar( char * titulo, char * msgErro, char * opcoes )
{
	char opcao;
	do{
		printf(titulo);
		fflush(stdin);
		opcao=toupper(getch());
		fflush(stdin);
		system("cls");
		if(strchr(opcoes,opcao)==NULL){
			printf(msgErro);
		}
	}while(strchr(opcoes,opcao)==NULL);
	return opcao;
}
/*Objetivo: ordenar dados
 Parametros: end. imov, quantidade
 Retorna: nenhum */
void ordenar_imoveis( imovel_t * imov, int qtde )
{
	int cont = 0;
	int aux = 0;
	imovel_t tmp;

	for( cont = 0; cont < qtde - 1; cont++ )
	{
		for( aux = cont + 1; aux < qtde; aux++ )
		{
			if( imov[cont].cod > imov[aux].cod )
			{
				memcpy( &tmp, &imov[cont], sizeof(imovel_t) );
				memcpy( &imov[cont], &imov[aux], sizeof(imovel_t) );
				memcpy( &imov[aux], &tmp, sizeof(imovel_t) );
			}
		}
	}
}

/*Objetivo: verificar código repetido
 Parametros: end. imov, quantidade e codigo
 Retorna: 0 ou 1*/
int verificar_cod_imovel_repetido( imovel_t * imov, int qtd, int cod )
{
	int cont = 0, flag = 0;

	for( cont = 0; cont < qtd; cont++ )
		if( imov[cont].cod == cod )
			flag = 1;

	return flag;
}

/*Objetivo: ignorar caracteres maiusculos e minusculos
 Parametros: end. verificador, end. palavra buscada
 Retorna: NULL */
const char * stristr( const char * palheiro, const char * agulha )
{
	do {
		const char * verificador = palheiro;
		const char * nomeBusca = agulha;

		while( (tolower(*verificador) == tolower(*nomeBusca)) && (*nomeBusca) )
		{
			nomeBusca++;
			verificador++;
		}

		if( *nomeBusca == 0 )
			return palheiro;

	} while (*palheiro++);

	return NULL;
}

/*Objetivo: obter data e hora do sistema
 Parametros: nenhum
 Retorna: data e hora*/
const char * obter_data_hora_local( void )
{
	time_t agora = time(NULL);
	struct tm * ptm = localtime( &agora );
	static char datahora[ DATA_HORA_MAX_TAM + 1 ] = {0};
	
	strftime( datahora, DATA_HORA_MAX_TAM, "%d/%m/%Y - %H:%M:%S", ptm );
	
	return datahora;
}

/*Objetivo: gravar dados em arquivo de saida
 Parametros: end. palavra buscada, end. imov, quantidade
 Retorna: 0 se obteve sucesso e -1 se ocorreu erro */
int gravaDados( const char * palavra_chave, imovel_t * imov, int count )
{
	FILE * arqSaida = NULL;
	int cont = 0, flag = 0;
	char opcao;
	
	ordenar_imoveis( imov, count );	

	
	for( cont = 0; cont < count; cont++ )
	{
		if( stristr( imov[cont].endereco, palavra_chave ) )
		{
			if(flag==0){
				arqSaida = fopen( obter_nome_arquivo_saida( palavra_chave ), "w" );				
				if(!arqSaida){
					return -1;
				}
					
				flag = 1;
			}			
			fprintf( arqSaida, "(%d)-%s\n", imov[cont].cod, imov[cont].endereco );			
		}
		
	}
	if(flag==1){		
		fprintf( arqSaida, "Processado em: %s\n", obter_data_hora_local() );		
		fclose(arqSaida);
	}
	
	if(flag==0){
		printf("Endereco nao encontrado!\n");
	}	

	return 0;
}

/*Objetivo: ler dados do arquivo
 Parametros: end. imov, quantidade
 Retorna: 0 se obteve sucesso e -1 se ocorreu erro */
int leDados( imovel_t ** imov, int * count )
{
	FILE * arqEntrada = NULL;
	FILE * arqErro = NULL;
	int cont = 0;
	imovel_t * p = NULL;
	int ret = 0;
	int nlinha = 0;
	int erros = 0;
	
	arqEntrada = fopen( ARQUIVO_ENTRADA, "r" );

	if(!arqEntrada)
		return -1;
	
	arqErro = fopen( ARQUIVO_ERROS, "w" );

	if(!arqErro)
	{
		fclose(arqEntrada);
		return -1;
	}
	
	while(1)
	{
		int cod = 0;
		char endereco[ ENDERECO_MAX_TAM + 1 ] = {0};
		char linha[ LINHA_MAX_TAM + 1 ] = {0};

		if( !fgets( linha, LINHA_MAX_TAM, arqEntrada ) )
			break;
		
		linha[ strcspn(linha, "\n") ] = 0;

		nlinha++;

		ret = sscanf( linha, "%d %[^\n]", &cod, endereco );

		if( ret != 2 )
		{
			fprintf( arqErro, "Linha %d - ERRO - Codigo e/ou endereco invalido(S): %s\n", nlinha, linha );
			erros++;
			continue;
		}
		
		if( verificar_cod_imovel_repetido( p, cont, cod ) )
		{
			fprintf( arqErro, "Linha %d - ERRO - Codigo repetido: %s\n", nlinha, linha );
			erros++;
			continue;
		}			
		p = realloc( p, sizeof(imovel_t) * (cont + 1) );
		p[cont].cod = cod;
		strcpy( p[cont].endereco, endereco );
		cont++;
	}
	
	if( erros > 0 )
	{
		fprintf( arqErro, "Processado em: %s\n", obter_data_hora_local() );		
		fclose(arqEntrada);
		fclose(arqErro);		
		free(p);		
		return -1;
	}
	
	*imov = p;
	*count = cont;

	fclose(arqEntrada);
	fclose(arqErro);
	
	return 0; 
}




