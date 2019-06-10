#include <iostream>
#include <cstring>
#include "MyVecNewIterator.h"
#include "MySet.h"

using namespace std;

int main(int argc, char *argv[]){
    string aux = argv[1];
    if(aux == "myvec"){
        MyVec<string> words;
        string word;
        int nwords = 0;

        while(cin >> word){
            nwords++;
            bool insere = true;
            for(int i=0;i<words.size();i++)
                if(words[i]==word) insere = false;

            if(insere) words.push_back(word);
        }

        cout << nwords << " " << words.size() << '\n';

        return 0;
    }
    if(aux == "myset"){
        MySet<string> words;
        string word;
        int nwords = 0;

        while(cin >> word){
            nwords++;
            words.insert(word);
        }

        cout << nwords << " " << words.size() << '\n';

        return 0;
    }

    return 0;
}