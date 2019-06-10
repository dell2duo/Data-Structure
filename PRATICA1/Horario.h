#ifndef HORARIO
#define HORARIO

#include <iostream>

using namespace std;

class Horario{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        Horario();
        Horario(int , int, int);
        Horario(const Horario &);
        void setHora(int);
        void setMinuto(int);
        void setSegundo(int);
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;
        int compHorario(const Horario &);
        int difSegundos(const Horario &);
        void imprime();

        friend istream& operator>>(istream &, Horario &);
        friend ostream& operator<<(ostream &, const Horario &);
};

#endif