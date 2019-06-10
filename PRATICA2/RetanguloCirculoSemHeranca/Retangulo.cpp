#include "Retangulo.h"
#include <iostream>
using std::cout;
using std::endl;

Retangulo::Retangulo() : FigBase(1, 1, 1, 1, 1){
    setAltura(1);
    setLargura(1);
}
Retangulo::Retangulo(double x, double y, 
                     double larg, double alt,
                     int esp, int c, int t) : FigBase(x, y,esp, c, t){
    setLargura(larg);
    setAltura(alt);
}

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}
double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

float Retangulo::area() const {
    return altura * largura;     
}      
          
float Retangulo::perimetro() const {
    return 2*(largura + altura);      
}

void Retangulo::imprime() const {
    cout << "--- [Retangulo] ---" << endl;
    cout << " Atributos da linha: " << endl;
    FigBase::imprime();
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

istream& operator>> (istream &in, Retangulo &ret){
    cout << "Digite os valores na seguinte ordem:" << endl;
    cout << "X Y Espessura Cor Tipo Largura Altura" << endl;
    double aux; int aux2;
    in >> aux; ret.setX(aux);
    in >> aux; ret.setY(aux);
    in >> aux2; ret.setEspessura(aux2);
    in >> aux2; ret.setCor(aux2);
    in >> aux2; ret.setTipo(aux2);
    in >> ret.largura >> ret.altura;

    return in;
}
ostream& operator<< (ostream &out, const Retangulo &ret){
    out << "--- [Retangulo] ---" << endl;
    out << " Atributos da linha: " << endl;
    out << "     Espessura = " << ret.getEspessura() << endl;
    out << "     Cor       = " << ret.getCor() << endl;
    out << "     Tipo      = " << ret.getTipo() << endl;          
    out << " x = " << ret.getX() << " y = " << ret.getY() << endl;
    out << " largura = " << ret.getLargura() << " altura = " << ret.getAltura() << endl;  
    out << " area = " << ret.area() << " perimetro = " << ret.perimetro() << endl;

    return out;
}
