/*
 myarray.hpp - v0.0. - __ / __ / _____
 Author:689655 Gustavo Torres Bretas Alves
*/
// ----------------------------------------------- definicoes globais
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_
// dependencias
#include <iostream>
using std::cin; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo
template <typename T>
class Array {
private: // area reservada
    int length;
    T* data;

public: // area aberta
    Array(int n)
    {
        // definir valor inicial
        length = n;
        data = NULL;
        // reservar area
        if(n > 0)
        {
            data = new T[length];
        }
    } // end constructor
    void free()
    {
        if (data != NULL) {
            delete (data);
            data = NULL;
        } // end if
    } // end free ( )
    void set(int position, T value)
    {
        if (0 <= position && position <= length) {
            data[position] = value;
        } // end if
    } // end set ( )
    T get(int position)
    {
        T value = 0; // return value has type dependency
        if (0 <= position && position <= length) {
            value = data[position];
        } // end if
        return (value);
    } // end get ( )
    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1) {
            cout << setw(3) << x << " : "
                 << setw(9) << data[x]
                 << endl;
        } // end for
        cout << endl;
    } // end print ( )

    int gerarInt(int inferior, int superior){
        int n;
        n = inferior + rand() % (superior - inferior + 1);
        return n;
    }
    void fprint ( string fileName )
    {
        ofstream afile; // output file
        afile.open ( fileName );
        afile << length << endl;
        for ( int x = 0; x < length; x=x+1 )
        {
            afile << data[ x ] << endl;
        }
        afile.close ( );
    } // end fprint ( )

    void fread ( string fileName )
    {
        ifstream afile; // input file
        int n = 0;
        afile.open ( fileName );
        afile >> n;
        if ( n <= 0 )
        {
            cout << "\nERROR: Invalid length.\n" << endl;
        }
        else
        {
            // guardar a quantidade de dados
            length = n;
            // reservar area
            data = new T [ n ];
            // ler dados
            for ( int x = 0; x < length; x=x+1 )
            {
                afile >> data[ x ];
            } // end for
        } // end if
        afile.close ( );
    } // end fread ( )

    int acharMaior(){
        int i = 0;
        int maior = data[0];
        for (i = 1; i < length; i++){
            if (data[i] > maior){
                maior = data[i];
            }
        }
        return maior;
    }

    int acharMenor(){
        int i = 0;
        int menor = data[0];
        for (i = 1; i < length; i++){
            if (data[i] < menor){
                menor = data[i];
            }
        }
        return menor;
    }

    int linhas(){
        return length;
    }

    int somarValores(){
        int soma = 0;
        int i = 0;
        for (i = 0; i < length; i++){
            soma = soma + data[i];
        }
        return soma;
    }

    float mediaValores(){
        return ((float)somarValores()/(float)length);
    }

    bool zeros(){
        bool result = 1;
        int i = 0;
        for (i = 0; i < length; i++){
            if(data[i] != 0){result = result * 0;}
        }
        return result;
    }

    bool crescente(){
        bool result = 1;
        int i = 0;
        int num = data[0];
        for (i = 1; i < length; i++){
            if(data[i] < num){result = result*0;}
            num = data[i];
        }
        return result;
    }

    bool procurar(int procurado, int inferior, int superior){
        bool result = 1;
        int i = 0;
        for (i = inferior; i < superior; i++){
            if(data[i] == procurado){result = result * 0;}
        }
        return !result;
    }

    void escalar(int constante){
       int i = 0;
        for (i = 0; i < length; i++){
            data[i] = data[i] * constante;
        } 
    }

    void ordenar(){
        int i = 0;
        bool ordenado;

       do{
            ordenado = true;
            for (i = 1; i < length; i++){
                if(data[i] < data[i-1]){
                    int aux;
                    aux = data[i-1];
                    data[i-1] = data[i];
                    data [i] = aux;
                    ordenado = false;
                }
            }
        }while(!ordenado);
    }

    Array& operator- ( const Array <T> other ){
        static Array <T> result ( other );

        if ( other.length == 0 ){
            cout << "\nERROR: Missing data.\n" << endl;
        }else{
            for ( int x = 0; x < this->length; x=x+1 ){
                result.data [ x ] =  this->data [ x ] - result.data [ x ];
            }
        }
        return ( result );
    }

     bool operator!= ( const Array <T> other ){
        bool retorno = 0;

        if ( other.length == 0 ){
            cout << "\nERROR: Missing data.\n" << endl;
        }else{
            for ( int x = 0; x < this->length && retorno == 0; x=x+1 ){
                if(this->data[x] != other.data[x]){
                    retorno = 1;
                }
            }
        }
        return ( retorno );
    }

};
#endif