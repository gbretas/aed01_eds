/*
 Contato.hpp - v0.0. - __ / __ / _____
 Author: ______________________
*/
// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
// outras dependencias
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
#include "erro.hpp"
// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar contatos, derivada da classe Erro.
 */
class Contato : public Erro
{
    /**
   * atributos privados.
   */
private:
    string nome;
    string fone2;
    string fone;
    /**
   * definicoes publicas.
   */
  bool telefoneValido(std::string telefone){
        bool result = 1;
        char traco[2] = "-";
        char aux[2] = "";
        int i = 0;
        int tamanho = telefone.length();
        setErro(0);
        if(tamanho > 12 || tamanho <= 9){
            setErro(2);
            result = 0;
        }else{
            for (i = 0; i < tamanho; i = i+1){
                aux[0] = telefone[i];
                if( !isdigit(telefone[i]) ){
                    setErro(2);
                    result = 0;
                }
            }
        }


        return result;
  }
public:
    /**
   * Destrutor.
   */
    ~Contato() {}
    /**
   * Construtor padrao.
   */
    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        // atribuir valores iniciais vazios
        setErro(0);            // nenhum erro, ainda
        setNome(nome_inicial); // nome = nome_inicial;
        setFone(fone_inicial); // fone = fone_inicial;
    }
     
    Contato ( Contato const & another )
    {
        // atribuir valores iniciais por copia
        setErro ( 0 ); // copiar erro
        setNome ( another.nome ); // copiar nome
        setFone ( another.fone ); // copiar fone
        setFone2 ( another.fone2 ); // copiar fone
    } // fim construtor alternativo

    Contato (  )
    {
        // atribuir valores iniciais por copia
        setErro ( 0 ); // copiar erro
    } // fim construtor alternativo

    Contato(std::string nome_inicial, std::string fone_inicial, std::string fone_inicial2)
    {
        // atribuir valores iniciais vazios
        setErro(0);            // nenhum erro, ainda
        setNome(nome_inicial); // nome = nome_inicial;
        setFone(fone_inicial); // fone = fone_inicial;
        setFone2(fone_inicial2); // fone = fone_inicial;
    }
    

    bool hasErro()
    {
        return (getErro() != 0);
    } // end hasErro ( )

     /**
     * Metodo para ler nome do teclado.
     */
    void readNome(std::string text){
        std::string aux;
        cout << text;cin>>aux;
        setNome(aux);
    }

    void readFones(){
        int resposta = 0;
        if(fone2.empty()){
            cout << "Deseja adicionar o numero 2 de telefone? (1 (sim) / 0 (nao)): ";cin >> resposta;
            if(resposta == 1){
                readFone2("Digite um numero para o telefone 2: ");
            }
        }
    }

    /**
     * Metodo para ler fone do teclado.
     */
    void readFone(std::string text){
        std::string aux;
        cout << text;cin>>aux;
        setFone(aux);
    }
    /**
     * Metodo para ler fone do teclado.
     */
    void readFone2(std::string text){
        std::string aux;
        cout << text;cin>>aux;
        setFone2(aux);
    }

    void erroSet(int n){
        setErro(n);
    }

    /**
     * Metodo para atribuir nome.
     * @param nome a ser atribuido
     */
    void setNome(std::string nome)
    {
        if (nome.empty())
        {
            setErro(1); // fone invalido
        }
        else
        {
            this->nome = nome;
        }
    } // fim setNome ( )
    /**
     * Metodo para atribuir telefone.
     * @param fone a ser atribuido
     */
    void setFone(std::string fone)
    {
        if (fone.empty())
        {
            setErro(2); // fone invalido
        }
        else
        {
            if(telefoneValido(fone)){
                this->fone = fone;
            }
            
        }
    } // fim setFone ( )
    /**
     * Metodo para atribuir telefone.
     * @param fone a ser atribuido
     */
    void setFone2(std::string fone)
    {
        if(fone.empty()){
            this->fone2 = ""; 
        }else{
            if(telefoneValido(fone)){
                this->fone2 = fone; 
            }
        }

            
        
    } // fim setFone ( )

    void fromFile(std::string filename){
        ifstream afile;
        std::string nomeaux, foneaux;
        afile.open(filename);
        afile >> nomeaux;
        afile >> foneaux;

        setNome(nomeaux);
        setFone(foneaux);
    }

    void toFile(std::string filename){
        ofstream afile;
        afile.open(filename);
        afile << getNome() << endl;
        afile << getFone() << endl;
    }
    /**
   * Funcao para obter nome.
   * @return nome armazenado
   */
    std::string getNome() { return (this->nome); } // fim getNome ( )
    /**
   * Funcao para obter fone.
   * @return fone armazenado
   */
    std::string getFone() { return (this->fone); } // fim getFone ( )
    std::string getFone2() { return (this->fone2); } // fim getFone ( )

    int telefones(){
        int result = 0;
        if(!fone.empty()){
            result++;
        }
        if(!fone2.empty()){
            result++;
        }

        return result;
    }


    /**
   * Funcao para obter dados de uma pessoa.
   * @return dados de uma pessoa
   */
    std::string toString()
    {
        if(fone2.empty()){
            return ("{ " + getNome() + ", " + getFone() + " }");
        }else{
             return ("{ " + getNome() + ", " + getFone() + ", "+ getFone2()+" }");
        }
    } // fim toString ( )

    // fim construtor padrao
};                             // fim da classe Contato
using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;
#endif