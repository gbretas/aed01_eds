/*
ED02 - v0.0. -
24/03/2020 Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"
	/* 
	Mostrar letras maiusculas
	*/
	void metodo1(){
		char palavra[24];
		int tamanho;
		printf("1 - Mostrar letras maiusculas de uma palavra \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);

		tamanho = strlen(palavra) - 1;
		for (size_t i = 0; i < tamanho; i++)
		{
			if(isupper(palavra[i]) ){
				printf("%c", palavra[i]);
			}
		}
	}

	/* 
	Contar e mostrar letras maiusculas
	*/
	void metodo2(){
       char palavra[24];
		int tamanho, maiusculas = 0;
		printf("2 - Contar e mostrar letras maiusculas de uma palavra \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");

		tamanho = strlen(palavra);
		for (size_t i = 0; i < tamanho; i++)
		{
			if(isupper(palavra[i]) ){
				maiusculas++;
				printf("%c", palavra[i]);
			}
		}
		IO_printf("\nA palavra %s possui %i letras maiusculas", palavra, maiusculas);
	}
	/* 
	Contar e mostrar letras maiusculas de uma palavra (Fim para inicio)
	*/
	void metodo3(){
		char palavra[24];
		int tamanho, maiusculas = 0;
		printf("3 - Contar e mostrar letras maiusculas de uma palavra (Fim para inicio) \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");

		tamanho = strlen(palavra) -1;
		
		
		for (int i = tamanho; i >= 0; i = i-1)
		{
			if(isupper(palavra[i]) ){
				maiusculas++;
				printf("%c", palavra[i]);
			}
		}
		IO_printf("\nA palavra %s possui %i letras maiusculas", palavra, maiusculas);
		
	}
	/* 
	Contar e mostrar letras maiusculas e minuscula de uma palavra
	*/
	void metodo4(){
		char palavra[24];
		int tamanho, maiusculas = 0, letras = 0, minusculas = 0;
		printf("4 - Contar e mostrar letras maiusculas e minuscula de uma palavra \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");

		tamanho = strlen(palavra);
		printf("Palavras Maiusculas: \n");
		for (size_t i = 0; i < tamanho; i++)
		{
			if(isupper(palavra[i]) && isalpha(palavra[i]) ){
				maiusculas++;
				printf("%c", palavra[i]);
			}
		}
		printf("\n\nPalavras Minusculas: \n");
		for (size_t i = 0; i < tamanho; i++)
		{
			if(islower(palavra[i]) && isalpha(palavra[i])){
				minusculas++;
				printf("%c", palavra[i]);
			}
		}
		printf("\n\nLetras: \n");
		for (size_t i = 0; i < tamanho; i++)
		{
			if(isalpha(palavra[i])){
				letras++;
				printf("%c", palavra[i]);
			}
		}
		
		IO_printf(
			"\n\nA palavra %s possui %i letras, %i letras maiusculas e %i letras minusculas", 
			palavra, letras, maiusculas, minusculas
		);
		
        
	}
	/* 
	Contar e mostrar todos digitos de uma palavra (Fim para inicio)
	*/
	void metodo5(){
		char palavra[24];
		int tamanho, digitos = 0;
		printf("5 - Contar e mostrar todos digitos de uma palavra (Fim para inicio) \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");

		tamanho = strlen(palavra) -1;
		
		
		for (int i = tamanho; i >= 0; i = i-1)
		{
			if(isdigit(palavra[i]) ){
				digitos++;
				printf("%c", palavra[i]);
			}
		}
		IO_printf("\nA palavra %s possui %i digitos", palavra, digitos);
	}
	/* 
	6 - Contar e mostrar tudo que nao for digito e nem letra
	*/
	void metodo6(){
		char palavra[24];
		int tamanho, especiais = 0;
		printf("6 - Contar e mostrar tudo que nao for digito e nem letra \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");

		tamanho = strlen(palavra) -1;
		
		
		for (int i = 0; i < tamanho; i++)
		{
			if(!isdigit(palavra[i]) && !isalpha(palavra[i])  ){
				especiais++;
				printf("%c", palavra[i]);
			}
		}
		IO_printf("\nA palavra %s possui %i caracteres especiais", palavra, especiais);
		
	}
	/* 
	Verificar numeros multiplos de 3
	*/
	void metodo7(){
		int intervalo[2];
        int valor[255];
		int qntd_multiplo = 0;
		int qntd_valores;
        printf("7 - Verificar numeros multiplos de 3 \n\n");
		intervalo[0] = IO_readint("Digite o primeiro número do intervalo: ");
		intervalo[1] = IO_readint("Digite o segundo número do intervalo: ");
		if(intervalo[1] <= intervalo[0]){
			IO_print("\nO intervalo 1 deve ser maior que o intervalo 2");
			return;
		}
		qntd_valores = IO_readint("Digite a quantidade de valores a serem lidos: ");
		IO_print("\n");
		for (int i = 0; i < qntd_valores; i++)
		{
			IO_printf("Digite o valor de index %i: ", i);
			valor[i] = IO_readint("");
		}
		IO_print("\n");
		IO_printf("Voce digitou %i valores e esses sao multipos de 3: (", qntd_valores);
		for (int i = 0; i < qntd_valores; i++)
		{
			if(valor[i] % 3 == 0){
				qntd_multiplo++;
				IO_printf("%i, ", valor[i]);
			}
		}
		IO_printf("). %i numeros", qntd_multiplo);
	}
	/*
	8 - Verificar numeros multiplos de 5 que nao sao de 7
	*/

	void metodo8(){
       	int intervalo[2];
        int valor[255];
		int qntd_multiplo = 0;
		int qntd_valores;
        printf("8 - Verificar numeros multiplos de 5 que nao sao de 7 \n\n");
		intervalo[0] = IO_readint("Digite o primeiro número do intervalo: ");
		intervalo[1] = IO_readint("Digite o segundo número do intervalo: ");
		if(intervalo[1] <= intervalo[0]){
			IO_print("\nO intervalo 1 deve ser maior que o intervalo 2");
			return;
		}
		qntd_valores = IO_readint("Digite a quantidade de valores a serem lidos: ");
		IO_print("\n");
		for (int i = 0; i < qntd_valores; i++)
		{
			IO_printf("Digite o valor de index %i: ", i);
			valor[i] = IO_readint("");
		}
		IO_print("\n");
		IO_printf("Voce digitou %i valores e esses sao multipos de 5 e nao sao de 7: (", qntd_valores);
		for (int i = 0; i < qntd_valores; i++)
		{
			if( (valor[i] % 5 == 0) && (valor[i] % 7 != 0) ){
				qntd_multiplo++;
				IO_printf("%i, ", valor[i]);
			}
		}
		IO_printf("). %i numeros", qntd_multiplo);
	}

	/*
	9 - Verificar numeros multiplos pertencentes ao intervalo pares
	*/

	void metodo9(){
		double intervalo[2];
        double valor[255];
		int qntd_multiplo = 0;
		int qntd_valores;
        printf("9 - Verificar numeros multiplos pertencentes ao intervalo pares \n\n");
		intervalo[0] = IO_readdouble("Digite o primeiro número do intervalo: ");
		intervalo[1] = IO_readdouble("Digite o segundo número do intervalo: ");
		if(intervalo[1] <= intervalo[0]){
			IO_print("\nO intervalo 1 deve ser maior que o intervalo 2");
			return;
		}
		qntd_valores = IO_readdouble("Digite a quantidade de valores a serem lidos: ");
		IO_print("\n");
		for (int i = 0; i < qntd_valores; i++)
		{
			IO_printf("Digite o valor de index %i: ", i);
			valor[i] = IO_readdouble("");
		}
		IO_print("\n");
		IO_printf("Voce digitou %i valores e esses estao dentro do intervalo e suas partes inteira sao pares: (", qntd_valores);
		for (int i = 0; i < qntd_valores; i++)
		{
			if( ((int)valor[i] % 2 == 0) && ((int)valor[i] > intervalo[0]) && ((int)valor[i] < intervalo[1]) ){
				qntd_multiplo++;
				IO_printf("%lf, ", valor[i]);
			}
		}
		IO_printf("). %i numeros", qntd_multiplo);
	}

	/*
	10 - dizer se o primeiro não está entre os outros dois primeiros quando todos forem diferentes entre si.
	*/

	void metodo10(){
       double intervalo[2];
        double valor[255];
		int qntd_multiplo = 0;
		int qntd_valores;
        printf("1 - Verificar numeros com intervalos maior que 0 e maior que 1 \n\n");
		intervalo[0] = IO_readdouble("Digite o primeiro número do intervalo: ");
		intervalo[1] = IO_readdouble("Digite o segundo número do intervalo: ");
		if(intervalo[1] <= intervalo[0]){
			IO_print("\nO intervalo 1 deve ser maior que o intervalo 2");
			return;
		}
		if(intervalo[0] < 0.0 || intervalo[1] > 1.0){
			IO_print("\nOs intervalos devem estar entre 0 e 1");
			return;
		}
		qntd_valores = IO_readdouble("Digite a quantidade de valores a serem lidos: ");
		IO_print("\n");
		for (int i = 0; i < qntd_valores; i++)
		{
			IO_printf("Digite o valor de index %i: ", i);
			valor[i] = IO_readdouble("");
		}
		IO_print("\n");
		IO_printf("Voce digitou %i valores e esses suas partes fracionarias estao fora do intervalo: (", qntd_valores);
		for (int i = 0; i < qntd_valores; i++)
		{
			if( valor[i] < intervalo[0] || valor[i] > intervalo[1] ){
				qntd_multiplo++;
				IO_printf("%lf, ", valor[i]);
			}
		}
		IO_printf("). %i numeros", qntd_multiplo);
	}

	void metodo11(){
		char outra[24];
		char palavra[24];
		int tamanho, especiais = 0;
		printf("E1 - Contar e mostrar tudo que nao for alfanumerico \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");
		for (int i = 0; i < sizeof(palavra); i++)
		{
			outra[i] = palavra[i];
		}
		
		tamanho = strlen(outra);
		
		
		for (int i = 0; i < tamanho; i++)
		{
			if(!isalpha(outra[i])  ){
				especiais++;
				printf("%c", outra[i]);
			}
		}
		IO_printf("\nA palavra %s possui %i caracteres especiais", outra, especiais);
		

	}

	void metodo12(){
		char palavra[24];
		int tamanho, especiais = 0;
		printf("12 - Verificar se a sequencia possui apenas simbolos que nao são letras \n\n");
		printf("Digite uma palavra: ");
		scanf("%s", palavra);
		IO_print("\n");
		
		tamanho = strlen(palavra);
		
		
		for (int i = 0; i < tamanho; i++)
		{
			if(isalpha(palavra[i])  ){
				especiais++;
			}
		}
		if(especiais > 0){
			IO_printf("\nA palavra %s possui letras", palavra);
		}else{
			IO_printf("\nA palavra %s nao possui letras", palavra);
		}
		
		

	}


	void select() {
		int atividade;
		IO_id("ED03 - 31 mar 2020");
		
		printf("1 - Mostrar letras maiusculas de uma palavra \n");
		printf("2 - Contar e mostrar letras maiusculas de uma palavra \n");
		printf("3 - Contar e mostrar letras maiusculas de uma palavra (Fim para inicio) \n");
		printf("4 - Contar e mostrar letras maiusculas e minuscula de uma palavra \n");
		printf("5 - Contar e mostrar todos digitos de uma palavra (Fim para inicio)\n");
		printf("6 - Contar e mostrar tudo que nao for digito e nem letra \n");
		printf("7 - Verificar numeros multiplos de 3 \n");
		printf("8 - Verificar numeros multiplos de 5 que nao sao de 7 \n");
		printf("9 - Verificar numeros multiplos pertencentes ao intervalo pares \n");
		printf("10 - Dizer se o primeiro não está entre os outros dois... \n");
		printf("11 - E1  - Contar e mostrar tudo que nao for alfanumerico  \n");
		printf("12 - E2 - Dizer se o primeiro não está entre os outros dois... \n");
        
		printf("0 - Finalizar o programa \n\n");
		atividade = IO_readint("Digite qual atividade você deseja executar: ");
		printf("\n\n");
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
			case 11:
				metodo11();
				break;
			case 12:
				metodo12();
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
	// definir dados
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
