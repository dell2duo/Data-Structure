#include <iostream>
#include <typeinfo>

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"

using namespace std;

int main(){
    Circulo c1, c2;
    Segmento s1, s2;
    Retangulo r1;

    FigBase *p[5];

    p[0] = &c1;
    p[1] = &c2;
    p[2] = &s1;
    p[3] = &s2;
    p[4] = &r1;

    for(int i=0;i<5;i++){
        cin >> *p[i];
        cout << *p[i];
    }

    cout << "\n IMPRIMINDO VALORES COM RAIO RECALCULADO \n" << endl;

    for(int i=0;i<5;i++){
        Circulo *ptr = dynamic_cast<Circulo*>(p[i]);
        if(ptr != 0){
            ptr->setRaio(ptr->getRaio()*2);
        }
        cout << *p[i];
    }
}