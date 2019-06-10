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

    FigBase *ptr[5];
    ptr[0] = dynamic_cast<FigBase*>(&c1);
    ptr[1] = dynamic_cast<FigBase*>(&c2);
    ptr[2] = dynamic_cast<FigBase*>(&r1);
    ptr[3] = dynamic_cast<FigBase*>(&s1);
    ptr[4] = dynamic_cast<FigBase*>(&s2);

    if(typeid(*ptr[0]).name() == typeid(r1).name()){
        cout << "é igual" << endl;
    }

    for(int i=0;i<5;i++){
        cin >> *ptr[i];
        cout << *ptr[i];
    }

    for(int i=0;i<5;i++){
        if(typeid(*ptr[i]).name() == typeid(c1).name()){
            
        }
    }
}