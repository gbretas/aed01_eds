/*
ED06 - 28/04/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"

/*
 
*/
void metodo1(){}

/*
 
*/
void metodo2(){}

/*
 
*/
void metodo3(){}

/*
 
*/
void metodo4(){}

/*
 
*/
void metodo5(){}

/*
 
*/
void metodo6(){}

/*
 
*/
void metodo7(){}

/*
 
*/
void metodo8(){}

/*
 
*/
void metodo9(){}

/*
 
*/
void metodo10(){}

/*
 
*/
void extra1(){}

/*
 
*/
void extra2(){}

void select() {
    int atividade;
    IO_id("ED06 - 28 abr 2020");

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
    IO_printf("11 - Extra 1 \n");
    IO_printf("12 - Extra 2 \n");
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

--------------------------
Metodo 2:

--------------------------
Metodo 3:

--------------------------
Metodo 4:

--------------------------
Metodo 5:

--------------------------
Metodo 6:

--------------------------
Metodo 7:

--------------------------
Metodo 8:

--------------------------
Metodo 9:

--------------------------
Metodo 10:

--------------------------
Metodo Extra 1:

--------------------------
Metodo Extra 2:

--------------------------
*/
