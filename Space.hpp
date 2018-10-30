#include "gfx.h"
#include "Asteroid.hpp"
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

//Direcciones
		int dx[] = {1,0,-1,-1,-1,0,1,1};
		int dy[] = {1,1,1,0,-1,-1,-1,0};
class Space{
	public:		
		int tamx = 1200, tamy = 1200;
		int nAsteroids;
 		vector<Asteroid> asteroides;

 		Space(int numAsteroides){
 			nAsteroids = numAsteroides;
 		}
		~Space(){
			return;
		}

		void start(){
			srand(time(NULL));
			gfx_open(tamy, tamx, "Asteroides");

		 	for(int i = 0; i < nAsteroids; i++)
		 		asteroides.push_back(createAsteroid());
		 	
		 	while(true){
		 		gfx_color(rand()%255,rand()%255,rand()%255);
		 		gfx_clear();
		 		for(int i = 0; i < nAsteroids; i++)
		 		{
		 			if(asteroidOut(asteroides[i]))
		 				asteroides[i] = createAsteroid();
		 			else
		 				moveAsteroid(asteroides[i]);
		 		}
		 		gfx_flush();
		 		usleep(19999); //24 por segundo
		 	}

		}

		bool asteroidOut(Asteroid &ast)
		{
			bool flag = true;
			for(int i = 0 ; i < ast.vertices.size(); i++)
			{
				int x = ast.vertices[i].first;
				int y = ast.vertices[i].second;
				if ( (x <= tamx && x>=0) && (y <= tamy && y>=0) ) 
					flag = false;
			}
			return flag;
		}

		void moveAsteroid(Asteroid &ast){
			int n = ast.vertices.size();
			ast.updateAsteroid();
			for(int i = 0 ; i < n-1; i++)
			{
				 gfx_line(ast.vertices[i].first, ast.vertices[i].second, 
				 		   ast.vertices[i+1].first, ast.vertices[i+1].second);
			}
			gfx_line(ast.vertices[n-1].first, ast.vertices[n-1].second, 
				    ast.vertices[0].first, ast.vertices[0].second);
		}

		Asteroid createAsteroid(){
			int x0,y0;
			int lado = rand() % 8;
			switch(lado){
				case 0:
					x0 = 0;
					y0 = 0;
					break;
				case 1:
					x0 = rand() % tamx;
					y0 = 0;
					break;
				case 2:
					x0 = tamx;
					y0 = 0;
					break;
				case 3:
					x0 = tamx;
					y0 = rand() % tamy;
					break;
				case 4:
					x0 = int(tamx/2);
					y0 = int(tamy/2);
					break;
				case 5:
					x0 = rand() % tamx;
					y0 = tamy;
					break;
				case 6:
					x0 = 0;
					y0 = tamy;
					break;
				case 7:
					x0 = 0;
					y0 = rand() % tamy;
					break;
			}
			int dir = rand() % 8;
			return Asteroid(rand() % 30 + 10, x0,y0,dx[dir],dy[dir], rand() % 60 );
		}

};