#include <iostream>
#include <vector>
#include <fstream>	
#include <string>
#include <cstdio>
using namespace std;
#include "../include/life.h"

	/**
	 * Constructor para pegar coluna na var y
	 * linha na var x
	 * e geração na var g
	 */
	Life::Life(int y, int x ,int g){
		lin = y;
		col = x;
		ger = g;
	}

	Life::Life(string arquivo){
		ifstream txtFile2;
		txtFile2.open(arquivo);
		if(!txtFile2){
        throw std::runtime_error("Arquivo não pode ser lido!!!");
    	}else{
	    	txtFile2 >> lin >> col >> Symbol;
	    	ger = 1;
	    	string LinhaAtual;
	    	vector < int > Criando;

	    	getline( txtFile2 , LinhaAtual );
	    	for(i = 0 ; i < lin ; i++){
	    		getline( txtFile2 , LinhaAtual );
	    		for(j = 0 ; j < col ; j++){
	    			if(LinhaAtual[j] == Symbol){	
	    				Criando.push_back(1);
	    			}else{
	    				Criando.push_back(0);
	    			}
	    		}
	    		matriz.push_back(Criando);
	    		Criando.clear();
	    	}

    	}
    	txtFile2.close();
	}
	/*
		Retorna a geração que teve o stable.
	 */
	int Life::getStable(){
		return stab;
	}
	/**
	 * [Life::getger description]
	 * Função para printa a matriz atual do jogo e a geração
	 */
	int Life::getger(){
		return ger;
	}

	/**
	 * [Life::start description]
	 * função que aloca a matriz inicial 
	 * indica quantidade de celulas vivas
	 * e coloca as celulas vivas na matriz 
	 */
	void Life::start(){

		int qtd;
		for(i = 0 ; i < lin ; i++){
		vector<int>aux;
			for(j= 0 ; j < col ; j++){
				aux.push_back(0);
			}
		matriz.push_back(aux);
		}
		cout << "Quantas celulas vivas deseja colocar?" << endl;
		cin >> qtd;
		while(qtd > 0){
			cout <<"Escolha a linha e em seguida a coluna(OBS:tamanho maximo da linha "<<lin<<" e da coluna "<<col<<"):"<<endl;
			cin >> i;
			if( i-1 > lin-1){
				cout << "Um valor menor que" << lin;
			}
			cin >> j;
			if( j-1 > col-1){
				cout << "Um valor menor que" << lin;
			}
			matriz[i-1][j-1] = 1;
			qtd = qtd-1;
		}
	}
	/**
	 * [Life::print description]
	 * Função para printa a matriz atual do jogo e a geração
	 */
	void Life::print(){
		cout<<"Geracao:"<<ger<<endl;
		for(i = 0 ; i < lin ; i++){
			for(j = 0 ; j < col ; j++){
				if(matriz[i][j]== 1){
					cout<<"*";
				}else{
					cout<<"-";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}

	/**
	 * [Life::extinct description]
	 * verifica se todas as celulas estão mortas
	 * se estiverem todas morta retorna true 
	 * caso tenha alguma viva retorna false
	 * @return [description]
	 */
	bool Life::extinct(){
		for(i = 0 ; i < lin ; i++){
			for(j = 0 ; j < col ; j++){
				if(matriz[i][j] == 1){
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * [Life::regraMorrer description]
	 * verifica se a celula viva deve morrer
	 * @param  i [variavel usada para percorrer a linha e saber onde ta sendo comparado]
	 * @param  j [variavel usada para percorrer a coluna e saber onde ta sendo comparado]
	 * @return   [retorna true se deve morrer && false caso não deva]
	 */
	bool Life::regraMorrer(int i, int j){
		int cont= 0;
		if(i < lin-1 && i > 0 && j < col-1 && j > 0){
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont +1;
			}
		}else if(i == lin-1 && j < col-1 && j > 0){
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont +1;
			}
			
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
		}
		else if(i == 0 && j < col-1 && j > 0){
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont +1;
			}
			
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
		}else if(i < lin-1 && i > 0 && j == 0){
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont +1;
			}
		}else if(i < lin-1 && i > 0 && j == col-1){
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont +1;
			}
		}else if(j == 0 && i == 0){
			if(matriz[i][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont+1;
			}
		}else if(j == 0 && i == lin-1){
			if(matriz[i][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j] == 1){
				cont = cont+1;
			}
		}else if(j == col-1 && i == 0){
			if(matriz[i][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont+1;
			}
		}else if(j == col-1 && i == lin-1){
			if(matriz[i][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j] == 1){
				cont = cont+1;
			}
		}

		if(cont < 2 || cont > 3){
			return true;
		}else{
			return false;
		}

	}

	/**
	 * [Life::regraNascer description]
	 * verifica se a celula morta deve viver
	 * @param  i [variavel usada para percorrer a linha e saber onde ta sendo comparado]
	 * @param  j [variavel usada para percorrer a coluna e saber onde ta sendo comparado]
	 * @return   [retorna true para caso deva viver 
	 * e caso deva permanecer morta retorna false]
	 */
	bool Life::regraNascer(int i, int j){
		int cont = 0;
		if(i < lin-1 && i > 0 && j < col-1 && j > 0){
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont +1;
			}
		}else if(i == lin-1 && j < col-1 && j > 0){
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont +1;
			}
			
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
		}
		else if(i == 0 && j < col-1 && j > 0){
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont +1;
			}
			
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
		}else if(i < lin-1 && i > 0 && j == 0){
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j+1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont +1;
			}
		}else if(i < lin-1 && i > 0 && j == col-1){
			if(matriz[i-1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont +1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i][j-1] == 1){
				cont = cont +1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont +1;
			}
		}else if(j == 0 && i == 0){
			if(matriz[i][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont+1;
			}
		}else if(j == 0 && i == lin-1){
			if(matriz[i][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j+1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j] == 1){
				cont = cont+1;
			}
		}else if(j == col-1 && i == 0){
			if(matriz[i][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i+1][j] == 1){
				cont = cont+1;
			}
		}else if(j == col-1 && i == lin-1){
			if(matriz[i][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j-1] == 1){
				cont = cont+1;
			}
			if(matriz[i-1][j] == 1){
				cont = cont+1;
			}
		}
		if(cont == 3){
			return true;
		}else{
			return false;
		}
	}

	/**
	 * [Life::update description]
	 * aplica as regras(nascer e morrer) e atualiza a matriz
	 */
	void Life::update(){

		vector<vector<int> >matrizAux;
		vector<int>aux2;
		for(i = 0 ; i < lin ; i++){
			
			for(j= 0 ; j < col ; j++){
				aux2.push_back(0);
			}
		matrizAux.push_back(aux2);
		aux2.clear();
		}


		for(i = 0 ; i < lin ; i++){
			for(j = 0 ; j < col ; j++){
				if(matriz[i][j] == 1){
					if(regraMorrer(i,j) == true){
						matrizAux[i][j] = 0;
					}else{
						matrizAux[i][j] = 1;
					}
				}
				if(matriz[i][j] == 0){
					if(regraNascer(i,j) == true){
						matrizAux[i][j] = 1;
					}else{
						matrizAux[i][j] = 0;
					}
				}
			}
		}

		for(i = 0 ; i < lin ; i++){
			for(j=0; j < col; j++){
				matriz[i][j]=matrizAux[i][j];
			}
		}
		ger = ger+1;
	}

	/**
	 * [Life::save description]
	 * guarda o historico num arquivo.txt
	 */
	void Life::save(){
		
		auto qtd = to_string(qtdARQ);
		ofstream arqSeila;
		arqSeila.open("result/arq"+qtd+".txt");
		arqSeila << lin<< " " << col <<endl;
		for(i = 0 ; i < lin ; i++){
			for(j = 0 ; j < col ; j++){
				//cout << matriz[i][j];
				arqSeila<<matriz[i][j];
			}
			arqSeila<<endl;
		}
		qtdARQ = qtdARQ+1;
	}

	/**
	 * [Life::stable description]
	 * verifica se tem um caso igual no arquivo de numeração Z
	 * @param  z [numeração do arquivo]
	 * @return   [retorna true caso tenha uma repetição de matriz e caso não retorna false]
	 */
	bool Life::stable(int z){

			ifstream txtFile;
			auto ajuda = to_string(z);
			int l, c;
			vector < vector < int > > stableMatriz;
			txtFile.open("result/arq"+ajuda+".txt");
			txtFile >> l >> c;

			string LinhaAtual;
			getline( txtFile , LinhaAtual );
			vector < int > Criando;

	    	for(i = 0 ; i < lin ; i++){
	    		getline( txtFile , LinhaAtual );
	    		for(j = 0 ; j < col ; j++){
	    			if(LinhaAtual[j] == '1'){	
	    				Criando.push_back(1);
	    			}else{
	    				Criando.push_back(0);
	    			}
	    		}
	    		stableMatriz.push_back(Criando);
	    		Criando.clear();
	    	}
	 		//cout << "Estavel?" << endl;
	  		//for( i = 0 ; i < lin ; i++){
			// 	for ( j = 0 ; j < col ; j++){
			// 		cout << stableMatriz[i][j] ;
			// 	}
			// 	cout << endl;
				
			// }
			for( i = 0 ; i < lin ; i++){
				for ( j = 0 ; j < col ; j++){
					if(stableMatriz[i][j] != matriz[i][j]){
						return false;
					}
				}
				
			}
			stab = z+1 ;
			txtFile.close();
			return true;
	}
