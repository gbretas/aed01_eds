/*
ED06 - 28/04/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"
int teste = 1; //1 para executar os metodos em versão teste - 0 para solicitar entradas
int testes = 0;
/*
Funcoes
*/
void impares_maiores(int qntd, int numero){
    if (qntd > 0 ){
        if(numero % 2 == 1){
            printf("%i ", numero);
            qntd = qntd - 1;
            impares_maiores(qntd, numero + 2);
        }
    }
}

void multiplos_3_decres_terminando_3(int qntd, int mostrados, int numero){
    int limite_superior = 0;
    limite_superior = (qntd * 3);
    if(mostrados < qntd){
        if(numero == 0){
            numero = limite_superior;
        }
        while (numero % 3 != 0){
            numero = numero - 1;
        }
        if(numero % 3 == 0){
            mostrados = mostrados + 1;
            IO_printf("%i ", numero);
            numero = numero - 1;
            multiplos_3_decres_terminando_3(qntd, mostrados, numero);
        }
    }
}

void sequencia_1_5(int qntd, int mostrados, int numero){
    if (mostrados < qntd){
        IO_printf("%i ", numero);
        if(numero == 1){
            numero = numero+4;
        }else{
            numero = numero+5;
        }
        ++mostrados;
        sequencia_1_5(qntd, mostrados, numero);
    }
}

void sequencia_1_sobre_3exponencial(int qntd, int mostrados, int numero){
    int limite_superior = pow(3, qntd + 1);
    if(mostrados < qntd){
        numero = pow(3, ( qntd - 1 - mostrados));
        IO_printf("1/%i ", numero);
        ++mostrados;
        
        sequencia_1_sobre_3exponencial(qntd, mostrados, numero);
    }
}

void mostrar_simbolos(chars cadeia, int x){
    if( x < strlen(cadeia) ){
        IO_printf("%c ", cadeia[x]);
        x++;
        mostrar_simbolos(cadeia, x);
    }
}

void soma_impares_tres(int qntd, int somados, int soma, int numero){
    if(somados < qntd){
        IO_printf("%i + ", numero);
        numero = numero + 2;
        soma = soma + numero;
        somados++;
        soma_impares_tres(qntd, somados, soma, numero);
        if(somados == qntd){
            IO_printf ("= %i", soma);
        }
        
    }
    
}

void soma_inversos_impares_tres(int qntd, int somados, double soma, int numero){
    if(somados < qntd){
        IO_printf("1/%i + ", numero);
        soma = (double)soma + (1.0/(double)numero);
        numero = numero + 2;
        somados++;
        soma_inversos_impares_tres(qntd, somados, soma, numero);
        if(somados == qntd){
            IO_printf ("= %lf", soma);
        }
        
    }
    
}

bool is_par(int num){
    bool result = false;
    if(num % 2 == 0){
        result = true;
    }
    return result;
}


int termo_fibonacci(int valor, int primeiro, int soma, int i){
	if(i < valor){
		soma = soma + primeiro;
		primeiro = soma - primeiro;
		if(soma % 2 == 0){
			i = i + 1;
		}
		soma = termo_fibonacci(valor, primeiro, soma, i);
	}
	return soma;
}

int pares = 0;
void contar_pares(chars cadeia, int posicao){
    if(posicao < strlen(cadeia)){
        if(isdigit(cadeia[posicao])){
           if(is_par(cadeia[posicao])){
            ++pares;
           }
        }
        posicao++;
        contar_pares( cadeia,  posicao);
    }
}

void contar_pares_a(chars cadeia, int posicao){
    contar_pares(cadeia, posicao);
    IO_printf("%i numeros pares nessa cadeia de caracteres", pares);
    pares = 0;
}

int maiusculas = 0;
void contar_maiusculas(chars cadeia, int posicao){
    if(posicao < strlen(cadeia)){
        if(isalpha(cadeia[posicao])){
           if(isupper(cadeia[posicao])){
            maiusculas++;
           }
        }
        posicao++;
        contar_maiusculas( cadeia,  posicao);
    }
}

void contar_maiusculas_a(chars cadeia, int posicao){
    contar_maiusculas(cadeia, posicao);
    IO_printf("%i letras maiusculas nessa cadeia de caracteres", maiusculas);
    maiusculas = 0;
}
/*
01.) Incluir em um programa (Exemplo0611) um método para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores ímpares em ordem crescente começando em 5.
*/
void metodo1(){
    int qntd = 0;

    IO_id("Método 1");
    /* Testes */
    srand(time(0));
    if (teste){
        while(teste){
            qntd = 1+ rand() % 20;
            printf("%i: ", qntd);
            impares_maiores(qntd, 5);
            IO_line();
            testes++;
            if(testes == 10){
                teste = false;
                teste = true;
            }
        }
        testes = 0;
    }else{
        qntd = IO_readint("Digite uma quantidade de números a serem exibidos: ");
        impares_maiores(qntd, 5);
    }
}

/*
02.) Incluir em um programa (Exemplo0612) um método para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em múltiplos de 3 em ordem decrescente encerrando em 3.
*/
void metodo2(){
    IO_id("Método 2");
    int qntd;
    srand(time(0));
    if (teste){
        while(teste){
            qntd = 1+ rand() % 20;
            printf("%i: ", qntd);
            multiplos_3_decres_terminando_3(qntd, 0, 0);
            IO_line();
            testes++;
            if(testes == 10){
                teste = false;
            }
        }
        testes = 0;
        teste = true;
    }else{
        qntd = IO_readint("Digite uma quantidade de números a serem exibidos: ");
        multiplos_3_decres_terminando_3(qntd, 0, 0);
    }
   
}

/*
03.) Incluir em um programa (Exemplo0613) um método para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores da sequência: 1 5 10 15 ...
*/
void metodo3(){
    IO_id("Método 3");
    int qntd;
    srand(time(0));
    if (teste){
        while(teste){
            qntd = 1+ rand() % 20;
            printf("%i: ", qntd);
            sequencia_1_5(qntd, 0, 1);
            IO_line();
            testes++;
            if(testes == 10){
                teste = false;
            }
        }
        testes = 0;
        teste = true;
    }else{
        qntd = IO_readint("Digite uma quantidade de números a serem exibidos: ");
        sequencia_1_5(qntd, 0, 1);
    }
}

/*
04.) Incluir em um programa (Exemplo0614) um método para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores decrescentes da sequência: ... 1/81 1/27 1/9 1/3 1.
*/
void metodo4(){
    IO_id("Método 4");
    int qntd;
    srand(time(0));
    if (teste){
        while(teste){
            qntd = 1+ rand() % 20;
            printf("%i: ", qntd);
            sequencia_1_sobre_3exponencial(qntd, 0, 0);
            IO_line();
            testes++;
            if(testes == 10){
                teste = false;
            }
        }
        testes = 0;
        teste = true;
    }else{
        qntd = IO_readint("Digite uma quantidade de números a serem exibidos: ");
        sequencia_1_sobre_3exponencial(qntd, 0, 0);
    }
}

/*
05.) Incluir em um programa (Exemplo0615) um método para
ler uma cadeia de caracteres e chamar procedimento recursivo para
mostrar cada símbolo separadamente, um por linha.
*/
void metodo5(){
    IO_id("Método 5");
    chars cadeia = 0;
    cadeia = IO_readstring("Digite uma cadeia de caracteres: ");
    mostrar_simbolos(cadeia, 0);
}

/*
06.) Incluir em um programa (Exemplo0616) uma função recursiva para
calcular a soma dos primeiros valores ímpares positivos começando em 3.
Testar essa função para quantidades diferentes.
*/
void metodo6(){
    IO_id("Método 6");
    int qntd;
    srand(time(0));
    if (teste){
        while(teste){
            qntd = 1+ rand() % 20;
            printf("%i: ", qntd);
            soma_impares_tres(qntd, 0, 0, 3);
            IO_line();
            testes++;
            if(testes == 10){
                teste = false;
            }
        }
        testes = 0;
        teste = true;
    }else{
        qntd = IO_readint("Digite uma quantidade de números a serem exibidos: ");
        soma_impares_tres(qntd, 0, 0, 3);
    }
}
/*
07.) Incluir em um programa (Exemplo0617) uma função recursiva para
calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos começando em 3.
Testar essa função para quantidades diferentes
*/
void metodo7(){
    IO_id("Método 7");
    int qntd;
    srand(time(0));
    if (teste){
        while(teste){
            qntd = 1+ rand() % 20;
            printf("%i: ", qntd);
            soma_inversos_impares_tres(qntd, 0, 0, 3);
            IO_line();
            testes++;
            if(testes == 10){
                teste = false;
            }
        }
        testes = 0;
        teste = true;
    }else{
        qntd = IO_readint("Digite uma quantidade de números a serem exibidos: ");
        soma_inversos_impares_tres(qntd, 0, 0, 3);
    }
}

/*
08.) Incluir em um programa (Exemplo0618) uma função recursiva para
calcular certo termo par da série de Fibonacci começando em 1.
Testar essa função para quantidades diferentes.
DICA: Separar o cálculo do termo e o teste para verificar se é par.
*/
void metodo8(){
    IO_id("Metodo 8");
    int termo, i =0;
    termo = IO_readint("Digite um numero para sequência fibonacci: ");
    IO_printf("O %i termo par e %i", termo, termo_fibonacci(termo, 0 , 1 , i));

}
/*
09.) Incluir em um programa (Exemplo0619) uma função recursiva para
contar os dígitos com valores pares em uma cadeia de caracteres.
Testar essa função para cadeias de diferentes tamanhos.
*/
void metodo9(){
    IO_id("Método 9");
    chars cadeia = 0;
    cadeia = IO_readstring("Digite uma cadeia de caracteres: ");
    contar_pares_a(cadeia, 0);
}

/*
10.) Incluir em um programa (Exemplo0620) uma função recursiva para
calcular a quantidade de maiúsculas em uma cadeia de caracteres.
Testar essa função para cadeias de diferentes tamanhos.
*/
void metodo10(){
    IO_id("Método 10");
    chars cadeia = 0;
    cadeia = IO_readstring("Digite uma cadeia de caracteres: ");
    contar_maiusculas_a(cadeia, 0);
}

void extra1(){}

void extra2(){}

void select() {
    int atividade;
    IO_id("ED06 - 28 abr 2020");

    IO_printf("0  -  Sair \n");
    IO_printf("1  -  Exemplo 1 \n");
    IO_printf("2  -  Exemplo 2 \n");
    IO_printf("3  -  Exemplo 3 \n");
    IO_printf("4  -  Exemplo 4 \n");
    IO_printf("5  -  Exemplo 5 \n");
    IO_printf("6  -  Exemplo 6 \n");
    IO_printf("7  -  Exemplo 7 \n");
    IO_printf("8  -  Exemplo 8 \n");
    IO_printf("9  -  Exemplo 9 \n");
    IO_printf("10 -  Exemplo 10 \n");
    IO_printf("11 -  Extra 1 \n");
    IO_printf("12 -  Extra 2 \n");
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
        case 11:
            extra1();
            break;
        case 12:
            extra2();
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
}



/*
--------------------------  Testes -------------------------- 
Metodo 1:
5: 5 7 9 11 13 
14: 5 7 9 11 13 15 17 19 21 23 25 27 29 31 
14: 5 7 9 11 13 15 17 19 21 23 25 27 29 31 
14: 5 7 9 11 13 15 17 19 21 23 25 27 29 31 
3: 5 7 9 
20: 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 
14: 5 7 9 11 13 15 17 19 21 23 25 27 29 31 
9: 5 7 9 11 13 15 17 19 21 
10: 5 7 9 11 13 15 17 19 21 23 
19: 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41

--------------------------
Metodo 2:

13: 39 36 33 30 27 24 21 18 15 12 9 6 3 
1: 3 
2: 6 3 
8: 24 21 18 15 12 9 6 3 
12: 36 33 30 27 24 21 18 15 12 9 6 3 
7: 21 18 15 12 9 6 3 
16: 48 45 42 39 36 33 30 27 24 21 18 15 12 9 6 3 
7: 21 18 15 12 9 6 3 
1: 3 
14: 42 39 36 33 30 27 24 21 18 15 12 9 6 3 

--------------------------
Metodo 3:
4: 1 5 10 15 
6: 1 5 10 15 20 25 
2: 1 5 
7: 1 5 10 15 20 25 30 
20: 1 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 
3: 1 5 10 
17: 1 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 
6: 1 5 10 15 20 25 
18: 1 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 
6: 1 5 10 15 20 25 

--------------------------
Metodo 4:

14: 1/1594323 1/531441 1/177147 1/59049 1/19683 1/6561 1/2187 1/729 1/243 1/81 1/27 1/9 1/3 1/1 
6: 1/243 1/81 1/27 1/9 1/3 1/1 
5: 1/81 1/27 1/9 1/3 1/1 
15: 1/4782969 1/1594323 1/531441 1/177147 1/59049 1/19683 1/6561 1/2187 1/729 1/243 1/81 1/27 1/9 1/3 1/1 
4: 1/27 1/9 1/3 1/1 
6: 1/243 1/81 1/27 1/9 1/3 1/1 
6: 1/243 1/81 1/27 1/9 1/3 1/1 
3: 1/9 1/3 1/1 
12: 1/177147 1/59049 1/19683 1/6561 1/2187 1/729 1/243 1/81 1/27 1/9 1/3 1/1 
1: 1/1 

--------------------------
Metodo 5:

teste: t e s t e 
gustavo: g u s t a v o
gust@v@: g u s t @ v @ 
gus1@v@: g u s 1 @ v @ 

--------------------------
Metodo 6:

20: 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21 + 23 + 25 + 27 + 29 + 31 + 33 + 35 + 37 + 39 + 41 + = 480
5: 3 + 5 + 7 + 9 + 11 + = 45
6: 3 + 5 + 7 + 9 + 11 + 13 + = 60
16: 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21 + 23 + 25 + 27 + 29 + 31 + 33 + = 320
17: 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21 + 23 + 25 + 27 + 29 + 31 + 33 + 35 + = 357
4: 3 + 5 + 7 + 9 + = 32
16: 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21 + 23 + 25 + 27 + 29 + 31 + 33 + = 320
6: 3 + 5 + 7 + 9 + 11 + 13 + = 60
11: 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19 + 21 + 23 + = 165
5: 3 + 5 + 7 + 9 + 11 + = 45

--------------------------
Metodo 7:

5: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + = 0.878211
16: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + 1/23 + 1/25 + 1/27 + 1/29 + 1/31 + 1/33 + = 1.398434
8: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + = 1.080624
19: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + 1/23 + 1/25 + 1/27 + 1/29 + 1/31 + 1/33 + 1/35 + 1/37 + 1/39 + = 1.479673
17: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + 1/23 + 1/25 + 1/27 + 1/29 + 1/31 + 1/33 + 1/35 + = 1.427005
2: 1/3 + 1/5 + = 0.533333
10: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + = 1.180875
13: 1/3 + 1/5 + 1/7 + 1/9
 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + 1/23 + 1/25 + 1/27 + = 1.301390
20: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + 1/23 + 1/25 + 1/27 + 1/29 + 1/31 + 1/33 + 1/35 + 1/37 + 1/39 + 1/41 + = 1.504063
17: 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/13 + 1/15 + 1/17 + 1/19 + 1/21 + 1/23 + 1/25 + 1/27 + 1/29 + 1/31 + 1/33 + 1/35 + = 1.427005
--------------------------
Metodo 8:

--------------------------
Metodo 9:
2446: 4 numeros pares nessa cadeia de caracteres
2444444444446: 13 numeros pares nessa cadeia de caracteres
236: 2 numeros pares nessa cadeia de caracteres
1135: 0 numeros pares nessa cadeia de caracteres
--------------------------
Metodo 10:
AaAa: 2 letras maiusculas nessa cadeia de caracteres
AaAA: 3 letras maiusculas nessa cadeia de caracteres
AAAA: 4 letras maiusculas nessa cadeia de caracteres
gustavo: 0 letras maiusculas nessa cadeia de caracteres
gust@vo: 0 letras maiusculas nessa cadeia de caracteres
GuST@vo: 3 letras maiusculas nessa cadeia de caracteres
--------------------------
Metodo Extra 1:

--------------------------
Metodo Extra 2:

--------------------------
*/
