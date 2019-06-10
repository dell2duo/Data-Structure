#ifndef DATA
#define DATA

#include <iostream>

using namespace std;

class Data {
    private:
        int dia;
        int mes;
        int ano;
    public:
        Data();
        Data(int , int , int );
        Data(const Data &);
        void setDia(int);
        void setMes(int);
        void setAno(int);
        int getDia() const;
        int getMes() const;
        int getAno() const;
        int compData(const Data &) const;
        int difDias(const Data &);
        void imprime();

        friend istream& operator>>(istream &, Data &);
        friend ostream& operator<<(ostream &, const Data &);
};

#endif