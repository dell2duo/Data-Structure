#include "Horario.h"

Horario::Horario(){
    hora = 0;
    minuto = 0;
    segundo = 0;
}
Horario::Horario(int h, int m, int s){
    if (h < 0 || h > 23){
        if(h < 0)
            h = 0;
        else
            h = 23;
    }
    if (m < 0 || m > 59){
        if(m < 0)
            m = 0;
        else
            m = 59;
    }
    if (s < 0 || s > 59){
        if(s < 0)
            s = 0;
        else
            s = 59;
    }

    hora = h;
    minuto = m;
    segundo = s;
}
Horario::Horario(const Horario &hr){
    hora = hr.hora;
    minuto = hr.minuto;
    segundo = hr.segundo;
}
void Horario::setHora(int h){
    if (h < 0 || h > 23){
        if(h < 0)
            h = 0;
        else
            h = 23;
    }

    hora = h;
}
void Horario::setMinuto(int m){
    if (m < 0 || m > 59){
        if(m < 0)
            m = 0;
        else
            m = 59;
    }

    minuto = m;
}
void Horario::setSegundo(int s){
    if (s < 0 || s > 59){
        if(s < 0)
            s = 0;
        else
            s = 59;
    }

    segundo = s;
}
int Horario::getHora() const{
    return hora;
}
int Horario::getMinuto() const{
    return minuto;
}
int Horario::getSegundo() const{
    return segundo;
}
int Horario::compHorario(const Horario &hms){
    if(hms.hora < hora)
        return -1;
    else if(hms.hora > hora)
        return 1;
    else{
        if(hms.minuto < minuto)
            return -1;
        else if(hms.minuto > minuto)
            return 1;
        else{
            if(hms.segundo < segundo)
                return -1;
            if(hms.segundo > segundo)
                return 1;
            else{
                return 0;
            }
        }
    }
}
int Horario::difSegundos(const Horario &hms){
    int diferenca = segundo - hms.segundo;
    return diferenca;
}
void Horario::imprime(){
    cout << hora << " " << minuto << " " << segundo << endl;
}

istream& operator>>(istream &in, Horario &hr){
    in >> hr.hora;
    in >> hr.minuto;
    in >> hr.segundo;

    if (hr.hora < 0 || hr.hora > 23){
        if(hr.hora < 0)
            hr.hora = 0;
        else
            hr.hora = 23;
    }
    if (hr.minuto < 0 || hr.minuto > 59){
        if(hr.minuto < 0)
            hr.minuto = 0;
        else
            hr.minuto = 59;
    }
    if (hr.segundo < 0 || hr.segundo > 59){
        if(hr.segundo < 0)
            hr.segundo = 0;
        else
            hr.segundo = 59;
    }

    return in;
}
ostream& operator<<(ostream &out, const Horario &hr){
    out << hr.hora << " " << hr.minuto << " " << hr.segundo;
    
    return out;
}