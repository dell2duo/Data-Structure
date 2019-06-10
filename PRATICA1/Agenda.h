#ifndef AGENDA
#define AGENDA

#include <iostream>
#include <string>
#include "Data.h"
#include "Horario.h"

using namespace std;

class ItemAgenda{
    private:
        string descricao;
        Data d;
        Horario h;
    public:
        ItemAgenda();
        ItemAgenda(const string &, const Data &, const Horario &);
        ItemAgenda(const ItemAgenda &);
        void setDesc(const string &);
        void setData(const Data &);
        void setHorario(const Horario &);
        const string & getDesc() const;
        const Data & getData() const;
        const Horario & getHorario() const;
};

class Agenda{
    private:
        int count;//contador
        ItemAgenda ita[1000];
    public:
        Agenda();
        void inserirItem(const ItemAgenda &);
        void compromissosData(const Data &) const;
};

#endif