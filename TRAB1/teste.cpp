#include <iostream>
#include "Tetris.h"

using namespace std;
void funcao(char fig[][4]){
    return;
}

int main(){
    //IJLOSTZ
    Tetris game(8);

    game.adicionaForma(4,0,'I',90);

    game.print();
    cout << '\n';

    game.adicionaForma(0,1,'I',90);

    game.print();
    cout << '\n';

    game.adicionaForma(0,0,'I',90);

    game.print();
    cout << '\n';

    game.adicionaForma(0,2,'I',90);

    game.print();
    cout << '\n';

    game.adicionaForma(4,2,'I',90);

    game.print();
    cout << '\n';

    game.adicionaForma(0,1,'I',90);

    game.print();
    cout << '\n';

    cout << "removendo linhas completas...\n";
    game.removeLinhasCompletas();
    
    game.print();

    /*game.adicionaForma(2,3,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(3,3,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(4,3,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(0,8,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(1,7,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(3,8,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(2,8,'I',0);

    game.print();
    cout << '\n';

    game.adicionaForma(4,8,'I',0);

    game.print();
    cout << '\n';

    cout << "removendo linhas completas...\n";
    game.removeLinhasCompletas();

    game.print();*/

    return 0;
}