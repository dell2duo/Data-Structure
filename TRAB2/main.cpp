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
        MyVec<unsigned char>::iterator it; /* iterador para o vector 'in' */
        it = in.begin();
        int temp;
        int freq[256] = {0};
        while(it != in.end()){
            temp = (int)*it;
            if(temp < 0) break;
            freq[temp]++;
            // cout << temp << endl;
            it++;
        }

        HuffmanTree arvore(freq); //objeto da classe 'HuffmanTree'

        MyVec<bool> out; //vector que irá receber os bits que representam o arquivo compactado

        arvore.comprimir(out, in); /*função que nos retorna um vector de bools que serão salvos
        no arquivo de saída*/

        ofstream output;
        output.open(argv[3], ios::binary);
        if(!output.is_open()){ /* debugger para caso o arquivo não exista ou não seja aberto */
            cout << "-- error! Input file could not be opened --\n";
            return 0;
        }

        for(int i=0;i<256;i++){ /* vamos salvar as frequências no início do arquivo compactado */
            output << freq[i];
        }

        //MyVec<unsigned char> temp1;
        MyVec<bool>::iterator it2; /* iterador para o vector de bools 'out' */
        it2 = out.begin();
        while(it2 != out.end()){
            unsigned char aux = char();
            for(int i=0;i<8;i++){
                if(it2 == out.end()) break;
                if(*it2) aux = (aux | (1<<i));
                //else aux = (aux & (0<<i));
                it2++;
            }
            //temp1.push_back(aux);
            output << aux;
        }

        // cout << out << endl;
        // cout << "temp1:\n";
        // for(int i=0;i<temp1.size();i++){
        //     for(int j=0;j<8;j++)
        //         if((temp1[i] & (1<<j)) != 0)
        //             cout << "1";
        //         else cout << "0";
        // }
        // cout << endl;
        // MyVec<unsigned char> out2;
        // arvore.descomprimir(out2, out);
    }

    else if(option == "d"){}

    return 0;
}