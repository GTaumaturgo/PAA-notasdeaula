#ifndef GRAFO_H
#define GRAFO_H
#include <bits/stdc++.h>

using namespace std;

class Grafo{
    
    public:
        class Vertice{
            public:
                int cor = 0;
                int dist = 0;
                int pai = -1;
                int descoberta;
                int termino;
        };
        
        vector<Vertice> V;
        vector<vector<int>> adj;
        Grafo(int tamanho): adj(tamanho+1,vector<int>()), V(tamanho+1,Vertice()){}

        void adicionaAresta(int origem_id, int destino_id){
            this->adj[origem_id].push_back(destino_id);
        }
};
#endif