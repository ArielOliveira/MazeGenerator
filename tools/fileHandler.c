#include <stdio.h>
#include "fileHandler.h"

void cabecalhoPPM(FILE *file, int *x, int *y) {
	fprintf(file, "%c%c\n", 'P', '3');
	fprintf(file, "%i %i\n", *x, *y);
	fprintf(file, "%i\n", 255);
}

int criarArquivo(int *x, int *y, char *arquivo) {
	FILE *file;
	file = fopen(arquivo, "w+");
	if (!file) {
		fprintf(stderr, "Erro ao criar arquivo\n");
		return 1;
	}
	cabecalhoPPM(file, x, y);
	fclose(file);
	return 0;
}

int saveImage(int x, int y, pixel **imagem, char *arquivo) {
	FILE *file;
	file = fopen(arquivo, "a");
	if (!file) {
		fprintf(stderr, "Erro ao salvar arquivo\n");
		return 1;
	}
	int i, j;
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			fprintf(file, "%i %i %i\n", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
		}
	}

	fclose(file);
	return 0;
}