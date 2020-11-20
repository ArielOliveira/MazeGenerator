#include <stdio.h>
#include "fileHandler.h"

void headerPPM(FILE *file, int x, int y) {
	fprintf(file, "%c%c\n", 'P', '3');
	fprintf(file, "%i %i\n", x, y);
	fprintf(file, "%i\n", 255);
}

int createFile(int x, int y, char *path) {
	FILE *file;
	file = fopen(path, "w+");
	if (!file) {
		fprintf(stderr, "Erro ao criar arquivo\n");
		return 1;
	}
	headerPPM(file, x, y);
	fclose(file);
	return 0;
}

int saveImage(int x, int y, int **map, char *path) {
	FILE *file;
	file = fopen(path, "a");
	if (!file) {
		fprintf(stderr, "Erro ao salvar arquivo\n");
		return 1;
	}
	int i, j;
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			switch(map[i][j]) {
				case 0:  fprintf(file, "%i %i %i\n", 12, 12, 0);
					break;
				case 1:  fprintf(file, "%i %i %i\n", 128, 77, 255);
					break;
				case 2:  fprintf(file, "%i %i %i\n", 128, 77, 255);
					break;
				default: fprintf(file, "%i %i %i\n", 0, 0, 0);
			}
		}
	}

	fclose(file);
	return 0;
}
