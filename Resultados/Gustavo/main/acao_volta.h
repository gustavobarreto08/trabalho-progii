#ifndef _VOLTA_H
#define _VOLTA_H

#include "jogador.h"

typedef struct Volta Volta;

Volta* criaCasaVolta(int qtdCasas);

Volta* LeCasaVolta();

int ExecutaVolta(void *dado, Jogador *j);

void ImprimeVolta(void *dado);

void DesalocaVolta(void *dado);

#endif