#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texo por região  
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários
{
  //início da criação de variáveis/string	
  char arquivo[40];	
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //Final da criação de variáveis/string
  
  printf("Digite o cpf a ser cadastrado: "); //Coletando informações do usuário
  scanf("%s", cpf); //Armazena string
  
  strcpy(arquivo, cpf); // Responsável por copiar os valores das string
  
  FILE *file; // Cria o arquivo
  file = fopen(arquivo, "w"); // abre o arquivo e o w é para ecrever
  fprintf(file,cpf); //Salvo o valor da variável
  fclose(file); //Fecha o arquivo
  
  file = fopen(arquivo, "a"); //Abre o arquivo e o "a" é para atualizar
  fprintf(file,",");
  fclose(file); //Fecha o arquivo
  
  printf("Digite o nome a ser cadastrado: "); // Informação dada ao usuário
  scanf("%s",nome); // Salva a string
  
  file = fopen(arquivo, "a"); // Abre o arquivo e o "a" atualiza
  fprintf(file, nome); //Fala para o computador do arquivo nome
  fclose(file); // Fecha o arquivo
  
  file = fopen(arquivo, "a"); //abre o arquivo e o "a" é para atualizar
  fprintf(file, ",");
  fclose(file); // Fecha o arquivo
  
  printf("Digite o sobrenome a ser cadastrado:"); //Fala ao usuário 
  scanf("%s", sobrenome); //Salva a string
  
  file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
  fprintf(file, sobrenome); // Fala para o computador arquivo sobrenome
  fclose(file); //Fecha o arquivo
  
  file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
  fprintf(file, ",");
  fclose(file); //Fecha o arquivo
  
  printf("Digite o cargo a ser cadastrado:"); //Fala ao usuário
  scanf("%s", cargo); //Armazena a string
  
  file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
  fprintf(file, cargo); // Fala para o computador o aruivo cargo
  fclose(file); //Fecha o arquivo
  
  system("pause"); //Pausa o programa para não passar direto na decisão 		
}

int consulta() //Função responsável por consultar os nomes
{
	setlocale(LC_ALL, "Portuguese"); // Define a linguagem (Portuguese)
	
	//Criação de variáveis, porque o computador não conhece a variável em outra função
	char cpf[40];
	char conteudo[200]; 
	
	
	printf("Digite o cpf a ser consultado: "); // Informação ao usuário
	scanf("%s", cpf); //Armazena string
	
	FILE *file; //Chama o FILE do sistema já existente e cria o file
	file = fopen(cpf, "r"); //Abre o arquivo e a letra "r" lê o arquivo cpf no caso aqui
	
	if(file == NULL) //Se o arquivo digitado não existir? É uma comparação a pergunta 
	{
		printf("Não foi possível abrir o arquivo, usuário não foi localizado!.\n"); //Informação que aparece ao usuário
		system("pause"); //Pause o programa para não passar direto
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: "); //Informação ao usuário
    	printf("%s", conteudo); //Informação ao usuário , armazenamento da string conteudo
    	printf("\n\n"); // Pular linha
    	
    	system("pause"); //Pausa o programa para o programa não passar direto e voltar ao início
	}
}			

int deleta () //Função de deletar os nomes e dados do programa
{
    char cpf[40]; //Variável string 
	
	printf("Digite o cpf do usuário a ser deletado: "); //Informação ao usário
	scanf("%s", cpf); //Armazena a string
	
	remove(cpf); //Deleta os dados
	
	FILE *file; //FILE do sistema cria o file
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" o lê
	
	if(file == NULL) //Pergunta e afirmação 
	{
		printf("O usuário não se encontra no sistema!.\n"); //Informação ao usuário
		system("pause"); //Pausa o programa para não ir direto ou voltar ao início
		}
			
}



int main() //Corpo do programa
{
	int opcao=0; //Definindo Variáveis
	int laco=1; //Laço de repetição, o programa começa e quando chega no fim , volta ao início
	
	for(laco=1;laco=1;) //Responsável por voltar o programa ao início quando chegar ao final
	{
		
		system("cls"); //Responsável por limpar a tela, deixar mais agradável 
		
		
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem ,localiza a linguagem por região aqui linguagem em português
	
	
    	printf("#### Cartório da EBAC ####\n\n"); // Início do Menu
	    printf("Escolha a opção desejada do menu:\n\n"); //Informção do menu falando para tomar uma decisão e o \n serve para pular linha
	    printf("\t1 - Registrar nomes\n"); //Decisões,o t1 é usado para pular espaço
	    printf("\t2 - Consultar nomes\n"); //Decisões, o t2 é usado para pular espaço
    	printf("\t3 - Deletar nomes\n"); //Decisões, o t3 é usado para pular espaço
		printf("\t4 - Sair do sistema\n\n"); //opção de sair do sistema 
    	printf("Opção:"); //fim do Menu
	
	    scanf("%d", &opcao); //scanf armazena tudo que for digitado antes , no caso aqui, vai armazenar na variável opcao, no caso de variável inteira é %d
	
	    system("cls"); //cls limpa a tela , fazendo assim ficar mais limpo
	
	
	    switch(opcao) //Início da seleção de função
	    {
		    case 1: //Responsável por chamar a função de registro de nome
	    	registro(); //Função registrar
	        break; //Parar o programa
		
		    case 2: //Responsável pela chamada de função consultar nomes
		    consulta(); //Função registrar
		    break; //Para o programa
		
		    case 3: //Responsável pela chamada de função deletar
		    deleta(); //Função deletar
		    break; //Parar o programa
		    
		    case 4: //Sair do sistema	
		    printf("Obrigado por ultilizar nosso sistema!\n");
		    return 0;
		    break;
		
		    default: //Quando digitar dados inválidos
		    printf("Essa opção não está disponível!\n"); //Informação ao usuário
		    system("pause"); //Pausa o programa para não passar direto
		    break;
			//Fim da seleção de funções	
			
       }
	
   
   }
	
}
