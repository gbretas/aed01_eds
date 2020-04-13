/*
Exemplo0111 - v0.0. - 
__ / __ / _____ Author: 689655 Gustavo Torres Bretas Alves
*/
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <math.h>
	/* 
	Calculo de metade da area de um quadrado
	*/
	void metodo1(){
		double lado;
		double metadearea;
		printf("1 - Calculo com area do quadrado \n\n");
		printf("Digite um valor inteiro: ");
		scanf("%lf", &lado);
		metadearea = ((lado * lado) / 2 );
		printf("\n\nSupondo que o valor inserido seja o lado de um quadrado, a metade da area vale: %lf", (double)metadearea);
		
	}

	/* 
	Calculo de metade da area de um quadrado
	*/
	void metodo2(){
		double lado;
		double area;
		double perimetro;
		printf("2 - Calculo com area, perimetro \n\n");
		printf("Digite um valor inteiro: ");
		scanf("%lf", &lado);
		lado = lado * 2;
		area = lado * lado;
		perimetro = lado * 4;
		
		printf("\n\nA area de um quadrado com o dobro de lado equivale a: %lf\n", (double)area);
		printf("\n\nO perimetro de um quadrado com o dobro de lado equivale a: %lf\n", (double)perimetro);
		
	}
	/* 
	Calculo de um terco da area de um retangulo
	*/
	void metodo3(){
		double lado1;
		double lado2;
		printf("3 - Calculo de um terco da area de um retangulo \n\n");
		printf("Digite um valor inteiro: ");
		scanf("%lf", &lado1);
		printf("Digite outro valor inteiro: ");
		scanf("%lf", &lado2);
		printf("\n\nO terco da area desse retangulo vale: %lf\n", (lado1*lado2)/3);
	}
	/* 
	Calculo de area e permimetro de um retangulo
	*/
	void metodo4(){
		double lado1;
		double lado2;
		printf("4 - Calculo de area e permimetro de um retangulo \n\n");
		printf("Digite um valor inteiro para lado: ");
		scanf("%lf", &lado1);
		printf("Digite outro valor inteiro para lado: ");
		scanf("%lf", &lado2);
		lado1 = lado1 * 2;
		lado2 = lado2 * 2;
		printf("\n\nA area de um retangulo com o dobro do lado vale: %lf\n", (lado1 * lado2)  );
		printf("\nO perimetro de um retangulo com o dobro do lado vale: %lf\n", (lado1 + lado1 + lado2 + lado2)  );
	}
	/* 
	Calculo de area de um triangulo
	*/
	void metodo5(){
		double base;
		double altura;
		printf("5 - Calculo de area de um triangulo \n\n");
		printf("Digite um valor inteiro para base: ");
		scanf("%lf", &base);
		printf("Digite outro valor inteiro para altura: ");
		scanf("%lf", &altura);
		printf("\n\nA area de um triangulo com a metade da altura é: %lf\n", ( (altura / 2) * base ) / 2  );
	}
	/* 
	Calculo de area de um triangulo
	*/
	void metodo6(){
		double lado;
		printf("6 - Calculo de area de um triangulo equilatero \n\n");
		printf("Digite valor inteiro para lado: ");
		scanf("%lf", &lado);
		printf("\n\nA altura de um triangulo equilatero e: %lf\n",  (lado * sqrt(3) ) / 2 );
		printf("A Area e: %lf\n", ( ( lado ) * lado ) / 2 );
		printf("O perimetro e: %lf\n", lado*3  );
	}
	/* 
	Calculo volume do solido com um quarto da medida do lado
	*/
	void metodo7(){
		double lado;
		printf("7 - Calculo volume do solido com um quarto da medida do lado \n\n");
		printf("Digite valor inteiro para lado: ");
		scanf("%lf", &lado);
		lado = lado / 4;
		printf("\n\nO volume e igual a %lf\n",  lado*lado*lado );
	}
	/*
	8 - Calculo volume do solido com a metade desses valores
	*/

	void metodo8(){
		double comprimento, largura, altura;
		printf("8 - Calculo volume do solido com a metade desses valores \n\n");
		printf("Digite valor inteiro para comprimento: ");
		scanf("%lf", &comprimento);
		printf("Digite valor inteiro para largura: ");
		scanf("%lf", &largura);
		printf("Digite valor inteiro para altura: ");
		scanf("%lf", &altura);
		printf("\n\nO volume e igual a %lf\n",  ((comprimento/2)*(largura/2)*(altura/2)) );
	}

	/*
	9 - area de um circulo com o dobro do raio.
	*/

	void metodo9(){
		double raio;
		printf("9 - area de um circulo com o dobro do raio. \n\n");
		printf("Digite valor inteiro para raio: ");
		scanf("%lf", &raio);
		printf("\n\nA area do ciruclo com o dobro do raio e %lf\n",  (M_PI * raio * raio) );
	}

	/*
	10 - calcular e mostrar o volume de uma esfera com um oitavo do raio.
	*/

	void metodo10(){
		double raio;
		printf("10 - Calcular e mostrar o volume de uma esfera com um oitavo do raio. \n\n");
		printf("Digite valor inteiro para raio: ");
		scanf("%lf", &raio);
		printf("\n\nVolume esfera com um oitavo do raio %lf\n",  (4/3 * M_PI * (raio/8) * (raio/8) * (raio/8)) );
	}

	void select() {
		int atividade;
		printf ( "%s\n", "ED01 - 689655 Gustavo Torres Bretas Alves - v0.0\n" );
		printf("1 - Calculo com area do quadrado \n");
		printf("2 - Calculo com area, perimetro \n");
		printf("3 - Calculo de um terco da area de um retangulo \n");
		printf("4 - Calculo de area e permimetro de um retangulo \n");
		printf("5 - Calculo de area de um triangulo \n");
		printf("6 - Calculo de area de um triangulo equilatero \n");
		printf("7 - Calculo volume do solido com um quarto da medida do lado \n");
		printf("8 - Calculo volume do solido com a metade desses valores \n");
		printf("9 - Area de um circulo com o dobro do raio. \n");
		printf("10 - Calcular e mostrar o volume de uma esfera com um oitavo do raio. \n");
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