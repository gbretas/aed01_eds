/*
ED02 - v0.0. -
24/03/2020 Author: 689655 Gustavo Torres Bretas Alves
*/
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <math.h>
	/* 
	Verificar paridade de um numero
	*/
	void metodo1(){
		int valor;
		printf("1 - Verificar paridade de um numero \n\n");
		printf("Digite um valor inteiro: ");
		scanf("%i", &valor);
        if(valor % 2 == 0){
            printf("\n\nO numero %i e par", valor);
        }else{
            printf("\n\nO numero %i e impar", valor);
        }
	}

	/* 
	Par e menor que -100 ou impar e maior que 100
	*/
	void metodo2(){
        int valor;
        printf("2 - Par e menor que -100 ou impar e maior que 100 \n\n");
        printf("Digite um valor inteiro: ");
        scanf("%i", &valor);
        
        if(valor % 2 == 0 && valor < -100){
            printf("\n\nO numero %i e par e menor que -100", valor);
        }else if(valor % 2 != 0 && valor > 100){
            printf("\n\nO numero %i e impar e maior que 100", valor);
        }else{
            printf("\n\nO numero %i nao se enquadra em nenhum intervalo", valor);
        }
		
	}
	/* 
	intervalo aberto entre (30:75)
	*/
	void metodo3(){
		int valor;
		printf("3 - Verificar se pertence ao intervalo aberto (30:75) \n\n");
		printf("Digite um valor inteiro: ");
		scanf("%i", &valor);
        if(valor > 30 && valor < 75){
            printf("%s%i%s", "\nO numero ", valor, " pertence ao intervalo aberto (30:75)");
        }else{
            printf("%s%i%s", "\nO numero ", valor, " nao pertence ao intervalo aberto (30:75)");
        }
        
		
	}
	/* 
	intervalo fechado [30:75]
	*/
	void metodo4(){
		int valor;
        printf("4 - Verificar se pertence ao intervalo fechado [30:75] \n\n");
        printf("Digite um valor inteiro: ");
        scanf("%i", &valor);
        if(valor >= 30 && valor <= 75){
            printf("%s%i%s", "\nO numero ", valor, " pertence ao intervalo fechado [30:75]");
        }else{
            printf("%s%i%s", "\nO numero ", valor, " nao pertence ao intervalo fechado [30:75]");
        }
        
        
	}
	/* 
	pertence aos intervalos fechados [20:45] ou [33:66], ou a apenas a um deles.
	*/
	void metodo5(){
		int valor;
        printf("5 - Verficar se pertence aos intervalos fechados [20:45] ou [33:66], ou a apenas a um deles. \n\n");
        printf("Digite um valor inteiro: ");
        scanf("%i", &valor);
        if(valor >= 20 && valor <= 45){
            printf("%s%i%s", "\nO numero ", valor, " pertence ao intervalo fechado [20:45]");
        }
        if(valor >= 33 && valor <= 66){
            printf("%s%i%s", "\nO numero ", valor, "s pertence ao intervalo fechado [33:66]");
        }
        if(valor < 20 || valor > 66){
            printf("%s%i%s", "\nO numero ", valor, " nao pertence a nenhum dos dois intervalos");
        }
	}
	/* 
	6 - Verificar paridade de dois numeros
	*/
	void metodo6(){
		int valor1, valor2;
		printf("6 - Verificar paridade de dois numeros \n\n");
		printf("Digite valor inteiro para verificar se e par: ");
		scanf("%i", &valor1);
        printf("\nDigite valor inteiro para verificar se e impar: ");
        scanf("%i", &valor2);
        
        printf("\n\n");
        if(valor1 % 2 == 0){
            printf("%s%i%s", "O primeiro valor: ", valor1, " e par\n");
        }else{
             printf("%s%i%s", "O primeiro valor: ", valor1, " nao e par\n");
        }
        if(valor2 % 2 != 0){
            printf("%s%i%s", "O segundo valor: ", valor1, " e impar\n");
        }else{
            printf("%s%i%s", "O segundo valor: ", valor1, " nao e impar\n");
        }
		
	}
	/* 
	Verificar paridade e se e positivo ou nao
	*/
	void metodo7(){
        int valor1, valor2;
        printf("7 - Verificar paridade e se e positivo ou nao \n\n");
        printf("Digite valor inteiro para verificar se e par e positivo: ");
        scanf("%i", &valor1);
        printf("\nDigite valor inteiro para verificar se e impar e negativo: ");
        scanf("%i", &valor2);
        
        printf("\n\n");
        if(valor1 % 2 == 0 && valor1 > 0){
            printf("%s", "O primeiro valor e' par e positivo\n");
        }else{
             printf("%s", "O primeiro valor nao e' par e positivo\n");
        }
        if(valor2 % 2 != 0 && valor2 < 0){
            printf("%s", "O segundo valor e' impar e negativo\n");
        }else{
            printf("%s", "O segundo valor nao e' impar e negativo\n");
        }
     
        
		
	}
	/*
	8 - dizer se o primeiro e maior, menor ou igual ao segundo
	*/

	void metodo8(){
        int valor1, valor2;
        printf("8 - Dizer se o primeiro e maior, menor ou igual ao segundo \n\n");
        printf("Digite um valor inteiro: ");
        scanf("%i", &valor1);
        printf("\nDigite outro valor inteiro: ");
        scanf("%i", &valor2);
        
        printf("\n\n");
        if(valor1 > valor2){
            printf("%s", "O primeiro valor e' maior do que o segundo\n");
        }else if(valor1 < valor2){
             printf("%s", "O primeiro valor e' menor do que o segundo\n");
        }else{
            printf("%s", "O primeiro valor e' igual ao segundo\n");
        }
	}

	/*
	9 - dizer se o primeiro está entre os outros dois quando esses forem diferentes entre si
	*/

	void metodo9(){
		int valor1, valor2, valor3;
        printf("9 - Dizer se o primeiro está entre os outros dois... \n\n");
        printf("Digite um valor inteiro: ");
        scanf("%i", &valor1);
        printf("\nDigite outro valor inteiro: ");
        scanf("%i", &valor2);
        printf("\nDigite outro valor inteiro: ");
        scanf("%i", &valor3);
        
        printf("\n\n");
        if(valor2 != valor3){
            if (valor2 > valor3) {
                if( (valor1 < valor2) && (valor1 > valor3) ){
                     printf("%s", "O primeiro valor esta entre o segundo e terceiro\n");
                }else{
                    printf("%s", "O primeiro valor nao esta entre o segundo e terceiro\n");
                }
            }else{
                if( (valor1 > valor2) && (valor1 < valor3) ){
                     printf("%s", "O primeiro valor esta entre o terceiro e segundo\n");
                }else{
                    printf("%s", "O primeiro valor nao esta entre o terceiro e segundo\n");
                }
            }
           
        }else{
            printf("%s", "O segundo valor e' igual ao terceiro\n");
        }
	}

	/*
	10 - dizer se o primeiro não está entre os outros dois primeiros quando todos forem diferentes entre si.
	*/

	void metodo10(){
        int valor1, valor2, valor3;
        printf("10 - Dizer se o primeiro não está entre os outros dois... \n\n");
        printf("Digite um valor inteiro: ");
        scanf("%i", &valor1);
        printf("\nDigite outro valor inteiro: ");
        scanf("%i", &valor2);
        printf("\nDigite outro valor inteiro: ");
        scanf("%i", &valor3);
        
        printf("\n\n");
        if( (valor1 != valor2) && (valor1 != valor3) && (valor2 != valor3) ){
            
            if (  (valor1 > valor2 && valor1 < valor3)  || (valor1 > valor3 && valor1 < valor2) ) {
                     printf("%s", "O primeiro valor esta entre os outros dois\n");
            }else{
                    printf("%s", "O primeiro valor nao esta entre os outros dois\n");
                    
            }
            
            
            
        }else{
            printf("Os tres numeros fornecidos sao iguais\n");
        }
	}

	void select() {
		int atividade;
		printf ( "%s\n", "ED02 - 689655 Gustavo Torres Bretas Alves - v1.0\n" );
		printf("1 - Verificar paridade de um numero \n");
		printf("2 - Par e menor que -100 ou impar e maior que 100 \n");
		printf("3 - Verificar se pertence ao intervalo aberto (30:75) \n");
		printf("4 - Verificar se pertence ao intervalo fechado [30:75] \n");
		printf("5 - Verficar se pertence aos intervalos fechados [20:45] ou [33:66]\n");
		printf("6 - Verificar paridade de dois numeros \n");
		printf("7 - Verificar paridade e se e positivo ou nao \n");
		printf("8 - Dizer se o primeiro e maior, menor ou igual ao segundo \n");
		printf("9 - Dizer se o primeiro está entre os outros dois... \n");
		printf("10 - Dizer se o primeiro não está entre os outros dois... \n");
        
		printf("0 - Finalizar o programa \n\n");
		printf("Digite qual atividade você deseja executar: ");
		scanf("%i", &atividade);
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
			default:
				exit(1);
				break;
		}
		printf ( "\n\nApertar ENTER para continuar." );
		getchar();
		getchar();
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
