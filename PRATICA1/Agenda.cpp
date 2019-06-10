#include "Agenda.h"

ItemAgenda::ItemAgenda(){}
ItemAgenda::ItemAgenda(const string &desc, const Data &dt, const Horario &hr){
    descricao = desc;

    d.setDia(dt.getDia());
    d.setMes(dt.getMes());
    d.setAno(dt.getAno());

    h.setHora(hr.getHora());
    h.setMinuto(hr.getMinuto());
    h.setSegundo(hr.getSegundo());
}
ItemAgenda::ItemAgenda(const ItemAgenda &it){
    this->descricao = it.descricao;

    this->d.setDia(it.d.getDia());
    this->d.setMes(it.d.getMes());
    this->d.setAno(it.d.getAno());

    this->h.setHora(it.h.getHora());
    this->h.setMinuto(it.h.getMinuto());
    this->h.setSegundo(it.h.getSegundo());
}
void ItemAgenda::setDesc(const string &desc){
    descricao = desc;
}
void ItemAgenda::setData(const Data &dt){
    d.setDia(dt.getDia());
    d.setMes(dt.getMes());
    d.setAno(dt.getAno());
}
void ItemAgenda::setHorario(const Horario &hr){
    h.setHora(hr.getHora());
    h.setMinuto(hr.getMinuto());
    h.setSegundo(hr.getSegundo());
}
const string & ItemAgenda::getDesc() const{
    return descricao;
}
const Data & ItemAgenda::getData() const{
    return d;
}
const Horario & ItemAgenda::getHorario() const{
    return h;
}

Agenda::Agenda(){count = 0;}

void Agenda::inserirItem(const ItemAgenda &it){
    ita[count] = it;
    count++;
}
void Agenda::compromissosData(const Data &d) const{
    for(int i=0; i<count; i++){
        if(d.compData(ita[i].getData())==0){
            cout << ita[i].getHorario() << " " << ita[i].getDesc() << endl;
        }
    }
}