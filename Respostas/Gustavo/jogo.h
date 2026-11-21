#ifndef _JOGO_H
#define _JOGO_H

#include "mapa.h"
#include "dado.h"
#include "acao_avanca.h"
#include "acao_monstro.h"
#include "acao_volta.h"
#include "acao_ouro.h"
#include "acao_vazia.h"
#include "acao_item.h"

typedef struct Jogo Jogo;

Jogo* CriaJogo();

void InsereJogadorVetorJogadores(Jogo *jogo, Jogador *jogador);

int EstaNoInicioOuFimJogador(Jogo *j, Jogador *jogador);

int JaExisteJogador(Jogo *j, Jogador *jogador);

int ChegouFinalJogador(Jogo *j, int posicao);

void VenceJogadorJogo(Jogo *j, Jogador *jogador);

int RetornaQtdJogadasTotais(Jogo *j);

int RetornaQtdDisputasTotais(Jogo *j);

int RetornaMonstrosDerrotados(Jogo *j);

void ImprimeEstadoPartida(Jogo *j);

void ImprimeRankingPatida(Jogo *j);

void ImprimeRelatorioPartida(Jogo *j);

void LeMapa(Mapa *mapa);

char RealizaDisputa(Jogo *j, Jogador *desafiante, Jogador *ocupante, int posicaoDisputa);

void RealizaDeslocamento(Jogo *j, Jogador *jogador, int deslocamento);

void ExecutaRolagem(Jogo *j, int nRolagens, int *jogadorDaVez);

void ExecutaJogo(Jogo *j);

void LiberaJogo(Jogo *j);

#endif