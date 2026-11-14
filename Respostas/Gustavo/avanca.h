#ifndef _AVANCA_H
#define _AVANCA_H

#include "jogador.h"

typedef struct Avanca Avanca;

Avanca* criaCasaAvanca();

int ExecutaAvanca(Avanca *a, Jogador *j);

void ImprimeAvanca(Avanca *a);

void DesalocaAvanca(Avanca *a);

#endif