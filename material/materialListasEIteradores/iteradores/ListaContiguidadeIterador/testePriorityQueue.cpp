#include <iostream>
#include "MyPriorityQueue.h"

using namespace std;

int main(){
    MyPriorityQueue<int> fila;

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int el;cin>>el;
        fila.push(el);
    }

    fila.print();
    cout << fila.top() << '\n';
    fila.pop();
    fila.print();
    cout << fila.top() << '\n';

    return 0;
}