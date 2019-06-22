#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "MyPriorityQueue.h"
#include "Node.h"
#include "MyQueue.h"

class HuffmanTree{
public:
    HuffmanTree():root(NULL){}
    HuffmanTree(const int freqs[]);
    HuffmanTree(const HuffmanTree &);
    ~HuffmanTree();

    void comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const;
    void descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const;
private:
    int n_char;
    bool search(Node<int> *, unsigned char &) const;
    void destroy(Node<int>*);
    void print() const;
    Node<int> *merge(MyPriorityQueue<Node<int>*> &);
    Node<int> *root; //primeiro argumento template = frequencia, segundo argumento template = caractere
};

#endif