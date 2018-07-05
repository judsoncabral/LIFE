#include "../include/life.h"
using namespace std;
/**
 * @author Judson Cabral de Melo
 * [main description]
 * @return  [description]
 */
int main(int argc,char *argv[]){
	int aux;
	char A;
	if (argc == 1){
		int x, y;
		

		cout << "Digite quantidade de colunas e quantidade de linhas:"<<endl;
		cin >> x;
		cin >> y;

		Life objeto(y,x,1);
		objeto.start();

		objeto.save();
		objeto.print();
		
		if(objeto.extinct() == true){
			cout << "Acabou o jogo!!!"<<endl;
			return 0;
		}

		std::cout<<"Deseja continuar?(y/n)"<<std::endl;
			std::cin>>A;
			while(A != 'y' && A !=  'n'){
				std::cout<<"Digite y pra sim ou n pra não!!!"<<std::endl;
				std::cin>>A;
			}
		while(A == 'y'){
			
			objeto.update();
			objeto.print();
			

			for(aux = 0; aux < objeto.getger()-1 ; aux++){
				if(objeto.stable(aux) == true){
					cout << "Jogo acabou por stable com a geração :" << objeto.getStable() <<endl;
					return 0;
				}
			}
			if(objeto.extinct() == true){
				cout << "Jogo acabou por extinct" << endl;
				return 0;
			}
			objeto.save();
			std::cout<<"Deseja continuar?(y/n)"<<std::endl;
			std::cin>>A;
			while(A != 'y' && A !=  'n'){
				std::cout<<"Digite y pra sim ou n pra não!!!"<<std::endl;
				std::cin>>A;
			}
		}
	}else{

		string arq;
		arq = argv[1];
		//arq = "teste.txt";
		Life objeto(arq);

		objeto.save();
		objeto.print();
		
		if(objeto.extinct() == true){
			cout << "Acabou o jogo!!!"<<endl;
			return 0;
		}

		std::cout<<"Deseja continuar?(y/n)"<<std::endl;
			std::cin>>A;
			while(A != 'y' && A !=  'n'){
				std::cout<<"Digite y pra sim ou n pra não!!!"<<std::endl;
				std::cin>>A;
			}
		while(A == 'y'){
			
			objeto.update();
			objeto.print();
			

			for(aux = 0; aux < objeto.getger()-1 ; aux++){
				if(objeto.stable(aux) == true){
					cout << "Jogo acabou por stable com a geração :" << objeto.getStable() <<endl;
					return 0;
				}
			}
			if(objeto.extinct() == true){
				cout << "Jogo acabou por extinct" << endl;
				return 0;
			}
			objeto.save();
			std::cout<<"Deseja continuar?(y/n)"<<std::endl;
			std::cin>>A;
			while(A != 'y' && A !=  'n'){
				std::cout<<"Digite y pra sim ou n pra não!!!"<<std::endl;
				std::cin>>A;
			}
		}

	}
	
	
	

}