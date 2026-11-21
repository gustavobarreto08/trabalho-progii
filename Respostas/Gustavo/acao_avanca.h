#ifndef _AVANCA_H
#define _AVANCA_H

#include "jogador.h"

typedef struct Avanca Avanca;

Avanca* criaCasaAvanca(int qtdCasas);

Avanca* LeCasaAvanca();

int ExecutaAvanca(void *dado, Jogador *j);

void ImprimeAvanca(void *dado);

void DesalocaAvanca(void *dado);

#endif