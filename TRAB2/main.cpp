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
            1 - ler o arquivo fonte (argv[2]) passando-o para um MyVec<char>
        enquanto salva as frequencias.
            2 - construir um objeto HuffmanTree com as frequencias obtidas.
            3 - chamar a função de comprimir passando um vector de booleanos
        e o vector de char.
            4 - salvar os arquivos a partir do vector de booleanos em um arquivo '.dat'
        */
        
        ifstream input; /* objeto para coleta dos char's do arquivo */
        input.open(argv[2], ios_base::in);
        if(!input.is_open()) cout << "-- error! file could not be opened --\n";

        MyVec<char> in;

        while(!input.eof()) in.push_back((char)input.get()); /*copia os caracteres do arquivo fonte*/

        MyVec<char>::iterator it;
        it = in.begin();
        int temp;
        int freq[256] = {0};
        while(it != in.end()){
            temp = (int)*it;
            if(temp < 0) break;
            freq[temp]++;
            cout << temp << endl;
            it++;
        }

        for(int i=0;i<256;i++){
            //cerr << "entrou 2\n";
            if(freq[i] == 0) continue;
            cout << "chave: " << (char)i << "\nfrequencia: " << freq[i] << "\n";
        }
        //cout << "\n";
        //cerr << "saiu 2\n";
    }

    return 0;
}