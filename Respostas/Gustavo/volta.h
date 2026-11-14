#ifndef _VOLTA_H
#define _VOLTA_H

#include "jogador.h"

typedef struct Volta Volta;

Volta* criaCasaVolta();

int ExecutaVolta(Volta *v, Jogador *j);

void ImprimeVolta(Volta *v);

void DesalocaVolta(Volta *v);

#endif