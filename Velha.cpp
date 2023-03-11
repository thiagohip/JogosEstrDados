#include "Velha.h"




    bool Velha::winCheck(char tab[3][3]){

        if
       (
       tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2] && tab[0][0] != ' ' ||
       tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2] && tab[1][0] != ' ' ||
       tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2] && tab[2][0] != ' ' ||
       tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0] && tab[0][0] != ' ' ||
       tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1] && tab[0][1] != ' ' ||
       tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2] && tab[0][2] != ' ' ||
       tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] != ' ' ||
       tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] != ' '
       ){
        return true;
    }else{
        return false;
    }
    }

    void Velha::showTab(char tab[3][3]){
        system("cls");
        for(int i = 0; i < 3; i++){
            std::cout << std::endl << "|";
            for(int j = 0; j < 3; j++){
                std::cout << tab[i][j] << "|";
            }
            std::cout << std::endl;
        }
    }


