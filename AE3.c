#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 200

typedef struct dados{
	int codigo;
	int modo;
	char nome[30];
	char desc[30];
	char responsavel [30];
	

}base_projetos;

int posicao = 0;

void cadastrarProjeto(base_projetos cadastro[MAX]); 
void listarProjeto(base_projetos cadastro[MAX]); 
void listarAfazer(base_projetos cadastro[MAX]); 
void listarFazendo(base_projetos cadastro[MAX]); 
void listarConcluido(base_projetos cadastro[MAX]); 
void cabecalho ();
void cabecalhoAfazer ();
void cabecalhoFazendo ();
void cabecalhoConcluido ();
void cabecalhoTodos ();
void cabecalhoCad ();

int main(){
	setlocale(LC_ALL, "Portuguese");
	base_projetos cadastro[MAX];
	
	int escolha;
	
	system("cls");	
	do{
		cabecalho ();
		printf("\n1 - Cadastrar projetos\n");
		printf("2 - Listar todos os projetos\n");
		printf("3 - Listar todos os projetos - A fazer\n");
		printf("4 - Listar todos os projetos - Fazendo\n");
		printf("5 - Listar todos os projetos - Concluído\n");
		printf("6 - Sair\n");
		printf("Escolha a opção:");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				listarProjeto(cadastro);
				break;
			case 3:
				listarAfazer(cadastro);
				break;
			case 4:
				listarFazendo(cadastro);
				break;
			case 5:
				listarConcluido(cadastro);
				break;	
			case 6:
				printf("\nFinalizando a aplicação!\n");
				system("Pause");
				break;
			default:
				printf("\nOpção inválida!\n");
				system("Pause");
		}
	}while(escolha != 6);
	return 0;
}

void cadastrarProjeto(base_projetos cadastro[MAX]){
	cabecalhoCad ();
	char resp = 's';
	
	while(resp == 's' && posicao <= MAX){
		posicao++;
		cabecalhoCad ();
		printf("\nCódigo do projeto: %d ", posicao);
		cadastro[posicao].codigo = posicao;
		
		printf("\nDigite o nome do projeto: \n");
		fflush(stdin);
		gets(cadastro[posicao].nome);
			
		printf("Digite uma breve descrição do projeto: \n");
		fflush(stdin);
		gets(cadastro[posicao].desc);
		
		printf("Digite o nome do responsável do projeto: \n");
		fflush(stdin);
		gets(cadastro[posicao].responsavel);
		
		printf("Digite o status do projeto (Apenas número)\n");
		printf("[1]- A fazer  |  [2]- Fazendo  |  [3]- Concluído \n");
		scanf("%d", &cadastro[posicao].modo);
		
		if(posicao < MAX){
			printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Não: \n");
			fflush(stdin);
			scanf("%c", &resp);
		}else{
			printf("\nLimite de cadastro atingido!\n");
			resp = 'n';
		}
	}
}
void listarProjeto(base_projetos cadastro[MAX]){
	cabecalhoTodos ();
	int linha=1;
	
	if(posicao >= 1){
		while(linha <= posicao){
			printf("Código do projeto: %d\n", cadastro[linha].codigo);
			printf("Nome do projeto  : %s\n", cadastro[linha].nome);
			printf("Descrição        : %s\n", cadastro[linha].desc);
			printf("Responsável      : %s\n", cadastro[linha].responsavel);
			printf("Status projeto   : ( %d ) [1]- A fazer [2]- Fazendo [3]- Concluído\n", cadastro[linha].modo);
			printf("-------------------------------------------------------------------\n");
			linha++;
		}			
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void listarAfazer(base_projetos cadastro[MAX]){
	cabecalhoAfazer ();
	int linha=1;
	
	if(posicao >= 1){
		while(linha <= posicao && cadastro[linha].modo ==1){
			printf("Status projeto   : %d - %s | A fazer\n", cadastro[linha].modo, cadastro[linha].nome);
			linha++;
		}		
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}


void listarFazendo(base_projetos cadastro[MAX]){
	cabecalhoFazendo ();
	int linha=2;
	
	if(posicao >= 2){
		while(linha <= posicao && cadastro[linha].modo ==2){
			printf("Status projeto   : %d - %s | Fazendo\n", cadastro[linha].modo, cadastro[linha].nome);
			linha++;
		}		
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void listarConcluido(base_projetos cadastro[MAX]){
	cabecalhoConcluido ();
	int linha=3;
	
	if(posicao >= 3){
		while(linha <= posicao && cadastro[linha].modo ==3){
			printf("Status projeto   : %d - %s | Concluído\n", cadastro[linha].modo, cadastro[linha].nome);
			linha++;
		}		
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void cabecalho (){
	system("cls");
	printf("-------------------------------------------------------------------\n");
	printf("                             PROJETOS                              \n");
	printf("-------------------------------------------------------------------\n");
}

void cabecalhoCad (){
	system("cls");
	printf("-------------------------------------------------------------------\n");
	printf("                        CADASTRAR PROJETOS                         \n");
	printf("-------------------------------------------------------------------\n");
}

void cabecalhoTodos (){
	system("cls");
	printf("-------------------------------------------------------------------\n");
	printf("                    LISTA DE TODOS OS PROJETOS                     \n");
	printf("-------------------------------------------------------------------\n");
}

void cabecalhoConcluido (){
	system("cls");
	printf("-------------------------------------------------------------------\n");
	printf("                  LISTA DE PROJETOS - CONCLUÍDOS                   \n");
	printf("-------------------------------------------------------------------\n");
}

void cabecalhoFazendo (){
	system("cls");
	printf("-------------------------------------------------------------------\n");
	printf("                   LISTA DE PROJETOS - FAZENDO                     \n");
	printf("-------------------------------------------------------------------\n");
}

void cabecalhoAfazer (){
	system("cls");
	printf("-------------------------------------------------------------------\n");
	printf("                   LISTA DE PROJETOS - A FAZER                     \n");
	printf("-------------------------------------------------------------------\n");
}

