#include "libs/DFS.h"

int main()
{
    Grafo G(5);
    G.adicionaAresta(1, 2);
    G.adicionaAresta(2, 3);
    G.adicionaAresta(3, 4);
    G.adicionaAresta(4, 5);
    G.adicionaAresta(2, 4);
    DFS(G);

    cout << "Floresta do DFS:\n";
    cout << "vertice\tpai\n";
    for (int i = 1; i < G.V.size(); i++)
    {
        cout << i << ":\t" << G.V[i].pai << endl;
    }
    cout << "Tempos:\n";
    cout << "vertice\ttempos\n";
    for (int i = 1; i < G.V.size(); i++)
    {
        cout << i << ":\t" << G.V[i].descoberta << "/" << G.V[i].termino << endl;
    }
}