#include "Forca.h"
#include "Velha.h"
#include "Senha.h"
//#include <windows.h>
#include <unistd.h>

using namespace std;

Forca F;
Velha V;
Senha S;

int menu(){
    system("cls");
    int op;
    std::cout << "=-==-==-==-==-==-==-==-==-==-==-==-==-==-==-=" << std::endl;
    std::cout << "        Bem vindo aos jogos cefetiano " << std::endl;
    std::cout << "=-==-==-==-==-==-==-==-==-==-==-==-==-==-==-=" << std::endl;
    std::cout << "[1]Jogo da Forca" << std::endl;
    std::cout << "[2]Jogo da Velha" << std::endl;
    std::cout << "[3]Jogo da Senha" << std::endl;
    std::cout << "[0]Sair do programa" << std::endl;
    std::cout << "=-==-==-==-==-==-==-==-==-==-==-==-==-==-==-=" << std::endl;
    std::cout << "Opção: ";
    std::cin >> op;
    return op;
}

void forca(){
    string w, wlock;
    char l, esc;
    int erros, i, n;
    bool ach, acerto;
    //Menu inicial.
    //----------------------------------------//
        do{
            //Sortear uma palavra do dicionário.
            w = F.wsort(F.WLEN, F.words);
            //----------------------------------------//
            //Encher a palavra escondida de barras.
            wlock = F.bars(w);
            //----------------------------------------//
            erros = 0;
            acerto = false;
            do{
                system("cls");
                //HUD
                F.hud(wlock, erros);
                //----------------------------------------//
                cin >> l;
                //Verificação de acerto da letra.
                wlock = F.lcheck(l, w, wlock, &ach);
                if (!ach){
                    erros++;
                }
                //----------------------------------------//
                //Verificar se a palavra ja foi encontrada
                acerto = F.wincheck(w, wlock) ;
                //----------------------------------------//
            }while(erros < 6 && !acerto);
            //Resultado.
            F.result(wlock, acerto);
            //----------------------------------------//
            cout << "Quer continuar jogando? [S/N]";
            cin >> esc;
        }while(esc == 's' || esc == 'S');
        cout << "Jogo finalizado!";
}

void velha(){
    char tab[3][3], last, esc;
    int jogadas, i, j, x, y;
    bool tru = true, win = false;
    jogadas = i = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tab[i][j] = ' ';
        }
    }
    do{
        do{
            //Vez do jogador 1
            if(i % 2 == 0){
                last = 'X';
                do{
                    V.showTab(tab);
                    cout << "Jogador 1[X] faca sua jogada: " << endl;
                    cout << "X: ";
                    cin >> x;
                    cout << endl;
                    cout << "Y: ";
                    cin >> y;
                    if (tab[x-1][y-1] != 'X' && tab[x-1][y-1] != 'O'){
                        tab[x-1][y-1] = 'X';
                        break;
                    }else{
                        cout << "O local ja esta preechido!" << endl;
                        sleep(1);
                    }
                }while(tru);
                i++;
            }
            //Vez do jogador 2
            else{
                last = 'O';
                do{
                    V.showTab(tab);
                    cout << "Jogador 2[O] faca sua jogada: " << endl;
                    cout << "X: ";
                    cin >> x;
                    cout << endl;
                    cout << "Y: ";
                    cin >> y;
                    if (tab[x-1][y-1] != 'X' && tab[x-1][y-1] != 'O'){
                        tab[x-1][y-1] = 'O';
                        break;
                    }else{
                        cout << "O local ja esta preechido!" << endl;
                        sleep(1);
                    }
                }while(tru);
                i = 0;
            }
            jogadas++;
            V.showTab(tab);
            win = V.winCheck(tab);
            if(win){
                if(last == 'X'){
                    cout << "O jogador 1 venceu!";
                    break;
                }else if(last == 'O'){
                    cout << "O jogador 2 venceu!";
                    break;
                }
            }

        }while(tru);


        cout << "Jogar novamente? [S/N] ";
        cin >> esc;

        if(esc == 'N' || esc == 'n'){
            break;
        }

    }while(esc == 'S' || esc == 's');
}

void senha(){
    system("cls");
    S.spass();
    int acertos=0, jogadas=1;
    bool acertou=false;
    do{
        cout << "Informe o palpite," << endl << "[V]Vermelho - [A]Azul - [P]Preto - [B]Branco" << endl;
        cout << "Jogadas: " << jogadas;
        for(int i=0; i<4; i++){
            cin >> S.ppass[i];
        }
        acertos=S.check();
        if(acertos == 4){
            acertou = true;
        }else{
            jogadas++;
            cout << acertos << " acertos" << endl;
        }
    }while(jogadas<=10 && !acertou);
    if(acertou){
        cout << "Parabéns! Você acertou.";
    }else{
        cout << "Que pena! Você perdeu, a senha era: ";
        for(int i=0; i<4; i++){
            cout << S.gpass[i] << " ";
        }
    }
}

int main(){
    do{
        int op = menu();
        if(op == 1){
            forca();
        }else if(op == 2){
            velha();
        }else if(op == 3){
            senha();
        }else{
            break;
        }
    }while(true);
    return 0;
}
