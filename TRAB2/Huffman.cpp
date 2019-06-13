#include "Huffman.h"
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree(const int freqs[]){
    treeSize = 0;
    MyPriorityQueue<Node<int>*> queue;

    for(int i=0;i<256;i++){
        if(freqs[i] != 0) {
            treeSize++;
            Node<int> *temp = new Node<int>(freqs[i], (char)i);
            queue.push(temp);
        }
    }
    //cerr << "tamanho da árvore: " << treeSize << endl;

    //queue.print();
    // cout << "ultimo elemento: " << *queue.bottom();
    // cout << "removendo...\n"; queue.popbottom();
    // cout << "ultimo elemento: " << *queue.bottom();

    merge(queue);
    //queue.print();

    cout << queue.bottom()->left->freq;
}

void HuffmanTree::merge(MyPriorityQueue<Node<int>*> &queue){
    Node<int> *temp1 = queue.bottom();
    queue.popbottom();
    cout << "temp1\n" << *temp1 << endl;

    Node<int> *temp2 = queue.bottom();
    queue.popbottom();
    cout << "temp2\n" << *temp2 << endl;

    /* a fila por prioridade nos diz que o ultimo elemento será o
    menor elemento da fila, então podemos adicionar à esquerda o
    nodo de maior frequencia e à direita o nodo de menor frequencia
    ao novo nodo que será a raiz de 'temp1' e 'temp2' */
    
    Node<int> *temp3 = new Node<int>(temp1->freq+temp2->freq, '0');
    temp3->right = temp1;
    temp3->left = temp2;

    queue.push(temp3);

    cout << "nova fila:\n";
    queue.print();
    cout << "frequencia do ultimo nodo: " << queue.bottom()->freq << '\n';
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