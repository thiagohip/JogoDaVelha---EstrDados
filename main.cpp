#include <iostream>
#include <unistd.h>

using namespace std;


void showTab(char tab[3][3]){
    for(int i = 0; i < 3; i++){
        cout << endl << "|";
        for(int j = 0; j < 3; j++){
            cout << tab[i][j] << "|";
        }
        cout << endl;
    }
}

char checkWin(char tab[3][3]){
    char let;
    int cont, i, j;
    cont = 0;

    if (cont != 3){
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(j == 0){
                    let = tab[i][j];
                }else if (tab[i][j] == let && tab [i][j] != ' '){
                    cont++;
                }
            }
            if(cont == 2){
                break;
            }else{
                cont = 0;
            }
        }
    }

    if (cont != 3){
        for(j = 0; j < 3; j++){
            for(i = 0; i < 3; i++){
                if(i == 0){
                    let = tab[i][j];
                }else if (tab[i][j] == let && tab[i][j] != ' '){
                    cont++;
                }
            }
            if(cont == 2){
                break;
            }else{
                cont = 0;
            }
        }
    }

    if (cont != 3){
        for(i = 0; i < 3; i++){
            if(i == 0){
                let = tab[i][i];
            }else if(tab[i][i] == let && tab[i][i] != ' '){
                cont++;
            }
        }
    }

    if(cont == 2){
        return let;
    }else{
        return 'a';
    }
}

int main()
{
    char tab[3][3], win;
    int jogadas, i, j, x, y;
    jogadas = i = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tab[i][j] = ' ';
        }
    }
    showTab(tab);
    do{


       if(i % 2 == 0){
            cout << "Jogador 1[X] faça sua jogada: " << endl;
            cout << "X: ";
            cin >> x;
            cout << endl;
            cout << "Y: ";
            cin >> y;
            if (tab[x-1][y-1] != 'X' && tab[x-1][y-1] != 'O'){
                tab[x-1][y-1] = 'X';
            }
            i++;
       }else{
            cout << "Jogador 2[O] faça sua jogada: " << endl;
            cout << "X: ";
            cin >> x;
            cout << endl;
            cout << "X: ";
            cin >> y;
            if (tab[x-1][y-1] != 'X' && tab[x-1][y-1] != 'O'){
                tab[x-1][y-1] = 'O';
            }
            i = 0;
       }

        system("cls");
        showTab(tab);


        win = checkWin(tab);
        if(win == 'X'){
            cout << "Jogador 1 venceu";
            break;
        }else if(win == 'O'){
            cout << "Jogador 2 venceu";
            break;
        }



    }while (i < 2);
    return 0;
}
