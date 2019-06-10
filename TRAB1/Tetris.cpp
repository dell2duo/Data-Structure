#include <iostream>
#include "Tetris.h"

Tetris::Tetris(const int colunas){
    n_colunas = colunas;
    alturas = new int [n_colunas];
    jogo = new char*[n_colunas];
    /*Alocamos um vetor de ponteiros char de tamanho 'colunas' e
    um vetor para guardar as alturas das colunas.
    Agora vamos apontar esses ponteiros criados em 'jogo' para NULL
    para maior segurança (ex.: caso o destrutor tente apagar um ponteiro
    não alocado).*/
    for(int i=0;i<n_colunas;i++){
        alturas[i] = 0;
        jogo[i] = NULL;
    }
}
Tetris::Tetris(const Tetris &other){
    alturas = NULL;
    jogo = NULL;
    *this = other;
}
Tetris::~Tetris(){
    delete[] alturas;

    for(int i=0;i<n_colunas;i++) delete[] jogo[i];

    delete[] jogo;
}
Tetris & Tetris::operator= (const Tetris &other){
    if(this == &other) return *this;

    if(jogo != NULL){//Necessário para casos de construção por cópia!
        delete[] alturas;
        for(int i=0;i<n_colunas;i++) delete[] jogo[i];
        delete[] jogo;
    }

    n_colunas = other.n_colunas;
    alturas = new int [n_colunas];
    for(int i=0;i<n_colunas;i++) alturas[i] = other.alturas[i];

    jogo = new char*[n_colunas];
    for(int i=0;i<n_colunas;i++) jogo[i] = new char[other.getAltura(i)];

    for(int c=0;c<n_colunas;c++){
        for(int l=0;l<other.getAltura(c);l++){
            jogo[c][l] = other.jogo[c][l];
        }
    }

    return *this;
}
char Tetris::get(const int coluna, const int linha) const{ //retorna um char que representa um "píxel".
    if(linha >= getAltura(coluna)) return ' ';
    return jogo[coluna][linha];
}
void Tetris::removeColuna(const int coluna){
    if(coluna < 0 || coluna > n_colunas) return;//Condição de segurança.

    /*Cria um novo vetor com uma coluna a menos, aponta os ponteiros
    para os ponteiros de 'jogo' e então deleta 'jogo' e o aponta
    ao novo vetor*/
    char **temp = new char* [n_colunas-1];
    for(int i=0, j=0;i<n_colunas;i++){ //'i' será contador para jogo
                                       //'j' será contador para temp
        if(i != coluna){
            temp[j] = jogo[i];
            j++;
        }
    }
    n_colunas--;

    delete[] jogo[coluna];
    delete[] jogo;
    jogo = temp;

    /*O vetor 'alturas' será redefinido também*/
    int *temp2 = new int [n_colunas];
    for(int i=0, j=0;i<n_colunas;i++){ //'i' será contador para alturas
                                       //'j' será contador para temp2
        if(i != coluna){
            temp2[j] = alturas[i];
            j++;
        }
    }

    delete[] alturas;
    alturas = temp2;
}
/*Observação: A função removeLinhasCompletas terá nível de complexidade O(n^3) no pior dos casos
onde todas as linhas estão completas*/
void Tetris::removeLinhasCompletas(){
    /*Iremos fixar uma linha 'l' e variar as colunas 'c'. Caso todas
    não estejam ocupadas por um 'espaço vazio', vamos remover a linha
    e realocar as colunas para um tamanho menor conforme o número de
    linhas completas*/
    for(int l=0;l<getAltura();l++){
        for(int c=0;c<getNumColunas();c++){
            if(getAltura(c) == 0) //Caso alguma altura for 0, não remove linha.
                return;
            if(l > (getAltura(c)-1)) //Condição de parada para 'l'.
                return;
        }

        /*Iremos percorrer a linha, se houver um elemento ' ' (espaço) setamos a
        variável booleana 'allowRemoval' para 'false'. Assim não iremos remover
        linhas com caracteres vazios.*/
        bool allowRemoval = true;
        for(int c=0;c<getNumColunas();c++){
            if(jogo[c][l] == ' ') allowRemoval = false;
        }
        if(allowRemoval){
            Tetris temp(n_colunas);
            //Copia os valores de altura para o objeto 'temp' uma unidade menor
            for(int i=0;i<temp.getNumColunas();i++)
                temp.alturas[i] = alturas[i] - 1;
            /*Quando alocamos um novo vetor que representa uma coluna de Tetris,
            já copiamos os valores do vetor do objeto da classe para o novo vetor
            no objeto auxiliar 'temp'. Em seguida, passamos os dados de 'temp' para
            'this' através do operador de igualdade.

            Para realizarmos a cópia dos vetores, devemos ignorar a linha completa
            do objeto 'this'. Para isso, criaremos duas variáveis. 'l1' percorre 'this'
            e 'l2' percorre o vetor de 'temp'. Caso 'l1' seja igual à linha a ser removida,
            iremos ignorar essa interação através do comando 'continue'. 'l1' será
            acrescentado e 'l2' não. Assim, só iremos copiar os valores diferentes da linha
            completa que está sendo removida.

            Como uma linha foi removida e alteramos os valores de 'this', iremos decrescentar
            uma unidade na variável 'l', caso contrário, não iremos verificar se a linha des_
            locada está completa.*/
            for(int c=0;c<temp.getNumColunas();c++){
                temp.jogo[c] = new char[temp.getAltura(c)];
                for(int l1=0,l2=0;l2<temp.getAltura(c);l1++){
                    if(l1 == l) continue;

                    temp.jogo[c][l2] = jogo[c][l1];
                    l2++;
                }
            }
            /*Checa se, após a remoção, existe alguma coluna com espaços alocados acima do último
            píxel diferente de ' '(espaço)*/
            for(int c=0;c<temp.getNumColunas();c++){
                bool allowRemoval = true;
                for(int linhaAux=0;linhaAux<temp.getAltura(c);linhaAux++){
                    if(temp.jogo[c][linhaAux] != ' ') allowRemoval = false;
                }
                if(allowRemoval && (temp.getAltura(c) > 0)){
                    temp.alturas[c] = 0;
                    delete[] temp.jogo[c];
                    temp.jogo[c] = NULL;
                }
            }

            *this = temp;
            l--;
        }
    }
}
int Tetris::getNumColunas() const {return n_colunas;}
int Tetris::getAltura(const int coluna) const {
    if(coluna < 0 || coluna > getNumColunas() || alturas == NULL) return 0;
    return alturas[coluna];
}
int Tetris::getAltura() const { //retorna o maior valor de altura no array 'alturas'.
    int temp = getAltura(0);
    for(int i=1;i<getNumColunas();i++){
        if(alturas[i] > temp) temp = alturas[i];
    }

    return temp;
}
void Tetris::realocColuna(const int coluna, const int tam){/*Função que realoca uma coluna. Caso não esteja alocada,
    faz a alocação e seta seus valores para o caractere espaço(' '). Caso contrário, irá realocar e copiar os an_
    tigos dados do vetor original*/
    if(jogo[coluna] == NULL){
        jogo[coluna] = new char[tam+1];
        alturas[coluna] = tam+1;
        for(int l=0;l<getAltura(coluna);l++) jogo[coluna][l] = ' ';
    }
    else{
        char *temp = jogo[coluna];
        jogo[coluna] = new char[tam+1];
        for(int l=0;l<tam+1;l++) jogo[coluna][l] = ' ';
        for(int l=0;l<getAltura(coluna);l++) jogo[coluna][l] = temp[l];
        alturas[coluna] = tam+1;
        delete[] temp;
    }

}
bool Tetris::adicionar(const int coluna, const int linha, char fig[][4]){
    if(coluna < 0 || coluna >= getNumColunas() || linha < 0) return false;

    /*Através destes dois comandos de repetição, vamos percorrer a matriz 'fig' e 'jogo' no modelo
    up-bottom. Caso, em uma mesma posição, houver uma parte de uma figura do jogo, retornaremos
    'false', indicando que não é possível adicionar a peça ao jogo.*/
    for(int l=linha,j=0;(j<4) && l>=0;l--,j++){
        for(int c=coluna,i=0;(i<4) && (c<getNumColunas());c++,i++){
            if(jogo[c] == NULL || l >= getAltura(c)) continue;
            if((jogo[c][l]!=' ')&&(fig[j][i]!=' ')) return false;
        }
    }
    /*Partindo da altura 'linha', varremos as 4 posições inferiores. Caso exista um píxel da peça na
    altura 'l', iremos alocar um novo vetor de altura 'l'+1*/
    for(int c=coluna,j=0;(j<4) && (c<getNumColunas());c++,j++){
        for(int l=linha,i=0;(i<4) && l>=0;l--,i++){
            if(fig[i][j]!=' '){
                if(l > getAltura(c)-1)
                    realocColuna(c, l);
                break;
            }
        }
    }
    /*Neste duplo laço, iremos copiar os píxels válidos da matriz 'fig' para a matriz 'jogo'*/
    for(int l=linha,i=0;(i<4) && l>=0;l--,i++){
        for(int c=coluna,j=0;(j<4) && (c<getNumColunas());c++,j++){
            if((fig[i][j]!=' ') && (jogo[c][l]==' ')) jogo[c][l] = fig[i][j];
        }
    }

    return true;
}
bool Tetris::adicionaForma(const int coluna, const int linha, const char id, const int rotacao){
    switch(id){ // POSSIVEIS ROTAÇÕES 0 / 90 / 180 / 270  !!!!
        case 'I':
            if(rotacao == 0 || rotacao == 180){
                char figI[4][4] = {'I', ' ', ' ', ' ',
                                   'I', ' ', ' ', ' ',
                                   'I', ' ', ' ', ' ',
                                   'I', ' ', ' ', ' ' };
                if(linha < 3) return false; //Não é possível posicionar uma peça 'I' em menos de 4 espaços.
                if(jogo[coluna] == NULL){ /*caso onde a coluna está vazia(nula). Iremos alocar a coluna,
                setar seus valores para o caractere espaço(' ') e então copiar para a coluna a forma par_
                tindo da matriz 'figI'*/
                    realocColuna(coluna, linha);
                    for(int l=linha, i=3;i>=0;l--,i--)
                        jogo[coluna][l] = figI[i][0];
                    return true;
                }
                return adicionar(coluna, linha, figI);

            }
            else if (rotacao == 90 || rotacao == 270){
                char figI90[4][4] = {'I', 'I', 'I', 'I',
                                     ' ', ' ', ' ', ' ',
                                     ' ', ' ', ' ', ' ',
                                     ' ', ' ', ' ', ' ' };
                if((getNumColunas()-coluna) < 4) return false; /*Não é possível posicionar a peça 'I' nesta
                rotação, pois são necessárias, no mínimo, QUATRO colunas disponíveis*/
                return adicionar(coluna, linha, figI90);
            }
        case 'J':
            if(rotacao == 0){
                char figJ[4][4] = {'J', 'J', 'J', 'J',
                                   ' ', ' ', ' ', 'J',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 4) return false; /*Não é possível alocar este tipo
                de figura abaixo da linha 1 e são necessárias QUATRO colunas para o posicionar*/
                return adicionar(coluna, linha, figJ);
            }
            else if(rotacao == 90){
                char figJ90[4][4] = {' ', 'J', ' ', ' ',
                                     ' ', 'J', ' ', ' ',
                                     ' ', 'J', ' ', ' ',
                                     'J', 'J', ' ', ' ' };
                if(linha < 3 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figJ90);
            }
            else if(rotacao == 180){
                char figJ180[4][4] = {'J', ' ', ' ', ' ',
                                      'J', 'J', 'J', 'J',
                                      ' ', ' ', ' ', ' ',
                                      ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 4) return false;
                return adicionar(coluna, linha, figJ180);
            }
            else if(rotacao == 270){
                char figJ270[4][4] = {'J', 'J', ' ', ' ',
                                      'J', ' ', ' ', ' ',
                                      'J', ' ', ' ', ' ',
                                      'J', ' ', ' ', ' ' };
                if(linha < 3 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figJ270);
            }
        case 'L':
            if(rotacao == 0){
                char figL[4][4] = {'L', 'L', 'L', 'L',
                                   'L', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 4) return false;
                return adicionar(coluna, linha, figL);
            }
            else if(rotacao == 90){
                char figL90[4][4] = {'L', 'L', ' ', ' ',
                                     ' ', 'L', ' ', ' ',
                                     ' ', 'L', ' ', ' ',
                                     ' ', 'L', ' ', ' ' };
                if(linha < 3 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figL90);
            }
            else if(rotacao == 180){
                char figL180[4][4] = {' ', ' ', ' ', 'L',
                                      'L', 'L', 'L', 'L',
                                      ' ', ' ', ' ', ' ',
                                      ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 4) return false;
                return adicionar(coluna, linha, figL180);
            }
            else if(rotacao == 270){
                char figL270[4][4] = {'L', ' ', ' ', ' ',
                                      'L', ' ', ' ', ' ',
                                      'L', ' ', ' ', ' ',
                                      'L', 'L', ' ', ' ' };
                if(linha < 3 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figL270);
            }
        case 'O': //independentemente da rotação, terá essa forma.
            if(rotacao == 0 || rotacao == 90 || rotacao == 180 || rotacao == 270){
                char figO[4][4] = {'O', 'O', ' ', ' ',
                                   'O', 'O', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figO);
            }
        case 'S':
            if(rotacao == 0 || rotacao == 180){
                char figS[4][4] = {' ', 'S', 'S', ' ',
                                   'S', 'S', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 3) return false;
                return adicionar(coluna, linha, figS);
            }
            else if(rotacao == 90 || rotacao == 270){
                char figS90[4][4] = {'S', ' ', ' ', ' ',
                                     'S', 'S', ' ', ' ',
                                     ' ', 'S', ' ', ' ',
                                     ' ', ' ', ' ', ' ' };
                if(linha < 2 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figS90);
            }
        case 'T':
            if(rotacao == 0){
                char figT[4][4] = {'T', 'T', 'T', ' ',
                                   ' ', 'T', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 3) return false;
                return adicionar(coluna, linha, figT);
            }
            else if(rotacao == 90){
                char figT90[4][4] = {' ', 'T', ' ', ' ',
                                     'T', 'T', ' ', ' ',
                                     ' ', 'T', ' ', ' ',
                                     ' ', ' ', ' ', ' ' };
                if(linha < 2 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figT90);
            }
            else if(rotacao == 180){
                char figT180[4][4] = {' ', 'T', ' ', ' ',
                                      'T', 'T', 'T', ' ',
                                      ' ', ' ', ' ', ' ',
                                      ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 3) return false;
                return adicionar(coluna, linha, figT180);
            }
            else if(rotacao == 270){
                char figT270[4][4] = {'T', ' ', ' ', ' ',
                                      'T', 'T', ' ', ' ',
                                      'T', ' ', ' ', ' ',
                                      ' ', ' ', ' ', ' ' };
                if(linha < 2 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figT270);
            }
        case 'Z':
            if(rotacao == 0 || rotacao == 180){
                char figZ[4][4] = {'Z', 'Z', ' ', ' ',
                                   ' ', 'Z', 'Z', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ' };
                if(linha < 1 || (getNumColunas()-coluna) < 3) return false;
                return adicionar(coluna, linha, figZ);
            }
            else if(rotacao == 90 || rotacao == 270){
                char figZ90[4][4] = {' ', 'Z', ' ', ' ',
                                     'Z', 'Z', ' ', ' ',
                                     'Z', ' ', ' ', ' ',
                                     ' ', ' ', ' ', ' ' };
                if(linha < 2 || (getNumColunas()-coluna) < 2) return false;
                return adicionar(coluna, linha, figZ90);
            }
    }
    return false;
}
void Tetris::print(){ //Função utilizada para testes
    std::cout << "alturas:\n";
    for(int i=0;i<getNumColunas();i++) std::cout << alturas[i];
    std::cout << '\n'<<'\n';
    for(int l=(getAltura()-1);l>=0;l--){
        for(int c=0;c<getNumColunas();c++){
            if(l>=getAltura(c)) std::cout << "0";
            else if(jogo[c][l]==' ') std::cout << "0";
            else std::cout << jogo[c][l];
        }
        std::cout << '\n';
    }
}
