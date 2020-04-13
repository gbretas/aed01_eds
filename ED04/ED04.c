/*
ED04 - 07/04/2020 
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"

//Verificar se pertecente a um intervalo
bool belongsTo(double valor, double intevalo_menor, double intervalo_maior){
    bool result = false;
	if(valor >= intevalo_menor && valor <= intervalo_maior){
		result = true;
	}
    return (result);
}

//Metodo1
void metodo1(){
	double intevalo_menor = 0.0, intervalo_maior = 0.0, valor = 0.0;
	int quantidade, contador_dentro = 0, contador_fora = 0;

	IO_printf("1 - Contar quantos numeros estao dentro e quantos estao fora do intervalo \n\n");
	intevalo_menor = IO_readdouble("Digite o intervalo menor: ");
	intervalo_maior = IO_readdouble("Digite o intervalo maior: ");
	if(intervalo_maior <=  intevalo_menor){
		IO_print("\nO intervalo maior deve ser maior que o intervalo menor");
	}else{
		IO_line();
		quantidade = IO_readint("Digite a quantidade de numeros a serem inseridos: ");
		IO_line();
		for (int i = 0; i < quantidade; i++)
		{
			IO_printf("Digite o numero %i: ", i + 1);
			valor = IO_readdouble("");
			if(belongsTo(valor, intevalo_menor, intervalo_maior)){
				contador_dentro++;
			}else{
				contador_fora++;
			}
		}
		IO_line();
		IO_printf("Voce digitou %i numeros dentro do intervalo e %i fora do intervalo", contador_dentro, contador_fora);
	}
}

//Verificar se maiuscula
bool maiuscula(char x){
	bool result = false;
	if ( 'A' <= x && x <= 'Z' ) {
		result = true;
	}
	return (result);
}
//Verificar se minuscula
bool minuscula(char x){
	bool result = false;
	if ( 'a' <= x && x <= 'z' ) {
		result = true;
	}
	return (result);
}

//Metodo2
void metodo2(){
	int i, contador = 0;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("2 - Verificar caracteres maiusculos\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	for (i = 0; i < strlen(palavra); i++)
	{
		if(maiuscula(palavra[i])){
			contador++;
		}
	}
	IO_line();
	IO_printf("A palavra %s tem %i letra maiusculas", palavra, contador);
}

//Countar caracteres maiusculos
int countUpper(chars palavra){
	int i, maiusculas = 0;
	char simbolo;
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(maiuscula(simbolo)){
			maiusculas++;
		}
		
	}
	return maiusculas;
} 
//Metodo 3
void metodo3(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("3 - Verificar e contar caracteres maiusculos por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	IO_line();
	IO_printf("A palavra %s tem %i letra maiusculas", palavra, countUpper(palavra));
}

//Show Upper
void showUpper(chars palavra){
	int i;
	char simbolo;
	IO_line();
	IO_printf("A palavra %s tem as seguintes letras maiusculas: ", palavra);
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(maiuscula(simbolo)){
			IO_printf("%c, ", simbolo);
		}
		
	}
}
// 4 - Verificar e mostar caracteres maiusculos separados por uma funcao
void metodo4(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("4 - Verificar e mostar caracteres maiusculos separados por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	showUpper(palavra);
}

//Count upper and lower case
void countUpperAndLower(chars palavra){
	int i, maiusculas = 0, minusculas = 0;
	char simbolo;
	IO_line();
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(maiuscula(simbolo)){
			maiusculas++;
		}
		if(minuscula(simbolo)){
			minusculas++;
		}
	}
	IO_printf("A palavra %s tem as %i letras maiusculas e %i letras minusculas ", palavra, maiusculas, minusculas);
}
//Metodo 5
void metodo5(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("5 - Verificar e contar maiusculos e minusuculos separados por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	countUpperAndLower(palavra);
}


//Show upper and lower case
void showUpperAndLower(chars palavra){
	int i;
	char simbolo;
	IO_line();
	IO_printf("A palavra %s tem as seguintes letras maiusculas: ", palavra);
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(maiuscula(simbolo)){
			IO_printf("%c, ", simbolo);
		}
	}
	IO_printf(" e as seguintes letras minusculas: ");
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(minuscula(simbolo)){
			IO_printf("%c, ", simbolo);
		}
	}
	
}
//Metodo 6
void metodo6(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("6 - Verificar e mostar maiusculos e minusuculos separados por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	showUpperAndLower(palavra);
}


//Show upper and lower case
void verifyDigitPair(chars palavra){
	int i, quantidade = 0;
	char simbolo;
	IO_line();
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(isdigit((int)simbolo)){
			if((int)simbolo%2 == 0){
				quantidade++;
			}
		}
	}
	IO_printf("A cadeia de caracteres %s tem %i digitos pares", palavra, quantidade);
	
}
//Metodo 7
void metodo7(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("7 - Verificar e mostar digitos pares separados por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	verifyDigitPair(palavra);
}

//Show upper and lower case
void notAlpha(chars palavra){
	int i;
	char simbolo;
	IO_line();
	IO_printf("A palavra %s tem as seguintes letras nao alphanumericos: ", palavra);
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(!isalpha(simbolo)){
			IO_printf("%c, ", simbolo);
		}
	}
	
	
}
void metodo8(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("8 - Verificar e mostar nao alpha numericos separados por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	notAlpha(palavra);
}


//Show upper and lower case
void showAlpha(chars palavra){
	int i;
	char simbolo;
	//IO_line();
	IO_printf("A palavra %s tem as seguintes letras alphanumericos: ", palavra);
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(isalpha(simbolo)){
			IO_printf("%c, ", simbolo);
		}
	}
}
//9 - Verificar e mostar alpha numericos separados por uma funcao
void metodo9(){
	int i;
	chars palavra = IO_new_chars ( STR_SIZE );
	IO_printf("9 - Verificar e mostar alpha numericos separados por uma funcao\n\n");
	palavra = IO_readstring("Digite uma cadeia de caracteres: ");
	showAlpha(palavra);
}

int calcularAlpha(chars palavra){
	int quantidade = 0;
	char simbolo;
	int i;
	for (i = 0; i < strlen(palavra); i++)
	{
		simbolo = palavra[i];
		if(isalpha(simbolo)){
			quantidade++;
		}
	}

	return quantidade;
}

void metodo10(){
	int loop, i, palavras = 0;
	chars palavra = IO_new_chars ( STR_SIZE );;
	IO_printf("10 - Total de palavras de uma quantidade x de cadeias de caracteres \n\n");
	loop = IO_readint("Digite a quantidade de palavras a serem lidas: ");
	for (i = 0; i < loop; i++)
	{
		IO_printf("\n\nDigite a palvra %i: ", i+1);
		palavra = IO_readstring("");
		showAlpha(palavra);
		palavras += calcularAlpha(palavra);
	}
	IO_printf("Todas as %i palavras digitas possuem %i caracteres alphanumericos", i, palavras);
	
}

	

void select() {
	int atividade;
	IO_id("ED04 - 07 abr 2020");
		
	IO_printf("0 - Sair \n");
	IO_printf("1 - Exemplo 1 \n");
	IO_printf("2 - Exemplo 2 \n");
	IO_printf("3 - Exemplo 3 \n");
	IO_printf("4 - Exemplo 4 \n");
	IO_printf("5 - Exemplo 5 \n");
	IO_printf("6 - Exemplo 6 \n");
	IO_printf("7 - Exemplo 7 \n");
	IO_printf("8 - Exemplo 8 \n");
	IO_printf("9 - Exemplo 9 \n");
	IO_printf("10 - Exemplo 10 \n");
	atividade = IO_readint("Digite qual atividade você deseja executar: ");
	IO_printf("\n\n");
	system("clear");
	switch(atividade){
		case 1:
			metodo1();
			break;
		case 2:
			metodo2();
			break;
		case 3:
			metodo3();
			break;
		case 4:
			metodo4();
			break;
		case 5:
			metodo5();
			break;
		case 6:
			metodo6();
			break;
		case 7:
			metodo7();
			break;
		case 8:
			metodo8();
			break;
		case 9:
			metodo9();
			break;
		case 10:
			metodo10();
			break;
		default:
			exit(1);
			break;
	}
	IO_pause("\n\nApertar ENTER para continuar.");
	system("clear");
	select();
}

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] ) {
	select();
} // fim main( )


// limpar a entrada de dados // aguardar por ENTER
// voltar ao SO (sem erros)
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/
