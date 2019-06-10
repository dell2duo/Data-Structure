#ifndef Mediana
#define Mediana

#include <iostream>
#include "MyPriorityQueue.h"

class Mediana{
    public:
        void insere(const int&);
        int getMediana();
    private:
        MyPriorityQueue<int> first;
        MyPriorityQueue<int> second;
};

#endif