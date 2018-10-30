#include <bits/stdc++.h>
using namespace std;

class Asteroid{
	public:
		double dx,dy;
		double giro;
		vector< pair<double,double> > vertices;
		Asteroid(double nVertex, double x0, double y0, double dirx, double diry, double size)
		{
			dx = (dirx * 10) / size;
			dy = (diry * 10) / size;
			dx += dirx;
			dy += diry;
			vector<double> angles;
			for(int i = 0; i < nVertex; i++)
			{
				angles.push_back( (rand() % 361) *  M_PI/180);
			}
			sort(angles.begin(),angles.end());
			for(int i = 0; i < nVertex; i++)
			{
				double x = x0 + size*cos(angles[i]); //cambiar r
				double y = y0 + size*sin(angles[i]);
				vertices.push_back(make_pair(x,y));
			}
		}
		~Asteroid()
		{
			return;
		}

		void rotateVertex(double id,double grados)
		{
				double radianes = grados * M_PI / 180.0;
				double x = vertices[id].first, y = vertices[id].second;
				vertices[id].first = x * cos(radianes) - y * sin(radianes);
				vertices[id].second = x * sin(radianes) + y * cos(radianes);
		}

		pair<double,double> getCentroid()
		{
			double area = 0,aux = 0;
			double x = 0, y = 0;
			for(int i = 0; i < vertices.size() - 1; i++)
			{
				aux = vertices[i].first * vertices[i+1].second;
				aux-= vertices[i+1].first * vertices[i].second;
				area+=aux;
				x += (vertices[i].first + vertices[i+1].first) * aux;
				y += (vertices[i].second + vertices[i+1].second) * aux;
			}

			aux = vertices[vertices.size()-1].first * vertices[0].second;
			aux-= vertices[0].first * vertices[vertices.size()-1].second;
			area+=aux;
			x += (vertices[vertices.size()-1].first + vertices[0].first) * aux;
			y += (vertices[vertices.size()-1].second + vertices[0].second) * aux;
			area /=2;
			x /= (6 * area);
			y /= (6 * area);
			return make_pair(x,y);
		}


		void updateAsteroid()
		{
			pair<double,double> centroid = getCentroid();
			for(int i = 0; i < vertices.size(); i++)
			{
				vertices[i].first += dx;
				vertices[i].second += dy;

				//Rotacion en torno a centroid
				vertices[i].first -= centroid.first;
				vertices[i].second -= centroid.second;
				rotateVertex(i,10);
				vertices[i].first += centroid.first;
				vertices[i].second += centroid.second;
			}

		}
		void updateVertex(double id)
		{
			vertices[id].first += dx;
			vertices[id].second += dy;
		}	
};