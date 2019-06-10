#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
#include "MyStack.h"
#include "MyQueue.h"

void etapa1() {
	int n = 6;
	MyStack<int> pilha;
	MyQueue<int> fila;
	for(int i=0;i<n;i++){
		int value; cin >> value;
		pilha.push(value);
		fila.push(value);
	}

	while(!pilha.empty()){
		cout << pilha.top() << " ";
		pilha.pop();
	}
	cout << '\n';

	while(!fila.empty()){
		cout << fila.front() << " ";
		fila.pop();
	}
	cout << '\n';
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> pilha;
	char symbol;
	while(cin>>symbol){
		if(symbol=='(' || symbol=='[' || symbol=='{')
			pilha.push(symbol);
			
		if(pilha.empty() && (symbol==')' || symbol==']' || symbol=='}')){
			cout << "Inconsistente\n"; return;
		}

		if(symbol==')' && pilha.top()=='(')
			pilha.pop();
		else if(symbol==']' && pilha.top()=='[')
			pilha.pop();
		else if(symbol=='}' && pilha.top()=='{')
			pilha.pop();
		
		
	}
	if(pilha.empty())
		cout << "Consistente\n";
	else
		cout << "Inconsistente\n";
	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
//#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
#include "MyPriorityQueue.h"
void etapa3() {
	MyPriorityQueue<int> fila;
	int n; cin >> n;
	while(cin>>n){
		fila.push(n);
	}
		fila.push(n);
	fila.print();
	//descomente o codigo abaixo ao fazer a etapa 3
	/*Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;*/
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}