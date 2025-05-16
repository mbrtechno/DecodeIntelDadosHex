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
	int i;
	int ndados;

	printf("Processando...\n");

	//Abrir o arquivo a ser analisado e o arquivo que receberá os dados tratados
	entrada = fopen("production.hex", "r");
	if(entrada == NULL){
		perror("Erro ao abrir o arquivo de entreda");
		return EXIT_FAILURE;
	}

	saida = fopen("analisado.txt", "w");
	if(saida == NULL){
		perror("Erro ao abrir arquivo de saida");
		return EXIT_FAILURE;
	}

	//Leitura de cada linha
	while(fgets(linha, sizeof(linha), entrada)){

		//informa quantos bytes foram adicionados
		ndados = (strlen(linha)-3);

		//Testar se linha contém dados ou endereços
		if((linha[8] == '0')){
			//salvar a partir do inicio de dados até o checksum
			for(i = 9; i < ndados; i++){
				fputc(linha[i], saida);	// somente dados - sem checksum
			}
			fputc('\n', saida);	//arquivo possue quebra de linha
		}else{
			//Não adiciona linha que possuem somente informações de endereços
		}
	}

	//fechamento dos arquivos aberto
	fclose(entrada);
	fclose(saida);

	printf("Finalizado.\n");
	return EXIT_SUCCESS;
}

