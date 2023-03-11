#include "Forca.h"


    std::string Forca::wsort(int wlen, std::string words[]){
        int n = rand()%wlen+1;
        return words[n];
    }

    std::string Forca::bars(std::string w){
        std::string wlock; wlock = "";
        for (int i = 0; i<w.length(); i++){
            wlock += "_";
        }
        return wlock;

    }

    std::string Forca::lcheck(char l, std::string w, std::string wlock, bool *ach){
        *ach = false;
        for (int i=0; i<w.length(); i++){
            if (w[i] == l){
                wlock[i] = l;
                *ach = true;
            }
        }
        return wlock;
    }

    bool Forca::wincheck(std::string w, std::string wlock){
        bool acertou;
        acertou = true;
        for(int i = 0; i<wlock.length(); i++){
        if(wlock[i] == '_'){
            return false;
        }
    }
    return acertou;
    }

    void Forca::result(std::string wlock, bool acerto){
        std::cout << wlock;
        if(acerto){
            std::cout << std::endl;
            std::cout << "Parabéns, você acertou a palavra!" << std::endl;
        }else{
            std::cout << std::endl;
            std::cout << "Infelizmente, você não conseguiu acertar a palavra!" << std::endl;
        }
    }

    void Forca::hud(std::string wlock, int erros){
        std::cout << wlock << std::endl;
        std::cout << "Erros: " << erros << std::endl;
        std::cout << "Informe uma letra: ";

    }
