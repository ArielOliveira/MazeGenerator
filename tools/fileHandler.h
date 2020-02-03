#ifndef HANDLER_H
#define HANDLER_H
#include "imagem.h"

int criarArquivo(int *x, int *y, char *arquivo);
int saveImage(int x, int y, pixel **imagem, char *arquivo);

#endif