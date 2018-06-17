#ifndef BFS_H
#define BFS_H

#include <bits/stdc++.h>
#include "Grafo.h"
using namespace std;

#define branco 0
#define cinza  1
#define preto  2
#define oo     1e9; // valor muito alto

void BFS(Grafo& G, int fonte){
    for(Grafo::Vertice u : G.V){
        u.cor = branco;
        u.dist = oo;
        u.pai = 0;
    }

    G.V[fonte].cor = cinza;
    G.V[fonte].dist = 0;
    G.V[fonte].pai = 0;

    queue<int> Q;
    Q.push(fonte);
    while(Q.size()){
        int u = Q.front();
        Q.pop();
        for(int v: G.adj[u]){
            if(G.V[v].cor == branco){
                G.V[v].cor = cinza;
                G.V[v].dist = G.V[u].dist + 1;
                G.V[v].pai = u;
                Q.push(v);
            }
        }
        G.V[u].cor = preto;
    }
}
#endif