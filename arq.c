#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#define MAX 4
//	PRAZO 3 DE SET!!!

FILE* ord (FILE* in){
	Memoria v[MAX];
	int i_men=0, men=0, ice = 0;

	for(int i = 0; i < MAX; i++){
		v[i].congelado = 0;	//inicialmente, nd está congelado
		//Lendo MAX registros do arq
		fread(v[i]->p.cod, sizeof(int), 1, in);
		fread(v[i]->p.nome, sizeof(char), sizeof(Cliente.nome), in);
		fread(v[i]->p.data_n, sizeof(char), sizeof(Cliente.data_n), in);
	}

	FILE* part = fopen("part1.dat", "ab");
	while(){
		//i_men = func(implementar função para achar o menor) (CHECAR se tá congelado)
		i_men = menor(v);	//encontrando menor
		men = v[i_men]->p.cod;
		Cliente cliente = criaCliente(v[i_men]->p.cod, v[i_men]->p.nome, v[i_men]->p.data_n);
		salva(cliente, part);	//salvando menor registro na particao
	
		//Lendo próx registro do arq in
		fread(v[i_men]->p.cod, sizeof(int), 1, in);
		fread(v[i_men]->p.nome, sizeof(char), sizeof(Cliente.nome), in);
		fread(v[i_men]->p.data_n, sizeof(char), sizeof(Cliente.data_n), in);
		
		//PAREI AQUI !
		
		if(v[i_men]->p.cod < men){
			v[i_men].congelado = 1;
			ice++;
		}
		if(ice == MAX){
			fclose(part);
			FILE* part = fopen("part2.dat", "ab"); //implementar um jeito de criar partição com nome em ordem crescente (strcat)
			for (int i = 0; i < MAX; ++i){
				v[i].congelado = 0;
			}
			ice = 0;
		}
	}
}

int main(){
	FILE* p;
	p = fopen("arquivo.dat", "ab");
	int aux;

	for (int i = 0; i < 10; i++){
    /* gerando valores aleatórios entre zero e 100 */
		aux = rand() % 100;
    	fwrite(&aux, sizeof(int), 1, p);
  	}

	return 0;
}
