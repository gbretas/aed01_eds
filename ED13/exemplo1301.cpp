/*
 Exemplo1301 - v0.0. - 18 / 05 / 2020
 Author: 689655 Gustavo Torres Bretas Alves
*/
// ----------------------------------------------- classes
#include "contato.hpp" // classe para tratar dados de pessoas
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos
/**
Method00 - nao faz nada.
*/
void method00() {
	// nao faz nada
}
/**
01.) Fazer um programa (Exemplo1311) para acrescentar um método público à classe Contato
para ler do teclado e atribuir um valor ao nome (atributo de certo objeto).
Incluir um método para testar essa nova característica.
DICA: Testar se o nome não está vazio.
Exemplo: contato1.readNome ( “Nome: ” );
*/
void method01() {
    Contato pessoa;
    pessoa.readNome("Digite um nome: ");
    if(pessoa.hasErro()){
        cout << "Os dados da pessoa possuem o erro: " << pessoa.getErro();
    }else{
        cout << pessoa.toString();
    }
} // fim method01 ( )

/*
02.) Fazer um programa (Exemplo1312) para acrescentar um método público à classe Contato
para ler do teclado e atribuir um valor ao telefone (atributo de certo objeto).
Incluir um método para testar essa nova característica.
DICA: Testar se o telefone não está vazio.
Exemplo: contato1.readFone ( “Fone: ” )
*/
void method02() {
    Contato pessoa;
    pessoa.readFone("Digite um fone: ");
    if(pessoa.hasErro()){
        cout << "Os dados da pessoa possuem o erro: " << pessoa.getErro();
    }else{
        cout << pessoa.toString();
    }
    
} // fim method02 ( )
/*
03.) Fazer um programa (Exemplo1313) para acrescentar um método privado à classe Contato
para testar se o valor de um telefone é válido, ou não.
Incluir um método para testar essa nova característica.
DICA: Testar se as posições contêm apenas algarismos e o símbolo ‘-‘.
*/
void method03() {
    Contato pessoa;
    pessoa.readFone("Digite um fone: ");
    if(pessoa.hasErro()){
        cout << "Os dados da pessoa possuem o erro: " << pessoa.getErro();
    }else{
        cout << pessoa.toString();
    }
}
/*
04.) Fazer um programa (Exemplo1314) para acrescentar um método público à classe Contato
para ler dados de arquivo, dado o nome do mesmo, e armazenar em um objeto dessa classe.
Incluir um método para testar essa nova característica.
Exemplo: contato1.fromFile ( “Pessoa1.txt” );
*/
void method04() {
    Contato pessoa;
    pessoa.fromFile ( "Pessoa1.txt" );
    cout << pessoa.toString();

}
/*
05.) Fazer um programa (Exemplo1315) para acrescentar um método à classe Contato
para gravar dados de uma pessoa em arquivo, dado o nome do mesmo.
Incluir um método para testar essa nova característica.
DICA: Gravar o tamanho também do arquivo, primeiro, antes dos outros dados.
Exemplo: contato.toFile ( “Pessoa1.txt” );
*/
void method05() {
    Contato pessoa;
    pessoa.readNome("Digite um nome: ");
    pessoa.readFone("Digite um fone: ");
    pessoa.toFile ( "Pessoa2.txt" );
    cout << pessoa.toString();
}
/*
06.) Fazer um programa (Exemplo1316) para acrescentar à classe Contato
um novo atributo para um segundo telefone e modificar os construtores para lidar com isso.
Incluir um método para testar essa nova característica.
Exemplo: contato1 = new Contato ( “nome1”, “1111-1111”, “2222-2222” );
*/
void method06() {
    Contato contato("nome1", "3138316026", "3138316027");
     cout << contato.toString();
}
/*
07.) Fazer um programa (Exemplo1317) para acrescentar um método público à classe Contato
um novo atributo para indicar quantos telefones estão associados a cada objeto.
Incluir um método para obter essa informação.
Incluir um método para testar essa nova característica.
Exemplo: int n = contato1.telefones ( );
*/
void method07() {
    Contato contato("nome1", "3138316026", "3138316027");
    int n = contato.telefones();
    cout << "O contato tem " << n << " telefones";
}
/*
08.) Fazer um programa (Exemplo1318) para acrescentar um método público à classe Contato
para atribuir o valor do segundo telefone.
Incluir um método para testar essa nova característica.
DICA: Se o contato só tiver um telefone, perguntar se quer acrescentar mais um número,
e mudar automaticamente a quantidade deles, se assim for desejado.
Exemplo: contato.setFone2a ( “3333-3333” );
*/
void method08() {
    Contato contato("nome1", "3138316026", "");
    contato.readFones();
    if(contato.hasErro()){
        cout << "Os dados da pessoa possuem o erro: " << contato.getErro();
    }else{
        cout << contato.toString();
    }

}
/*
09.) Fazer um programa (Exemplo01319) para acrescentar um método público à classe Contato
para alterar o valor apenas do segundo telefone.
Incluir um método para testar essa nova característica.
DICA: Se o contato não tiver dois telefones, uma situação de erro deverá ser indicada.
Exemplo: contato.setFone2b ( “3333-3333” );
*/
void method09() {
    Contato contato("nome1", "3138316026", "");
    contato.readFones();
    if(contato.telefones() != 2){
        contato.erroSet(3);
    }
    if(contato.hasErro()){
        cout << "Os dados da pessoa possuem o erro: " << contato.getErro();
    }else{
        cout << contato.toString();
    }
}
/*
10.) Fazer um programa (Exemplo0240) para acrescentar um método público à classe Contato
para remover apenas o valor do segundo telefone.
Incluir um método para testar essa nova característica.
DICA: Se o contato só tiver um telefone, uma situação de erro deverá ser indicada.
Exemplo: contato.setFone2c ( "" );
*/
void method10() {
    Contato contato("nome1", "3138316026", "3138316027");
    
    if(contato.telefones() == 1){
        contato.erroSet(4);
    }
    contato.setFone2("");
    if(contato.hasErro()){
        cout << "Os dados da pessoa possuem o erro: " << contato.getErro();
    }else{
        cout << contato.toString();
    }
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