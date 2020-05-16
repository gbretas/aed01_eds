/*
 Exemplo12 - v0.0. - __ / __ / _____
 Author: 689655 Gustavo Torres Bretas Alves
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause(std::string text) {
  std::string dummy;
  std::cin.clear();
  std::cout << std::endl << text;
  std::cin.ignore();
  std::getline(std::cin, dummy);
  std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "mymatrix.hpp"
using namespace std;
// ----------------------------------------------- metodos

/**
01.) Incluir em um programa (Exemplo1211)
ler a quantidade de elementos ( MxN ) a serem gerados;
gerar essa quantidade ( MxN ) de valores aleatórios
dentro do intervalo e armazená-los em matriz;

gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
DICA: Usar a função rand( ), mas tentar limitar valores muito grandes.
*/
void method01() {
    int linhas;
    int colunas;

    int i_lin = 0;
    int i_col = 0;

    cout << "Digite o numero de linhas para a matriz: ";cin >> linhas;
    cout << endl << "Digite o numero de colunas para a matriz: ";cin >> colunas;
    cout << endl;
    if(linhas > 0 && colunas > 0){
        Matrix<int> matriz(linhas, colunas);
        for (i_lin = 0; i_lin < linhas; i_lin = i_lin + 1){
            for (i_col = 0; i_col < colunas; i_col = i_col + 1){
                matriz.set(i_lin, i_col, matriz.gerarInt(0,100));
            }
        }
        matriz.fprint("Metodo01.txt");
    }else{
        cout << "ERROR: Valores invalidos para linhas e/ou colunas";
    }
    
}


/**
02.) Incluir em um programa (Exemplo1212) uma função para
escalar uma matriz, multiplicando todos os seus valores por uma constante.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre a matriz com os valores lidos;
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
matrix2 = matrix1.scale ( 2 );
*/
void method02() {
    Matrix<int> matriz1(0, 0), matriz2(0,0);
    matriz1.fread("Metodo01.txt");
    int constante;
    cout << "Digite uma constante para escalar toda a matriz: ";cin >> constante;
    matriz1.scale(constante);
    matriz1.print();
}

/**
03.) Incluir em um programa (Exemplo1213) uma função para
testar se uma matriz é a identidade.

Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre a matriz com os valores lidos;
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
teste = matrix1.isIdentity ( );
*/
void method03() {
  bool identidade = 1;
  Matrix<int> matriz1(0, 0), matriz2(0,0);
  matriz1.fread("Metodo01.txt");
  if(matriz1.isIdentity()){
    cout << "A matriz e identidade";
  }else{
    cout << "A matriz nao e identidade";
  }
}

/**
04.) Incluir em um programa (Exemplo1214) um operador para
testar a igualdade de duas matrizes.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;

Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
matrix2 = lerArquivo ( "DADOS2.TXT" );
teste = (matrix1 == matrix2);
*/
void method04() {
  Matrix<int> matriz1(0, 0);
  Matrix<int> matriz2(0, 0);
  matriz1.fread("Metodo01.txt");
  matriz2.fread("Metodo02.txt");

  cout << "Diferentes = " << (matriz1 == matriz2) << endl;
}

/**
05.) Incluir em um programa (Exemplo1215) um operador para
somar duas matrizes.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
matrix2 = lerArquivo ( "DADOS2.TXT" );
soma = matrix1 + matrix2;
*/
void method05() {
  Matrix<int> matriz1(0, 0);
  Matrix<int> matriz2(0, 0);
  Matrix<int> soma(0, 0);
  matriz1.fread("Metodo01.txt");
  matriz2.fread("Metodo02.txt");

  soma = (matriz1 + matriz2);
  soma.print();
}

/**
06.) Incluir em um programa (Exemplo1216) uma função para
operar duas linhas da matriz, guardando no lugar da primeira,
a soma da primeira com a segunda multiplicada por uma constante.
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
matrix1.addRows ( 0, 1, (-1) );
*/
void method06() {
  Matrix<int> matriz1(0, 0);
  matriz1.fread("Metodo01.txt");
  matriz1.addRows(0, 1, 2);
  matriz1.print();
}
/*
Normal sem a funcao:
1       2
3       4
constante 1
4       6
3       4
constante 2
8       12
3       4
*/




/**
07.) Incluir em um programa (Exemplo1217) uma função para
operar duas colunas da matriz, guardando no lugar da primeira,
a diferença da primeira com a segunda multiplicada por uma constante.
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
matrix1.subRows ( 0, 1, (2) );
*/
void method07() {
  Matrix<int> matriz1(0, 0);
  matriz1.fread("Metodo01.txt");
  matriz1.subRows(0, 1, 1);
  matriz1.print();
}
/**
Normal sem a funcao:
1       2
3       4
constante 1
-2       -2
3       4
constante 2
-4      -4
3       4
*/

/*
08.) Incluir em um programa (Exemplo1218) uma função para
dizer em qual linha da matriz se encontra certo valor, se houver.
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
teste = matrix1.searchRows ( procurado )
*/
void method08() {
  Matrix<int> matriz1(0, 0);
  matriz1.fread("Metodo01.txt");
  int teste = -1;
  int procurado = 0;
  cout << "Digite um valor para procurar sua linha na matriz: ";cin >> procurado;cout << endl;
  teste = matriz1.searchRows(procurado);
  if(teste > -1){
    cout << "Valor encontrado na linha " << teste + 1 << endl;
  }else{
    cout << "Valor nao encontrado" << endl;
  }
}

/**
09.) Incluir em um programa (Exemplo1219) uma função para
dizer em qual coluna da matriz se encontra certo valor, se houver.
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
teste = matrix1.searchColumns ( procurado );
*/
void method09() {
  Matrix<int> matriz1(0, 0);
  matriz1.fread("Metodo01.txt");
  int teste = -1;
  int procurado = 0;
  cout << "Digite um valor para procurar sua coluna na matriz: ";cin >> procurado;cout << endl;
  teste = matriz1.searchColumns(procurado);
  if(teste > -1){
    cout << "Valor encontrado na coluna " << teste + 1 << endl;
  }else{
    cout << "Valor nao encontrado" << endl;
  }
}

/**
10.) Incluir em um programa (Exemplo1220) uma função para
transpor os dados em uma matriz.
Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
matrix1.transpose ( );
*/
void method10() {
  Matrix<int> matriz1(0, 0);
  Matrix<int> transposta(0, 0);
  matriz1.fread("Metodo01.txt");
  transposta = matriz1.transpose();
  transposta.print();
}

/*

*/
void method11() {}

/*
*/
void method12() {}

// ----------------------------------------------- acao principal
int main(int argc, char **argv) {
  int x = 0;
  
  do {
    cout << "ED 12 - 14/05/2020\n " << endl;
    cout << "ED 12 - 689655 Gustavo Torres Bretas Alves\n " << endl;
    cout << "Opcoes " << endl;
    cout << " 0 - Parar " << endl;
    cout << " 1 - Metodo 1 " << endl;
    cout << " 2 - Metodo 2" << endl;
    cout << " 3 - Metodo 3" << endl;
    cout << " 4 - Metodo 4" << endl;
    cout << " 5 - Metodo 5" << endl;
    cout << " 6 - Metodo 6" << endl;
    cout << " 7 - Metodo 7" << endl;
    cout << " 8 - Metodo 8" << endl;
    cout << " 9 - Metodo 9" << endl;
    cout << "10 - Metodo 10" << endl;
    cout << "11 - Extra 1" << endl;
    cout << "12 - Extra 2" << endl;
    cout << endl << "Entrar com uma opcao: ";
    cin >> x;
    switch (x) {
    case 1:
      method01();
      pause("Apertar ENTER para continuar");
      break;
    case 2:
      method02();
      pause("Apertar ENTER para continuar");
      break;
    case 3:
      method03();
      pause("Apertar ENTER para continuar");
      break;
    case 4:
      method04();
      pause("Apertar ENTER para continuar");
      break;
    case 5:
      method05();
      pause("Apertar ENTER para continuar");
      break;
    case 6:
      method06();
      pause("Apertar ENTER para continuar");
      break;
    case 7:
      method07();
      pause("Apertar ENTER para continuar");
      break;
    case 8:
      method08();
      pause("Apertar ENTER para continuar");
      break;
    case 9:
      method09();
      pause("Apertar ENTER para continuar");
      break;
    case 10:
      method10();
      pause("Apertar ENTER para continuar");
      break;
    case 11:
      method11();
      pause("Apertar ENTER para continuar");
      break;
    case 12:
      method12();
      pause("Apertar ENTER para continuar");
      break;
    default:
      cout << endl << "ERRO: Valor invalido." << endl;
    }
  } while (x != 0);
  pause("Apertar ENTER para terminar");
  return (0);
}