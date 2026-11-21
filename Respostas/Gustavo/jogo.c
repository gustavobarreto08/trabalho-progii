#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Jogo{
    Mapa *mapa;
    Jogador **jogadores;
    int qtdJogadores;
    Jogador *vencedor;
};

Jogo* CriaJogo(){
    Jogo *j = malloc(sizeof(struct Jogo));
    if(j == NULL){
        perror("ERRO ALOC JOGO\n");
        exit(1);
    }
    j->mapa = criaMapa();
    j->jogadores = NULL;
    j->qtdJogadores = 0;
    j->vencedor = NULL;
    return j;
}

int EstaNoInicioOuFimJogador(Jogo *j, Jogador *jogador){
    if(obtemPosicaoJogador(jogador) <= 0){
        return -1;
    }
    else if(obtemPosicaoJogador(jogador) >= obtemPosicaoFimMapa(j->mapa)){
        return 1;
    }
    else{
        return 0;
    }
}

void InsereJogadorVetorJogadores(Jogo *j, Jogador *jogador){
    j->qtdJogadores++;
    j->jogadores = realloc(j->jogadores, j->qtdJogadores * sizeof(*j->jogadores));
    if(j->jogadores == NULL){
        perror("ERRO ALOC VETOR JOGADORES\n");
        exit(1);
    }
    j->jogadores[j->qtdJogadores-1] = jogador;
}

int JaExisteJogador(Jogo *j, Jogador *jogador){
    for(int i = 0; i < j->qtdJogadores; i++){
        if(comparaNomeJogador(j->jogadores[i], jogador) == 1){
            return 1;
        }
    }
    return 0;
}

int ChegouFinalJogador(Jogo *j, int posicao){
    if(posicao >= obtemPosicaoFimMapa(j->mapa)){
        return 1;
    }
    return 0;
}

int RetornaQtdJogadasTotais(Jogo *j){
    int totaisJogadas = 0;
    for(int i = 0; i < j->qtdJogadores; i++){
        totaisJogadas += obtemJogadasJogador(j->jogadores[i]);
    }
    return totaisJogadas;
}

int RetornaQtdDisputasTotais(Jogo *j){
    int qtdDisputas = 0;
    for(int i = 0; i < j->qtdJogadores; i++){
        qtdDisputas += obtemDisputasVencidasJogador(j->jogadores[i]);
    }
    return qtdDisputas;
}

int RetornaMonstrosDerrotados(Jogo *j){
    int qtdMonstros = 0;
    for(int i = 0; i < j->qtdJogadores; i++){
        qtdMonstros += obtemMonstrosDerrotadosJogador(j->jogadores[i]);
    }
    return qtdMonstros;
}

void ImprimeEstadoPartida(Jogo *j){
    int ehprimeiro = 1;
    printf("=========== ESTADO ============\n");
    printf("[INICIO]");
    for(int i = 0; i < j->qtdJogadores; i++){
        if(EstaNoInicioOuFimJogador(j, j->jogadores[i]) < 0){
            if(ehprimeiro){
                printf(" <- %s", obtemNomeJogador(j->jogadores[i]));
                ehprimeiro = 0;
            }
            else{
                printf(", %s", obtemNomeJogador(j->jogadores[i]));
            }
        }
    }
    printf("\n");
    imprimeCelulasMapa(j->mapa);
    printf("[FIM]");
    ehprimeiro = 1;
    for(int i = 0; i < j->qtdJogadores; i++){
        if(EstaNoInicioOuFimJogador(j, j->jogadores[i]) > 0){
            if(ehprimeiro){
                printf(" <- %s", obtemNomeJogador(j->jogadores[i]));
                ehprimeiro = 0;
            }
            else{
                printf(", %s", obtemNomeJogador(j->jogadores[i]));
            }
        }
    }
    printf("\n");
    printf("-------------------------------\n");
    for(int i = 0; i < j->qtdJogadores; i++){
        printEstadoJogador(j->jogadores[i]);
    }
    printf("- Situacao: ");
    if(j->vencedor == NULL){
        printf("EM ANDAMENTO\n");
    }
    else{
        printf("VENCEDOR %s\n", obtemNomeJogador(j->vencedor));
    }
    printf("===============================\n");
}

void ImprimeRankingPatida(Jogo *j){
    Jogador **copia = malloc(j->qtdJogadores * sizeof(*(j->jogadores)));
    for(int i = 0; i < j->qtdJogadores; i++){
        copia[i] = j->jogadores[i];
    }
    qsort(copia, j->qtdJogadores, sizeof(*(copia)), comparaOrdJogador);
    printf("=========== RANKING ===========\n");
    for(int i = 0; i < j->qtdJogadores; i++){
        printRankingJogador(copia[i], i+1);
    }
    printf("===============================\n");
    free(copia);
}

void ImprimeRelatorioPartida(Jogo *j){
    printf("========= RELATORIO ===========\n");
    printf("- Celulas do mapa: %d\n", obtemQtdCelulasMapa(j->mapa));
    printf("- Jogadores: %d\n", j->qtdJogadores);
    printf("- Jogadas totais: %d\n", RetornaQtdJogadasTotais(j));
    printf("- Disputas: %d\n", RetornaQtdDisputasTotais(j));
    printf("- Monstros derrotados: %d\n", RetornaMonstrosDerrotados(j));
    printf("- Situacao: ");
    if(j->vencedor == NULL){
        printf("EM ANDAMENTO\n");
    }
    else{
        printf("VENCEDOR %s\n", obtemNomeJogador(j->vencedor));
    }
    printf("-------------------------------\n");
    for(int i = 0; i < j->qtdJogadores; i++){
        printRelatorioJogador(j->jogadores[i]);
    }
    printf("===============================\n");
}

void LeMapa(Mapa *mapa){
    char celula[100];
    scanf("INICIO MAPA\n");
    while(1){

        scanf("%s", celula);

        if(strcmp(celula, "OURO") == 0){

            Ouro *o = LeOuro();
            scanf("\n");
            insereCelulaMapa(mapa, o, ExecutaOuro, ImprimeOuro, DesalocaOuro);
            
        }
        else if(strcmp(celula, "MONSTRO") == 0){

            Monstro *m = leMonstro();
            scanf("\n");
            insereCelulaMapa(mapa, m, executaMonstro, imprimeMonstro, desalocaMonstro);

        }
        else if(strcmp(celula, "AVANCA") == 0){

            Avanca *v = LeCasaAvanca();
            scanf("\n");
            insereCelulaMapa(mapa, v, ExecutaAvanca, ImprimeAvanca, DesalocaAvanca);

        }
        else if(strcmp(celula, "VOLTA") == 0){

            Volta *v = LeCasaVolta();
            scanf("\n");
            insereCelulaMapa(mapa, v, ExecutaVolta, ImprimeVolta, DesalocaVolta);

        }
        else if(strcmp(celula, "VAZIA") == 0){

            scanf("\n");
            insereCelulaMapa(mapa, NULL, ExecutaVazia, ImprimeVazia, DesalocaVazia);

        }
        else if(strcmp(celula, "ITEM") == 0){

            Item *i = LeItem();
            scanf("\n");
            insereCelulaMapa(mapa, i, ExecutaItem, ImprimeItem, DesalocaItem);

        }
        else if(strcmp(celula, "FIM") == 0){

            scanf("MAPA\n");
            break;

        }
    }
}

void VenceJogadorJogo(Jogo *j, Jogador *jogador){
    moveJogadorMapa(j->mapa, jogador, obtemPosicaoFimMapa(j->mapa));
    j->vencedor = jogador;
}

char RealizaDisputa(Jogo *j, Jogador *desafiante, Jogador *ocupante, int posicaoDisputa){ 
    if (venceDisputaJogador(desafiante, ocupante))
    {
        incrementaDisputasVencidasJogador(desafiante);
        moveJogadorMapa(j->mapa, desafiante, posicaoDisputa);
        recuaJogadorMapa(j->mapa, ocupante, posicaoDisputa);
        return 'D';
    }
    else
    {
        incrementaDisputasVencidasJogador(ocupante);
        retiraJogadorMapa(j->mapa, desafiante);
        recuaJogadorMapa(j->mapa, desafiante, posicaoDisputa);
        return 'O';
    }
}

void RealizaDeslocamento(Jogo *j, Jogador *jogador, int deslocamento){
    int posicaoJogador = obtemPosicaoJogador(jogador);
    Celula *cDisputa = NULL;
    if (deslocamento == RECUO_CELULA)
    {
        recuaJogadorMapa(j->mapa, jogador, posicaoJogador);
    }
    else if (deslocamento != 0)
    {

        if (ChegouFinalJogador(j, (posicaoJogador + deslocamento)))
        {
            VenceJogadorJogo(j, jogador);
            return;
        }
        else if ((posicaoJogador + deslocamento) <= 0)
        {
            moveJogadorMapa(j->mapa, jogador, 0);
        }
        else
        {   
            cDisputa = obtemCelulaMapa(j->mapa, posicaoJogador+deslocamento);
            if (estaOcupadaCelula(cDisputa))
            {
                RealizaDisputa(j, jogador, obtemOcupanteCelula(cDisputa), posicaoJogador+deslocamento);
            }
            else
            {
                moveJogadorMapa(j->mapa, jogador, posicaoJogador+deslocamento);
            }
        }
    }
}

void ExecutaRolagem(Jogo *j, int nRolagens, int *jogadorDaVez){
    int qtdCasasDado = 0;       //muda para ponteiro
    int deslocamento = 0;
    Celula *cDisputa = NULL;
    for(int i = 0; i < nRolagens; i++){
        int posicaoJogador = 0;
        qtdCasasDado = RolaDado();
        incrementaJogadasJogador(j->jogadores[*jogadorDaVez]);
        posicaoJogador = obtemPosicaoJogador(j->jogadores[*jogadorDaVez]) + qtdCasasDado;
        if(ChegouFinalJogador(j, posicaoJogador))
        {
            VenceJogadorJogo(j, j->jogadores[*jogadorDaVez]);
            return;

        }
        else{

            cDisputa = obtemCelulaMapa(j->mapa, posicaoJogador);
            if(estaOcupadaCelula(cDisputa)){

                char vencedor = RealizaDisputa(j, j->jogadores[*jogadorDaVez], obtemOcupanteCelula(cDisputa), posicaoJogador);
                if(vencedor == 'D'){
                    deslocamento = executaAcaoCelula(cDisputa, j->jogadores[*jogadorDaVez]);
                    RealizaDeslocamento(j, j->jogadores[*jogadorDaVez], deslocamento);
                    if(j->vencedor != NULL){
                        return;
                    }
                }

            }
            else{

                moveJogadorMapa(j->mapa, j->jogadores[*jogadorDaVez], posicaoJogador);
                deslocamento = executaAcaoCelula(obtemCelulaMapa(j->mapa, posicaoJogador), j->jogadores[*jogadorDaVez]);
                RealizaDeslocamento(j, j->jogadores[*jogadorDaVez], deslocamento);
                if(j->vencedor != NULL){
                        return;
                }
            }

        }
        (*jogadorDaVez)++;
        if(*jogadorDaVez >= j->qtdJogadores){
            *jogadorDaVez = 0;
        }
    }
}


void ExecutaJogo(Jogo *j){
    int *jogadorDaVez = NULL;
    int a = 0;
    jogadorDaVez = &a;
    char opcao[40];
    LeMapa(j->mapa);
    while(1){

        scanf("%s", opcao);

        if(strcmp(opcao, "J") == 0){

            Jogador *jogador = leJogador();
            if(!JaExisteJogador(j, jogador)){
                InsereJogadorVetorJogadores(j, jogador);     
            }
            else{
                desalocaJogador(jogador);
            }

        }
        else if(strcmp(opcao, "ROLAGEM") == 0){

            int nRolagens;
            scanf("%d\n", &nRolagens);
            if(j->vencedor != NULL){
                continue;
            }
            ExecutaRolagem(j, nRolagens, jogadorDaVez);

        }
        else if(strcmp(opcao, "E") == 0){

            scanf("\n");
            scanf("%[^\n]\n", opcao);

            if(strcmp(opcao, "RANKING") == 0){
                ImprimeRankingPatida(j);
            }
            else if(strcmp(opcao, "RELATORIO") == 0){
                ImprimeRelatorioPartida(j);
            }
            else if(strcmp(opcao, "ESTADO") == 0){
                ImprimeEstadoPartida(j);
            }

        }
        else if(strcmp(opcao, "F") == 0){
            break;
        }
    }
}

void LiberaJogo(Jogo *j){
    for(int i = 0; i < j->qtdJogadores; i++){
        desalocaJogador(j->jogadores[i]);
    }
    free(j->jogadores);
    desalocaMapa(j->mapa);
    free(j);
}