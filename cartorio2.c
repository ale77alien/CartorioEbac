#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texo por regi�o  
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios
{
  //in�cio da cria��o de vari�veis/string	
  char arquivo[40];	
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //Final da cria��o de vari�veis/string
  
  printf("Digite o cpf a ser cadastrado: "); //Coletando informa��es do usu�rio
  scanf("%s", cpf); //Armazena string
  
  strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
  
  FILE *file; // Cria o arquivo
  file = fopen(arquivo, "w"); // abre o arquivo e o w � para ecrever
  fprintf(file,cpf); //Salvo o valor da vari�vel
  fclose(file); //Fecha o arquivo
  
  file = fopen(arquivo, "a"); //Abre o arquivo e o "a" � para atualizar
  fprintf(file,",");
  fclose(file); //Fecha o arquivo
  
  printf("Digite o nome a ser cadastrado: "); // Informa��o dada ao usu�rio
  scanf("%s",nome); // Salva a string
  
  file = fopen(arquivo, "a"); // Abre o arquivo e o "a" atualiza
  fprintf(file, nome); //Fala para o computador do arquivo nome
  fclose(file); // Fecha o arquivo
  
  file = fopen(arquivo, "a"); //abre o arquivo e o "a" � para atualizar
  fprintf(file, ",");
  fclose(file); // Fecha o arquivo
  
  printf("Digite o sobrenome a ser cadastrado:"); //Fala ao usu�rio 
  scanf("%s", sobrenome); //Salva a string
  
  file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
  fprintf(file, sobrenome); // Fala para o computador arquivo sobrenome
  fclose(file); //Fecha o arquivo
  
  file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
  fprintf(file, ",");
  fclose(file); //Fecha o arquivo
  
  printf("Digite o cargo a ser cadastrado:"); //Fala ao usu�rio
  scanf("%s", cargo); //Armazena a string
  
  file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
  fprintf(file, cargo); // Fala para o computador o aruivo cargo
  fclose(file); //Fecha o arquivo
  
  system("pause"); //Pausa o programa para n�o passar direto na decis�o 		
}

int consulta() //Fun��o respons�vel por consultar os nomes
{
	setlocale(LC_ALL, "Portuguese"); // Define a linguagem (Portuguese)
	
	//Cria��o de vari�veis, porque o computador n�o conhece a vari�vel em outra fun��o
	char cpf[40];
	char conteudo[200]; 
	
	
	printf("Digite o cpf a ser consultado: "); // Informa��o ao usu�rio
	scanf("%s", cpf); //Armazena string
	
	FILE *file; //Chama o FILE do sistema j� existente e cria o file
	file = fopen(cpf, "r"); //Abre o arquivo e a letra "r" l� o arquivo cpf no caso aqui
	
	if(file == NULL) //Se o arquivo digitado n�o existir? � uma compara��o a pergunta 
	{
		printf("N�o foi poss�vel abrir o arquivo, usu�rio n�o foi localizado!.\n"); //Informa��o que aparece ao usu�rio
		system("pause"); //Pause o programa para n�o passar direto
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: "); //Informa��o ao usu�rio
    	printf("%s", conteudo); //Informa��o ao usu�rio , armazenamento da string conteudo
    	printf("\n\n"); // Pular linha
    	
    	system("pause"); //Pausa o programa para o programa n�o passar direto e voltar ao in�cio
	}
}			

int deleta () //Fun��o de deletar os nomes e dados do programa
{
    char cpf[40]; //Vari�vel string 
	
	printf("Digite o cpf do usu�rio a ser deletado: "); //Informa��o ao us�rio
	scanf("%s", cpf); //Armazena a string
	
	remove(cpf); //Deleta os dados
	
	FILE *file; //FILE do sistema cria o file
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" o l�
	
	if(file == NULL) //Pergunta e afirma��o 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //Informa��o ao usu�rio
		system("pause"); //Pausa o programa para n�o ir direto ou voltar ao in�cio
		}
			
}



int main() //Corpo do programa
{
	int opcao=0; //Definindo Vari�veis
	int laco=1; //La�o de repeti��o, o programa come�a e quando chega no fim , volta ao in�cio
	
	for(laco=1;laco=1;) //Respons�vel por voltar o programa ao in�cio quando chegar ao final
	{
		
		system("cls"); //Respons�vel por limpar a tela, deixar mais agrad�vel 
		
		
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem ,localiza a linguagem por regi�o aqui linguagem em portugu�s
	
	
    	printf("#### Cart�rio da EBAC ####\n\n"); // In�cio do Menu
	    printf("Escolha a op��o desejada do menu:\n\n"); //Inform��o do menu falando para tomar uma decis�o e o \n serve para pular linha
	    printf("\t1 - Registrar nomes\n"); //Decis�es,o t1 � usado para pular espa�o
	    printf("\t2 - Consultar nomes\n"); //Decis�es, o t2 � usado para pular espa�o
    	printf("\t3 - Deletar nomes\n"); //Decis�es, o t3 � usado para pular espa�o
		printf("\t4 - Sair do sistema\n\n"); //op��o de sair do sistema 
    	printf("Op��o:"); //fim do Menu
	
	    scanf("%d", &opcao); //scanf armazena tudo que for digitado antes , no caso aqui, vai armazenar na vari�vel opcao, no caso de vari�vel inteira � %d
	
	    system("cls"); //cls limpa a tela , fazendo assim ficar mais limpo
	
	
	    switch(opcao) //In�cio da sele��o de fun��o
	    {
		    case 1: //Respons�vel por chamar a fun��o de registro de nome
	    	registro(); //Fun��o registrar
	        break; //Parar o programa
		
		    case 2: //Respons�vel pela chamada de fun��o consultar nomes
		    consulta(); //Fun��o registrar
		    break; //Para o programa
		
		    case 3: //Respons�vel pela chamada de fun��o deletar
		    deleta(); //Fun��o deletar
		    break; //Parar o programa
		    
		    case 4: //Sair do sistema	
		    printf("Obrigado por ultilizar nosso sistema!\n");
		    return 0;
		    break;
		
		    default: //Quando digitar dados inv�lidos
		    printf("Essa op��o n�o est� dispon�vel!\n"); //Informa��o ao usu�rio
		    system("pause"); //Pausa o programa para n�o passar direto
		    break;
			//Fim da sele��o de fun��es	
			
       }
	
   
   }
	
}
