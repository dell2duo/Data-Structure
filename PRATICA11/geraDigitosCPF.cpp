#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n;
    cin >> n;
    char cpf[9];
    for(int i=0;i<n;i++){
        cin >> cpf;
        if(strlen(cpf) < 9) cout << "tamanho inválido" << endl;
        else{
            int sum = 0;
            int first;
            int second;
            for(int j=0, aux=10;j<9;j++, aux--){
                int temp = cpf[j] - '0';
                // cout << temp << endl;
                sum += temp*aux;
            }
            //cout << sum << endl;
            first = ((10*sum) % 11);
            if(first == 10) first = 0;
            sum = 0;
            cout << first;
            for(int j=0, aux=11;j<9;j++, aux--){
                int temp = cpf[j] - '0';
                // cout << temp << endl;
                sum += temp*aux;
            }
            sum += first*2;
            //cout << sum << endl;
            second = ((10*sum) % 11);
            cout << second << endl;
        }
    }
}