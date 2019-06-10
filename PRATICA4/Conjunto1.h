#ifndef CONJUNTO
#define CONJUNTO

#include <iostream>

using namespace std;

template<class T>
class Conjunto;

template <class T>
ostream &operator<<(ostream &, const Conjunto<T> &);

template <class T>
istream &operator>>(istream &, Conjunto<T> &);

template<class T>
class Conjunto{
    friend ostream &operator<< <T>(ostream &, const Conjunto<T> &);
    friend istream &operator>> <T>(istream &, Conjunto<T> &);
    public:
        Conjunto(int=10);
        Conjunto(const Conjunto<T> &);
        ~Conjunto();

        bool pertence(T) const;
        bool insere(T);
        const int numelementos() const;
        bool operator==(const Conjunto<T>) const;
        const Conjunto<T> & operator=(const Conjunto<T> &);
    private:
        T *elementos = NULL;
        int num_elementos;
        int tam_array;
        void deleta(Conjunto<T> &);
};

template<class T>
void Conjunto<T>::deleta(Conjunto<T> &conj){ //função auxiliar que desaloca e zera um
    if(conj.elementos == NULL) return;       //conjunto
    delete[] conj.elementos;                 
    conj.num_elementos = 0;
    conj.tam_array = 0;
}

template<class T>
Conjunto<T>::Conjunto(int tam){
    elementos = new T[tam];
    num_elementos = 0;
    tam_array = tam;
}

template<class T>
Conjunto<T>::Conjunto(const Conjunto<T> &conj){
    *this = conj; //fazer sobrecarga da igualdade
}

template<class T>
Conjunto<T>::~Conjunto(){
    deleta(*this); //função privada que deleta o objeto
}

template<class T>
bool Conjunto<T>::pertence(T valor) const{
    for(int i=0;i<num_elementos;i++){
        if(elementos[i]==valor){
            return true;
        }
    }
    return false;
}

template<class T>
bool Conjunto<T>::insere(T valor){
    if(tam_array == num_elementos) return false;
    else if (pertence(valor)) return false;
    else{
        elementos[num_elementos] = valor;
        num_elementos++;
        return true;
    }
}

template<class T>
const int Conjunto<T>::numelementos() const{
    return num_elementos;
}

template<class T>
bool Conjunto<T>::operator==(const Conjunto<T> conj) const{
    if(num_elementos != conj.num_elementos) return false;
    else{
        for(int i=0;i<num_elementos;i++){
            if(!conj.pertence(elementos[i]))
                return false;
        }
        return true;
    } 
}

template<class T>
const Conjunto<T> & Conjunto<T>::operator=(const Conjunto<T> &conj){
    if(this == &conj) return *this;

    deleta(*this);
    tam_array = conj.tam_array;
    num_elementos = conj.num_elementos;
    elementos = new T[conj.tam_array];

    for(int i=0;i<conj.num_elementos;i++){
        elementos[i] = conj.elementos[i];
    }

    return *this;
}

template <class T>
ostream &operator<<(ostream &out,const Conjunto<T> &conj){ 
    out << "{";
    if (conj.numelementos()<=0){
        out << "}";
        return out;
    }
    for(int i=0;i<conj.numelementos();i++){
        if((i+1)==conj.numelementos()){
            out << conj.elementos[i] << "}";
            break;
        }
        out << conj.elementos[i] << ",";
    }
    return out;
}

template <class T>
istream &operator>>(istream &in, Conjunto<T> &conj){
    T aux;
    for(int i=0;i<conj.tam_array || in>>aux;i++){
        in >> aux;
        if(!conj.pertence(aux)){
            conj.insere(aux);
        }
    }
}

#endif