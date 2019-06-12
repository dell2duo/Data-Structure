#include "Huffman.h"
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree(const int freqs[]){
    treeSize = 0;
    MyPriorityQueue<Node<int, char>> fila;

    for(int i=0;i<256;i++){
        if(freqs[i] != 0) {
            treeSize++;
            Node<int, char> temp(freqs[i], (char)i);
            fila.push(temp);
            //vou ter que alterar as classes mypriority e myvec
        }
    }
    cerr << "tamanho da árvore: " << treeSize << endl;

    // for(int i=0;i<treeSize;i++){
    //     Node<int, char> temp(freqs[i],);
    // }
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