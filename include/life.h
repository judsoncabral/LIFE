#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <vector>
#include <fstream>	
#include <string>
#include <cstdio>
using namespace std;

class Life{
private:
	int lin, col, i, j;
	int qtdARQ = 0;
	int ger;
	vector<vector<int> >matriz;
	int stab;

	//A mais para execução atraves de arquivo
	char Symbol;
public:
	/**
	 * Constructor para pegar coluna na var y
	 * linha na var x
	 * e geração na var g
	 */
	Life(int y, int x , int g);
	/**
	 * Constructor para pegar o inicio por um arquivo;
	 */
	Life(string arquivo);
	/*
		Retorna a geração que teve o stable.
	 */
	int getStable();
	/**
	 * [Life description]
	 * retorna a geração
	 * @return ger
	 */
	int getger();
	
	/**
	 * [print description]
	 * Função para printa a matriz atual do jogo e a geração
	 */
	void print();

	/**
	 * [extinct description]
	 * verifica se todas as celulas estão mortas
	 * se estiverem todas morta retorna true 
	 * caso tenha alguma viva retorna false
	 * @return [description]
	 */
	bool extinct();

	/**
	 * [regraMorrer description]
	 * verifica se a celula viva deve morrer
	 * @param  i [variavel usada para percorrer a linha e saber onde ta sendo comparado]
	 * @param  j [variavel usada para percorrer a coluna e saber onde ta sendo comparado]
	 * @return   [retorna true se deve morrer && false caso não deva]
	 */
	bool regraMorrer(int i , int j);

	/**
	 * [regraNascer description]
	 * verifica se a celula morta deve viver
	 * @param  i [variavel usada para percorrer a linha e saber onde ta sendo comparado]
	 * @param  j [variavel usada para percorrer a coluna e saber onde ta sendo comparado]
	 * @return   [retorna true para caso deva viver 
	 * e caso deva permanecer morta retorna false]
	 */
	bool regraNascer(int i, int j);

	/**
	 * [update description]
	 * aplica as regras(nascer e morrer) e atualiza a matriz
	 */
	void update();

	/**
	 * [save description]
	 * guarda o historico num arquivo.txt
	 */
	void save();

	/**
	 * [stable description]
	 * verifica se tem um caso igual no arquivo de numeração Z
	 * @param  z [numeração do arquivo]
	 * @return   [retorna true caso tenha uma repetição de matriz e caso não retorna false]
	 */
	bool stable(int z);

	/**
	 * [start description]
	 * função que aloca a matriz inicial 
	 * indica quantidade de celulas vivas
	 * e coloca as celulas vivas na matriz 
	 */
	void start();
};

#endif