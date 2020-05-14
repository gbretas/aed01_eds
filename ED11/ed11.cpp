/*
 Exemplo1101 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
 Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // definir dados
    Array<int> int_array(5);
    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);
    // identificar
    cout << "\nEXEMPLO1101 - Method01 - v0.0\n" << endl;
    // mostrar dados
    int_array.print();
    // reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method01 ( )
/**
 Method02.
*/
void method02()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method02 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method02 ( )
/**
 Method03.
*/
void method03()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method03 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method03 ( )
/**
 Method04.
*/
void method04()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method04 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method04 ( )
/**
 Method05.
*/
void method05()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method05 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method05 ( )
/**
 Method06.
*/
void method06()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method06 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method06 ( )
/**
 Method07.
*/
void method07()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method07 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method07 ( )
/**
 Method08.
*/
void method08()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method08 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method08 ( )
/**
 Method09.
*/
void method09()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method09 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method09 ( )
/**
 Method10.
*/
void method10()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method10 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method10 ( )
// ----------------------------------------------- acao principal
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main(int argc, char** argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - mostrar dados inteiros em arranjo " << endl;
        cout << " 2 - " << endl;
        cout << " 3 - " << endl;
        cout << " 4 - " << endl;
        cout << " 5 - " << endl;
        cout << " 6 - " << endl;
        cout << " 7 - " << endl;
        cout << " 8 - " << endl;
        cout << " 9 - " << endl;
        cout << "10 - " << endl;
        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
        switch (x) {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        } // fim escolher
    } while (x != 0);
    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )