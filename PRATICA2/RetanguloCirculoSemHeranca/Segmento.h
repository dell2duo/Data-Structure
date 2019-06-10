#ifndef SEGMENTO
#define SEGMENTO

#include "FigBase.h"

class Segmento : public FigBase {
    public:
        Segmento();
        Segmento(double, double, double, double, int, int, int);

        double getX2() const;
        void setX2(double);

        double getY2() const;
        void setY2(double);

        float area() const;
        float perimetro() const;
        void imprime() const;

        friend istream& operator>> (istream &, Segmento &);
        friend ostream& operator<< (ostream &, const Segmento &);
        
    private:
        double x2;
        double y2;
};

#endif