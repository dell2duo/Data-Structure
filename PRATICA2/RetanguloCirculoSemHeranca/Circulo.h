
#ifndef __Circulo_h
#define __Circulo_h

#include "FigBase.h"

class Circulo: public FigBase {
    public:
        Circulo();
        Circulo(const Circulo &);
        Circulo(double, double, double, int, int, int);

        double getRaio() const;
        void setRaio(double);

        float area() const;
        float perimetro() const;

        void imprime() const;

        friend istream& operator>> (istream &, Circulo &);
        friend ostream& operator<< (ostream &, const Circulo &);

    private:
        double raio;
};

#endif
