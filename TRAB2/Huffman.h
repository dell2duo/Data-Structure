#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "MyPriorityQueue.h"
#include "Node.h"

class HuffmanTree{
public:
    HuffmanTree():root(NULL), treeSize(0){}
    HuffmanTree(const int freqs[]);
    HuffmanTree(const HuffmanTree &);

    void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;
    void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;
private:
    Node<int, char> *root; //primeiro argumento template = frequencia, segundo argumento template = caractere
    //MyVec<int> freq;
    MyPriorityQueue<char> roots;
    int treeSize;
};

#endif