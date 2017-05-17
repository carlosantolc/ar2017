#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct{
	int tiempo;
	std::vector<int> tareas;
	std::vector<int> maquinas;
}solucion;

//Algoritmo general, dividimos en 2 partes
solucion avanceRapido(vector<vector<int> > tabla, int tareas, int maquinas) {
	solucion s;
	s.tiempo = 0;
	vector<int> candidatos;
	int tiempos[maquinas];
	for (int i = 0; i < maquinas; ++i)
	{
		tiempos[i] = 0;
	}
	for (int k = 0; k < tareas; ++k)
	{		
		candidatos.push_back(k);
	}
	while (candidatos.size() > 0) {
		int posibleTiempo = s.tiempo+101;
		int posibleTarea = 0;
		int posibleMaquina = 0;
		for (int i = 0; i < tareas; ++i)
		{
			if (std::find(candidatos.begin(), candidatos.end(), i) != candidatos.end())
			{
				for (int j = 0; j < maquinas; ++j)
				{
					int aux = tiempos[j] + tabla[i][j];
					if (aux < posibleTiempo) {
						posibleTiempo = aux;
						posibleTarea = i;
						posibleMaquina = j;
					}
				}
			}
			
		}
		tiempos[posibleMaquina] = posibleTiempo;
		candidatos.erase(remove(candidatos.begin(), candidatos.end(), posibleTarea), candidatos.end());
		s.tareas.push_back(posibleTarea+1);
		s.maquinas.push_back(posibleMaquina+1);
		if (tiempos[posibleMaquina] > s.tiempo) {
			s.tiempo = posibleTiempo;
		}
	}
	return s;
}

int main(int argc, char *argv[]) {


	int tareas;
	int maquinas;
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		cin >> tareas;
		cin >> maquinas;
		vector<vector<int> > tiempos;
		for (int j = 0; j < tareas; ++j) {
			vector<int> aux;
			for (int k = 0; k < maquinas; ++k) {
				int aux2;
				cin >> aux2;
				aux.push_back(aux2);
			}
			tiempos.push_back(aux);
			aux.clear();
		}
		/*for (int j = 0; j < tareas; ++j) {
			for (int k = 0; k < maquinas; ++k) {
				cout << tiempos[j][k] << " ";
		}
		cout << endl;*/

		solucion final = avanceRapido(tiempos, tareas, maquinas);
		cout << final.tiempo << endl;
		cout << final.tareas.at(0);
		for (size_t i = 1; i < final.tareas.size(); ++i)
		{
			cout << " " << final.tareas.at(i);
		}
		cout << endl;
		cout << final.maquinas.at(0);
		for (size_t i = 1; i < final.maquinas.size(); ++i)
		{
			cout << " " << final.maquinas.at(i);
		}
		cout << endl;
	}
}

