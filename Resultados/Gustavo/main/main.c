#include "jogo.h"

int main(){
    Jogo *jogo = CriaJogo();
    ExecutaJogo(jogo);
    LiberaJogo(jogo);
    return 0;
}