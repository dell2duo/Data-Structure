#include "Huffman.h"
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree(const int freqs[]){
    for(int i=0;i<256;i++){ //copiando as frequencias para o vector da classe
        freq.push_back(freqs[i]);
    }
}

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{
    //pseudo-código
    //'in' é vector com todos os caracteres do arquivo a ser compactado
    //'out' terá os caracteres em forma binária representada por booleanos
    MyVec<char>::iterator it = in.begin();
    while(it != in.end()){
        //cotinuar
    }
}
void HuffmanTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{

}