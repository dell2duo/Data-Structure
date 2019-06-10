#ifndef TETRIS
#define TETRIS

class Tetris{
    public:
        //Construtor/Destrutor/Sobrecarga =
        Tetris(const int=0); //"int=0" para objetos criados sem um número de colunas
        Tetris(const Tetris &); //construtor por cópia
        ~Tetris();
        Tetris &operator=(const Tetris &);
        
        /*Funções*/
        char get(const int, const int) const; //retorna um char que representa um "píxel".
        void removeColuna(const int);
        void removeLinhasCompletas();
        int getNumColunas() const;
        int getAltura(const int) const;
        int getAltura() const; //retorna o maior valor de altura no array 'alturas'.
        bool adicionaForma(const int, const int, const char, const int); 
        /*Função que adiciona uma determinada peça passando como argumento, respectivamente,
        coluna, linha, id (símbolo que identifica uma peça/forma) e a rotação da peça/forma*/

        void print();
    private:
        bool adicionar(const int, const int, char [][4]);
        void realocColuna(const int coluna, const int tam);/*Função que realoca uma coluna. Caso não esteja alocada,
        faz a alocação e seta seus valores para o caractere espaço(' '). Caso contrário, irá realocar e copiar os an_
        tigos dados do vetor original*/
        char **jogo;
        int *alturas;
        int n_colunas;
};

#endif