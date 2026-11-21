#ifndef _VAZIA_H
#define _VAZIA_H

#include "jogador.h"

typedef struct Vazia Vazia;

int ExecutaVazia(void *dado, Jogador *j);

void ImprimeVazia(void *dado);

void DesalocaVazia(void *dado);

#endif