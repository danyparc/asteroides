#include "gfx.h"
#include "Asteroid.hpp"
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int dx[] = {1,0,-1,-1,-1,0,1,1};
int dy[] = {1,1,1,0,-1,-1,-1,0};
class Space{
	public:		
		int size_screen_x = 1200, size_screen_y = 1200;
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
			gfx_open(size_screen_y, size_screen_x, "Asteroides");

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
		 		usleep(19999);
		 	}

		}

		bool asteroidOut(Asteroid &ast)
		{
			bool flag = true;
			for(int i = 0 ; i < ast.vertices.size(); i++)
			{
				int x = ast.vertices[i].first;
				int y = ast.vertices[i].second;
				if ( (x <= size_screen_x && x>=0) && (y <= size_screen_y && y>=0) ) 
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
					x0 = rand() % size_screen_x;
					y0 = 0;
					break;
				case 2:
					x0 = size_screen_x;
					y0 = 0;
					break;
				case 3:
					x0 = size_screen_x;
					y0 = rand() % size_screen_y;
					break;
				case 4:
					x0 = int(size_screen_x/2);
					y0 = int(size_screen_y/2);
					break;
				case 5:
					x0 = rand() % size_screen_x;
					y0 = size_screen_y;
					break;
				case 6:
					x0 = 0;
					y0 = size_screen_y;
					break;
				case 7:
					x0 = 0;
					y0 = rand() % size_screen_y;
					break;
			}
			int dir = rand() % 8;
			return Asteroid(rand() % 30 + 10, x0,y0,dx[dir],dy[dir], rand() % 60 );
		}

};