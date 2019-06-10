#ifndef VETOR_H
#define VETOR_H

#include <ostream>
#include <algorithm>
#include <cstdlib>

//precisamos declarar que a classe Vetor existe para que possamos utiliza-la na declaracao
//do operador << abaixo...
template <class T>
class Vetor;

//precisamos declarar a existencia do operador << do tipo T antes de poder
//declarar que ele e' friend da classe(abaixo)
//Ha outras alternativas para declarar o operador << friend, mas elas possuem alguns problemas
//Ha muita variacao sobre as exigencias dos compiladores a respeito de templates/friend
template <class T>
std::ostream &operator<<(std::ostream &,const Vetor<T> &v);



template <class T>
class Vetor {

	friend std::ostream &operator<< <T>(std::ostream &,const Vetor<T> &v); // o operador nao e' friend de Vetor... e' friend do Vetor de T! 
public:
	Vetor(int n);
	~Vetor();
	const Vetor &operator=(const Vetor&other);
	Vetor(const Vetor&other);

	T &operator[](int i) { return v[i]; } //implementada no cabecalho...
	const T& operator[](int) const; //versao constante do operador acima...
									        //T pode ser grande --> retornar por referencia!

	int size() const { return tam; }

	//nao existe mais a classe "Vetor"... existe "Vetor de T"
	Vetor<T> operator+(const Vetor<T> &other) const; //soma o vetor "this" com other, retornando o resultado
																						 //o vetor "this" nao eh modificado
	bool operator==(const Vetor<T> &other) const; //verifica se o vetor e' igual ao outro
	bool operator!=(const Vetor<T> &other) const;

	void sort() { std::sort(v,v+tam); }

private:
	int tam;
	T *v;
};


template <class T>
Vetor<T>::~Vetor() {
	delete []v;
}

template <class T>
const Vetor<T> & Vetor<T>::operator=(const Vetor<T>&other) {
	if(&other==this) return *this; //testa auto-atribuicao...
	delete []v;
	tam = other.tam;
	v = new T[tam];
	for(int i=0;i<tam;i++) v[i]= other.v[i];
	return *this;
}

template <class T>
Vetor<T>::Vetor(const Vetor<T>&other) {
	v = NULL;
	*this = other;
}

//Definicao em C++ nao podem estar em arquivos .cpp (ao incluir o header
//em um .cpp o compilador precisa instanciar a classe imediatamente -- nao 
// eh possivel compilar de forma separada)
//Exemplo: se houvesse um .cpp contendo a implementacao de Vetor com templates, ao
//compilar esse .cpp de forma separada como o compilador saberia quais os tipos a serem usados
//no lugar de T?

//precisamos desse cabecalho em todas funcoes declaradas fora da classe
template <class T>
Vetor<T>::Vetor(int n): tam(n) {
	v = new T[n];
	for(int i=0;i<tam;i++)
		v[i] = T(); //construtor padrao to tipo T . Inteiros, float, char, etc. valem 0 por padrao.
}

template <class T>
std::ostream &operator<<(std::ostream &os,const Vetor<T> &vet) {
	for(int i=0;i<vet.tam;i++) os << vet.v[i] << " "; //poderiamos ter simplesmente utilizado vet[i], mas decidimos
																						  //acessar o array privado para praticar o uso de friend
	return os;
}

template <class T>
const T& Vetor<T>::operator[](int i) const { //versao constante do operador acima...
	return v[i];
}

template <class T>
Vetor<T> Vetor<T>::operator+(const Vetor<T> &other) const{ //soma o vetor "this" com other, retornando o resultado
	if(tam!=other.tam) {
		std::cerr << "Erro... somando arrays de tamanho diferente" << std::endl;
		exit(1);
	}
	Vetor v = *this;
	for(int i=0;i<tam;i++)
		v[i] += other[i];
	return v;
}

template <class T>												        //o vetor "this" nao eh modificado
bool Vetor<T>::operator!=(const Vetor<T> &other) const{ //verifica se o vetor e' igual ao outro
	return !(*this == other); 
}

template <class T>
bool Vetor<T>::operator==(const Vetor<T> &other) const{
	if(tam!=other.tam) {
		return false; // tamanho diferente --> vetores diferentes!
	}
	for(int i=0;i<tam;i++)
		if(v[i]!=other.v[i]) 
			return false;
	return true;
}

#endif