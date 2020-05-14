/*
ED10 - 13/05/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"

//Definir estrutura do array
typedef struct arranjo{
    int qntd;
    int *data;
} array;
//Definir ponteiro de array
typedef array* ref_Array;

//Definir estrutura da matriz
typedef struct matrix{
    int linhas;
    int colunas;
    ints* data;
    int i_lin;
    int i_col;
} matrix;
//Definir ponteiro de array
typedef matrix* ref_Matriz;

/*
@function alocar_Matriz(int linhas, int colunas)
@return ref_Matriz
*/
ref_Matriz alocar_Matriz(int linhas, int colunas){
    ref_Matriz tmpmatriz;
    tmpmatriz = (ref_Matriz)malloc(sizeof(matrix));
    if(linhas > 0 && colunas > 0){
        if ( tmpmatriz != NULL ){
            tmpmatriz->linhas = linhas;
            tmpmatriz->colunas = colunas;
            tmpmatriz->data = NULL;

            tmpmatriz->data = malloc(linhas * sizeof(ints));
            for(tmpmatriz->i_lin = 0; tmpmatriz->i_lin < tmpmatriz->linhas;  tmpmatriz->i_lin =  tmpmatriz->i_lin + 1){
                tmpmatriz->data[tmpmatriz->i_lin] =  (ints)malloc(sizeof(int) * colunas);
            }
            tmpmatriz->i_lin = 0;
            tmpmatriz->i_col = 0;
        }else{
            IO_printf("\nERROR: Erro ao alocar espaco para a matriz");
        }
    }else{
        IO_printf("\nERROR: Numero de colunas e/ou linhas invalidos");
    }
    return tmpmatriz;
}

/*
@function mostrarMatriz( ref_Array arranjo)
*/
void mostrarMatriz(ref_Matriz matrix){
for ( matrix->i_lin=0; matrix->i_lin<matrix->linhas; matrix->i_lin=matrix->i_lin+1 )
    {
        for ( matrix->i_col=0; matrix->i_col<matrix->colunas; matrix->i_col=matrix->i_col+1 )
        {
            printf ( "%3d\t", matrix->data [ matrix->i_lin ][ matrix->i_col ] );
        }
        printf ( "\n" );
    }
}

/*
@function mostarArranjo( ref_Array arranjo)
*/
void mostarArranjo(ref_Array arranjo){
    int i = 0;
    IO_printf("\n");
    for (i = 0; i < arranjo->qntd; i = i + 1){
        IO_printf("arranjo[%i]: %i\n", i, arranjo->data[i]);
    }
}
/*
@function gerarInt( int inferior, int superior)
@return int
*/
int gerarInt(int inferior, int superior){
    int gerado = 0;
    gerado = (rand() % (superior - inferior + 1)) + inferior;
    return gerado;
}
/*
01.) Incluir em um programa (Exemplo1011) um método para
gerar um valor inteiro aleatoriamente dentro de um intervalo,
cujos limites de início e de fim serão recebidos como parâmetros;

Para para testar, ler os limites do intervalo do teclado;

ler a quantidade de elementos ( N ) a serem gerados;

gerar essa quantidade ( N ) de valores aleatórios
dentro do intervalo e armazená-los em arranjo;

gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.

DICA: Usar a função rand( ), mas tentar limitar valores muito grandes.
Exemplo: valor = gerarInt ( inferior, superior );
*/
void metodo1(){
    int inferior = 0;
    int superior = 0;
    int qntd = 0;
    int i = 0;
    int valor = 0;

    ref_Array arranjo = (ref_Array)malloc(sizeof(array));

    FILE * dados = fopen("DADOS.txt", "wt");
    qntd = IO_readint("Digite uma quantidade de numeros inteiros a serem gerados: ");
    inferior = IO_readint("Digite um valor para o limite inferior: ");
    superior = IO_readint("Digite um valor para o limite superior: ");
    if(qntd <= 0){
        IO_printf("\nERROR: Digite um valor valido para a quantidade de numeros");
    }else{
        fprintf(dados, "%i\n", qntd);

        arranjo->qntd = qntd;
        arranjo->data = (int*)malloc(sizeof(int) * arranjo->qntd);

        if(superior <= inferior){
            IO_print("\nERROR: Nao ha um limite valido");
        }else{
            for (i = 0; i < qntd; i = i + 1){
                valor = gerarInt(inferior, superior);
                arranjo->data[0] = valor;
                fprintf(dados, "%i\n", valor);
            }
        }
    }
    fclose(dados);
}

/*
@function lerArquivo( chars filename )
@return ref_Array
*/
ref_Array lerArquivo(chars filename){
    ref_Array arranjo = (ref_Array)malloc(sizeof(array));
    FILE * dados = fopen(filename, "rt");
    int i = 0;
    if(dados == NULL){
        IO_printf("\nERROR: Erro ao ler o arquivo de dados");
    }else{
        fscanf(dados, "%i", &arranjo->qntd);
        arranjo->data = (int*)malloc(sizeof(int) * arranjo->qntd);
        for (i = 0; i < arranjo->qntd; i = i +1){
            fscanf(dados, "%i", &arranjo->data[i]);
        }
    }
    return arranjo;
}

/*
@function procurar_Arranjo( ref_Array arranjo, int n )
@return bool
*/
bool procurar_Arranjo(ref_Array arranjo, int n){
    bool result = 0;
    int i = 0;
    for (i = 0; i < arranjo->qntd; i = i+1){
        if(arranjo->data[i] == n){
            result = 1;
        }
    }
    return result;
}

/*
02.) Incluir em um programa (Exemplo1012) uma função para
procurar certo valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;

Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
menor = procurar ( arranjo, n );
*/
void metodo2(){
    ref_Array arranjo;
    int n = 0;
    arranjo = lerArquivo("DADOS.txt");
    n = IO_readint("Digite um numero para procurar no arranjo: ");
    if(procurar_Arranjo(arranjo, n)){
        IO_printf("\nO numero %i foi encontrado no arranjo", n);
    }else{
        IO_printf("\nO numero %i nao foi encontrado no arranjo", n);
    }
}
/*
@function comparar( ref_Array arranjo1, ref_Array arranjo2 )
@return bool
*/
bool comparar( ref_Array arranjo1, ref_Array arranjo2 ){
    bool result = 0;
    if(arranjo1->qntd == arranjo2->qntd){
        result = 1;
    }
    return result;
}
/*
03.) Incluir em um programa (Exemplo1013) uma função para
operar a comparação de dois arranjos.
Para testar, receber dados de arquivos e
aplicar a função sobre os arranjos com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
arranjo2 = lerArquivo ( "DADOS2.TXT" );
resposta = comparar ( arranjo1, arranjo2 );
*/
void metodo3(){
    ref_Array arranjo1, arranjo2;
    arranjo1 = lerArquivo("DADOS1.txt");
    arranjo2 = lerArquivo("DADOS2.txt");
    if ( comparar(arranjo1, arranjo2) ){
        IO_printf("\nOs arranjos tem tamanhos compativeis");
    }else{
        IO_printf("\nOs arranjos nao tem tamanhos compativeis");
    }
}

/*
@function procurar_Arranjo( ref_Array arranjo, int n )
@return bool
*/
ref_Array somar_Arranjo(ref_Array arranjo1, ref_Array arranjo2){
    ref_Array soma;
    soma = (ref_Array)malloc(sizeof(array));
    soma->qntd = arranjo1->qntd;
    soma->data = (int*)malloc(sizeof(int)*soma->qntd);
    int i = 0;
    for (i = 0; i < arranjo1->qntd; i = i+1){
        soma->data[i] = arranjo1->data[i] + arranjo2->data[i];
    }
    return soma;
}

/*
04.) Incluir em um programa (Exemplo1014) uma função para
operar a soma de dois arranjos, com o segundo escalado por uma constante.
Para testar, receber dados de arquivos e
aplicar a função sobre os arranjos com os valores lidos;

DICA: Verificar se os tamanhos são compatíveis.
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
arranjo2 = lerArquivo ( "DADOS2.TXT" );
soma = somar ( arranjo1, arranjo2 );
*/
void metodo4(){
    ref_Array arranjo1, arranjo2, soma;
    arranjo1 = lerArquivo("DADOS1.txt");
    arranjo2 = lerArquivo("DADOS2.txt");
    if ( comparar(arranjo1, arranjo2) ){
        soma = somar_Arranjo(arranjo1, arranjo2);
        mostarArranjo(soma);
        IO_pause("Aperte enter");
    }else{
        IO_printf("\nOs arranjos nao tem tamanhos compativeis");
    }
}
/*
@function array_ordenada( ref_Array arranjo1)
@return bool
*/
bool array_ordenada( ref_Array arranjo){
    bool result = 1;
    int n = arranjo->data[0];
    int i = 1;

    for( i = 1; i < arranjo->qntd; i = i + 1){
        if(arranjo->data[i] < n){
            result = result * 0;
        }
        n = arranjo->data[i];
    }

    return result;
}
/*
05.) Incluir em um programa (Exemplo1015) uma função para
dizer se um arranjo está em ordem crescente.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
resposta = ordenado ( arranjo );
*/
void metodo5(){
    ref_Array arranjo1;
    arranjo1 = lerArquivo("DADOS.txt");
    if ( array_ordenada(arranjo1) ){
        IO_printf("\nO arranjo esta ordenado em ordem crescente");
    }else{
        IO_printf("\nO arranjo nao esta ordenado em ordem crescente");
    }
}


/*
@function lerMatrizDeArquivo ( chars filename)
@return ref_Matriz
*/
ref_Matriz lerMatrizDeArquivo ( chars filename){
    ref_Matriz matriz;
    int x;
    int y;
    FILE * arquivo = fopen(filename, "rt");
    fscanf(arquivo, "%i", &x);
    fscanf(arquivo, "%i", &y);
    
    matriz = alocar_Matriz(x, y);
    for (matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
        for (matriz->i_col = 0; matriz->i_col < matriz->colunas; matriz->i_col = matriz->i_col + 1){
            fscanf(arquivo, "%i", &matriz->data[matriz->i_lin][matriz->i_col]);
        }
    }
    fclose(arquivo);
    return matriz;
}

/*
@function transporMatriz(ref_Matriz matriz)
@return ref_Matriz
*/
ref_Matriz transporMatriz(ref_Matriz matriz){
    ref_Matriz matrizT;
    matrizT = alocar_Matriz(matriz->linhas, matriz->colunas);

    matriz->i_col = 0;
    matriz->i_lin = 0;
    for(matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
        for(matriz->i_col = 0; matriz->i_col < matriz->colunas; matriz->i_col = matriz->i_col + 1){
            matrizT->data[matriz->i_col][matriz->i_lin] = matriz->data[matriz->i_lin][matriz->i_col];
        }
    }
    matrizT->linhas = matriz->colunas;
    matrizT->colunas = matriz->linhas;
    return matrizT;
}

/*
06.) Incluir em um programa (Exemplo1016) uma função para
obter a transposta de uma matriz.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.

Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = transpostaMatriz ( matriz1 );
*/
void metodo6(){
    ref_Matriz matriz, matrizT;
    matriz = lerMatrizDeArquivo("DadosMatriz1.txt");
    matrizT = transporMatriz(matriz);
    mostrarMatriz(matrizT);
}
/*
@function zero_Matrix(ref_Matriz matriz)
@return bool
@       1 - Matriz somente com zeros
@       0 - Matriz contem outros numeros alem do 0
*/
bool zero_Matrix(ref_Matriz matriz){
    bool result = 1;
    for(matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
        for(matriz->i_col = 0; matriz->i_col < matriz->colunas; matriz->i_col = matriz->i_col + 1){
            if(matriz->data[matriz->i_lin][matriz->i_col] != 0){
                result = result * 0;
            }
        }
    }
    return result;
}

/*
07.) Incluir em um programa (Exemplo1017) uma função para
testar se uma matriz só contém valores iguais a zero.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
resposta = zeroMatriz ( matriz1 );
*/
void metodo7(){
    ref_Matriz matriz;
    matriz = lerMatrizDeArquivo("DadosMatriz2.txt");
    if(zero_Matrix(matriz)){
        IO_printf("A matriz de entrada contem somente valores iguais a zero");
    }else{
        IO_printf("A matriz de entrada contem valores diferentes de zero");
    }

}

/*
@function compararMatriz(ref_Matriz matriz, ref_Matriz matriz2)
@return bool
@       1 - Matriz identica
@       0 - Matriz nao identica
*/
bool compararMatriz(ref_Matriz matriz, ref_Matriz matriz2){
    bool result = 1;
    if(matriz->linhas == matriz2->linhas && matriz->colunas == matriz2->colunas){
        for(matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
            for(matriz->i_col = 0; matriz->i_col < matriz->colunas; matriz->i_col = matriz->i_col + 1){
                if(matriz->data[matriz->i_lin][matriz->i_col] !=  matriz2->data[matriz->i_lin][matriz->i_col]){
                    result = result * 0;
                }
            }
        }
    }else{
        IO_erro("As matrizes tem tamanhos diferentes");
    }
    return result;
}

/*
08.) Incluir em um programa (Exemplo1018) uma função para
testar a igualdade de duas matrizes pela.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = lerMatrizDeArquivo ( "DADOS2.TXT" );
resposta = compararMatriz ( matriz1, matriz2 );
*/
void metodo8(){
    ref_Matriz matriz1, matriz2;
    matriz1 = lerMatrizDeArquivo("DadosMatriz1.txt");
    matriz2 = lerMatrizDeArquivo("DadosMatriz2.txt");
    if(compararMatriz(matriz1, matriz2)){
        IO_printf("As matrizes sao iguais");
    }else{
        IO_printf("As matrizes sao diferentes");
    }
}


/*
@function somarMatriz(ref_Matriz matriz, ref_Matriz matriz2)
@return ref_Matriz
*/
ref_Matriz somarMatriz(ref_Matriz matriz, ref_Matriz matriz2){
    ref_Matriz tmpMatriz;
    if(matriz->linhas == matriz2->linhas && matriz->colunas == matriz2->colunas){
        tmpMatriz = alocar_Matriz(matriz->linhas, matriz->colunas);
        for(matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
            for(matriz->i_col = 0; matriz->i_col < matriz->colunas; matriz->i_col = matriz->i_col + 1){
                tmpMatriz->data[matriz->i_lin][matriz->i_col] = (matriz->data[matriz->i_lin][matriz->i_col] + matriz2->data[matriz->i_lin][matriz->i_col]);                
            }
        }
    }else{
        IO_erro("As matrizes tem tamanhos diferentes");
        tmpMatriz = NULL;
    }
    
    return tmpMatriz;
}

/*
09.) Incluir em um programa (Exemplo1019) uma função para
operar a soma de duas matrizes, com a segunda escalado por uma constante.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = lerMatrizDeArquivo ( "DADOS2.TXT" );
soma = somarMatriz ( matriz1, matriz2 );
*/
void metodo9(){
    ref_Matriz matriz1, matriz2, soma;
    matriz1 = lerMatrizDeArquivo("DadosMatriz1.txt");
    matriz2 = lerMatrizDeArquivo("DadosMatriz2.txt");
    soma = somarMatriz(matriz1, matriz2);
    if(soma){
        mostrarMatriz(soma);
    }
    //
}

/*
@function multiplicarMatriz(ref_Matriz matriz, ref_Matriz matriz2)
@return ref_Matriz
*/
ref_Matriz multiplicarMatriz(ref_Matriz matriz, ref_Matriz matriz2){
    ref_Matriz tmpMatriz;
    int i = 0;
    int aux = 0;

    if(matriz->colunas == matriz2->linhas){
        tmpMatriz = alocar_Matriz(matriz->linhas, matriz2->colunas);
        //Cada linha tenho que passar nela matriz2->colunas vezes
        for(matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
            for(matriz2->i_col = 0; matriz2->i_col < matriz2->colunas; matriz2->i_col = matriz2->i_col + 1){
                aux = 0;
                for(i = 0; i < matriz->colunas; i = i + 1){
                    aux = aux + matriz->data[matriz->i_lin][i] * matriz2->data[i][matriz2->i_col];
                }
                tmpMatriz->data[matriz->i_lin][matriz2->i_col] = aux;
            }      
        }
    }else{
        IO_erro("Impossivel multiplicar as matrizes");
        tmpMatriz = NULL;
    }
    
    return tmpMatriz;
}
/*
10.) Incluir em um programa (Exemplo1020) uma função para
obter o produto de duas matrizes.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = lerMatrizDeArquivo ( "DADOS2.TXT" );
soma = multiplicarMatriz ( matriz1, matriz2 );
*/
void metodo10(){
    ref_Matriz matriz1, matriz2, multi;
    matriz1 = lerMatrizDeArquivo("DadosMatrizM1.txt");
    matriz2 = lerMatrizDeArquivo("DadosMatrizM2.txt");
    multi = multiplicarMatriz(matriz1, matriz2);
    if(multi){
        mostrarMatriz(multi);
    }
    
}

/*
E1.) Incluir em um programa (Exemplo10E1) uma função para
colocar um arranjo em ordem decrescente, pelo método de trocas de posição.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos.
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
ordenado = ordenar ( arranjo );
*/
void extra1(){
    ref_Array arranjo, ordenado;
    arranjo = lerArquivo("DADOS.TXT");
}
/*
@function identidadeMatriz(ref_Matriz matriz)
@return bool
@       1 - Matriz identidade
@       0 - Matriz nao identidade
*/
bool identidadeMatriz(ref_Matriz matriz){
    bool result = 1;
    for(matriz->i_lin = 0; matriz->i_lin < matriz->linhas; matriz->i_lin = matriz->i_lin + 1){
        for(matriz->i_col = 0; matriz->i_col < matriz->colunas; matriz->i_col = matriz->i_col + 1){
            if(matriz->i_col == matriz->i_lin){
                if(matriz->data[matriz->i_lin][matriz->i_col] != 1){
                    result = result * 0;
                }
            }else{
                if(matriz->data[matriz->i_lin][matriz->i_col] != 0){
                    result = result * 0;
                }
            }
        }
    }
    return result;
}
/*
E2.) Incluir em um programa (Exemplo10E2) uma função para
testar se o produto de duas matrizes é igual à matriz identidade.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: matriz1 = lerMatrizDeArquivo ( "DADOS1.TXT" );
matriz2 = lerMatrizDeArquivo ( "DADOS2.TXT" );
resposta = identidadeMatriz ( multiplicar (matriz1, matriz2) );
*/
void extra2(){
    ref_Matriz matriz1, matriz2, produto;
    matriz1 = lerMatrizDeArquivo("DadosMatriz1.txt");
    matriz2 = lerMatrizDeArquivo("DadosMatriz2.txt");
    produto = multiplicarMatriz(matriz1, matriz2);
    if(identidadeMatriz(produto)){
        IO_printf("O produto das matrizes resulta em uma matriz identidade");
    }else{
        IO_printf("O produto das matrizes nao resulta em uma matriz identidade");
    }
}

void select() {
    int atividade;
    IO_id("ED10 - 13 mai 2020");

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
    //metodo10();
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
