#include "Huffman.h"
#include <iostream>

using namespace std;

void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const{
    //'in' é vector com todos os caracteres do arquivo a serem compactados
    //'out' terá os caracteres em forma binária representada por booleanos
    MyVec<unsigned char>::iterator it; it = in.begin(); //iterador de 'in'
    /* para comprimir o arquivo, devemos gerar os valores para o vector de booleanos 'out'
    que corresponda à nova configuração binária dos caracteres do arquivo comprimido.
    Para tal, iremos percorrer o vector de unsigned char's e utilizar uma função auxiliar
    'search' que, dado uma raiz e um valor, nos retorna um valor booleano caso o elemento
    esteja no local indicado, no caso, esquerda da raiz ou direita. Então fazemos um 'push'
    no vector de booleanos conforme o nosso retorno da função 'search'. Caso o arquivo só 
    tenha um caractere, independente do número de repetições, podemos assumir seu valor
    como '1' ou '0', na minha implementação, isso não fará muita diferença.
    
    Podemos percorrer a árvore (com o ponteiro 'temp') enquanto salvamos em 'out' os res_
    pectivos valores booleanos. */
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
    //'in' é vector com todos os caracteres no formato binário-booleano
    //'out' terá os caracteres "descompactados"
    MyVec<bool>::iterator it; it = in.begin();// iterador de 'in'
    /* para descomprimir o arquivo, não haverá necessidade de fazer buscas na árvore
    como na compressão (função 'search'), basta verificar se o valor do vector de
    booleanos é verdadeiro ou falso. Caso verdadeiro, apontamos o ponteiro 'temp'
    para a direita da árvore, caso contrário, apontamos para a esquerda. Faremos
    isso até que o Nodo tenha seus ponteiros apontando para 'NULL', o que simboliza
    que encontramos o final do "caminho" e aquele caractere é o caractere do arquivo
    original. */
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
    /* iremos apontar 'temp' para um novo Node retornado pela função 'merge' criada
    por mim. Em seguida, faremos um push do ponteiro 'temp' com o endereço de memória
    desse novo Node para a fila de prioridades. No fim, teremos uma única arvore na fila,
    assim sendo podemos apontar o ponteiro da classe Huffman para a primeira posição da
    fila, que é a única árvore e é a nossa árvore de Huffman. */
    while(queue.size() > 1){
        Node<int> *temp = merge(queue);
        queue.push(temp);
    }

    root = queue.top();
}

Node<int> *HuffmanTree::merge(MyPriorityQueue<Node<int>*> &queue){
    /* nesta função, iremos pegar os dois primeiros Node's da fila e os subjulgar
    à um outro Node. Então retornamos um ponteiro para o espaço de memória alocado. */
    Node<int> *temp1 = queue.top();
    queue.pop();

    Node<int> *temp2 = queue.top();
    queue.pop();

    Node<int> *temp3 = new Node<int>(temp1->freq+temp2->freq, char());
    if(temp1->character == char()){ // os elementos com caracteres 'char()' serão Node's
    //de junção, não representarão um caractere real. Logo ficarão à direita na árvore.
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
    /* função recursiva que retorna true caso encontre um determinado 'elem' em algum
    dos lados da árvore. Essencial para determinar qual será a representação binária
    dos caracteres do arquivo. */
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

void HuffmanTree::print() const{ // função utilizada para auxiliar a implementação.
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