/*
ED07 - 03/05/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"


void write5impares ( chars fileName, int valor){
    int i = 0;
    int armaz = 0;
    int base = 5;
    FILE* arquivo = fopen ( fileName, "wt" );
    for (i = 0; i < valor; i++)
    {
        armaz = base * (i + 1);
        while(armaz % 2 == 0){
            i++;
            valor++;
            armaz = base * (i + 1);
        }
        fprintf ( arquivo, "%d\n", armaz );
    }
    
    fclose ( arquivo );
}

void readInts ( chars fileName )
{
    FILE* arquivo = fopen ( fileName, "rt" );
    int x = 0;
    fscanf ( arquivo, "%d", &x );
    while ( ! feof ( arquivo ) ){
        printf ( "%d\n", x );
        fscanf ( arquivo, "%d", &x );
    }

    fclose ( arquivo );
}

void readDoubles ( chars fileName )
{
    FILE* arquivo = fopen ( fileName, "rt" );
    int x = 0 ;
    int y = 1 ;
    double z = 0.0;
    fscanf ( arquivo, "%d", &x );
    while ( ! feof ( arquivo ) && y <= x ){
        fscanf ( arquivo, "%lf", &z );
        printf ( "%2d: %lf\n", y, z );
        y = y + 1;
    }
    fclose ( arquivo );
} 

/*
01.) Incluir em um programa (Exemplo0711) um método para
ler um valor inteiro do teclado e
gravar essa quantidade em múltiplos de 5, ímpares, em ordem crescente, começando em 5.
*/
void metodo1(){
    int valor;
    valor = IO_readint("Digite um valor inteiro: ");
    IO_line();
    write5impares("Exemplo0711.txt", valor);
}

/*
02.) Incluir em um programa (Exemplo0712) um método para
ler um valor inteiro do teclado e
gravar essa quantidade em múltiplos de 5, pares , em ordem decrescente encerrando em 10.
*/
void metodo2(){
    int limite_superior, i, qntd, valor;
    FILE* arquivo = fopen ( "Exemplo0712.txt", "wt" );

    qntd = IO_readint("Digite um valor inteiro: ");
    IO_line();

    limite_superior = (10 * qntd);
    valor = limite_superior;
    if(valor % 2 == 1){
        valor = valor - 5;
    }
    for (i = qntd; i <= qntd && i > 0 ; i--)
    {
        //IO_printf("%d\n", valor);
        fprintf ( arquivo, "%d\n", valor );
        valor = valor - 10;
    }
    fclose(arquivo);
}

/*
03.) Incluir em um programa (Exemplo0713) um método para
ler um valor inteiro do teclado e
gravar essa quantidade em valores da sequência: 1 4 16 64 256 ...
*/
void metodo3(){
    int i, qntd, valor;
    FILE* arquivo = fopen ( "Exemplo0713.txt", "wt" );

    qntd = IO_readint("Digite um valor inteiro: ");
    IO_line();
    valor = 1;
    for (i = 0; i < qntd; i++)
    {
        //IO_printf("%d\n", valor);
        fprintf ( arquivo, "%d\n", valor );
        valor = valor * 4;
    }
    fclose(arquivo);
}

/*
04.) Incluir em um programa (Exemplo0714) um método para
ler um valor inteiro do teclado e
gravar essa quantidade em valores decrescentes da sequência: ... 1/81 1/27 1/9 1/3 1.
*/
void metodo4(){
    int limite_superior, i, qntd, valor;
    double numero;
    FILE* arquivo = fopen ( "Exemplo0714.txt", "wt" );

    qntd = IO_readint("Digite um valor inteiro: ");
    IO_line();
    qntd = qntd - 1;

    limite_superior = pow(3, qntd);
    valor = limite_superior;

    fprintf ( arquivo, "%i\n", qntd );
    for (i = qntd; i <= qntd && i >= 0 ; i--)
    {
        //IO_printf("%d\n", valor);
        numero = 1.0/valor;
        fprintf ( arquivo, "%lf\n", numero );
        valor = pow(3, i - 1);
    }
    fclose(arquivo);
}


/*
05.) Incluir em um programa (Exemplo0715) um método para
ler um valor inteiro do teclado (n) e outro valor real (x),
gravar essa quantidade (n) em valores reais da sequência: 1 1/x 1/x2 1/x4
...
DICA: Usar pow ( x, y ) da biblioteca <math.h> para calcular a potência.
*/
void metodo5(){
    int i, x, n, valor;
    double conta = 0.0;
    FILE* arquivo = fopen ( "Exemplo0715.txt", "wt" );

    n = IO_readint("Digite uma quantidade de numeros: ");
    IO_line();
    x = IO_readint("Digite um valor inteiro: ");

    IO_line();
    valor = 1;
    fprintf ( arquivo, "%d\n", n );
    for (i = 1; i <= n; i++)
    {
        conta = 1.0/valor;
        fprintf ( arquivo, "%lf\n", conta );
        valor = pow(x, i*2);
    }
    fclose(arquivo);
}

/*
06.) Incluir em um programa (Exemplo0716) com função para
ler um valor inteiro do teclado e
calcular a soma dessa quantidade dentre os primeiros valores gravados no exercício anterior.
Testar essa função para quantidades diferentes.
Gravar em outro arquivo ("RESULTADO06.TXT") cada quantidade e seu resultado
*/
void metodo6(){
    double soma = 0.0;
    FILE* arquivo_salvar = fopen ( "RESULTADO06.txt", "wt" );
    FILE* arquivo = fopen ( "EXEMPLO0715.txt", "rt" );
    int x = 0 ; // Quantidade de linhas
    int n = 0 ;
    int y = 1 ;
    double z = 0.0;

    n = IO_readint("Digite uma quantidade de numeros: ");

    fscanf ( arquivo, "%d", &x );

    if(n > x){
        IO_printf("ERRO: O arquivo EXEMPLO0715.txt nao possui %i linhas", n);
    }else{

        while ( ! feof ( arquivo ) && y <= x && y <= n){
            fscanf ( arquivo, "%lf", &z );
            printf ( "%2d: %lf\n", y, z );
            soma = soma + z;
            y = y + 1;
        }
        fclose ( arquivo );
        fprintf(arquivo_salvar, "%lf", soma);
        fclose ( arquivo_salvar );
    }
}

/*
07.) Incluir em um programa (Exemplo0717) com função para
ler um valor inteiro do teclado e
calcular a soma dessa quantidade dentre os inversos das potências de 3 do exercício 04 acima.
Gravar em outro arquivo ("RESULTADO07.TXT") cada quantidade e seu resultado
*/
void metodo7(){
    double soma = 0.0;
    FILE* arquivo_salvar = fopen ( "RESULTADO07.txt", "wt" );
    FILE* arquivo = fopen ( "EXEMPLO0714.txt", "rt" );
    int x = 0 ; // Quantidade de linhas
    int n = 0 ;
    int y = 1 ;
    double z = 0.0;

    n = IO_readint("Digite uma quantidade de numeros: ");

    fscanf ( arquivo, "%d", &x );

    if(n > x){
        IO_printf("ERRO: O arquivo EXEMPLO0715.txt nao possui %i linhas", n);
    }else{

        while ( ! feof ( arquivo ) && y <= x && y <= n){
            fscanf ( arquivo, "%lf", &z );
            printf ( "%2d: %lf\n", y, z );
            soma = soma + z;
            y = y + 1;
        }
        fclose ( arquivo );
        fprintf(arquivo_salvar, "%lf", soma);
        fclose ( arquivo_salvar );
    }
}

/*
08.) Incluir em um programa (Exemplo0718) com função para
ler um valor inteiro do teclado e
gravar o valor correspondente aos primeiros termos ímpares da série de Fibonacci.
Gravar em outro arquivo ("RESULTADO08.TXT") cada quantidade e seu resultado.
*/
void metodo8(){
    FILE* arquivo = fopen ( "RESULTADO08.txt", "wt" );
    int n = 0;
    int calculados = 0;
    n = IO_readint("Digite uma quantidade de numeros: ");
    while (n < calculados){

    }
    fclose(arquivo);
}

/*
09.) Incluir em um programa (Exemplo0719) com função para
para calcular a quantidade de minúsculas em cadeia de caracteres de um arquivo texto.
Gravar em outro arquivo ("RESULTADO09.TXT") cada cadeia de caracteres e seu resultado
*/
void metodo9(){
    int minusculas = 0;
    int i = 0;
    FILE* arquivo_salvar = fopen ( "RESULTADO09.txt", "wt" );
    FILE* arquivo = fopen ( "Exemplo0719.txt", "rt" );
    chars linha = IO_new_chars ( STR_SIZE );
    strcpy ( linha, IO_freadln ( arquivo ) );
    while ( ! feof (arquivo) && strcmp ( "PARAR", linha ) != 0 ){
        for (i = 0; i < strlen(linha); i++){
            if(islower(linha[i])){
                ++minusculas;
            }
        }
        fprintf(arquivo_salvar, "%s: %i minusculas\n", linha, minusculas);
        strcpy ( linha, IO_freadln ( arquivo ) );
        minusculas = 0;
    }
    fclose ( arquivo );
    fclose ( arquivo_salvar );
}

/*
 10.) Incluir em um programa (Exemplo0720) com função para
para contar dígitos em uma cadeia de caracteres.
Gravar em outro arquivo ("RESULTADO10.TXT") cada cadeia de caracteres e seu resultado.
Testar essa função para quantidades diferentes
*/
void metodo10(){
     int digitos = 0;
    int i = 0;
    FILE* arquivo_salvar = fopen ( "RESULTADO10.txt", "wt" );
    FILE* arquivo = fopen ( "Exemplo0720.txt", "rt" );
    chars linha = IO_new_chars ( STR_SIZE );
    strcpy ( linha, IO_freadln ( arquivo ) );
    while ( ! feof (arquivo) && strcmp ( "PARAR", linha ) != 0 ){
        for (i = 0; i < strlen(linha); i++){
            if(isdigit(linha[i])){
                ++digitos;
            }
        }
        fprintf(arquivo_salvar, "%s: %i digitos\n", linha, digitos);
        strcpy ( linha, IO_freadln ( arquivo ) );
        digitos = 0;
    }
    fclose ( arquivo );
    fclose ( arquivo_salvar );
}

/*
 
*/
void extra1(){}

/*
 
*/
void extra2(){}

void select() {
    int atividade;
    IO_id("ED07 - 03 mai 2020");

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
