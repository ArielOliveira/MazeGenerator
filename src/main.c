#include <stdio.h>
#include <stdlib.h>
#include "../include/backtracker.h"
#include "../tools/fileHandler.h"
#include "../tools/stack.h"

int main() {
	int **map = (int**)malloc(sizeof(int*) * MAP_SIZE);
	int i;
	for (i = 0; i < MAP_SIZE; i++) {
		map[i] = (int*)malloc(sizeof(int) * MAP_SIZE);
	}

	create_map(map);

	char *arquivo = (char*)malloc(sizeof(char) * 10);
	arquivo = "map.ppm";

	criarArquivo(MAP_SIZE, MAP_SIZE, arquivo);
	saveImage(MAP_SIZE, MAP_SIZE, map, arquivo);

	return 0;
}
