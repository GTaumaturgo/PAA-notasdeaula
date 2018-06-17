#ifndef DFS_H
#define DFS_H

#include <bits/stdc++.h>
#include "Grafo.h"
using namespace std;

#define branco 0
#define cinza 1
#define preto 2
#define oo 1e9; // valor muito alto

int tempo;

void DFS_Visit(Grafo& G, int u){
    tempo++;
    G.V[u].descoberta = tempo;
    G.V[u].cor = cinza;
    for(int w: G.adj[u]){
        if(G.V[w].cor == branco){
            G.V[w].pai = u;
            DFS_Visit(G,w);
        }
    }

    G.V[u].cor = preto;
    tempo++;
    G.V[u].termino = tempo;
}

void DFS(Grafo &G){
    for (Grafo::Vertice& u : G.V){
        u.cor = branco;
        u.pai = 0;
    }
    tempo = 0;

    for(int u = 1; u < G.V.size(); u++){
        if(G.V[u].cor == branco){
            DFS_Visit(G,u);
        }
    }
    
}

#endif