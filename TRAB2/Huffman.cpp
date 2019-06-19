#include "Huffman.h"
#include <iostream>

using namespace std;

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const{
    //'in' é vector com todos os caracteres do arquivo a serem compactados
    //'out' terá os caracteres em forma binária representada por booleanos
    print();
    MyVec<unsigned char>::iterator it;
    it = in.begin();
    while(it != in.end()){
        //if(*it == -1) break; // não sei o motivo, porém estava aparecendo um 'EOF' no arquivo
        if(root->left->character == *it) out.push_back(false);
        else{
            out.push_back(true);
            Node<int> *temp = root;
            temp = temp->right;
            while(temp->left != NULL && temp->right != NULL){
                if(search(temp->right, *it)){
                    out.push_back(true);
                    temp = temp->right;
                }
                else{
                    out.push_back(false);
                    temp = temp->left;
                }
            }
        }
        it++;
    }
    //cout << out << endl;
    // cout << in << endl;
}
void HuffmanTree::descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const{
    MyVec<bool>::iterator it; it = in.begin();

    while(it != in.end()){
        Node<int> *temp = root;
        while(temp->left && temp->right){
            if(it == in.end()) break;
            if(*it == false) temp = temp->left;
            else temp = temp->right;
            it++;
        }
        out.push_back(temp->character);
    }

    //cout << out << endl;
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
        queue.pushbottom(temp);
        // queue.print();
    }

    root = queue.bottom();
    print();
}

Node<int> *HuffmanTree::merge(MyPriorityQueue<Node<int>*> &queue){
    // queue.print();
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
    if(temp1->character == '0'){
        temp3->right = temp1;
        temp3->left = temp2;
    }
    else{
        temp3->right = temp2;
        temp3->left = temp1;
    }

    // cout << "temp3\n" << *temp3 << endl;
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

void HuffmanTree::print() const{
    MyQueue<Node<int> *> q;
	if(!root) return;
	q.push(root);

    int size = 0;
	while(!q.empty()) {
        size++;
		Node<int> * p = q.front();
		q.pop();
        if(p->character == '\n') cout << "/n ";
        //else if(p->character == -1) cout << "EOF ";
		else cout << p->character << " ";
		if(p->left) q.push(p->left);  
		if(p->right) q.push(p->right);
	}
    cout << size << '\n';
}