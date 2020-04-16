/*
ED05 - 13/04/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"

//Verificar multiplos de 3
void multiplos_de_3(int qntd){
    int i = 1;
    chars s = ",";
    if(qntd <= 0){
        IO_print("Digite um numero maior do que 0");
    }else{
        while(i <= qntd){
            if(i == qntd){s="";}
            IO_printf("%i%s", (3 * (i+1)), s );
            i++;
        }
    }
}
//Metodo1
void metodo1(){
    int qntd = 0;
    IO_printf("1 - Digitar x numeros multiplos de 3 \n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem mostrados: ");
    multiplos_de_3(qntd);
}

//Verificar multiplos de 3 impares
bool verificar_se_impar(int numero){
    bool result = false;
    if(numero % 2 != 0){
        result = true;
    }
    return result;
}

void mostrar_numero (int numero){
  IO_printf("%i, ", numero);
}

void multiplos_de_3_impares(int qntd){
    int i = 1;
    int numero = 0;
    chars s = ",";
    if(qntd <= 0){
        IO_print("Digite um numero maior do que 0");
    }else{
        while(i <= qntd){
            numero = (3 * (i+1));
            if(verificar_se_impar(numero)){
                mostrar_numero(numero);
            }else{
                mostrar_numero(numero+3);
                i++;
                qntd++;
            }
            i++;
        }
    }
}
//Metodo2
void metodo2(){
    int qntd = 0;
    IO_printf("2 - Digitar x numeros impares multiplos de 3 crescente \n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem mostrados: ");
    multiplos_de_3_impares(qntd);
}

void mostrar_numero_d (double numero){
  IO_printf("%.0f, ", numero);
}


void multiplos_de_3_pares_decres(int qntd){
    #define NUM_OF_ELEMS qntd
    int i = 1;
    int numero = 0;
    int loop = 0;
    int aux = 0;
    int superior = 0;
    
    if(qntd <= 0 ){
        IO_print("Digite um numero maior do que 0");
    }else{
        superior = (qntd * 6) + 3;
        
        for(int i =0; i < qntd; i++){
            superior -= 3;
            while(superior % 2 == 1){
                superior -= 3;
            }
            IO_printf("%i \n", superior);
        }
    }
}

//Metodo 3
void metodo3(){
    int qntd = 0;
    IO_printf("3 - Digitar x numeros pares multiplos de 3 decrescente \n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem mostrados: ");
    multiplos_de_3_pares_decres(qntd);
}

// Calcular 1/3 * x
void calcular_inversos(int qntd){
    double numero = 0.0;
    int i = 1;
    if(qntd <= 0 ){
        IO_print("Digite um numero maior do que 0");
    }else{
        while (i <= qntd) {
            numero = ( (1.0) / (3.0*i) );
            IO_printf("%f\n", numero);
            i++;
        }
        
        
    }
}

void metodo4(){
    int qntd = 0;
    IO_printf("4 - Digitar x numeros 1/(3*qntd) \n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem mostrados: ");
    calcular_inversos(qntd);
}


void calcular_inversos_pot(int qntd, int potencia){
    double numero = 0.0;
    int i = 1;
    
    if(qntd <= 0 || potencia <= 0){
        IO_print("Digite um numero maior do que 0");
    }else{
        while (i <= qntd) {
            numero = ( (1.0) / (pow(potencia, i)) );
            IO_printf("%f\n", numero);
            i++;
        }
        
        
    }
}
// Metodo 5
void metodo5(){
    int qntd = 0;
    int numero = 0;
    IO_printf("5 - Digitar x numeros 1/(x ˆ i) \n\n");
    numero = IO_readint("Digite um numero a ser elevado: ");
    IO_line();
    qntd = IO_readint("Digite uma quantidade de numeros a serem mostrados: ");
    calcular_inversos_pot(qntd, numero);
}

void impares_multipos3_n5(int qntd){
    int numero = 3;
    int i = 1;
    int mostrados = 0;
    
    if(qntd <= 0){
        IO_print("Digite um numero maior do que 0");
    }else{
        while (mostrados < qntd) {
            numero = numero + 2;
            while (numero % 5 == 0) {
                numero = numero + 2;
            }
            IO_printf("%i\n", numero);
            mostrados++;
        }
    }
}

//Metodo 6
void metodo6(){
    int qntd = 0;
    IO_printf("6 - Mostrar valores impares positivos comecando em 3 e nao multiplos de 5 \n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem mostrados: ");
    impares_multipos3_n5(qntd);
}

void soma_impares_multipos3_n5(int qntd){
    double soma = 0.0;
    double numero = 3.0;
    int i = 1;
    int mostrados = 0;
    
    if(qntd <= 0){
        IO_print("Digite um numero maior do que 0");
    }else{
        while (mostrados < qntd) {
            numero = numero + 2.0;
            while ((int)numero % 5 == 0) {
                numero = numero + 2.0;
            }
            soma = soma + (1/numero);
            IO_printf("1/%.0f = %f\n", numero, (1/numero));
            mostrados++;
        }
        IO_printf("\nSoma = %f", soma);
    }
    
}
//Metodo 7
void metodo7(){
    int qntd = 0;
    IO_printf("7 - Soma valores impares positivos 1/X comecando em 3 e nao multiplos de 5 \n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem somados: ");
    soma_impares_multipos3_n5(qntd);
}

void soma_naturais(int qntd){
    int soma = 0;
    int somados = 0;
    int aux = 1;
    if(qntd <= 0){
           IO_print("Digite um numero maior do que 0");
    }else{
        while (aux - 1 < qntd) {
            soma = soma+aux;
            aux++;
        }
        IO_printf("Soma de %i numeros resulta em %i", aux - 1, soma);
    }
}

void metodo8(){
    int qntd = 0;
    IO_printf("8 - Soma de numeros naturais\n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem somados: ");
    soma_naturais(qntd);
}

void soma_naturais_quadrados(int qntd){
    int soma = 0;
    int somados = 0;
    int aux = 1;
    if(qntd <= 0){
           IO_print("Digite um numero maior do que 0");
    }else{
        while (aux - 1 < qntd) {
            soma = soma+ (int)pow(aux, 2);
            IO_printf("%i ao quadrado = %.0f\n", aux, pow(aux, 2));
            aux++;
        }
        IO_printf("Soma de %i numeros ao quadrado resulta em %i", aux - 1, soma);
    }
}
//metodo9
void metodo9(){
    int qntd = 0;
    IO_printf("9 - Soma de quadrados numeros naturais\n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem somados: ");
    soma_naturais_quadrados(qntd);
}

void soma_inversos(int qntd){
    double soma = 0.0;
    double numero = 1.0;
    int i = 1;
    int mostrados = 0;
    
    if(qntd <= 0){
        IO_print("Digite um numero maior do que 0");
    }else{
        while (mostrados < qntd) {
            soma = soma + (1/numero);
            IO_printf("1/%.0f = %.2f\n", numero, (1/numero));
            numero++;
            mostrados++;
        }
        IO_printf("\nSoma = %f", soma);
    }
    
}
//Metodo 10
void metodo10(){
    int qntd = 0;
    IO_printf("10 - Soma de numeros inversos\n\n");
    qntd = IO_readint("Digite uma quantidade de numeros a serem somados: ");
    soma_inversos(qntd);
}
double calcular_fatorial_a(double num){
    if(num > 0 ){
        return num * calcular_fatorial_a(num-1);
    }
    return 1;
}

void calcular_fatorial(int num){
    double result = 1;
    if(num == 0){
        IO_printf("%.0f", result);
    }else if(num < 0){
         IO_printf("%s", "Digite um numero valido para calcular o fatorial");
    }else{
        IO_printf("%s%i%s%.0f", "\nO fatorial de ", num, " e: ", calcular_fatorial_a(num));
    }
    
   
}
void extra1(){
    int qntd = 0;
    IO_printf("E1 - Calcular fatorial\n\n");
    qntd = IO_readint("Digite um número para calcular o fatorial: ");
    calcular_fatorial(qntd);
}

void calculo_extra2(int quantidade){
    int i = 2;
    double resultado = 1.0;
    double calculo = 0.0;
    int mostrados = 0;
    while (mostrados < quantidade) {
         double calculo = (1 + (i / calcular_fatorial_a(i+1)));
        IO_printf("1 + (%i/%i!) = %.2f\n", i, i+1, calculo);
        i++;
        resultado = resultado * calculo;
        mostrados++;
    }
   IO_printf("O resultado da multiplicao das expressoes e %0.2f", resultado);
   
    
}

void extra2(){
    //calcular_fatorial_a
    int qntd = 0;
    IO_printf("E1 - Calcular expressao\n\n");
    qntd = IO_readint("Digite um número para calcular a expressao: ");
    calculo_extra2(qntd);
}

void select() {
    int atividade;
    IO_id("ED05 - 13 abr 2020");

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
