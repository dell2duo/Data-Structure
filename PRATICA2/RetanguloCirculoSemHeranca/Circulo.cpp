
#include "Circulo.h"
#include <iostream>
using std::cout;
using std::endl;

const float PI = 3.141592653589;

Circulo::Circulo() : FigBase(1, 1, 1, 1, 1){
    setRaio(1);
}
Circulo::Circulo(double x, double y, double r, int esp, int c, int t) : FigBase(x, y, esp, c, t){
    setRaio(r);
}

Circulo::Circulo(const Circulo &circ) : FigBase(circ.getX(), circ.getY(), circ.getEspessura(), 
        circ.getCor(), circ.getTipo()){
    setRaio(circ.getRaio());
}

double Circulo::getRaio() const {
    return raio;
}

void Circulo::setRaio(double r) {
    raio = r;
}

float Circulo::area() const {
    return PI * raio * raio;    
}      
          
float Circulo::perimetro() const {
    return 2 * PI * raio;      
}


void Circulo::imprime() const {
    cout << "--- [Circulo] ---" << endl;
    cout << " Atributos da linha: " << endl;
    FigBase::imprime();
    cout << " raio = " << getRaio() << endl; 
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

istream& operator>> (istream &in, Circulo &circ){
    cout << "Digite os valores na seguinte ordem:" << endl;
    cout << "X Y Espessura Cor Tipo Raio" << endl;
    double aux; int aux2;
    in >> aux; circ.setX(aux);
    in >> aux; circ.setY(aux);
    in >> aux2; circ.setEspessura(aux2);
    in >> aux2; circ.setCor(aux2);
    in >> aux2; circ.setTipo(aux2);
    in >> circ.raio;

    return in;
}
ostream& operator<< (ostream &out, const Circulo &circ){
    out << "--- [Circulo] ---" << endl;
    out << " Atributos da linha: " << endl;
    out << "     Espessura = " << circ.getEspessura() << endl;
    out << "     Cor       = " << circ.getCor() << endl;
    out << "     Tipo      = " << circ.getTipo() << endl;          
    out << " x = " << circ.getX() << " y = " << circ.getY() << endl;
    out << " raio = " << circ.getRaio() << endl; 
    out << " area = " << circ.area() << " perimetro = " << circ.perimetro() << endl;

    return out;
}
