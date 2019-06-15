#include "Huffman.h"
#include <iostream>

using namespace std;

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const{
    //pseudo-código
    //'in' é vector com todos os caracteres do arquivo a ser compactado
    //'out' terá os caracteres em forma binária representada por booleanos
    print();
    //char aux = 'A';
    //if(search(root, aux)) cout << aux << " está presente na árvore!\n"; 
}
void HuffmanTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const{

}

HuffmanTree::HuffmanTree(const int freqs[]){
    MyPriorityQueue<Node<int>*> queue;
    /* iremos agora criar os nodos com seus respectivos caracteres e frequencias
    e então fazer um 'push' para a fila de prioridade 'queue' */
    for(int i=0;i<256;i++){
        if(freqs[i] != 0) {
            Node<int> *temp = new Node<int>(freqs[i], (char)i);
            queue.push(temp);
        }
    }

    // cout << "fila antiga:\n";
    // queue.print();

    while(queue.size() > 1){
        Node<int> *temp = merge(queue);
        queue.push(temp);
        // queue.print();
    }

    root = queue.bottom();
}

Node<int> *HuffmanTree::merge(MyPriorityQueue<Node<int>*> &queue){
    Node<int> *temp1 = queue.bottom();
    queue.popbottom();
    // cout << "temp1\n" << *temp1 << endl;

    Node<int> *temp2 = queue.bottom();
    queue.popbottom();
    // cout << "temp2\n" << *temp2 << endl;

    /* a fila por prioridade nos diz que o ultimo elemento será o
    menor elemento da fila, então podemos adicionar à esquerda o
    nodo de maior frequencia e à direita o nodo de menor frequencia
    ao novo nodo que será a raiz de 'temp1' e 'temp2' */
    
    Node<int> *temp3 = new Node<int>(temp1->freq+temp2->freq, '0');
    if(queue.size() == 0){
        temp3->right = temp2;
        temp3->left = temp1;
    }
    else{
        temp3->right = temp1;
        temp3->left = temp2;
    }

    return temp3;
}

bool HuffmanTree::search(Node<int> *object, char &elem) const{
    if(!object->left || !object->right) return false;
    if(object->left->character == elem) return true;
    if(object->right->character == elem) return true;
    //search(object->left, elem); // não há necessidade, pois só há um elemento na esquerda
    search(object->right, elem);
}

void HuffmanTree::destroy(Node<int> *object){
    if(object == NULL) return;
	destroy(object->left);
	destroy(object->right);
	delete object;
}

HuffmanTree::~HuffmanTree(){
    destroy(root);
}

void HuffmanTree::print() const{
    MyQueue<Node<int> *> q;
	if(!root) return;
	q.push(root);

	while(!q.empty()) {
		Node<int> * p = q.front();
		q.pop();
        if(p->character == '\n') cout << "/n";
		else cout << p->character << " ";
		if(p->left) q.push(p->left);  
		if(p->right) q.push(p->right);
	}
    cout << '\n';
}