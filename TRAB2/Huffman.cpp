#include "Huffman.h"
#include <iostream>

using namespace std;

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const{
    //'in' é vector com todos os caracteres do arquivo a serem compactados
    //'out' terá os caracteres em forma binária representada por booleanos
    MyVec<unsigned char>::iterator it; //iterador de 'in'
    it = in.begin();
    while(it != in.end()){
        if(n_char == 1) out.push_back(true);
        else {
            Node<int> *temp = root;
            while(temp->left != NULL && temp->right != NULL){
                if(search(temp->left, *it)){
                    out.push_back(false);
                    temp = temp->left;
                }
                else{
                    out.push_back(true);
                    temp = temp->right;
                }
            }
        }
        it++;
    }
}
void HuffmanTree::descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const{
    MyVec<bool>::iterator it; it = in.begin();

    while(it != in.end()){
        Node<int> *temp = root;
        if(n_char == 1) {it++;}
        else{
            while(temp->left && temp->right){
                if(it == in.end()) break;
                if(*it == false) temp = temp->left;
                else temp = temp->right;
                it++;
            }
        }
        out.push_back(temp->character);
    }
}

HuffmanTree::HuffmanTree(const int freqs[]){
    n_char = 0;
    MyPriorityQueue<Node<int>*> queue;
    /* iremos agora criar os nodos com seus respectivos caracteres e frequencias
    e então fazer um 'push' para a fila de prioridade 'queue' */
    for(int i=0;i<256;i++){
        if(freqs[i] != 0) {
            n_char++;
            Node<int> *temp = new Node<int>(freqs[i], (char)i);
            queue.push(temp);
        }
    }

    while(queue.size() > 1){
        Node<int> *temp = merge(queue);
        queue.push(temp);
    }

    root = queue.top();
}

Node<int> *HuffmanTree::merge(MyPriorityQueue<Node<int>*> &queue){
    // queue.print();
    Node<int> *temp1 = queue.top();
    queue.pop();

    Node<int> *temp2 = queue.top();
    queue.pop();

    /* a fila por prioridade nos diz que o ultimo elemento será o
    menor elemento da fila, então podemos adicionar à esquerda o
    nodo de maior frequencia e à direita o nodo de menor frequencia
    ao novo nodo que será a raiz de 'temp1' e 'temp2' */
    
    Node<int> *temp3 = new Node<int>(temp1->freq+temp2->freq, '0');
    if(temp1->character == '0'){
        temp3->right = temp1;
        temp3->left = temp2;
    }
    else{
        temp3->right = temp2;
        temp3->left = temp1;
    }
    return temp3;
}

bool HuffmanTree::search(Node<int> *object, unsigned char &elem) const{
    if(!object) return false;
    if(object->character == elem) return true;
    return search(object->left, elem) || search(object->right, elem);
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

void HuffmanTree::print() const{ //um nivel por vez..
	MyQueue<Node<int> *> q;
	MyQueue<Node<int> *> u;
	if(!root) return;
	u.push(root);

	int nivel = 0;
	while(!u.empty()) {
		q = u;
		u = MyQueue<Node<int> *>();

		cout <<  "Nivel " << nivel++ << " : ";
		while(!q.empty()) {
			Node<int> * p = q.front();
			q.pop();
            if(p->character == '\n') cout << "/n ";
			else cout << p->character << " ";
			if(p->left) u.push(p->left);  
			if(p->right) u.push(p->right);
		}
		cout << endl;
	}
	
}