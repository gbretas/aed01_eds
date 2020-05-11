/*
ED06 - 28/04/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"

/*
 * void mostrarMatriz( int linhas, int colunas, int matriz[linhas][colunas] )
 * @params int linhas  -    quantidade de linhas da matriz
 *         int colunas -    quantidade de colunas da matriz
 *         int matriz[linhas][colunas] - matriz
 */
void mostrarMatriz(int linhas, int colunas, int matriz[linhas][colunas]){
    int i_lin = 0, i_col = 0;
    for(i_lin = 0; i_lin<linhas; i_lin++){
        for(i_col = 0; i_col<colunas; i_col++){
            IO_printf("%3d\t", matriz[i_lin][i_col]);
        }
        IO_line();
    }
}
/*
 * int freadMatrizLinhas( chars filename )
 * @params chars filename - nome do arquivo da matriz
 * @return int - quantidade de linhas da matriz
 */
int freadMatrizLinhas(chars filename){
    int n=0;
    FILE * arquivo = fopen(filename, "rt");
    fscanf(arquivo, "%d", &n);
    if( n<= 0 ){
        IO_print("ERROR: Valor de linhas invalido");
        n=0;
    }
    fclose(arquivo);
    return n;
}
/*
 * int freadMatrizColunas( chars filename )
 * @params chars filename - nome do arquivo da matriz
 * @return int - quantidade de colunas da matriz
 */
int freadMatrizColunas(chars filename){
    int n=0;
    FILE * arquivo = fopen(filename, "rt");
    fscanf(arquivo, "%d", &n);
    fscanf(arquivo, "%d", &n);
    if( n<= 0 ){
        IO_print("ERROR: Valor de colunas invalido");
        n=0;
    }
    fclose(arquivo);
    return n;
}

/*
 * void freadMatriz( chars filename, int linhas, int colunas, int matrix[][colunas] )
 * @params chars filename - nome do arquivo da matriz
 * @params int linhas - quantidade de linhas da matriz
 * @params int colunas - quantidade de colunas
 * @params int matrix[][colunas] - matriz propriamente dita
 */
void freadMatriz(chars filename, int linhas, int colunas, int matrix[][colunas]){
    int n = 0, linha_n = 0, coluna_n = 0;
    FILE * arquivo = fopen("Metodo0902.txt", "rt");
    fscanf(arquivo, "%d", &linhas);
    fscanf(arquivo, "%d", &colunas);
    int arr[linhas][colunas];

    if( linhas <= 0 || colunas <= 0 ){
        IO_print("ERROR: Valor de linhas e/ou colunas invalido");
    }else{
        fscanf(arquivo, "%d", &n);
        while (!feof(arquivo)){
            while(linha_n < linhas){
                while(coluna_n < colunas){
                    matrix[linha_n][coluna_n] = n;
                    coluna_n++;
                    fscanf(arquivo, "%d", &n);
                }
                coluna_n = 0;
                linha_n++;
            }
        }
    }
    fclose(arquivo);
    //return arr;
}
/*
 * void criarMatriz( int linhas, int colunas, int matriz[][colunas] )
 * @params int linhas - quantidade de linhas da matriz
 * @params int colunas - quantidade de colunas
 * @params int matrix[][colunas] - matriz propriamente dita
 */
void criarMatriz(int linhas, int colunas, int matriz[][colunas]){
    int i_lin = 0, i_col = 0;
    if(linhas <= 0 || colunas <= 0){
        IO_printf("ERROR: Apenas valores positivos sao aceitos para linhas e colunas");
    }else{
        for(i_lin = 0; i_lin<linhas; i_lin++){
            for(i_col = 0; i_col<colunas; i_col++){
                IO_printf("matriz[%i][%i]: ", i_lin + 1, i_col + 1);
                matriz[i_lin][i_col] = IO_readint("");
            }
            IO_line();
        }
    }
}

/*
01.) Incluir em um programa (Exemplo0911) um método para
ler as dimensões (quantidade de linhas e de colunas) de uma matriz real do teclado,
bem como todos os seus elementos (apenas valores positivos).
Verificar se as dimensões não são nulas ou negativas.
Para testar, ler dados e mostrá-los na tela por outro método.
*/
void metodo1(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    if(linhas <= 0 || colunas <= 0){
        IO_printf("ERROR: Apenas valores positivos sao aceitos para linhas e colunas");
    }else{
        IO_line();
        for(i_lin = 0; i_lin<linhas; i_lin++){
            for(i_col = 0; i_col<colunas; i_col++){
                IO_printf("matriz[%i][%i]: ", i_lin + 1, i_col + 1);
                matriz[i_lin][i_col] = IO_readint("");
            }
            IO_line();
        }
        mostrarMatriz(linhas, colunas, matriz);
    }
}

/*
02.) Incluir em um programa (Exemplo0912) um método para
gravar uma matriz real em arquivo.
A matriz e o nome do arquivo serão dados como parâmetros.
Para testar, usar a leitura da matriz do problema anterior.
Usar outro método para ler e recuperar a matriz do arquivo, antes de mostrá-la na tela.
*/
void metodo2(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    chars filename;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    filename = IO_readstring("Digite o nome do arquivo a ser gravada a matriz: ");
    FILE * arquivo = fopen(filename, "wt");
    int matriz[linhas][colunas];
    IO_fprintf(arquivo, "%i\n", linhas);
    IO_fprintf(arquivo, "%i\n", colunas);
    if(linhas <= 0 || colunas <= 0){
        IO_printf("ERROR: Apenas valores positivos sao aceitos para linhas e colunas");
    }else{
        IO_line();
        for(i_lin = 0; i_lin<linhas; i_lin++){
            for(i_col = 0; i_col<colunas; i_col++){
                IO_printf("matriz[%i][%i]: ", i_lin + 1, i_col + 1);
                matriz[i_lin][i_col] = IO_readint("");
                IO_fprintf(arquivo, "%i\n", matriz[i_lin][i_col]);
            }
            IO_line();
        }
        mostrarMatriz(linhas, colunas, matriz);
    }
    fclose(arquivo);
}

/*
03.) Incluir em um programa (Exemplo0913) um método para
mostrar somente os valores na diagonal principal de uma matriz real, se for quadrada.
*/
void metodo3(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == i_lin){
                    IO_printf("\nmatriz[%i][%i] = %i", i_lin, i_col, matriz[i_lin][i_col]);
                }
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
04.) Incluir em um programa (Exemplo0914) um método para
mostrar somente os valores na diagonal secundária de uma matriz real, se for quadrada.
*/
void metodo4(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    int s_lin = 0, s_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    s_col = colunas - 1;
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == s_col && i_lin == s_lin){
                    IO_printf("\nmatriz[%i][%i] = %i", i_lin, i_col, matriz[i_lin][i_col]);
                    s_lin++;
                    s_col--;
                }
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
05.) Incluir em um programa (Exemplo0915) um método para
mostrar somente os valores abaixo da diagonal principal de uma matriz real, se for quadrada
*/
void metodo5(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == i_lin){
                    if(i_lin + 1 < linhas ){
                        IO_printf("\nmatriz[%i][%i] = %i", i_lin + 1, i_col, matriz[i_lin + 1][i_col]);
                    }
                }
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
06.) Incluir em um programa (Exemplo0916) um método para
mostrar somente os valores acima da diagonal principal de uma matriz real, se for quadrada
*/
void metodo6(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == i_lin){
                    if(i_lin -1 >= 0 ){
                        IO_printf("\nmatriz[%i][%i] = %i", i_lin - 1, i_col, matriz[i_lin - 1][i_col]);
                    }
                }
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
07.) Incluir em um programa (Exemplo0917) um método para
mostrar somente os valores abaixo da diagonal secundária de uma matriz real, se for quadrada.
*/
void metodo7(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    int s_lin = 0, s_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    s_col = colunas - 1;
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == s_col && i_lin == s_lin){
                    if(i_lin + 1 < linhas){
                        IO_printf("\nmatriz[%i][%i] = %i", i_lin+1, i_col, matriz[i_lin+1][i_col]);
                    }
                    s_lin++;
                    s_col--;
  
                }
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
08.) Incluir em um programa (Exemplo0918) um método para
mostrar somente os valores acima da diagonal secundária de uma matriz real, se for quadrada.
*/
void metodo8(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    int s_lin = 0, s_col = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    s_col = colunas - 1;
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == s_col && i_lin == s_lin){
                    if(i_lin - 1 >= 0){
                        IO_printf("\nmatriz[%i][%i] = %i", i_lin-1, i_col, matriz[i_lin-1][i_col]);
                    }
                    s_lin++;
                    s_col--;
                }
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
09.) Incluir em um programa (Exemplo0919) uma função para
testar se não são todos nulos os valores abaixo da diagonal principal de uma matriz real quadrada.
*/
void metodo9(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    int soma = 0;
    int nulos = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == i_lin){
                    if(i_lin + 1 < linhas ){
                        soma = soma + matriz[i_lin + 1][i_col];
                        if(matriz[i_lin + 1][i_col] == 0){
                            nulos++;
                        }
                    }
                }
            }
        }
        if(soma == 0){
            IO_printf("Todos os valores abaixo da diagonal principal dessa matriz sao nulos");
        }else{
            if(nulos == 0){
                IO_printf("Todos os valores abaixo da diagonal principal dessa matriz nao sao nulos");
            }else{
                IO_printf("%i valores abaixo da diagonal principal dessa matriz sao nulos", nulos);
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
10.) Incluir em um programa (Exemplo0920) uma função para
testar se são nulos os valores acima da diagonal principal de uma matriz real quadrada.
*/
void metodo10(){
    int linhas = 0, colunas = 0;
    int i_lin = 0, i_col = 0;
    int soma = 0, nulos = 0;
    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    criarMatriz(linhas, colunas, matriz);
    IO_separator();
    if(linhas == colunas){
        for (i_lin = 0; i_lin < linhas; i_lin++){
            for (i_col = 0; i_col < colunas; i_col++){
                if(i_col == i_lin){
                    if(i_lin -1 >= 0 ){
                        soma = soma + matriz[i_lin - 1][i_col];
                        if(matriz[i_lin - 1][i_col] == 0){
                            nulos++;
                        }
                    }
                }
            }
        }
        if(soma == 0){
            IO_printf("Todos os valores acima da diagonal principal dessa matriz sao nulos");
        }else{
            if(nulos == 0){
                IO_printf("Todos os valores acima da diagonal principal dessa matriz nao sao nulos");
            }else{
                IO_printf("%i valores acima da diagonal principal dessa matriz sao nulos", nulos);
            }
        }
    }else{
        IO_print("\nERROR: A matriz nao e quadrada");
    }
}

/*
E1.) Incluir em um programa (Exemplo09E1) definições e testes para
ler do teclado as quantidades de linhas e colunas de uma matriz,
e montar uma matriz com a característica abaixo,
a qual deverá ser gravada em arquivo, após o retorno
*/
void extra1(){
    int linhas;
    int colunas;
    int i;
    int i_col = 0, i_lin = 0;

    FILE * arquivo = fopen("Metodo0901.txt", "wt");

    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    i = linhas * colunas;

    for(i_lin = 0; i_lin < colunas; i_lin++){
        for(i_col = 0; i_col < colunas; i_col++){
            IO_fprintf(arquivo, "%3d\t", i);
            i--;
        }
        IO_fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

/*
E2.) Incluir em um programa (Exemplo09E2) definições e testes para
ler do teclado as quantidades de linhas e colunas de uma matriz,
e montar uma matriz com a característica abaixo,
a qual deverá ser gravada em arquivo, após o retorno.
*/
void extra2(){
    int linhas;
    int colunas;
    int i;
    int i_col = 0, i_lin = 0;

    FILE * arquivo = fopen("Metodo0912.txt", "wt");

    linhas = IO_readint("Digite a quantidade de linhas para a matriz: ");
    colunas = IO_readint("Digite a quantidade de colunas para a matriz: ");
    int matriz[linhas][colunas];
    i = linhas * colunas;

    for(i_lin = 0; i_lin < colunas; i_lin++){
        for(i_col = 0; i_col < colunas; i_col++){
            //IO_printf("%3d\t", ( i - i_lin - colunas * i_col)  );
            IO_fprintf(arquivo, "%3d\t", ( i - i_lin - colunas * i_col)  );
        }
        IO_fprintf(arquivo, "\n");
        //IO_line();
    }

    fclose(arquivo);
}

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
