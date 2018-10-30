#include "gfx.h"
#include "Space.hpp"
using namespace std;

int main(int argc, char *argv[]){
	int nAsteroids;
	if(argc==2){
		nAsteroids = atoi(argv[1]);
	}else{
		cout << "No hay argumentos" << endl;
		cout << "Se generaran 50 Asteroides" << endl;
		nAsteroids = 50;
	}
	Space space = Space(nAsteroids);
	space.start();

}