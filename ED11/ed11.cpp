/*
 Exemplo1101 - v0.0. - __ / __ / _____
 Author: 689655 Gustavo Torres Bretas Alves
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
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos

/**
01.) Incluir em um programa (Exemplo1111)
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatórios
dentro do intervalo e armazená-los em arranjo;
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
DICA Usar a função rand( ), mas tentar limitar valores muito grandes.
Exemplo: valor = arranjo.gerarInt ( inferior, superior );
*/
void method01()
{
    int n;
    int i = 0;
    int inferior, superior;
    cout << "\nEXEMPLO1101 - Method01 - v0.0\n" << endl;
    cout << endl << "Digite uma quantidade de dados a serem gerados: ";
    cin >> n;
    Array<int> arranjo(n);
    if(n >= 0){
        cout << endl << "Digite um valor para o limite inferior: ";
        cin >> inferior;

        cout << endl << "Digite um valor para o limite superior: ";
        cin >> superior;

        if(superior <= inferior){
            cout << endl << "\nERROR: Nao ha um limite valido\n";
        }else{
            for (i=0; i<n; i=i+1){
                arranjo.set(i, arranjo.gerarInt(inferior, superior));
            }
            arranjo.fprint("DADOS.TXT");
        }
    }else{
        cout << endl << "\nERROR: Digite uma quantidade valida de valores a serem gerados\n";
    }
    arranjo.free();
}

/**
02.) Incluir em um programa (Exemplo1112) uma função para
procurar o maior valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA Usar o primeiro valor como referência inicial.
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
maior = arranjo.acharMaior ( );
*/
void method02()
{
    int maior = 0;
    cout << endl;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    maior = arranjo.acharMaior();
    cout << "O maior numero do arranjo e: " << maior << endl;
    arranjo.free();
}


/**
03.) Incluir em um programa (Exemplo1113) uma função para
procurar o menor valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;

DICA Usar o maior valor como referência inicial.
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
menor = arranjo.acharMenor ( );
*/
void method03()
{
    int menor = 0;
    cout << endl;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    menor = arranjo.acharMenor();
    cout << "O menor numero do arranjo e: " << menor << endl;
    arranjo.free();
}

/**
04.) Incluir em um programa (Exemplo1114) uma função para
somar todos os valores em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
soma = arranjo.somarValores ( );
*/
void method04()
{
    int soma;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    soma = arranjo.somarValores();
    cout << "A soma dos valores do arranjo e: " << soma << endl;
    arranjo.free();
}


/**
05.) Incluir em um programa (Exemplo1115) uma função para
achar a média dos valores em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
media = arranjo.mediaValores( );
*/
void method05()
{
    float media;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    media = arranjo.mediaValores();
    cout << "A media dos valores do arranjo e: " << media << endl;
    arranjo.free();
}



/**
06.) Incluir em um programa (Exemplo1116) uma função para
verificar se todos os valores são iguais a zero em um arranjo.
Para testar, ler o arquivo ("DADOS.TXT")
armazenar os dados em um arranjo.
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
teste = arranjo.zeros ( );
*/
void method06()
{
    bool zeros = 0;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    zeros = arranjo.zeros();
    if(zeros){
        cout << "Nesse arranjo todos valores sao iguais a zero"<<endl;
    }else{
        cout << "Nesse arranjo existem valores diferentes de zero"<<endl;
    }
    arranjo.free();
}

/**
07.) Incluir em um programa (Exemplo1117) uma função para
dizer se está ordenado, ou não, em ordem crescente.
DICA: Testar se não está desordenado, ou seja,
se existe algum valor que seja menor que o seguinte.
Não usar break !
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
teste = arranjo.crescente ( );
*/
void method07()
{
    bool crescente = 0;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    crescente = arranjo.crescente();
    if(crescente){
        cout << "Nesse arranjo os valores estao em ordem crescente"<<endl;
    }else{
        cout << "Nesse arranjo os valores nao estao em ordem crescente"<<endl;
    }
    arranjo.free();
}


/**
08.) Incluir em um programa (Exemplo1118) uma função para
dizer se determinado valor está presente em arranjo,
entre duas posições indicadas.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar se o valor procurado existe no arranjo.
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
existe = arranjo.acharValor ( procurado, 5, 10 );
*/
void method08()
{
    bool existe = 0;
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    int procurado = 0;
    int inferior = 0;
    int superior = 0;
    cout << "Digite um numero a procurar no arranjo: ";cin >> procurado;cout << endl;
    cout << "Digite o valor do limite inferior: ";cin >> inferior;cout << endl;
    cout << "Digite o valor do limite superior: ";cin >> superior;cout << endl;

    if (inferior < 0 || superior <= inferior || superior > arranjo.linhas()){
        cout << "ERROR: Nao ha um limite valido";
    }else{
        existe = arranjo.procurar( procurado, inferior, superior);
        if(existe){
            cout << "Valor encontrado no arranjo nos limites definidos"<<endl;
        }else{
            cout << "Valor nao encontrado no arranjo nos limites definidos"<<endl;
        }
    }
    arranjo.free();
}


/**
09.) Incluir em um programa (Exemplo1119) uma função para
escalar o arranjo, multiplicando cada valor por uma constante.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para indicar a constante.
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
novo = arranjo.escalar( constante );
*/
void method09()
{
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    int constante = 0;
    cout << "Digite um valor para escalar o arranjo: ";cin >> constante;cout << endl;
    arranjo.escalar(constante);
    arranjo.fprint("METODO09.TXT");
}

/**
10.) Incluir em um programa (Exemplo1120) um método para
colocar valores em arranjo em ordem crescente,
mediante trocas de posições, até ficar totalmente ordenado.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo.
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
arranjo.ordenar ( );
*/
void method10()
{
    Array<int> arranjo(0);
    arranjo.fread("DADOS.txt");
    arranjo.ordenar();
    arranjo.fprint("METODO10.TXT");
}

/*
E1.) Incluir em um programa (Exemplo11E1) um operador (!=) para
dizer se dois arranjos são diferentes, pelo menos em uma posição.
*/
void method11(){
    bool result;
    Array<int> arranjo(0);
    Array<int> arranjo_2(0);

    arranjo.fread("DADOS.txt");
    arranjo_2.fread("DADOS2.txt");

    result = (arranjo != arranjo_2);
    if(result){
        cout << "Os arranjos sao diferentes" << endl;
    }else{
        cout << "Os arranjos nao sao diferentes" << endl;
    }
}

/*
E2.) Incluir em um programa (Exemplo11E2) um operador (-) para
calcular as diferenças entre dois arranjos, posição por posição
*/
void method12(){
    Array<int> arranjo(0);
    Array<int> arranjo_2(0);
    Array<int> arranjo_resultado(0);
    arranjo.fread("DADOS.txt");
    arranjo_2.fread("DADOS2.txt");
    arranjo_resultado =  arranjo - arranjo_2;
    arranjo_resultado.print();
}

// ----------------------------------------------- acao principal
int main(int argc, char** argv)
{
    int x = 0;
    do {
        cout << "ED 11 - 14/05/2020\n " << endl;
        cout << "ED 11 - 689655 Gustavo Torres Bretas Alves\n " << endl;
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
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        }
    } while (x != 0);
    pause("Apertar ENTER para terminar");
    return (0);
}