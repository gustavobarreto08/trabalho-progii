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

/**
 * @brief Usada para ver se já existe o jogador na hora de fazer cadastro
 * @return 1 se já existe ou 0 se não existe
 */
int JaExisteJogador(Jogo *j, Jogador *jogador);

int ChegouFinalJogador(Jogo *j, int posicao);

void VenceJogadorJogo(Jogo *j, Jogador *jogador);

int RetornaQtdJogadasTotais(Jogo *j);

int RetornaQtdDisputasTotais(Jogo *j);

int RetornaMonstrosDerrotados(Jogo *j);

void ImprimeEstadoPartida(Jogo *j);

/**
 * @brief Ordena os Jogadores antes de imprimir o ranking usando qsort e a função de comparaOrd
 */

void ImprimeRankingPartida(Jogo *j);

void ImprimeRelatorioPartida(Jogo *j);

/**
 * @brief Lê qual é a opção de célula e chama a respectiva função e lê a quebra de linha do final
 * então a função ler a célula genérica não deve consumir a quebra
 */

void LeMapa(Mapa *mapa);

/**
 * @brief Faz a disputa pela celula, já movendo ou recuando o desafiante e o ocupante. NÃO EXECUTA A AÇÃO DA CELULA
 * @return Retorna 'D' se o desafiante ganhar ou 'O' se o ocupante ganhar
 */

char RealizaDisputa(Jogo *j, Jogador *desafiante, Jogador *ocupante, int posicaoDisputa);

/**
 * @brief Recebe como parametro o deslocamento resultante do executa acao celula (feito pela função executa rolagem)
 * e tenta mover o jogador para a nova celula se houver deslocamento (fazendo a disputa caso haja), também checa se o jogador venceu com esse deslocamento ou se a posição resultou em menor que zero
 */
void RealizaDeslocamento(Jogo *j, Jogador *jogador, int deslocamento);

/**
 * @brief Rola o dado a quantidade de vezes pedida e faz a jogada usando as funções de RealizaDisputa e de RealizaDeslocamento. Executa a ação da célula de destino
 */
void ExecutaRolagem(Jogo *j, int nRolagens, int *jogadorDaVez);

/**
 * @brief Le as entradas de jogadores, as Rolagens e as opções de Estados e chama as funções de cada um de acordo
 * com o que foi pedido. Ao scannear a opção não le a quebra de linha
 */
void ExecutaJogo(Jogo *j);

void LiberaJogo(Jogo *j);

#endif