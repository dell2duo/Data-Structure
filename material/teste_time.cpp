#include <iostream>
#include <algorithm>
#include "6_vetor.h"
using namespace std;

int binSearch(Vetor<int> v, int elemBusca, int lo, int hi) {
	int meio = lo + (hi-lo)/2;
	if(lo>hi) return -1; //elemento nao esta no vetor...
	if(v[meio] == elemBusca) return meio;
	if(v[meio] < elemBusca) return binSearch(v,elemBusca,meio+1,hi);
	else return binSearch(v,elemBusca,lo,meio-1);
}

int seqSearch(Vetor<int> v, int elemBusca, int lo, int hi) {
	for(int i=lo;i<=hi;i++) if(v[i]==elemBusca) return i;
	return -1;
}


void testaBuscaBinaria(Vetor<int> v, int numBuscas) {
	int elemMaximoBuscar = v.size()*4;
	int encontrados = 0;

	v.sort(); //para a busca binaria precisamos primeiro ordenar os elementos...
	for(int i=0;i<numBuscas;i++) {
		int elem = rand()%elemMaximoBuscar;
		int ans = binSearch(v,elem,0,v.size()-1);
		if(ans!=-1) encontrados++;
	}
	cout << "Numero de elementos encontrados com busca binaria: " << encontrados << endl;
} 

void testaBuscaSequencial(Vetor<int> v, int numBuscas) {
	int elemMaximoBuscar = v.size()*4;
	int encontrados = 0;

	for(int i=0;i<numBuscas;i++) {
		int ans = seqSearch(v,rand()%elemMaximoBuscar,0,v.size()-1);
		if(ans!=-1) encontrados++;
	}
	cout << "Numero de elementos encontrados com busca sequencial: " << encontrados << endl;
}   

int main(int argc, char **argv) {
	int tamVetor = atoi(argv[1]);
	int numBuscas = tamVetor;

	cerr << "Criando vetor de tamanho " << tamVetor << " e fazendo " << numBuscas << " buscas" << endl;
	Vetor<int> v(tamVetor);

	for(int i=0;i<tamVetor;i++) v[i] = rand()%(4*tamVetor);

	if(argv[2][0]=='b') testaBuscaBinaria(v,numBuscas);
	else testaBuscaSequencial(v,numBuscas);

}