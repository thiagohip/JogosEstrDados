#include <iostream>

class Forca
{
    public:
        const static int WLEN = 20;
        std::string words[WLEN] = {"abacateiro", "estrela", "gravata",
        "forca", "dromedario", "julieta", "janela", "geladeira",
        "hemorragia", "paralelepipedo", "corrida", "safira", "amendoa",
        "amarela", "abelha", "clava", "trovoada", "ondulado", "calmaria",
        "servente"};

        std::string wsort(int wlen, std::string words[]);
        std::string bars(std::string);
        std::string lcheck(char, std::string, std::string, bool*);
        bool wincheck(std::string, std::string);
        void result(std::string, bool);
        void hud(std::string wlock, int erros);
};
