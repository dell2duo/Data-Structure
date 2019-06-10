#include "Segmento.h"
#include <cmath>

Segmento::Segmento() : FigBase(1, 1, 1, 1, 1){
    setX2(1);
    setY2(1);
}
Segmento::Segmento(double x1, double y1, double x2, double y2, int esp, int c, int t)
: FigBase(x1, y1, esp, c, t){
    setX2(x2);
    setY2(y2);
}
double Segmento::getX2() const{
    return x2;
}
void Segmento::setX2(double x2){
    this->x2 = x2;
}
double Segmento::getY2()const{
    return y2;
}
void Segmento::setY2(double y2){
    this->y2 = y2;
}
float Segmento::area() const{
    return 0;
}
float Segmento::perimetro() const{
    return sqrt(pow((getX2()-getX()), 2) + pow((getY2() - getY()), 2));
}
void Segmento::imprime() const{
    cout << "--- [Segmento] ---" << endl;
    cout << " Atributos da linha: " << endl;
    FigBase::imprime();
    cout << " x2 = " << getX2() << " y2 = " << getY2() << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl;
}

istream& operator>> (istream &in, Segmento &seg){
    cout << "Digite os valores na seguinte ordem:" << endl;
    cout << "X1 Y1 X2 Y2 Espessura Cor Tipo Largura Altura" << endl;
    double aux; int aux2;
    in >> aux; seg.setX(aux);
    in >> aux; seg.setY(aux);
    in >> seg.x2 >> seg.y2;
    in >> aux2; seg.setEspessura(aux2);
    in >> aux2; seg.setCor(aux2);
    in >> aux2; seg.setTipo(aux2);

    return in;
}
ostream& operator<< (ostream &out, const Segmento &seg){
    cout << "--- [Segmento] ---" << endl;
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << seg.getEspessura() << endl;
    cout << "     Cor       = " << seg.getCor() << endl;
    cout << "     Tipo      = " << seg.getTipo() << endl;          
    cout << " x = " << seg.getX() << " y = " << seg.getY() << endl;
    cout << " x2 = " << seg.getX2() << " y2 = " << seg.getY2() << endl;
    cout << " area = " << seg.area() << " perimetro = " << seg.perimetro() << endl;

    return out;
}