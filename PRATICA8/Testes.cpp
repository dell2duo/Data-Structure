#include <iostream>
#include "MyList2NewIterator.h"
using namespace std;


//implemente aqui a funcao nao-membro reverse (etapa 4):
template <class T>
void reverse(MyList2<T> &lista) {

}


void testaPushFront() {
  MyList2<char> v;
  cout << v << endl;
  v.push_front('a');
  cout << v << endl;  
  for(int i=1;i<10;i++) {
    v.push_front('a'+i);
    cout << v << endl;
  }
}

void testaConstrutoresEtc() {
  MyList2<char> v;
  cout << v << endl;
  v.push_back('a');
  cout << v << endl;  
  for(int i=1;i<10;i++) {
    v.push_back('a'+i);
    cout << v << endl;
  }



  { //testando criacao e destrucao de vetor vazio..
    MyList2<char> v2;
  }

  {
    //copias de vetor vazio
    MyList2<char> v2;
    MyList2<char> v3 = v2; //construtor de copia
    v3 = v2;

    v2 = v;
    v2 = v;
    v3 = v;

    MyList2<char> v4 = v2;
  }

  cout << "fazendo insert" << endl;
  v.insert('0',v.begin());
  cout << v << endl;

  MyList2<char>::iterator it = v.begin();
  it++;
  it++;
  it++;
  v.insert('w',it);

  cout << v << endl;

  while(it!=v.end()) it++; //obviamente poderiamos fazer apenas it = v.end();, mas quero iterar para testar melhor o iterador...
  v.insert('z',it);

  cout << v << endl; 
}



void testaReverseMembro() {
  //descomente o codigo abaixo apos implementar a funcao-membro reverse
  int n;
  cin >> n;
  MyList2<string> v; //Realiza testes com strings...
  string st;
  for(int i=0;i<n;i++) {
    cin >> st;
    v.push_back(st);
  }
  cout << "Antes de reverse: " << endl;
  cout << v << endl;
  v.reverse();

  cout << "Apos reverse: " << endl;
  cout << v << endl;
}


template<class T>
typename MyList2<T>::iterator find(const T&elem, const MyList2<T> &list) { //funcao auxiliar para os testes
  typename MyList2<T>::iterator it = list.begin();
  while(it!=list.end() && list.derref(it)!=elem) {
    it = list.next(it);
  }
  return it;
}

void testaInsert() {
  int n,numInserts;
  cin >> n >> numInserts;
  MyList2<string> v; //Realiza testes com strings...
  string st;
  for(int i=0;i<n;i++) {
    cin >> st;
    v.push_back(st);
  }

  cout << "V antes das insercoes: " << endl;
  cout << v << endl;

  //agora vamos fazer os inserts..
  //cada insert e' composto de uma posicao (inteira) e de uma string
  for(int i=0;i<numInserts;i++) {
    int posInsert;
    cin >> posInsert >> st;
    MyList2<string>::iterator it = v.begin();
    for(int i=0;i<posInsert;i++, it++); //faca it apontar para a posicao "posInsert"
    v.insert(st,it);
    cout << "V apos a insercao de " << st << " na posicao " << posInsert << endl;
    cout << v << endl;
  }
}

void testaReverse() {
  cout << "Testando a funcao reverse..." << endl;
  MyList2<int> l1;

  for(int i=0;i<6;i++) {
    MyList2<int> l2 = l1;
    reverse(l2);
    cout << "Lista: " << endl << l1 << " Reverse: " << endl << l2 << endl << "--------------" << endl;
    l1.push_back(i);
  }
}


void printReverse(MyList2<int> &l1) { 
  //nao passamos por referencia constante porque nao nos preocupamos com iteradores constantes
  //na implementacao da classe MyList2 (sem esses iteradores nao podemos iterar em listas constantes,
  //visto que um iterador pode modificar a lista com a operacao de derreferencia)
  MyList2<int>::iterator it = l1.end();
  if(it!=l1.begin()) { //lista nao vazia...
    do {
      it--;
      cout << *it << " ";
    } while(it!=l1.begin());
  }
  cout << endl;
}

void testaDecrementoEnd() {
  cout << "Testando o decremento do iterador end()" << endl;
  MyList2<int> l1;

  for(int i=0;i<6;i++) {
    printReverse(l1);
    l1.push_back(i);
  }

  //e se criarmos um iterador para end() e inserirmos algo antes do end(), o decremento
  //vai acessar o novo valor corretamente?
  MyList2<int>::iterator it = l1.end();
  l1.insert(6,l1.end());
  it--;
  cout << "Isso deve imprimir o numero 6...: " << *it << endl;
  it--;
  cout << "Isso deve imprimir o numero 5...: " << *it << endl;

}



/*
O arquivo de entrada contem um tipo de teste 

As listas utilizadas nos testes contem apenas strings. Cada string e' formada apenas por letras e numeros.

A primeira linha do arquivo contem um caractere. 

Se o caractere for 'S', entao o arquivo representa testes com a funcao size. 
Se for 'D' significa testes com o decremento do iterador apontando para end(). 
Se for 'R' significa testes com a funcao-membro reverse. 
Se for 'N' significa testes com a funcao nao-membro reverse.
Se for 'I', representa testes com a funcao insert. 
Se nao for nenhum dos anteriores, entao representa testes gerais com push_front, construtores, etc

-----------------
Arquivos de testes gerais, com a funcao size ou com o decremento do end():
Sem dados de entrada
-----------------
Arquivos de teste com as funcoes (membro e nao-membro) reverse:  
A segunda linha contem um numero N representando o numero de elementos a serem inseridos na lista
Na terceira linha ha N strings a serem inseridas na lista (sempre comecamos com uma lista vazia)
-----------------
Arquivos de teste da funcao insert: 
A segunda linha contem dois numeros N e M.
N representa o numero de elementos a serem inseridos na lista inicial
M representa o numero de insercoes posteriores na lista.

A terceira linha contem N strings a serem inseridas na lista inicial
As proximas M linhas contem pares com um inteiro P e uma string S
: P representa a posicao da lista onde S sera inserida (note que a cada nova insercao a lista cresce)
-----------------
*/



int main() {
  MyList2<string> v; //Realiza testes com strings...
  char tipoTeste;
  cin >> tipoTeste; 

  if(tipoTeste=='N') { //testes com funcao reverse
    cout << "Testes com reverse (nao-membro)" << endl;
    testaReverse();
  } else if(tipoTeste=='R') { //testes com funcao reverse
    cout << "Testes com reverse" << endl;
    testaReverseMembro();
  } else if(tipoTeste=='D') { //testes com funcao reverse
    cout << "Testes com decremento do iterador end" << endl;
    testaDecrementoEnd();
  } else if(tipoTeste=='I') {
    cout << "Testes com insert" << endl;
    testaInsert();
  }  else {
    cout << "Testes gerais" << endl;
    testaPushFront();
    cout << "passou do push front" << endl;
    testaConstrutoresEtc();
  }
}


