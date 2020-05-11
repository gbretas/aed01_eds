/*
ED08 - 10/05/2020
Author: 689655 Gustavo Torres Bretas Alves
*/
#include "io.h"

void showArrayInt(int array[], int i){
    int show;
    for (show=0;show<i;show++){
        IO_printf("%i: %i\n", show, array[show]);
    }
}

/*
01.) Incluir em um programa (Exemplo0811) um método para
ler o tamanho de um arranjo para inteiros do teclado,
bem como todos os seus elementos, garantindo que só tenha valores positivos e ímpares.
Verificar se as dimensões não são nulas ou negativas.
Para testar, ler diferentes quantidades de dados
*/
void metodo1(){
    int i, lidos;
    i = IO_readint("Digite uma quantidade de numeros a serem lidos: ");
    IO_line();
    int array[i+1];
    for ( lidos = 0; lidos < i; lidos++){
        array[lidos] = IO_readint("Digite um numero: ");
        while(array[lidos] < 0 || array[lidos] % 2 ==0){
            array[lidos] = IO_readint("Digite um numero valido: ");
        }
    }
    IO_line();
    showArrayInt(array, i);
}

/*
02.) Incluir em um programa (Exemplo0812) um método para
ler um arranjo com inteiros positivos de arquivo.
Valores negativos e também os pares deverão ser descartados.
O arranjo e o nome do arquivo serão dados como parâmetros.
Guardar primeiro o tamanho, depois os elementos, um dado por linha.
Para testar, ler diferentes quantidade de dados.
*/
/*
1 - Ler nome do arquivo
2 - Salvar em um outro arquivo os positivos impares (RESULTADO0812.txt)
*/
void metodo2(){
    char* arquivo_nome;
    int array[60];
    int x = 0;

    arquivo_nome = IO_readstring("Digite um nome do arquivo a ser lido: ");

    FILE * arquivo_salvar = fopen("RESULTADO0812.txt", "wt");
    FILE * arquivo_ler = fopen(arquivo_nome, "rt");

    fscanf ( arquivo_ler, "%d", &x );
    while (! feof(arquivo_ler)){
        if(x > 0 && x % 2 == 1){
            fprintf(arquivo_salvar, "%i\n", x);
        }
        fscanf(arquivo_ler, "%d", &x);
    }

    fclose(arquivo_ler);
    fclose(arquivo_salvar);
}

/*
* @int gerarInt( int limite_inferior, int limite_superior )
* @params    int limite_inferior - Limite inferior para gerar o inteiro
* @params    int limite_superior - Limite superior para gerar o inteiro
* @return    int
*/
int gerarInt(int limite_inferior, int limite_superior){
    return limite_inferior + (rand() % (limite_superior - limite_inferior + 1));
}
/*
* @void gerarInteiros( int limite_inferior, int limite_superior, int qntd )
* @params    int limite_inferior - Limite inferior para gerar o inteiro
* @params    int limite_superior - Limite superior para gerar o inteiro
* @params    int qntd - Quantidade de inteiros para gerar e armazenar no arquivo
*/
void gerarInteiros(int limite_inferior, int limite_superior, int qntd){
    int i = 0;
    int num = 0;
    int array[qntd+1];
    FILE * dados = fopen("DADOS.TXT", "wt");
    fprintf(dados, "%i\n", qntd);
    srand( (unsigned)time( NULL ) );
    for (i = 0; i < qntd; i++){
        
        num = gerarInt(limite_inferior, limite_superior);
        array[i] = num;
        fprintf(dados, "%i\n", num);
    }
    fclose(dados);
}
/*
03.) Incluir em um programa (Exemplo0813) uma função para
gerar um valor inteiro aleatoriamente dentro de um intervalo,
cujos limites de início e de fim serão recebidos como parâmetros;
Para para testar, ler os limites do intervalo do teclado;
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatórios
dentro do intervalo e armazená-los em arranjo;
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
DICA: Usar a função rand( ), mas tentar limitar valores muito grandes (usar mod=%).
Exemplo: valor = gerarInt ( inferior, superior );
*/
void metodo3(){
    int inferior, superior, qntd;
    inferior = IO_readint("Digite um valor para o limite inferior: ");
    superior = IO_readint("Digite um valor para o limite superior: ");
    if(superior <= inferior){
        IO_printf("ERROR: Limite Invalido");
    }else{
        qntd = IO_readint("Digite uma quantidade de valores a serem gerados: ");
        gerarInteiros(inferior, superior, qntd);
    }
    
}

/*
* @int acharMaior( int arranjo[], int n)
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
*/
int acharMaior(int arranjo[], int n){
    int result = 0;
    int i = 0;
    if(i > n || i < 0){
        IO_printf("ERROR: numero de elementos buscados invalidos");
    }else{
        for(i=1; i<n ;i++){
            if(arranjo[i] > result){
                result = arranjo[i];
            }
        }
    }
    return result;
}

/*
04.) Incluir em um programa (Exemplo0814) uma função para
procurar o maior valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor da tabela como referência inicial
para o maior valor.
Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
maior = acharMaior ( arranjo, n );
*/
void metodo4(){
    chars nome_arquivo;
    nome_arquivo = IO_readstring("Digite o nome do arquivo de dados: ");
    int i;
    int n;
    int x;
    int maior;
    FILE * arquivo = fopen(nome_arquivo, "rt");
    fscanf(arquivo, "%i", &x);
    n = x;
    int arranjo[x];

    if(n > x){
        IO_printf("ERROR: Quantidade de dados nao disponiveis no arquivo");
    }else{
        for(i=1; i<n; i++){
            arranjo[i] = x;
            fscanf(arquivo, "%i", &x);
        }
    }
    fclose(arquivo);
    maior = acharMaior(arranjo, n);
    IO_printf("O maior valor do arranjo e: %i", maior);
}

/*
* @int acharMenor( int arranjo[], int n)
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
*/
int acharMenor(int arranjo[], int n){
    int result = arranjo[1];
    int i = 0;
    if(i > n || i < 0){
        IO_printf("ERROR: numero de elementos buscados invalidos");
    }else{
        for(i=1; i < n ;i++){
            if(arranjo[i] < result){
                result = arranjo[i];
            }
        }
    }
    return result;
}

/*
05.) Incluir em um programa (Exemplo0815) uma função para
procurar o menor valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor da tabela como referência inicial.
Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
menor = acharMenor ( n, arranjo );
*/
void metodo5(){
    chars nome_arquivo;
    nome_arquivo = IO_readstring("Digite o nome do arquivo de dados: ");
    int i;
    int n;
    int x;
    int maior;
    FILE * arquivo = fopen(nome_arquivo, "rt");
    fscanf(arquivo, "%i", &x);
    n = x;
    int arranjo[x];

    if(n > x){
        IO_printf("ERROR: Quantidade de dados nao disponiveis no arquivo");
    }else{
        for(i=1; i<n; i++){
            arranjo[i] = x;
            fscanf(arquivo, "%i", &x);
        }
    }
    fclose(arquivo);
    maior = acharMenor(arranjo, n);
    IO_printf("O menor valor do arranjo e: %i", maior);
}


/*
* @int acharMedia( int arranjo[], int n)
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
*/
double acharMedia(int arranjo[], int n){
    double result = 0;
    double soma = 0;
    int i = 0;
    int valor = 0;
    //IO_printf("%i\n", n);
    if(i > n || i < 0){
        IO_printf("ERROR: numero de elementos buscados invalidos");
    }else{
        for(i=0; i < n ;i++){
            soma = soma+arranjo[i];
        }
    }
    result = (double)soma/n;
    return result;
}
/*
* @int  salvarAcimaAbaixoMedia(int arranjo[], int n, double media)
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
* @params    double media - media do arranjo
*/
void  salvarAcimaAbaixoMedia(int arranjo[], int n, double media){
    int num, i;
    FILE * acima = fopen("RESULTADO0816ACIMA.txt", "wt");
    FILE * abaixo = fopen("RESULTADO0816ABAIXO.txt", "wt");
    for(i=0; i < n ;i++){
        num = arranjo[i];
        if(num > media){
            fprintf(acima, "%i\n", num);
        }
        if(num < media){
            fprintf(abaixo, "%i\n", num);
        }
    }

    fclose(abaixo);
    fclose(acima);
}
/*
06.) Incluir em um programa (Exemplo0816) uma função para
para determinar a média valores em um arranjo.
Para testar, ler o arquivo ("DADOS.TXT")
armazenar os dados em um arranjo;
separar em dois outros arquivos,
os valores maiores ou iguais à média, e os menores que ela.
Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
media = acharMedia ( n, arranjo );
*/
void metodo6(){
    chars nome_arquivo;
    nome_arquivo = IO_readstring("Digite o nome do arquivo de dados: ");
    int i;
    int n;
    int x;
    double media;
    FILE * arquivo = fopen(nome_arquivo, "rt");
    fscanf(arquivo, "%i", &x);
    n = x;
    int arranjo[x];

    if(n > x){
        IO_printf("ERROR: Quantidade de dados nao disponiveis no arquivo");
    }else{
        for(i=0; i<n; i++){
            arranjo[i] = x;
            fscanf(arquivo, "%i", &x);
        }
    }
    fclose(arquivo);
    media = acharMedia(arranjo, n);
    IO_printf("A media dos valores do arranjo e: %lf", media);
    salvarAcimaAbaixoMedia(arranjo, n, media);
}

/*
* @bool ordenadoEmCrescente( int arranjo[], int n)
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
*/
bool ordenadoEmCrescente(int arranjo[], int n){
    bool result = 1;
    int i = 0;
    int atual = 0;
    int anterior = 0;
    atual = arranjo[2];
    for (i = 3; i < n + 1; i++){
        anterior = atual;
        atual = arranjo[i];
        if(anterior > atual){
            result = result * 0;
        }
    }
    return result;
}
/*
07.) Incluir em um programa (Exemplo0817) uma função para
receber como parâmetro um arranjo
e dizer se está ordenado, ou não, em ordem crescente.
DICA: Testar se não está desordenado, ou seja,
se existe algum valor que seja maior que o seguinte.
Não usar break !
*/
void metodo7(){
    int n;
    int x;
    int i;
    FILE * arquivo = fopen("DADOSMETODO7.txt", "rt");
    fscanf(arquivo, "%d", &x);
    n = x;
    int arranjo[n];
    for(i=1; i < n + 1; i++){
        arranjo[i] = x;
        fscanf(arquivo, "%d", &x);
    }
    
    if(ordenadoEmCrescente(arranjo, n)){
        IO_print("O arranjo esta ordenado em ordem crescente");
    }else{
         IO_print("O arranjo nao esta ordenado em ordem crescente");
    }

    fclose(arquivo);
}

/*
* @bool acharValor( int arranjo[], int n, int procurado, int posicao )
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
* @params    int procurado - numero a ser procurado
* @params    int posicao - posicao para partir a busa
*/
bool acharValor(int arranjo[], int n, int procurado, int posicao){
    bool result = 0;
    int i;
    if(posicao > n){
        IO_printf("ERROR: Posiciao de inicio invalida");
    }else{
        for (i = posicao; i < n; i++){
            if(arranjo[i] == procurado){
                result = 1;
            }
        }
    }
    return result;
}
/*
08.) Incluir em um programa (Exemplo0818) uma função para
procurar por determinado valor em arranjo e
dizer se esse valor pode ser nele encontrado,

indicada a posição inicial para se começar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;

ler do teclado um valor inteiro para ser procurado;
determinar se o valor procurado existe no arranjo,
a partir da posição indicada.

Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
existe = acharValor ( n, arranjo, procurado, 0 );
*/
void metodo8(){
    FILE * dados = fopen("DADOS.txt", "rt");
    int x, i, n, procurado, posicao;
    fscanf(dados, "%d", &x);
    n=x;
    int arranjo[n+1];
    for(i = 1; i< n+1; i++){
        arranjo[i] = x;
        fscanf(dados, "%d", &x);
    }
    procurado = IO_readint("Digite um numero a ser procurado no arranjo: ");
    posicao = IO_readint("Digite a posicao de inicio para procurar no arranjo: ");
    if( acharValor(arranjo, n, procurado, posicao)){
        IO_printf("O numero %i partindo da posicao %i foi encontrado no arranjo", procurado, posicao);
    }else{
         IO_printf("O numero %i partindo da posicao %i nao foi encontrado no arranjo", procurado, posicao);
    }
   
    fclose(dados);
}

/*
* @double acharValorPosicao( int arranjo[], int n, int procurado, int posicao )
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
* @params    int procurado - numero a ser procurado
*/
double acharValorPosicao(int arranjo[], int n, int procurado){
    double result = -2;
    int i;
    for (i = 1; i < n; i++){
        if(arranjo[i] == procurado){
            result = i - 1;
         }
    }
    
    return result;
}
/*
09.) Incluir em um programa (Exemplo0819) uma função para
procurar por determinado valor em arranjo e
dizer onde se encontra esse valor,
indicada a posição inicial para começar a procura.

Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;

ler do teclado um valor inteiro para ser procurado;
determinar onde o valor procurado está no arranjo,
se houver.

Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
onde = acharPosicao ( n, arranjo, procurado, 0 );
*/
void metodo9(){
    FILE * dados = fopen("DADOS.txt", "rt");
    int x, i, n, procurado;
    double posicao;
    fscanf(dados, "%d", &x);
    n=x;
    int arranjo[n+1];
    for(i = 1; i< n+1; i++){
        arranjo[i] = x;
        fscanf(dados, "%d", &x);
    }
    procurado = IO_readint("Digite um numero a ser procurado no arranjo: ");
    posicao = acharValorPosicao(arranjo, n, procurado);
    
    if( posicao != -2 ){
        IO_printf("O numero %i foi encontrado no arranjo na posicao %.0lf", procurado, posicao);
    }else{
         IO_printf("O numero %i nao foi encontrado no arranjo", procurado);
    }
   
    fclose(dados);
}

/*
* @int acharQuantos( int arranjo[], int n, int procurado, int posicao )
* @params    int arranjo - Arranjo de inteiros
* @params    int n - quantidade de dados
* @params    int procurado - numero a ser procurado
* @params    int posicao - posicao para partir a busa
*/
int acharQuantos(int arranjo[], int n, int procurado, int posicao){
    int result = 0;
    int i;
    if(posicao > n){
        IO_printf("ERROR: Posiciao de inicio invalida");
    }else{
        for (i = posicao; i < n; i++){
            if(arranjo[i] == procurado){
                result = result + 1;
            }
        }
    }
    return result;
}
/*
10.) Incluir em um programa (Exemplo0820) uma função para
procurar por determinado valor em arranjo e
dizer quantas vezes esse valor pode ser encontrado,
indicada a posição inicial para começar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar quantas vezes o valor procurado aparece no arranjo,
se houver.
Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
vezes =acharQuantos ( n, arranjo, procurado, 0 );
*/
void metodo10(){
    FILE * dados = fopen("DADOS.txt", "rt");
    int x, i, n, procurado, posicao, encontrados;
    fscanf(dados, "%d", &x);
    n=x;
    int arranjo[n+1];
    for(i = 1; i< n+1; i++){
        arranjo[i] = x;
        fscanf(dados, "%d", &x);
    }
    procurado = IO_readint("Digite um numero a ser procurado no arranjo: ");
    posicao = IO_readint("Digite a posicao de inicio para procurar no arranjo: ");
    encontrados = acharQuantos(arranjo, n, procurado, posicao);
    if( encontrados > 0 ){
        IO_printf("\nO numero %i partindo da posicao %i foi encontrado %i vezes no arranjo", procurado, posicao, encontrados);
    }else{
         IO_printf("\nO numero %i partindo da posicao %i nao foi encontrado nenhuma vez no arranjo", procurado, posicao);
    }
   
    fclose(dados);
}

/*
* @int divisores( int numero )
* @params    int numero - Numero para buscar os divisores
* @result    int        - Quantidade de divisores do numero
*/
int divisores(int numero){
    int divisores[numero];
    int divisor;
    int quantidade = 0;
    int i = 0;
    divisor = numero;

    FILE * f_divisores = fopen("DIVISORES.txt", "wt");

    while(divisor != 0){
        if(numero % divisor == 0){
            IO_printf("O numero %i tem o %i como divisor\n", numero, divisor);
            IO_fprintf(f_divisores, "O numero %i tem o %i como divisor\n", numero, divisor);
            divisores[i] = divisor;
            i++;
            quantidade++;

        }
        divisor--;
    }

    fclose(f_divisores);
    return quantidade;
    
}

/*
E1.) Incluir em um programa (Exemplo08E1) uma função para
ler um valor inteiro do teclado,

e mediante funções para calcular e retornar a quantidade
e seus divisores guardados em arranjo,
o qual deverá ser mostrado na tela após o retorno,
bem como gravado em arquivo ( "DIVISORES.TXT" ).
DICA: Supor que a quantidade de divisores
será menor ou igual ao próprio número.
*/
void extra1(){
    int num;
    num = IO_readint("Digite um numero para buscar seus divisores: ");
    IO_line();
    IO_printf("O numero %i tem %i divisores", num, divisores(num));
}

/*
E2.) Incluir em um programa (Exemplo08E1) uma função para
ler um arquivo ( "PALAVRAS.TXT" ),
e mediante uma função retornar as dez primeiras palavras
que não comecem pela letra 'a' (ou 'A'), se houver.
As palavras encontradas deverão ser exibidas na tela,
após retorno.
DICA: Supor que a quantidade de palavras não ultrapassará 100
*/
void extra2(){
    int comemcando_com_a = 0;
    int i = 0;
    FILE* arquivo = fopen ( "PALAVRAS.txt", "rt" );
    chars linha = IO_new_chars ( STR_SIZE );
    strcpy ( linha, IO_freadln ( arquivo ) );
    while ( ! feof (arquivo) && strcmp ( "PARAR", linha ) != 0 && comemcando_com_a < 10){
        if(linha[0] == 'A' || linha[0] == 'a'){
            IO_printf("%s: comeca com a ou A\n", linha);
            comemcando_com_a++;
        }
        strcpy ( linha, IO_freadln ( arquivo ) );
    }
    fclose ( arquivo );
}

void select() {
    int atividade;
    IO_id("ED08 - 10 mai 2020");

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
