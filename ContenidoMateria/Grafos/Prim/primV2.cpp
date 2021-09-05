/*
Autor ------> Gabriel Neme Benitez
*/

#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin) 
#define output freopen("out.txt", "w", stdout) 
using namespace std;
//Nodos numerados de 0 a n-1
vector<bool>esta; //esta[i] = true -0 -> el nodo "i" esta en la componente
vector<vector<pair<int, int>>>grafo;
int prim(int nodo) {
	int answer=0; // tamaño arbol expansion
	priority_queue<pair<int, int>>cola; //[ -peso, nodo (al que pertenece)] // es la clave de todo
	cola.push( {
		0, nodo
	}
	);
	while(!cola.empty()) {
		// ejecutamos siempre y cuando la cola no esta vacia
		pair<int, int>curr=cola.top();
		cola.pop();
		if(esta[curr.second]==true) continue;
		cout <<"{" << -curr.first << "," << curr.second << "}" << endl;
		esta[curr.second]=true;
		answer=answer - curr.first;
		for(int i=0;
		i< grafo[curr.second].size();
		i++) {
			cola.push( {
				-grafo[curr.second][i].second, grafo[curr.second][i].first
			}
			);
		}
	}
	return answer;
}
int main() {
	input;
	int n, m;
	cin>>n>>m; // n es numeros de nodos y m es cantidad de aristas
	grafo.resize(n);
	esta.resize(n);
	for(int i=0;
	i < m;
	i++) {
		int a, b, c; // a nodo origen, b nodo de destino, c peso de la arista
		cin>>a>>b>>c;
		grafo[a].push_back( {
			b, c
		}
		); // solo esta instruccion es grafo dirigido
		grafo[b].push_back( {
			a, c
		}
		); // aqui no dirigido
	}
	cout<< prim(0) <<endl;
	return 0;
}