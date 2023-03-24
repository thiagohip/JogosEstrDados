#include "Senha.h"

void Senha::spass(){
    for(int i=0; i<4; i++){
        gpass[i] = col[rand()%4];
    }
}

int Senha::check(){
    int total=0;
    for(int i=0; i<4; i++){
        if(ppass[i] == gpass[i]){
            total++;
        }
    }
    return total;
}
