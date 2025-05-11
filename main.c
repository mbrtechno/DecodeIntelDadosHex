/*
 * main.c
 *
 *  Created on: 11 de mai. de 2025
 *      Author: clayton
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *entrada, *saida;
	char linha[255]; 		//Buffer para armazenar dado de cada linha
	char aux;
	int i;

	//Abrir o arquivo a ser analisado e o arquivo que receberá os dados tratados
	entrada = fopen("production.hex", "r");
	if(entrada == NULL){
		perror("Erro ao abrir o arquivo de entreda");
		return EXIT_FAILURE;
	}

	saida = fopen("analisado.txt", "a");
	if(saida == NULL){
		perror("Erro ao abrir arquivo de saida");
		return EXIT_FAILURE;
	}

	//Leitura de cada linha
	while(fgets(linha, sizeof(linha), entrada)){
		//unir bytes antes da analise
		for(i = 0; i < sizeof(linha); i++){
			aux = (linha[i+1] << 4) | linha[i+2];
			linha[i] = aux;
			aux = sizeof(linha);
		}

		//tratar cada linha seguindo o padrão INTELHEX
	}

	//fechamento dos arquivos aberto
	fclose(entrada);
	fclose(saida);
	return EXIT_SUCCESS;
}

