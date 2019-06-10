#ifndef __Retangulo_h
#define __Retangulo_h

#include "FigBase.h"
//https://docs.google.com/document/d/1UxjyfGkF7QOlUrY2CHjCsQkNfOQBsknI-vCmFc9BEo8/edit
class Retangulo: public FigBase {

public:
    Retangulo();
    Retangulo(double, double, double, double, int, int, int);

    double getLargura() const;
    void setLargura(double);

    double getAltura() const;
    void setAltura(double);

    float area() const;
    float perimetro() const;

    void imprime() const;

    friend istream& operator>> (istream &, Retangulo &);
    friend ostream& operator<< (ostream &, const Retangulo &);

private:
    double largura, altura;

};

#endif
