#ifndef _VAZIA_H
#define _VAZIA_H

#include "jogador.h"

typedef struct Vazia Vazia;

int ExecutaVazia(Vazia *v, Jogador *j);

void ImprimeVazia(Vazia *v);

void DesalocaVazia(Vazia *v);

#endif