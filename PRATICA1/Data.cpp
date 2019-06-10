#include "Data.h"

Data::Data(){
    dia = 1;
    mes = 1;
    ano = 2018;
}
Data::Data(int d, int m, int a){
    if (d < 1 || d > 30){
        if(d < 1)
            d = 1;
        else
            d = 30;
    }
    if (m < 1 || m > 12){
        if(m < 1)
            m = 1;
        else
            m = 12;
    }
    if (a < 2018 || a > 2020){
        if(a < 2018)
            a = 2018;
        else
            a = 2020;
    }

    dia = d;
    mes = m;
    ano = a;
}
Data::Data(const Data &dt){
    dia = dt.dia;
    mes = dt.mes;
    ano = dt.ano;
}
void Data::setDia(int d){
    if (d < 1 || d > 30){
        if(d < 1)
            d = 1;
        else
            d = 30;
    }

    dia = d;
}
void Data::setMes(int m){
    if (m < 1 || m > 12){
        if(m < 1)
            m = 1;
        else
            m = 12;
    }

    mes = m;
}
void Data::setAno(int a){
    if (a < 2018 || a > 2020){
        if(a < 2018)
            a = 2018;
        else
            a = 2020;
    }

    ano = a;
}
int Data::getDia() const{
    return dia;
}
int Data::getMes() const{
    return mes;
}
int Data::getAno() const{
    return ano;
}
int Data::compData(const Data &dma) const{
    if(dma.ano < ano)
        return -1;
    else if(dma.ano > ano)
        return 1;
    else{
        if(dma.mes < mes)
            return -1;
        else if(dma.mes > mes)
            return 1;
        else{
            if(dma.dia < dia)
                return -1;
            if(dma.dia > dia)
                return 1;
            else{
                return 0;
            }
        }
    }
}
int Data::difDias(const Data &dma){
    int diferenca = dia - dma.dia;
    return diferenca;
}
void Data::imprime(){
    cout << dia << " " << mes << " " << ano << endl;
}

istream& operator>>(istream &in, Data &dt){
    in >> dt.dia;
    in >> dt.mes;
    in >> dt.ano;

    if (dt.dia < 1 || dt.dia > 30){
        if(dt.dia < 1)
            dt.dia = 1;
        else
            dt.dia = 30;
    }
    if (dt.mes < 1 || dt.mes > 12){
        if(dt.mes < 1)
            dt.mes = 1;
        else
            dt.mes = 12;
    }
    if (dt.ano < 2018 || dt.ano > 2020){
        if(dt.ano < 2018)
            dt.ano = 2018;
        else
            dt.ano = 2020;
    }

    return in;
}
ostream& operator<<(ostream &out, const Data &dt){
    out << dt.dia << " " << dt.mes << " " << dt.ano;
    return out;
}