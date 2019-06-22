#include <iostream>
#include <fstream>
#include <cstring>
#include "Huffman.h"

using namespace std;

int main(int argc, char *argv[]){
    //se o primeiro argumento for 'c', comprima-o
    //se for 'd', descomprima-o
    string option = argv[1];
    if(option == "c"){
        /*
            1 - ler o arquivo fonte (argv[2]) passando-o para um MyVec<unsigned char>
        enquanto salva as frequencias.
            2 - construir um objeto HuffmanTree com as frequencias obtidas.
            3 - chamar a função de comprimir passando um vector de booleanos
        e o vector de char.
            4 - salvar os arquivos a partir do vector de booleanos em um arquivo '.dat'
        */
        
        ifstream input; /* objeto para coleta dos char's do arquivo */
        input.open(argv[2], ios::in);
        if(!input.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
            cout << "-- error! Input file could not be opened --\n";
            return 0;
        }

        MyVec<unsigned char> in; /* vector de 'unsigned char' que recebe os caracteres do arquivo */

        while(!input.eof()) in.push_back((unsigned char)input.get()); /*copia os caracteres do arquivo fonte*/
        input.close(); /*não há mais necessidade de acessar o arquivo fonte*/
        /*neste trecho de código iremos ler a frequência de cada caractere do arquivo fonte
        armazenados no vector 'in'*/
        in.pop_back(); /* removemos o caractere de 'fim de arquivo' */

        if(in.size() == 0){ //cria arquivo vazio
            ofstream output;
            output.open(argv[3], ios::binary);
            if(!output.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
                cout << "-- error! Output file could not be opened --\n";
                return 0;
            }

            int freq[256] = {0};
            output.write(reinterpret_cast<char*>(freq), sizeof(freq));

            int n_bits = 0;
            output.write(reinterpret_cast<char*>(&n_bits), sizeof(n_bits));

            output.close();
            return 0;
        }

        MyVec<unsigned char>::iterator it; /* iterador para o vector 'in' */
        it = in.begin();
        int temp;
        int freq[256] = {0};
        while(it != in.end()){
            temp = (int)*it;
            if(temp < 0) break;
            freq[temp]++;
            it++;
        }

        HuffmanTree arvore(freq); //objeto da classe 'HuffmanTree'

        MyVec<bool> out; //vector que irá receber os bits que representam o arquivo compactado

        arvore.comprimir(out, in); /*função que nos retorna um vector de bools que serão salvos
        no arquivo de saída*/

        ofstream output;
        output.open(argv[3], ios::binary);
        if(!output.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
            cout << "-- error! Output file could not be opened --\n";
            return 0;
        }

        output.write(reinterpret_cast<char*>(freq), sizeof(freq));

        int n_bits = out.size();
        output.write(reinterpret_cast<char*>(&n_bits), sizeof(n_bits));

        MyVec<bool>::iterator it2; /* iterador para o vector de bools 'out' */
        it2 = out.begin();

        while(it2 != out.end()){
            unsigned char aux = char();
            for(int i=7;i>=0;i--){
                if(it2 == out.end()) break;
                if(*it2 == true) aux = (aux | (1<<i));
                else aux = (aux & ~(1<<i));
                it2++;
            }
            output.write(reinterpret_cast<char*> (&aux), sizeof(aux));
        }
        output.close();
    }

    else if(option == "d"){
        /*
            1 - ler o arquivo fonte (argv[2]) pegando os primeiros 256 inteiros
        que serão as frequências dos caracteres do arquivo original.
            2 - construir um objeto HuffmanTree com as frequencias obtidas.
            3 - chamar a função de descomprimir passando um vector de booleanos
        com os bits do arquivo comprimido e o vector de char que receberá os
        caracteres originais do arquivo.
            4 - salvar os arquivos a partir do vector de char em um arquivo fornecido
        (argv[3]).
        */
        ifstream input;
        input.open(argv[2], ios::binary);/*abrir o arquivo como binário (formato em que foi salvo)*/
        if(!input.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
            cout << "-- error! Input file could not be opened --\n";
            return 0;
        }

        int freq[256];
        input.read(reinterpret_cast<char*> (freq), sizeof(freq)); /*ler os primeiros 1024 bytes que é a frequência*/
        int n_bits; //número total de bits válidos para a leitura.
        input.read(reinterpret_cast<char*>(&n_bits), sizeof(n_bits));

        if(n_bits == 0){ //caso do arquivo original vazio
            ofstream output;
            output.open(argv[3], ios::out);
            if(!output.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
                cout << "-- error! Output file could not be opened --\n";
                return 0;
            }

            output.close();
            return 0;
        }

        HuffmanTree arvore(freq);

        MyVec<bool> in;
        MyVec<unsigned char> out;

        int limit = 0;
        while(!input.eof()){
            unsigned char aux;
            input.read(reinterpret_cast<char*>(&aux), sizeof(aux));
            for(int i=7;i>=0;i--){
                if(limit == n_bits) break;
                limit++;
                if((aux & (1<<i)) != 0) in.push_back(true);
                else in.push_back(false);
            }
            if(limit == n_bits) break;
        }

        input.close();

        arvore.descomprimir(out, in);

        ofstream output;
        output.open(argv[3], ios::out);
        if(!output.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
            cout << "-- error! Output file could not be opened --\n";
            return 0;
        }

        MyVec<unsigned char>::iterator it;
        it = out.begin();

        while(it != out.end()){
            output << *it;
            it++;
        }
        output.close();
    }

    return 0;
}