                                                                                                                                                               
/* ************************************************************************** */
/* *                                  Projeto final                         * */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.c>

/* ************************************************************************** */
/* *                            DEFINES/MACROS                              * */
/* ************************************************************************** */

#define ARQUIVO_ALUNOS                 "alunos.txt"
#define ARQUIVO_CURSOS                 "cursos.txt"
#define ARQUIVO_MATRICULAS             "matriculas.txt"

#define SITUACAO_ALUNO_CURSANDO        "CURSANDO"
#define SITUACAO_ALUNO_CONCLUIDO       "CONCLUIDO"
#define SITUACAO_FINANCEIRA_REGULAR    "REGULAR"
#define SITUACAO_FINANCEIRA_PENDENTE   "PENDENTE"
#define SITUACAO_FINANCEIRA_PAGO       "PAGO"
#define SEXO_FEMININO                  "FEMININO"
#define SEXO_MASCULINO                 "MASCULINO"

#define TAM_MIN_IDADE                  (5)
#define TAM_MAX_IDADE                  (200)
#define TAM_MIN_MATRICULA              (1)
#define TAM_MAX_MATRICULA              (99999999)
#define TAM_MIN_NOME_ALUNO             (2)
#define TAM_MAX_NOME_ALUNO             (51)
#define TAM_MIN_VALOR                  (10) 
#define TAM_CPF                        (12)
#define VALIDO                         (1)
#define INVALIDO                       (0)
#define TAM_MAX_SEXO                   (11)
#define TAM_MAX_MENU_ALUNOS            (4)
#define TAM_MAX_MENU_PRINC             (5)
#define TAM_MAX_MENU_CURSOS            (3)
#define TAM_MAX_MENU_RELATORIOS        (7)
#define VALOR_MIN                      (99)
#define TAM_MIN_HORA                   (50)
#define TAM_MIN_CODIGO                 (1000)
#define TAM_MAX_CODIGO                 (999999999)
#define TAM_MAX_NOME_CURSO             (26)
#define TAM_MIN_NOME_CURSO             (2)
#define TAM_MAX_DATA                   (9)
#define TAM_MIN_DATA                   (8)
#define TAM_MIN_CARGA_HORARIA          (10)
#define TAM_MAX_CARGA_HORARIA          (1500)
#define TAM_MIN_MES                    (1)
#define TAM_MAX_MES                    (12)
#define TAM_MIN_ANO                    (1900)
#define TAM_MAX_ANO                    (2050)

/* ************************************************************************** */
/* *                                   STRUCTS                              * */
/* ************************************************************************** */

typedef struct Aluno
{
	int matricula;
	char nome_aluno[TAM_MAX_NOME_ALUNO];
	char cpf[TAM_CPF];
	int idade;
	char sexo;
	char data_ingresso[TAM_MAX_DATA];
}Aluno;

typedef struct Curso
{
	int cod_curso;
	char nome_curso[TAM_MAX_NOME_CURSO];
	int carga_horaria;
	float valor_mensalidade;
}Curso;

typedef struct Matricula
{
	int id_aluno;
	int id_curso;
	char situacao_aluno;
	char situacao_financeira;
	int mes, ano;
}Matricula;

/* ************************************************************************** */
/* *                                   PROTOTIPOS                           * */
/* ************************************************************************** */
 
float le_valida_float( char * titulo, char * msg_erro, float valor_min );
FILE * abre_arquivo( char * nome_arquivo, char * modo_abertura, char * msg_erro );
int le_dados_alunos( int nro_aluno, Aluno * aluno );
void pesquisa_aluno_por_codigo( void );
char * stristr( char * nome, char * nome_busca );
int validar_cpf( char * cpf, char * msg_erro );
char * formata_CPF ( char * cpf );
void obtem_data( char * data );
char * formata_data ( char * data );
void exclui_aluno( void );
void menu_alunos();
void cores_janela1();
void cores_janela2();
void menu_principal();
void menu_cursos();
void menu_matriculas();
void relatorios( void );
void HoraData();
void funcao_exit();
void cadastra_curso( void );
void altera_curso( void );
void lista_cursos( void );
void cadastra_matricula( void );
void altera_matricula( void );
void exclui_matricula( void );
void consulta_simples ( void );
void pesquisa_aluno_por_curso ( void );
void pesquisa_curso_por_nome ( void ); 
void pesquisa_aluno_por_data ( void );
void pesquisa_aluno_por_situacao_finac ( void ); 
void pesquisa_aluno_curso_anoMat_situac ( void );
void cadastra_aluno( void );
void lista_alunos( void );
void obtem_data( char * data );
char * formata_data ( char * data );
void le_valida_string( char * titulo, char * msg_erro, int tam_max, int tam_min, char * texto );
void le_string( char * titulo, char * texto, int tam_max );
int obtem_codigo_curso( int cod );
int obtem_codigo_matricula( int cod );
int obtem_codigo_aluno( int cod );
void altera_aluno( void );
void apresenta_aluno_por_nome( void );
int le_valida_int( char * titulo, char * msg_erro, int valor_min, int valor_max );
int le_int( char * titulo, char * msg_erro );
void exclui_registro_arq(char * nomeArq, int tam_registro, int reg_excluir, int * existe_erro);
void pesquisa_aluno_por_data( void );
void apresenta_curso_por_nome( void );
void pesquisa_curso_por_codigo( void );
void pesquisa_matricula_por_codigo( void );
int le_dados_cursos( int nro_curso, Curso * curso );
int le_dados_matriculas( int nro_matricula, Matricula * matricula );
void lista_matriculas( void );
char le_valida_char( char *titulo, char * msg_erro, char * opcoes );
int inverte_data( char * data );
int verifica_situacao( int codigo );
int obtem_ultimo_codigo_lido( void );
Curso * obtem_dados_arq_curso( int *qtde );
int obtem_qtde_arq( int tam_registro, char * nome_arq );
void ordena_cursos( int qtde, Curso *cursos );
int compara_nome_cursos( const void * p1, const void * p2 );
Aluno * obtem_dados_arq_aluno( int *qtde );
void ordena_alunos(int qtde, Aluno *alunos);
int compara_nome_alunos( const void * p1, const void * p2 );
Matricula * obtem_dados_ano_mat( int * qtde, int ano_pesq );
Aluno * obter_aluno_sit_concluido( int * qtdeAlunos );
Matricula * obtem_dados_arq_matricula( int * qtde );
char * formata_situacao ( char situacao );

/* ************************************************************************** */
/* *                                   MAIN                                 * */
/* ************************************************************************** */

int main( void )
{
 
	 menu_principal();
     
     getch();
     return 0;
}

/* Objetivo  : cadastrar dados de um aluno
   Parametros: nenhum
   Rteorna   : nenhum */
void cadastra_aluno( void )
{
	Aluno aluno;
	FILE * arq;
	int verifica = VALIDO;
	
	textcolor(LIGHTGREEN);
	aluno.matricula = le_valida_int(" Matricula: "," Matricula invalida!",TAM_MIN_MATRICULA,TAM_MAX_MATRICULA);
	if( obtem_codigo_aluno(aluno.matricula) !=0 )
    {
	    printf(" Matricula repetida!\n") ;
	    getche();
	    system("cls");
	    menu_alunos();
	}
	
	le_valida_string( " Nome: "," Nome Invalido!",TAM_MAX_NOME_ALUNO,TAM_MIN_NOME_ALUNO, aluno.nome_aluno );
	do{
		le_string( " CPF: ",aluno.cpf,TAM_CPF );
		verifica = validar_cpf(aluno.cpf," CPF invalido!");
	}while( verifica == INVALIDO );

	aluno.idade = le_valida_int( " Idade: ", " Idade invalida!", TAM_MIN_IDADE, TAM_MAX_IDADE );
	aluno.sexo = le_valida_char( " Sexo: ", " Sexo invalido!","MF" );	
	obtem_data(aluno.data_ingresso);
	
	if((arq = abre_arquivo(ARQUIVO_ALUNOS,"ab", " Erro ao abir o arquivo!")) != NULL){
		if(fwrite(&aluno,sizeof(Aluno),1,arq)==1){
			printf(" Dados gravados com sucesso!\n");
		}
		else
		{
			printf(" Erro ao gravar os dados!\n");
		}
		fclose(arq);	
	}
	getch();
	system("cls");
	menu_alunos();
}

/* Objetivo  : alterar dados de um aluno
   Parametros: nenhum 
   Retorna   : nenhum */
void alterar_aluno( void )
{
    FILE * arq;
	Aluno aluno;
	int ret, verifica, altera_id;
	char opcao;
	
  	apresenta_aluno_por_nome(); 
	getch();  
	textcolor(LIGHTGREEN);
	altera_id = le_valida_int( " Informe a matricula para alteracao: \n", " Matricula invalida!\n", TAM_MIN_MATRICULA, TAM_MAX_MATRICULA );
	ret = obtem_codigo_aluno( altera_id );
	
	opcao = le_valida_char(" Qual dado deseja alterar? \n (N)-Nome/(C)-CPF/(I)-Idade/(S)-Sexo\n"," Opcao invalida!\n","NCIS");
	if(ret != 0)
	{
		arq = abre_arquivo(ARQUIVO_ALUNOS,"r+b"," Erro ao abrir arquivo!\n");
		if(arq != NULL)
		{
	        
			if(fseek(arq,(ret-1)*sizeof(Aluno),SEEK_SET) == 0)
			{        
				if(fread(&aluno,sizeof(Aluno),1,arq)==1)
				{   
					switch(opcao)
					{
						case 'N':
							le_valida_string( " Informe o nome: \n"," Nome Invalido!\n",TAM_MAX_NOME_ALUNO,TAM_MIN_NOME_ALUNO, aluno.nome_aluno );
							break;
						case 'C':
							do{
								le_string( " Informe o CPF: \n",aluno.cpf,TAM_CPF );
								verifica = validar_cpf(aluno.cpf,"CPF invalido!\n");
							}while(verifica == INVALIDO);
							break;
						case 'I':
							aluno.idade = le_valida_int( " Informe a idade: \n", " Idade invalida!\n", TAM_MIN_IDADE, TAM_MAX_IDADE );
							break;
						default:
							aluno.sexo = le_valida_char( " Informe o sexo: \n", " Sexo invalido!\n","FM" );
							break;
					}                                            
						
					if(fseek(arq,(ret-1)*sizeof(Aluno),SEEK_SET) == 0)
					{        
						if(fwrite(&aluno,sizeof(aluno),1,arq) == 1)
						{
							                                                       
							printf(" Alteracao realizada com sucesso\n");
							getch();
						}
						else
							printf(" Erro ao gravar dados!\n");
						}
					else
						printf(" Erro ao posicionar arquivo!\n");
	                    
					}   
				}
			}
		if(fclose(arq) != 0)
			printf(" Erro ao fechar arquivo!\n");
	}
	else
	{	     
		printf(" Aluno nao cadastrado!\n");
	}
	getch();
	system("cls");
	menu_alunos();
}
/* Objetivo  : excluir os dados de um aluno do arquivo
   Parametros: nenhum 
   Retorna   : nenhum */
void exclui_aluno( void )
{
    FILE * arq = NULL;
	Aluno aluno;
	int ret, ret2, cont=0, existeErro, cod_exclui;
	char resposta;
	char * cpf_formatado;
	char * data;
	char * sexo_por_extenso;
	
	apresenta_aluno_por_nome(); 
	getch();
	textcolor(LIGHTGREEN);
	cod_exclui = le_valida_int(" Informe a matricula do aluno para excluir registro: \n", " Matricula invalida!\n", TAM_MIN_MATRICULA,TAM_MAX_MATRICULA );
	ret = obtem_codigo_aluno( cod_exclui );
	
	ret2 = obtem_codigo_matricula( cod_exclui );		
			
	if(ret != 0)
	{
		if(ret2 == 0)
		{	
			arq = abre_arquivo(ARQUIVO_ALUNOS,"rb"," Erro ao abrir arquivo!\n");
			if(arq != NULL)
			{
				resposta = 'N';     
		        
				if(fseek(arq,(ret-1)*sizeof(Aluno),SEEK_SET) == 0)
				{        
					if(fread(&aluno,sizeof(Aluno),1,arq)==1)
					{    
						cpf_formatado = formata_CPF(aluno.cpf);
						data = formata_data(aluno.data_ingresso);
						sexo_por_extenso = aluno.sexo == 'F' ? SEXO_FEMININO : SEXO_MASCULINO;
						printf(" %6d - %-20.20s - %-14.14s - %3d - %-10.10s - %10.10s\n",aluno.matricula,aluno.nome_aluno,
						cpf_formatado,aluno.idade,sexo_por_extenso,data);                                         
						resposta = le_valida_char(" Tem certeza que deseja excluir registro? (S/N)","Opcao invalida!\n","SN");
					}
				}
				if(fclose(arq) != 0)
					printf(" Erro ao fechar arquivo!\n");
				if(resposta == 'S')
				{
					exclui_registro_arq(ARQUIVO_ALUNOS, sizeof(aluno),ret,&existeErro);
					if(!existeErro)
					{
						printf(" Exclusao realizada com sucesso!\n");    
					}    
					else
					{
						printf(" Erro ao exclui registro!\n");
					}            
				} 
			} 
		}
		else
		{
			printf(" Nao e permitido excluir alunos matriculados!\n");
		}
	}             
	else
	{ 
		printf(" Aluno nao cadastrado!\n");
	}  
	
	getch();
	system("cls");
	menu_alunos();
}

/* Objetivo  : listar dados dos alunos
   Parametros: nenhum 
   Retorna   : nenhum */
void lista_alunos( void )
{
	Aluno * alunos;
	int qtdeAlunos, i;
	char * cpf_formatado = NULL;
	char * data = NULL;
	char * sexo_por_extenso = NULL;
	
	textcolor(LIGHTGREEN);
   	if((alunos = obtem_dados_arq_aluno(&qtdeAlunos)) != NULL)
   	{  
    	for (i=0;i<qtdeAlunos;i++)
        {
        	                                   
        	if( i == 0 ){
				printf("------------------------------------------------------------------------\n");
				printf( "|%6.6s|%-20.20s|%-14.14s|%-5.5s|%-10.10s|%-10.10s|\n","CODIGO","ALUNO","CPF","IDADE","SEXO","DATA");	
				printf("------------------------------------------------------------------------\n");
			}
			cpf_formatado = formata_CPF(alunos[i].cpf);
			data = formata_data(alunos[i].data_ingresso);
			sexo_por_extenso = alunos[i].sexo == 'F' ? SEXO_FEMININO : SEXO_MASCULINO;
			printf("|%6d|%-20.20s|%-14.14s|%5d|%-10.10s|%10.10s|\n",alunos[i].matricula,alunos[i].nome_aluno,
			cpf_formatado,alunos[i].idade,sexo_por_extenso,data);       
        }
        if(i != 0)
        	printf("------------------------------------------------------------------------\n");
		
		free(alunos); 
    } 
	else
	{
		printf(" Nao existe alunos cadastrados!\n");	
	}   
    getch();
	system("cls");
	relatorios();
}
/* ************************************************************************** */
/* *                               FUNCOES GERAIS                           * */
/* ************************************************************************** */

/* Objetivo  : ler uma string
   Parametros: end. titulo, end. string, tamanho maximo
   Retorna   : nenhum */
void le_string( char * titulo, char * texto, int tam_max )
{
	printf(titulo);
	fflush(stdin);
	fgets(texto,tam_max,stdin);
	fflush(stdin);
	system("cls");
	texto[strcspn(texto,"\n")] = 0;
}

/* Objetivo  : ler e validar uma string 
   Parametros: end. titulo, end. msg de erro, tamanho maximo, tamanho maximo e end. string
   Retorna   : nenhum */
void le_valida_string( char * titulo, char * msg_erro, int tam_max, int tam_min, char * texto )
{
	int test, cont, conta_espaco;
	
	do{
		test = 0;
		conta_espaco = 0;
		le_string(titulo,texto,tam_max);
		for(cont=0; cont<strlen(texto); cont++) 
			if(isspace(texto[cont]) != 0)
				conta_espaco++;											
		if( strlen(texto) < tam_min || strlen(texto) == conta_espaco ){
			printf(msg_erro);
			test = 1;
		}			
	}while( strlen(texto) < tam_min || test == 1 );
}
/* Objetivo  : ler numero inteiro
   Parametros: end. titulo e end. msg de erro
   Retorna   : numero */
int le_int( char * titulo, char * msg_erro )
{
	int numero, ret;
	
	do{
		printf(titulo);
		fflush(stdin);
		ret = scanf("%d",&numero);
		fflush(stdin);
		system("cls");
		if( ret == 0 )
			printf("Deve ser informado digitos numericos. \n");
	}while( ret == 0 );	
	return numero;
}

/* Objetivo  : ler e validar um numero inteiro
   Parametros: end. titulo, end. msg de erro, valor minimo e valor maximo
   Retorna   : nenhum */
int le_valida_int( char * titulo, char * msg_erro, int valor_min, int valor_max )
{
	int numero;
	
	do{
		numero = le_int(titulo,msg_erro);
		if( numero < valor_min || numero > valor_max )
			printf(msg_erro);
	}while( numero < valor_min || numero > valor_max );
	return numero;
}

/* Objetivo: Abrir/criar um arquivo
   Parametros: end. com nome do arquivo, end. com o modo de abertura e end. msg de erro
   Retorna : end. para a stream */
FILE * abre_arquivo( char * nome_arquivo, char * modo_abertura, char * msg_erro )
{
	FILE * arq;
	
    if((arq = fopen(nome_arquivo,modo_abertura)) == NULL)
	{
		if(strlen(msg_erro))
		{
		   printf(msg_erro);
		   getch();
	    }
    }
    return arq;
}

/* Objetivo  : procurar a ocorrência de uma string dentro de outra
   Parametros: end. nome e end. nome busca
   Retorna   : ponteiro para a primeira ocorrencia da string ou NULL se nao encontrar */
char * stristr( char * nome, char * nome_busca ){
	char texto1[50], texto2[50], *ret;
	int cont;
	
	strcpy(texto1,nome);
	strcpy(texto2,nome_busca);
	
	for(cont=0;cont<strlen(texto1);cont++){
		texto1[cont]=tolower(texto1[cont]);
	}
	for(cont=0;cont<strlen(texto2);cont++){
		texto2[cont]=tolower(texto2[cont]);
	}
	ret = strstr(texto1,texto2);
	return ret;
}

/* Objetivo  : ler e validar caracter 
   Parametros: end. titulo, end. msg de erro e end. opções
   Retorna   : caracter */
char le_valida_char( char *titulo, char * msg_erro, char * opcoes )
{
	char resposta;
	do{
		printf(titulo);
		fflush(stdin);
		resposta = getch();
		resposta = toupper(resposta);
		fflush(stdin);
		system("cls");
		
		if(strchr(opcoes,resposta)==NULL)
			printf(msg_erro);
		
	}while(strchr(opcoes,resposta)==NULL);
	return resposta;
}

/* Objetivo  : excluir um registro de um arquivo
   Parametros: end. nome arquivo, tamanho de cada registro do arquivo, nro de registro a exluir e end. msg
   Retorna   : msg de erro */ 
void exclui_registro_arq(char * nomeArq, int tam_registro, int reg_excluir, int * existe_erro)
{
	FILE * arq, * arqTemp;
	int cont = 0;
	char * dados;
	*existe_erro = 0;
	
	if((arq = fopen(nomeArq,"rb"))== NULL)
	{
		printf(" Erro ao abrir arquivo  para exclusao!\n");    
		*existe_erro  = 1;
	}
	else
	{       
		if((arqTemp = fopen("arqTemp.txt","wb")) ==NULL)
		{
			fclose(arq);
			printf(" Erro ao criar arquivo para exclusao\n");    
			*existe_erro  = 2; 
		}
		else
		{
			if((dados = (char*)realloc(NULL,sizeof(char)*tam_registro)) == NULL)
			{
				printf(" Erro ao alocar memoria para exclusao!\n");            
				*existe_erro  = 3;
			}
			else
			{
				while(!feof(arq))
				{
					if(fread(dados,tam_registro,1,arq)==1)
					{
						cont++;
						if(cont != reg_excluir)
						{
							if(fwrite(dados,tam_registro,1,arqTemp)!=1)
							{
								printf(" Erro ao gravar dados para copia!\n ");
								*existe_erro = 4;
							}
						} 
					}
					else
					{
						if(!feof(arq))
						{
							printf(" Erro ao ler dados para copia!\n");
							*existe_erro = 5;
						}   
					}  
				}
				free(dados);
			}
			if(fclose(arq) != 0)
			{
				printf(" Erro ao fechar arquivo para exclusao!\n");
				*existe_erro = 6;
			}      
			if(fclose(arqTemp) != 0)
			{
				printf(" Erro ao fechar arquivo temporario exclusao!\n");
				*existe_erro = 7;
			}      
		}
	}
	if(!*existe_erro)
	{
		if(remove(nomeArq) != 0)
		{
			printf(" Erro ao remover aquivo original!\n");
			*existe_erro = 8;
		}   
		else
		{   
			if(rename("arqTemp.txt",nomeArq)!=0)
			{
				printf(" Erro ao renomear arquivo!\n");
				*existe_erro = 9;
			}   
		}  
	}    
} 

/* Objetivo  : validar cpf do aluno
   Parametros: end. cpf e end. msg de erro
   Retorna   : mensagem (valido ou invalido) */
int validar_cpf( char * cpf, char * msg_erro )
{
	int icpf[ TAM_CPF ] = {0};
	int cont = 0;
	int soma = 0;
	int dig1 = 0;
	int res1 = 0;
	int res2 = 0;
	int dig2 = 0;
	int verifica = VALIDO;

	if( strlen( cpf ) != 11 ){
		printf(msg_erro);
		verifica = INVALIDO;
	}
		
	for( soma = 0, cont = 0; cont < 10; cont++ )
		if( cpf[cont] == cpf[cont+1] )
			soma++;

	if( soma == 10 ){
		printf(msg_erro);
		verifica = INVALIDO;
	}

	for( cont = 0; cont < 11; cont++ )
		icpf[cont] = cpf[cont] - 48;

	for( soma = 0, cont = 0; cont < 9; cont++ )
		soma += icpf[cont] * (10 - cont);

	res1 = soma % 11;

	if( res1 < 2 )
		dig1 = 0;
	else
		dig1 = 11 - res1;

	for( soma = 0, cont = 0; cont < 10; cont++ )
		soma += icpf[cont] * ( 11 - cont );

	res2 = soma % 11;

	if( res2 < 2 )
		dig2 = 0;
	else
		dig2 = 11 - res2;

	if( (dig1 != icpf[9]) || (dig2 != icpf[10]) ){
		printf(msg_erro);
		verifica = INVALIDO;
	}
	
	return verifica;
}

/* Objetivo  : obtem codigo de aluno
   Parametros: codigo
   Retorna   : 0 - nao encontrado ou codigo encontrado */
int obtem_codigo_aluno( int cod )
{
	Aluno aluno;
	FILE * arq;
	int cont = 0;
	int nro = 0;
	
	if((arq = abre_arquivo(ARQUIVO_ALUNOS,"rb",""))!=NULL){
		while(!feof(arq)){
			if(fread(&aluno,sizeof(Aluno),1,arq)==1){
				cont++;
				if(cod == aluno.matricula){
                    nro = cont;
					break;
				}
			}
		}
		fclose(arq);
	}
	return nro;
}


/* Objetivo  : formatar cores da janela do menu de aluno, curso, matricula e relatorio
   Parametros: nenhum 
   Retorna   : nenhum */
void cores_janela2()
{
     int lin, col;
     col = 0;
     for ( lin = 2; lin <= 24; lin++ )
         for ( col = 3; col <= 78; col++ ){
              gotoxy(col,lin);
			  textbackground(WHITE);
			  printf(" ");
         }
}

/* Objetivo  : apresentar menu alunos formatado
   Parametros: nenhum 
   Retorna   : nenhum */
void menu_alunos()
{
     
     system("cls");
     
     cores_janela2();
    
     textcolor(BLACK);
	 gotoxy(25,7); 
	 printf("[--------CONTROLE ALUNOS--------]");
     char * menu_list [ TAM_MAX_MENU_ALUNOS ] = { "Cadastrar",
									              "Alterar",
									              "Excluir",
									              "Voltar" };
     int i,
     xpos = 15,
     ypos [ TAM_MAX_MENU_ALUNOS ] = { 13, 15, 17, 19 };
     for ( i = 0; i < TAM_MAX_MENU_ALUNOS; ++i ){
         gotoxy (xpos, ypos [i] );
         textattr(10);
         printf("%s",menu_list [i] );
     }
     i = 0;
     while (1) {
         gotoxy( xpos, ypos [i] );
         textattr(12);
         printf("%s",menu_list [i] );
         
         switch ( _getch () ){
         case 72: 
			  if ( i > 0 ) {
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              --i;
	          }
	          break;
         case 80: 
		      if ( i <  TAM_MAX_MENU_ALUNOS -1 ){
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              ++i;
              }
              break;
         case 13:
              if ( i == 0 ) {  system("cls"); cadastra_aluno (); }
              if ( i == 1 ) {  system("cls"); alterar_aluno (); }
              if ( i == 2 ) {  system("cls"); exclui_aluno (); }
              if ( i == 3 ) {  system("cls"); menu_principal () ;}
              break;
         }
     }
}

/* Objetivo  : finalizar programa
   Parametros: nenhum
   Retorna   : nenhum */
void funcao_exit()
{
     void cores_janela();
     cores_janela2();
     gotoxy(32,11);
     printf("OPERACAO FINALIZADA");
     gotoxy(2,23);
     Sleep(1800);
     gotoxy(36,13);
     printf("VOLTE SEMPRE");
     Sleep(4800);exit(0);
     gotoxy(3,24);
}
/* ******************************************************************************** */
/* *                           MANIPULACAO DE CURSOS                                */
/* ******************************************************************************** */

/* Objetivo  : cadastrar dados de um curso
   Parametros: nenhum
   Rteorna   : nenhum */
void cadastra_curso( void )
{
	Curso curso;
	FILE * arq;
	int cont = 1000;
	
	textcolor(LIGHTGREEN);
	if((cont = obtem_ultimo_codigo_lido()) != 0 )
		curso.cod_curso = cont+1;
	else
		curso.cod_curso = cont;	
	
	le_valida_string( " Nome: \n"," Nome Invalido!\n",TAM_MAX_NOME_CURSO,TAM_MIN_NOME_CURSO, curso.nome_curso );
	curso.carga_horaria = le_valida_int( " Carga horaria: \n", " Carga horaria invalida!\n", TAM_MIN_CARGA_HORARIA, TAM_MAX_CARGA_HORARIA );
	curso.valor_mensalidade = le_valida_float( " Valor da mensalidade: \n", " Valor invalido!\n",VALOR_MIN );
	
	if((arq = abre_arquivo(ARQUIVO_CURSOS,"ab", " Erro ao abir o arquivo!\n")) != NULL)
	{
		if(fwrite(&curso,sizeof(Curso),1,arq)==1)
			printf(" Dados gravados com sucesso!\n");
		else
			printf(" Erro ao gravar os dados!\n");
		fclose(arq);	
	}
	getch();
	system("cls");
	menu_cursos();
}

/* Objetivo  : alterar dados de um curso
   Parametros: nenhum 
   Retorna   : nenhum */
void altera_curso( void )
{
    FILE * arq;
	Curso curso;
	int ret, verifica, altera_id;
	char opcao;
	
  	apresenta_curso_por_nome();
	getch();  
	 
	textcolor(LIGHTGREEN); 
	altera_id = le_valida_int( " Informe o codigo para alteracao: \n", " Codigo invalido!\n", TAM_MIN_CODIGO, TAM_MAX_CODIGO );
	ret = obtem_codigo_curso( altera_id );
	
	opcao = le_valida_char(" Especifique o dado que deseja alterar: \n (N)-Nome/(C)-Carga Horaria/(V)-Valor Mensalidade"," Opcao invalida!\n","NCV");
	if(ret != 0)
	{
		arq = abre_arquivo(ARQUIVO_CURSOS,"r+b"," Erro ao abrir arquivo!\n");
		if(arq != NULL)
		{
	        
			if(fseek(arq,(ret-1)*sizeof(Curso),SEEK_SET) == 0)
			{        
				if(fread(&curso,sizeof(Curso),1,arq)==1)
				{     
					switch(opcao)
					{
						case 'N':
							le_valida_string( " Informe o nome: \n"," Nome Invalido!\n",TAM_MAX_NOME_CURSO,TAM_MIN_NOME_CURSO, curso.nome_curso );
							break;
						case 'C':
							curso.carga_horaria = le_valida_int( " Informe a carga horaria: \n", " Carga horaria invalida!\n", TAM_MIN_CARGA_HORARIA, TAM_MAX_CARGA_HORARIA );
							break;
						default:
							curso.valor_mensalidade = le_valida_float( " Informe o valor da mensalidade: \n", " Valor invalido!\n",VALOR_MIN );
							break;
					}                                          	
					if(fseek(arq,(ret-1)*sizeof(Curso),SEEK_SET) == 0)
					{        
						if(fwrite(&curso,sizeof(Curso),1,arq) == 1)
						{
							                                                       
							printf(" Alteracao realizada com sucesso\n");
							getch();
						}
						else
							printf(" Erro ao gravar dados!\n");
						}
					else
						printf(" Erro ao posicionar arquivo!\n");
	                    
					}   
				}
			}
		if(fclose(arq) != 0)
			printf(" Erro ao fechar arquivo!\n");
	}
	else
	{	     
		printf(" Curso nao cadastrado!\n");
		getch();
	}
	getch();
	system("cls");
	menu_cursos();
}

/* Objetivo  : listar dados dos alunos
   Parametros: nenhum 
   Retorna   : nenhum */
void lista_cursos( void )
{
	FILE * arq;
	Curso * curso = NULL;
	int flag = 0;
	
	textcolor(LIGHTGREEN);
	if((arq = abre_arquivo(ARQUIVO_CURSOS,"rb",""))!=NULL){
		if(( curso = (Curso *) realloc(NULL,sizeof(Curso))) == NULL )
		{
			printf(" Erro ao alocar memoria para listar alunos!\n");            
		}
		else
		{
		while(!feof(arq)){	
			if(fread(curso,sizeof(Curso),1,arq)==1){
				if( flag == 0 ){
					printf("----------------------------------------------------------\n");
					printf( "| %-6.6s | %-20.20s | %-10.10s | %-9.9s |\n","CODIGO","CURSO","C. HORARIA","VALOR(R$)");	
					printf("----------------------------------------------------------\n");
					flag = 1;
				}
				printf("| %6d | %-20.20s | %10d | %9.2f |\n",curso->cod_curso,curso->nome_curso,
				curso->carga_horaria,curso->valor_mensalidade); 
			}
		}
		if(flag==1)
			printf("----------------------------------------------------------\n");
		free(curso);
		}
		if(fclose(arq)!=0)
			printf("Erro ao fechar arquivo cursos.txt!\n");
	}
	getch();
	system("cls");
	relatorios();
}


/* Objetivo  : pesquisar alunos por nome
   Parametros: nenhum
   Retorna   : nenhum */
void apresenta_curso_por_nome( void )
{
	FILE * arq;
	Curso curso;
	int flag = 0;
	char nome_pesq[TAM_MAX_NOME_CURSO];
	
	le_valida_string( " Informe o nome: \n"," Nome Invalido!\n",TAM_MAX_NOME_CURSO,TAM_MIN_NOME_CURSO, nome_pesq );
	
	if((arq = fopen(ARQUIVO_CURSOS,"rb"))!=NULL){
		while(!feof(arq)){
			if(fread(&curso,sizeof(Curso),1,arq)==1){
				if(stristr(curso.nome_curso,nome_pesq) != NULL){
					printf(" %6d - %-20.20s - %10d - %9.2f \n",curso.cod_curso,curso.nome_curso,
					curso.carga_horaria,curso.valor_mensalidade);
					flag = 1;
				}
			}
		}
		fclose(arq);
	}
	if(flag==0){
		printf(" Nao foi encontrado cursos com o nome informado.\n");
	}
	getch();
}


/* Objetivo  : ler e validar um valor
   Parametros: end. titulo, end. msg de erro e valor minimo
   Retorna   : nenhum */
float le_valida_float( char * titulo, char * msg_erro, float valor_min )
{
	float numero, ret;
	
	do{
		do{
			printf(titulo);
			fflush(stdin);
			ret = scanf("%f",&numero);
			fflush(stdin);
			system("cls");
			if( ret == 0 )
				printf("Deve ser informado digitos numericos. \n");
		}while( ret == 0 );
		if( numero < valor_min)
			printf(msg_erro);
	}while( numero < valor_min );
	return numero;
}

/* Objetivo  : obter codigo 
   Parâmetros: codigo 
   Retorno   : 0 - nao existe ou codigo do aluno */
int obtem_codigo_curso( int cod )
{
	FILE * arq;
	int cont = 0;
	Curso curso; 
	int codigo = 0;
	
	if((arq=fopen(ARQUIVO_CURSOS,"rb")) != NULL){
		while(!feof(arq)){
			if(fread(&curso,sizeof(Curso),1,arq)==1){
				cont++;
				if(cod == curso.cod_curso){
                    codigo=cont;
					break;
				}
			}
		}
		if(fclose(arq)!=0)
			printf("Erro ao fechar arquivo alunos.txt!\n");
	}
	return codigo;
}


/* Objetivo  : mostrar menu cursos para selecao
   Parametros: nenhum
   Retorna   : nenhum */
void menu_cursos()
{   
     system("cls");
     
     cores_janela2();
    
     textcolor(BLACK);gotoxy(25,7); 
	 printf("[--------CONTROLE CURSOS--------]");
     char * menu_list [ TAM_MAX_MENU_CURSOS ] = { "Cadastrar",
                                                  "Alterar",
                                                  "Voltar" };
     int i,
     xpos = 15,
     ypos [ TAM_MAX_MENU_CURSOS ] = { 13, 15, 17 }; 
     for ( i = 0; i < TAM_MAX_MENU_CURSOS; ++i ){
         gotoxy (xpos, ypos [i] );
         textattr(10);
         printf("%s",menu_list [i] );
     }
     i = 0;
     while (1) {
         gotoxy( xpos, ypos [i] );
         textattr(12);
         printf("%s",menu_list [i] );
         
         switch ( _getch () ){
         case 72: 
			  if ( i > 0 ) {
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              --i;
	          }
	          break;
         case 80: 
		      if ( i <  TAM_MAX_MENU_CURSOS -1 ){
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              ++i;
              }
              break;
         case 13:
              if ( i == 0 ) {  system("cls"); cadastra_curso (); }
              if ( i == 1 ) {  system("cls"); altera_curso (); }
              if ( i == 2 ) {  system("cls"); menu_principal () ;}
              break;
         }
     }
}

/* ******************************************************************************** */
/* *                           MANIPULACAO DE MATRICULAS                            */
/* ******************************************************************************** */

/* Objetivo  : mostrar menu matriculas para selecao
   Parametros: nenhum
   Retorna   : nenhum */
void menu_matriculas()
{
     
     system("cls");
     
     cores_janela2();
    
     textcolor(BLACK);gotoxy(25,7); 
	 printf("[--------CONTROLE MATRICULAS--------]");
     char * menu_list [ TAM_MAX_MENU_ALUNOS ] = { "Cadastrar",
									              "Alterar",
									              "Excluir",
									              "Voltar" };
     int i,
     xpos = 15,
     ypos [ TAM_MAX_MENU_ALUNOS ] = { 13, 15, 17, 19 }; // lista do menu com o número da linha
     for ( i = 0; i < TAM_MAX_MENU_ALUNOS; ++i ){
         gotoxy (xpos, ypos [i] );
         textattr(10);
         printf("%s",menu_list [i] );
     }
     i = 0;
     while (1) {
         gotoxy( xpos, ypos [i] );
         textattr(12);
         printf("%s",menu_list [i] );
         
         switch ( _getch () ){
         case 72: 
			  if ( i > 0 ) {
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              --i;
	          }
	          break;
         case 80: 
		      if ( i <  TAM_MAX_MENU_ALUNOS -1 ){
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              ++i;
              }
              break;
         case 13:
              if ( i == 0 ) {  system("cls"); cadastra_matricula (); }
              if ( i == 1 ) {  system("cls"); altera_matricula (); }
              if ( i == 2 ) {  system("cls"); exclui_matricula (); }
              if ( i == 3 ) {  system("cls"); menu_principal () ;}
              break;
         }
     }
}
/* Objetivo  : cadastrar matricula de um aluno
   Parametros: nenhum
   Rteorna   : nenhum */
void cadastra_matricula( void )
{
	Matricula matricula;
	FILE * arq;
	int verifica = VALIDO;
	int ret = 0;
	
	textcolor(LIGHTGREEN);
	do{
		matricula.id_aluno = le_valida_int(" Matricula do aluno: \n"," Matricula invalida!\n",TAM_MIN_MATRICULA, TAM_MAX_MATRICULA);
		verifica = obtem_codigo_aluno(matricula.id_aluno);	
		if(verifica == INVALIDO)
			printf(" Matricula nao existe!\n");
	}while(verifica == INVALIDO);
	
	ret = verifica_situacao( matricula.id_aluno );
	if( ret ==0 )
	{
		do{
			matricula.id_curso = le_valida_int(" Codigo do curso: \n"," Codigo invalido!\n",TAM_MIN_CODIGO, TAM_MAX_CODIGO);
			verifica = obtem_codigo_curso(matricula.id_curso);
			if(verifica == INVALIDO)
				printf(" Codigo nao existe!\n");
		}while(verifica == INVALIDO);  
	    
		matricula.situacao_aluno = le_valida_char(" Situacao do aluno no curso: ('C'- Cursando/'T'- Concluido)\n"," Situacao invalida!\n","CT");
		matricula.situacao_financeira = le_valida_char(" Situacao financeira do aluno: ('R'- Regular/'P'- Pendente/'F'- Pago)\n", " Situacao invalida!\n","RPF");
			
		matricula.mes = le_valida_int( " Mes: \n", " Mes invalido!\n", TAM_MIN_MES,TAM_MAX_MES );
		matricula.ano = le_valida_int( " Ano: \n", " Carga horaria invalida!\n", TAM_MIN_ANO,TAM_MAX_ANO );
			
		if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"ab", " Erro ao abir o arquivo!\n")) != NULL){
			if(fwrite(&matricula,sizeof(Matricula),1,arq)==1)
				printf(" Dados gravados com sucesso!\n");
			else
				printf(" Erro ao gravar os dados!\n");
			fclose(arq);	
		}
	}
	else
	{
		printf(" Aluno ja esta cursando!\n");
	}
	getch();
	system("cls");
	menu_matriculas();
}
/* Objetivo  : alterar matricula de um aluno
   Parametros: nenhum 
   Retorna   : nenhum */
void altera_matricula( void )
{
    FILE * arq;
	Matricula matricula;
	int ret, verifica, altera_id;
	char opcao; 
	
	textcolor(LIGHTGREEN);
	altera_id = le_valida_int( " Informe a matricula para alteracao: \n", " Matricula invalida!\n", TAM_MIN_MATRICULA, TAM_MAX_MATRICULA );
	ret = obtem_codigo_matricula( altera_id );
	
	opcao = le_valida_char(" Especifique o dado que deseja alterar: \n (C)-Codigo do Curso/(S)-Situacao aluno/(F)-Situacao financeira/(M)-Mes/(A)-Ano\n"," Opcao invalida!\n","CSFMA");
	if(ret != 0)
	{
		arq = abre_arquivo(ARQUIVO_MATRICULAS,"r+b"," Erro ao abrir arquivo!\n");
		if(arq != NULL)
		{
	        
			if(fseek(arq,(ret-1)*sizeof(Matricula),SEEK_SET) == 0)
			{        
				if(fread(&matricula,sizeof(Matricula),1,arq)==1)
				{   
					switch(opcao)
					{
						case 'C':
							do{
								matricula.id_curso = le_valida_int(" Informe o codigo do curso: \n"," Codigo invalido!\n",TAM_MIN_CODIGO,TAM_MAX_CODIGO);
								verifica = obtem_codigo_curso(matricula.id_curso);
								if(verifica == INVALIDO)
									printf(" Codigo nao existe!\n");
							}while(verifica == INVALIDO); 
							break;
						case 'S':
							matricula.situacao_aluno = le_valida_char(" Informe a situacao do aluno no curso: ('C'- Cursando/'T'- Concluido)\n"," Situacao invalida!\n","CT");
							break;
						case 'F':
							matricula.situacao_financeira = le_valida_char(" Informe a situacao financeira do aluno: ('R'- Regular/'P'- Pendente/'F'- Pago)\n", " Situacao invalida!\n","RPF");
							break;
						case 'M':
							matricula.mes = le_valida_int( " Informe o mes: \n", " Mes invalido!\n", TAM_MIN_MES,TAM_MAX_MES );
							break;
						default:
							matricula.ano = le_valida_int( " Informe o ano: \n", " Carga horaria invalida!\n", TAM_MIN_ANO,TAM_MAX_ANO );
							break; 
					}
					             	
					if(fseek(arq,(ret-1)*sizeof(Matricula),SEEK_SET) == 0)
					{        
						if(fwrite(&matricula,sizeof(Matricula),1,arq) == 1)
						{
							                                                       
							printf(" Alteracao realizada com sucesso\n");
						}
						else
							printf(" Erro ao gravar dados!\n");
						}
					else
						printf(" Erro ao posicionar arquivo!\n");
	                    
					}   
				}
			}
		if(fclose(arq) != 0)
			printf(" Erro ao fechar arquivo!\n");
	}
	else
	{	     
		printf(" Matricula nao cadastrada!\n");
	}
	getch();
	system("cls");
	menu_matriculas();
}
/* Objetivo  : excluir os dados de um aluno do arquivo
   Parametros: nenhum 
   Retorna   : nenhum */
void exclui_matricula( void )
{
    FILE * arq = NULL;
	Matricula matricula;
	int ret, cont=0, existeErro, exclui;
	char resposta;
	char sit_aluno[10], sit_financeira[10];
	 
	textcolor(LIGHTGREEN);  
	exclui = le_valida_int(" Informe a matricula do aluno para excluir registro: \n", " Matricula invalida!\n", TAM_MIN_MATRICULA,TAM_MAX_MATRICULA );
	ret = obtem_codigo_matricula( exclui );
	
	if(ret != 0)
	{
		arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb"," Erro ao abrir arquivo!\n");
		if(arq != NULL)
		{
			resposta = 'N';     
	        
			if(fseek(arq,(ret-1)*sizeof(Matricula),SEEK_SET) == 0)
			{        
				if(fread(&matricula,sizeof(Matricula),1,arq)==1)
				{        
					if(matricula.situacao_aluno == 'C')
						sprintf(sit_aluno,SITUACAO_ALUNO_CURSANDO);
					else
						sprintf(sit_aluno,SITUACAO_ALUNO_CONCLUIDO);
					
					if(matricula.situacao_financeira == 'R')
						sprintf(sit_financeira,SITUACAO_FINANCEIRA_REGULAR);
					else if(matricula.situacao_financeira == 'P')
						sprintf(sit_financeira,SITUACAO_FINANCEIRA_PENDENTE);
					else
						sprintf(sit_financeira,SITUACAO_FINANCEIRA_PAGO);
					
					printf(" %8d - %8d - %10.10s - %11.11s - %3d - %4d \n",matricula.id_aluno,matricula.id_curso,
					sit_aluno,sit_financeira,matricula.mes,matricula.ano);                                      
					resposta = le_valida_char(" Tem certeza que deseja excluir registro? (S/N)","Opcao invalida!\n","FM");
				}
			}
			if(fclose(arq) != 0)
				printf(" Erro ao fechar arquivo!\n");
			if(resposta == 'S')
			{
				exclui_registro_arq(ARQUIVO_MATRICULAS, sizeof(matricula),ret,&existeErro);
				if(!existeErro)
				{
					printf(" Exclusao realizada com sucesso!\n");    
				}    
				else
				{
					printf(" Erro ao exclui registro!\n");
				}            
			} 
		}     
	}             
	else
	{ 
		printf(" Matricula nao cadastrada!\n");
	}  
	getch();
	system("cls");
	menu_matriculas();
} 

/* Objetivo  : obtem codigo de aluno
   Parametros: codigo
   Retorna   : 0 - nao encontrado ou codigo encontrado */
int obtem_codigo_matricula( int cod )
{
	Matricula matricula;
	FILE * arq;
	int cont = 0;
	int nro = 0;
	
	if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb",""))!=NULL){
		while(!feof(arq)){
			if(fread(&matricula,sizeof(Matricula),1,arq)==1){
				cont++;
				if(cod == matricula.id_aluno){
                    nro = cont;
					break;
				}
			}
		}
		fclose(arq);
	}
	return nro;
}

/* ******************************************************************************** */
/* *                           RELATORIOS                                           */
/* ******************************************************************************** */

/* Objetivo  : mostrar menu de relatorios para selecao
   Parametros: nenhum
   Retorna   : nenhum */
void relatorios( void )
{
     
     system("cls");
     
     cores_janela2();
    
     textcolor(BLACK);gotoxy(25,5); 
	 printf("[----------RELATORIOS----------]");
     char * menu_list [ TAM_MAX_MENU_RELATORIOS ] = { "(R1) Consulta Simples",
										              "(R2) Consulta Alunos por Curso",
										              "(R3) Consultar Curso por Nome" ,
										              "(R4) Consultar Alunos por Periodo de Data",
										              "(R5) Consultar Alunos por Situacao Financeira",
										              "(R6) Consultar Alunos por Curso/AnoMatricula/Situacao",
										              "Voltar" };
     int i,
     xpos = 15,
     ypos [ TAM_MAX_MENU_RELATORIOS ] = { 9, 11, 13, 15, 17, 19, 21 }; 
     for ( i = 0; i < TAM_MAX_MENU_RELATORIOS; ++i ){
         gotoxy (xpos, ypos [i] );
         textattr(10);
         printf("%s",menu_list [i] );
     }
     i = 0;
     while (1) {
         gotoxy( xpos, ypos [i] );
         textattr(12);
         printf("%s",menu_list [i] );
         
         switch ( _getch () ){
         case 72: 
			  if ( i > 0 ) {
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              --i;
	          }
	          break;
         case 80: 
		      if ( i <  TAM_MAX_MENU_RELATORIOS -1 ){
	              gotoxy( xpos, ypos [i] );
	              textattr(10);
	              printf("%s", menu_list [i] );
	              ++i;
              }
              break;
         case 13:
              if ( i == 0 ) {  system("cls"); consulta_simples (); }
              if ( i == 1 ) {  system("cls"); pesquisa_aluno_por_curso (); }
              if ( i == 2 ) {  system("cls"); pesquisa_curso_por_nome (); }
              if ( i == 3 ) {  system("cls"); pesquisa_aluno_por_data () ;}
              if ( i == 4 ) {  system("cls"); pesquisa_aluno_por_situacao_finac (); }
              if ( i == 5 ) {  system("cls"); pesquisa_aluno_curso_anoMat_situac (); }
              if ( i == 6 ) {  system("cls"); menu_principal (); }
              break;
         }
     }
}
/* Objetivo  : mostrar menu de relatorios para selecao
   Parametros: nenhum
   Retorna   : nenhum */
void consulta_simples( void )
{
	int opcao, opcao2, opcao3;
	
	textcolor(LIGHTGREEN);
	opcao = le_valida_int(" Informe a forma de pesquisa: \n ('1'- Consulta arquivo/'2'- Consulta chave unica)\n"," Opcao invalida!\n",1,2);
	system("cls");
	switch (opcao)
	{
		case 1 :
			opcao2 = le_valida_int(" Informe o arquivo que deseja consultar: \n ('1'- Alunos/'2'- Cursos/'3'- Matriculas)\n","Opcao invalida!\n",1,3);
			system("cls");
			if( opcao2 == 1 )
				lista_alunos();
			else if( opcao2 == 2 )
				lista_cursos();
			else
				lista_matriculas();
			break;
		default :
			opcao3 = le_valida_int(" Informe o arquivo que deseja consultar: \n ('1'- Alunos/'2'- Cursos/'3'- Matriculas)\n","Opcao invalida!\n",1,3);
			system("cls");
			if( opcao3 == 1 )
				pesquisa_aluno_por_codigo();
			else if( opcao3 == 2 )
				pesquisa_curso_por_codigo();
			else
				pesquisa_matricula_por_codigo();
			break;	
			break;
	}
	getch();
    system("cls");
	relatorios();
}

/* Objetivo  : listar dados da matricula
   Parametros: nenhum
   Retorna   : nenhum */
void lista_matriculas( void )
{
	FILE * arq;
	Matricula * matriculas = NULL, * matriculasAux = NULL;
	int flag = 0;
	char sit_aluno[10];
	char sit_financeira[10];
	
	textcolor(LIGHTGREEN);
	if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb",""))!=NULL){
		if(( matriculasAux = (Matricula *) realloc(matriculasAux,sizeof(Matricula))) == NULL )
		{
			printf(" Erro ao alocar memoria para listar alunos!\n");            
		}
		else
		{
			matriculas = matriculasAux;
			while(!feof(arq)){	
				if(fread(matriculas,sizeof(Matricula),1,arq)==1){
					if( flag == 0 ){
						printf("---------------------------------------------------------------\n");
						printf( "| %-8.8s | %-8.8s | %-10.10s | %-11.11s | %-3.3s | %-4.4s |\n","ID-ALUNO","ID-CURSO","SIT. ALUNO","SIT. FINANC","MES","ANO");	
						printf("---------------------------------------------------------------\n");
						flag = 1;
					}
					
					if(matriculas->situacao_aluno == 'C')
						sprintf(sit_aluno,SITUACAO_ALUNO_CURSANDO);
					else
						sprintf(sit_aluno,SITUACAO_ALUNO_CONCLUIDO);
					
					if(matriculas->situacao_financeira == 'R')
						sprintf(sit_financeira,SITUACAO_FINANCEIRA_REGULAR);
					else if(matriculas->situacao_financeira == 'P')
						sprintf(sit_financeira,SITUACAO_FINANCEIRA_PENDENTE);
					else
						sprintf(sit_financeira,SITUACAO_FINANCEIRA_PAGO);
					
					printf("| %8d | %8d | %10.10s | %11.11s | %3d | %4d |\n",matriculas->id_aluno,matriculas->id_curso,
					sit_aluno,sit_financeira,matriculas->mes,matriculas->ano); 
				}
			}
			if(flag==1)
				printf("---------------------------------------------------------------\n");
			free(matriculas);
		}
		if(fclose(arq)!=0)
			printf("Erro ao fechar arquivo matricula.txt!\n");
		
	}
	getch();
	system("cls");
	relatorios();
}


/* Objetivo  : apresentar dados de aluno por matricula 
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_aluno_por_codigo( void )
{
	char * cpf_formatado = NULL;
	char * data_formatada = NULL;
	char * sexo_por_extenso = NULL;
	FILE * arq;
	Aluno aluno;
	int pesq_mat;
	int flag = 0;
	int nro;
	textcolor(LIGHTGREEN);
	pesq_mat = le_valida_int(" Informe a matricula a ser pesquisada: "," Matricula Invalida!\n",TAM_MIN_MATRICULA, TAM_MAX_MATRICULA);
	
    if((nro = obtem_codigo_aluno( pesq_mat ))==0)
    {
 		printf(" Matricula nao encontrada!\n");   	
    }
	else
	{ 
         if(le_dados_alunos(nro, &aluno) ==1)
         {
         	 if( flag == 0 )
			{
				printf( " %-20.20s - %-14.14s - %-5.5s - %-10.10s - %-10.10s \n","ALUNO","CPF","IDADE","SEXO","DATA");	
				flag = 1;
			}
			cpf_formatado = formata_CPF(aluno.cpf);
			data_formatada = formata_data(aluno.data_ingresso);
			sexo_por_extenso = aluno.sexo == 'F' ? "FEMININO" : "MASCULINO";
			printf(" %-20.20s - %-14.14s - %5d - %-10.10s - %-10.10s \n",
			aluno.nome_aluno,cpf_formatado,aluno.idade,sexo_por_extenso,data_formatada);         	
         }
         else
         {
         	printf(" Erro ao ler os dados do arquivo!\n");
         }  
    }
	getch();
	system("cls");
	relatorios();
}
/* Objetivo  : apresentar dados do curso por codigo 
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_curso_por_codigo( void )
{
	FILE * arq;
	Curso curso;
	int pesq_cod;
	int flag = 0;
	int nro;
	textcolor(LIGHTGREEN);
	pesq_cod = le_valida_int(" Informe o codigo a ser pesquisado: "," Codigo Invalido!\n",TAM_MIN_CODIGO, TAM_MAX_CODIGO);
	
    if((nro = obtem_codigo_curso( pesq_cod ))==0)
    {
 		printf(" Codigo nao encontrado!\n");   	
    }
	else
	{ 
         if(le_dados_cursos(nro, &curso) ==1)
         {
         	 if( flag == 0 ){
				printf( " %-6.6s - %-20.20s - %-10.10s - %-9.9s \n","CODIGO","CURSO","C. HORARIA","VALOR(R$)");	
				flag = 1;
			 }
			 printf(" %6d - %-20.20s - %10d - %9.2f \n",curso.cod_curso,curso.nome_curso,
			 curso.carga_horaria,curso.valor_mensalidade);         	
         }
         else
         {
         	printf(" Erro ao ler os dados do arquivo!\n");
         }  
    }
	getch();
	system("cls");
	relatorios();
}
/* Objetivo  : apresentar dados de matricula por chave unica 
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_matricula_por_codigo( void )
{
	FILE * arq;
	Matricula matricula;
	int pesq_id;
	int flag = 0;
	int nro;
	char sit_aluno[10];
	char sit_financeira[10];
	
	textcolor(LIGHTGREEN);
	pesq_id = le_valida_int(" Informe o codigo do aluno a ser pesquisado: "," Codigo Invalido!\n",TAM_MIN_MATRICULA, TAM_MAX_MATRICULA);
	
    if((nro = obtem_codigo_matricula( pesq_id ))==0)
    {
 		printf(" Codigo nao encontrado!\n");   	
    }
	else
	{ 
         if(le_dados_matriculas(nro, &matricula) ==1)
         {
         	if( flag == 0 ){
				printf( " %-8.8s - %-8.8s - %-10.10s - %-11.11s - %-3.3s - %-4.4s \n","ID-ALUNO","ID-CURSO","SIT. ALUNO","SIT. FINANC","MES","ANO");	
				flag = 1;
			}
			if(matricula.situacao_aluno == 'C')
				sprintf(sit_aluno,SITUACAO_ALUNO_CURSANDO);
			else
				sprintf(sit_aluno,SITUACAO_ALUNO_CONCLUIDO);
					
			if(matricula.situacao_financeira == 'R')
				sprintf(sit_financeira,SITUACAO_FINANCEIRA_REGULAR);
			else if(matricula.situacao_financeira == 'P')
				sprintf(sit_financeira,SITUACAO_FINANCEIRA_PENDENTE);
			else
				sprintf(sit_financeira,SITUACAO_FINANCEIRA_PAGO);
			printf(" %8d - %8d - %10.10s - %11.11s - %3d - %4d \n",matricula.id_aluno,matricula.id_curso,
			sit_aluno,sit_financeira,matricula.mes,matricula.ano);         	
         }
         else
         {
         	printf(" Erro ao ler os dados do arquivo!\n");
         }  
    }
	getch();
	system("cls");
	relatorios();
}
/* Objetivo  : ler dados do aluno
   Parametros: nro do aluno e end. aluno
   Retorna   : 0 - se nao foi lido e 1 - se obteve sucesso */
int le_dados_alunos( int nro_aluno, Aluno * aluno )
{
	FILE * arq;
	int leitura = 0;

	if((arq = abre_arquivo(ARQUIVO_ALUNOS,"rb","")) != NULL){	
        if(fseek(arq,sizeof(Aluno)*(nro_aluno-1),SEEK_SET) ==0)
        {
        	if(fread(aluno,sizeof(Aluno),1,arq) ==1)
        	{
                leitura = 1;
            }
        }
        fclose(arq);
    }
    return leitura;
} 
/* Objetivo  : ler dados do curso
   Parametros: nro do curso e end. curso
   Retorna   : 0 - se nao foi lido e 1 - se obteve sucesso */
int le_dados_cursos( int nro_curso, Curso * curso )
{
	FILE * arq;
	int leitura = 0;

	if((arq = abre_arquivo(ARQUIVO_CURSOS,"rb","")) != NULL){	
        if(fseek(arq,sizeof(Curso)*(nro_curso-1),SEEK_SET) ==0)
        {
        	if(fread(curso,sizeof(Curso),1,arq) ==1)
        	{
                leitura = 1;
            }
        }
        fclose(arq);
    }
    return leitura;
} 
/* Objetivo  : ler dados da matricula
   Parametros: nro da matricula e end. matricula
   Retorna   : 0 - se nao foi lido e 1 - se obteve sucesso */
int le_dados_matriculas( int nro_matricula, Matricula * matricula )
{
	FILE * arq;
	int leitura = 0;

	if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb","")) != NULL){	
        if(fseek(arq,sizeof(Matricula)*(nro_matricula-1),SEEK_SET) ==0)
        {
        	if(fread(matricula,sizeof(Matricula),1,arq) ==1)
        	{
                leitura = 1;
            }
        }
        fclose(arq);
    }
    return leitura;
} 
/* Objetivo  : pesquisar por periodo de data
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_aluno_por_data( void )
{
	FILE * arq;
	Aluno * alunos = NULL;
	char * data_formatada = NULL;
	char * cpf_formatado = NULL;
	char * sexo_por_extenso = NULL;
	char data1[TAM_MAX_DATA];
	char data2[TAM_MAX_DATA];
	int data_int, flag = 0;
	int data_inicial, qtdeAlunos;
	int data_final, i;

	textcolor(LIGHTGREEN);
	if((alunos = obtem_dados_arq_aluno(&qtdeAlunos)) != NULL)
   	{
    	ordena_alunos(qtdeAlunos,alunos);
    	
		le_valida_string( " Data inicial: "," Data invalida!\n",TAM_MAX_DATA,TAM_MIN_DATA, data1 );
		le_valida_string( " Data final: "," Nome Invalido!",TAM_MAX_DATA,TAM_MIN_DATA, data2 );
		data_inicial = inverte_data( data1 );
		data_final = inverte_data( data2 );
		
		system("cls");
         
        for (i=0;i<qtdeAlunos;i++)
        {	
        	data_int = inverte_data( alunos[i].data_ingresso );
			if( data_int >= data_inicial  && data_int <= data_final){
			
            	if( flag == 0 ){
					printf("------------------------------------------------------------------------\n");
					printf( "|%6.6s|%-20.20s|%-14.14s|%-5.5s|%-10.10s|%-10.10s|\n","CODIGO","ALUNO","CPF","IDADE","SEXO","DATA");	
					printf("------------------------------------------------------------------------\n");
					flag=1;
				}
				cpf_formatado = formata_CPF(alunos[i].cpf);
				data_formatada = formata_data(alunos[i].data_ingresso);
				sexo_por_extenso = alunos[i].sexo == 'F' ? SEXO_FEMININO : SEXO_MASCULINO;
				printf("|%6d|%-20.20s|%-14.14s|%5d|%-10.10s|%10.10s|\n",alunos[i].matricula,alunos[i].nome_aluno,
				cpf_formatado,alunos[i].idade,sexo_por_extenso,data_formatada); 
                   
            }
        }
        if(flag!=0)
        	printf("------------------------------------------------------------------------\n");
		else
			printf(" Nao foram encontrados alunos no periodo informado!\n");
         
		free(alunos); 
    }    	
		
	getch();
	system("cls");
	relatorios();
}

/* Objetivo  : lê os dados dos alunos existentes em arquivo
   Parametros: end. qtde de alunos 
   Retorna   : end. onde localiza-se os dados recuperados
              do arquivo ou NULL no caso de insucesso */
Aluno * obtem_dados_arq_aluno( int *qtde )
{
	FILE * arq;
	Aluno * alunos = NULL, * alunosAux = NULL;
	int i;
	
	(*qtde) = obtem_qtde_arq(sizeof(Aluno),ARQUIVO_ALUNOS );
	
    if((arq = abre_arquivo(ARQUIVO_ALUNOS,"rb"," Erro ao abrir arquivo!\n")) != NULL)
    {
		alunosAux = (Aluno*) realloc(alunosAux,*qtde * sizeof(Aluno));

		if(alunosAux == NULL)
		{
			printf(" Erro ao alocar memoria!\n");
		}                      
		else
		{    
			alunos = alunosAux;     
			if(fread(alunos,sizeof(Aluno),*qtde,arq)!=*qtde)
			{
				printf(" Erro de leitura!\n");
				free(alunos);
			} 
		}           
	
	    if(fclose(arq) != 0)
	       printf(" Erro ao fechar arquivo!\n");            
    }
    
    return alunos;
}


/* Objetivo  : ordena os dados dos dos alunos existentes na memória
   Parâmetros: qtde de alunos, end. com os dados dos alunos
   Retorno   : nenhum */
void ordena_alunos(int qtde, Aluno *alunos)
{    
	qsort(alunos,qtde,sizeof(Aluno),compara_nome_alunos);
}

/* Objetivo  : compara os dados a serem ordenados pela qsort
   parâmetros: end. para os elementos a serem pesquisados na ordenação
   retorno   : =0 se dados iguais
              >0 se dados desordenados
              <0 se dados ordenados */
int compara_nome_alunos( const void * p1, const void * p2 )
{
	Aluno *aluno1,*aluno2;
	aluno1 = (Aluno*)p1;
	aluno2 = (Aluno*)p2;
	return stricmp(aluno1->nome_aluno,aluno2->nome_aluno); 
}
/* Objetivo  : pesquisar alunos por nome
   Parametros: nenhum
   Retorna   : nenhum */
void apresenta_aluno_por_nome( void )
{
	FILE * arq;
	Aluno aluno;
	int flag = 0;
	char * data_formatada = NULL;
	char * cpf_formatado = NULL;
	char * sexo_por_extenso = NULL;
	char nome_pesq[TAM_MAX_NOME_ALUNO];
	
	le_valida_string( " Informe o nome: \n"," Nome Invalido!\n",TAM_MAX_NOME_ALUNO,TAM_MIN_NOME_ALUNO, nome_pesq );
	
	if((arq = fopen(ARQUIVO_ALUNOS,"rb"))!=NULL){
		while(!feof(arq)){
			if(fread(&aluno,sizeof(Aluno),1,arq)==1){
				if(stristr(aluno.nome_aluno,nome_pesq) != NULL){
					flag = 1;
					cpf_formatado = formata_CPF(aluno.cpf);
					data_formatada = formata_data(aluno.data_ingresso);
					sexo_por_extenso = aluno.sexo == 'F' ? SEXO_FEMININO : SEXO_MASCULINO;
					printf("|%6d|%-20.20s|%-14.14s|%-5d|%-10.10s|%10.10s|\n",aluno.matricula,aluno.nome_aluno,
					cpf_formatado,aluno.idade,sexo_por_extenso,data_formatada);
				}
			}
		}
		fclose(arq);
	}
	if(flag==0){
		printf(" Nao foi encontrado alunos com o nome informado.\n");
	}
	getch();
}

/* Objetivo  : relacionar os alunos de um curso especifico 
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_aluno_por_curso( void )
{
	FILE * arq;
	Aluno * alunos = NULL;
	Matricula * matriculas = NULL;
	Curso curso;
	int qtdeMat = 0, qtdeAlunos = 0;
	int ret = 0, i, cod_pesq;
	char opcao;
	char * cpf_formatado;
	char * sit_aluno;
	
	textcolor(LIGHTGREEN);
		
	cod_pesq = le_valida_int(" Informe o codigo do curso a ser pesquisado: \n"," Codigo Invalido!\n",TAM_MIN_CODIGO,9999999);
	
	if((ret = obtem_codigo_curso(cod_pesq)) != 0)
	{
		opcao = le_valida_char(" Especifique: \n (C)-Cursando/(T)-Concluido/(A)-Ambos\n"," Opcao invalida!\n","CTA");
		
		matriculas = obtem_dados_arq_matricula(&qtdeMat);
			
			if((le_dados_cursos( ret, &curso))==1)
			{
			if((alunos = obtem_dados_arq_aluno(&qtdeAlunos)) != 0)
			{ 	
	    		for(i=0;i<qtdeMat;i++)	     
				{                    
		        	if( i == 0 )
						printf( " %6.6s - %-20.20s - %-14.14s - %-10.10s \n","CODIGO","NOME","CPF","SIT. ALUNO");	
					cpf_formatado = formata_CPF(alunos[i].cpf);
					sit_aluno = formata_situacao ( matriculas[i].situacao_aluno );
					switch(opcao)
					{
						case 'C':
							if(matriculas[i].situacao_aluno == 'C' && matriculas[i].id_curso == curso.cod_curso)
							{	 
								printf(" %6d - %-20.20s - %-14.14s - %-10.10s \n",curso.cod_curso,alunos[i].nome_aluno,
								cpf_formatado,sit_aluno);
							}
							break;
						case 'T':
							if(matriculas[i].situacao_aluno == 'T' && matriculas[i].id_curso == curso.cod_curso)
							{ 
								printf(" %6d - %-20.20s - %-14.14s - %-10.10s \n",curso.cod_curso,alunos[i].nome_aluno,
								cpf_formatado,sit_aluno);
							}
							break;
						default:
							if(matriculas[i].situacao_aluno == 'C' && matriculas[i].situacao_aluno && matriculas[i].id_curso == curso.cod_curso)
							{
								printf(" %6d - %-20.20s - %-14.14s - %-10.10s \n",cod_pesq,alunos[i].nome_aluno,
								cpf_formatado,sit_aluno);	
							}
							break;	
					}
							
						       
	        	}
				free(alunos);	
			}
			}
			free(matriculas);		
	}
	else
	{
		printf(" Nao existe curso com o codigo informado!\n");
	}
		
	getch();
	system("cls");
	relatorios();	
} 
/* Objetivo  : apresentar situacao do aluno por extenso
   Parametros: situacao
   Retorna   : situacao por extenso */
char * formata_situacao ( char situacao )
{
	static char sit_aluno[10];
  
  	if(situacao == 'C')
    	sprintf(sit_aluno,SITUACAO_ALUNO_CURSANDO);
    else
    	sprintf(sit_aluno,SITUACAO_ALUNO_CONCLUIDO);
        
    return sit_aluno;         
}

/* Objetivo  : lê os dados dos alunos existentes em arquivo
   Parametros: end. qtde de matriculas 
   Retorna   : end. onde localiza-se os dados recuperados
              do arquivo ou NULL no caso de insucesso */
Matricula * obtem_dados_arq_matricula( int * qtde )
{
	FILE * arq = NULL;
	Matricula * matriculas = NULL, * matriculasAux = NULL;
	
	(*qtde) = obtem_qtde_arq(sizeof(Matricula),ARQUIVO_MATRICULAS );
	
    if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb"," Erro ao abrir arquivo!\n")) != NULL)
    {
		matriculasAux = (Matricula*) realloc(matriculasAux,*qtde * sizeof(Matricula));

		if(matriculasAux == NULL)
		{
			printf(" Erro ao alocar memoria!\n");
		}                      
		else
		{    
			matriculas = matriculasAux;     
			if(fread(matriculas,sizeof(Matricula),*qtde,arq)!=*qtde)
			{
				printf(" Erro de leitura!\n");
				free(matriculas);
			} 
		}           
	
	    if(fclose(arq) != 0)
	       printf(" Erro ao fechar arquivo!\n");            
    }
    
    return matriculas;
}


/* Objetivo  : pesquisa curso pelo nome
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_curso_por_nome( void )
{
	Curso * cursos;
	int qtde, cont = 0, i;
	char nome_pesq[TAM_MAX_NOME_CURSO];

	if((cursos = obtem_dados_arq_curso(&qtde)) != NULL)
    {
		ordena_cursos(qtde,cursos);
        fflush(stdin);
		  
        le_valida_string( " Nome: \n"," Nome Invalido!\n",TAM_MAX_NOME_CURSO,TAM_MIN_NOME_CURSO, nome_pesq );
		system("cls");
         
        for (i=0;i<qtde;i++)
        {
        	if(stristr(cursos[i].nome_curso,nome_pesq)!= NULL)
            {                                    
            	if( cont == 0 ){
					printf("----------------------------------------------------------\n");
					printf( "| %-6.6s | %-20.20s | %-10.10s | %-9.9s |\n","CODIGO","CURSO","C. HORARIA","VALOR(R$)");	
					printf("----------------------------------------------------------\n");
				}
				printf("| %6d | %-20.20s | %10d | %9.2f |\n",cursos[i].cod_curso,cursos[i].nome_curso,
				cursos[i].carga_horaria,cursos[i].valor_mensalidade); 
              
			    cont++;     
            }
        }
        if(cont != 0)
        	printf("----------------------------------------------------------\n");
        else
        	printf(" Nao existe cursos cadastrado com o nome %s\n",nome_pesq); 
           
    	free(cursos);
    }  
	getch();            
  	system("cls");
	relatorios();     
}
   
/* Objetivo  : lê os dados dos cursos existentes em arquivo
   Parametros: end. qtde de cursos 
   Retorna   : end. onde localiza-se os dados recuperados
            do arquivo ou NULL no caso de insucesso */
Curso * obtem_dados_arq_curso( int *qtde )
{
	FILE * arq;
	Curso * cursos = NULL, * cursosAux = NULL;
	int i;
	
	(*qtde) = obtem_qtde_arq(sizeof(Curso),ARQUIVO_CURSOS );
	
    if((arq = abre_arquivo(ARQUIVO_CURSOS,"rb"," Erro ao abrir arquivo\n")) != NULL)
    {
		cursosAux = (Curso*) realloc(cursosAux,*qtde * sizeof(Curso));

		if(cursosAux == NULL)
		{
			printf(" Erro ao alocar memoria!\n");
		}                      
		else
		{     
			cursos = cursosAux;    
			if(fread(cursos,sizeof(Curso),*qtde,arq)!=*qtde)
			{
				printf(" Erro de leitura!\n");
				free(cursos);
			} 
		}           

	    if(fclose(arq) != 0)
	       printf(" Erro ao fechar arquivo!\n");            
    }
    
    return cursos;
}

/* Objetivo  : obter a quantidade existente no arquivo
   Parametros: tamanho do registro e end. nome do arquivo 
   Retorna   : quantidade */
int obtem_qtde_arq( int tam_registro, char * nome_arq )
{
	FILE *arq;
	int qtde;
	
	if((arq=abre_arquivo(nome_arq,"rb",""))!=NULL)
	{
		if(fseek(arq,0,SEEK_END)==0)
		{
			qtde = ftell(arq)/tam_registro;
		}
		fclose(arq);
	}
	return qtde;
}
/* Objetivo  : ordena os dados dos dos cursos existentes na memória
   Parametros: qtde de cursos, end. com os dados dos cursos
   Retorna   : nenhum */
void ordena_cursos( int qtde, Curso *cursos )
{    
	qsort(cursos,qtde,sizeof(Curso),compara_nome_cursos);
}

/* Objetivo  : compara os dados a serem ordenados pela qsort
   Parametros: end. para os elementos a serem pesquisados na ordenação
   Retorna   : =0 se dados iguais
              >0 se dados desordenados
              <0 se dados ordenados */
int compara_nome_cursos( const void * p1, const void * p2 )
{
	Curso *curso1,*curso2;

	curso1 = (Curso*)p1;
	curso2 = (Curso*)p2;
	
	return stricmp(curso1->nome_curso,curso2->nome_curso); 
}
/* Objetivo  : perquisar alunos por situacao financeira
   Parametros: nenhum
   Retorna   : nenhum */
void pesquisa_aluno_por_situacao_finac ( void )
{
	FILE * arq = NULL;
	Matricula * matriculas = NULL, * matriculasAux = NULL;
	int qtde = 0;
	int flag = 0;
	char * sit_aluno;
	char sit_financeira[10];
	int opcao;
	
	textcolor(LIGHTGREEN);
	opcao = le_valida_int(" Informe a situacao financeira: \n (1)-Regular/(2)-Pendente/(3)-Pago \n"," Opcao invalida!\n",1,3);
	
	if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb",""))!=NULL){
		if(( matriculasAux = (Matricula *) realloc(NULL,sizeof(Matricula))) == NULL )
		{
			printf(" Erro ao alocar memoria!\n");            
		}
		else
		{
			matriculas = matriculasAux;
			while(!feof(arq))
			{	
				if(fread(matriculas,sizeof(Matricula),1,arq)==1)
				{
					sit_aluno = formata_situacao(matriculas->situacao_aluno);
					switch(opcao)
					{
						case 1:
							if(matriculas->situacao_financeira == 'R')
							{
								if(flag==0)
									printf(" %8.8s - %8.8s - %10.10s - %15.15s - %3.3s - %4.4s \n","ID_ALUNO","ID_CURSO","SIT. ALUNO","SIT. FINANCEIRA","MES","ANO");
								sprintf(sit_financeira,SITUACAO_FINANCEIRA_REGULAR);
								printf(" %8d - %8d - %10.10s - %15.15s - %3d - %4d \n",matriculas->id_aluno,matriculas->id_curso,
								sit_aluno,sit_financeira,matriculas->mes,matriculas->ano);
								flag=1; 
							}
							break;
						case 2:
							if(matriculas->situacao_financeira == 'P')
							{
								if(flag==0)
									printf(" %8.8s - %8.8s - %10.10s - %15.15s - %3.3s - %4.4s \n","ID_ALUNO","ID_CURSO","SIT. ALUNO","SIT. FINANCEIRA","MES","ANO");
								sprintf(sit_financeira,SITUACAO_FINANCEIRA_PENDENTE);
								printf(" %8d - %8d - %10.10s - %15.15s - %3d - %4d \n",matriculas->id_aluno,matriculas->id_curso,
								sit_aluno,sit_financeira,matriculas->mes,matriculas->ano);
								flag=1; 
							}
							break;
						default:
							if(matriculas->situacao_financeira == 'F')
							{
								if(flag==0)
									printf(" %8.8s - %8.8s - %10.10s - %15.15s - %3.3s - %4.4s \n","ID_ALUNO","ID_CURSO","SIT. ALUNO","SIT. FINANCEIRA","MES","ANO");
								sprintf(sit_financeira,SITUACAO_FINANCEIRA_PAGO);
								printf(" %8d - %8d - %10.10s - %15.15s - %3d - %4d \n",matriculas->id_aluno,matriculas->id_curso,
								sit_aluno,sit_financeira,matriculas->mes,matriculas->ano);
								flag=1; 
							}
							break;
					}
					
				}
			}
			free(matriculas);
		}
		if(fclose(arq)!=0)
			printf("Erro ao fechar arquivo matricula.txt!\n");
		
	}
	if(flag==0)
		printf(" Nao existe alunos cadastrados!\n");

	getch();
	system("cls");
	relatorios();
}
/* Objetivo  : apresentar alunos com o curso concluido em determinado ano
   Parametros: nenhum
   Retorno	 : nenhum */
void pesquisa_aluno_curso_anoMat_situac( void )
{
	Matricula * matriculas = NULL;
	Aluno * alunos = NULL;
	int qtde = 0, i, ano_pesq;
	int cod_pesq, ret = 0, qtde2 = 0;
	char * cpf_formatado = NULL;
	char * data = NULL;
	char * sexo_por_extenso = NULL;

	textcolor(LIGHTGREEN);
	// apresentar tabela para selecao
	cod_pesq = le_valida_int(" Informe o codigo do curso a ser pesquisado: \n"," Codigo Invalido!\n",TAM_MIN_CODIGO,9999999);
	
	if((ret = obtem_codigo_curso(cod_pesq)) != 0)
	{
		matriculas = obtem_dados_ano_mat(&qtde2,ano_pesq);
		alunos = obter_aluno_sit_concluido(&qtde);
		if(alunos != NULL)
		{
			ordena_alunos(qtde,alunos); 
	    	for (i=0;i<qtde;i++)
	        {	                                   
	        	if( i == 0 ){
					printf("--------------------------------------------------------------------------------\n");
					printf( "|%5.5s|%-20.20s|%-14.14s|%-5.5s|%-10.10s|%-10.10s|%3.3s|%4.4s|\n","COD","ALUNO","CPF","IDADE","SEXO","DATA","MES","ANO");	
					printf("--------------------------------------------------------------------------------\n");
				}
				cpf_formatado = formata_CPF(alunos[i].cpf);
				data = formata_data(alunos[i].data_ingresso);
				sexo_por_extenso = alunos[i].sexo == 'F' ? SEXO_FEMININO : SEXO_MASCULINO;
				printf("|%5d|%-20.20s|%-14.14s|%5d|%-10.10s|%10.10s|%3d|%4d|\n",alunos[i].matricula,alunos[i].nome_aluno,
				cpf_formatado,alunos[i].idade,sexo_por_extenso,data,matriculas[i].mes,matriculas[i].ano);       
	        }
        	if(i != 0)
        		printf("--------------------------------------------------------------------------------\n");	
		}
		free(alunos);
		free(matriculas);
	}
	else
	{
		printf(" Nao existe curso com o codigo informado!\n");
	}
	
	getch();
	system("cls");
	relatorios();
}
/* Objetivo  : obter dados pesquisados
   Parametros: end. para armazenar quantidade necessaria
   Retorna   : end. de estrutura com os dados necessarios */
Aluno * obter_aluno_sit_concluido( int * qtdeAlunos )
{
	FILE * arqBin = NULL;
	Matricula * matriculas = NULL;
	Aluno * alunos = NULL, * alunosAux;
	int qtde = 0, ano_pesq;
	
	ano_pesq = le_valida_int(" Informe o ano de conclusao: \n"," Ano invalido!\n",TAM_MIN_ANO,TAM_MAX_ANO);
	
	if((matriculas = obtem_dados_ano_mat(&qtde,ano_pesq)) != 0)
	{
		if((arqBin = abre_arquivo(ARQUIVO_ALUNOS,"rb"," Erro ao abrir o arquivo!\n"))!=NULL)
		{
			while(!feof(arqBin))
			{
			
				alunosAux = (Aluno*)realloc(NULL,sizeof(Aluno)*((*qtdeAlunos)+1));			
				if( alunosAux != NULL )
				{
					alunos = alunosAux;
					if(fread(&alunos[*qtdeAlunos],sizeof(Aluno),1,arqBin)==1)
					{
						if(matriculas[*qtdeAlunos].id_aluno == alunos[*qtdeAlunos].matricula)
						{
							(*qtdeAlunos)++;
						}
						
					}
					else
					{
						printf(" Erro ao ler arquivo!\n");
					}
				}
				else
				{
					printf(" Erro ao alocar memoria!\n");
				}
			}
			if(fclose(arqBin)!=0)
				printf("Erro ao fechar o arquivo\n");
		}
		
	}
	else
	{
		printf(" Nao existe alunos cadastrados!\n");
	}

	return alunos;
}

/* Objetivo  : obter dados de matriculas com o ano informado 
   Parametros: end. para armqzenar quantidade e ano informado
   Retorno   : end. estrutura com os dados pesquisados */
Matricula * obtem_dados_ano_mat( int * qtde, int ano_pesq )
{
	FILE * arq = NULL;
	Matricula * matriculas = NULL, * matriculasAux = NULL;
	
	if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb"," Erro ao abrir o arquivo!\n"))!=NULL)
	{
		while(!feof(arq))
		{
			matriculasAux = (Matricula*)realloc(matriculasAux,sizeof(Matricula)*((*qtde)+1));			
			if( matriculasAux != NULL )
			{
				matriculas = matriculasAux;
				if(fread(matriculas,sizeof(Matricula),1,arq)==1)
				{
					if(matriculas->ano == ano_pesq)
					{
						if(matriculas->situacao_aluno == 'T')
						{
							(*qtde)++;
						}	
					}
				}
			}else{
				printf(" Erro ao alocar memoria!\n");
			}
		}
		if(fclose(arq)!=0){
			printf(" Erro ao fechar o arquivo!\n");
		}
	}
	return matriculas;
}


/* Objetivo  : mostrar data e hora formatada no menu principal
   Parametros: nenhum
   Retorna   : nenhum */
void HoraData()
{
     textbackground(BLACK);
     gotoxy(6,22);textcolor(WHITE);
     printf("Data:");
     system("date/t");
     gotoxy(6,23);
     printf("Horas:     ");
     system("time/t ");
}

/* Objetivo  : formatar janela de menu principal
   Parametros: nenhum
   Retorna   : nenhum */
void cores_janela1()
{
     int lin, col;
     col = 0;
     for( lin = 2; lin <= 24; lin++ )
         for( col = 3; col <= 78; col++ ){
              gotoxy( col, lin );
			  textbackground(5);
			  printf(" ");
         }
     col = 0;
     for( lin = 5; lin <= 21; lin++ )
         for( col = 6; col <= 75; col++ ){
              gotoxy( col, lin );
			  textbackground(16);
			  printf(" ");
         }
		 HoraData();
}
/**************************************************************************************/

/* Objetivos : apresentar menu principal formatado
   Parametros: nenhum
   Retorna   : nenhum*/
void menu_principal()
{
     system("title ESCOLA DE INFORMATICA");
	 HoraData();
     system("cls");
     cores_janela1();
     textcolor(WHITE);gotoxy(33,3); 
	 printf("ESCOLA DE INFORMATICA");
     textcolor(LIGHTGREEN);gotoxy(29,7); 
	 printf("[-----MENU PRINCIPAL-----]");
     char * menu_list [ TAM_MAX_MENU_PRINC ] = { "Controle de Alunos",
									             "Controle de Cursos",
									             "Controle de Matriculas",
									             "Relatorios",
									             "Sair do Programa" };
     int i,
     xpos = 15,
     ypos [ TAM_MAX_MENU_PRINC ] = { 11, 13, 15, 17, 19 }; 
     for ( i = 0; i < TAM_MAX_MENU_PRINC; ++i ){
         gotoxy (xpos, ypos [i] );
         textattr(10);
         printf("%s",menu_list [i] );
     }
     i = 0;
     while (1) {
         gotoxy( xpos, ypos [i] );
         textattr(6);
         printf("%s",menu_list [i] );
         
         switch ( _getch () ){
         case 72: 
		    if ( i > 0 ) {
              gotoxy( xpos, ypos [i] );
              textattr(10);
              printf("%s", menu_list [i] );
              --i;
         	}
         	break;
         case 80: 
		      if ( i <  TAM_MAX_MENU_PRINC -1 ){
	              gotoxy( xpos, ypos [i] );
	              textattr(14);
	              printf("%s", menu_list [i] );
	              ++i;
              }
              break;
         case 13:
              if ( i == 0 ) {  system("cls"); menu_alunos (); }
              if ( i == 1 ) {  system("cls"); menu_cursos (); }
              if ( i == 2 ) {  system("cls"); menu_matriculas (); }
              if ( i == 3 ) {  system("cls"); relatorios (); }
              if ( i == 4 ) {  system("cls"); funcao_exit();}
              break;
         }
     }
}


/***************************************************************************************************
/* Objetivo  : obter data atual
   Parametros: end. data
   Retorna   : nenhum */
void obtem_data( char * data )
{    
    time_t agora = time(NULL);
	struct tm * tempo = localtime( &agora );
	
	strftime( data, TAM_MAX_DATA, "%d%m%Y", tempo );
}

/* Objetivo  : formatar CPF
   Parametros: end. cpf
   Retorna   : cpf formatado */
char * formata_CPF ( char * cpf )
{
	static char cpfFormatado[15];
  
    sprintf(cpfFormatado,"%3.3s.%3.3s.%3.3s-%2.2s",cpf,cpf+3,cpf+6,cpf+9);
        
    return cpfFormatado;         
}
/* Objetivo  : formatar data
   Parametros: end. data
   Retorna   : data formatada */
char * formata_data ( char * data )
{
	static char data_formatada[11];
  
    sprintf(data_formatada,"%2.2s/%2.2s/%4.4s",data,data+2,data+4);
        
    return data_formatada;         
}

/* Objetivo  : obter situacao do aluno
   Parametros: codigo do aluno
   Retorna   : posicao onde se escontra a situacao do aluno */
int verifica_situacao( int codigo )
{
	Matricula matricula;
	FILE * arq;
	int nro_verifica = 0;
	
	if((arq = abre_arquivo(ARQUIVO_MATRICULAS,"rb",""))!=NULL){
		while(!feof(arq)){
			if(fread(&matricula,sizeof(Matricula),1,arq)==1){
				if(codigo == matricula.id_aluno){
                    if(matricula.situacao_aluno == 'C')
                    {
                    	nro_verifica = 1;
                    	break;
					}	
				}
			}
		}
		fclose(arq);
	}
	
	return nro_verifica;
}
   
/* Objetivo  : obter ultimo codigo do curso lido
   Parametros: nenhum
   Retorna   : ultimo codigo lido se obteve sucesso ou NULL*/
int obtem_ultimo_codigo_lido( void )
{
	FILE * arq;
	int cont = 0;
	Curso curso; 
	int codigo = 0;
	
	if((arq = abre_arquivo(ARQUIVO_CURSOS,"rb"," Erro ao abrir o arquivo")) != NULL)
	{
		if(fseek(arq,(codigo-1)*sizeof(Curso),SEEK_END) == 0)
		{        
			if(fread(&curso.cod_curso,sizeof(curso.cod_curso),1,arq)==1)
			{
				codigo = curso.cod_curso;
			}
		}
		else
		{
			printf(" Erro ao posicionar arquivo!\n");               
		} 
		if(fclose(arq)!=0)
			printf("Erro ao fechar arquivo alunos.txt!\n");
	}
	return codigo;
}
/* Objetivo  : inverter data para verificacao
   Parametros: end. data
   Retorna   : data invertida como inteiro */
int inverte_data( char * data )
{
	int cont, data_i;
	char data_aux[9];
    
    for(cont = 0; cont < strlen(data); cont++)
	{
		data_aux[0]=data[4];
		data_aux[1]=data[5];
		data_aux[2]=data[6];
		data_aux[3]=data[7];
		data_aux[4]=data[2];
		data_aux[5]=data[3];
		data_aux[6]=data[0];
		data_aux[7]=data[1];	
	}
			
	data_i=atoi(data_aux);
	
	return data_i;         
}




