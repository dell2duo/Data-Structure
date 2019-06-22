#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    ofstream out(argv[1]);
    if(!out.is_open()) cout << "-não abriu-" << endl;

    for(int i=0;i<255;i++){
        char temp = (char)i;
        out << temp;
    }

    return 0;
}